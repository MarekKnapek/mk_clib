#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"

#include <stdarg.h> /* va_list va_start va_arg va_end */


#include "mk_lib_fmt_inl_defd.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fmt_inl_defd_fn_vsnprintf(mk_lib_fmt_inl_defd_char_pt const dst, mk_lang_types_sint_t const len, mk_lib_fmt_inl_defd_char_pct const fmt, va_list* const va) mk_lang_noexcept
{
	static mk_lang_types_sint_t const s_negative_offset = 64;

	mk_lib_fmt_inl_defd_char_pt d;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_lib_fmt_inl_defd_char_pct f;
	mk_lib_fmt_inl_defd_char_t ch;
	mk_lib_fmt_inl_defd_char_pct vas;
	mk_lang_types_sint_pct vasip;
	mk_lang_types_sint_t vasiv;
	mk_lang_types_uint_t vauiv;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_sint_t lim;
	mk_lang_types_sint_t tsi;
	mk_lang_types_uint_pct vauip;
	mk_lang_types_sint_t ret;

	mk_lang_assert(dst);
	mk_lang_assert(len >= 0);
	mk_lang_assert(fmt);
	mk_lang_assert(va);

	d = dst;
	rem = len;
	bad = mk_lang_false;
	for(f = fmt; f[0] != mk_lib_fmt_inl_defd_char_c('\0'); ++f)
	{
		ch = f[0];
		if(ch == mk_lib_fmt_inl_defd_char_c('%'))
		{
			++f;
			ch = f[0];
			if(ch == mk_lib_fmt_inl_defd_char_c('%'))
			{
				if(!(rem >= 1)){ bad = mk_lang_true; break; }
				d[0] = mk_lib_fmt_inl_defd_char_c('%');
				++d;
				--rem;
				break;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('s'))
			{
				vas = va_arg(*va, mk_lib_fmt_inl_defd_char_pct);
				mk_lang_assert(vas);
				while(vas[0] != mk_lib_fmt_inl_defd_char_c('\0'))
				{
					if(!(rem >= 1)){ bad = mk_lang_true; break; }
					d[0] = vas[0];
					++d;
					--rem;
					++vas;
				}
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('d'))
			{
				vasip = va_arg(*va, mk_lang_types_sint_pct);
				vasiv = *vasip;
				if(vasiv < 0)
				{
					if(!(rem >= 1)){ bad = mk_lang_true; break; }
					d[0] = mk_lib_fmt_inl_defd_char_c('-');
					++d;
					--rem;
					if(vasiv < -s_negative_offset)
					{
						vauiv = ((mk_lang_types_uint_t)(((mk_lang_types_uint_t)(((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(0)) - ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(vasiv)) + ((mk_lang_types_sint_t)(s_negative_offset)))))))) + ((mk_lang_types_uint_t)(s_negative_offset))));
					}
					else
					{
						vauiv = ((mk_lang_types_uint_t)(((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(0)) - ((mk_lang_types_sint_t)(vasiv))))));
					}
				}
				else
				{
					vauiv = ((mk_lang_types_uint_t)(vasiv));
				}
				mk_sl_cui_uint32_from_bi_uint(&tu32, &vauiv);
				lim = mk_lang_min(mk_sl_cui_uint32_strlendec_v, rem);
				#if mk_lib_fmt_inl_defd_wide == 0
				tsi = mk_sl_cui_uint32_to_str_dec_n(&tu32, d, lim);
				#else
				tsi = mk_sl_cui_uint32_to_str_dec_w(&tu32, d, lim);
				#endif
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi;
				rem -= tsi;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('u'))
			{
				vauip = va_arg(*va, mk_lang_types_uint_pct);
				vauiv = *vauip;
				mk_sl_cui_uint32_from_bi_uint(&tu32, &vauiv);
				lim = mk_lang_min(mk_sl_cui_uint32_strlendec_v, rem);
				#if mk_lib_fmt_inl_defd_wide == 0
				tsi = mk_sl_cui_uint32_to_str_dec_n(&tu32, d, lim);
				#else
				tsi = mk_sl_cui_uint32_to_str_dec_w(&tu32, d, lim);
				#endif
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi;
				rem -= tsi;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('x'))
			{
				vauip = va_arg(*va, mk_lang_types_uint_pct);
				vauiv = *vauip;
				mk_sl_cui_uint32_from_bi_uint(&tu32, &vauiv);
				lim = mk_lang_min(mk_sl_cui_uint32_strlenhex_v, rem);
				#if mk_lib_fmt_inl_defd_wide == 0
				tsi = mk_sl_cui_uint32_to_str_hex_n(&tu32, d, lim);
				#else
				tsi = mk_sl_cui_uint32_to_str_hex_w(&tu32, d, lim);
				#endif
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi;
				rem -= tsi;
			}
			/*else if(ch == 'l')
			{
				++f;
				ch = f[0];
				mk_lang_assert(ch == 'l');
				++f;
				ch = f[0];
				if(ch == 'u')
				{
					vaullp = va_arg(*va, mk_lib_fmt_cui_ullong_pct);
					lim = mk_lang_min(mk_lib_fmt_cui_ullong_strlendec_v, rem);
					tsi = mk_lib_fmt_cui_ullong_to_str_dec_n(vaullp, d, lim);
					if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
					d += tsi;
					rem -= tsi;
				}
				else
				{
					mk_lang_assert(mk_lang_false);
				}
			}*/
			else
			{
				mk_lang_assert(mk_lang_false);
			}
		}
		else
		{
			if(!(rem >= 1)){ bad = mk_lang_true; break; }
			d[0] = ch;
			++d;
			--rem;
		}
	}
	if(!bad)
	{
		if(rem >= 1)
		{
			d[0] = '\0';
			ret = ((mk_lang_types_sint_t)(d - dst));
		}
		else
		{
			ret = 0;
		}
	}
	else
	{
		ret = 0;
	}
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fmt_inl_defd_fn_snprintf(mk_lib_fmt_inl_defd_char_pt const dst, mk_lang_types_sint_t const len, mk_lib_fmt_inl_defd_char_pct const fmt, ...) mk_lang_noexcept
{
	va_list va;
	mk_lang_types_sint_t r;

	mk_lang_assert(dst);
	mk_lang_assert(len >= 0);
	mk_lang_assert(fmt);
	mk_lang_assert(dst != fmt);

	va_start(va, fmt);
	r = mk_lib_fmt_inl_defd_fn_vsnprintf(dst, len, fmt, &va);
	va_end(va);
	return r;
}


#include "mk_lib_fmt_inl_defu.h"


#undef mk_lib_fmt_t_name
#undef mk_lib_fmt_t_wide
