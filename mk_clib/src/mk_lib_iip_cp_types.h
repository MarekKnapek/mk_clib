#ifndef mk_include_guard_mk_lib_iip_cp_types_h
#define mk_include_guard_mk_lib_iip_cp_types_h


#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha2_256.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_key_enc_elgamal_pri.h"
#include "mk_lib_iip_key_enc_elgamal_pub.h"
#include "mk_lib_iip_key_sgn_dsa_sha1_pri.h"
#include "mk_lib_iip_key_sgn_dsa_sha1_pub.h"
#include "mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub.h"
#include "mk_lib_iip_time.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"


#define mk_sl_cui_t_name mk_lib_iip_cp_types_sessionid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint16
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint16_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_cp_types_sessionid_size_bits_d mk_sl_cui_uint16_size_bits_d
#define mk_lib_iip_cp_types_sessionid_size_bytes_d (mk_sl_cui_uint16_size_bits_d / mk_lang_charbit)

#define mk_sl_cui_t_name mk_lib_iip_cp_types_messageid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_cp_types_messageid_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_lib_iip_cp_types_messageid_size_bytes_d (mk_sl_cui_uint32_size_bits_d / mk_lang_charbit)

#define mk_sl_cui_t_name mk_lib_iip_cp_types_tunnelid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_cp_types_tunnelid_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_lib_iip_cp_types_tunnelid_size_bytes_d (mk_sl_cui_uint32_size_bits_d / mk_lang_charbit)

#define mk_sl_cui_t_name mk_lib_iip_cp_types_requestid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_cp_types_requestid_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_lib_iip_cp_types_requestid_size_bytes_d (mk_sl_cui_uint32_size_bits_d / mk_lang_charbit)

#define mk_sl_cui_t_name mk_lib_iip_cp_types_nonce
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_cp_types_nonce_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_lib_iip_cp_types_nonce_size_bytes_d (mk_sl_cui_uint32_size_bits_d / mk_lang_charbit)

#define mk_sl_cui_t_name mk_lib_iip_cp_types_date
#define mk_sl_cui_t_base_type_name mk_lib_iip_time_timestamp
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lib_iip_time_timestamp_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_cp_types_date_size_bits_d mk_lib_iip_time_timestamp_size_bits_d
#define mk_lib_iip_cp_types_date_size_bytes_d (mk_lib_iip_time_timestamp_size_bits_d / mk_lang_charbit)

struct mk_lib_iip_cp_types_bandwidth_limits_s
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
typedef struct mk_lib_iip_cp_types_bandwidth_limits_s mk_lib_iip_cp_types_bandwidth_limits_t;
mk_lang_typedef(mk_lib_iip_cp_types_bandwidth_limits);

struct mk_lib_iip_cp_types_hash_s
{
	mk_lib_crypto_hash_stream_sha2_256_digest_t m_digest;
};
typedef struct mk_lib_iip_cp_types_hash_s mk_lib_iip_cp_types_hash_t;
mk_lang_typedef(mk_lib_iip_cp_types_hash);

struct mk_lib_iip_cp_types_buffer_s
{
	mk_lang_types_sint_t m_len;
	mk_sl_cui_uint8_t m_buf[64 * 1024];
};
typedef struct mk_lib_iip_cp_types_buffer_s mk_lib_iip_cp_types_buffer_t;
mk_lang_typedef(mk_lib_iip_cp_types_buffer);

struct mk_lib_iip_cp_types_string_s
{
	mk_lang_types_sint_t m_len;
	mk_lang_types_pchar_t m_buf[0xff + 1];
};
typedef struct mk_lib_iip_cp_types_string_s mk_lib_iip_cp_types_string_t;
mk_lang_typedef(mk_lib_iip_cp_types_string);

struct mk_lib_iip_cp_types_strpair_s
{
	mk_lib_iip_cp_types_string_t m_key;
	mk_lib_iip_cp_types_string_t m_val;
};
typedef struct mk_lib_iip_cp_types_strpair_s mk_lib_iip_cp_types_strpair_t;
mk_lang_typedef(mk_lib_iip_cp_types_strpair);

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_types_strpair_rw_construct_void(mk_lib_iip_cp_types_strpair_pt const strpair) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_types_strpair_rw_destroy(mk_lib_iip_cp_types_strpair_pt const strpair) mk_lang_noexcept;

#define mk_sl_fixed_vector_t_name mk_lib_iip_cp_types_strpairs
#define mk_sl_fixed_vector_t_element_type mk_lib_iip_cp_types_strpair_t
#define mk_sl_fixed_vector_t_capacity 16 /* todo */
#define mk_sl_fixed_vector_t_element_construct_void mk_lib_iip_cp_types_strpair_rw_construct_void
#define mk_sl_fixed_vector_t_element_destroy mk_lib_iip_cp_types_strpair_rw_destroy
#include "mk_sl_fixed_vector_inl_fileh.h"
#include "mk_sl_fixed_vector_inl_fileu.h"

struct mk_lib_iip_cp_types_mapping_s
{
	mk_lib_iip_cp_types_strpairs_t m_strpairs;
};
typedef struct mk_lib_iip_cp_types_mapping_s mk_lib_iip_cp_types_mapping_t;
mk_lang_typedef(mk_lib_iip_cp_types_mapping);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_types_hash_and_tunnelid_s
{
	mk_lib_iip_cp_types_hash_t m_router_hash;
	mk_lib_iip_cp_types_tunnelid_t m_tunnel_id;
};
typedef struct mk_lib_iip_cp_types_hash_and_tunnelid_s mk_lib_iip_cp_types_hash_and_tunnelid_t;
mk_lang_typedef(mk_lib_iip_cp_types_hash_and_tunnelid);
#include "mk_lang_warning_msvc_pop.h"

#define mk_sl_fixed_vector_t_name mk_lib_iip_cp_types_hash_and_tunnelids
#define mk_sl_fixed_vector_t_element_type mk_lib_iip_cp_types_hash_and_tunnelid_t
#define mk_sl_fixed_vector_t_capacity 16
#include "mk_sl_fixed_vector_inl_fileh.h"
#include "mk_sl_fixed_vector_inl_fileu.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_types_lease_s
{
	mk_lib_iip_cp_types_hash_t m_router_hash;
	mk_lib_iip_cp_types_tunnelid_t m_tunnel_id;
	mk_lib_iip_cp_types_date_t m_end_date;
};
typedef struct mk_lib_iip_cp_types_lease_s mk_lib_iip_cp_types_lease_t;
mk_lang_typedef(mk_lib_iip_cp_types_lease);
#include "mk_lang_warning_msvc_pop.h"

#define mk_sl_fixed_vector_t_name mk_lib_iip_cp_types_leases
#define mk_sl_fixed_vector_t_element_type mk_lib_iip_cp_types_lease_t
#define mk_sl_fixed_vector_t_capacity 16
#include "mk_sl_fixed_vector_inl_fileh.h"
#include "mk_sl_fixed_vector_inl_fileu.h"

#define mk_sl_vector_t_name mk_lib_iip_cp_types_leasez
#define mk_sl_vector_t_element_type mk_lib_iip_cp_types_lease_t
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_fileu.h"

struct mk_lib_iip_cp_types_destination_buffer_s
{
	mk_sl_cui_uint8_t m_crpt_pub_key[256];
	mk_sl_cui_uint8_t m_sign_pub_key[128];
};
typedef struct mk_lib_iip_cp_types_destination_buffer_s mk_lib_iip_cp_types_destination_buffer_t;
mk_lang_typedef(mk_lib_iip_cp_types_destination_buffer);

enum mk_lib_iip_cp_types_certificate_type_e
{
	mk_lib_iip_cp_types_certificate_type_e_null     = 0,
	mk_lib_iip_cp_types_certificate_type_e_hashcash = 1,
	mk_lib_iip_cp_types_certificate_type_e_hidden   = 2,
	mk_lib_iip_cp_types_certificate_type_e_signed   = 3,
	mk_lib_iip_cp_types_certificate_type_e_multiple = 4,
	mk_lib_iip_cp_types_certificate_type_e_key      = 5,
	mk_lib_iip_cp_types_certificate_type_e_dummy_end
};
typedef enum mk_lib_iip_cp_types_certificate_type_e mk_lib_iip_cp_types_certificate_type_t;
mk_lang_typedef(mk_lib_iip_cp_types_certificate_type);

struct mk_lib_iip_cp_types_certificate_s
{
	mk_lib_iip_cp_types_certificate_type_t m_type;
	mk_lang_types_sint_t m_len;
};
typedef struct mk_lib_iip_cp_types_certificate_s mk_lib_iip_cp_types_certificate_t;
mk_lang_typedef(mk_lib_iip_cp_types_certificate);

enum mk_lib_iip_cp_types_sign_key_type_e
{
	mk_lib_iip_cp_types_sign_key_type_e_dsa_sha1               =  0,
	mk_lib_iip_cp_types_sign_key_type_e_ecdsa_sha256_p256      =  1,
	mk_lib_iip_cp_types_sign_key_type_e_ecdsa_sha384_p384      =  2,
	mk_lib_iip_cp_types_sign_key_type_e_ecdsa_sha512_p521      =  3,
	mk_lib_iip_cp_types_sign_key_type_e_rsa_sha256_2048        =  4,
	mk_lib_iip_cp_types_sign_key_type_e_rsa_sha384_3072        =  5,
	mk_lib_iip_cp_types_sign_key_type_e_rsa_sha512_4096        =  6,
	mk_lib_iip_cp_types_sign_key_type_e_eddsa_sha512_ed25519   =  7,
	mk_lib_iip_cp_types_sign_key_type_e_eddsa_sha512_ed25519ph =  8,
	mk_lib_iip_cp_types_sign_key_type_e_gost_a                 =  9,
	mk_lib_iip_cp_types_sign_key_type_e_gost_b                 = 10,
	mk_lib_iip_cp_types_sign_key_type_e_reddsa_sha512_ed25519  = 11,
	mk_lib_iip_cp_types_sign_key_type_e_dummy_end
};
typedef enum mk_lib_iip_cp_types_sign_key_type_e mk_lib_iip_cp_types_sign_key_type_t;
mk_lang_typedef(mk_lib_iip_cp_types_sign_key_type);

enum mk_lib_iip_cp_types_crpt_key_type_e
{
	mk_lib_iip_cp_types_crpt_key_type_e_elgamal = 0,
	mk_lib_iip_cp_types_crpt_key_type_e_p256    = 1,
	mk_lib_iip_cp_types_crpt_key_type_e_p384    = 2,
	mk_lib_iip_cp_types_crpt_key_type_e_p521    = 3,
	mk_lib_iip_cp_types_crpt_key_type_e_x25519  = 4,
	mk_lib_iip_cp_types_crpt_key_type_e_dummy_end
};
typedef enum mk_lib_iip_cp_types_crpt_key_type_e mk_lib_iip_cp_types_crpt_key_type_t;
mk_lang_typedef(mk_lib_iip_cp_types_crpt_key_type);

enum mk_lib_iip_cp_types_signature_len_e
{
	mk_lib_iip_cp_types_signature_len_e_dsa_sha1               =  40,
	mk_lib_iip_cp_types_signature_len_e_ecdsa_sha256_p256      =  64,
	mk_lib_iip_cp_types_signature_len_e_ecdsa_sha384_p384      =  96,
	mk_lib_iip_cp_types_signature_len_e_ecdsa_sha512_p521      = 132,
	mk_lib_iip_cp_types_signature_len_e_rsa_sha256_2048        = 256,
	mk_lib_iip_cp_types_signature_len_e_rsa_sha384_3072        = 384,
	mk_lib_iip_cp_types_signature_len_e_rsa_sha512_4096        = 512,
	mk_lib_iip_cp_types_signature_len_e_eddsa_sha512_ed25519   =  64,
	mk_lib_iip_cp_types_signature_len_e_eddsa_sha512_ed25519ph =  64,
	mk_lib_iip_cp_types_signature_len_e_gost_a                 =   1, /* todo */
	mk_lib_iip_cp_types_signature_len_e_gost_b                 =   1, /* todo */
	mk_lib_iip_cp_types_signature_len_e_reddsa_sha512_ed25519  =  64,
	mk_lib_iip_cp_types_signature_len_e_dummy_end
};
typedef enum mk_lib_iip_cp_types_signature_len_e mk_lib_iip_cp_types_signature_len_t;
mk_lang_typedef(mk_lib_iip_cp_types_signature_len);

enum mk_lib_iip_cp_types_sign_key_len_e
{
	mk_lib_iip_cp_types_sign_key_len_e_dsa_sha1               = 128,
	mk_lib_iip_cp_types_sign_key_len_e_ecdsa_sha256_p256      =  64,
	mk_lib_iip_cp_types_sign_key_len_e_ecdsa_sha384_p384      =  96,
	mk_lib_iip_cp_types_sign_key_len_e_ecdsa_sha512_p521      = 132,
	mk_lib_iip_cp_types_sign_key_len_e_rsa_sha256_2048        = 256,
	mk_lib_iip_cp_types_sign_key_len_e_rsa_sha384_3072        = 384,
	mk_lib_iip_cp_types_sign_key_len_e_rsa_sha512_4096        = 512,
	mk_lib_iip_cp_types_sign_key_len_e_eddsa_sha512_ed25519   =  32,
	mk_lib_iip_cp_types_sign_key_len_e_eddsa_sha512_ed25519ph =  32,
	mk_lib_iip_cp_types_sign_key_len_e_gost_a                 =  64,
	mk_lib_iip_cp_types_sign_key_len_e_gost_b                 = 128,
	mk_lib_iip_cp_types_sign_key_len_e_reddsa_sha512_ed25519  =  32,
	mk_lib_iip_cp_types_sign_key_len_e_dummy_end
};
typedef enum mk_lib_iip_cp_types_sign_key_len_e mk_lib_iip_cp_types_sign_key_len_t;
mk_lang_typedef(mk_lib_iip_cp_types_sign_key_len);

enum mk_lib_iip_cp_types_crpt_key_len_e
{
	mk_lib_iip_cp_types_crpt_key_len_e_elgamal = 256,
	mk_lib_iip_cp_types_crpt_key_len_e_p256    =  64,
	mk_lib_iip_cp_types_crpt_key_len_e_p384    =  96,
	mk_lib_iip_cp_types_crpt_key_len_e_p521    = 132,
	mk_lib_iip_cp_types_crpt_key_len_e_x25519  =  32,
	mk_lib_iip_cp_types_crpt_key_len_e_dummy_end
};
typedef enum mk_lib_iip_cp_types_crpt_key_len_e mk_lib_iip_cp_types_crpt_key_len_t;
mk_lang_typedef(mk_lib_iip_cp_types_crpt_key_len);

enum mk_lib_iip_cp_types_key_additional_len_worst_sign_e
{
	mk_lib_iip_cp_types_key_additional_len_worst_sign_v = mk_lang_max(1,
		mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(0,
		mk_lib_iip_cp_types_sign_key_len_e_dsa_sha1),
		mk_lib_iip_cp_types_sign_key_len_e_ecdsa_sha256_p256),
		mk_lib_iip_cp_types_sign_key_len_e_ecdsa_sha384_p384),
		mk_lib_iip_cp_types_sign_key_len_e_ecdsa_sha512_p521),
		mk_lib_iip_cp_types_sign_key_len_e_rsa_sha256_2048),
		mk_lib_iip_cp_types_sign_key_len_e_rsa_sha384_3072),
		mk_lib_iip_cp_types_sign_key_len_e_rsa_sha512_4096),
		mk_lib_iip_cp_types_sign_key_len_e_eddsa_sha512_ed25519),
		mk_lib_iip_cp_types_sign_key_len_e_eddsa_sha512_ed25519ph),
		mk_lib_iip_cp_types_sign_key_len_e_gost_a),
		mk_lib_iip_cp_types_sign_key_len_e_gost_b),
		mk_lib_iip_cp_types_sign_key_len_e_reddsa_sha512_ed25519),
		0) - 128)
};
typedef enum mk_lib_iip_cp_types_key_additional_len_worst_sign_e mk_lib_iip_cp_types_key_additional_len_worst_sign_t;
mk_lang_typedef(mk_lib_iip_cp_types_key_additional_len_worst_sign);

enum mk_lib_iip_cp_types_key_additional_len_worst_crpt_e
{
	mk_lib_iip_cp_types_key_additional_len_worst_crpt_v = mk_lang_max(1,
		mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(0,
		mk_lib_iip_cp_types_crpt_key_len_e_elgamal),
		mk_lib_iip_cp_types_crpt_key_len_e_p256),
		mk_lib_iip_cp_types_crpt_key_len_e_p384),
		mk_lib_iip_cp_types_crpt_key_len_e_p521),
		mk_lib_iip_cp_types_crpt_key_len_e_x25519),
		0) - 256)
};
typedef enum mk_lib_iip_cp_types_key_additional_len_worst_crpt_e mk_lib_iip_cp_types_key_additional_len_worst_crpt_t;
mk_lang_typedef(mk_lib_iip_cp_types_key_additional_len_worst_crpt);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_types_keycert_s
{
	mk_lib_iip_cp_types_sign_key_type_t m_sign_type;
	mk_lib_iip_cp_types_crpt_key_type_t m_crpt_type;
	mk_sl_cui_uint8_t m_sign_pub_key[mk_lib_iip_cp_types_key_additional_len_worst_sign_v];
	mk_sl_cui_uint8_t m_crpt_pub_key[mk_lib_iip_cp_types_key_additional_len_worst_crpt_v];
};
typedef struct mk_lib_iip_cp_types_keycert_s mk_lib_iip_cp_types_keycert_t;
mk_lang_typedef(mk_lib_iip_cp_types_keycert);
#include "mk_lang_warning_msvc_pop.h"

union mk_lib_iip_cp_types_cert_data_u
{
	mk_lib_iip_cp_types_keycert_t m_keycert;
};
typedef union mk_lib_iip_cp_types_cert_data_u mk_lib_iip_cp_types_cert_data_t;
struct mk_lib_iip_cp_types_cert_s
{
	mk_lib_iip_cp_types_cert_data_t m_data;
};
typedef struct mk_lib_iip_cp_types_cert_s mk_lib_iip_cp_types_cert_t;
mk_lang_typedef(mk_lib_iip_cp_types_cert);

struct mk_lib_iip_cp_types_destination_with_cert_s
{
	mk_lib_iip_cp_types_destination_buffer_t m_destination_buffer;
	mk_lib_iip_cp_types_certificate_t m_certificate;
	mk_lib_iip_cp_types_cert_t m_cert;
};
typedef struct mk_lib_iip_cp_types_destination_with_cert_s mk_lib_iip_cp_types_destination_with_cert_t;
mk_lang_typedef(mk_lib_iip_cp_types_destination_with_cert);

struct mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_s
{
	mk_lib_iip_key_enc_elgamal_pri_t m_key_elgamal_pri;
	mk_lib_iip_key_enc_elgamal_pub_t m_key_elgamal_pub;
	mk_lib_iip_key_sgn_dsa_sha1_pri_t m_key_dsa_sha1_pri;
	mk_lib_iip_key_sgn_dsa_sha1_pub_t m_key_dsa_sha1_pub;
};
typedef struct mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_s mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_t;
mk_lang_typedef(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1);

#include "mk_lang_warning_msvc_push_c4820.h"
enum mk_lib_iip_cp_types_destination_type_e
{
	mk_lib_iip_cp_types_destination_type_e_elgamal_dsa_sha1,
	mk_lib_iip_cp_types_destination_type_e_dummy_end
};
typedef enum mk_lib_iip_cp_types_destination_type_e mk_lib_iip_cp_types_destination_type_t;
union mk_lib_iip_cp_types_destination_data_u
{
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_t m_elgamal_dsa_sha1;
};
typedef union mk_lib_iip_cp_types_destination_data_u mk_lib_iip_cp_types_destination_data_t;
struct mk_lib_iip_cp_types_destination_s
{
	mk_lib_iip_cp_types_destination_type_t m_type;
	mk_lib_iip_cp_types_destination_data_t m_data;
};
typedef struct mk_lib_iip_cp_types_destination_s mk_lib_iip_cp_types_destination_t;
mk_lang_typedef(mk_lib_iip_cp_types_destination);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_types_remote_destination_elgamal_dsa_sha1_s
{
	mk_lib_iip_key_enc_elgamal_pub_t m_enc_pub;
	mk_lib_iip_key_sgn_dsa_sha1_pub_t m_sgn_pub;
};
typedef struct mk_lib_iip_cp_types_remote_destination_elgamal_dsa_sha1_s mk_lib_iip_cp_types_remote_destination_elgamal_dsa_sha1_t;
mk_lang_typedef(mk_lib_iip_cp_types_remote_destination_elgamal_dsa_sha1);
struct mk_lib_iip_cp_types_remote_destination_elgamal_eddsa_sha512_ed25519_s
{
	mk_lib_iip_key_enc_elgamal_pub_t m_enc_pub;
	mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_t m_sgn_pub;
};
typedef struct mk_lib_iip_cp_types_remote_destination_elgamal_eddsa_sha512_ed25519_s mk_lib_iip_cp_types_remote_destination_elgamal_eddsa_sha512_ed25519_t;
mk_lang_typedef(mk_lib_iip_cp_types_remote_destination_elgamal_eddsa_sha512_ed25519);
enum mk_lib_iip_cp_types_remote_destination_type_e
{
	mk_lib_iip_cp_types_remote_destination_type_e_elgamal_dsa_sha1,
	mk_lib_iip_cp_types_remote_destination_type_e_elgamal_eddsa_sha512_ed25519,
	mk_lib_iip_cp_types_remote_destination_type_e_dummy_end
};
typedef enum mk_lib_iip_cp_types_remote_destination_type_e mk_lib_iip_cp_types_remote_destination_type_t;
union mk_lib_iip_cp_types_remote_destination_data_u
{
	mk_lib_iip_cp_types_remote_destination_elgamal_dsa_sha1_t m_elgamal_dsa_sha1;
	mk_lib_iip_cp_types_remote_destination_elgamal_eddsa_sha512_ed25519_t m_elgamal_eddsa_sha512_ed25519;
};
typedef union mk_lib_iip_cp_types_remote_destination_data_u mk_lib_iip_cp_types_remote_destination_data_t;
struct mk_lib_iip_cp_types_remote_destination_s
{
	mk_lib_iip_cp_types_remote_destination_type_t m_type;
	mk_lib_iip_cp_types_remote_destination_data_t m_data;
};
typedef struct mk_lib_iip_cp_types_remote_destination_s mk_lib_iip_cp_types_remote_destination_t;
mk_lang_typedef(mk_lib_iip_cp_types_remote_destination);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_types_leaseset_s
{
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_t m_destination;
	mk_lib_iip_cp_types_leases_t m_leases;
};
typedef struct mk_lib_iip_cp_types_leaseset_s mk_lib_iip_cp_types_leaseset_t;
mk_lang_typedef(mk_lib_iip_cp_types_leaseset);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_types_session_config_s
{
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_t m_destination;
	mk_lib_iip_cp_types_mapping_t m_options;
	mk_lib_iip_cp_types_date_t m_creation_date;
};
typedef struct mk_lib_iip_cp_types_session_config_s mk_lib_iip_cp_types_session_config_t;
mk_lang_typedef(mk_lib_iip_cp_types_session_config);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_types_get_signature_len(mk_lib_iip_cp_types_sign_key_type_t const key_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_types_get_key_additional_len_sign(mk_lib_iip_cp_types_sign_key_type_t const key_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_types_get_key_additional_len_crpt(mk_lib_iip_cp_types_crpt_key_type_t const key_type) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_types_destination_with_cert_from_u8s(mk_lib_iip_cp_types_destination_with_cert_pt const destination, mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen, mk_lang_types_sint_pt const outlen) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_types_destination_with_cert_from_buffer(mk_lib_iip_cp_types_destination_with_cert_pt const destination, mk_lib_iip_cp_types_buffer_pct const buffer) mk_lang_noexcept;
//mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_generate_random(mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt const destination) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_types.c"
#endif
#endif
