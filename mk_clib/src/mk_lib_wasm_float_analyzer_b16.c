#ifndef mk_include_guard_mk_lib_wasm_float_analyzer_b16_c
#define mk_include_guard_mk_lib_wasm_float_analyzer_b16_c
#include "mk_lib_wasm_float_analyzer_b16.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_offsetof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_float_analyzer_b16.h"


enum mk_lib_wasm_float_analyzer_b16_fnc_id_e
{
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_analyze,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_buffer_buf,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_buffer_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_bin_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_bin_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_hex_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_hex_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_dec_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_dec_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_sgn_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_sgn_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_sign_text_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_sign_text_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_bin_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_bin_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_hex_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_hex_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_dec_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_dec_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_decoded_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_decoded_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_type_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_type_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_implied_one_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_implied_one_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_bin_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_bin_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_hex_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_hex_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_dec_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_dec_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_dcd_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_dcd_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_value_text_beg,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_value_text_len,
	mk_lib_wasm_float_analyzer_b16_fnc_id_e_dummy_end
};
typedef enum mk_lib_wasm_float_analyzer_b16_fnc_id_e mk_lib_wasm_float_analyzer_b16_fnc_id_t;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_analyze(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_b16_analyze(analyzer);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_get_buffer_buf(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(&analyzer->m_float_bytes_le[0]));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_get_buffer_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = mk_lang_countof(analyzer->m_float_bytes_le);
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_all_text_bin_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_all_text_bin_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_all_text_bin_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_all_text_bin_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_all_text_hex_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_all_text_hex_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_all_text_hex_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_all_text_hex_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_all_text_dec_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_all_text_dec_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_all_text_dec_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_all_text_dec_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_all_text_sgn_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_all_text_sgn_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_all_text_sgn_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_all_text_sgn_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_sign_text_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_sign_text_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_sign_text_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_sign_text_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_bin_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_exponent_text_bin_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_bin_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_exponent_text_bin_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_hex_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_exponent_text_hex_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_hex_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_exponent_text_hex_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_dec_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_exponent_text_dec_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_dec_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_exponent_text_dec_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_decoded_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_exponent_text_decoded_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_decoded_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_exponent_text_decoded_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_type_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_exponent_text_type_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_type_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_exponent_text_type_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_implied_one_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_exponent_text_implied_one_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_implied_one_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_exponent_text_implied_one_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_bin_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_mantissa_text_bin_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_bin_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_mantissa_text_bin_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_hex_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_mantissa_text_hex_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_hex_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_mantissa_text_hex_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_dec_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_mantissa_text_dec_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_dec_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_mantissa_text_dec_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_dcd_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_mantissa_text_dcd_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_dcd_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_mantissa_text_dcd_len;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_value_text_beg(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(analyzer);

	addr = ((mk_lang_types_uintptr_t)(analyzer)) + ((mk_lang_types_uint_t)(mk_lang_offsetof(mk_lib_float_analyzer_b16_t, m_value_buf)));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_pr_get_value_text_len(mk_lib_float_analyzer_b16_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(analyzer);

	len = analyzer->m_value_len;
	return len;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b16_main(mk_lib_float_analyzer_b16_pt const analyzer, mk_lang_types_uintptr_t const fnc, mk_lang_types_uintptr_t const arg) mk_lang_noexcept
{
	mk_lang_types_uintptr_t res;

	mk_lang_assert(analyzer);
	mk_lang_assert(fnc || !fnc);
	mk_lang_assert(arg || !arg);

	res = ((mk_lang_types_uintptr_t)(((mk_lang_types_sintptr_t)(-1))));
	switch(fnc)
	{
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_analyze                          :  res = mk_lib_wasm_float_analyzer_b16_analyze                             (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_buffer_buf                   :  res = mk_lib_wasm_float_analyzer_b16_get_buffer_buf                      (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_buffer_len                   :  res = mk_lib_wasm_float_analyzer_b16_get_buffer_len                      (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_bin_beg             :  res = mk_lib_wasm_float_analyzer_b16_pr_get_all_text_bin_beg             (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_bin_len             :  res = mk_lib_wasm_float_analyzer_b16_pr_get_all_text_bin_len             (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_hex_beg             :  res = mk_lib_wasm_float_analyzer_b16_pr_get_all_text_hex_beg             (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_hex_len             :  res = mk_lib_wasm_float_analyzer_b16_pr_get_all_text_hex_len             (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_dec_beg             :  res = mk_lib_wasm_float_analyzer_b16_pr_get_all_text_dec_beg             (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_dec_len             :  res = mk_lib_wasm_float_analyzer_b16_pr_get_all_text_dec_len             (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_sgn_beg             :  res = mk_lib_wasm_float_analyzer_b16_pr_get_all_text_sgn_beg             (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_all_text_sgn_len             :  res = mk_lib_wasm_float_analyzer_b16_pr_get_all_text_sgn_len             (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_sign_text_beg                :  res = mk_lib_wasm_float_analyzer_b16_pr_get_sign_text_beg                (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_sign_text_len                :  res = mk_lib_wasm_float_analyzer_b16_pr_get_sign_text_len                (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_bin_beg        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_bin_beg        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_bin_len        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_bin_len        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_hex_beg        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_hex_beg        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_hex_len        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_hex_len        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_dec_beg        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_dec_beg        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_dec_len        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_dec_len        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_decoded_beg    :  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_decoded_beg    (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_decoded_len    :  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_decoded_len    (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_type_beg       :  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_type_beg       (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_type_len       :  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_type_len       (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_implied_one_beg:  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_implied_one_beg(analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_exponent_text_implied_one_len:  res = mk_lib_wasm_float_analyzer_b16_pr_get_exponent_text_implied_one_len(analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_bin_beg        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_bin_beg        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_bin_len        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_bin_len        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_hex_beg        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_hex_beg        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_hex_len        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_hex_len        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_dec_beg        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_dec_beg        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_dec_len        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_dec_len        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_dcd_beg        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_dcd_beg        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_mantissa_text_dcd_len        :  res = mk_lib_wasm_float_analyzer_b16_pr_get_mantissa_text_dcd_len        (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_value_text_beg               :  res = mk_lib_wasm_float_analyzer_b16_pr_get_value_text_beg               (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_get_value_text_len               :  res = mk_lib_wasm_float_analyzer_b16_pr_get_value_text_len               (analyzer); break;
		case mk_lib_wasm_float_analyzer_b16_fnc_id_e_dummy_end: break;
		default: break;
	}
	return res;
}


#endif
