//
// Created by victor on 8/31/21.
//

#ifndef DBCRUDGEN_CPP_MSSQLDATABASEDECOMPOSER_H
#define DBCRUDGEN_CPP_MSSQLDATABASEDECOMPOSER_H

#include "../scaffolding/entities/SysDatabases.h"
#include "../executor/MSSQLColBinder.h"
#include "../executor/MSSQLResultSet.h"
#include "../scaffolding/queries/MSSQLQueries.h"

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class MSSQLDatabaseDecomposer {
            public:
                MSSQLDatabaseDecomposer() {

                }

                /**
                 * Get all Sys databases
                 * @return
                 */
                std::vector<SysDatabases> getSysDatabases() {
                    std::vector<MSSQLColBinder> colBindings;
                    std::vector<SysDatabases> sysDatabases;

                    SQLCHAR name[255];
                    SQLLEN name_indicator;
                    colBindings.emplace_back(MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::NAME::INDEX, SQL_C_CHAR,
                                                            SysDatabases::COLUMNS::NAME::NAME, name, 255,
                                                            &name_indicator;});

                    SQLCHAR database_id[255];
                    SQLLEN database_id_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::DATABASE_ID::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::DATABASE_ID::NAME, database_id, 255,
                                           &database_id_indicator;});

                    SQLCHAR source_database_id[255];
                    SQLLEN source_database_id_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::SOURCE_DATABASE_ID::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::SOURCE_DATABASE_ID::NAME, source_database_id, 255,
                                           &source_database_id_indicator;});

                    SQLCHAR owner_sid[255];
                    SQLLEN owner_sid_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::OWNER_SID::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::OWNER_SID::NAME, owner_sid, 255,
                                           &owner_sid_indicator;});

                    SQLCHAR create_date[255];
                    SQLLEN create_date_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::CREATE_DATE::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::CREATE_DATE::NAME, create_date, 255,
                                           &create_date_indicator;});

                    SQLCHAR compatibility_level[255];
                    SQLLEN compatibility_level_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::COMPATIBILITY_LEVEL::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::COMPATIBILITY_LEVEL::NAME, compatibility_level, 255,
                                           &compatibility_level_indicator;});

                    SQLCHAR collation_name[255];
                    SQLLEN collation_name_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::COLLATION_NAME::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::COLLATION_NAME::NAME, collation_name, 255,
                                           &collation_name_indicator;});

                    SQLCHAR user_access[255];
                    SQLLEN user_access_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::USER_ACCESS::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::USER_ACCESS::NAME, user_access, 255,
                                           &user_access_indicator;});

                    SQLCHAR user_access_desc[255];
                    SQLLEN user_access_desc_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::USER_ACCESS_DESC::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::USER_ACCESS_DESC::NAME, user_access_desc, 255,
                                           &user_access_desc_indicator;});

                    SQLCHAR is_read_only[255];
                    SQLLEN is_read_only_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_READ_ONLY::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_READ_ONLY::NAME, is_read_only, 255,
                                           &is_read_only_indicator;});

                    SQLCHAR is_auto_close_on[255];
                    SQLLEN is_auto_close_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_AUTO_CLOSE_ON::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_AUTO_CLOSE_ON::NAME, is_auto_close_on, 255,
                                           &is_auto_close_on_indicator;});

                    SQLCHAR is_auto_shrink_on[255];
                    SQLLEN is_auto_shrink_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_AUTO_SHRINK_ON::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_AUTO_SHRINK_ON::NAME, is_auto_shrink_on, 255,
                                           &is_auto_shrink_on_indicator;});

                    SQLCHAR state[255];
                    SQLLEN state_indicator;
                    colBindings.emplace_back(MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::STATE::INDEX, SQL_C_CHAR,
                                                            SysDatabases::COLUMNS::STATE::NAME, state, 255,
                                                            &state_indicator;});

                    SQLCHAR state_desc[255];
                    SQLLEN state_desc_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::STATE_DESC::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::STATE_DESC::NAME, state_desc, 255,
                                           &state_desc_indicator;});

                    SQLCHAR is_in_standby[255];
                    SQLLEN is_in_standby_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_IN_STANDBY::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_IN_STANDBY::NAME, is_in_standby, 255,
                                           &is_in_standby_indicator;});

                    SQLCHAR is_cleanly_shutdown[255];
                    SQLLEN is_cleanly_shutdown_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_CLEANLY_SHUTDOWN::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_CLEANLY_SHUTDOWN::NAME, is_cleanly_shutdown, 255,
                                           &is_cleanly_shutdown_indicator;});

                    SQLCHAR is_supplemental_logging_enabled[255];
                    SQLLEN is_supplemental_logging_enabled_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_SUPPLEMENTAL_LOGGING_ENABLED::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_SUPPLEMENTAL_LOGGING_ENABLED::NAME,
                                           is_supplemental_logging_enabled, 255,
                                           &is_supplemental_logging_enabled_indicator;});

                    SQLCHAR snapshot_isolation_state[255];
                    SQLLEN snapshot_isolation_state_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE::NAME,
                                           snapshot_isolation_state, 255, &snapshot_isolation_state_indicator;});

                    SQLCHAR snapshot_isolation_state_desc[255];
                    SQLLEN snapshot_isolation_state_desc_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE_DESC::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE_DESC::NAME,
                                           snapshot_isolation_state_desc, 255,
                                           &snapshot_isolation_state_desc_indicator;});

                    SQLCHAR is_read_committed_snapshot_on[255];
                    SQLLEN is_read_committed_snapshot_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_READ_COMMITTED_SNAPSHOT_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_READ_COMMITTED_SNAPSHOT_ON::NAME,
                                           is_read_committed_snapshot_on, 255,
                                           &is_read_committed_snapshot_on_indicator;});

                    SQLCHAR recovery_model[255];
                    SQLLEN recovery_model_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::RECOVERY_MODEL::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::RECOVERY_MODEL::NAME, recovery_model, 255,
                                           &recovery_model_indicator;});

                    SQLCHAR recovery_model_desc[255];
                    SQLLEN recovery_model_desc_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::RECOVERY_MODEL_DESC::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::RECOVERY_MODEL_DESC::NAME, recovery_model_desc, 255,
                                           &recovery_model_desc_indicator;});

                    SQLCHAR page_verify_option[255];
                    SQLLEN page_verify_option_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::PAGE_VERIFY_OPTION::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::PAGE_VERIFY_OPTION::NAME, page_verify_option, 255,
                                           &page_verify_option_indicator;});

                    SQLCHAR page_verify_option_desc[255];
                    SQLLEN page_verify_option_desc_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::PAGE_VERIFY_OPTION_DESC::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::PAGE_VERIFY_OPTION_DESC::NAME,
                                           page_verify_option_desc, 255, &page_verify_option_desc_indicator;});

                    SQLCHAR is_auto_create_stats_on[255];
                    SQLLEN is_auto_create_stats_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_ON::NAME,
                                           is_auto_create_stats_on, 255, &is_auto_create_stats_on_indicator;});

                    SQLCHAR is_auto_create_stats_incremental_on[255];
                    SQLLEN is_auto_create_stats_incremental_on_indicator;
                    colBindings.emplace_back(MSSQLColBinder{SQL_C_CHAR,
                                                            SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_INCREMENTAL_ON::INDEX,
                                                            SQL_C_CHAR,
                                                            SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_INCREMENTAL_ON::NAME,
                                                            is_auto_create_stats_incremental_on, 255,
                                                            &is_auto_create_stats_incremental_on_indicator;});

                    SQLCHAR is_auto_update_stats_on[255];
                    SQLLEN is_auto_update_stats_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ON::NAME,
                                           is_auto_update_stats_on, 255, &is_auto_update_stats_on_indicator;});

                    SQLCHAR is_auto_update_stats_async_on[255];
                    SQLLEN is_auto_update_stats_async_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ASYNC_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ASYNC_ON::NAME,
                                           is_auto_update_stats_async_on, 255,
                                           &is_auto_update_stats_async_on_indicator;});

                    SQLCHAR is_ansi_null_default_on[255];
                    SQLLEN is_ansi_null_default_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_ANSI_NULL_DEFAULT_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_ANSI_NULL_DEFAULT_ON::NAME,
                                           is_ansi_null_default_on, 255, &is_ansi_null_default_on_indicator;});

                    SQLCHAR is_ansi_nulls_on[255];
                    SQLLEN is_ansi_nulls_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_ANSI_NULLS_ON::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_ANSI_NULLS_ON::NAME, is_ansi_nulls_on, 255,
                                           &is_ansi_nulls_on_indicator;});

                    SQLCHAR is_ansi_padding_on[255];
                    SQLLEN is_ansi_padding_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_ANSI_PADDING_ON::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_ANSI_PADDING_ON::NAME, is_ansi_padding_on, 255,
                                           &is_ansi_padding_on_indicator;});

                    SQLCHAR is_ansi_warnings_on[255];
                    SQLLEN is_ansi_warnings_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_ANSI_WARNINGS_ON::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_ANSI_WARNINGS_ON::NAME, is_ansi_warnings_on, 255,
                                           &is_ansi_warnings_on_indicator;});

                    SQLCHAR is_arithabort_on[255];
                    SQLLEN is_arithabort_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_ARITHABORT_ON::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_ARITHABORT_ON::NAME, is_arithabort_on, 255,
                                           &is_arithabort_on_indicator;});

                    SQLCHAR is_concat_null_yields_null_on[255];
                    SQLLEN is_concat_null_yields_null_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_CONCAT_NULL_YIELDS_NULL_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_CONCAT_NULL_YIELDS_NULL_ON::NAME,
                                           is_concat_null_yields_null_on, 255,
                                           &is_concat_null_yields_null_on_indicator;});

                    SQLCHAR is_numeric_roundabort_on[255];
                    SQLLEN is_numeric_roundabort_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_NUMERIC_ROUNDABORT_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_NUMERIC_ROUNDABORT_ON::NAME,
                                           is_numeric_roundabort_on, 255, &is_numeric_roundabort_on_indicator;});

                    SQLCHAR is_quoted_identifier_on[255];
                    SQLLEN is_quoted_identifier_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_QUOTED_IDENTIFIER_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_QUOTED_IDENTIFIER_ON::NAME,
                                           is_quoted_identifier_on, 255, &is_quoted_identifier_on_indicator;});

                    SQLCHAR is_recursive_triggers_on[255];
                    SQLLEN is_recursive_triggers_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_RECURSIVE_TRIGGERS_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_RECURSIVE_TRIGGERS_ON::NAME,
                                           is_recursive_triggers_on, 255, &is_recursive_triggers_on_indicator;});

                    SQLCHAR is_cursor_close_on_commit_on[255];
                    SQLLEN is_cursor_close_on_commit_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_CURSOR_CLOSE_ON_COMMIT_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_CURSOR_CLOSE_ON_COMMIT_ON::NAME,
                                           is_cursor_close_on_commit_on, 255,
                                           &is_cursor_close_on_commit_on_indicator;});

                    SQLCHAR is_local_cursor_default[255];
                    SQLLEN is_local_cursor_default_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_LOCAL_CURSOR_DEFAULT::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_LOCAL_CURSOR_DEFAULT::NAME,
                                           is_local_cursor_default, 255, &is_local_cursor_default_indicator;});

                    SQLCHAR is_fulltext_enabled[255];
                    SQLLEN is_fulltext_enabled_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_FULLTEXT_ENABLED::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_FULLTEXT_ENABLED::NAME, is_fulltext_enabled, 255,
                                           &is_fulltext_enabled_indicator;});

                    SQLCHAR is_trustworthy_on[255];
                    SQLLEN is_trustworthy_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_TRUSTWORTHY_ON::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_TRUSTWORTHY_ON::NAME, is_trustworthy_on, 255,
                                           &is_trustworthy_on_indicator;});

                    SQLCHAR is_db_chaining_on[255];
                    SQLLEN is_db_chaining_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_DB_CHAINING_ON::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_DB_CHAINING_ON::NAME, is_db_chaining_on, 255,
                                           &is_db_chaining_on_indicator;});

                    SQLCHAR is_parameterization_forced[255];
                    SQLLEN is_parameterization_forced_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_PARAMETERIZATION_FORCED::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_PARAMETERIZATION_FORCED::NAME,
                                           is_parameterization_forced, 255, &is_parameterization_forced_indicator;});

                    SQLCHAR is_master_key_encrypted_by_server[255];
                    SQLLEN is_master_key_encrypted_by_server_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_MASTER_KEY_ENCRYPTED_BY_SERVER::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_MASTER_KEY_ENCRYPTED_BY_SERVER::NAME,
                                           is_master_key_encrypted_by_server, 255,
                                           &is_master_key_encrypted_by_server_indicator;});

                    SQLCHAR is_query_store_on[255];
                    SQLLEN is_query_store_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_QUERY_STORE_ON::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_QUERY_STORE_ON::NAME, is_query_store_on, 255,
                                           &is_query_store_on_indicator;});

                    SQLCHAR is_published[255];
                    SQLLEN is_published_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_PUBLISHED::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_PUBLISHED::NAME, is_published, 255,
                                           &is_published_indicator;});

                    SQLCHAR is_subscribed[255];
                    SQLLEN is_subscribed_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_SUBSCRIBED::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_SUBSCRIBED::NAME, is_subscribed, 255,
                                           &is_subscribed_indicator;});

                    SQLCHAR is_merge_published[255];
                    SQLLEN is_merge_published_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_MERGE_PUBLISHED::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_MERGE_PUBLISHED::NAME, is_merge_published, 255,
                                           &is_merge_published_indicator;});

                    SQLCHAR is_distributor[255];
                    SQLLEN is_distributor_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_DISTRIBUTOR::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_DISTRIBUTOR::NAME, is_distributor, 255,
                                           &is_distributor_indicator;});

                    SQLCHAR is_sync_with_backup[255];
                    SQLLEN is_sync_with_backup_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_SYNC_WITH_BACKUP::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_SYNC_WITH_BACKUP::NAME, is_sync_with_backup, 255,
                                           &is_sync_with_backup_indicator;});

                    SQLCHAR service_broker_guid[255];
                    SQLLEN service_broker_guid_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::SERVICE_BROKER_GUID::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::SERVICE_BROKER_GUID::NAME, service_broker_guid, 255,
                                           &service_broker_guid_indicator;});

                    SQLCHAR is_broker_enabled[255];
                    SQLLEN is_broker_enabled_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_BROKER_ENABLED::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_BROKER_ENABLED::NAME, is_broker_enabled, 255,
                                           &is_broker_enabled_indicator;});

                    SQLCHAR log_reuse_wait[255];
                    SQLLEN log_reuse_wait_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::LOG_REUSE_WAIT::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::LOG_REUSE_WAIT::NAME, log_reuse_wait, 255,
                                           &log_reuse_wait_indicator;});

                    SQLCHAR log_reuse_wait_desc[255];
                    SQLLEN log_reuse_wait_desc_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::LOG_REUSE_WAIT_DESC::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::LOG_REUSE_WAIT_DESC::NAME, log_reuse_wait_desc, 255,
                                           &log_reuse_wait_desc_indicator;});

                    SQLCHAR is_date_correlation_on[255];
                    SQLLEN is_date_correlation_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_DATE_CORRELATION_ON::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_DATE_CORRELATION_ON::NAME, is_date_correlation_on,
                                           255, &is_date_correlation_on_indicator;});

                    SQLCHAR is_cdc_enabled[255];
                    SQLLEN is_cdc_enabled_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_CDC_ENABLED::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_CDC_ENABLED::NAME, is_cdc_enabled, 255,
                                           &is_cdc_enabled_indicator;});

                    SQLCHAR is_encrypted[255];
                    SQLLEN is_encrypted_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_ENCRYPTED::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_ENCRYPTED::NAME, is_encrypted, 255,
                                           &is_encrypted_indicator;});

                    SQLCHAR is_honor_broker_priority_on[255];
                    SQLLEN is_honor_broker_priority_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_HONOR_BROKER_PRIORITY_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_HONOR_BROKER_PRIORITY_ON::NAME,
                                           is_honor_broker_priority_on, 255, &is_honor_broker_priority_on_indicator;});

                    SQLCHAR replica_id[255];
                    SQLLEN replica_id_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::REPLICA_ID::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::REPLICA_ID::NAME, replica_id, 255,
                                           &replica_id_indicator;});

                    SQLCHAR group_database_id[255];
                    SQLLEN group_database_id_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::GROUP_DATABASE_ID::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::GROUP_DATABASE_ID::NAME, group_database_id, 255,
                                           &group_database_id_indicator;});

                    SQLCHAR resource_pool_id[255];
                    SQLLEN resource_pool_id_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::RESOURCE_POOL_ID::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::RESOURCE_POOL_ID::NAME, resource_pool_id, 255,
                                           &resource_pool_id_indicator;});

                    SQLCHAR default_language_lcid[255];
                    SQLLEN default_language_lcid_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::DEFAULT_LANGUAGE_LCID::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::DEFAULT_LANGUAGE_LCID::NAME, default_language_lcid,
                                           255, &default_language_lcid_indicator;});

                    SQLCHAR default_language_name[255];
                    SQLLEN default_language_name_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::DEFAULT_LANGUAGE_NAME::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::DEFAULT_LANGUAGE_NAME::NAME, default_language_name,
                                           255, &default_language_name_indicator;});

                    SQLCHAR default_fulltext_language_lcid[255];
                    SQLLEN default_fulltext_language_lcid_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_LCID::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_LCID::NAME,
                                           default_fulltext_language_lcid, 255,
                                           &default_fulltext_language_lcid_indicator;});

                    SQLCHAR default_fulltext_language_name[255];
                    SQLLEN default_fulltext_language_name_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_NAME::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_NAME::NAME,
                                           default_fulltext_language_name, 255,
                                           &default_fulltext_language_name_indicator;});

                    SQLCHAR is_nested_triggers_on[255];
                    SQLLEN is_nested_triggers_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_NESTED_TRIGGERS_ON::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_NESTED_TRIGGERS_ON::NAME, is_nested_triggers_on,
                                           255, &is_nested_triggers_on_indicator;});

                    SQLCHAR is_transform_noise_words_on[255];
                    SQLLEN is_transform_noise_words_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_TRANSFORM_NOISE_WORDS_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_TRANSFORM_NOISE_WORDS_ON::NAME,
                                           is_transform_noise_words_on, 255, &is_transform_noise_words_on_indicator;});

                    SQLCHAR two_digit_year_cutoff[255];
                    SQLLEN two_digit_year_cutoff_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::TWO_DIGIT_YEAR_CUTOFF::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::TWO_DIGIT_YEAR_CUTOFF::NAME, two_digit_year_cutoff,
                                           255, &two_digit_year_cutoff_indicator;});

                    SQLCHAR containment[255];
                    SQLLEN containment_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::CONTAINMENT::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::CONTAINMENT::NAME, containment, 255,
                                           &containment_indicator;});

                    SQLCHAR containment_desc[255];
                    SQLLEN containment_desc_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::CONTAINMENT_DESC::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::CONTAINMENT_DESC::NAME, containment_desc, 255,
                                           &containment_desc_indicator;});

                    SQLCHAR target_recovery_time_in_seconds[255];
                    SQLLEN target_recovery_time_in_seconds_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::TARGET_RECOVERY_TIME_IN_SECONDS::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::TARGET_RECOVERY_TIME_IN_SECONDS::NAME,
                                           target_recovery_time_in_seconds, 255,
                                           &target_recovery_time_in_seconds_indicator;});

                    SQLCHAR delayed_durability[255];
                    SQLLEN delayed_durability_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::DELAYED_DURABILITY::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::DELAYED_DURABILITY::NAME, delayed_durability, 255,
                                           &delayed_durability_indicator;});

                    SQLCHAR delayed_durability_desc[255];
                    SQLLEN delayed_durability_desc_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::DELAYED_DURABILITY_DESC::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::DELAYED_DURABILITY_DESC::NAME,
                                           delayed_durability_desc, 255, &delayed_durability_desc_indicator;});

                    SQLCHAR is_memory_optimized_elevate_to_snapshot_on[255];
                    SQLLEN is_memory_optimized_elevate_to_snapshot_on_indicator;
                    colBindings.emplace_back(MSSQLColBinder{SQL_C_CHAR,
                                                            SysDatabases::COLUMNS::IS_MEMORY_OPTIMIZED_ELEVATE_TO_SNAPSHOT_ON::INDEX,
                                                            SQL_C_CHAR,
                                                            SysDatabases::COLUMNS::IS_MEMORY_OPTIMIZED_ELEVATE_TO_SNAPSHOT_ON::NAME,
                                                            is_memory_optimized_elevate_to_snapshot_on, 255,
                                                            &is_memory_optimized_elevate_to_snapshot_on_indicator;});

                    SQLCHAR is_federation_member[255];
                    SQLLEN is_federation_member_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_FEDERATION_MEMBER::INDEX, SQL_C_CHAR,
                                           SysDatabases::COLUMNS::IS_FEDERATION_MEMBER::NAME, is_federation_member, 255,
                                           &is_federation_member_indicator;});

                    SQLCHAR is_remote_data_archive_enabled[255];
                    SQLLEN is_remote_data_archive_enabled_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_REMOTE_DATA_ARCHIVE_ENABLED::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_REMOTE_DATA_ARCHIVE_ENABLED::NAME,
                                           is_remote_data_archive_enabled, 255,
                                           &is_remote_data_archive_enabled_indicator;});

                    SQLCHAR is_mixed_page_allocation_on[255];
                    SQLLEN is_mixed_page_allocation_on_indicator;
                    colBindings.emplace_back(
                            MSSQLColBinder{SQL_C_CHAR, SysDatabases::COLUMNS::IS_MIXED_PAGE_ALLOCATION_ON::INDEX,
                                           SQL_C_CHAR, SysDatabases::COLUMNS::IS_MIXED_PAGE_ALLOCATION_ON::NAME,
                                           is_mixed_page_allocation_on, 255, &is_mixed_page_allocation_on_indicator;});

                    SQLCHAR is_temporal_history_retention_enabled[255];
                    SQLLEN is_temporal_history_retention_enabled_indicator;
                    colBindings.emplace_back(MSSQLColBinder{SQL_C_CHAR,
                                                            SysDatabases::COLUMNS::IS_TEMPORAL_HISTORY_RETENTION_ENABLED::INDEX,
                                                            SQL_C_CHAR,
                                                            SysDatabases::COLUMNS::IS_TEMPORAL_HISTORY_RETENTION_ENABLED::NAME,
                                                            is_temporal_history_retention_enabled, 255,
                                                            &is_temporal_history_retention_enabled_indicator;});

                    std::vector<MSSQLResultSet> resultSet{};
                    executor.execQuery(GET_SYS_DATABASES, colBindings, resultSet);

                    for (const dbcrudgen::db::mssql::MSSQLResultSet &data: resultSet) {

                        std::string name;
                        int database_id;
                        int source_database_id;
                        std::string owner_sid;
                        std::string create_date;
                        int compatibility_level;
                        std::string collation_name;
                        int user_access;
                        std::string user_access_desc;
                        bool is_read_only;
                        bool is_auto_close_on;
                        bool is_auto_shrink_on;
                        int state;
                        std::string state_desc;
                        bool is_in_standby;
                        bool is_cleanly_shutdown;
                        bool is_supplemental_logging_enabled;
                        int snapshot_isolation_state;
                        std::string snapshot_isolation_state_desc;
                        bool is_read_committed_snapshot_on;
                        int recovery_model;
                        std::string recovery_model_desc;
                        int page_verify_option;
                        std::string page_verify_option_desc;
                        bool is_auto_create_stats_on;
                        bool is_auto_create_stats_incremental_on;
                        bool is_auto_update_stats_on;
                        bool is_auto_update_stats_async_on;
                        bool is_ansi_null_default_on;
                        bool is_ansi_nulls_on;
                        bool is_ansi_padding_on;
                        bool is_ansi_warnings_on;
                        bool is_arithabort_on;
                        bool is_concat_null_yields_null_on;
                        bool is_numeric_roundabort_on;
                        bool is_quoted_identifier_on;
                        bool is_recursive_triggers_on;
                        bool is_cursor_close_on_commit_on;
                        bool is_local_cursor_default;
                        bool is_fulltext_enabled;
                        bool is_trustworthy_on;
                        bool is_db_chaining_on;
                        bool is_parameterization_forced;
                        bool is_master_key_encrypted_by_server;
                        bool is_query_store_on;
                        bool is_published;
                        bool is_subscribed;
                        bool is_merge_published;
                        bool is_distributor;
                        bool is_sync_with_backup;
                        std::string service_broker_guid;
                        bool is_broker_enabled;
                        int log_reuse_wait;
                        std::string log_reuse_wait_desc;
                        bool is_date_correlation_on;
                        bool is_cdc_enabled;
                        bool is_encrypted;
                        bool is_honor_broker_priority_on;
                        std::string replica_id;
                        std::string group_database_id;
                        int resource_pool_id;
                        int default_language_lcid;
                        std::string default_language_name;
                        int default_fulltext_language_lcid;
                        std::string default_fulltext_language_name;
                        bool is_nested_triggers_on;
                        bool is_transform_noise_words_on;
                        int two_digit_year_cutoff;
                        int containment;
                        std::string containment_desc;
                        int target_recovery_time_in_seconds;
                        int delayed_durability;
                        std::string delayed_durability_desc;
                        bool is_memory_optimized_elevate_to_snapshot_on;
                        bool is_federation_member;
                        bool is_remote_data_archive_enabled;
                        bool is_mixed_page_allocation_on;
                        bool is_temporal_history_retention_enabled;

                        void *colValue = data.getColumnValue();

                        switch (data.getColumnIndex()) {
                            case SysDatabases::COLUMNS::NAME::INDEX name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DATABASE_ID::INDEX database_id = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::SOURCE_DATABASE_ID::INDEX source_database_id = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::OWNER_SID::INDEX owner_sid = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::CREATE_DATE::INDEX create_date = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::COMPATIBILITY_LEVEL::INDEX compatibility_level = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::COLLATION_NAME::INDEX collation_name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::USER_ACCESS::INDEX user_access = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::USER_ACCESS_DESC::INDEX user_access_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_READ_ONLY::INDEX is_read_only = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_CLOSE_ON::INDEX is_auto_close_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_SHRINK_ON::INDEX is_auto_shrink_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::STATE::INDEX state = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::STATE_DESC::INDEX state_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_IN_STANDBY::INDEX is_in_standby = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_CLEANLY_SHUTDOWN::INDEX is_cleanly_shutdown = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_SUPPLEMENTAL_LOGGING_ENABLED::INDEX is_supplemental_logging_enabled = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE::INDEX snapshot_isolation_state = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE_DESC::INDEX snapshot_isolation_state_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_READ_COMMITTED_SNAPSHOT_ON::INDEX is_read_committed_snapshot_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::RECOVERY_MODEL::INDEX recovery_model = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::RECOVERY_MODEL_DESC::INDEX recovery_model_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::PAGE_VERIFY_OPTION::INDEX page_verify_option = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::PAGE_VERIFY_OPTION_DESC::INDEX page_verify_option_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_ON::INDEX is_auto_create_stats_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_INCREMENTAL_ON::INDEX is_auto_create_stats_incremental_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ON::INDEX is_auto_update_stats_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ASYNC_ON::INDEX is_auto_update_stats_async_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ANSI_NULL_DEFAULT_ON::INDEX is_ansi_null_default_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ANSI_NULLS_ON::INDEX is_ansi_nulls_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ANSI_PADDING_ON::INDEX is_ansi_padding_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ANSI_WARNINGS_ON::INDEX is_ansi_warnings_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ARITHABORT_ON::INDEX is_arithabort_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_CONCAT_NULL_YIELDS_NULL_ON::INDEX is_concat_null_yields_null_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_NUMERIC_ROUNDABORT_ON::INDEX is_numeric_roundabort_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_QUOTED_IDENTIFIER_ON::INDEX is_quoted_identifier_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_RECURSIVE_TRIGGERS_ON::INDEX is_recursive_triggers_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_CURSOR_CLOSE_ON_COMMIT_ON::INDEX is_cursor_close_on_commit_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_LOCAL_CURSOR_DEFAULT::INDEX is_local_cursor_default = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_FULLTEXT_ENABLED::INDEX is_fulltext_enabled = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_TRUSTWORTHY_ON::INDEX is_trustworthy_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_DB_CHAINING_ON::INDEX is_db_chaining_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_PARAMETERIZATION_FORCED::INDEX is_parameterization_forced = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_MASTER_KEY_ENCRYPTED_BY_SERVER::INDEX is_master_key_encrypted_by_server = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_QUERY_STORE_ON::INDEX is_query_store_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_PUBLISHED::INDEX is_published = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_SUBSCRIBED::INDEX is_subscribed = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_MERGE_PUBLISHED::INDEX is_merge_published = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_DISTRIBUTOR::INDEX is_distributor = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_SYNC_WITH_BACKUP::INDEX is_sync_with_backup = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::SERVICE_BROKER_GUID::INDEX service_broker_guid = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_BROKER_ENABLED::INDEX is_broker_enabled = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::LOG_REUSE_WAIT::INDEX log_reuse_wait = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::LOG_REUSE_WAIT_DESC::INDEX log_reuse_wait_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_DATE_CORRELATION_ON::INDEX is_date_correlation_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_CDC_ENABLED::INDEX is_cdc_enabled = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ENCRYPTED::INDEX is_encrypted = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_HONOR_BROKER_PRIORITY_ON::INDEX is_honor_broker_priority_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::REPLICA_ID::INDEX replica_id = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::GROUP_DATABASE_ID::INDEX group_database_id = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::RESOURCE_POOL_ID::INDEX resource_pool_id = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DEFAULT_LANGUAGE_LCID::INDEX default_language_lcid = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DEFAULT_LANGUAGE_NAME::INDEX default_language_name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_LCID::INDEX default_fulltext_language_lcid = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_NAME::INDEX default_fulltext_language_name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_NESTED_TRIGGERS_ON::INDEX is_nested_triggers_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_TRANSFORM_NOISE_WORDS_ON::INDEX is_transform_noise_words_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::TWO_DIGIT_YEAR_CUTOFF::INDEX two_digit_year_cutoff = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::CONTAINMENT::INDEX containment = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::CONTAINMENT_DESC::INDEX containment_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::TARGET_RECOVERY_TIME_IN_SECONDS::INDEX target_recovery_time_in_seconds = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DELAYED_DURABILITY::INDEX delayed_durability = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DELAYED_DURABILITY_DESC::INDEX delayed_durability_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_MEMORY_OPTIMIZED_ELEVATE_TO_SNAPSHOT_ON::INDEX is_memory_optimized_elevate_to_snapshot_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_FEDERATION_MEMBER::INDEX is_federation_member = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_REMOTE_DATA_ARCHIVE_ENABLED::INDEX is_remote_data_archive_enabled = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_MIXED_PAGE_ALLOCATION_ON::INDEX is_mixed_page_allocation_on = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_TEMPORAL_HISTORY_RETENTION_ENABLED::INDEX is_temporal_history_retention_enabled = *reinterpret_cast<std::string *>(colValue);
                                break;
                        }
                        SysDatabases sysDatabase{name, database_id, source_database_id, owner_sid, create_date,
                                                 compatibility_level, collation_name, user_access, user_access_desc,
                                                 is_read_only, is_auto_close_on, is_auto_shrink_on, state, state_desc,
                                                 is_in_standby, is_cleanly_shutdown, is_supplemental_logging_enabled,
                                                 snapshot_isolation_state, snapshot_isolation_state_desc,
                                                 is_read_committed_snapshot_on, recovery_model, recovery_model_desc,
                                                 page_verify_option, page_verify_option_desc, is_auto_create_stats_on,
                                                 is_auto_create_stats_incremental_on, is_auto_update_stats_on,
                                                 is_auto_update_stats_async_on, is_ansi_null_default_on,
                                                 is_ansi_nulls_on, is_ansi_padding_on, is_ansi_warnings_on,
                                                 is_arithabort_on, is_concat_null_yields_null_on,
                                                 is_numeric_roundabort_on, is_quoted_identifier_on,
                                                 is_recursive_triggers_on, is_cursor_close_on_commit_on,
                                                 is_local_cursor_default, is_fulltext_enabled, is_trustworthy_on,
                                                 is_db_chaining_on, is_parameterization_forced,
                                                 is_master_key_encrypted_by_server, is_query_store_on, is_published,
                                                 is_subscribed, is_merge_published, is_distributor, is_sync_with_backup,
                                                 service_broker_guid, is_broker_enabled, log_reuse_wait,
                                                 log_reuse_wait_desc, is_date_correlation_on, is_cdc_enabled,
                                                 is_encrypted, is_honor_broker_priority_on, replica_id,
                                                 group_database_id, resource_pool_id, default_language_lcid,
                                                 default_language_name, default_fulltext_language_lcid,
                                                 default_fulltext_language_name, is_nested_triggers_on,
                                                 is_transform_noise_words_on, two_digit_year_cutoff, containment,
                                                 containment_desc, target_recovery_time_in_seconds, delayed_durability,
                                                 delayed_durability_desc, is_memory_optimized_elevate_to_snapsh,
                                                 ot_on is_federation_member, is_remote_data_archive_enabled,
                                is_mixed_page_allocation_on, is_temporal_history_retention_enabled};
                        sysDatabases.emplace_back(sysDatabase);
                    }

                    executor.freeStatementHandle();
                }
            };
        }
    }
}

#endif //DBCRUDGEN_CPP_MSSQLDATABASEDECOMPOSER_H
