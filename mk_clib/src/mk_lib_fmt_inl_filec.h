#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"

#include <stdarg.h> /* va_list va_start va_arg va_end */


#include "mk_lib_fmt_inl_defd.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fmt_inl_defd_fn_vsnprintf(mk_lib_fmt_inl_defd_char_pt const dst, mk_lang_types_sint_t const len, mk_lib_fmt_inl_defd_char_pct const fmt, va_list* const va) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt d;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_lib_fmt_inl_defd_char_pct f;
	mk_lib_fmt_inl_defd_char_t ch;
	mk_lib_fmt_inl_defd_char_pct vas;
	mk_sl_cui_uint32_pct vau32;
	mk_sl_cui_uint32_t tu32a;
	mk_lang_types_sint_t lim;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t ret;
	mk_sl_cui_uint64_pct vau64;
	mk_sl_cui_uint64_t tu64a;

	mk_lang_assert(dst);
	mk_lang_assert(len >= 0);
	mk_lang_assert(fmt);
	mk_lang_assert(va);
	mk_lang_assert(dst != fmt);

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
				++d; --rem;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('s'))
			{
				vas = va_arg(*va, mk_lib_fmt_inl_defd_char_pct);
				mk_lang_assert(vas);
				while(vas[0] != mk_lib_fmt_inl_defd_char_c('\0'))
				{
					if(!(rem >= 1)){ bad = mk_lang_true; break; }
					d[0] = vas[0];
					++d; --rem; ++vas;
				}
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('d'))
			{
				vau32 = va_arg(*va, mk_sl_cui_uint32_pct);
				mk_lang_assert(vau32);
				mk_sl_cui_uint32_shr3(vau32, 32 - 1, &tu32a);
				if(mk_sl_cui_uint32_has_lsb(&tu32a))
				{
					if(!(rem >= 1)){ bad = mk_lang_true; break; }
					d[0] = mk_lib_fmt_inl_defd_char_c('-');
					++d; --rem;
					mk_sl_cui_uint32_not2(vau32, &tu32a);
					mk_sl_cui_uint32_inc1(&tu32a);
				}
				else
				{
					tu32a = *vau32;
				}
				lim = mk_lang_min(mk_sl_cui_uint32_strlendec_v, rem);
				#if mk_lib_fmt_inl_defd_wide == 0
				tsi = mk_sl_cui_uint32_to_str_dec_n(&tu32a, d, lim);
				#else
				tsi = mk_sl_cui_uint32_to_str_dec_w(&tu32a, d, lim);
				#endif
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi; rem -= tsi;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('u'))
			{
				vau32 = va_arg(*va, mk_sl_cui_uint32_pct);
				mk_lang_assert(vau32);
				lim = mk_lang_min(mk_sl_cui_uint32_strlendec_v, rem);
				#if mk_lib_fmt_inl_defd_wide == 0
				tsi = mk_sl_cui_uint32_to_str_dec_n(vau32, d, lim);
				#else
				tsi = mk_sl_cui_uint32_to_str_dec_w(vau32, d, lim);
				#endif
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi; rem -= tsi;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('x'))
			{
				vau32 = va_arg(*va, mk_sl_cui_uint32_pct);
				mk_lang_assert(vau32);
				lim = mk_lang_min(mk_sl_cui_uint32_strlenhex_v, rem);
				#if mk_lib_fmt_inl_defd_wide == 0
				tsi = mk_sl_cui_uint32_to_str_hex_n(vau32, d, lim);
				#else
				tsi = mk_sl_cui_uint32_to_str_hex_w(vau32, d, lim);
				#endif
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi; rem -= tsi;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('l'))
			{
				++f;
				ch = f[0];
				mk_lang_assert(ch == mk_lib_fmt_inl_defd_char_c('l'));
				++f;
				ch = f[0];
				if(ch == mk_lib_fmt_inl_defd_char_c('d'))
				{
					vau64 = va_arg(*va, mk_sl_cui_uint64_pct);
					mk_lang_assert(vau64);
					mk_sl_cui_uint64_shr3(vau64, 64 - 1, &tu64a);
					if(mk_sl_cui_uint64_has_lsb(&tu64a))
					{
						if(!(rem >= 1)){ bad = mk_lang_true; break; }
						d[0] = mk_lib_fmt_inl_defd_char_c('-');
						++d; --rem;
						mk_sl_cui_uint64_not2(vau64, &tu64a);
						mk_sl_cui_uint64_inc1(&tu64a);
					}
					else
					{
						tu64a = *vau64;
					}
					lim = mk_lang_min(mk_sl_cui_uint64_strlendec_v, rem);
					#if mk_lib_fmt_inl_defd_wide == 0
					tsi = mk_sl_cui_uint64_to_str_dec_n(&tu64a, d, lim);
					#else
					tsi = mk_sl_cui_uint64_to_str_dec_w(&tu64a, d, lim);
					#endif
					if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
					d += tsi; rem -= tsi;
				}
				else if(ch == mk_lib_fmt_inl_defd_char_c('u'))
				{
					vau64 = va_arg(*va, mk_sl_cui_uint64_pct);
					mk_lang_assert(vau64);
					lim = mk_lang_min(mk_sl_cui_uint64_strlendec_v, rem);
					#if mk_lib_fmt_inl_defd_wide == 0
					tsi = mk_sl_cui_uint64_to_str_dec_n(vau64, d, lim);
					#else
					tsi = mk_sl_cui_uint64_to_str_dec_w(vau64, d, lim);
					#endif
					if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
					d += tsi; rem -= tsi;
				}
				else if(ch == mk_lib_fmt_inl_defd_char_c('x'))
				{
					vau64 = va_arg(*va, mk_sl_cui_uint64_pct);
					mk_lang_assert(vau64);
					lim = mk_lang_min(mk_sl_cui_uint64_strlenhex_v, rem);
					#if mk_lib_fmt_inl_defd_wide == 0
					tsi = mk_sl_cui_uint64_to_str_hex_n(vau64, d, lim);
					#else
					tsi = mk_sl_cui_uint64_to_str_hex_w(vau64, d, lim);
					#endif
					if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
					d += tsi; rem -= tsi;
				}
				else
				{
					mk_lang_assert(mk_lang_false);
				}
			}
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
			d[0] = mk_lib_fmt_inl_defd_char_c('\0');
			mk_lang_assert(d - dst <= ((mk_lang_types_sintptr_t)(mk_lang_limits_sint_max)));
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fmt_inl_defd_fn_vsnnprintf(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, mk_lib_fmt_inl_defd_char_pct const fmt_buf, mk_lang_types_sint_t const fmt_len, va_list* const va) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt d;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_fmt_inl_defd_char_t ch;
	mk_lib_fmt_inl_defd_char_pct vas;
	mk_sl_cui_uint32_pct vau32;
	mk_sl_cui_uint32_t tu32a;
	mk_lang_types_sint_t lim;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t ret;
	mk_sl_cui_uint64_pct vau64;
	mk_sl_cui_uint64_t tu64a;

	mk_lang_assert(dst_buf);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(fmt_buf);
	mk_lang_assert(fmt_len >= 0);
	mk_lang_assert(va);
	mk_lang_assert(dst_buf != fmt_buf);

	d = dst_buf;
	rem = dst_len;
	bad = mk_lang_false;
	n = fmt_len;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(fmt_buf[i] != mk_lib_fmt_inl_defd_char_c('\0'));
		ch = fmt_buf[i];
		if(ch == mk_lib_fmt_inl_defd_char_c('%'))
		{
			++i; mk_lang_assert(i != n);
			ch = fmt_buf[i];
			if(ch == mk_lib_fmt_inl_defd_char_c('%'))
			{
				if(!(rem >= 1)){ bad = mk_lang_true; break; }
				d[0] = mk_lib_fmt_inl_defd_char_c('%');
				++d; --rem;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('s'))
			{
				vas = va_arg(*va, mk_lib_fmt_inl_defd_char_pct);
				mk_lang_assert(vas);
				while(vas[0] != mk_lib_fmt_inl_defd_char_c('\0'))
				{
					if(!(rem >= 1)){ bad = mk_lang_true; break; }
					d[0] = vas[0];
					++d; --rem; ++vas;
				}
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('d'))
			{
				vau32 = va_arg(*va, mk_sl_cui_uint32_pct);
				mk_lang_assert(vau32);
				mk_sl_cui_uint32_shr3(vau32, 32 - 1, &tu32a);
				if(mk_sl_cui_uint32_has_lsb(&tu32a))
				{
					if(!(rem >= 1)){ bad = mk_lang_true; break; }
					d[0] = mk_lib_fmt_inl_defd_char_c('-');
					++d; --rem;
					mk_sl_cui_uint32_not2(vau32, &tu32a);
					mk_sl_cui_uint32_inc1(&tu32a);
				}
				else
				{
					tu32a = *vau32;
				}
				lim = mk_lang_min(mk_sl_cui_uint32_strlendec_v, rem);
				#if mk_lib_fmt_inl_defd_wide == 0
				tsi = mk_sl_cui_uint32_to_str_dec_n(&tu32a, d, lim);
				#else
				tsi = mk_sl_cui_uint32_to_str_dec_w(&tu32a, d, lim);
				#endif
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi; rem -= tsi;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('u'))
			{
				vau32 = va_arg(*va, mk_sl_cui_uint32_pct);
				mk_lang_assert(vau32);
				lim = mk_lang_min(mk_sl_cui_uint32_strlendec_v, rem);
				#if mk_lib_fmt_inl_defd_wide == 0
				tsi = mk_sl_cui_uint32_to_str_dec_n(vau32, d, lim);
				#else
				tsi = mk_sl_cui_uint32_to_str_dec_w(vau32, d, lim);
				#endif
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi; rem -= tsi;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('x'))
			{
				vau32 = va_arg(*va, mk_sl_cui_uint32_pct);
				mk_lang_assert(vau32);
				lim = mk_lang_min(mk_sl_cui_uint32_strlenhex_v, rem);
				#if mk_lib_fmt_inl_defd_wide == 0
				tsi = mk_sl_cui_uint32_to_str_hex_n(vau32, d, lim);
				#else
				tsi = mk_sl_cui_uint32_to_str_hex_w(vau32, d, lim);
				#endif
				if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
				d += tsi; rem -= tsi;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('l'))
			{
				++i; mk_lang_assert(i != n);
				ch = fmt_buf[i];
				mk_lang_assert(ch == mk_lib_fmt_inl_defd_char_c('l'));
				++i; mk_lang_assert(i != n);
				ch = fmt_buf[i];
				if(ch == mk_lib_fmt_inl_defd_char_c('d'))
				{
					vau64 = va_arg(*va, mk_sl_cui_uint64_pct);
					mk_lang_assert(vau64);
					mk_sl_cui_uint64_shr3(vau64, 64 - 1, &tu64a);
					if(mk_sl_cui_uint64_has_lsb(&tu64a))
					{
						if(!(rem >= 1)){ bad = mk_lang_true; break; }
						d[0] = mk_lib_fmt_inl_defd_char_c('-');
						++d; --rem;
						mk_sl_cui_uint64_not2(vau64, &tu64a);
						mk_sl_cui_uint64_inc1(&tu64a);
					}
					else
					{
						tu64a = *vau64;
					}
					lim = mk_lang_min(mk_sl_cui_uint64_strlendec_v, rem);
					#if mk_lib_fmt_inl_defd_wide == 0
					tsi = mk_sl_cui_uint64_to_str_dec_n(&tu64a, d, lim);
					#else
					tsi = mk_sl_cui_uint64_to_str_dec_w(&tu64a, d, lim);
					#endif
					if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
					d += tsi; rem -= tsi;
				}
				else if(ch == mk_lib_fmt_inl_defd_char_c('u'))
				{
					vau64 = va_arg(*va, mk_sl_cui_uint64_pct);
					mk_lang_assert(vau64);
					lim = mk_lang_min(mk_sl_cui_uint64_strlendec_v, rem);
					#if mk_lib_fmt_inl_defd_wide == 0
					tsi = mk_sl_cui_uint64_to_str_dec_n(vau64, d, lim);
					#else
					tsi = mk_sl_cui_uint64_to_str_dec_w(vau64, d, lim);
					#endif
					if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
					d += tsi; rem -= tsi;
				}
				else if(ch == mk_lib_fmt_inl_defd_char_c('x'))
				{
					vau64 = va_arg(*va, mk_sl_cui_uint64_pct);
					mk_lang_assert(vau64);
					lim = mk_lang_min(mk_sl_cui_uint64_strlenhex_v, rem);
					#if mk_lib_fmt_inl_defd_wide == 0
					tsi = mk_sl_cui_uint64_to_str_hex_n(vau64, d, lim);
					#else
					tsi = mk_sl_cui_uint64_to_str_hex_w(vau64, d, lim);
					#endif
					if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
					d += tsi; rem -= tsi;
				}
				else
				{
					mk_lang_assert(mk_lang_false);
				}
			}
			else
			{
				mk_lang_assert(mk_lang_false);
			}
		}
		else
		{
			if(!(rem >= 1)){ bad = mk_lang_true; break; }
			d[0] = ch;
			++d; --rem;
		}
	}
	if(!bad)
	{
		mk_lang_assert(d - dst_buf <= ((mk_lang_types_sintptr_t)(mk_lang_limits_sint_max)));
		ret = ((mk_lang_types_sint_t)(d - dst_buf));
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fmt_inl_defd_fn_snnprintf(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, mk_lib_fmt_inl_defd_char_pct const fmt_buf, mk_lang_types_sint_t const fmt_len, ...) mk_lang_noexcept
{
	va_list va;
	mk_lang_types_sint_t r;

	mk_lang_assert(dst_buf);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(fmt_buf);
	mk_lang_assert(fmt_len >= 0);
	mk_lang_assert(dst_buf != fmt_buf);

	va_start(va, fmt_len);
	r = mk_lib_fmt_inl_defd_fn_vsnnprintf(dst_buf, dst_len, fmt_buf, fmt_len, &va);
	va_end(va);
	return r;
}


#include "mk_lib_fmt_inl_defu.h"


#undef mk_lib_fmt_t_name
#undef mk_lib_fmt_t_wide
