#ifndef mk_include_guard_mk_sl_unicode_c
#define mk_include_guard_mk_sl_unicode_c
#include "mk_sl_unicode.h"

#include "mk_lang_limits.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stdint.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_unicode_utf16_wchar_to_utf8_u8(mk_lang_types_wchar_pct const utf16_buf, mk_lang_types_sint_t const utf16_len, mk_sl_cui_uint8_pt const utf8_buf, mk_lang_types_sint_t const utf8_len, mk_lang_types_sint_pt const utf16_constumed, mk_lang_types_sint_pt const utf8_consumed) mk_lang_noexcept
{
	#define hi_surrogate_beg ((mk_lang_stdint_uint16_t)(0xd800))
	#define hi_surrogate_end ((mk_lang_stdint_uint16_t)(0xdbff))
	#define lo_surrogate_beg ((mk_lang_stdint_uint16_t)(0xdc00))
	#define lo_surrogate_end ((mk_lang_stdint_uint16_t)(0xdfff))
	#define mask_10_bits ((mk_lang_stdint_uint16_t)(((mk_lang_stdint_uint16_t)(((mk_lang_stdint_uint16_t)(1u)) << 10)) - 1))
	#define mask_6_bits ((mk_lang_stdint_uint32_t)(((mk_lang_stdint_uint32_t)(((mk_lang_stdint_uint32_t)(1u)) << ((mk_lang_types_sint_t)(6)))) - ((mk_lang_stdint_uint32_t)(1))))
	#define mask_5_bits ((mk_lang_stdint_uint32_t)(((mk_lang_stdint_uint32_t)(((mk_lang_stdint_uint32_t)(1u)) << ((mk_lang_types_sint_t)(5)))) - ((mk_lang_stdint_uint32_t)(1))))
	#define mask_4_bits ((mk_lang_stdint_uint32_t)(((mk_lang_stdint_uint32_t)(((mk_lang_stdint_uint32_t)(1u)) << ((mk_lang_types_sint_t)(4)))) - ((mk_lang_stdint_uint32_t)(1))))
	#define mask_3_bits ((mk_lang_stdint_uint32_t)(((mk_lang_stdint_uint32_t)(((mk_lang_stdint_uint32_t)(1u)) << ((mk_lang_types_sint_t)(3)))) - ((mk_lang_stdint_uint32_t)(1))))
	#define continuation_byte ((mk_lang_types_uchar_t)(0x80))
	#define leading_byte_2 ((mk_lang_types_uchar_t)(0xc0))
	#define leading_byte_3 ((mk_lang_types_uchar_t)(0xe0))
	#define leading_byte_4 ((mk_lang_types_uchar_t)(0xf0))

	mk_lang_types_sint_t utf16_cur mk_lang_constexpr_init;
	mk_lang_types_sint_t utf8_cur mk_lang_constexpr_init;
	mk_lang_stdint_uint16_t tus_a mk_lang_constexpr_init;
	mk_lang_stdint_uint16_t tus_b mk_lang_constexpr_init;
	mk_lang_stdint_uint32_t tu32a mk_lang_constexpr_init;
	mk_lang_stdint_uint32_t tu32b mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_sint_t utf16_ccc mk_lang_constexpr_init;
	mk_lang_types_sint_t utf8_ccc mk_lang_constexpr_init;

	mk_lang_assert(utf16_buf || utf16_len == 0);
	mk_lang_assert(utf16_len >= 0);
	mk_lang_assert(utf16_len <= mk_lang_limits_sint_max / 3);
	mk_lang_assert(utf8_buf || utf8_len == 0);
	mk_lang_assert(utf8_len >= 0);
	mk_lang_assert(utf8_len >= utf16_len * 3);
	mk_lang_assert(utf16_constumed);
	mk_lang_assert(utf8_consumed);

	utf16_cur = 0;
	utf8_cur = 0;
	for(;;)
	{
		tus_a = ((mk_lang_stdint_uint16_t)(utf16_buf[utf16_cur]));
		if(tus_a >= hi_surrogate_beg && tus_a <= hi_surrogate_end)
		{
			if(!(utf16_cur + 1 < utf16_len))
			{
				break; /* missing low surrogate */
			}
			tus_b = ((mk_lang_stdint_uint16_t)(utf16_buf[utf16_cur + 1]));
			if(!(tus_b >= lo_surrogate_beg && tus_b <= lo_surrogate_end))
			{
				break; /* expecting low surrogate */
			}
			utf16_cur += 2;
			tu32a =
			((mk_lang_stdint_uint32_t)(
				((mk_lang_stdint_uint32_t)(((mk_lang_stdint_uint32_t)(tus_a & mask_10_bits)) << (1 * 10))) |
				((mk_lang_stdint_uint32_t)(((mk_lang_stdint_uint32_t)(tus_b & mask_10_bits)) << (0 * 10)))
			));
		}
		else if(tus_a >= lo_surrogate_beg && tus_a <= lo_surrogate_end)
		{
			break; /* not expecting low surrogate */
		}
		else
		{
			tu32a = ((mk_lang_stdint_uint32_t)(tus_a));
			utf16_cur += 1;
		}
		#include "mk_lang_warning_msvc_push_c4296.h"
		if(tu32a >= ((mk_lang_stdint_uint32_t)(0)) && tu32a < ((mk_lang_stdint_uint32_t)(0x80)))
		#include "mk_lang_warning_msvc_pop.h"
		{
			tuc = ((mk_lang_types_uchar_t)(tu32a));
			mk_sl_cui_uint8_from_bi_uchar(&utf8_buf[utf8_cur], &tuc);
			utf8_cur += 1;
		}
		else if(tu32a >= ((mk_lang_stdint_uint32_t)(0x80)) && tu32a < ((mk_lang_stdint_uint32_t)(0x800)))
		{
			tu32b = tu32a;
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b >> ((mk_lang_types_sint_t)(0 * 6))));
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b & mask_6_bits));
			tuc = ((mk_lang_types_uchar_t)(tu32b));
			tuc = ((mk_lang_types_uchar_t)(tuc | continuation_byte));
			mk_sl_cui_uint8_from_bi_uchar(&utf8_buf[utf8_cur + 1], &tuc);
			tu32b = tu32a;
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b >> ((mk_lang_types_sint_t)(1 * 6))));
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b & mask_5_bits));
			tuc = ((mk_lang_types_uchar_t)(tu32b));
			tuc = ((mk_lang_types_uchar_t)(tuc | leading_byte_2));
			mk_sl_cui_uint8_from_bi_uchar(&utf8_buf[utf8_cur + 0], &tuc);
			utf8_cur += 2;
		}
		else if(tu32a >= ((mk_lang_stdint_uint32_t)(0x800)) && tu32a < ((mk_lang_stdint_uint32_t)(0x10000)))
		{
			tu32b = tu32a;
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b >> ((mk_lang_types_sint_t)(0 * 6))));
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b & mask_6_bits));
			tuc = ((mk_lang_types_uchar_t)(tu32b));
			tuc = ((mk_lang_types_uchar_t)(tuc | continuation_byte));
			mk_sl_cui_uint8_from_bi_uchar(&utf8_buf[utf8_cur + 0], &tuc);
			tu32b = tu32a;
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b >> ((mk_lang_types_sint_t)(1 * 6))));
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b & mask_6_bits));
			tuc = ((mk_lang_types_uchar_t)(tu32b));
			tuc = ((mk_lang_types_uchar_t)(tuc | continuation_byte));
			mk_sl_cui_uint8_from_bi_uchar(&utf8_buf[utf8_cur + 1], &tuc);
			tu32b = tu32a;
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b >> ((mk_lang_types_sint_t)(3 * 6))));
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b & mask_4_bits));
			tuc = ((mk_lang_types_uchar_t)(tu32b));
			tuc = ((mk_lang_types_uchar_t)(tuc | leading_byte_3));
			mk_sl_cui_uint8_from_bi_uchar(&utf8_buf[utf8_cur + 0], &tuc);
			utf8_cur += 3;
		}
		else
		{
			mk_lang_assert(tu32a >= ((mk_lang_stdint_uint32_t)(0x10000)));
			mk_lang_assert(tu32a <= ((mk_lang_stdint_uint32_t)(0x10ffff)));
			tu32b = tu32a;
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b >> ((mk_lang_types_sint_t)(0 * 6))));
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b & mask_6_bits));
			tuc = ((mk_lang_types_uchar_t)(tu32b));
			tuc = ((mk_lang_types_uchar_t)(tuc | continuation_byte));
			mk_sl_cui_uint8_from_bi_uchar(&utf8_buf[utf8_cur + 0], &tuc);
			tu32b = tu32a;
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b >> ((mk_lang_types_sint_t)(1 * 6))));
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b & mask_6_bits));
			tuc = ((mk_lang_types_uchar_t)(tu32b));
			tuc = ((mk_lang_types_uchar_t)(tuc | continuation_byte));
			mk_sl_cui_uint8_from_bi_uchar(&utf8_buf[utf8_cur + 1], &tuc);
			tu32b = tu32a;
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b >> ((mk_lang_types_sint_t)(3 * 6))));
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b & mask_6_bits));
			tuc = ((mk_lang_types_uchar_t)(tu32b));
			tuc = ((mk_lang_types_uchar_t)(tuc | continuation_byte));
			mk_sl_cui_uint8_from_bi_uchar(&utf8_buf[utf8_cur + 2], &tuc);
			tu32b = tu32a;
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b >> ((mk_lang_types_sint_t)(4 * 6))));
			tu32b = ((mk_lang_stdint_uint32_t)(tu32b & mask_3_bits));
			tuc = ((mk_lang_types_uchar_t)(tu32b));
			tuc = ((mk_lang_types_uchar_t)(tuc | leading_byte_4));
			mk_sl_cui_uint8_from_bi_uchar(&utf8_buf[utf8_cur + 0], &tuc);
			utf8_cur += 4;
		}
		if(utf16_cur == utf16_len)
		{
			break;
		}
	}
	utf16_ccc = utf16_cur;
	utf8_ccc = utf8_cur;
	*utf16_constumed = utf16_ccc;
	*utf8_consumed = utf8_ccc;

	#undef hi_surrogate_beg
	#undef hi_surrogate_end
	#undef lo_surrogate_beg
	#undef lo_surrogate_end
	#undef mask_10_bits
	#undef mask_6_bits
	#undef mask_5_bits
	#undef mask_4_bits
	#undef mask_3_bits
	#undef continuation_byte
	#undef leading_byte_2
	#undef leading_byte_3
	#undef leading_byte_4
}


#endif
