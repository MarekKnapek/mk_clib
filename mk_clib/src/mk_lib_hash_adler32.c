#ifndef mk_include_guard_mk_lib_hash_adler32_c
#define mk_include_guard_mk_lib_hash_adler32_c
#include "mk_lib_hash_adler32.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_hash_adler32_block(mk_lib_hash_adler32_pt const adler32, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct buf mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tcui32 mk_lang_constexpr_init;
	mk_lang_types_uint_t prime mk_lang_constexpr_init;

	mk_lang_assert(adler32);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(data_len <= 4 * 1024);

	buf = data_buf;
	len = data_len;
	if(len != 0)
	{
		n = len;
		for(i = 0; i != n; ++i)
		{
			mk_sl_cui_uint8_to_bi_uchar(&buf[i], &tuc);
			mk_sl_cui_uint32_from_bi_uchar(&tcui32, &tuc);
			mk_lang_assert(!mk_sl_cui_uint32_would_overflow_add_cc(&adler32->m_a, &tcui32));
			mk_sl_cui_uint32_add2_wrap_cid_cod(&adler32->m_a, &tcui32);
			mk_lang_assert(!mk_sl_cui_uint32_would_overflow_add_cc(&adler32->m_b, &adler32->m_a));
			mk_sl_cui_uint32_add2_wrap_cid_cod(&adler32->m_b, &adler32->m_a);
		}
		prime = 65521u; mk_sl_cui_uint32_from_bi_uint(&tcui32, &prime);
		mk_sl_cui_uint32_mod2_wrap(&adler32->m_a, &tcui32);
		mk_sl_cui_uint32_mod2_wrap(&adler32->m_b, &tcui32);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_adler32_init(mk_lib_hash_adler32_pt const adler32) mk_lang_noexcept
{
	mk_lang_assert(adler32);

	mk_sl_cui_uint32_set_one(&adler32->m_a);
	mk_sl_cui_uint32_set_zero(&adler32->m_b);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_adler32_append(mk_lib_hash_adler32_pt const adler32, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct buf mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(adler32);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	buf = data_buf;
	len = data_len;
	n = data_len / (4 * 1024);
	for(i = 0; i != n; ++i)
	{
		mk_lib_hash_adler32_block(adler32, buf, 4 * 1024);
		buf += 4 * 1024;
		len -= 4 * 1024;
	}
	mk_lang_assert(len < 4 * 1024);
	mk_lib_hash_adler32_block(adler32, buf, len);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_hash_adler32_finish(mk_lib_hash_adler32_pt const adler32, mk_sl_cui_uint32_pt const digest) mk_lang_noexcept
{
	mk_sl_cui_uint32_t tcui32 mk_lang_constexpr_init;

	mk_lang_assert(adler32);
	mk_lang_assert(digest);

	mk_sl_cui_uint32_shl3(&adler32->m_b, mk_sl_cui_uint16_size_bits_v, &tcui32);
	mk_sl_cui_uint32_or2(&tcui32, &adler32->m_a);
	*digest = tcui32;
}


#endif
