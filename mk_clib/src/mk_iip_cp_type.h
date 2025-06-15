#ifndef mk_include_guard_mk_iip_cp_type_h
#define mk_include_guard_mk_iip_cp_type_h


#include "mk_iip_cp_base.h"
#include "mk_iip_cp_mallocator_global.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha2_256.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


struct mk_iip_cp_type_sessionid_s
{
	mk_sl_cui_uint16_t m_id;
};
typedef struct mk_iip_cp_type_sessionid_s mk_iip_cp_type_sessionid_t;
typedef mk_iip_cp_type_sessionid_t const mk_iip_cp_type_sessionid_ct;
typedef mk_iip_cp_type_sessionid_t* mk_iip_cp_type_sessionid_pt;
typedef mk_iip_cp_type_sessionid_t const* mk_iip_cp_type_sessionid_pct;

struct mk_iip_cp_type_messageid_s
{
	mk_sl_cui_uint32_t m_id;
};
typedef struct mk_iip_cp_type_messageid_s mk_iip_cp_type_messageid_t;
typedef mk_iip_cp_type_messageid_t const mk_iip_cp_type_messageid_ct;
typedef mk_iip_cp_type_messageid_t* mk_iip_cp_type_messageid_pt;
typedef mk_iip_cp_type_messageid_t const* mk_iip_cp_type_messageid_pct;

struct mk_iip_cp_type_tunnelid_s
{
	mk_sl_cui_uint32_t m_id;
};
typedef struct mk_iip_cp_type_tunnelid_s mk_iip_cp_type_tunnelid_t;
typedef mk_iip_cp_type_tunnelid_t const mk_iip_cp_type_tunnelid_ct;
typedef mk_iip_cp_type_tunnelid_t* mk_iip_cp_type_tunnelid_pt;
typedef mk_iip_cp_type_tunnelid_t const* mk_iip_cp_type_tunnelid_pct;

struct mk_iip_cp_type_date_s
{
	mk_sl_cui_uint64_t m_ms_since_unix;
};
typedef struct mk_iip_cp_type_date_s mk_iip_cp_type_date_t;
typedef mk_iip_cp_type_date_t const mk_iip_cp_type_date_ct;
typedef mk_iip_cp_type_date_t* mk_iip_cp_type_date_pt;
typedef mk_iip_cp_type_date_t const* mk_iip_cp_type_date_pct;

struct mk_iip_cp_type_bandwidth_limits_s
{
	mk_sl_cui_uint32_t m_client_inbound_limit_kbps;
	mk_sl_cui_uint32_t m_client_outbound_limit_kbps;
	mk_sl_cui_uint32_t m_router_inbound_limit_kbps;
	mk_sl_cui_uint32_t m_router_inbound_burst_limit_kbps;
	mk_sl_cui_uint32_t m_router_outbound_limit_kbps;
	mk_sl_cui_uint32_t m_router_outbound_burst_limit_kbps;
	mk_sl_cui_uint32_t m_router_burst_time_seconds;
	mk_sl_cui_uint32_t m_future_use_1;
	mk_sl_cui_uint32_t m_future_use_2;
	mk_sl_cui_uint32_t m_future_use_3;
	mk_sl_cui_uint32_t m_future_use_4;
	mk_sl_cui_uint32_t m_future_use_5;
	mk_sl_cui_uint32_t m_future_use_6;
	mk_sl_cui_uint32_t m_future_use_7;
	mk_sl_cui_uint32_t m_future_use_8;
	mk_sl_cui_uint32_t m_future_use_9;
};
typedef struct mk_iip_cp_type_bandwidth_limits_s mk_iip_cp_type_bandwidth_limits_t;
typedef mk_iip_cp_type_bandwidth_limits_t const mk_iip_cp_type_bandwidth_limits_ct;
typedef mk_iip_cp_type_bandwidth_limits_t* mk_iip_cp_type_bandwidth_limits_pt;
typedef mk_iip_cp_type_bandwidth_limits_t const* mk_iip_cp_type_bandwidth_limits_pct;

struct mk_iip_cp_type_hash_s
{
	mk_lib_crypto_hash_block_sha2_256_digest_t m_digest;
};
typedef struct mk_iip_cp_type_hash_s mk_iip_cp_type_hash_t;
typedef mk_iip_cp_type_hash_t const mk_iip_cp_type_hash_ct;
typedef mk_iip_cp_type_hash_t* mk_iip_cp_type_hash_pt;
typedef mk_iip_cp_type_hash_t const* mk_iip_cp_type_hash_pct;

struct mk_iip_cp_type_buffer_s
{
	mk_lang_types_sint_t m_len;
	mk_sl_cui_uint8_t m_buf[64 * 1024];
};
typedef struct mk_iip_cp_type_buffer_s mk_iip_cp_type_buffer_t;
typedef mk_iip_cp_type_buffer_t const mk_iip_cp_type_buffer_ct;
typedef mk_iip_cp_type_buffer_t* mk_iip_cp_type_buffer_pt;
typedef mk_iip_cp_type_buffer_t const* mk_iip_cp_type_buffer_pct;

struct mk_iip_cp_type_string_s
{
	mk_lang_types_sint_t m_len;
	mk_lang_types_pchar_t m_buf[0xff + 1];
};
typedef struct mk_iip_cp_type_string_s mk_iip_cp_type_string_t;
typedef mk_iip_cp_type_string_t const mk_iip_cp_type_string_ct;
typedef mk_iip_cp_type_string_t* mk_iip_cp_type_string_pt;
typedef mk_iip_cp_type_string_t const* mk_iip_cp_type_string_pct;

struct mk_iip_cp_type_strpair_s
{
	mk_iip_cp_type_string_t m_key;
	mk_iip_cp_type_string_t m_val;
};
typedef struct mk_iip_cp_type_strpair_s mk_iip_cp_type_strpair_t;
typedef mk_iip_cp_type_strpair_t const mk_iip_cp_type_strpair_ct;
typedef mk_iip_cp_type_strpair_t* mk_iip_cp_type_strpair_pt;
typedef mk_iip_cp_type_strpair_t const* mk_iip_cp_type_strpair_pct;

#define mk_sl_fixed_vector2_t_name mk_iip_cp_type_strpairs
#define mk_sl_fixed_vector2_t_element mk_iip_cp_type_strpair_t
#define mk_sl_fixed_vector2_t_count 16 /* todo */
#include "mk_sl_fixed_vector2_inl_fileh.h"
#include "mk_sl_fixed_vector2_inl_fileu.h"

struct mk_iip_cp_type_mapping_s
{
	mk_iip_cp_type_strpairs_t m_strpairs;
};
typedef struct mk_iip_cp_type_mapping_s mk_iip_cp_type_mapping_t;
typedef mk_iip_cp_type_mapping_t const mk_iip_cp_type_mapping_ct;
typedef mk_iip_cp_type_mapping_t* mk_iip_cp_type_mapping_pt;
typedef mk_iip_cp_type_mapping_t const* mk_iip_cp_type_mapping_pct;

struct mk_iip_cp_type_hash_and_tunnelid_s
{
	mk_iip_cp_type_hash_t m_router_hash;
	mk_iip_cp_type_tunnelid_t m_tunnel_id;
};
typedef struct mk_iip_cp_type_hash_and_tunnelid_s mk_iip_cp_type_hash_and_tunnelid_t;
typedef mk_iip_cp_type_hash_and_tunnelid_t const mk_iip_cp_type_hash_and_tunnelid_ct;
typedef mk_iip_cp_type_hash_and_tunnelid_t* mk_iip_cp_type_hash_and_tunnelid_pt;
typedef mk_iip_cp_type_hash_and_tunnelid_t const* mk_iip_cp_type_hash_and_tunnelid_pct;

#define mk_sl_fixed_vector2_t_name mk_iip_cp_type_hash_and_tunnelids
#define mk_sl_fixed_vector2_t_element mk_iip_cp_type_hash_and_tunnelid_t
#define mk_sl_fixed_vector2_t_count 16
#include "mk_sl_fixed_vector2_inl_fileh.h"
#include "mk_sl_fixed_vector2_inl_fileu.h"

struct mk_iip_cp_type_lease_s
{
	mk_iip_cp_type_hash_t m_router_hash;
	mk_iip_cp_type_tunnelid_t m_tunnel_id;
	mk_iip_cp_type_date_t m_end_date;
};
typedef struct mk_iip_cp_type_lease_s mk_iip_cp_type_lease_t;
typedef mk_iip_cp_type_lease_t const mk_iip_cp_type_lease_ct;
typedef mk_iip_cp_type_lease_t* mk_iip_cp_type_lease_pt;
typedef mk_iip_cp_type_lease_t const* mk_iip_cp_type_lease_pct;

#define mk_sl_fixed_vector2_t_name mk_iip_cp_type_leases
#define mk_sl_fixed_vector2_t_element mk_iip_cp_type_lease_t
#define mk_sl_fixed_vector2_t_count 16
#include "mk_sl_fixed_vector2_inl_fileh.h"
#include "mk_sl_fixed_vector2_inl_fileu.h"

#define mk_sl_vector_t_name mk_iip_cp_type_leasess
#define mk_sl_vector_t_element mk_iip_cp_type_lease_t
#define mk_sl_vector_t_mallocatorg mk_iip_cp_mallocator_global
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_fileu.h"

struct mk_iip_cp_type_destination_buffer_s
{
	mk_sl_cui_uint8_t m_crpt_pub_key[256];
	mk_sl_cui_uint8_t m_sign_pub_key[128];
};
typedef struct mk_iip_cp_type_destination_buffer_s mk_iip_cp_type_destination_buffer_t;
typedef mk_iip_cp_type_destination_buffer_t const mk_iip_cp_type_destination_buffer_ct;
typedef mk_iip_cp_type_destination_buffer_t* mk_iip_cp_type_destination_buffer_pt;
typedef mk_iip_cp_type_destination_buffer_t const* mk_iip_cp_type_destination_buffer_pct;

enum mk_iip_cp_type_certificate_type_e
{
	mk_iip_cp_type_certificate_type_e_null     = 0,
	mk_iip_cp_type_certificate_type_e_hashcash = 1,
	mk_iip_cp_type_certificate_type_e_hidden   = 2,
	mk_iip_cp_type_certificate_type_e_signed   = 3,
	mk_iip_cp_type_certificate_type_e_multiple = 4,
	mk_iip_cp_type_certificate_type_e_key      = 5,
	mk_iip_cp_type_certificate_type_e_dummy_end
};
typedef enum mk_iip_cp_type_certificate_type_e mk_iip_cp_type_certificate_type_t;

struct mk_iip_cp_type_certificate_s
{
	mk_iip_cp_type_certificate_type_t m_type;
	mk_lang_types_sint_t m_len;
};
typedef struct mk_iip_cp_type_certificate_s mk_iip_cp_type_certificate_t;
typedef mk_iip_cp_type_certificate_t const mk_iip_cp_type_certificate_ct;
typedef mk_iip_cp_type_certificate_t* mk_iip_cp_type_certificate_pt;
typedef mk_iip_cp_type_certificate_t const* mk_iip_cp_type_certificate_pct;

enum mk_iip_cp_type_sign_key_type_e
{
	mk_iip_cp_type_sign_key_type_e_dsa_sha1               =  0,
	mk_iip_cp_type_sign_key_type_e_ecdsa_sha256_p256      =  1,
	mk_iip_cp_type_sign_key_type_e_ecdsa_sha384_p384      =  2,
	mk_iip_cp_type_sign_key_type_e_ecdsa_sha512_p521      =  3,
	mk_iip_cp_type_sign_key_type_e_rsa_sha256_2048        =  4,
	mk_iip_cp_type_sign_key_type_e_rsa_sha384_3072        =  5,
	mk_iip_cp_type_sign_key_type_e_rsa_sha512_4096        =  6,
	mk_iip_cp_type_sign_key_type_e_eddsa_sha512_ed25519   =  7,
	mk_iip_cp_type_sign_key_type_e_eddsa_sha512_ed25519ph =  8,
	mk_iip_cp_type_sign_key_type_e_gost_a                 =  9,
	mk_iip_cp_type_sign_key_type_e_gost_b                 = 10,
	mk_iip_cp_type_sign_key_type_e_reddsa_sha512_ed25519  = 11,
	mk_iip_cp_type_sign_key_type_e_dummy_end
};
typedef enum mk_iip_cp_type_sign_key_type_e mk_iip_cp_type_sign_key_type_t;

enum mk_iip_cp_type_crpt_key_type_e
{
	mk_iip_cp_type_crpt_key_type_e_elgamal = 0,
	mk_iip_cp_type_crpt_key_type_e_p256    = 1,
	mk_iip_cp_type_crpt_key_type_e_p384    = 2,
	mk_iip_cp_type_crpt_key_type_e_p521    = 3,
	mk_iip_cp_type_crpt_key_type_e_x25519  = 4,
	mk_iip_cp_type_crpt_key_type_e_dummy_end
};
typedef enum mk_iip_cp_type_crpt_key_type_e mk_iip_cp_type_crpt_key_type_t;

enum mk_iip_cp_type_signature_len_e
{
	mk_iip_cp_type_signature_len_e_dsa_sha1               =  40,
	mk_iip_cp_type_signature_len_e_ecdsa_sha256_p256      =  64,
	mk_iip_cp_type_signature_len_e_ecdsa_sha384_p384      =  96,
	mk_iip_cp_type_signature_len_e_ecdsa_sha512_p521      = 132,
	mk_iip_cp_type_signature_len_e_rsa_sha256_2048        = 256,
	mk_iip_cp_type_signature_len_e_rsa_sha384_3072        = 384,
	mk_iip_cp_type_signature_len_e_rsa_sha512_4096        = 512,
	mk_iip_cp_type_signature_len_e_eddsa_sha512_ed25519   =  64,
	mk_iip_cp_type_signature_len_e_eddsa_sha512_ed25519ph =  64,
	mk_iip_cp_type_signature_len_e_gost_a                 =   1, /* todo */
	mk_iip_cp_type_signature_len_e_gost_b                 =   1, /* todo */
	mk_iip_cp_type_signature_len_e_reddsa_sha512_ed25519  =  64,
	mk_iip_cp_type_signature_len_e_dummy_end
};
typedef enum mk_iip_cp_type_signature_len_e mk_iip_cp_type_signature_len_t;

enum mk_iip_cp_type_sign_key_len_e
{
	mk_iip_cp_type_sign_key_len_e_dsa_sha1               = 128,
	mk_iip_cp_type_sign_key_len_e_ecdsa_sha256_p256      =  64,
	mk_iip_cp_type_sign_key_len_e_ecdsa_sha384_p384      =  96,
	mk_iip_cp_type_sign_key_len_e_ecdsa_sha512_p521      = 132,
	mk_iip_cp_type_sign_key_len_e_rsa_sha256_2048        = 256,
	mk_iip_cp_type_sign_key_len_e_rsa_sha384_3072        = 384,
	mk_iip_cp_type_sign_key_len_e_rsa_sha512_4096        = 512,
	mk_iip_cp_type_sign_key_len_e_eddsa_sha512_ed25519   =  32,
	mk_iip_cp_type_sign_key_len_e_eddsa_sha512_ed25519ph =  32,
	mk_iip_cp_type_sign_key_len_e_gost_a                 =  64,
	mk_iip_cp_type_sign_key_len_e_gost_b                 = 128,
	mk_iip_cp_type_sign_key_len_e_reddsa_sha512_ed25519  =  32,
	mk_iip_cp_type_sign_key_len_e_dummy_end
};
typedef enum mk_iip_cp_type_sign_key_len_e mk_iip_cp_type_sign_key_len_t;

enum mk_iip_cp_type_crpt_key_len_e
{
	mk_iip_cp_type_crpt_key_len_e_elgamal = 256,
	mk_iip_cp_type_crpt_key_len_e_p256    =  64,
	mk_iip_cp_type_crpt_key_len_e_p384    =  96,
	mk_iip_cp_type_crpt_key_len_e_p521    = 132,
	mk_iip_cp_type_crpt_key_len_e_x25519  =  32,
	mk_iip_cp_type_crpt_key_len_e_dummy_end
};
typedef enum mk_iip_cp_type_crpt_key_len_e mk_iip_cp_type_crpt_key_len_t;

enum mk_iip_cp_type_key_additional_len_worst_sign_e
{
	mk_iip_cp_type_key_additional_len_worst_sign_v = mk_lang_max(1,
		mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(0,
		mk_iip_cp_type_sign_key_len_e_dsa_sha1),
		mk_iip_cp_type_sign_key_len_e_ecdsa_sha256_p256),
		mk_iip_cp_type_sign_key_len_e_ecdsa_sha384_p384),
		mk_iip_cp_type_sign_key_len_e_ecdsa_sha512_p521),
		mk_iip_cp_type_sign_key_len_e_rsa_sha256_2048),
		mk_iip_cp_type_sign_key_len_e_rsa_sha384_3072),
		mk_iip_cp_type_sign_key_len_e_rsa_sha512_4096),
		mk_iip_cp_type_sign_key_len_e_eddsa_sha512_ed25519),
		mk_iip_cp_type_sign_key_len_e_eddsa_sha512_ed25519ph),
		mk_iip_cp_type_sign_key_len_e_gost_a),
		mk_iip_cp_type_sign_key_len_e_gost_b),
		mk_iip_cp_type_sign_key_len_e_reddsa_sha512_ed25519),
		0) - 128)
};
typedef enum mk_iip_cp_type_key_additional_len_worst_sign_e mk_iip_cp_type_key_additional_len_worst_sign_t;

enum mk_iip_cp_type_key_additional_len_worst_crpt_e
{
	mk_iip_cp_type_key_additional_len_worst_crpt_v = mk_lang_max(1,
		mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(0,
		mk_iip_cp_type_crpt_key_len_e_elgamal),
		mk_iip_cp_type_crpt_key_len_e_p256),
		mk_iip_cp_type_crpt_key_len_e_p384),
		mk_iip_cp_type_crpt_key_len_e_p521),
		mk_iip_cp_type_crpt_key_len_e_x25519),
		0) - 256)
};
typedef enum mk_iip_cp_type_key_additional_len_worst_crpt_e mk_iip_cp_type_key_additional_len_worst_crpt_t;

struct mk_iip_cp_type_keycert_s
{
	mk_iip_cp_type_sign_key_type_t m_sign_type;
	mk_iip_cp_type_crpt_key_type_t m_crpt_type;
	mk_sl_cui_uint8_t m_sign_pub_key[mk_iip_cp_type_key_additional_len_worst_sign_v];
	mk_sl_cui_uint8_t m_crpt_pub_key[mk_iip_cp_type_key_additional_len_worst_crpt_v];
};
typedef struct mk_iip_cp_type_keycert_s mk_iip_cp_type_keycert_t;
typedef mk_iip_cp_type_keycert_t const mk_iip_cp_type_keycert_ct;
typedef mk_iip_cp_type_keycert_t* mk_iip_cp_type_keycert_pt;
typedef mk_iip_cp_type_keycert_t const* mk_iip_cp_type_keycert_pct;

union mk_iip_cp_type_cert_data_u
{
	mk_iip_cp_type_keycert_t m_keycert;
};
typedef union mk_iip_cp_type_cert_data_u mk_iip_cp_type_cert_data_t;

struct mk_iip_cp_type_cert_s
{
	mk_iip_cp_type_cert_data_t m_data;
};
typedef struct mk_iip_cp_type_cert_s mk_iip_cp_type_cert_t;
typedef mk_iip_cp_type_cert_t const mk_iip_cp_type_cert_ct;
typedef mk_iip_cp_type_cert_t* mk_iip_cp_type_cert_pt;
typedef mk_iip_cp_type_cert_t const* mk_iip_cp_type_cert_pct;

struct mk_iip_cp_type_destination_with_cert_s
{
	mk_iip_cp_type_destination_buffer_t m_destination_buffer;
	mk_iip_cp_type_certificate_t m_certificate;
	mk_iip_cp_type_cert_t m_cert;
};
typedef struct mk_iip_cp_type_destination_with_cert_s mk_iip_cp_type_destination_with_cert_t;
typedef mk_iip_cp_type_destination_with_cert_t const mk_iip_cp_type_destination_with_cert_ct;
typedef mk_iip_cp_type_destination_with_cert_t* mk_iip_cp_type_destination_with_cert_pt;
typedef mk_iip_cp_type_destination_with_cert_t const* mk_iip_cp_type_destination_with_cert_pct;

struct mk_iip_cp_type_destination_elgamal_dsa_s
{
	mk_iip_cp_base_elgamal_key_pri_t m_key_elgamal_pri;
	mk_iip_cp_base_elgamal_key_pub_t m_key_elgamal_pub;
	mk_iip_cp_base_dsa_key_pri_t m_key_dsa_pri;
	mk_iip_cp_base_dsa_key_pub_t m_key_dsa_pub;
};
typedef struct mk_iip_cp_type_destination_elgamal_dsa_s mk_iip_cp_type_destination_elgamal_dsa_t;
typedef mk_iip_cp_type_destination_elgamal_dsa_t const mk_iip_cp_type_destination_elgamal_dsa_ct;
typedef mk_iip_cp_type_destination_elgamal_dsa_t* mk_iip_cp_type_destination_elgamal_dsa_pt;
typedef mk_iip_cp_type_destination_elgamal_dsa_t const* mk_iip_cp_type_destination_elgamal_dsa_pct;

struct mk_iip_cp_type_leaseset_s
{
	mk_iip_cp_type_destination_elgamal_dsa_t m_destination;
	mk_iip_cp_type_leases_t m_leases;
};
typedef struct mk_iip_cp_type_leaseset_s mk_iip_cp_type_leaseset_t;
typedef mk_iip_cp_type_leaseset_t const mk_iip_cp_type_leaseset_ct;
typedef mk_iip_cp_type_leaseset_t* mk_iip_cp_type_leaseset_pt;
typedef mk_iip_cp_type_leaseset_t const* mk_iip_cp_type_leaseset_pct;

struct mk_iip_cp_type_session_config_s
{
	mk_iip_cp_type_destination_elgamal_dsa_t m_destination;
	mk_iip_cp_type_mapping_t m_options;
	mk_iip_cp_type_date_t m_creation_date;
};
typedef struct mk_iip_cp_type_session_config_s mk_iip_cp_type_session_config_t;
typedef mk_iip_cp_type_session_config_t const mk_iip_cp_type_session_config_ct;
typedef mk_iip_cp_type_session_config_t* mk_iip_cp_type_session_config_pt;
typedef mk_iip_cp_type_session_config_t const* mk_iip_cp_type_session_config_pct;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_type_get_signature_len(mk_iip_cp_type_sign_key_type_t const key_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_type_get_key_additional_len_sign(mk_iip_cp_type_sign_key_type_t const key_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_type_get_key_additional_len_crpt(mk_iip_cp_type_crpt_key_type_t const key_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_type_destination_with_cert_from_u8s(mk_iip_cp_type_destination_with_cert_pt const destination, mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen, mk_lang_types_sint_pt const outlen) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_type_destination_with_cert_from_buffer(mk_iip_cp_type_destination_with_cert_pt const destination, mk_iip_cp_type_buffer_pct const buffer) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_type_destination_elgamal_dsa_generate_random(mk_iip_cp_type_destination_elgamal_dsa_pt const destination) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_iip_cp_type.c"
#endif
#endif
