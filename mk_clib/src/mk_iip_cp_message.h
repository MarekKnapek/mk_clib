#ifndef mk_include_guard_mk_iip_cp_message_h
#define mk_include_guard_mk_iip_cp_message_h


#include "mk_iip_cp_type.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


enum mk_iip_cp_message_message_type_e
{
	mk_iip_cp_message_message_type_e_create_session             =  1,
	mk_iip_cp_message_message_type_e_reconfigure_session        =  2,
	mk_iip_cp_message_message_type_e_destroy_session            =  3,
	mk_iip_cp_message_message_type_e_create_lease_set           =  4,
	mk_iip_cp_message_message_type_e_send_message               =  5,
	mk_iip_cp_message_message_type_e_receive_message_begin      =  6,
	mk_iip_cp_message_message_type_e_receive_message_end        =  7,
	mk_iip_cp_message_message_type_e_get_bandwidth_limits       =  8,
	mk_iip_cp_message_message_type_e_session_status             = 20,
	mk_iip_cp_message_message_type_e_request_lease_set          = 21,
	mk_iip_cp_message_message_type_e_message_status             = 22,
	mk_iip_cp_message_message_type_e_bandwidth_limits           = 23,
	mk_iip_cp_message_message_type_e_report_abuse               = 29,
	mk_iip_cp_message_message_type_e_disconnect                 = 30,
	mk_iip_cp_message_message_type_e_message_payload            = 31,
	mk_iip_cp_message_message_type_e_get_date                   = 32,
	mk_iip_cp_message_message_type_e_set_date                   = 33,
	mk_iip_cp_message_message_type_e_dest_lookup                = 34,
	mk_iip_cp_message_message_type_e_dest_reply                 = 35,
	mk_iip_cp_message_message_type_e_send_message_expires       = 36,
	mk_iip_cp_message_message_type_e_request_variable_lease_set = 37,
	mk_iip_cp_message_message_type_e_host_lookup                = 38,
	mk_iip_cp_message_message_type_e_host_reply                 = 39,
	mk_iip_cp_message_message_type_e_create_lease_set2          = 41,
	mk_iip_cp_message_message_type_e_blinding_info              = 42,
	mk_iip_cp_message_message_type_e_dummy_end
};
typedef enum mk_iip_cp_message_message_type_e mk_iip_cp_message_message_type_t;
typedef mk_iip_cp_message_message_type_t* mk_iip_cp_message_message_type_pt;
typedef mk_iip_cp_message_message_type_t const* mk_iip_cp_message_message_type_pct;


enum mk_iip_cp_message_session_status_status_e
{
	mk_iip_cp_message_session_status_status_e_destroyed = 0,
	mk_iip_cp_message_session_status_status_e_created   = 1,
	mk_iip_cp_message_session_status_status_e_updated   = 2,
	mk_iip_cp_message_session_status_status_e_invalid   = 3,
	mk_iip_cp_message_session_status_status_e_refused   = 4,
	mk_iip_cp_message_session_status_status_e_dummy_end
};
typedef enum mk_iip_cp_message_session_status_status_e mk_iip_cp_message_session_status_status_t;
typedef mk_iip_cp_message_session_status_status_t* mk_iip_cp_message_session_status_status_pt;
typedef mk_iip_cp_message_session_status_status_t const* mk_iip_cp_message_session_status_status_pct;

enum mk_iip_cp_message_certificate_type_e
{
	mk_iip_cp_message_certificate_type_e_null     = 0,
	mk_iip_cp_message_certificate_type_e_hashcash = 1,
	mk_iip_cp_message_certificate_type_e_hidden   = 2,
	mk_iip_cp_message_certificate_type_e_signed   = 3,
	mk_iip_cp_message_certificate_type_e_multiple = 4,
	mk_iip_cp_message_certificate_type_e_key      = 5,
	mk_iip_cp_message_certificate_type_e_dummy_end
};
typedef enum mk_iip_cp_message_certificate_type_e mk_iip_cp_message_certificate_type_t;
typedef mk_iip_cp_message_certificate_type_t* mk_iip_cp_message_certificate_type_pt;
typedef mk_iip_cp_message_certificate_type_t const* mk_iip_cp_message_certificate_type_pct;

enum mk_iip_cp_message_host_lookup_request_type_e
{
	mk_iip_cp_message_host_lookup_request_type_e_hash = 0,
	mk_iip_cp_message_host_lookup_request_type_e_name = 1,
	mk_iip_cp_message_host_lookup_request_type_e_dummy_end
};
typedef enum mk_iip_cp_message_host_lookup_request_type_e mk_iip_cp_message_host_lookup_request_type_t;
typedef mk_iip_cp_message_host_lookup_request_type_t* mk_iip_cp_message_host_lookup_request_type_pt;
typedef mk_iip_cp_message_host_lookup_request_type_t const* mk_iip_cp_message_host_lookup_request_type_pct;

enum mk_iip_cp_message_host_reply_result_code_e
{
	mk_iip_cp_message_host_reply_result_code_e_success                                  = 0,
	mk_iip_cp_message_host_reply_result_code_e_failure                                  = 1,
	mk_iip_cp_message_host_reply_result_code_e_lookup_password_required                 = 2,
	mk_iip_cp_message_host_reply_result_code_e_private_key_required                     = 3,
	mk_iip_cp_message_host_reply_result_code_e_lookup_password_and_private_key_required = 4,
	mk_iip_cp_message_host_reply_result_code_e_leaseset_decryption_failure              = 5,
	mk_iip_cp_message_host_reply_result_code_e_dummy_end
};
typedef enum mk_iip_cp_message_host_reply_result_code_e mk_iip_cp_message_host_reply_result_code_t;
typedef mk_iip_cp_message_host_reply_result_code_t* mk_iip_cp_message_host_reply_result_code_pt;
typedef mk_iip_cp_message_host_reply_result_code_t const* mk_iip_cp_message_host_reply_result_code_pct;

enum mk_iip_cp_message_message_status_status_e
{
	mk_iip_cp_message_message_status_status_e_available              =  0,
	mk_iip_cp_message_message_status_status_e_accepted               =  1,
	mk_iip_cp_message_message_status_status_e_best_effort_success    =  2,
	mk_iip_cp_message_message_status_status_e_best_effort_failure    =  3,
	mk_iip_cp_message_message_status_status_e_guaranteed_success     =  4,
	mk_iip_cp_message_message_status_status_e_guaranteed_failure     =  5,
	mk_iip_cp_message_message_status_status_e_local_success          =  6,
	mk_iip_cp_message_message_status_status_e_local_failure          =  7,
	mk_iip_cp_message_message_status_status_e_router_failure         =  8,
	mk_iip_cp_message_message_status_status_e_network_failure        =  9,
	mk_iip_cp_message_message_status_status_e_bad_session            = 10,
	mk_iip_cp_message_message_status_status_e_bad_message            = 11,
	mk_iip_cp_message_message_status_status_e_bad_options            = 12,
	mk_iip_cp_message_message_status_status_e_overflow_failure       = 13,
	mk_iip_cp_message_message_status_status_e_message_expired        = 14,
	mk_iip_cp_message_message_status_status_e_bad_local_leaseset     = 15,
	mk_iip_cp_message_message_status_status_e_no_local_tunnels       = 16,
	mk_iip_cp_message_message_status_status_e_unsupported_encryption = 17,
	mk_iip_cp_message_message_status_status_e_bad_destination        = 18,
	mk_iip_cp_message_message_status_status_e_bad_leaseset           = 19,
	mk_iip_cp_message_message_status_status_e_expired_leaseset       = 20,
	mk_iip_cp_message_message_status_status_e_no_leaseset            = 21,
	mk_iip_cp_message_message_status_status_e_meta_leaseset          = 22,
	mk_iip_cp_message_message_status_status_e_loopback_denied        = 23,
	mk_iip_cp_message_message_status_status_e_dummy_end
};
typedef enum mk_iip_cp_message_message_status_status_e mk_iip_cp_message_message_status_status_t;
typedef mk_iip_cp_message_message_status_status_t* mk_iip_cp_message_message_status_status_pt;
typedef mk_iip_cp_message_message_status_status_t const* mk_iip_cp_message_message_status_status_pct;


#define mk_iip_cp_message_mapping_key_get_date_username_str_buf "i2cp.username"
#define mk_iip_cp_message_mapping_key_get_date_password_str_buf "i2cp.password"
#define mk_iip_cp_message_mapping_val_create_session_inbound_nickname_str_buf "inbound.nickname"
#define mk_iip_cp_message_mapping_val_create_session_outbound_nickname_str_buf "outbound.nickname"
#define mk_iip_cp_message_mapping_key_create_session_message_reliability_str_buf "i2cp.messageReliability"
#define mk_iip_cp_message_mapping_val_create_session_message_reliability_best_effort_str_buf "BestEffort"
#define mk_iip_cp_message_mapping_val_create_session_message_reliability_none_str_buf "None"

#define mk_iip_cp_message_mapping_key_get_date_username_str_len mk_lang_countstr(mk_iip_cp_message_mapping_key_get_date_username_str_buf)
#define mk_iip_cp_message_mapping_key_get_date_password_str_len mk_lang_countstr(mk_iip_cp_message_mapping_key_get_date_password_str_buf)
#define mk_iip_cp_message_mapping_val_create_session_inbound_nickname_str_len mk_lang_countstr(mk_iip_cp_message_mapping_val_create_session_inbound_nickname_str_buf)
#define mk_iip_cp_message_mapping_val_create_session_outbound_nickname_str_len mk_lang_countstr(mk_iip_cp_message_mapping_val_create_session_outbound_nickname_str_buf)
#define mk_iip_cp_message_mapping_key_create_session_message_reliability_str_len mk_lang_countstr(mk_iip_cp_message_mapping_key_create_session_message_reliability_str_buf)
#define mk_iip_cp_message_mapping_val_create_session_message_reliability_best_effort_str_len mk_lang_countstr(mk_iip_cp_message_mapping_val_create_session_message_reliability_best_effort_str_buf)
#define mk_iip_cp_message_mapping_val_create_session_message_reliability_none_str_len mk_lang_countstr(mk_iip_cp_message_mapping_val_create_session_message_reliability_none_str_buf)


struct mk_iip_cp_message_create_session_s
{
	mk_iip_cp_type_session_config_t m_session_config;
};
typedef struct mk_iip_cp_message_create_session_s mk_iip_cp_message_create_session_t;
typedef mk_iip_cp_message_create_session_t const mk_iip_cp_message_create_session_ct;
typedef mk_iip_cp_message_create_session_t* mk_iip_cp_message_create_session_pt;
typedef mk_iip_cp_message_create_session_t const* mk_iip_cp_message_create_session_pct;

struct mk_iip_cp_message_reconfigure_session_s
{
	int m_dummy;
};
typedef struct mk_iip_cp_message_reconfigure_session_s mk_iip_cp_message_reconfigure_session_t;
typedef mk_iip_cp_message_reconfigure_session_t const mk_iip_cp_message_reconfigure_session_ct;
typedef mk_iip_cp_message_reconfigure_session_t* mk_iip_cp_message_reconfigure_session_pt;
typedef mk_iip_cp_message_reconfigure_session_t const* mk_iip_cp_message_reconfigure_session_pct;

struct mk_iip_cp_message_destroy_session_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
};
typedef struct mk_iip_cp_message_destroy_session_s mk_iip_cp_message_destroy_session_t;
typedef mk_iip_cp_message_destroy_session_t const mk_iip_cp_message_destroy_session_ct;
typedef mk_iip_cp_message_destroy_session_t* mk_iip_cp_message_destroy_session_pt;
typedef mk_iip_cp_message_destroy_session_t const* mk_iip_cp_message_destroy_session_pct;

struct mk_iip_cp_message_create_lease_set_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
	mk_iip_cp_base_dsa_key_pri_t m_key_sgn_pri;
	mk_iip_cp_base_elgamal_key_pri_t m_key_enc_pri;
	mk_iip_cp_type_leaseset_t m_leaseset;
};
typedef struct mk_iip_cp_message_create_lease_set_s mk_iip_cp_message_create_lease_set_t;
typedef mk_iip_cp_message_create_lease_set_t const mk_iip_cp_message_create_lease_set_ct;
typedef mk_iip_cp_message_create_lease_set_t* mk_iip_cp_message_create_lease_set_pt;
typedef mk_iip_cp_message_create_lease_set_t const* mk_iip_cp_message_create_lease_set_pct;

struct mk_iip_cp_message_send_message_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
	mk_iip_cp_type_buffer_t m_destination;
	mk_iip_cp_type_buffer_t m_payload;
	mk_sl_cui_uint32_t m_nonce;
};
typedef struct mk_iip_cp_message_send_message_s mk_iip_cp_message_send_message_t;
typedef mk_iip_cp_message_send_message_t const mk_iip_cp_message_send_message_ct;
typedef mk_iip_cp_message_send_message_t* mk_iip_cp_message_send_message_pt;
typedef mk_iip_cp_message_send_message_t const* mk_iip_cp_message_send_message_pct;

struct mk_iip_cp_message_receive_message_begin_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
	mk_iip_cp_type_messageid_t m_message_id;
};
typedef struct mk_iip_cp_message_receive_message_begin_s mk_iip_cp_message_receive_message_begin_t;
typedef mk_iip_cp_message_receive_message_begin_t const mk_iip_cp_message_receive_message_begin_ct;
typedef mk_iip_cp_message_receive_message_begin_t* mk_iip_cp_message_receive_message_begin_pt;
typedef mk_iip_cp_message_receive_message_begin_t const* mk_iip_cp_message_receive_message_begin_pct;

struct mk_iip_cp_message_receive_message_end_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
	mk_iip_cp_type_messageid_t m_message_id;
};
typedef struct mk_iip_cp_message_receive_message_end_s mk_iip_cp_message_receive_message_end_t;
typedef mk_iip_cp_message_receive_message_end_t const mk_iip_cp_message_receive_message_end_ct;
typedef mk_iip_cp_message_receive_message_end_t* mk_iip_cp_message_receive_message_end_pt;
typedef mk_iip_cp_message_receive_message_end_t const* mk_iip_cp_message_receive_message_end_pct;

struct mk_iip_cp_message_get_bandwidth_limits_s
{
#if defined __cplusplus
#else
	mk_lang_types_sint_t m_dummy;
#endif
};
typedef struct mk_iip_cp_message_get_bandwidth_limits_s mk_iip_cp_message_get_bandwidth_limits_t;
typedef mk_iip_cp_message_get_bandwidth_limits_t const mk_iip_cp_message_get_bandwidth_limits_ct;
typedef mk_iip_cp_message_get_bandwidth_limits_t* mk_iip_cp_message_get_bandwidth_limits_pt;
typedef mk_iip_cp_message_get_bandwidth_limits_t const* mk_iip_cp_message_get_bandwidth_limits_pct;

struct mk_iip_cp_message_session_status_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
	mk_iip_cp_message_session_status_status_t m_status;
};
typedef struct mk_iip_cp_message_session_status_s mk_iip_cp_message_session_status_t;
typedef mk_iip_cp_message_session_status_t const mk_iip_cp_message_session_status_ct;
typedef mk_iip_cp_message_session_status_t* mk_iip_cp_message_session_status_pt;
typedef mk_iip_cp_message_session_status_t const* mk_iip_cp_message_session_status_pct;

struct mk_iip_cp_message_request_lease_set_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
	mk_iip_cp_type_hash_and_tunnelids_t m_tunnels;
	mk_iip_cp_type_date_t m_end_date;
};
typedef struct mk_iip_cp_message_request_lease_set_s mk_iip_cp_message_request_lease_set_t;
typedef mk_iip_cp_message_request_lease_set_t const mk_iip_cp_message_request_lease_set_ct;
typedef mk_iip_cp_message_request_lease_set_t* mk_iip_cp_message_request_lease_set_pt;
typedef mk_iip_cp_message_request_lease_set_t const* mk_iip_cp_message_request_lease_set_pct;

struct mk_iip_cp_message_message_status_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
	mk_iip_cp_type_messageid_t m_message_id;
	mk_iip_cp_message_message_status_status_t m_status;
	mk_lang_types_sint_t m_size;
	mk_sl_cui_uint32_t m_nonce;
};
typedef struct mk_iip_cp_message_message_status_s mk_iip_cp_message_message_status_t;
typedef mk_iip_cp_message_message_status_t const mk_iip_cp_message_message_status_ct;
typedef mk_iip_cp_message_message_status_t* mk_iip_cp_message_message_status_pt;
typedef mk_iip_cp_message_message_status_t const* mk_iip_cp_message_message_status_pct;

struct mk_iip_cp_message_bandwidth_limits_s
{
	mk_iip_cp_type_bandwidth_limits_t m_bandwidth_limits;
};
typedef struct mk_iip_cp_message_bandwidth_limits_s mk_iip_cp_message_bandwidth_limits_t;
typedef mk_iip_cp_message_bandwidth_limits_t const mk_iip_cp_message_bandwidth_limits_ct;
typedef mk_iip_cp_message_bandwidth_limits_t* mk_iip_cp_message_bandwidth_limits_pt;
typedef mk_iip_cp_message_bandwidth_limits_t const* mk_iip_cp_message_bandwidth_limits_pct;

struct mk_iip_cp_message_report_abuse_s
{
	int m_dummy;
};
typedef struct mk_iip_cp_message_report_abuse_s mk_iip_cp_message_report_abuse_t;
typedef mk_iip_cp_message_report_abuse_t const mk_iip_cp_message_report_abuse_ct;
typedef mk_iip_cp_message_report_abuse_t* mk_iip_cp_message_report_abuse_pt;
typedef mk_iip_cp_message_report_abuse_t const* mk_iip_cp_message_report_abuse_pct;

struct mk_iip_cp_message_disconnect_s
{
	mk_iip_cp_type_string_t m_reason;
};
typedef struct mk_iip_cp_message_disconnect_s mk_iip_cp_message_disconnect_t;
typedef mk_iip_cp_message_disconnect_t const mk_iip_cp_message_disconnect_ct;
typedef mk_iip_cp_message_disconnect_t* mk_iip_cp_message_disconnect_pt;
typedef mk_iip_cp_message_disconnect_t const* mk_iip_cp_message_disconnect_pct;

struct mk_iip_cp_message_message_payload_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
	mk_iip_cp_type_messageid_t m_message_id;
	mk_iip_cp_type_buffer_t m_payload;
};
typedef struct mk_iip_cp_message_message_payload_s mk_iip_cp_message_message_payload_t;
typedef mk_iip_cp_message_message_payload_t const mk_iip_cp_message_message_payload_ct;
typedef mk_iip_cp_message_message_payload_t* mk_iip_cp_message_message_payload_pt;
typedef mk_iip_cp_message_message_payload_t const* mk_iip_cp_message_message_payload_pct;

struct mk_iip_cp_message_get_date_s
{
	mk_iip_cp_type_string_t m_client_version;
	mk_iip_cp_type_mapping_t m_authentication;
};
typedef struct mk_iip_cp_message_get_date_s mk_iip_cp_message_get_date_t;
typedef mk_iip_cp_message_get_date_t const mk_iip_cp_message_get_date_ct;
typedef mk_iip_cp_message_get_date_t* mk_iip_cp_message_get_date_pt;
typedef mk_iip_cp_message_get_date_t const* mk_iip_cp_message_get_date_pct;

struct mk_iip_cp_message_set_date_s
{
	mk_iip_cp_type_date_t m_server_date;
	mk_iip_cp_type_string_t m_server_version;
};
typedef struct mk_iip_cp_message_set_date_s mk_iip_cp_message_set_date_t;
typedef mk_iip_cp_message_set_date_t const mk_iip_cp_message_set_date_ct;
typedef mk_iip_cp_message_set_date_t* mk_iip_cp_message_set_date_pt;
typedef mk_iip_cp_message_set_date_t const* mk_iip_cp_message_set_date_pct;

struct mk_iip_cp_message_dest_lookup_s
{
	int m_dummy;
};
typedef struct mk_iip_cp_message_dest_lookup_s mk_iip_cp_message_dest_lookup_t;
typedef mk_iip_cp_message_dest_lookup_t const mk_iip_cp_message_dest_lookup_ct;
typedef mk_iip_cp_message_dest_lookup_t* mk_iip_cp_message_dest_lookup_pt;
typedef mk_iip_cp_message_dest_lookup_t const* mk_iip_cp_message_dest_lookup_pct;

struct mk_iip_cp_message_dest_reply_s
{
	int m_dummy;
};
typedef struct mk_iip_cp_message_dest_reply_s mk_iip_cp_message_dest_reply_t;
typedef mk_iip_cp_message_dest_reply_t const mk_iip_cp_message_dest_reply_ct;
typedef mk_iip_cp_message_dest_reply_t* mk_iip_cp_message_dest_reply_pt;
typedef mk_iip_cp_message_dest_reply_t const* mk_iip_cp_message_dest_reply_pct;

struct mk_iip_cp_message_send_message_expires_s
{
	int m_dummy;
};
typedef struct mk_iip_cp_message_send_message_expires_s mk_iip_cp_message_send_message_expires_t;
typedef mk_iip_cp_message_send_message_expires_t const mk_iip_cp_message_send_message_expires_ct;
typedef mk_iip_cp_message_send_message_expires_t* mk_iip_cp_message_send_message_expires_pt;
typedef mk_iip_cp_message_send_message_expires_t const* mk_iip_cp_message_send_message_expires_pct;

struct mk_iip_cp_message_request_variable_lease_set_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
	mk_iip_cp_type_leases_t m_leases;
};
typedef struct mk_iip_cp_message_request_variable_lease_set_s mk_iip_cp_message_request_variable_lease_set_t;
typedef mk_iip_cp_message_request_variable_lease_set_t const mk_iip_cp_message_request_variable_lease_set_ct;
typedef mk_iip_cp_message_request_variable_lease_set_t* mk_iip_cp_message_request_variable_lease_set_pt;
typedef mk_iip_cp_message_request_variable_lease_set_t const* mk_iip_cp_message_request_variable_lease_set_pct;

struct mk_iip_cp_message_host_lookup_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
	mk_sl_cui_uint32_t m_request_id;
	mk_lang_types_sint_t m_timeout_ms;
	mk_iip_cp_message_host_lookup_request_type_t m_request_type;
	mk_iip_cp_type_string_t m_hostname;
};
typedef struct mk_iip_cp_message_host_lookup_s mk_iip_cp_message_host_lookup_t;
typedef mk_iip_cp_message_host_lookup_t const mk_iip_cp_message_host_lookup_ct;
typedef mk_iip_cp_message_host_lookup_t* mk_iip_cp_message_host_lookup_pt;
typedef mk_iip_cp_message_host_lookup_t const* mk_iip_cp_message_host_lookup_pct;

struct mk_iip_cp_message_host_reply_s
{
	mk_iip_cp_type_sessionid_t m_session_id;
	mk_sl_cui_uint32_t m_request_id;
	mk_iip_cp_message_host_reply_result_code_t m_result_code;
	mk_iip_cp_type_buffer_t m_destination;
};
typedef struct mk_iip_cp_message_host_reply_s mk_iip_cp_message_host_reply_t;
typedef mk_iip_cp_message_host_reply_t const mk_iip_cp_message_host_reply_ct;
typedef mk_iip_cp_message_host_reply_t* mk_iip_cp_message_host_reply_pt;
typedef mk_iip_cp_message_host_reply_t const* mk_iip_cp_message_host_reply_pct;

struct mk_iip_cp_message_create_lease_set2_s
{
	int m_dummy;
};
typedef struct mk_iip_cp_message_create_lease_set2_s mk_iip_cp_message_create_lease_set2_t;
typedef mk_iip_cp_message_create_lease_set2_t const mk_iip_cp_message_create_lease_set2_ct;
typedef mk_iip_cp_message_create_lease_set2_t* mk_iip_cp_message_create_lease_set2_pt;
typedef mk_iip_cp_message_create_lease_set2_t const* mk_iip_cp_message_create_lease_set2_pct;

struct mk_iip_cp_message_blinding_info_s
{
	int m_dummy;
};
typedef struct mk_iip_cp_message_blinding_info_s mk_iip_cp_message_blinding_info_t;
typedef mk_iip_cp_message_blinding_info_t const mk_iip_cp_message_blinding_info_ct;
typedef mk_iip_cp_message_blinding_info_t* mk_iip_cp_message_blinding_info_pt;
typedef mk_iip_cp_message_blinding_info_t const* mk_iip_cp_message_blinding_info_pct;


struct mk_iip_cp_message_header_s
{
	mk_lang_types_sint_t m_len;
	mk_iip_cp_message_message_type_t m_type;
};
typedef struct mk_iip_cp_message_header_s mk_iip_cp_message_header_t;
typedef mk_iip_cp_message_header_t const mk_iip_cp_message_header_ct;
typedef mk_iip_cp_message_header_t* mk_iip_cp_message_header_pt;
typedef mk_iip_cp_message_header_t const* mk_iip_cp_message_header_pct;

union mk_iip_cp_message_mix_data_u
{
	mk_iip_cp_message_create_session_t             m_create_session            ;
	mk_iip_cp_message_reconfigure_session_t        m_reconfigure_session       ;
	mk_iip_cp_message_destroy_session_t            m_destroy_session           ;
	mk_iip_cp_message_create_lease_set_t           m_create_lease_set          ;
	mk_iip_cp_message_send_message_t               m_send_message              ;
	mk_iip_cp_message_receive_message_begin_t      m_receive_message_begin     ;
	mk_iip_cp_message_receive_message_end_t        m_receive_message_end       ;
	mk_iip_cp_message_get_bandwidth_limits_t       m_get_bandwidth_limits      ;
	mk_iip_cp_message_session_status_t             m_session_status            ;
	mk_iip_cp_message_request_lease_set_t          m_request_lease_set         ;
	mk_iip_cp_message_message_status_t             m_message_status            ;
	mk_iip_cp_message_bandwidth_limits_t           m_bandwidth_limits          ;
	mk_iip_cp_message_report_abuse_t               m_report_abuse              ;
	mk_iip_cp_message_disconnect_t                 m_disconnect                ;
	mk_iip_cp_message_message_payload_t            m_message_payload           ;
	mk_iip_cp_message_get_date_t                   m_get_date                  ;
	mk_iip_cp_message_set_date_t                   m_set_date                  ;
	mk_iip_cp_message_dest_lookup_t                m_dest_lookup               ;
	mk_iip_cp_message_dest_reply_t                 m_dest_reply                ;
	mk_iip_cp_message_send_message_expires_t       m_send_message_expires      ;
	mk_iip_cp_message_request_variable_lease_set_t m_request_variable_lease_set;
	mk_iip_cp_message_host_lookup_t                m_host_lookup               ;
	mk_iip_cp_message_host_reply_t                 m_host_reply                ;
	mk_iip_cp_message_create_lease_set2_t          m_create_lease_set2         ;
	mk_iip_cp_message_blinding_info_t              m_blinding_info             ;
};
typedef union mk_iip_cp_message_mix_data_u mk_iip_cp_message_mix_data_t;
typedef mk_iip_cp_message_mix_data_t const mk_iip_cp_message_mix_data_ct;
typedef mk_iip_cp_message_mix_data_t* mk_iip_cp_message_mix_data_pt;
typedef mk_iip_cp_message_mix_data_t const* mk_iip_cp_message_mix_data_pct;

struct mk_iip_cp_message_mix_s
{
	mk_iip_cp_message_mix_data_t m_data;
};
typedef struct mk_iip_cp_message_mix_s mk_iip_cp_message_mix_t;
typedef mk_iip_cp_message_mix_t const mk_iip_cp_message_mix_ct;
typedef mk_iip_cp_message_mix_t* mk_iip_cp_message_mix_pt;
typedef mk_iip_cp_message_mix_t const* mk_iip_cp_message_mix_pct;


struct mk_iip_cp_message_s
{
	mk_iip_cp_message_header_t m_header;
	mk_iip_cp_message_mix_t m_mix;
};
typedef struct mk_iip_cp_message_s mk_iip_cp_message_t;
typedef mk_iip_cp_message_t const mk_iip_cp_message_ct;
typedef mk_iip_cp_message_t* mk_iip_cp_message_pt;
typedef mk_iip_cp_message_t const* mk_iip_cp_message_pct;
typedef mk_iip_cp_message_pt const mk_iip_cp_message_cpt;
typedef mk_iip_cp_message_pt* mk_iip_cp_message_ppt;
typedef mk_iip_cp_message_pt const* mk_iip_cp_message_pcpt;
typedef mk_iip_cp_message_pct const mk_iip_cp_message_cpct;
typedef mk_iip_cp_message_pct* mk_iip_cp_message_ppct;
typedef mk_iip_cp_message_pct const* mk_iip_cp_message_pcpct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_message_is_server_to_client(mk_iip_cp_message_message_type_t const message_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_message_is_client_to_server(mk_iip_cp_message_message_type_t const message_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_message_is_per_connection(mk_iip_cp_message_message_type_t const message_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_message_is_per_session(mk_iip_cp_message_message_type_t const message_type) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_construct(mk_iip_cp_message_pt const message, mk_iip_cp_message_message_type_t const type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_destroy(mk_iip_cp_message_pt const message) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_reconstruct(mk_iip_cp_message_pt const message, mk_iip_cp_message_message_type_t const type) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_iip_cp_message.c"
#endif
#endif
