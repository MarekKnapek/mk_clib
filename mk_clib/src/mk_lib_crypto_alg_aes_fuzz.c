#ifndef mk_include_guard_mk_lib_crypto_alg_aes_fuzz_c
#define mk_include_guard_mk_lib_crypto_alg_aes_fuzz_c
#include "mk_lib_crypto_alg_aes_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_aes_128.h"
#include "mk_lib_crypto_alg_aes_192.h"
#include "mk_lib_crypto_alg_aes_256.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"
#include "mk_win_base.h"
#include "mk_win_dll_bcrypt.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_aes_fuzz_encrypt_my(mk_sl_cui_uint8_pct const key_buf, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pct const msg_buf, mk_lang_types_usize_t const block_count, mk_sl_cui_uint8_pt const out_buf) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_128_msg_pct in_128;
	mk_lib_crypto_alg_aes_128_msg_pt out_128;
	mk_lib_crypto_alg_aes_128_key_t key_128;
	mk_lib_crypto_alg_aes_128_schedule_t schedule_128;
	mk_lib_crypto_alg_aes_192_msg_pct in_192;
	mk_lib_crypto_alg_aes_192_msg_pt out_192;
	mk_lib_crypto_alg_aes_192_key_t key_192;
	mk_lib_crypto_alg_aes_192_schedule_t schedule_192;
	mk_lib_crypto_alg_aes_256_msg_pct in_256;
	mk_lib_crypto_alg_aes_256_msg_pt out_256;
	mk_lib_crypto_alg_aes_256_key_t key_256;
	mk_lib_crypto_alg_aes_256_schedule_t schedule_256;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(key_buf);
	mk_lang_assert(key_len == 128 / mk_lang_charbit || key_len == 192 / mk_lang_charbit || key_len == 256 / mk_lang_charbit);
	mk_lang_assert(msg_buf);
	mk_lang_assert(block_count >= 1);
	mk_lang_assert(out_buf);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	switch(key_len)
	{
		case 128 / mk_lang_charbit:
		{
			mk_lang_assert(((mk_lang_types_uintptr_t)(msg_buf)) % sizeof(mk_lib_crypto_alg_aes_128_msg_t) == 0);
			mk_lang_assert(((mk_lang_types_uintptr_t)(out_buf)) % sizeof(mk_lib_crypto_alg_aes_128_msg_t) == 0);
			#include "mk_lang_warning_clang_push_cast_align.h"
			in_128 = ((mk_lib_crypto_alg_aes_128_msg_pct)(msg_buf));
			out_128 = ((mk_lib_crypto_alg_aes_128_msg_pt)(out_buf));
			#include "mk_lang_warning_clang_pop.h"
			mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&key_128.m_data.m_uint8s[0], &key_buf[0]);
			mk_lib_crypto_alg_aes_128_expand_enc(&key_128, &schedule_128);
			mk_lib_crypto_alg_aes_128_schedule_encrypt(&schedule_128, in_128, out_128, block_count);
		}
		break;
		case 192 / mk_lang_charbit:
		{
			mk_lang_assert(((mk_lang_types_uintptr_t)(msg_buf)) % sizeof(mk_lib_crypto_alg_aes_192_msg_t) == 0);
			mk_lang_assert(((mk_lang_types_uintptr_t)(out_buf)) % sizeof(mk_lib_crypto_alg_aes_192_msg_t) == 0);
			#include "mk_lang_warning_clang_push_cast_align.h"
			in_192 = ((mk_lib_crypto_alg_aes_192_msg_pct)(msg_buf));
			out_192 = ((mk_lib_crypto_alg_aes_192_msg_pt)(out_buf));
			#include "mk_lang_warning_clang_pop.h"
			mk_lib_crypto_bitops_bulk_uint8_24_memcpy(&key_192.m_data.m_uint8s[0], &key_buf[0]);
			mk_lib_crypto_alg_aes_192_expand_enc(&key_192, &schedule_192);
			mk_lib_crypto_alg_aes_192_schedule_encrypt(&schedule_192, in_192, out_192, block_count);
		}
		break;
		case 256 / mk_lang_charbit:
		{
			mk_lang_assert(((mk_lang_types_uintptr_t)(msg_buf)) % sizeof(mk_lib_crypto_alg_aes_256_msg_t) == 0);
			mk_lang_assert(((mk_lang_types_uintptr_t)(out_buf)) % sizeof(mk_lib_crypto_alg_aes_256_msg_t) == 0);
			#include "mk_lang_warning_clang_push_cast_align.h"
			in_256 = ((mk_lib_crypto_alg_aes_256_msg_pct)(msg_buf));
			out_256 = ((mk_lib_crypto_alg_aes_256_msg_pt)(out_buf));
			#include "mk_lang_warning_clang_pop.h"
			mk_lib_crypto_bitops_bulk_uint8_32_memcpy(&key_256.m_data.m_uint8s[0], &key_buf[0]);
			mk_lib_crypto_alg_aes_256_expand_enc(&key_256, &schedule_256);
			mk_lib_crypto_alg_aes_256_schedule_encrypt(&schedule_256, in_256, out_256, block_count);
		}
		break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_aes_fuzz_decrypt_my(mk_sl_cui_uint8_pct const key_buf, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pct const msg_buf, mk_lang_types_usize_t const block_count, mk_sl_cui_uint8_pt const out_buf) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_128_msg_pct in_128;
	mk_lib_crypto_alg_aes_128_msg_pt out_128;
	mk_lib_crypto_alg_aes_128_key_t key_128;
	mk_lib_crypto_alg_aes_128_schedule_t schedule_128;
	mk_lib_crypto_alg_aes_192_msg_pct in_192;
	mk_lib_crypto_alg_aes_192_msg_pt out_192;
	mk_lib_crypto_alg_aes_192_key_t key_192;
	mk_lib_crypto_alg_aes_192_schedule_t schedule_192;
	mk_lib_crypto_alg_aes_256_msg_pct in_256;
	mk_lib_crypto_alg_aes_256_msg_pt out_256;
	mk_lib_crypto_alg_aes_256_key_t key_256;
	mk_lib_crypto_alg_aes_256_schedule_t schedule_256;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(key_buf);
	mk_lang_assert(key_len == 128 / mk_lang_charbit || key_len == 192 / mk_lang_charbit || key_len == 256 / mk_lang_charbit);
	mk_lang_assert(msg_buf);
	mk_lang_assert(block_count >= 1);
	mk_lang_assert(out_buf);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	switch(key_len)
	{
		case 128 / mk_lang_charbit:
		{
			mk_lang_assert(((mk_lang_types_uintptr_t)(msg_buf)) % sizeof(mk_lib_crypto_alg_aes_128_msg_t) == 0);
			mk_lang_assert(((mk_lang_types_uintptr_t)(out_buf)) % sizeof(mk_lib_crypto_alg_aes_128_msg_t) == 0);
			#include "mk_lang_warning_clang_push_cast_align.h"
			in_128 = ((mk_lib_crypto_alg_aes_128_msg_pct)(msg_buf));
			out_128 = ((mk_lib_crypto_alg_aes_128_msg_pt)(out_buf));
			#include "mk_lang_warning_clang_pop.h"
			mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&key_128.m_data.m_uint8s[0], &key_buf[0]);
			mk_lib_crypto_alg_aes_128_expand_dec(&key_128, &schedule_128);
			mk_lib_crypto_alg_aes_128_schedule_decrypt(&schedule_128, in_128, out_128, block_count);
		}
		break;
		case 192 / mk_lang_charbit:
		{
			mk_lang_assert(((mk_lang_types_uintptr_t)(msg_buf)) % sizeof(mk_lib_crypto_alg_aes_192_msg_t) == 0);
			mk_lang_assert(((mk_lang_types_uintptr_t)(out_buf)) % sizeof(mk_lib_crypto_alg_aes_192_msg_t) == 0);
			#include "mk_lang_warning_clang_push_cast_align.h"
			in_192 = ((mk_lib_crypto_alg_aes_192_msg_pct)(msg_buf));
			out_192 = ((mk_lib_crypto_alg_aes_192_msg_pt)(out_buf));
			#include "mk_lang_warning_clang_pop.h"
			mk_lib_crypto_bitops_bulk_uint8_24_memcpy(&key_192.m_data.m_uint8s[0], &key_buf[0]);
			mk_lib_crypto_alg_aes_192_expand_dec(&key_192, &schedule_192);
			mk_lib_crypto_alg_aes_192_schedule_decrypt(&schedule_192, in_192, out_192, block_count);
		}
		break;
		case 256 / mk_lang_charbit:
		{
			mk_lang_assert(((mk_lang_types_uintptr_t)(msg_buf)) % sizeof(mk_lib_crypto_alg_aes_256_msg_t) == 0);
			mk_lang_assert(((mk_lang_types_uintptr_t)(out_buf)) % sizeof(mk_lib_crypto_alg_aes_256_msg_t) == 0);
			#include "mk_lang_warning_clang_push_cast_align.h"
			in_256 = ((mk_lib_crypto_alg_aes_256_msg_pct)(msg_buf));
			out_256 = ((mk_lib_crypto_alg_aes_256_msg_pt)(out_buf));
			#include "mk_lang_warning_clang_pop.h"
			mk_lib_crypto_bitops_bulk_uint8_32_memcpy(&key_256.m_data.m_uint8s[0], &key_buf[0]);
			mk_lib_crypto_alg_aes_256_expand_dec(&key_256, &schedule_256);
			mk_lib_crypto_alg_aes_256_schedule_decrypt(&schedule_256, in_256, out_256, block_count);
		}
		break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

#if mk_lang_platform_is_windows_at_least_any
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_aes_fuzz_encrypt_win(mk_sl_cui_uint8_pct const key_buf, mk_lang_types_sint_t const key_len, mk_sl_cui_uint8_pct const msg_buf, mk_lang_types_usize_t const block_count, mk_sl_cui_uint8_pt const out_buf) mk_lang_noexcept
{
	mk_win_base_ntstatus_t st;
	mk_win_dll_bcrypt_provider_t provider;
	mk_win_dll_bcrypt_key_t key;
	mk_lang_types_ulong_t tul;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(key_buf);
	mk_lang_assert(key_len == 128 / mk_lang_charbit || key_len == 192 / mk_lang_charbit || key_len == 256 / mk_lang_charbit);
	mk_lang_assert(msg_buf);
	mk_lang_assert(block_count >= 1);
	mk_lang_assert(out_buf);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	st = mk_win_dll_bcrypt_open_algorithm_provider(&provider, mk_win_dll_bcrypt_k_algorithm_aes, mk_win_dll_bcrypt_k_provider_ms_primitive, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_set_property(mk_win_dll_bcrypt_handle_from(provider.m_handle), mk_win_dll_bcrypt_k_chaining_mode, mk_win_dll_bcrypt_k_chain_mode_ecb, sizeof(mk_win_dll_bcrypt_k_chain_mode_ecb), mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_generate_symmetric_key(provider, &key, mk_lang_null, 0, key_buf, ((mk_lang_types_ulong_t)(key_len)), mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_encrypt(key, msg_buf, ((mk_lang_types_ulong_t)(block_count * (128 / mk_lang_charbit))), mk_lang_null, mk_lang_null, 0, out_buf, ((mk_lang_types_ulong_t)(block_count * (128 / mk_lang_charbit))), &tul, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0); mk_lang_check_return(tul == ((mk_lang_types_ulong_t)(block_count * (128 / mk_lang_charbit))));
	st = mk_win_dll_bcrypt_destroy_key(key); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_close_algorithm_provider(provider, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	return 0;
}
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_alg_aes_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t key_len_u;
	mk_lang_types_sint_t key_len_s;
	mk_sl_cui_uint8_pt pkey_buf;
	mk_sl_cui_uint8_t key_buf[(256 / mk_lang_charbit) * 64];
	mk_lang_types_uint_t block_count_u;
	mk_lang_types_uint_t block_offset_u;
	mk_lang_types_sint_t block_offset_s;
	mk_lang_types_uint_t outa_offset_u;
	mk_lang_types_sint_t outa_offset_s;
	mk_lang_types_uint_t outb_offset_u;
	mk_lang_types_sint_t outb_offset_s;
	mk_sl_cui_uint8_t msg[(128 / mk_lang_charbit) * 64];
	mk_sl_cui_uint8_pt pmsg;
	mk_sl_cui_uint8_pt pouta_my;
	mk_sl_cui_uint8_t outa_my[128 / mk_lang_charbit * 64];
	mk_sl_cui_uint8_pt poutb_my;
	mk_sl_cui_uint8_t outb_my[128 / mk_lang_charbit * 64];
	mk_lang_types_sint_t err;
	#if mk_lang_platform_is_windows_at_least_any
	mk_sl_cui_uint8_pt pout_win;
	mk_sl_cui_uint8_t out_win[128 / mk_lang_charbit * 64];
	#endif

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= 1))
	{
		return 0;
	}
	key_len_u = d[0] % 3u;
	d += 1;
	s -= 1;
	key_len_s = ((mk_lang_types_sint_t)(key_len_u));
	key_len_s = ((key_len_s == 0) ? (128 / mk_lang_charbit) : ((key_len_s == 1) ? (192 / mk_lang_charbit) : (256 / mk_lang_charbit)));
	key_len_u = ((mk_lang_types_uint_t)(key_len_s));
	if(!(s >= key_len_u))
	{
		return 0;
	}
	pkey_buf = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(&key_buf[0], 32 * (256 / mk_lang_charbit))));
	mk_sl_cui_uint8_from_bi_uchar_many(&pkey_buf[0], &d[0], key_len_u);
	d += key_len_u;
	s -= key_len_u;
	if(!(s >= mk_lang_countof(msg)))
	{
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(&msg[0], &d[0], mk_lang_countof(msg));
	d += mk_lang_countof(msg);
	s -= mk_lang_countof(msg);
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&block_count_u, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	block_count_u = block_count_u % 32 + 1;
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&block_offset_u, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	block_offset_u = block_offset_u % 32;
	block_offset_s = ((mk_lang_types_sint_t)(block_offset_u));
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&outa_offset_u, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	outa_offset_u = outa_offset_u % 32;
	outa_offset_s = ((mk_lang_types_sint_t)(outa_offset_u));
	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&outb_offset_u, &d[0]);
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	outb_offset_u = outb_offset_u % 32;
	outb_offset_s = ((mk_lang_types_sint_t)(outb_offset_u));
	pmsg = &msg[(mk_lib_crypto_alg_aes_128_msg_len_v - (((mk_lang_types_uintptr_t)(&msg[0])) & (mk_lib_crypto_alg_aes_128_msg_len_v - 1))) + block_offset_s * (128 / mk_lang_charbit)];

	pouta_my = &outa_my[(mk_lib_crypto_alg_aes_128_msg_len_v - (((mk_lang_types_uintptr_t)(&outa_my[0])) & (mk_lib_crypto_alg_aes_128_msg_len_v - 1))) + outa_offset_s * (128 / mk_lang_charbit)];
	poutb_my = &outb_my[(mk_lib_crypto_alg_aes_128_msg_len_v - (((mk_lang_types_uintptr_t)(&outb_my[0])) & (mk_lib_crypto_alg_aes_128_msg_len_v - 1))) + outb_offset_s * (128 / mk_lang_charbit)];
	err = mk_lib_crypto_alg_aes_fuzz_encrypt_my(&pkey_buf[0], key_len_s, &pmsg[0], block_count_u, &pouta_my[0]); mk_lang_check_rereturn(err);
	#if mk_lang_platform_is_windows_at_least_any
	pout_win = &out_win[(mk_lib_crypto_alg_aes_128_msg_len_v - (((mk_lang_types_uintptr_t)(&out_win[0])) & (mk_lib_crypto_alg_aes_128_msg_len_v - 1))) + outa_offset_s * (128 / mk_lang_charbit)];
	err = mk_lib_crypto_alg_aes_fuzz_encrypt_win(&pkey_buf[0], key_len_s, &pmsg[0], block_count_u, &pout_win[0]); mk_lang_check_rereturn(err);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&pouta_my[0], &pout_win[0], block_count_u * (128 / mk_lang_charbit)) == 0);
	#endif
	err = mk_lib_crypto_alg_aes_fuzz_decrypt_my(&pkey_buf[0], key_len_s, &pouta_my[0], block_count_u, &poutb_my[0]); mk_lang_check_rereturn(err);
	mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&poutb_my[0], &pmsg[0], block_count_u * (128 / mk_lang_charbit)) == 0);
	return 0;
}


#endif
