#ifndef mk_include_guard_mk_lib_iip_cp_message_str_c
#define mk_include_guard_mk_lib_iip_cp_message_str_c
#include "mk_lib_iip_cp_message_str.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha2_256.h"
#include "mk_lib_fmt.h"
#include "mk_lib_iip_cp_destination.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_message_strings.h"
#include "mk_lib_iip_key_enc_elgamal_pri.h"
#include "mk_lib_iip_key_enc_elgamal_pub.h"
#include "mk_lib_iip_key_sgn_dsa_sha1.h"
#include "mk_lib_iip_time.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_val_obj_beg(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);

	ptr = str_buf;
	rem = str_len;

	tlen = 1;
	mk_lang_check_return(rem >= tlen);
	ptr[0] = '{';
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_val_obj_end(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);

	ptr = str_buf;
	rem = str_len;

	tlen = 1;
	mk_lang_check_return(rem >= tlen);
	ptr[0] = '}';
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_val_arr_beg(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);

	ptr = str_buf;
	rem = str_len;

	tlen = 1;
	mk_lang_check_return(rem >= tlen);
	ptr[0] = '[';
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_val_arr_end(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);

	ptr = str_buf;
	rem = str_len;

	tlen = 1;
	mk_lang_check_return(rem >= tlen);
	ptr[0] = ']';
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_val_str_beg(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);

	ptr = str_buf;
	rem = str_len;

	tlen = 1;
	mk_lang_check_return(rem >= tlen);
	ptr[0] = '"';
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_val_str_end(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);

	ptr = str_buf;
	rem = str_len;

	tlen = 1;
	mk_lang_check_return(rem >= tlen);
	ptr[0] = '"';
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_val_key_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);

	ptr = str_buf;
	rem = str_len;

	tlen = 1;
	mk_lang_check_return(rem >= tlen);
	ptr[0] = ':';
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_val_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);

	ptr = str_buf;
	rem = str_len;

	tlen = 1;
	mk_lang_check_return(rem >= tlen);
	ptr[0] = ',';
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_val_hex_beg(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);

	ptr = str_buf;
	rem = str_len;

	tlen = 1;
	mk_lang_check_return(rem >= tlen);
	ptr[0] = '0';
	ptr += tlen;
	rem -= tlen;

	tlen = 1;
	mk_lang_check_return(rem >= tlen);
	ptr[0] = 'x';
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_str_id_quotn(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_pchar_pct key_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t key_len mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	key_buf = mk_lib_iip_cp_message_strings_get_str_buf(*obj); mk_lang_assert(key_buf); mk_lang_assert(key_buf[0] != '\0');
	key_len = mk_lib_iip_cp_message_strings_get_str_len(*obj); mk_lang_assert(key_len >= 1);
	tlen = key_len;
	mk_lang_check_return(rem >= tlen);
	mk_lang_string_memcpy_pc_fn(&ptr[0], &key_buf[0], ((mk_lang_types_usize_t)(tlen)));
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_str_id_quoty(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_str_beg (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_str_id_quotn(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_sid(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_str_id_quoty(ptr, rem, &tlen, &str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_key_sep (ptr, rem, &tlen         ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_pchars_quotn(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lang_types_pchar_pct const obj_buf, mk_lang_types_sint_t const obj_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj_buf || obj_len == 0);
	mk_lang_assert(obj_len >= 0);

	ptr = str_buf;
	rem = str_len;

	tlen = obj_len;
	mk_lang_check_return(rem >= tlen);
	mk_lang_string_memcpy_pc_fn(ptr, obj_buf, ((mk_lang_types_usize_t)(obj_len)));
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_u8s_hex_quotn(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_sl_cui_uint8_pct const obj_buf, mk_lang_types_sint_t const obj_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj_buf || obj_len == 0);
	mk_lang_assert(obj_len >= 0);

	ptr = str_buf;
	rem = str_len;

	tlen = obj_len * mk_sl_cui_uint8_strlen_hex_v;
	mk_lang_check_return(rem >= tlen);
	len = mk_sl_cui_uint8_to_str_hexf_many_n(obj_buf, obj_len, ptr, rem); mk_lang_assert(len == tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_u8s_hex_quoty(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_sl_cui_uint8_pct const obj_buf, mk_lang_types_sint_t const obj_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj_buf || obj_len == 0);
	mk_lang_assert(obj_len >= 0);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_str_beg  (ptr, rem, &tlen);                   mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u8s_hex_quotn(ptr, rem, &tlen, obj_buf, obj_len); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end  (ptr, rem, &tlen);                   mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_u16_hex_nak(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_sl_cui_uint16_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	tlen = mk_sl_cui_uint16_strlen_hex_v;
	mk_lang_check_return(rem >= tlen);
	len = mk_sl_cui_uint16_to_str_hexf_n(obj, ptr, rem); mk_lang_assert(len == tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_u16_hex_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_sl_cui_uint16_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_str_beg(ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_hex_beg(ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u16_hex_nak(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end(ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_u32_dec_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_sl_cui_uint32_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	tlen = mk_sl_cui_uint32_strlen_dec_v;
	mk_lang_check_return(rem >= tlen);
	len = mk_sl_cui_uint32_to_str_dec_n(obj, ptr, rem); mk_lang_assert(len >= 1); mk_lang_assert(len <= tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_u32_dec_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_sl_cui_uint32_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid    (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_u32_dec_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_sl_cui_uint32_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep        (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_u32_hex_nak(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_sl_cui_uint32_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	tlen = mk_sl_cui_uint32_strlen_hex_v;
	mk_lang_check_return(rem >= tlen);
	len = mk_sl_cui_uint32_to_str_hexf_n(obj, ptr, rem); mk_lang_assert(len == tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_u32_hex_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_sl_cui_uint32_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_str_beg(ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_hex_beg(ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_hex_nak(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end(ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_u32_hex_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_sl_cui_uint32_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid    (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_hex_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_time_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_time_timestamp_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	tlen = 24;
	mk_lang_check_return(rem >= tlen);
	len = mk_lib_iip_time_to_text(obj, ptr, rem); mk_lang_assert(len == tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_int_elgamal_pri_single_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_enc_elgamal_pri_integer_single_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	tlen = mk_lib_iip_key_enc_elgamal_pri_integer_single_strlen_hex_v;
	mk_lang_check_return(rem >= tlen);
	len = mk_lib_iip_key_enc_elgamal_pri_integer_single_to_str_hexf_n(obj, ptr, rem); mk_lang_assert(len == tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_int_elgamal_pub_single_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_enc_elgamal_pub_integer_single_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	tlen = mk_lib_iip_key_enc_elgamal_pub_integer_single_strlen_hex_v;
	mk_lang_check_return(rem >= tlen);
	len = mk_lib_iip_key_enc_elgamal_pub_integer_single_to_str_hexf_n(obj, ptr, rem); mk_lang_assert(len == tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_int_dsa_sha1_pri_single_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_sgn_dsa_sha1_pri_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_sl_cui_uint8_t u8s[mk_lib_iip_key_sgn_dsa_sha1_pri_len_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	tlen = ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v));
	mk_lang_check_return(rem >= tlen);
	err = mk_lib_iip_key_sgn_dsa_sha1_pri_rw_export_pri_to_u8s(obj, &u8s[0]); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_many_n(&u8s[0], mk_lib_iip_key_sgn_dsa_sha1_pri_len_v, ptr, rem); mk_lang_assert(len == tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_int_dsa_sha1_pub_single_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_sgn_dsa_sha1_pub_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_sl_cui_uint8_t u8s[mk_lib_iip_key_sgn_dsa_sha1_pub_len_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	tlen = ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v));
	mk_lang_check_return(rem >= tlen);
	err = mk_lib_iip_key_sgn_dsa_sha1_pub_rw_export_to_u8s(obj, &u8s[0]); mk_lang_check_rereturn(err);
	len = mk_sl_cui_uint8_to_str_hexf_many_n(&u8s[0], mk_lib_iip_key_sgn_dsa_sha1_pub_len_v, ptr, rem); mk_lang_assert(len == tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_int_ecdsa_sha256_p256_pub_single_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	tlen = mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_strlen_hex_v;
	mk_lang_check_return(rem >= tlen);
	len = mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_to_str_hexf_n(obj, ptr, rem); mk_lang_assert(len == tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

/*mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_int_eddsa_sha512_ed25519_pub_single_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_integer_single_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	tlen = mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_integer_single_strlen_hex_v;
	mk_lang_check_return(rem >= tlen);
	len = mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_integer_single_to_str_hexf_n(obj, ptr, rem); mk_lang_assert(len == tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}*/


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_sessionid_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_sessionid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_u16_hex_raw(ptr, rem, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_sessionid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid           (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_sessionid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep               (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_messageid_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_messageid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_u32_hex_raw(ptr, rem, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_messageid_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_messageid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid           (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_messageid_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_messageid_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_messageid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_type_messageid_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep               (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_tunnelid_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_tunnelid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_u32_hex_raw(ptr, rem, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_tunnelid_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_tunnelid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid          (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_tunnelid_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_tunnelid_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_tunnelid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_type_tunnelid_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep              (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_requestid_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_requestid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_u32_hex_raw(ptr, rem, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_requestid_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_requestid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid           (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_requestid_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_requestid_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_requestid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_type_requestid_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep               (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_nonce_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_nonce_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_u32_hex_raw(ptr, rem, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_nonce_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_nonce_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid       (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_nonce_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_nonce_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_nonce_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_type_nonce_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep           (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_date_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_date_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_str_beg(ptr, rem, &tlen                     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_time_raw   (ptr, rem, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end(ptr, rem, &tlen                     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_date_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_date_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid      (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_date_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_date_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_date_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_type_date_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep          (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_sint_dec_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	mk_lang_check_return(*obj >= 0);
	mk_sl_cui_uint32_from_bi_sint(&tu32, obj);
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_raw(ptr, rem, &tlen, &tu32); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_sint_dec_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid     (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_sint_dec_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_sint_dec_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_sint_dec_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep         (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_message_strings_id_t mk_lib_iip_cp_message_str_to_json_enum_message_type_id(mk_lib_iip_cp_message_message_type_id_t const obj) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
	mk_lib_iip_cp_message_strings_id_t str_id mk_lang_constexpr_init;

	mk_lang_assert(obj >= 0);
	mk_lang_assert(obj < mk_lib_iip_cp_message_message_type_id_e_dummy_end);

	switch(obj)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : str_id = mk_lib_iip_cp_message_strings_id_e_create_session            ; break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : str_id = mk_lib_iip_cp_message_strings_id_e_reconfigure_session       ; break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : str_id = mk_lib_iip_cp_message_strings_id_e_destroy_session           ; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : str_id = mk_lib_iip_cp_message_strings_id_e_create_lease_set          ; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : str_id = mk_lib_iip_cp_message_strings_id_e_send_message              ; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : str_id = mk_lib_iip_cp_message_strings_id_e_receive_message_begin     ; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : str_id = mk_lib_iip_cp_message_strings_id_e_receive_message_end       ; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : str_id = mk_lib_iip_cp_message_strings_id_e_get_bandwidth_limits      ; break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : str_id = mk_lib_iip_cp_message_strings_id_e_session_status            ; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : str_id = mk_lib_iip_cp_message_strings_id_e_request_lease_set         ; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : str_id = mk_lib_iip_cp_message_strings_id_e_message_status            ; break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : str_id = mk_lib_iip_cp_message_strings_id_e_bandwidth_limits          ; break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : str_id = mk_lib_iip_cp_message_strings_id_e_report_abuse              ; break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : str_id = mk_lib_iip_cp_message_strings_id_e_disconnect                ; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : str_id = mk_lib_iip_cp_message_strings_id_e_message_payload           ; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : str_id = mk_lib_iip_cp_message_strings_id_e_get_date                  ; break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : str_id = mk_lib_iip_cp_message_strings_id_e_set_date                  ; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : str_id = mk_lib_iip_cp_message_strings_id_e_dest_lookup               ; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : str_id = mk_lib_iip_cp_message_strings_id_e_dest_reply                ; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : str_id = mk_lib_iip_cp_message_strings_id_e_send_message_expires      ; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: str_id = mk_lib_iip_cp_message_strings_id_e_request_variable_lease_set; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : str_id = mk_lib_iip_cp_message_strings_id_e_host_lookup               ; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : str_id = mk_lib_iip_cp_message_strings_id_e_host_reply                ; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : str_id = mk_lib_iip_cp_message_strings_id_e_create_lease_set2         ; break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : str_id = mk_lib_iip_cp_message_strings_id_e_blinding_info             ; break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&str_id);
	return str_id;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_message_strings_id_t mk_lib_iip_cp_message_str_to_json_enum_session_status_status_id(mk_lib_iip_cp_message_session_status_status_id_t const obj) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
	mk_lib_iip_cp_message_strings_id_t str_id mk_lang_constexpr_init;

	mk_lang_assert(obj >= 0);
	mk_lang_assert(obj < mk_lib_iip_cp_message_session_status_status_id_e_dummy_end);

	switch(obj)
	{
		case mk_lib_iip_cp_message_session_status_status_id_e_destroyed: str_id = mk_lib_iip_cp_message_strings_id_e_destroyed; break;
		case mk_lib_iip_cp_message_session_status_status_id_e_created  : str_id = mk_lib_iip_cp_message_strings_id_e_created  ; break;
		case mk_lib_iip_cp_message_session_status_status_id_e_updated  : str_id = mk_lib_iip_cp_message_strings_id_e_updated  ; break;
		case mk_lib_iip_cp_message_session_status_status_id_e_invalid  : str_id = mk_lib_iip_cp_message_strings_id_e_invalid  ; break;
		case mk_lib_iip_cp_message_session_status_status_id_e_refused  : str_id = mk_lib_iip_cp_message_strings_id_e_refused  ; break;
		case mk_lib_iip_cp_message_session_status_status_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&str_id);
	return str_id;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_message_strings_id_t mk_lib_iip_cp_message_str_to_json_enum_message_status_status_id(mk_lib_iip_cp_message_message_status_status_id_t const obj) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
	mk_lib_iip_cp_message_strings_id_t str_id mk_lang_constexpr_init;

	mk_lang_assert(obj >= 0);
	mk_lang_assert(obj < mk_lib_iip_cp_message_message_status_status_id_e_dummy_end);

	switch(obj)
	{
		case mk_lib_iip_cp_message_message_status_status_id_e_available             : str_id = mk_lib_iip_cp_message_strings_id_e_available             ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_accepted              : str_id = mk_lib_iip_cp_message_strings_id_e_accepted              ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_best_effort_success   : str_id = mk_lib_iip_cp_message_strings_id_e_best_effort_success   ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_best_effort_failure   : str_id = mk_lib_iip_cp_message_strings_id_e_best_effort_failure   ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_guaranteed_success    : str_id = mk_lib_iip_cp_message_strings_id_e_guaranteed_success    ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_guaranteed_failure    : str_id = mk_lib_iip_cp_message_strings_id_e_guaranteed_failure    ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_local_success         : str_id = mk_lib_iip_cp_message_strings_id_e_local_success         ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_local_failure         : str_id = mk_lib_iip_cp_message_strings_id_e_local_failure         ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_router_failure        : str_id = mk_lib_iip_cp_message_strings_id_e_router_failure        ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_network_failure       : str_id = mk_lib_iip_cp_message_strings_id_e_network_failure       ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_session           : str_id = mk_lib_iip_cp_message_strings_id_e_bad_session           ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_message           : str_id = mk_lib_iip_cp_message_strings_id_e_bad_message           ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_options           : str_id = mk_lib_iip_cp_message_strings_id_e_bad_options           ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_overflow_failure      : str_id = mk_lib_iip_cp_message_strings_id_e_overflow_failure      ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_message_expired       : str_id = mk_lib_iip_cp_message_strings_id_e_message_expired       ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_local_leaseset    : str_id = mk_lib_iip_cp_message_strings_id_e_bad_local_leaseset    ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_no_local_tunnels      : str_id = mk_lib_iip_cp_message_strings_id_e_no_local_tunnels      ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_unsupported_encryption: str_id = mk_lib_iip_cp_message_strings_id_e_unsupported_encryption; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_destination       : str_id = mk_lib_iip_cp_message_strings_id_e_bad_destination       ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_leaseset          : str_id = mk_lib_iip_cp_message_strings_id_e_bad_leaseset          ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_expired_leaseset      : str_id = mk_lib_iip_cp_message_strings_id_e_expired_leaseset      ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_no_leaseset           : str_id = mk_lib_iip_cp_message_strings_id_e_no_leaseset           ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_meta_leaseset         : str_id = mk_lib_iip_cp_message_strings_id_e_meta_leaseset         ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_loopback_denied       : str_id = mk_lib_iip_cp_message_strings_id_e_loopback_denied       ; break;
		case mk_lib_iip_cp_message_message_status_status_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&str_id);
	return str_id;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_message_strings_id_t mk_lib_iip_cp_message_str_to_json_enum_host_lookup_request_type_id(mk_lib_iip_cp_message_host_lookup_request_type_id_t const obj) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
	mk_lib_iip_cp_message_strings_id_t str_id mk_lang_constexpr_init;

	mk_lang_assert(obj >= 0);
	mk_lang_assert(obj < mk_lib_iip_cp_message_host_lookup_request_type_id_e_dummy_end);

	switch(obj)
	{
		case mk_lib_iip_cp_message_host_lookup_request_type_id_e_hash: str_id = mk_lib_iip_cp_message_strings_id_e_hash; break;
		case mk_lib_iip_cp_message_host_lookup_request_type_id_e_name: str_id = mk_lib_iip_cp_message_strings_id_e_name; break;
		case mk_lib_iip_cp_message_host_lookup_request_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&str_id);
	return str_id;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_iip_cp_message_strings_id_t mk_lib_iip_cp_message_str_to_json_enum_host_reply_result_code_id(mk_lib_iip_cp_message_host_reply_result_code_id_t const obj) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
	mk_lib_iip_cp_message_strings_id_t str_id mk_lang_constexpr_init;

	mk_lang_assert(obj >= 0);
	mk_lang_assert(obj < mk_lib_iip_cp_message_host_reply_result_code_id_e_dummy_end);

	switch(obj)
	{
		case mk_lib_iip_cp_message_host_reply_result_code_id_e_success                                 : str_id = mk_lib_iip_cp_message_strings_id_e_success                                 ; break;
		case mk_lib_iip_cp_message_host_reply_result_code_id_e_failure                                 : str_id = mk_lib_iip_cp_message_strings_id_e_failure                                 ; break;
		case mk_lib_iip_cp_message_host_reply_result_code_id_e_lookup_password_required                : str_id = mk_lib_iip_cp_message_strings_id_e_lookup_password_required                ; break;
		case mk_lib_iip_cp_message_host_reply_result_code_id_e_private_key_required                    : str_id = mk_lib_iip_cp_message_strings_id_e_private_key_required                    ; break;
		case mk_lib_iip_cp_message_host_reply_result_code_id_e_lookup_password_and_private_key_required: str_id = mk_lib_iip_cp_message_strings_id_e_lookup_password_and_private_key_required; break;
		case mk_lib_iip_cp_message_host_reply_result_code_id_e_leaseset_decryption_failure             : str_id = mk_lib_iip_cp_message_strings_id_e_leaseset_decryption_failure             ; break;
		case mk_lib_iip_cp_message_host_reply_result_code_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&str_id);
	return str_id;
#include "mk_lang_warning_clang_pop.h"
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_enum_message_type_quoty(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_message_type_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_strings_id_t str_id mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	str_id = mk_lib_iip_cp_message_str_to_json_enum_message_type_id(*obj);
 	err = mk_lib_iip_cp_message_str_to_json_str_id_quoty(ptr, rem, &tlen, &str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_enum_message_type_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_message_type_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid                (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_enum_message_type_quoty(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_enum_session_status_quoty(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_session_status_status_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_strings_id_t str_id mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	str_id = mk_lib_iip_cp_message_str_to_json_enum_session_status_status_id(*obj);
 	err = mk_lib_iip_cp_message_str_to_json_str_id_quoty(ptr, rem, &tlen, &str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_enum_session_status_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_session_status_status_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid                  (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_enum_session_status_quoty(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_tp_json_enum_session_status_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_session_status_status_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_enum_session_status_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                    (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_enum_message_status_quoty(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_message_status_status_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_strings_id_t str_id mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	str_id = mk_lib_iip_cp_message_str_to_json_enum_message_status_status_id(*obj);
 	err = mk_lib_iip_cp_message_str_to_json_str_id_quoty(ptr, rem, &tlen, &str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_enum_message_status_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_message_status_status_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid                  (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_enum_message_status_quoty(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_enum_message_status_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_message_status_status_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_enum_message_status_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                    (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_enum_host_lookup_request_type_quoty(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_host_lookup_request_type_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_strings_id_t str_id mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	str_id = mk_lib_iip_cp_message_str_to_json_enum_host_lookup_request_type_id(*obj);
 	err = mk_lib_iip_cp_message_str_to_json_str_id_quoty(ptr, rem, &tlen, &str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_enum_host_lookup_request_type_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_host_lookup_request_type_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid                            (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_enum_host_lookup_request_type_quoty(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_tp_json_enum_host_lookup_request_type_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_host_lookup_request_type_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_enum_host_lookup_request_type_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                              (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_enum_host_reply_result_code_quoty(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_host_reply_result_code_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_strings_id_t str_id mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	str_id = mk_lib_iip_cp_message_str_to_json_enum_host_reply_result_code_id(*obj);
 	err = mk_lib_iip_cp_message_str_to_json_str_id_quoty(ptr, rem, &tlen, &str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_enum_host_reply_result_code_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_host_reply_result_code_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid                          (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_enum_host_reply_result_code_quoty(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_tp_json_enum_host_reply_result_code_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_host_reply_result_code_id_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_enum_host_reply_result_code_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                            (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_elgamal_pri_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_enc_elgamal_pri_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_str_beg               (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_hex_beg               (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_int_elgamal_pri_single_raw(ptr, rem, &tlen, &obj->m_data.m_integer); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end               (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_elgamal_pri_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_key_enc_elgamal_pri_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid            (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_key_elgamal_pri_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_elgamal_pri_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_key_enc_elgamal_pri_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_elgamal_pri_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_elgamal_pub_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_enc_elgamal_pub_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_str_beg               (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_hex_beg               (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_int_elgamal_pub_single_raw(ptr, rem, &tlen, &obj->m_data.m_integer); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end               (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_elgamal_pub_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_key_enc_elgamal_pub_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid            (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_key_elgamal_pub_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_elgamal_pub_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_key_enc_elgamal_pub_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_elgamal_pub_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_dsa_sha1_pri_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_sgn_dsa_sha1_pri_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_str_beg                (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_hex_beg                (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_int_dsa_sha1_pri_single_raw(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end                (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_dsa_sha1_pri_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_key_sgn_dsa_sha1_pri_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid             (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_key_dsa_sha1_pri_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_dsa_sha1_pri_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_key_sgn_dsa_sha1_pri_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_dsa_sha1_pri_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                 (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_dsa_sha1_pub_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_sgn_dsa_sha1_pub_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_val_str_beg                (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_hex_beg                (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_int_dsa_sha1_pub_single_raw(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end                (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_dsa_sha1_pub_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_key_sgn_dsa_sha1_pub_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid             (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_key_dsa_sha1_pub_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_ecdsa_sha256_p256_pub_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_val_str_beg                         (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_hex_beg                         (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_int_ecdsa_sha256_p256_pub_single_raw(ptr, rem, &tlen, &obj->m_data.m_integer); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end                         (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_ecdsa_sha256_p256_pub_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid                      (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_key_ecdsa_sha256_p256_pub_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

/*mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_eddsa_sha512_ed25519_pub_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_val_str_beg                            (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_hex_beg                            (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_int_eddsa_sha512_ed25519_pub_single_raw(ptr, rem, &tlen, &obj->m_data.m_integer); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end                            (ptr, rem, &tlen                        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}*/

/*mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_eddsa_sha512_ed25519_pub_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid                         (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_key_eddsa_sha512_ed25519_pub_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}*/


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_hash_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_hash_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_u8s_hex_quoty(ptr, rem, &tlen, &obj->m_digest.m_data.m_uint8s[0], mk_lang_countof(obj->m_digest.m_data.m_uint8s)); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_hash_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_hash_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid      (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_hash_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_hash_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_hash_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_type_hash_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep          (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_buffer_quotn(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_buffer_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);
	mk_lang_assert(obj->m_len >= 0);
	mk_lang_assert(obj->m_len <= mk_lang_countof(obj->m_buf));

	ptr = str_buf;
	rem = str_len;

	tlen = obj->m_len * mk_sl_cui_uint8_strlen_hex_v;
	mk_lang_check_return(rem >= tlen);
	len = mk_sl_cui_uint8_to_str_hexf_many_n(&obj->m_buf[0], obj->m_len, ptr, rem); mk_lang_assert(len == tlen);
	ptr += len;
	rem -= len;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_buffer_quoty(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_buffer_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_val_str_beg      (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_buffer_quotn(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_val_str_end      (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_buffer_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_buffer_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid          (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_buffer_quoty(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_buffer_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_buffer_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_type_buffer_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep            (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_string_quotn(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_string_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	tlen = obj->m_len;
	mk_lang_check_return(rem >= tlen);
	mk_lang_string_memcpy_pc_fn(&ptr[0], &obj->m_buf[0], ((mk_lang_types_usize_t)(tlen)));
	ptr += tlen;
	rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_string_quoty(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_string_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_val_str_beg      (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_string_quotn(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_val_str_end      (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_string_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_string_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid          (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_string_quoty(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_string_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_string_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_type_string_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep            (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_key_string(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_string_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_string_quoty(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_key_sep      (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_strpair_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_strpair_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_string       (ptr, rem, &tlen, &obj->m_key); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_string_quoty(ptr, rem, &tlen, &obj->m_val); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_strpair_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_strpair_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_obj_beg     (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_strpair_raw(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_end     (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_strpair_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_strpair_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_strpair_nsp(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep         (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_strpairs_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_strpairs_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_iip_cp_types_strpair_pct strpair mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(((mk_lang_types_usize_t)(mk_lang_limits_sint_max)))) == mk_lang_limits_sint_max);

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	n = mk_lib_iip_cp_types_strpairs_ro_sise(obj);
	if(n >= 1)
	{
		for(i = 0; i != n - 1; ++i)
		{
			strpair = mk_lib_iip_cp_types_strpairs_ro_at(obj, ((mk_lang_types_usize_t)(i))); mk_lang_assert(strpair);
			err = mk_lib_iip_cp_message_str_to_json_type_strpair_sep(ptr, rem, &tlen, strpair); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
		}
		strpair = mk_lib_iip_cp_types_strpairs_ro_at(obj, ((mk_lang_types_usize_t)(i))); mk_lang_assert(strpair);
		err = mk_lib_iip_cp_message_str_to_json_type_strpair_nsp(ptr, rem, &tlen, strpair); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	}

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_strpairs_arr(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_strpairs_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_arr_beg      (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_strpairs_raw(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_arr_end      (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_mapping_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_mapping_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_strpairs_arr(ptr, rem, &tlen, &obj->m_strpairs); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_mapping_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_mapping_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid         (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_mapping_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_mapping_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_mapping_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_mapping_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep             (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelid_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_hash_and_tunnelid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_hash_sid_sep    (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_router_hash, &obj->m_router_hash); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_tunnelid_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_tunnel_id  , &obj->m_tunnel_id  ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_hash_and_tunnelid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_obj_beg               (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelid_raw(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_end               (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_hash_and_tunnelid_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelid_nsp(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                   (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelids_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_hash_and_tunnelids_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_iip_cp_types_hash_and_tunnelid_pct hash_and_tunnelid mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(((mk_lang_types_usize_t)(mk_lang_limits_sint_max)))) == mk_lang_limits_sint_max);

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);
	mk_lang_assert(mk_lib_iip_cp_types_hash_and_tunnelids_ro_size(obj) <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));

	ptr = str_buf;
	rem = str_len;

	n = mk_lib_iip_cp_types_hash_and_tunnelids_ro_sise(obj);
	if(n >= 1)
	{
		for(i = 0; i != n - 1; ++i)
		{
			hash_and_tunnelid = mk_lib_iip_cp_types_hash_and_tunnelids_ro_at(obj, ((mk_lang_types_usize_t)(i))); mk_lang_assert(hash_and_tunnelid);
			err = mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelid_sep(ptr, rem, &tlen, hash_and_tunnelid); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
		}
		hash_and_tunnelid = mk_lib_iip_cp_types_hash_and_tunnelids_ro_at(obj, ((mk_lang_types_usize_t)(i))); mk_lang_assert(hash_and_tunnelid);
		err = mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelid_nsp(ptr, rem, &tlen, hash_and_tunnelid); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	}

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelids_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_hash_and_tunnelids_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid                    (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_arr_beg                (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelids_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_arr_end                (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelids_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_hash_and_tunnelids_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelids_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                        (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_lease_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_lease_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_hash_sid_sep    (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_router_hash, &obj->m_router_hash); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_tunnelid_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_tunnel_id  , &obj->m_tunnel_id  ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_date_sid_nsp    (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_end_date   , &obj->m_end_date   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_lease_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_lease_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_obj_beg   (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_lease_raw(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_end   (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_lease_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_lease_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_lease_nsp(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep       (ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_leases_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_leases_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_iip_cp_types_lease_pct lease mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(((mk_lang_types_usize_t)(mk_lang_limits_sint_max)))) == mk_lang_limits_sint_max);

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);
	mk_lang_assert(mk_lib_iip_cp_types_leases_ro_size(obj) <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));

	ptr = str_buf;
	rem = str_len;

	n = mk_lib_iip_cp_types_leases_ro_sise(obj);
	if(n >= 1)
	{
		for(i = 0; i != n - 1; ++i)
		{
			lease = mk_lib_iip_cp_types_leases_ro_at(obj, ((mk_lang_types_usize_t)(i))); mk_lang_assert(lease);
			err = mk_lib_iip_cp_message_str_to_json_type_lease_sep(ptr, rem, &tlen, lease); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
		}
		lease = mk_lib_iip_cp_types_leases_ro_at(obj, ((mk_lang_types_usize_t)(i))); mk_lang_assert(lease);
		err = mk_lib_iip_cp_message_str_to_json_type_lease_nsp(ptr, rem, &tlen, lease); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	}

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_leases_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_leases_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid        (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_arr_beg    (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_leases_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_arr_end    (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_destination_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_destination_local_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_pchar_pt data_buf mk_lang_constexpr_init;
	mk_lang_types_pchar_t data_store[52 + 8 + 0] mk_lang_constexpr_init;
	mk_lang_types_sint_t data_cap mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t data_len mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	data_buf = &data_store[0];
	data_cap = mk_lang_countof(data_store);
	err = mk_lib_iip_cp_destination_remote_ro_to_b32(&obj->m_remote_destination, data_buf, data_cap, &data_len); mk_lang_check_rereturn(err); mk_lang_assert(data_len >= 1); mk_lang_assert(data_len <= data_cap);
	err = mk_lib_iip_cp_message_str_to_json_pchars_quotn(ptr, rem, &tlen, data_buf, data_len); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_destination_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_destination_local_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid             (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_beg         (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_destination_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_str_end         (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_destination_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_destination_local_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_destination_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                 (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

/*mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_remote_destination_legacy_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_remote_destination_elgamal_dsa_sha1_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_elgamal_pub_sid_sep (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_key_enc_pub, &obj->m_enc_pub); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_key_dsa_sha1_pub_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_key_sgn_pub, &obj->m_sgn_pub); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}*/

/*mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_remote_destination_elgamal_dsa_sha1_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_remote_destination_elgamal_dsa_sha1_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_elgamal_pub_sid_sep (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_key_enc_pub, &obj->m_enc_pub); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_key_dsa_sha1_pub_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_key_sgn_pub, &obj->m_sgn_pub); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}*/

/*mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_remote_destination_elgamal_dsa_sha1_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_remote_destination_elgamal_dsa_sha1_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid                                     (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_beg                                 (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_remote_destination_elgamal_dsa_sha1_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_end                                 (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}*/

/*mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_remote_destination_elgamal_dsa_sha1_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_remote_destination_elgamal_dsa_sha1_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_remote_destination_elgamal_dsa_sha1_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                                         (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}*/

/*mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_remote_destination_elgamal_ecdsa_sha256_p256_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_remote_destination_elgamal_ecdsa_sha256_p256_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_elgamal_pub_sid_sep          (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_key_enc_pub, &obj->m_enc_pub); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_key_ecdsa_sha256_p256_pub_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_key_sgn_pub, &obj->m_sgn_pub); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}*/

/*mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_remote_destination_elgamal_eddsa_sha512_ed25519_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_remote_destination_elgamal_eddsa_sha512_ed25519_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_elgamal_pub_sid_sep             (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_key_enc_pub, &obj->m_enc_pub); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_key_eddsa_sha512_ed25519_pub_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_key_sgn_pub, &obj->m_sgn_pub); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}*/

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_remote_destination_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_destination_remote_pct const obj) mk_lang_noexcept
{
	/*mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;*/
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	//mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	/*ptr = str_buf;*/
	rem = str_len;

	/*switch(obj->m_type)
	{
		case mk_lib_iip_cp_types_remote_destination_type_e_legacy                      : err = mk_lib_iip_cp_message_str_to_json_type_remote_destination_legacy_raw                      (ptr, rem, &tlen, &obj->m_data.m_legacy                      ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_types_remote_destination_type_e_elgamal_dsa_sha1            : err = mk_lib_iip_cp_message_str_to_json_type_remote_destination_elgamal_dsa_sha1_raw            (ptr, rem, &tlen, &obj->m_data.m_elgamal_dsa_sha1            ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_types_remote_destination_type_e_elgamal_ecdsa_sha256_p256   : err = mk_lib_iip_cp_message_str_to_json_type_remote_destination_elgamal_ecdsa_sha256_p256_raw   (ptr, rem, &tlen, &obj->m_data.m_elgamal_ecdsa_sha256_p256   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_types_remote_destination_type_e_elgamal_eddsa_sha512_ed25519: err = mk_lib_iip_cp_message_str_to_json_type_remote_destination_elgamal_eddsa_sha512_ed25519_raw(ptr, rem, &tlen, &obj->m_data.m_elgamal_eddsa_sha512_ed25519); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_types_remote_destination_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}*/

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_remote_destination_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_destination_remote_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_key_sid                    (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_beg                (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_remote_destination_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_end                (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_remote_destination_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_destination_remote_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_remote_destination_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                        (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_leaseset_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_leaseset_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_destination_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_destination, &obj->m_local_destination); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_leases_sid_nsp     (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_leases     , &obj->m_leases           ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_leaseset_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_leaseset_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid          (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_beg      (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_leaseset_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_end      (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_session_config_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_types_session_config_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_type_destination_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_destination  , &obj->m_local_destination); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_mapping_sid_sep    (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_opptions     , &obj->m_options          ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_date_sid_nsp       (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_creation_date, &obj->m_creation_date    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_type_session_config_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_types_session_config_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

 	err = mk_lib_iip_cp_message_str_to_json_key_sid                (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_beg            (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_session_config_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_end            (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msgessage_header_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_header_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_sint_dec_sid_sep             (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_len , &obj->m_len ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_enum_message_type_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_type, &obj->m_type); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msgessage_header_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_header_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_key_sid             (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_beg         (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_msgessage_header_raw(ptr, rem, &tlen, obj   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_end         (ptr, rem, &tlen        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_message_header_sid_sep(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_header_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_msgessage_header_sid_nsp(ptr, rem, &tlen, str_id, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_sep                 (ptr, rem, &tlen             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_create_session(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_create_session_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
 	err = mk_lib_iip_cp_message_str_to_json_type_session_config_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_config, &obj->m_session_config); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_reconfigure_session(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_reconfigure_session_pct const obj) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}

	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_destroy_session(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_destroy_session_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id, &obj->m_session_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_create_lease_set(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_create_lease_set_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep  (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id , &obj->m_session_id ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	//err = mk_lib_iip_cp_message_str_to_json_key_dsa_sha1_pri_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_key_sgn_pri, &obj->m_key_sgn_pri); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	//err = mk_lib_iip_cp_message_str_to_json_key_elgamal_pri_sid_sep (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_key_enc_pri, &obj->m_key_enc_pri); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_leaseset_sid_nsp   (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_leaseset   , &obj->m_leaseset   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_send_message(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_send_message_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep         (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id , &obj->m_session_id        ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_remote_destination_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_destination, &obj->m_remote_destination); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_buffer_sid_sep            (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_payload    , &obj->m_payload           ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_nonce_sid_nsp             (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_nonce      , &obj->m_nonce             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_receive_message_begin(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_receive_message_begin_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id, &obj->m_session_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_messageid_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_message_id, &obj->m_message_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_receive_message_end(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_receive_message_end_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id, &obj->m_session_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_messageid_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_message_id, &obj->m_message_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_get_bandwidth_limits(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_get_bandwidth_limits_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(obj));
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_session_status(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_session_status_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep     (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id, &obj->m_session_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_enum_session_status_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_status    , &obj->m_status    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_request_lease_set(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_request_lease_set_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep         (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id, &obj->m_session_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_hash_and_tunnelids_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_tunnels   , &obj->m_tunnels   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_date_sid_nsp              (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_end_date  , &obj->m_end_date  ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_message_status(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_message_status_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep     (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id, &obj->m_session_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_messageid_sid_sep     (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_message_id, &obj->m_message_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_enum_message_status_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_status    , &obj->m_status    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_sint_dec_sid_sep           (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_size      , &obj->m_size      ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_nonce_sid_nsp         (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_nonce     , &obj->m_nonce     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_bandwidth_limits(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_bandwidth_limits_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_client_inbound_limit_kbps       , &obj->m_bandwidth_limits.m_client_inbound_limit_kbps       ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_client_outbound_limit_kbps      , &obj->m_bandwidth_limits.m_client_outbound_limit_kbps      ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_router_inbound_limit_kbps       , &obj->m_bandwidth_limits.m_router_inbound_limit_kbps       ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_router_inbound_burst_limit_kbps , &obj->m_bandwidth_limits.m_router_inbound_burst_limit_kbps ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_router_outbound_limit_kbps      , &obj->m_bandwidth_limits.m_router_outbound_limit_kbps      ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_router_outbound_burst_limit_kbps, &obj->m_bandwidth_limits.m_router_outbound_burst_limit_kbps); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_router_burst_time_seconds       , &obj->m_bandwidth_limits.m_router_burst_time_seconds       ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_future_use_1                    , &obj->m_bandwidth_limits.m_future_use_1                    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_future_use_2                    , &obj->m_bandwidth_limits.m_future_use_2                    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_future_use_3                    , &obj->m_bandwidth_limits.m_future_use_3                    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_future_use_4                    , &obj->m_bandwidth_limits.m_future_use_4                    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_future_use_5                    , &obj->m_bandwidth_limits.m_future_use_5                    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_future_use_6                    , &obj->m_bandwidth_limits.m_future_use_6                    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_future_use_7                    , &obj->m_bandwidth_limits.m_future_use_7                    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_future_use_8                    , &obj->m_bandwidth_limits.m_future_use_8                    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_u32_dec_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_future_use_9                    , &obj->m_bandwidth_limits.m_future_use_9                    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_report_abuse(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_report_abuse_pct const obj) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}

	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_disconnect(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_disconnect_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_string_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_reason, &obj->m_reason); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_message_payload(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_message_payload_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id, &obj->m_session_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_messageid_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_message_id, &obj->m_message_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_buffer_sid_nsp   (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_payload   , &obj->m_payload   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_get_date(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_get_date_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_string_sid_sep (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_api_version   , &obj->m_api_version   ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_mapping_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_authentication, &obj->m_authentication); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_set_date(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_set_date_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_date_sid_sep  (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_server_date, &obj->m_server_date); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_type_string_sid_nsp(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_api_version, &obj->m_api_version); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_dest_lookup(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_dest_lookup_pct const obj) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}

	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_dest_reply(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_dest_reply_pct const obj) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}

	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_send_message_expires(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_send_message_expires_pct const obj) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}

	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_request_variable_lease_set(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_request_variable_lease_set_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id, &obj->m_session_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_leases_sid_nsp   (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_leases    , &obj->m_leases    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_host_lookup(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_host_lookup_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep               (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id  , &obj->m_session_id  ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_requestid_sid_sep               (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_request_id  , &obj->m_request_id  ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_sint_dec_sid_sep                     (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_timeout_ms  , &obj->m_timeout_ms  ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_tp_json_enum_host_lookup_request_type_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_request_type, &obj->m_request_type); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_string_sid_nsp                  (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_hostname    , &obj->m_hostname    ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_host_reply(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_host_reply_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
 	err = mk_lib_iip_cp_message_str_to_json_type_sessionid_sid_sep             (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_id , &obj->m_session_id ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_requestid_sid_sep             (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_request_id , &obj->m_request_id ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_tp_json_enum_host_reply_result_code_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_result_code, &obj->m_result_code); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_type_buffer_sid_nsp                (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_destination, &obj->m_destination); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_create_lease_set2(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_create_lease_set2_pct const obj) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}

	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_msg_blinding_info(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_blinding_info_pct const obj) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}

	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_message_mix_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
	switch(obj->m_header.m_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : err = mk_lib_iip_cp_message_str_to_json_msg_create_session            (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_create_session            , &obj->m_mix.m_data.m_create_session            ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : err = mk_lib_iip_cp_message_str_to_json_msg_reconfigure_session       (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_reconfigure_session       , &obj->m_mix.m_data.m_reconfigure_session       ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : err = mk_lib_iip_cp_message_str_to_json_msg_destroy_session           (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_destroy_session           , &obj->m_mix.m_data.m_destroy_session           ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : err = mk_lib_iip_cp_message_str_to_json_msg_create_lease_set          (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_create_lease_set          , &obj->m_mix.m_data.m_create_lease_set          ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : err = mk_lib_iip_cp_message_str_to_json_msg_send_message              (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_send_message              , &obj->m_mix.m_data.m_send_message              ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : err = mk_lib_iip_cp_message_str_to_json_msg_receive_message_begin     (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_receive_message_begin     , &obj->m_mix.m_data.m_receive_message_begin     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : err = mk_lib_iip_cp_message_str_to_json_msg_receive_message_end       (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_receive_message_end       , &obj->m_mix.m_data.m_receive_message_end       ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : err = mk_lib_iip_cp_message_str_to_json_msg_get_bandwidth_limits      (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_get_bandwidth_limits      , &obj->m_mix.m_data.m_get_bandwidth_limits      ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : err = mk_lib_iip_cp_message_str_to_json_msg_session_status            (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_session_status            , &obj->m_mix.m_data.m_session_status            ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : err = mk_lib_iip_cp_message_str_to_json_msg_request_lease_set         (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_request_lease_set         , &obj->m_mix.m_data.m_request_lease_set         ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : err = mk_lib_iip_cp_message_str_to_json_msg_message_status            (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_message_status            , &obj->m_mix.m_data.m_message_status            ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : err = mk_lib_iip_cp_message_str_to_json_msg_bandwidth_limits          (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_bandwidth_limits          , &obj->m_mix.m_data.m_bandwidth_limits          ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : err = mk_lib_iip_cp_message_str_to_json_msg_report_abuse              (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_report_abuse              , &obj->m_mix.m_data.m_report_abuse              ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : err = mk_lib_iip_cp_message_str_to_json_msg_disconnect                (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_disconnect                , &obj->m_mix.m_data.m_disconnect                ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : err = mk_lib_iip_cp_message_str_to_json_msg_message_payload           (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_message_payload           , &obj->m_mix.m_data.m_message_payload           ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : err = mk_lib_iip_cp_message_str_to_json_msg_get_date                  (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_get_date                  , &obj->m_mix.m_data.m_get_date                  ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : err = mk_lib_iip_cp_message_str_to_json_msg_set_date                  (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_set_date                  , &obj->m_mix.m_data.m_set_date                  ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : err = mk_lib_iip_cp_message_str_to_json_msg_dest_lookup               (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_dest_lookup               , &obj->m_mix.m_data.m_dest_lookup               ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : err = mk_lib_iip_cp_message_str_to_json_msg_dest_reply                (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_dest_reply                , &obj->m_mix.m_data.m_dest_reply                ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : err = mk_lib_iip_cp_message_str_to_json_msg_send_message_expires      (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_send_message_expires      , &obj->m_mix.m_data.m_send_message_expires      ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: err = mk_lib_iip_cp_message_str_to_json_msg_request_variable_lease_set(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_request_variable_lease_set, &obj->m_mix.m_data.m_request_variable_lease_set); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : err = mk_lib_iip_cp_message_str_to_json_msg_host_lookup               (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_host_lookup               , &obj->m_mix.m_data.m_host_lookup               ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : err = mk_lib_iip_cp_message_str_to_json_msg_host_reply                (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_host_reply                , &obj->m_mix.m_data.m_host_reply                ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : err = mk_lib_iip_cp_message_str_to_json_msg_create_lease_set2         (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_create_lease_set2         , &obj->m_mix.m_data.m_create_lease_set2         ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : err = mk_lib_iip_cp_message_str_to_json_msg_blinding_info             (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_blinding_info             , &obj->m_mix.m_data.m_blinding_info             ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_message_mix_sid_nsp(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_strings_id_t const str_id, mk_lib_iip_cp_message_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(str_id >= 0 && str_id < mk_lib_iip_cp_message_strings_id_e_dummy_end);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
 	err = mk_lib_iip_cp_message_str_to_json_key_sid        (ptr, rem, &tlen, str_id); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_val_obj_beg    (ptr, rem, &tlen);         mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_message_mix_raw(ptr, rem, &tlen, obj);    mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
 	err = mk_lib_iip_cp_message_str_to_json_val_obj_end    (ptr, rem, &tlen);         mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_message_raw(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;
 	err = mk_lib_iip_cp_message_str_to_json_message_header_sid_sep(ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_header, &obj->m_header); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_message_mix_sid_nsp   (ptr, rem, &tlen, mk_lib_iip_cp_message_strings_id_e_body  , obj           ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_message(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_pct const obj) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(obj);

	ptr = str_buf;
	rem = str_len;

	err = mk_lib_iip_cp_message_str_to_json_val_obj_beg(ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_message_raw(ptr, rem, &tlen, obj); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_str_to_json_val_obj_end(ptr, rem, &tlen     ); mk_lang_check_rereturn(err); mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = str_len - rem;
	*out_len = tlen;
	return 0;
}


#endif
