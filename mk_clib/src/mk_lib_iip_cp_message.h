#ifndef mk_include_guard_mk_lib_iip_cp_message_h
#define mk_include_guard_mk_lib_iip_cp_message_h


#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_iip_crypt_dsa_sha1.h"
#include "mk_lib_iip_crypt_elgamal.h"


enum mk_lib_iip_cp_message_message_type_id_e
{
	mk_lib_iip_cp_message_message_type_id_e_create_session,
	mk_lib_iip_cp_message_message_type_id_e_reconfigure_session,
	mk_lib_iip_cp_message_message_type_id_e_destroy_session,
	mk_lib_iip_cp_message_message_type_id_e_create_lease_set,
	mk_lib_iip_cp_message_message_type_id_e_send_message,
	mk_lib_iip_cp_message_message_type_id_e_receive_message_begin,
	mk_lib_iip_cp_message_message_type_id_e_receive_message_end,
	mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits,
	mk_lib_iip_cp_message_message_type_id_e_session_status,
	mk_lib_iip_cp_message_message_type_id_e_request_lease_set,
	mk_lib_iip_cp_message_message_type_id_e_message_status,
	mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits,
	mk_lib_iip_cp_message_message_type_id_e_report_abuse,
	mk_lib_iip_cp_message_message_type_id_e_disconnect,
	mk_lib_iip_cp_message_message_type_id_e_message_payload,
	mk_lib_iip_cp_message_message_type_id_e_get_date,
	mk_lib_iip_cp_message_message_type_id_e_set_date,
	mk_lib_iip_cp_message_message_type_id_e_dest_lookup,
	mk_lib_iip_cp_message_message_type_id_e_dest_reply,
	mk_lib_iip_cp_message_message_type_id_e_send_message_expires,
	mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set,
	mk_lib_iip_cp_message_message_type_id_e_host_lookup,
	mk_lib_iip_cp_message_message_type_id_e_host_reply,
	mk_lib_iip_cp_message_message_type_id_e_create_lease_set2,
	mk_lib_iip_cp_message_message_type_id_e_blinding_info,
	mk_lib_iip_cp_message_message_type_id_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_message_type_id_e mk_lib_iip_cp_message_message_type_id_t;
mk_lang_typedef(mk_lib_iip_cp_message_message_type_id);

enum mk_lib_iip_cp_message_message_type_val_e
{
	mk_lib_iip_cp_message_message_type_val_e_create_session             =  1,
	mk_lib_iip_cp_message_message_type_val_e_reconfigure_session        =  2,
	mk_lib_iip_cp_message_message_type_val_e_destroy_session            =  3,
	mk_lib_iip_cp_message_message_type_val_e_create_lease_set           =  4,
	mk_lib_iip_cp_message_message_type_val_e_send_message               =  5,
	mk_lib_iip_cp_message_message_type_val_e_receive_message_begin      =  6,
	mk_lib_iip_cp_message_message_type_val_e_receive_message_end        =  7,
	mk_lib_iip_cp_message_message_type_val_e_get_bandwidth_limits       =  8,
	mk_lib_iip_cp_message_message_type_val_e_session_status             = 20,
	mk_lib_iip_cp_message_message_type_val_e_request_lease_set          = 21,
	mk_lib_iip_cp_message_message_type_val_e_message_status             = 22,
	mk_lib_iip_cp_message_message_type_val_e_bandwidth_limits           = 23,
	mk_lib_iip_cp_message_message_type_val_e_report_abuse               = 29,
	mk_lib_iip_cp_message_message_type_val_e_disconnect                 = 30,
	mk_lib_iip_cp_message_message_type_val_e_message_payload            = 31,
	mk_lib_iip_cp_message_message_type_val_e_get_date                   = 32,
	mk_lib_iip_cp_message_message_type_val_e_set_date                   = 33,
	mk_lib_iip_cp_message_message_type_val_e_dest_lookup                = 34,
	mk_lib_iip_cp_message_message_type_val_e_dest_reply                 = 35,
	mk_lib_iip_cp_message_message_type_val_e_send_message_expires       = 36,
	mk_lib_iip_cp_message_message_type_val_e_request_variable_lease_set = 37,
	mk_lib_iip_cp_message_message_type_val_e_host_lookup                = 38,
	mk_lib_iip_cp_message_message_type_val_e_host_reply                 = 39,
	mk_lib_iip_cp_message_message_type_val_e_create_lease_set2          = 41,
	mk_lib_iip_cp_message_message_type_val_e_blinding_info              = 42,
	mk_lib_iip_cp_message_message_type_val_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_message_type_val_e mk_lib_iip_cp_message_message_type_val_t;
mk_lang_typedef(mk_lib_iip_cp_message_message_type_val);

enum mk_lib_iip_cp_message_session_status_status_id_e
{
	mk_lib_iip_cp_message_session_status_status_id_e_destroyed,
	mk_lib_iip_cp_message_session_status_status_id_e_created,
	mk_lib_iip_cp_message_session_status_status_id_e_updated,
	mk_lib_iip_cp_message_session_status_status_id_e_invalid,
	mk_lib_iip_cp_message_session_status_status_id_e_refused,
	mk_lib_iip_cp_message_session_status_status_id_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_session_status_status_id_e mk_lib_iip_cp_message_session_status_status_id_t;
mk_lang_typedef(mk_lib_iip_cp_message_session_status_status_id);

enum mk_lib_iip_cp_message_session_status_status_val_e
{
	mk_lib_iip_cp_message_session_status_status_val_e_destroyed = 0,
	mk_lib_iip_cp_message_session_status_status_val_e_created   = 1,
	mk_lib_iip_cp_message_session_status_status_val_e_updated   = 2,
	mk_lib_iip_cp_message_session_status_status_val_e_invalid   = 3,
	mk_lib_iip_cp_message_session_status_status_val_e_refused   = 4,
	mk_lib_iip_cp_message_session_status_status_val_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_session_status_status_val_e mk_lib_iip_cp_message_session_status_status_val_t;
mk_lang_typedef(mk_lib_iip_cp_message_session_status_status_val);

enum mk_lib_iip_cp_message_message_status_status_id_e
{
	mk_lib_iip_cp_message_message_status_status_id_e_available,
	mk_lib_iip_cp_message_message_status_status_id_e_accepted,
	mk_lib_iip_cp_message_message_status_status_id_e_best_effort_success,
	mk_lib_iip_cp_message_message_status_status_id_e_best_effort_failure,
	mk_lib_iip_cp_message_message_status_status_id_e_guaranteed_success,
	mk_lib_iip_cp_message_message_status_status_id_e_guaranteed_failure,
	mk_lib_iip_cp_message_message_status_status_id_e_local_success,
	mk_lib_iip_cp_message_message_status_status_id_e_local_failure,
	mk_lib_iip_cp_message_message_status_status_id_e_router_failure,
	mk_lib_iip_cp_message_message_status_status_id_e_network_failure,
	mk_lib_iip_cp_message_message_status_status_id_e_bad_session,
	mk_lib_iip_cp_message_message_status_status_id_e_bad_message,
	mk_lib_iip_cp_message_message_status_status_id_e_bad_options,
	mk_lib_iip_cp_message_message_status_status_id_e_overflow_failure,
	mk_lib_iip_cp_message_message_status_status_id_e_message_expired,
	mk_lib_iip_cp_message_message_status_status_id_e_bad_local_leaseset,
	mk_lib_iip_cp_message_message_status_status_id_e_no_local_tunnels,
	mk_lib_iip_cp_message_message_status_status_id_e_unsupported_encryption,
	mk_lib_iip_cp_message_message_status_status_id_e_bad_destination,
	mk_lib_iip_cp_message_message_status_status_id_e_bad_leaseset,
	mk_lib_iip_cp_message_message_status_status_id_e_expired_leaseset,
	mk_lib_iip_cp_message_message_status_status_id_e_no_leaseset,
	mk_lib_iip_cp_message_message_status_status_id_e_meta_leaseset,
	mk_lib_iip_cp_message_message_status_status_id_e_loopback_denied,
	mk_lib_iip_cp_message_message_status_status_id_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_message_status_status_id_e mk_lib_iip_cp_message_message_status_status_id_t;
mk_lang_typedef(mk_lib_iip_cp_message_message_status_status_id);

enum mk_lib_iip_cp_message_message_status_status_val_e
{
	mk_lib_iip_cp_message_message_status_status_val_e_available              =  0,
	mk_lib_iip_cp_message_message_status_status_val_e_accepted               =  1,
	mk_lib_iip_cp_message_message_status_status_val_e_best_effort_success    =  2,
	mk_lib_iip_cp_message_message_status_status_val_e_best_effort_failure    =  3,
	mk_lib_iip_cp_message_message_status_status_val_e_guaranteed_success     =  4,
	mk_lib_iip_cp_message_message_status_status_val_e_guaranteed_failure     =  5,
	mk_lib_iip_cp_message_message_status_status_val_e_local_success          =  6,
	mk_lib_iip_cp_message_message_status_status_val_e_local_failure          =  7,
	mk_lib_iip_cp_message_message_status_status_val_e_router_failure         =  8,
	mk_lib_iip_cp_message_message_status_status_val_e_network_failure        =  9,
	mk_lib_iip_cp_message_message_status_status_val_e_bad_session            = 10,
	mk_lib_iip_cp_message_message_status_status_val_e_bad_message            = 11,
	mk_lib_iip_cp_message_message_status_status_val_e_bad_options            = 12,
	mk_lib_iip_cp_message_message_status_status_val_e_overflow_failure       = 13,
	mk_lib_iip_cp_message_message_status_status_val_e_message_expired        = 14,
	mk_lib_iip_cp_message_message_status_status_val_e_bad_local_leaseset     = 15,
	mk_lib_iip_cp_message_message_status_status_val_e_no_local_tunnels       = 16,
	mk_lib_iip_cp_message_message_status_status_val_e_unsupported_encryption = 17,
	mk_lib_iip_cp_message_message_status_status_val_e_bad_destination        = 18,
	mk_lib_iip_cp_message_message_status_status_val_e_bad_leaseset           = 19,
	mk_lib_iip_cp_message_message_status_status_val_e_expired_leaseset       = 20,
	mk_lib_iip_cp_message_message_status_status_val_e_no_leaseset            = 21,
	mk_lib_iip_cp_message_message_status_status_val_e_meta_leaseset          = 22,
	mk_lib_iip_cp_message_message_status_status_val_e_loopback_denied        = 23,
	mk_lib_iip_cp_message_message_status_status_val_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_message_status_status_val_e mk_lib_iip_cp_message_message_status_status_val_t;
mk_lang_typedef(mk_lib_iip_cp_message_message_status_status_val);

enum mk_lib_iip_cp_message_host_reply_result_code_id_e
{
	mk_lib_iip_cp_message_host_reply_result_code_id_e_success,
	mk_lib_iip_cp_message_host_reply_result_code_id_e_failure,
	mk_lib_iip_cp_message_host_reply_result_code_id_e_lookup_password_required,
	mk_lib_iip_cp_message_host_reply_result_code_id_e_private_key_required,
	mk_lib_iip_cp_message_host_reply_result_code_id_e_lookup_password_and_private_key_required,
	mk_lib_iip_cp_message_host_reply_result_code_id_e_leaseset_decryption_failure,
	mk_lib_iip_cp_message_host_reply_result_code_id_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_host_reply_result_code_id_e mk_lib_iip_cp_message_host_reply_result_code_id_t;
mk_lang_typedef(mk_lib_iip_cp_message_host_reply_result_code_id);

enum mk_lib_iip_cp_message_host_reply_result_code_val_e
{
	mk_lib_iip_cp_message_host_reply_result_code_val_e_success                                  = 0,
	mk_lib_iip_cp_message_host_reply_result_code_val_e_failure                                  = 1,
	mk_lib_iip_cp_message_host_reply_result_code_val_e_lookup_password_required                 = 2,
	mk_lib_iip_cp_message_host_reply_result_code_val_e_private_key_required                     = 3,
	mk_lib_iip_cp_message_host_reply_result_code_val_e_lookup_password_and_private_key_required = 4,
	mk_lib_iip_cp_message_host_reply_result_code_val_e_leaseset_decryption_failure              = 5,
	mk_lib_iip_cp_message_host_reply_result_code_val_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_host_reply_result_code_val_e mk_lib_iip_cp_message_host_reply_result_code_val_t;
mk_lang_typedef(mk_lib_iip_cp_message_host_reply_result_code_val);

enum mk_lib_iip_cp_message_certificate_type_id_e
{
	mk_lib_iip_cp_message_certificate_type_id_e_null,
	mk_lib_iip_cp_message_certificate_type_id_e_hashcash,
	mk_lib_iip_cp_message_certificate_type_id_e_hidden,
	mk_lib_iip_cp_message_certificate_type_id_e_signed,
	mk_lib_iip_cp_message_certificate_type_id_e_multiple,
	mk_lib_iip_cp_message_certificate_type_id_e_key,
	mk_lib_iip_cp_message_certificate_type_id_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_certificate_type_id_e mk_lib_iip_cp_message_certificate_type_id_t;
mk_lang_typedef(mk_lib_iip_cp_message_certificate_type_id);

enum mk_lib_iip_cp_message_host_lookup_request_type_id_e
{
	mk_lib_iip_cp_message_host_lookup_request_type_id_e_hash,
	mk_lib_iip_cp_message_host_lookup_request_type_id_e_name,
	mk_lib_iip_cp_message_host_lookup_request_type_id_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_host_lookup_request_type_id_e mk_lib_iip_cp_message_host_lookup_request_type_id_t;
mk_lang_typedef(mk_lib_iip_cp_message_host_lookup_request_type_id);


#define mk_lib_iip_cp_message_mapping_key_get_date_username_str_buf "i2cp.username"
#define mk_lib_iip_cp_message_mapping_key_get_date_password_str_buf "i2cp.password"
#define mk_lib_iip_cp_message_mapping_val_create_session_inbound_nickname_str_buf "inbound.nickname"
#define mk_lib_iip_cp_message_mapping_val_create_session_outbound_nickname_str_buf "outbound.nickname"
#define mk_lib_iip_cp_message_mapping_key_create_session_message_reliability_str_buf "i2cp.messageReliability"
#define mk_lib_iip_cp_message_mapping_val_create_session_message_reliability_best_effort_str_buf "BestEffort"
#define mk_lib_iip_cp_message_mapping_val_create_session_message_reliability_none_str_buf "None"

#define mk_lib_iip_cp_message_mapping_key_get_date_username_str_len mk_lang_countstr(mk_lib_iip_cp_message_mapping_key_get_date_username_str_buf)
#define mk_lib_iip_cp_message_mapping_key_get_date_password_str_len mk_lang_countstr(mk_lib_iip_cp_message_mapping_key_get_date_password_str_buf)
#define mk_lib_iip_cp_message_mapping_val_create_session_inbound_nickname_str_len mk_lang_countstr(mk_lib_iip_cp_message_mapping_val_create_session_inbound_nickname_str_buf)
#define mk_lib_iip_cp_message_mapping_val_create_session_outbound_nickname_str_len mk_lang_countstr(mk_lib_iip_cp_message_mapping_val_create_session_outbound_nickname_str_buf)
#define mk_lib_iip_cp_message_mapping_key_create_session_message_reliability_str_len mk_lang_countstr(mk_lib_iip_cp_message_mapping_key_create_session_message_reliability_str_buf)
#define mk_lib_iip_cp_message_mapping_val_create_session_message_reliability_best_effort_str_len mk_lang_countstr(mk_lib_iip_cp_message_mapping_val_create_session_message_reliability_best_effort_str_buf)
#define mk_lib_iip_cp_message_mapping_val_create_session_message_reliability_none_str_len mk_lang_countstr(mk_lib_iip_cp_message_mapping_val_create_session_message_reliability_none_str_buf)


struct mk_lib_iip_cp_message_create_session_s
{
	mk_lib_iip_cp_types_session_config_t m_session_config;
};
typedef struct mk_lib_iip_cp_message_create_session_s mk_lib_iip_cp_message_create_session_t;
mk_lang_typedef(mk_lib_iip_cp_message_create_session);

struct mk_lib_iip_cp_message_reconfigure_session_s
{
	int m_dummy;
};
typedef struct mk_lib_iip_cp_message_reconfigure_session_s mk_lib_iip_cp_message_reconfigure_session_t;
mk_lang_typedef(mk_lib_iip_cp_message_reconfigure_session);

struct mk_lib_iip_cp_message_destroy_session_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
};
typedef struct mk_lib_iip_cp_message_destroy_session_s mk_lib_iip_cp_message_destroy_session_t;
mk_lang_typedef(mk_lib_iip_cp_message_destroy_session);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_create_lease_set_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
	mk_lib_iip_crypt_dsa_sha1_key_pri_t m_key_sgn_pri;
	mk_lib_iip_crypt_elgamal_key_pri_t m_key_enc_pri;
	mk_lib_iip_cp_types_leaseset_t m_leaseset;
};
typedef struct mk_lib_iip_cp_message_create_lease_set_s mk_lib_iip_cp_message_create_lease_set_t;
mk_lang_typedef(mk_lib_iip_cp_message_create_lease_set);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_send_message_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
	mk_lib_iip_cp_types_buffer_t m_destination;
	mk_lib_iip_cp_types_buffer_t m_payload;
	mk_lib_iip_cp_types_nonce_t m_nonce;
};
typedef struct mk_lib_iip_cp_message_send_message_s mk_lib_iip_cp_message_send_message_t;
mk_lang_typedef(mk_lib_iip_cp_message_send_message);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_receive_message_begin_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
	mk_lib_iip_cp_types_messageid_t m_message_id;
};
typedef struct mk_lib_iip_cp_message_receive_message_begin_s mk_lib_iip_cp_message_receive_message_begin_t;
mk_lang_typedef(mk_lib_iip_cp_message_receive_message_begin);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_receive_message_end_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
	mk_lib_iip_cp_types_messageid_t m_message_id;
};
typedef struct mk_lib_iip_cp_message_receive_message_end_s mk_lib_iip_cp_message_receive_message_end_t;
mk_lang_typedef(mk_lib_iip_cp_message_receive_message_end);
#include "mk_lang_warning_msvc_pop.h"

struct mk_lib_iip_cp_message_get_bandwidth_limits_s
{
#if defined __cplusplus
#else
	mk_lang_types_sint_t m_dummy;
#endif
};
typedef struct mk_lib_iip_cp_message_get_bandwidth_limits_s mk_lib_iip_cp_message_get_bandwidth_limits_t;
mk_lang_typedef(mk_lib_iip_cp_message_get_bandwidth_limits);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_session_status_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
	mk_lib_iip_cp_message_session_status_status_id_t m_status;
};
typedef struct mk_lib_iip_cp_message_session_status_s mk_lib_iip_cp_message_session_status_t;
mk_lang_typedef(mk_lib_iip_cp_message_session_status);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_request_lease_set_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
	mk_lib_iip_cp_types_hash_and_tunnelids_t m_tunnels;
	mk_lib_iip_cp_types_date_t m_end_date;
};
typedef struct mk_lib_iip_cp_message_request_lease_set_s mk_lib_iip_cp_message_request_lease_set_t;
mk_lang_typedef(mk_lib_iip_cp_message_request_lease_set);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_message_status_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
	mk_lib_iip_cp_types_messageid_t m_message_id;
	mk_lib_iip_cp_message_message_status_status_id_t m_status;
	mk_lang_types_sint_t m_size;
	mk_lib_iip_cp_types_nonce_t m_nonce;
};
typedef struct mk_lib_iip_cp_message_message_status_s mk_lib_iip_cp_message_message_status_t;
mk_lang_typedef(mk_lib_iip_cp_message_message_status);
#include "mk_lang_warning_msvc_pop.h"

struct mk_lib_iip_cp_message_bandwidth_limits_s
{
	mk_lib_iip_cp_types_bandwidth_limits_t m_bandwidth_limits;
};
typedef struct mk_lib_iip_cp_message_bandwidth_limits_s mk_lib_iip_cp_message_bandwidth_limits_t;
mk_lang_typedef(mk_lib_iip_cp_message_bandwidth_limits);

struct mk_lib_iip_cp_message_report_abuse_s
{
	int m_dummy;
};
typedef struct mk_lib_iip_cp_message_report_abuse_s mk_lib_iip_cp_message_report_abuse_t;
mk_lang_typedef(mk_lib_iip_cp_message_report_abuse);

struct mk_lib_iip_cp_message_disconnect_s
{
	mk_lib_iip_cp_types_string_t m_reason;
};
typedef struct mk_lib_iip_cp_message_disconnect_s mk_lib_iip_cp_message_disconnect_t;
mk_lang_typedef(mk_lib_iip_cp_message_disconnect);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_message_payload_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
	mk_lib_iip_cp_types_messageid_t m_message_id;
	mk_lib_iip_cp_types_buffer_t m_payload;
};
typedef struct mk_lib_iip_cp_message_message_payload_s mk_lib_iip_cp_message_message_payload_t;
mk_lang_typedef(mk_lib_iip_cp_message_message_payload);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_get_date_s
{
	mk_lib_iip_cp_types_string_t m_client_version;
	mk_lib_iip_cp_types_mapping_t m_authentication;
};
typedef struct mk_lib_iip_cp_message_get_date_s mk_lib_iip_cp_message_get_date_t;
mk_lang_typedef(mk_lib_iip_cp_message_get_date);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_set_date_s
{
	mk_lib_iip_cp_types_date_t m_server_date;
	mk_lib_iip_cp_types_string_t m_server_version;
};
typedef struct mk_lib_iip_cp_message_set_date_s mk_lib_iip_cp_message_set_date_t;
mk_lang_typedef(mk_lib_iip_cp_message_set_date);
#include "mk_lang_warning_msvc_pop.h"

struct mk_lib_iip_cp_message_dest_lookup_s
{
	int m_dummy;
};
typedef struct mk_lib_iip_cp_message_dest_lookup_s mk_lib_iip_cp_message_dest_lookup_t;
mk_lang_typedef(mk_lib_iip_cp_message_dest_lookup);

struct mk_lib_iip_cp_message_dest_reply_s
{
	int m_dummy;
};
typedef struct mk_lib_iip_cp_message_dest_reply_s mk_lib_iip_cp_message_dest_reply_t;
mk_lang_typedef(mk_lib_iip_cp_message_dest_reply);

struct mk_lib_iip_cp_message_send_message_expires_s
{
	int m_dummy;
};
typedef struct mk_lib_iip_cp_message_send_message_expires_s mk_lib_iip_cp_message_send_message_expires_t;
mk_lang_typedef(mk_lib_iip_cp_message_send_message_expires);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_request_variable_lease_set_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
	mk_lib_iip_cp_types_leases_t m_leases;
};
typedef struct mk_lib_iip_cp_message_request_variable_lease_set_s mk_lib_iip_cp_message_request_variable_lease_set_t;
mk_lang_typedef(mk_lib_iip_cp_message_request_variable_lease_set);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_host_lookup_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
	mk_lib_iip_cp_types_requestid_t m_request_id;
	mk_lang_types_sint_t m_timeout_ms;
	mk_lib_iip_cp_message_host_lookup_request_type_id_t m_request_type;
	mk_lib_iip_cp_types_string_t m_hostname;
};
typedef struct mk_lib_iip_cp_message_host_lookup_s mk_lib_iip_cp_message_host_lookup_t;
mk_lang_typedef(mk_lib_iip_cp_message_host_lookup);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_host_reply_s
{
	mk_lib_iip_cp_types_sessionid_t m_session_id;
	mk_lib_iip_cp_types_requestid_t m_request_id;
	mk_lib_iip_cp_message_host_reply_result_code_id_t m_result_code;
	mk_lib_iip_cp_types_buffer_t m_destination;
};
typedef struct mk_lib_iip_cp_message_host_reply_s mk_lib_iip_cp_message_host_reply_t;
mk_lang_typedef(mk_lib_iip_cp_message_host_reply);
#include "mk_lang_warning_msvc_pop.h"

struct mk_lib_iip_cp_message_create_lease_set2_s
{
	int m_dummy;
};
typedef struct mk_lib_iip_cp_message_create_lease_set2_s mk_lib_iip_cp_message_create_lease_set2_t;
mk_lang_typedef(mk_lib_iip_cp_message_create_lease_set2);

struct mk_lib_iip_cp_message_blinding_info_s
{
	int m_dummy;
};
typedef struct mk_lib_iip_cp_message_blinding_info_s mk_lib_iip_cp_message_blinding_info_t;
mk_lang_typedef(mk_lib_iip_cp_message_blinding_info);


struct mk_lib_iip_cp_message_header_s
{
	mk_lang_types_sint_t m_len;
	mk_lib_iip_cp_message_message_type_id_t m_type;
};
typedef struct mk_lib_iip_cp_message_header_s mk_lib_iip_cp_message_header_t;
mk_lang_typedef(mk_lib_iip_cp_message_header);

union mk_lib_iip_cp_message_mix_data_u
{
	mk_lib_iip_cp_message_create_session_t             m_create_session            ;
	mk_lib_iip_cp_message_reconfigure_session_t        m_reconfigure_session       ;
	mk_lib_iip_cp_message_destroy_session_t            m_destroy_session           ;
	mk_lib_iip_cp_message_create_lease_set_t           m_create_lease_set          ;
	mk_lib_iip_cp_message_send_message_t               m_send_message              ;
	mk_lib_iip_cp_message_receive_message_begin_t      m_receive_message_begin     ;
	mk_lib_iip_cp_message_receive_message_end_t        m_receive_message_end       ;
	mk_lib_iip_cp_message_get_bandwidth_limits_t       m_get_bandwidth_limits      ;
	mk_lib_iip_cp_message_session_status_t             m_session_status            ;
	mk_lib_iip_cp_message_request_lease_set_t          m_request_lease_set         ;
	mk_lib_iip_cp_message_message_status_t             m_message_status            ;
	mk_lib_iip_cp_message_bandwidth_limits_t           m_bandwidth_limits          ;
	mk_lib_iip_cp_message_report_abuse_t               m_report_abuse              ;
	mk_lib_iip_cp_message_disconnect_t                 m_disconnect                ;
	mk_lib_iip_cp_message_message_payload_t            m_message_payload           ;
	mk_lib_iip_cp_message_get_date_t                   m_get_date                  ;
	mk_lib_iip_cp_message_set_date_t                   m_set_date                  ;
	mk_lib_iip_cp_message_dest_lookup_t                m_dest_lookup               ;
	mk_lib_iip_cp_message_dest_reply_t                 m_dest_reply                ;
	mk_lib_iip_cp_message_send_message_expires_t       m_send_message_expires      ;
	mk_lib_iip_cp_message_request_variable_lease_set_t m_request_variable_lease_set;
	mk_lib_iip_cp_message_host_lookup_t                m_host_lookup               ;
	mk_lib_iip_cp_message_host_reply_t                 m_host_reply                ;
	mk_lib_iip_cp_message_create_lease_set2_t          m_create_lease_set2         ;
	mk_lib_iip_cp_message_blinding_info_t              m_blinding_info             ;
};
typedef union mk_lib_iip_cp_message_mix_data_u mk_lib_iip_cp_message_mix_data_t;
struct mk_lib_iip_cp_message_mix_s
{
	mk_lib_iip_cp_message_mix_data_t m_data;
};
typedef struct mk_lib_iip_cp_message_mix_s mk_lib_iip_cp_message_mix_t;
mk_lang_typedef(mk_lib_iip_cp_message_mix);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_message_s
{
	mk_lib_iip_cp_message_header_t m_header;
	mk_lib_iip_cp_message_mix_t m_mix;
};
typedef struct mk_lib_iip_cp_message_s mk_lib_iip_cp_message_t;
mk_lang_typedef(mk_lib_iip_cp_message);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_message_type_val_is_known(mk_lang_types_sint_t const message_type_val) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lib_iip_cp_message_message_type_id_t mk_lib_iip_cp_message_message_type_val_to_message_type_id(mk_lib_iip_cp_message_message_type_val_t const message_type_val) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_session_status_status_val_is_known(mk_lang_types_sint_t const session_status_status_val) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lib_iip_cp_message_session_status_status_id_t mk_lib_iip_cp_message_session_status_status_val_to_session_status_status_id(mk_lib_iip_cp_message_session_status_status_val_t const session_status_status_val) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_message_status_status_val_is_known(mk_lang_types_sint_t const message_status_status_val) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lib_iip_cp_message_message_status_status_id_t mk_lib_iip_cp_message_message_status_status_val_to_message_status_status_id(mk_lib_iip_cp_message_message_status_status_val_t const message_status_status_val) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_host_reply_result_code_val_is_known(mk_lang_types_sint_t const host_reply_result_code_val) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lib_iip_cp_message_host_reply_result_code_id_t mk_lib_iip_cp_message_host_reply_result_code_val_to_host_reply_result_code_id(mk_lib_iip_cp_message_host_reply_result_code_val_t const host_reply_result_code_val) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_is_server_to_client(mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_is_client_to_server(mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_is_per_connection(mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_is_per_session(mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct(mk_lib_iip_cp_message_pt const message, mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy(mk_lib_iip_cp_message_pt const message) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_reconstruct(mk_lib_iip_cp_message_pt const message, mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_message.c"
#endif
#endif
