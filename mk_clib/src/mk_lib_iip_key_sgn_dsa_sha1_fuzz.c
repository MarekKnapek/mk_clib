#ifndef mk_include_guard_mk_lib_iip_key_sgn_dsa_sha1_fuzz_c
#define mk_include_guard_mk_lib_iip_key_sgn_dsa_sha1_fuzz_c
#include "mk_lib_iip_key_sgn_dsa_sha1_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_key_sgn_dsa_sha1_portable.h"
#include "mk_lib_iip_key_sgn_dsa_sha1_windows.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_sl_cui_uint8_t raw_pri_key[mk_lib_iip_key_sgn_dsa_sha1_portable_pri_len_v];
	mk_lang_types_bool_t portable_valid;
	mk_lang_types_bool_t windows_valid;
	mk_lang_types_sint_t err;
	mk_lib_iip_key_sgn_dsa_sha1_portable_pri_t portable_pri_key;
	mk_lib_iip_key_sgn_dsa_sha1_windows_pri_t windows_pri_key;
	mk_lang_types_usize_t bit_idx;
	mk_lang_types_usize_t byte_idx;
	mk_lang_types_sint_t message_len;
	mk_sl_cui_uint8_t message_buf[1 * 1024];
	mk_lib_iip_key_sgn_dsa_sha1_portable_digest_t portable_digest;
	mk_lib_iip_key_sgn_dsa_sha1_windows_digest_t windows_digest;
	mk_lib_iip_key_sgn_dsa_sha1_portable_signature_t portable_signature;
	mk_lib_iip_key_sgn_dsa_sha1_windows_signature_t windows_signature;
	mk_lang_types_bool_t portable_validation;
	mk_lang_types_bool_t windows_validation;
	mk_sl_cui_uint8_t tu8;
	mk_sl_cui_uint8_pt pu8;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_portable_pri_len_v)) == ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_len_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_portable_pub_len_v)) == ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_windows_pub_len_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_portable_digest_len_v)) == ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_windows_digest_len_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_portable_signature_len_v)) == ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_windows_signature_len_v)));

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;

	if(!(s >= mk_lang_countof(raw_pri_key)))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&raw_pri_key[0], d, mk_lang_countof(raw_pri_key));
	d += mk_lang_countof(raw_pri_key);
	s -= mk_lang_countof(raw_pri_key);

	err = mk_lib_iip_key_sgn_dsa_sha1_portable_pri_rw_is_valid(&raw_pri_key[0], &portable_valid); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_is_valid(&raw_pri_key[0], &windows_valid); mk_lang_check_rereturn(err);
	mk_lang_test(portable_valid == windows_valid);

	if(!portable_valid)
	{
		return 0;
	}

	err = mk_lib_iip_key_sgn_dsa_sha1_portable_pri_rw_construct_from_u8s(&portable_pri_key, &raw_pri_key[0]); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_construct_from_u8s(&windows_pri_key, &raw_pri_key[0]); mk_lang_check_rereturn(err);

	if(!(s >= mk_lang_bui_usize_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_usize_from_buis_uchar_le(&bit_idx, d);
	bit_idx = bit_idx % ((mk_lib_iip_key_sgn_dsa_sha1_portable_digest_len_v + mk_lib_iip_key_sgn_dsa_sha1_portable_signature_len_v) * mk_lang_charbit);
	byte_idx = bit_idx / mk_lang_charbit;
	bit_idx = bit_idx % mk_lang_charbit;
	d += mk_lang_bui_usize_size_bytes_v;
	s -= mk_lang_bui_usize_size_bytes_v;

	message_len = mk_lang_countof(message_buf);
	message_len = mk_lang_min(message_len, ((mk_lang_types_sint_t)(s)));
	mk_sl_cui_uint8_from_bi_uchar_many(&message_buf[0], d, message_len);
	d += message_len;
	s -= message_len;

	err = mk_lib_iip_key_sgn_dsa_sha1_portable_st_hash_data(&message_buf[0], message_len, &portable_digest); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_dsa_sha1_windows_st_hash_data(&message_buf[0], message_len, &windows_digest); mk_lang_check_rereturn(err);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&portable_digest.m_data.m_uint8s[0], &windows_digest.m_data.m_uint8s[0], mk_lib_iip_key_sgn_dsa_sha1_portable_digest_len_v) == 0);

	err = mk_lib_iip_key_sgn_dsa_sha1_portable_pri_rw_sign_digest(&portable_pri_key, &portable_digest, &portable_signature); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_sign_digest(&windows_pri_key, &windows_digest, &windows_signature); mk_lang_check_rereturn(err);

	err = mk_lib_iip_key_sgn_dsa_sha1_portable_pri_rw_validate_signature(&portable_pri_key, &portable_digest, &portable_signature, &portable_validation); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_validate_signature(&windows_pri_key, &windows_digest, &windows_signature, &windows_validation); mk_lang_check_rereturn(err);
	mk_lang_test(portable_validation);
	mk_lang_test(windows_validation);
	err = mk_lib_iip_key_sgn_dsa_sha1_portable_pri_rw_validate_signature(&portable_pri_key, &portable_digest, ((mk_lib_iip_key_sgn_dsa_sha1_portable_signature_pct)(&windows_signature)), &portable_validation); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_validate_signature(&windows_pri_key, &windows_digest, ((mk_lib_iip_key_sgn_dsa_sha1_windows_signature_pct)(&portable_signature)), &windows_validation); mk_lang_check_rereturn(err);
	mk_lang_test(portable_validation);
	mk_lang_test(windows_validation);

	mk_sl_cui_uint8_set_bit(&tu8, ((mk_lang_types_sint_t)(bit_idx)));
	pu8 = byte_idx < mk_lib_iip_key_sgn_dsa_sha1_portable_digest_len_v ? &portable_digest.m_data.m_uint8s[byte_idx] : &portable_signature.m_data.m_uint8s[byte_idx - mk_lib_iip_key_sgn_dsa_sha1_portable_digest_len_v]; mk_sl_cui_uint8_xor2(pu8, &tu8);
	pu8 = byte_idx < mk_lib_iip_key_sgn_dsa_sha1_portable_digest_len_v ? &windows_digest .m_data.m_uint8s[byte_idx] : &windows_signature .m_data.m_uint8s[byte_idx - mk_lib_iip_key_sgn_dsa_sha1_portable_digest_len_v]; mk_sl_cui_uint8_xor2(pu8, &tu8);

	err = mk_lib_iip_key_sgn_dsa_sha1_portable_pri_rw_validate_signature(&portable_pri_key, &portable_digest, &portable_signature, &portable_validation); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_validate_signature(&windows_pri_key, &windows_digest, &windows_signature, &windows_validation); mk_lang_check_rereturn(err);
	mk_lang_test(!portable_validation);
	mk_lang_test(!windows_validation);
	err = mk_lib_iip_key_sgn_dsa_sha1_portable_pri_rw_validate_signature(&portable_pri_key, &portable_digest, ((mk_lib_iip_key_sgn_dsa_sha1_portable_signature_pct)(&windows_signature)), &portable_validation); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_validate_signature(&windows_pri_key, &windows_digest, ((mk_lib_iip_key_sgn_dsa_sha1_windows_signature_pct)(&portable_signature)), &windows_validation); mk_lang_check_rereturn(err);
	mk_lang_test(!portable_validation);
	mk_lang_test(!windows_validation);

	err = mk_lib_iip_key_sgn_dsa_sha1_portable_pri_rw_destroy(&portable_pri_key); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_destroy(&windows_pri_key); mk_lang_check_rereturn(err);
	return 0;
}


#endif
