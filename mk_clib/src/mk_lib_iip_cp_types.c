#ifndef mk_include_guard_mk_lib_iip_cp_types_c
#define mk_include_guard_mk_lib_iip_cp_types_c
#include "mk_lib_iip_cp_types.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_key_enc_elgamal_pub.h"
#include "mk_lib_iip_key_sgn_dsa_sha1.h"
#include "mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub.h"
#include "mk_lib_iip_time.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


#define mk_sl_cui_t_name mk_lib_iip_cp_types_sessionid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint16
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint16_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_types_messageid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_types_tunnelid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_types_requestid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_types_nonce
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_types_date
#define mk_sl_cui_t_base_type_name mk_lib_iip_time_timestamp
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lib_iip_time_timestamp_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_types_strpair_rw_construct_void(mk_lib_iip_cp_types_strpair_pt const strpair) mk_lang_noexcept
{
	mk_lang_assert(strpair);

	strpair->m_key.m_len = 0;
	strpair->m_val.m_len = 0;
	#if defined DEBUG || defined _DEBUG
	strpair->m_key.m_buf[0] = '\0';
	strpair->m_val.m_buf[0] = '\0';
	#endif
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_types_strpair_rw_destroy(mk_lib_iip_cp_types_strpair_pt const strpair) mk_lang_noexcept
{
	mk_lang_assert(strpair);

	((mk_lang_types_void_t)(strpair));
	return 0;
}

#define mk_sl_fixed_vector_t_name mk_lib_iip_cp_types_strpairs
#define mk_sl_fixed_vector_t_element_type mk_lib_iip_cp_types_strpair_t
#define mk_sl_fixed_vector_t_capacity 16 /* todo */
#define mk_sl_fixed_vector_t_element_construct_void mk_lib_iip_cp_types_strpair_rw_construct_void
#define mk_sl_fixed_vector_t_element_destroy mk_lib_iip_cp_types_strpair_rw_destroy
#include "mk_sl_fixed_vector_inl_filec.h"
#include "mk_sl_fixed_vector_inl_fileu.h"

#define mk_sl_fixed_vector_t_name mk_lib_iip_cp_types_hash_and_tunnelids
#define mk_sl_fixed_vector_t_element_type mk_lib_iip_cp_types_hash_and_tunnelid_t
#define mk_sl_fixed_vector_t_capacity 16
#include "mk_sl_fixed_vector_inl_filec.h"
#include "mk_sl_fixed_vector_inl_fileu.h"

#define mk_sl_fixed_vector_t_name mk_lib_iip_cp_types_leases
#define mk_sl_fixed_vector_t_element_type mk_lib_iip_cp_types_lease_t
#define mk_sl_fixed_vector_t_capacity 16
#include "mk_sl_fixed_vector_inl_filec.h"
#include "mk_sl_fixed_vector_inl_fileu.h"

#define mk_sl_vector_t_name mk_lib_iip_cp_types_leasez
#define mk_sl_vector_t_element_type mk_lib_iip_cp_types_lease_t
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
