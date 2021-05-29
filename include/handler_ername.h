/* Copyright (c) 2013, 2021, MariaDB Corporation.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335 USA */

/* Names of all handler error numbers. Used by mysqltest */

{ "HA_ERR_KEY_NOT_FOUND", HA_ERR_KEY_NOT_FOUND, "" },
{ "HA_ERR_FOUND_DUPP_KEY", HA_ERR_FOUND_DUPP_KEY, "" },
{ "HA_ERR_INTERNAL_ERROR", HA_ERR_INTERNAL_ERROR, "" },
{ "HA_ERR_RECORD_CHANGED", HA_ERR_RECORD_CHANGED, "" },
{ "HA_ERR_WRONG_INDEX", HA_ERR_WRONG_INDEX, "" },
{ "HA_ERR_CRASHED", HA_ERR_CRASHED, "" },
{ "HA_ERR_WRONG_IN_RECORD", HA_ERR_WRONG_IN_RECORD, "" },
{ "HA_ERR_OUT_OF_MEM", HA_ERR_OUT_OF_MEM, "" },
{ "HA_ERR_NOT_A_TABLE", HA_ERR_NOT_A_TABLE, "" },
{ "HA_ERR_WRONG_COMMAND", HA_ERR_WRONG_COMMAND, "" },
{ "HA_ERR_OLD_FILE", HA_ERR_OLD_FILE, "" },
{ "HA_ERR_NO_ACTIVE_RECORD", HA_ERR_NO_ACTIVE_RECORD, "" },
{ "HA_ERR_RECORD_DELETED", HA_ERR_RECORD_DELETED, "" },
{ "HA_ERR_RECORD_FILE_FULL", HA_ERR_RECORD_FILE_FULL, "" },
{ "HA_ERR_INDEX_FILE_FULL", HA_ERR_INDEX_FILE_FULL, "" },
{ "HA_ERR_END_OF_FILE", HA_ERR_END_OF_FILE, "" },
{ "HA_ERR_UNSUPPORTED", HA_ERR_UNSUPPORTED, "" },
{ "HA_ERR_TO_BIG_ROW", HA_ERR_TO_BIG_ROW, "" },
{ "HA_WRONG_CREATE_OPTION", HA_WRONG_CREATE_OPTION, "" },
{ "HA_ERR_FOUND_DUPP_UNIQUE", HA_ERR_FOUND_DUPP_UNIQUE, "" },
{ "HA_ERR_UNKNOWN_CHARSET", HA_ERR_UNKNOWN_CHARSET, "" },
{ "HA_ERR_WRONG_MRG_TABLE_DEF", HA_ERR_WRONG_MRG_TABLE_DEF, "" },
{ "HA_ERR_CRASHED_ON_REPAIR", HA_ERR_CRASHED_ON_REPAIR, "" },
{ "HA_ERR_CRASHED_ON_USAGE", HA_ERR_CRASHED_ON_USAGE, "" },
{ "HA_ERR_LOCK_WAIT_TIMEOUT", HA_ERR_LOCK_WAIT_TIMEOUT, "" },
{ "HA_ERR_LOCK_TABLE_FULL", HA_ERR_LOCK_TABLE_FULL, "" },
{ "HA_ERR_READ_ONLY_TRANSACTION", HA_ERR_READ_ONLY_TRANSACTION, "" },
{ "HA_ERR_LOCK_DEADLOCK", HA_ERR_LOCK_DEADLOCK, "" },
{ "HA_ERR_CANNOT_ADD_FOREIGN", HA_ERR_CANNOT_ADD_FOREIGN, "" },
{ "HA_ERR_NO_REFERENCED_ROW", HA_ERR_NO_REFERENCED_ROW, "" },
{ "HA_ERR_ROW_IS_REFERENCED", HA_ERR_ROW_IS_REFERENCED, "" },
{ "HA_ERR_NO_SAVEPOINT", HA_ERR_NO_SAVEPOINT, "" },
{ "HA_ERR_NON_UNIQUE_BLOCK_SIZE", HA_ERR_NON_UNIQUE_BLOCK_SIZE, "" },
{ "HA_ERR_NO_SUCH_TABLE", HA_ERR_NO_SUCH_TABLE, "" },
{ "HA_ERR_TABLE_EXIST", HA_ERR_TABLE_EXIST, "" },
{ "HA_ERR_NO_CONNECTION", HA_ERR_NO_CONNECTION, "" },
{ "HA_ERR_NULL_IN_SPATIAL", HA_ERR_NULL_IN_SPATIAL, "" },
{ "HA_ERR_TABLE_DEF_CHANGED", HA_ERR_TABLE_DEF_CHANGED, "" },
{ "HA_ERR_NO_PARTITION_FOUND", HA_ERR_NO_PARTITION_FOUND, "" },
{ "HA_ERR_RBR_LOGGING_FAILED", HA_ERR_RBR_LOGGING_FAILED, "" },
{ "HA_ERR_DROP_INDEX_FK", HA_ERR_DROP_INDEX_FK, "" },
{ "HA_ERR_FOREIGN_DUPLICATE_KEY", HA_ERR_FOREIGN_DUPLICATE_KEY, "" },
{ "HA_ERR_TABLE_NEEDS_UPGRADE", HA_ERR_TABLE_NEEDS_UPGRADE, "" },
{ "HA_ERR_TABLE_READONLY", HA_ERR_TABLE_READONLY, "" },
{ "HA_ERR_AUTOINC_READ_FAILED", HA_ERR_AUTOINC_READ_FAILED, "" },
{ "HA_ERR_AUTOINC_ERANGE", HA_ERR_AUTOINC_ERANGE, "" },
{ "HA_ERR_GENERIC", HA_ERR_GENERIC, "" },
{ "HA_ERR_RECORD_IS_THE_SAME", HA_ERR_RECORD_IS_THE_SAME, "" },
{ "HA_ERR_LOGGING_IMPOSSIBLE", HA_ERR_LOGGING_IMPOSSIBLE, "" },
{ "HA_ERR_CORRUPT_EVENT", HA_ERR_CORRUPT_EVENT, "" },
{ "HA_ERR_NEW_FILE", HA_ERR_NEW_FILE, "" },
{ "HA_ERR_ROWS_EVENT_APPLY", HA_ERR_ROWS_EVENT_APPLY, "" },
{ "HA_ERR_INITIALIZATION", HA_ERR_INITIALIZATION, "" },
{ "HA_ERR_FILE_TOO_SHORT", HA_ERR_FILE_TOO_SHORT, "" },
{ "HA_ERR_WRONG_CRC", HA_ERR_WRONG_CRC, "" },
{ "HA_ERR_TOO_MANY_CONCURRENT_TRXS", HA_ERR_TOO_MANY_CONCURRENT_TRXS, "" },
{ "HA_ERR_INDEX_COL_TOO_LONG", HA_ERR_INDEX_COL_TOO_LONG, "" },
{ "HA_ERR_INDEX_CORRUPT", HA_ERR_INDEX_CORRUPT, "" },
{ "HA_ERR_UNDO_REC_TOO_BIG", HA_ERR_UNDO_REC_TOO_BIG, "" },
{ "HA_ERR_ROW_NOT_VISIBLE", HA_ERR_ROW_NOT_VISIBLE, "" },
{ "HA_ERR_ABORTED_BY_USER", HA_ERR_ABORTED_BY_USER, "" },
{ "HA_ERR_DISK_FULL", HA_ERR_DISK_FULL, "" },
{ "HA_ERR_INCOMPATIBLE_DEFINITION", HA_ERR_INCOMPATIBLE_DEFINITION, "" },
