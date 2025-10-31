#ifndef mk_include_guard_mk_lib_app_cryptor_c
#define mk_include_guard_mk_lib_app_cryptor_c
#include "mk_lib_app_cryptor.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_lib_app_cryptor_alg_names.h"
#include "mk_lib_app_cryptor_mode_names.h"
#include "mk_lib_crypto_hash_names.h"
#include "mk_lib_crypto_padding_names.h"
#include "mk_sl_bui.h"
#include "mk_sl_cui_uint8.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_args_no_check(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_direction_t const direction, mk_lib_app_cryptor_mode_names_id_t const mode, mk_lib_app_cryptor_alg_names_id_t const alg, mk_lib_crypto_padding_names_id_t const padding, mk_lang_types_bool_t const kdf, mk_lib_crypto_hash_names_id_t const hash, mk_lang_types_ulong_t const cost, mk_lang_types_pchar_pct const password_buf, mk_lang_types_sint_t const password_len, mk_lang_types_pchar_pct const salt_buf, mk_lang_types_sint_t const salt_len) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(cryptor);
	mk_lang_assert(direction == mk_lang_false || direction == mk_lang_true);
	mk_lang_assert(mode >= 0);
	mk_lang_assert(mode < mk_lib_app_cryptor_mode_names_id_e_dummy_end);
	mk_lang_assert(alg >= 0);
	mk_lang_assert(alg < mk_lib_app_cryptor_alg_names_id_e_dummy_end);
	mk_lang_assert(padding >= 0);
	mk_lang_assert(padding < mk_lib_crypto_padding_names_id_e_dummy_end);
	mk_lang_assert(kdf == mk_lang_false || kdf == mk_lang_true);
	mk_lang_assert(hash >= 0);
	mk_lang_assert(hash < mk_lib_crypto_hash_names_id_e_dummy_end);
	mk_lang_assert(cost >= 0);
	mk_lang_assert(cost <= 0xfffffffful);
	mk_lang_assert(password_buf);
	mk_lang_assert(password_len >= 1);
	mk_lang_assert(password_len <= mk_lang_countof(cryptor->m_password_buf));
	mk_lang_assert(salt_buf);
	mk_lang_assert(salt_len >= 1);
	mk_lang_assert(salt_len <= mk_lang_countof(cryptor->m_salt_buf));
	#include "mk_lang_warning_msvc_pop.h"

	cryptor->m_direction = direction;
	cryptor->m_mode = mode;
	cryptor->m_alg = alg;
	cryptor->m_padding = padding;
	cryptor->m_kdf = kdf;
	cryptor->m_hash = hash;
	cryptor->m_cost = cost;
	mk_lang_string_memcpy_pc_fn(&cryptor->m_password_buf[0], &password_buf[0], password_len);
	cryptor->m_password_len = password_len;
	mk_lang_string_memcpy_pc_fn(&cryptor->m_salt_buf[0], &salt_buf[0], salt_len);
	cryptor->m_salt_len = salt_len;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_args_do_check(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_direction_t const direction, mk_lib_app_cryptor_mode_names_id_t const mode, mk_lib_app_cryptor_alg_names_id_t const alg, mk_lib_crypto_padding_names_id_t const padding, mk_lang_types_bool_t const kdf, mk_lib_crypto_hash_names_id_t const hash, mk_lang_types_ulong_t const cost, mk_lang_types_pchar_pct const password_buf, mk_lang_types_sint_t const password_len, mk_lang_types_pchar_pct const salt_buf, mk_lang_types_sint_t const salt_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(cryptor);

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_check_return(direction == mk_lang_false || direction == mk_lang_true);
	mk_lang_check_return(mode >= 0);
	mk_lang_check_return(mode < mk_lib_app_cryptor_mode_names_id_e_dummy_end);
	mk_lang_check_return(alg >= 0);
	mk_lang_check_return(alg < mk_lib_app_cryptor_alg_names_id_e_dummy_end);
	mk_lang_check_return(padding >= 0);
	mk_lang_check_return(padding < mk_lib_crypto_padding_names_id_e_dummy_end);
	mk_lang_check_return(kdf == mk_lang_false || kdf == mk_lang_true);
	mk_lang_check_return(hash >= 0);
	mk_lang_check_return(hash < mk_lib_crypto_hash_names_id_e_dummy_end);
	mk_lang_check_return(cost >= 0);
	mk_lang_check_return(cost <= 0xfffffffful);
	mk_lang_check_return(password_buf);
	mk_lang_check_return(password_len >= 1);
	mk_lang_check_return(password_len <= mk_lang_countof(cryptor->m_password_buf));
	mk_lang_check_return(salt_buf);
	mk_lang_check_return(salt_len >= 1);
	mk_lang_check_return(salt_len <= mk_lang_countof(cryptor->m_salt_buf));
	#include "mk_lang_warning_msvc_pop.h"
	err = mk_lib_app_cryptor_prrw_construct_args_no_check(cryptor, direction, mode, alg, padding, kdf, hash, cost, password_buf, password_len, salt_buf, salt_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_args(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_direction_t const direction, mk_lib_app_cryptor_mode_names_id_t const mode, mk_lib_app_cryptor_alg_names_id_t const alg, mk_lib_crypto_padding_names_id_t const padding, mk_lang_types_bool_t const kdf, mk_lib_crypto_hash_names_id_t const hash, mk_lang_types_ulong_t const cost, mk_lang_types_pchar_pct const password_buf, mk_lang_types_sint_t const password_len, mk_lang_types_pchar_pct const salt_buf, mk_lang_types_sint_t const salt_len) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_construct_args_no_check(cryptor, direction, mode, alg, padding, kdf, hash, cost, password_buf, password_len, salt_buf, salt_len);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_construct_parse(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct d;
	mk_lang_types_sint_t s;
	mk_lang_bui_uintptr_t bui;
	mk_lib_app_cryptor_direction_t direction;
	mk_lib_app_cryptor_mode_names_id_t mode;
	mk_lib_app_cryptor_alg_names_id_t alg;
	mk_lib_crypto_padding_names_id_t padding;
	mk_lang_types_bool_t kdf;
	mk_lib_crypto_hash_names_id_t hash;
	mk_lang_types_ulong_t cost;
	mk_lang_types_pchar_pct password_buf;
	mk_lang_types_sint_t password_len;
	mk_lang_types_pchar_pct salt_buf;
	mk_lang_types_sint_t salt_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(cryptor);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	d = data_buf;
	s = data_len;
	mk_lang_assert(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; direction    = ((mk_lib_app_cryptor_direction_t    )(bui));
	mk_lang_assert(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; mode         = ((mk_lib_app_cryptor_mode_names_id_t)(bui));
	mk_lang_assert(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; alg          = ((mk_lib_app_cryptor_alg_names_id_t )(bui));
	mk_lang_assert(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; padding      = ((mk_lib_crypto_padding_names_id_t  )(bui));
	mk_lang_assert(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; kdf          = ((mk_lang_types_bool_t              )(bui));
	mk_lang_assert(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; hash         = ((mk_lib_crypto_hash_names_id_t     )(bui));
	mk_lang_assert(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; cost         = ((mk_lang_types_ulong_t             )(bui));
	mk_lang_assert(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; password_buf = ((mk_lang_types_pchar_pct           )(bui));
	mk_lang_assert(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; password_len = ((mk_lang_types_sint_t              )(bui));
	mk_lang_assert(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; salt_buf     = ((mk_lang_types_pchar_pct           )(bui));
	mk_lang_assert(s >= mk_lang_bui_uintptr_size_bytes_v); mk_sl_bui_uintptr_from_uint8s_le(&bui, d); d += mk_lang_bui_uintptr_size_bytes_v; s -= mk_lang_bui_uintptr_size_bytes_v; salt_len     = ((mk_lang_types_sint_t              )(bui));
	err = mk_lib_app_cryptor_prrw_construct_args_do_check(cryptor, direction, mode, alg, padding, kdf, hash, cost, password_buf, password_len, salt_buf, salt_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pt mk_lib_app_cryptor_prrw_get_buffer_1_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	mk_lang_assert(cryptor);

	ptr = &cryptor->m_buffer.m_data.m_uint8s[0];
	ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(ptr, mk_lib_app_cryptor_buff_algn)));
	ptr += 0 * mk_lib_app_cryptor_buff_size;
	return ptr;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_get_buffer_1_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(cryptor);

	((mk_lang_types_void_t)(cryptor));
	len = mk_lib_app_cryptor_buff_size;
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pt mk_lib_app_cryptor_prrw_get_buffer_2_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;

	mk_lang_assert(cryptor);

	ptr = &cryptor->m_buffer.m_data.m_uint8s[0];
	ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(ptr, mk_lib_app_cryptor_buff_algn)));
	ptr += 1 * mk_lib_app_cryptor_buff_size;
	return ptr;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_app_cryptor_prrw_get_buffer_2_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(cryptor);

	((mk_lang_types_void_t)(cryptor));
	len = mk_lib_app_cryptor_buff_size;
	return len;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_args(mk_lib_app_cryptor_pt const cryptor, mk_lib_app_cryptor_direction_t const direction, mk_lib_app_cryptor_mode_names_id_t const mode, mk_lib_app_cryptor_alg_names_id_t const alg, mk_lib_crypto_padding_names_id_t const padding, mk_lang_types_bool_t const kdf, mk_lib_crypto_hash_names_id_t const hash, mk_lang_types_ulong_t const cost, mk_lang_types_pchar_pct const password_buf, mk_lang_types_sint_t const password_len, mk_lang_types_pchar_pct const salt_buf, mk_lang_types_sint_t const salt_len) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_construct_args(cryptor, direction, mode, alg, padding, kdf, hash, cost, password_buf, password_len, salt_buf, salt_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_construct_parse(mk_lib_app_cryptor_pt const cryptor, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_construct_parse(cryptor, data_buf, data_len);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_cui_uint8_pt mk_lib_app_cryptor_rw_get_buffer_1_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_get_buffer_1_ptr(cryptor);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_get_buffer_1_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_get_buffer_1_len(cryptor);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_cui_uint8_pt mk_lib_app_cryptor_rw_get_buffer_2_ptr(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_get_buffer_2_ptr(cryptor);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_app_cryptor_rw_get_buffer_2_len(mk_lib_app_cryptor_pt const cryptor) mk_lang_noexcept
{
	return mk_lib_app_cryptor_prrw_get_buffer_2_len(cryptor);
}


#endif
