/* We are going to test whether create and close properly check their input. */

#include "test.h"

static DBT _key;
static DBT _data;
DBT* key;
DBT* data;

int main(int argc, const char *argv[]) {
    int r;
    toku_lock_tree* lt  = NULL;
    DB*             db  = (DB*)1;
    DB_TXN*         txn = (DB_TXN*)1;  // Fake.
    BOOL duplicates = FALSE;

    /* create tests. */
    for (duplicates = 0; duplicates < 2; duplicates++) {
        r = toku_lt_create(NULL, db,   duplicates, dbcmp, dbcmp,
                           toku_malloc, toku_free, toku_realloc);
        CKERR2(r, EINVAL);
        r = toku_lt_create(&lt,  NULL, duplicates, dbcmp, dbcmp,
                           toku_malloc, toku_free, toku_realloc);
        CKERR2(r, EINVAL);
        r = toku_lt_create(&lt,  db,   duplicates, NULL,  dbcmp,
                           toku_malloc, toku_free, toku_realloc);
        CKERR2(r, EINVAL);
        r = toku_lt_create(&lt,  db,   duplicates, dbcmp, NULL,
                           toku_malloc, toku_free, toku_realloc);
        CKERR2(r, EINVAL);
        r = toku_lt_create(&lt,  db,   duplicates, dbcmp, dbcmp,
                           NULL,        toku_free, toku_realloc);
        CKERR2(r, EINVAL);
        r = toku_lt_create(&lt,  db,   duplicates, dbcmp, dbcmp,
                           toku_malloc, NULL,      toku_realloc);
        CKERR2(r, EINVAL);
        r = toku_lt_create(&lt,  db,   duplicates, dbcmp, dbcmp,
                           toku_malloc, toku_free, NULL);
        CKERR2(r, EINVAL);
    }

    /* Close tests. */
    r = toku_lt_close(NULL);
    CKERR2(r, EINVAL);

    lt = NULL;
    DBT* reverse_data;
    /* Point read tests. */
    key  = &_key;
    for (duplicates = 0; duplicates < 2; duplicates++) {
        if (duplicates) {
            data         = &_data;
            reverse_data = NULL;
        }
        else {
            reverse_data = &_data;
            data         = NULL;
        }
        r = toku_lt_create(&lt, db, duplicates, dbcmp, dbcmp,
                           toku_malloc, toku_free, toku_realloc);
        CKERR(r);
        assert(lt);

        r = toku_lt_acquire_read_lock(NULL, txn,  key,  data);
        CKERR2(r, EINVAL);

        r = toku_lt_acquire_read_lock(lt,   NULL, key,  data);
        CKERR2(r, EINVAL);

        r = toku_lt_acquire_read_lock(lt,   txn,  NULL, data);
        CKERR2(r, EINVAL);

        r = toku_lt_acquire_read_lock(lt,   txn,  key,  reverse_data);
        CKERR2(r, EINVAL);

        /* Infinite tests. */
        if (duplicates) {
            r = toku_lt_acquire_read_lock(lt, txn, toku_lt_infinity,     data);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_read_lock(lt, txn, toku_lt_neg_infinity, data);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_read_lock(lt, txn, toku_lt_infinity,
                                                   toku_lt_neg_infinity);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_read_lock(lt, txn, toku_lt_neg_infinity,
                                                   toku_lt_infinity);
            CKERR2(r, EINVAL);
        }

        /* Cleanup. */
        r = toku_lt_close(lt);
        CKERR(r);
        
        lt = NULL;
    }

    /* Point write tests. */
    key  = &_key;
    for (duplicates = 0; duplicates < 2; duplicates++) {
        if (duplicates) {
            data         = &_data;
            reverse_data = NULL;
        }
        else {
            reverse_data = &_data;
            data         = NULL;
        }
        r = toku_lt_create(&lt, db, duplicates, dbcmp, dbcmp,
                           toku_malloc, toku_free, toku_realloc);
        CKERR(r);
        assert(lt);

        r = toku_lt_acquire_write_lock(NULL, txn,  key,  data);
        CKERR2(r, EINVAL);

        r = toku_lt_acquire_write_lock(lt,   NULL, key,  data);
        CKERR2(r, EINVAL);

        r = toku_lt_acquire_write_lock(lt,   txn,  NULL, data);
        CKERR2(r, EINVAL);

        r = toku_lt_acquire_write_lock(lt,   txn,  key,  reverse_data);
        CKERR2(r, EINVAL);

        /* Infinite tests. */
        if (duplicates) {
            r = toku_lt_acquire_write_lock(lt, txn, toku_lt_infinity,     data);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_write_lock(lt, txn, toku_lt_neg_infinity, data);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_write_lock(lt, txn, toku_lt_infinity,
                                                    toku_lt_neg_infinity);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_write_lock(lt, txn, toku_lt_neg_infinity,
                                                    toku_lt_infinity);
            CKERR2(r, EINVAL);
        }

        /* Cleanup. */
        r = toku_lt_close(lt);
        CKERR(r);
        
        lt = NULL;
    }

    /* Range read tests. */
    DBT _key_l  = _key;
    DBT _key_r  = _key;
    DBT _data_l = _data;
    DBT _data_r = _data;
    DBT* key_l  = &_key_l;
    DBT* key_r  = &_key_r;
    DBT* data_l;
    DBT* data_r;
    DBT* reverse_data_l;
    DBT* reverse_data_r;
    for (duplicates = 0; duplicates < 2; duplicates++) {
        if (duplicates) {
            data_l         = &_data_l;
            data_r         = &_data_r;
            reverse_data_l = NULL;
            reverse_data_r = NULL;
        }
        else {
            data_l         = NULL;
            data_r         = NULL;
            reverse_data_l = &_data_l;
            reverse_data_r = &_data_r;
        }
        r = toku_lt_create(&lt, db, duplicates, dbcmp, dbcmp,
                           toku_malloc, toku_free, toku_realloc);
        CKERR(r);
        assert(lt);
        r = toku_lt_acquire_range_read_lock(NULL,   txn,
                                            key_l,  data_l,
                                            key_r,  data_r);
        CKERR2(r, EINVAL);
        r = toku_lt_acquire_range_read_lock(lt,     NULL,
                                            key_l,  data_l,
                                            key_r,  data_r);
        CKERR2(r, EINVAL);
        r = toku_lt_acquire_range_read_lock(lt,     txn,
                                            NULL,   data_l,
                                            key_r,  data_r);
        CKERR2(r, EINVAL);
        r = toku_lt_acquire_range_read_lock(lt,     txn,
                                            key_l,  reverse_data_l,
                                            key_r,  data_r);
        CKERR2(r, EINVAL);
        r = toku_lt_acquire_range_read_lock(lt,     txn,
                                            key_l,  data_l,
                                            NULL,   data_r);
        CKERR2(r, EINVAL);
        r = toku_lt_acquire_range_read_lock(lt,     txn,
                                            key_l,  data_l,
                                            key_r,  reverse_data_r);
        CKERR2(r, EINVAL);

        /* Infinite tests. */
        if (duplicates) {
            r = toku_lt_acquire_range_read_lock(lt, txn,
                                                toku_lt_infinity,       data_l,
                                                key_r,                  data_r);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_range_read_lock(lt, txn,
                                                toku_lt_neg_infinity,   data_l,
                                                key_r,                  data_r);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_range_read_lock(lt, txn,
                                                key_l,                  data_l,
                                                toku_lt_infinity,       data_r);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_range_read_lock(lt, txn,
                                                key_l,                  data_l,
                                                toku_lt_neg_infinity,   data_r);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_range_read_lock(lt, txn,
                                toku_lt_infinity,       toku_lt_neg_infinity,
                                key_r,                  data_r);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_range_read_lock(lt, txn,
                                toku_lt_neg_infinity,   toku_lt_infinity,
                                key_r,                  data_r);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_range_read_lock(lt, txn,
                                key_l,                  data_l,
                                toku_lt_infinity,       toku_lt_neg_infinity);
            CKERR2(r, EINVAL);
            r = toku_lt_acquire_range_read_lock(lt, txn,
                                key_l,                  data_l,
                                toku_lt_neg_infinity,   toku_lt_infinity);
            CKERR2(r, EINVAL);
        }
        /* left > right tests. */
        const DBT* d_inf     = duplicates ? toku_lt_infinity      : NULL;
        const DBT* inf       =              toku_lt_infinity;
        const DBT* d_ninf    = duplicates ? toku_lt_neg_infinity  : NULL;
        const DBT* ninf      =              toku_lt_neg_infinity;
        r = toku_lt_acquire_range_read_lock(lt,     txn,
                                            inf,    d_inf,
                                            key_r,  data_r);
        CKERR2(r, EDOM);
        r = toku_lt_acquire_range_read_lock(lt,     txn,
                                            key_l,  data_l,
                                            ninf,   d_ninf);
        CKERR2(r, EDOM);
        r = toku_lt_acquire_range_read_lock(lt,     txn,
                                            inf,    d_inf,
                                            ninf,   d_ninf);
        CKERR2(r, EDOM);

        /* Cleanup. */
        r = toku_lt_close(lt);
        CKERR(r);
        
        lt = NULL;
    }
    return 0;
}
