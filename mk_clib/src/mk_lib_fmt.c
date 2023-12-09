#include "mk_lib_fmt.h"

#include "mk_lang_assert.h"
#include "mk_lang_bitness.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"

#define mk_lang_bui_t_name mk_lib_fmt_bui_uint
#define mk_lang_bui_t_base uint
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_t_name mk_lib_fmt_cui_uint
#define mk_sl_cui_t_base mk_lib_fmt_bui_uint
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_sizebits_d (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#if mk_lang_bitness == mk_lang_bitness_64

#define mk_lang_bui_t_name mk_lib_fmt_bui_ullong
#define mk_lang_bui_t_base ullong
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_t_name mk_lib_fmt_cui_ullong
#define mk_sl_cui_t_base mk_lib_fmt_bui_ullong
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_sizebits_d (mk_lang_sizeof_bi_ullong_t * mk_lang_charbit)
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#else

#define mk_sl_cui_t_name mk_lib_fmt_cui_ullong
#define mk_sl_cui_t_base mk_lib_fmt_bui_uint
#define mk_sl_cui_t_count 2
#define mk_sl_cui_t_base_sizebits_d (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_t_disable_big_div 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#endif


#include <stdarg.h> /* va_list va_start va_arg va_end */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_lib_fmt_v(mk_lang_types_pchar_pct const fmt, va_list* const vp, mk_lang_types_pchar_pt const dst) mk_lang_noexcept
{
	mk_lang_types_pchar_pct f;
	mk_lang_types_pchar_pt d;
	va_list* va;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t ch;
	mk_lang_types_pchar_pct vas;
	mk_lang_types_sint_t vai;
	mk_lang_types_sint_t i;
	mk_lang_types_usize_t ret;

	mk_lang_assert(fmt);
	mk_lang_assert(vp);
	mk_lang_assert(dst);

	f = fmt;
	d = dst;
	va = vp;
	len = 0;
	for(;;)
	{
		ch = *f;
		if(ch == '\0')
		{
			*d = '\0';
			break;
		}
		else if(ch == '%')
		{
			++f;
			ch = *f;
			if(ch == '%')
			{
				*d = '%';
				++d;
			}
			else if(ch == 's')
			{
				vas = va_arg(*va, mk_lang_types_pchar_pct);
				mk_lang_assert(vas);
				while(*vas)
				{
					*d = *vas;
					++d;
					++vas;
				}
			}
			else if(ch == '.')
			{
				++f;
				ch = *f;
				if(ch == '*')
				{
					vai = va_arg(*va, mk_lang_types_sint_t);
					len = vai;
					++f;
					ch = *f;
					if(ch == 's')
					{
						vas = va_arg(*va, mk_lang_types_pchar_pct);
						mk_lang_assert(vas);
						for(i = 0; i != len; ++i)
						{
							*d = *vas;
							++d;
							++vas;
						}
					}
					else
					{
						mk_lang_assert(0);
					}
				}
				else
				{
					mk_lang_assert(0);
				}
			}
			else
			{
				mk_lang_assert(0);
			}
		}
		else
		{
			*d = ch;
			++d;
		}
		++f;
	}
	ret = ((mk_lang_types_usize_t)(d - dst));
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_lib_fmt(mk_lang_types_pchar_pct const fmt, mk_lang_types_pchar_pt const dst, ...) mk_lang_noexcept
{
	va_list va;
	mk_lang_types_usize_t ret;

	mk_lang_assert(fmt);
	mk_lang_assert(dst);

	va_start(va, dst);
	ret = mk_lib_fmt_v(fmt, &va, dst);
	va_end(va);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fmt_sprintf(mk_lang_types_pchar_pt const dst, mk_lang_types_pchar_pct const fmt, ...) mk_lang_noexcept
{
	va_list va;
	mk_lang_types_usize_t ret;

	mk_lang_assert(fmt);
	mk_lang_assert(dst);

	va_start(va, fmt);
	ret = mk_lib_fmt_v(fmt, &va, dst);
	va_end(va);
	mk_lang_assert(ret <= mk_lang_limits_sint_max);
	return ((mk_lang_types_sint_t)(ret));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fmt_vsnprintf(mk_lang_types_pchar_pt const dst, mk_lang_types_sint_t const len, mk_lang_types_pchar_pct const fmt, va_list* const va) mk_lang_noexcept
{
	static mk_lang_types_sint_t const s_negative_offset = 64;

	mk_lang_types_pchar_pt d;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_lang_types_pchar_pct f;
	mk_lang_types_pchar_t ch;
	mk_lang_types_pchar_pct vas;
	mk_lang_types_sint_pct vasip;
	mk_lang_types_sint_t vasiv;
	mk_lang_types_uint_t vauiv;
	mk_lib_fmt_bui_uint_t tbui;
	mk_lib_fmt_cui_uint_t tcui;
	mk_lang_types_sint_t lim;
	mk_lang_types_sint_t tsi;
	mk_lang_types_uint_pct vauip;
	mk_lib_fmt_cui_ullong_pct vaullp;
	mk_lang_types_sint_t ret;

	mk_lang_assert(dst);
	mk_lang_assert(len >= 0);
	mk_lang_assert(fmt);
	mk_lang_assert(va);

	d = dst;
	rem = len;
	bad = mk_lang_false;
	for(f = fmt; f[0] != '\0'; ++f)
	{
		ch = f[0];
		if(ch == '%')
		{
			++f;
			ch = f[0];
			if(ch == '%')
			{
				if(!(rem >= 1)){ bad = mk_lang_true; break; }
				d[0] = '%';
				++d;
				--rem;
				break;
			}
			else if(ch == 's')
			{
				vas = va_arg(*va, mk_lang_types_pchar_pct);
				mk_lang_assert(vas);
				while(vas[0] != '\0')
				{
					if(!(rem >= 1)){ bad = mk_lang_true; break; }
					d[0] = vas[0];
					++d;
					--rem;
					++vas;
				}
			}
			else if(ch == 'd')
			{
				vasip = va_arg(*va, mk_lang_types_sint_pct);
				vasiv = *vasip;
				if(vasiv < 0)
				{
					if(!(rem >= 1)){ bad = mk_lang_true; break; }
					d[0] = '-';
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
				tbui = ((mk_lib_fmt_bui_uint_t)(vauiv));
				mk_lib_fmt_cui_uint_from_base(&tcui, &tbui);
				lim = mk_lang_min(mk_lib_fmt_cui_uint_strlendec_v, rem);
				tsi = mk_lib_fmt_cui_uint_to_str_dec_n(&tcui, d, lim);
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi;
				rem -= tsi;
			}
			else if(ch == 'u')
			{
				vauip = va_arg(*va, mk_lang_types_uint_pct);
				vauiv = *vauip;
				tbui = ((mk_lib_fmt_bui_uint_t)(vauiv));
				mk_lib_fmt_cui_uint_from_base(&tcui, &tbui);
				lim = mk_lang_min(mk_lib_fmt_cui_uint_strlendec_v, rem);
				tsi = mk_lib_fmt_cui_uint_to_str_dec_n(&tcui, d, lim);
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi;
				rem -= tsi;
			}
			else if(ch == 'x')
			{
				vauip = va_arg(*va, mk_lang_types_uint_pct);
				vauiv = *vauip;
				tbui = ((mk_lib_fmt_bui_uint_t)(vauiv));
				mk_lib_fmt_cui_uint_from_base(&tcui, &tbui);
				lim = mk_lang_min(mk_lib_fmt_cui_uint_strlenhex_v, rem);
				tsi = mk_lib_fmt_cui_uint_to_str_hex_n(&tcui, d, mk_lib_fmt_cui_uint_strlenhex_v);
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi;
				rem -= tsi;
			}
			else if(ch == 'l')
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
					mk_lang_assert(0);
				}
			}
			else
			{
				mk_lang_assert(0);
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fmt_snprintf(mk_lang_types_pchar_pt const dst, mk_lang_types_sint_t const len, mk_lang_types_pchar_pct const fmt, ...) mk_lang_noexcept
{
	va_list va;
	mk_lang_types_sint_t r;

	mk_lang_assert(dst);
	mk_lang_assert(len >= 0);
	mk_lang_assert(fmt);

	va_start(va, fmt);
	r = mk_lib_fmt_vsnprintf(dst, len, fmt, &va);
	va_end(va);
	return r;
}
