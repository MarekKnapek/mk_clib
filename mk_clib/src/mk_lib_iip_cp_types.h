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
#include "mk_lib_iip_cp_local_destination.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_key_enc_elgamal_pri.h"
#include "mk_lib_iip_key_enc_elgamal_pub.h"
#include "mk_lib_iip_key_sgn_dsa_sha1.h"
#include "mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub.h"
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

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_types_leaseset_s
{
	mk_lib_iip_cp_local_destination_t m_local_destination;
	mk_lib_iip_cp_types_leases_t m_leases;
};
typedef struct mk_lib_iip_cp_types_leaseset_s mk_lib_iip_cp_types_leaseset_t;
mk_lang_typedef(mk_lib_iip_cp_types_leaseset);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_types_session_config_s
{
	mk_lib_iip_cp_local_destination_t m_local_destination;
	mk_lib_iip_cp_types_mapping_t m_options;
	mk_lib_iip_cp_types_date_t m_creation_date;
};
typedef struct mk_lib_iip_cp_types_session_config_s mk_lib_iip_cp_types_session_config_t;
mk_lang_typedef(mk_lib_iip_cp_types_session_config);
#include "mk_lang_warning_msvc_pop.h"


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_types.c"
#endif
#endif
