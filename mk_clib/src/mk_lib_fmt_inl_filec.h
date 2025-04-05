#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_concat.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_runtime_bool.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"

#include <stdarg.h> /* va_list va_start va_arg va_end */


#include "mk_lib_fmt_inl_defd.h"


#define mk_lib_fmt_inl_filec_overlap_name mk_lang_concat(mk_lib_fmt_inl_defd_name, _zzz_overlap)
#define mk_lang_overlap_t_name mk_lib_fmt_inl_filec_overlap_name
#define mk_lang_overlap_t_type mk_lib_fmt_inl_defd_char_t
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"
#include "mk_lang_overlap_inl_fileu.h"
#define mk_lib_fmt_inl_filec_overlap_fn mk_lang_concat(mk_lib_fmt_inl_filec_overlap_name, _fn)


static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_inl_defd_vsnnprintf_s(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, va_list* const va, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt dst;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_lib_fmt_inl_defd_char_pct vas;

	mk_lang_assert(dst_buf || dst_len == 0);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(va);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);

	dst = dst_buf;
	rem = dst_len;
	bad = mk_lang_false;
	vas = va_arg(*va, mk_lib_fmt_inl_defd_char_pct); mk_lang_assert(vas);
	while(vas[0] != mk_lib_fmt_inl_defd_char_c('\0'))
	{
		if(!(rem >= 1)){ bad = mk_lang_true; break; }
		dst[0] = vas[0];
		++dst; --rem; ++vas;
	}
	*gud = !bad;
	*consumed = dst_len - rem;
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_inl_defd_vsnnprintf_t(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, va_list* const va, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt dst;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_lib_fmt_inl_defd_char_pct vas;
	mk_lang_types_sint_t vai;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(dst_buf || dst_len == 0);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(va);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);

	dst = dst_buf;
	rem = dst_len;
	bad = mk_lang_false;
	vas = va_arg(*va, mk_lib_fmt_inl_defd_char_pct); mk_lang_assert(vas);
	vai = va_arg(*va, mk_lang_types_sint_t); mk_lang_assert(vai >= 0);
	n = vai;
	for(i = 0; i != n; ++i)
	{
		if(!(rem >= 1)){ bad = mk_lang_true; break; }
		dst[0] = vas[0];
		++dst; --rem; ++vas;
	}
	*gud = !bad;
	*consumed = dst_len - rem;
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_inl_defd_vsnnprintf_n(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, va_list* const va, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt dst;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_lang_types_pchar_pct vas;
	mk_lang_types_sint_t vai;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(dst_buf || dst_len == 0);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(va);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);

	dst = dst_buf;
	rem = dst_len;
	bad = mk_lang_false;
	vas = va_arg(*va, mk_lang_types_pchar_pct); mk_lang_assert(vas);
	vai = va_arg(*va, mk_lang_types_sint_t); mk_lang_assert(vai >= 0);
	n = vai;
	for(i = 0; i != n; ++i)
	{
		if(!(rem >= 1)){ bad = mk_lang_true; break; }
		dst[0] = ((mk_lib_fmt_inl_defd_char_t)(vas[0]));
		++dst; --rem; ++vas;
	}
	*gud = !bad;
	*consumed = dst_len - rem;
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_inl_defd_vsnnprintf_x(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, va_list* const va, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt dst;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_sl_cui_uint32_pct vau;
	mk_lang_types_sint_t lim;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(dst_buf || dst_len == 0);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(va);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);

	dst = dst_buf;
	rem = dst_len;
	bad = mk_lang_false;
	vau = va_arg(*va, mk_sl_cui_uint32_pct); mk_lang_assert(vau);
	lim = mk_lang_min(mk_sl_cui_uint32_strlen_hex_v, rem);
	tsi = mk_sl_cui_uint32_to_str_hex_u(vau, dst, lim);
	if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; }
	*gud = !bad;
	*consumed = tsi;
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_inl_defd_vsnnprintf_u(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, va_list* const va, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt dst;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_sl_cui_uint32_pct vau;
	mk_lang_types_sint_t lim;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(dst_buf || dst_len == 0);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(va);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);

	dst = dst_buf;
	rem = dst_len;
	bad = mk_lang_false;
	vau = va_arg(*va, mk_sl_cui_uint32_pct); mk_lang_assert(vau);
	lim = mk_lang_min(mk_sl_cui_uint32_strlen_dec_v, rem);
	tsi = mk_sl_cui_uint32_to_str_dec_u(vau, dst, lim);
	if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; }
	*gud = !bad;
	*consumed = tsi;
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_inl_defd_vsnnprintf_d(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, va_list* const va, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt dst;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_sl_cui_uint32_pct vau;
	mk_sl_cui_uint32_t tui;
	mk_lang_types_sint_t lim;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(dst_buf || dst_len == 0);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(va);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);

	dst = dst_buf;
	rem = dst_len;
	bad = mk_lang_false;
	vau = va_arg(*va, mk_sl_cui_uint32_pct); mk_lang_assert(vau);
	do
	{
		if(mk_sl_cui_uint32_is_bit(vau, mk_sl_cui_uint32_size_bits_v - 1))
		{
			if(!(rem >= 1)){ bad = mk_lang_true; break; }
			dst[0] = mk_lib_fmt_inl_defd_char_c('-');
			++dst; --rem;
			mk_sl_cui_uint32_not2(vau, &tui);
			mk_sl_cui_uint32_inc1(&tui);
			vau = &tui;
		}
		lim = mk_lang_min(mk_sl_cui_uint32_strlen_dec_v, rem);
		tsi = mk_sl_cui_uint32_to_str_dec_u(vau, dst, lim);
		if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
		*consumed = tsi;
	}while(mk_lang_runtime_bool_fn_false);
	*gud = !bad;
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_inl_defd_vsnnprintf_llx(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, va_list* const va, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt dst;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_sl_cui_uint64_pct vau;
	mk_lang_types_sint_t lim;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(dst_buf || dst_len == 0);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(va);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);

	dst = dst_buf;
	rem = dst_len;
	bad = mk_lang_false;
	vau = va_arg(*va, mk_sl_cui_uint64_pct); mk_lang_assert(vau);
	lim = mk_lang_min(mk_sl_cui_uint64_strlen_hex_v, rem);
	tsi = mk_sl_cui_uint64_to_str_hex_u(vau, dst, lim);
	if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; }
	*gud = !bad;
	*consumed = tsi;
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_inl_defd_vsnnprintf_llu(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, va_list* const va, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt dst;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_sl_cui_uint64_pct vau;
	mk_lang_types_sint_t lim;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(dst_buf || dst_len == 0);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(va);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);

	dst = dst_buf;
	rem = dst_len;
	bad = mk_lang_false;
	vau = va_arg(*va, mk_sl_cui_uint64_pct); mk_lang_assert(vau);
	lim = mk_lang_min(mk_sl_cui_uint64_strlen_dec_v, rem);
	tsi = mk_sl_cui_uint64_to_str_dec_u(vau, dst, lim);
	if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; }
	*gud = !bad;
	*consumed = tsi;
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_inl_defd_vsnnprintf_lld(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, va_list* const va, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt dst;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_sl_cui_uint64_pct vau;
	mk_sl_cui_uint64_t tui;
	mk_lang_types_sint_t lim;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(dst_buf || dst_len == 0);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(va);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);

	dst = dst_buf;
	rem = dst_len;
	bad = mk_lang_false;
	vau = va_arg(*va, mk_sl_cui_uint64_pct); mk_lang_assert(vau);
	do
	{
		if(mk_sl_cui_uint64_is_bit(vau, mk_sl_cui_uint64_size_bits_v - 1))
		{
			if(!(rem >= 1)){ bad = mk_lang_true; break; }
			dst[0] = mk_lib_fmt_inl_defd_char_c('-');
			++dst; --rem;
			mk_sl_cui_uint64_not2(vau, &tui);
			mk_sl_cui_uint64_inc1(&tui);
			vau = &tui;
		}
		lim = mk_lang_min(mk_sl_cui_uint64_strlen_dec_v, rem);
		tsi = mk_sl_cui_uint64_to_str_dec_u(vau, dst, lim);
		if(!(tsi >= 1 && tsi <= lim)){ bad = mk_lang_true; break; }
		*consumed = tsi;
	}while(mk_lang_runtime_bool_fn_false);
	*gud = !bad;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fmt_inl_defd_vsnnprintf(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, mk_lib_fmt_inl_defd_char_pct const fmt_buf, mk_lang_types_sint_t const fmt_len, va_list* const va) mk_lang_noexcept
{
	mk_lib_fmt_inl_defd_char_pt dst;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t bad;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_fmt_inl_defd_char_t ch;
	mk_lang_types_sint_t ret;

	mk_lang_assert(dst_buf);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(fmt_buf);
	mk_lang_assert(fmt_len >= 0);
	mk_lang_assert(va);
	mk_lang_assert(dst_buf != fmt_buf);
	mk_lang_assert(!mk_lib_fmt_inl_filec_overlap_fn(dst_buf, ((mk_lang_types_usize_t)(dst_len)), fmt_buf, ((mk_lang_types_usize_t)(fmt_len))));

	dst = dst_buf;
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
				dst[0] = mk_lib_fmt_inl_defd_char_c('%');
				++dst; --rem;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('s'))
			{
				mk_lib_fmt_inl_defd_vsnnprintf_s(dst, rem, va, &gud, &consumed); if(!gud){ break; } mk_lang_assert(consumed >= 1 && consumed <= rem); dst += consumed; rem -= consumed;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('t'))
			{
				mk_lib_fmt_inl_defd_vsnnprintf_t(dst, rem, va, &gud, &consumed); if(!gud){ break; } mk_lang_assert(consumed >= 1 && consumed <= rem); dst += consumed; rem -= consumed;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('n'))
			{
				mk_lib_fmt_inl_defd_vsnnprintf_n(dst, rem, va, &gud, &consumed); if(!gud){ break; } mk_lang_assert(consumed >= 1 && consumed <= rem); dst += consumed; rem -= consumed;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('x'))
			{
				mk_lib_fmt_inl_defd_vsnnprintf_x(dst, rem, va, &gud, &consumed); if(!gud){ break; } mk_lang_assert(consumed >= 1 && consumed <= rem); dst += consumed; rem -= consumed;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('u'))
			{
				mk_lib_fmt_inl_defd_vsnnprintf_u(dst, rem, va, &gud, &consumed); if(!gud){ break; } mk_lang_assert(consumed >= 1 && consumed <= rem); dst += consumed; rem -= consumed;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('d'))
			{
				mk_lib_fmt_inl_defd_vsnnprintf_d(dst, rem, va, &gud, &consumed); if(!gud){ break; } mk_lang_assert(consumed >= 1 && consumed <= rem); dst += consumed; rem -= consumed;
			}
			else if(ch == mk_lib_fmt_inl_defd_char_c('l'))
			{
				++i; mk_lang_assert(i != n);
				ch = fmt_buf[i];
				mk_lang_assert(ch == mk_lib_fmt_inl_defd_char_c('l'));
				++i; mk_lang_assert(i != n);
				ch = fmt_buf[i];
				if(ch == mk_lib_fmt_inl_defd_char_c('x'))
				{
					mk_lib_fmt_inl_defd_vsnnprintf_llx(dst, rem, va, &gud, &consumed); if(!gud){ break; } mk_lang_assert(consumed >= 1 && consumed <= rem); dst += consumed; rem -= consumed;
				}
				else if(ch == mk_lib_fmt_inl_defd_char_c('u'))
				{
					mk_lib_fmt_inl_defd_vsnnprintf_llu(dst, rem, va, &gud, &consumed); if(!gud){ break; } mk_lang_assert(consumed >= 1 && consumed <= rem); dst += consumed; rem -= consumed;
				}
				else if(ch == mk_lib_fmt_inl_defd_char_c('d'))
				{
					mk_lib_fmt_inl_defd_vsnnprintf_lld(dst, rem, va, &gud, &consumed); if(!gud){ break; } mk_lang_assert(consumed >= 1 && consumed <= rem); dst += consumed; rem -= consumed;
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
			dst[0] = ch;
			++dst; --rem;
		}
	}
	if(!bad)
	{
		mk_lang_assert(dst - dst_buf <= ((mk_lang_types_sintptr_t)(mk_lang_limits_sint_max)));
		ret = ((mk_lang_types_sint_t)(dst - dst_buf));
	}
	else
	{
		ret = 0;
	}
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fmt_inl_defd_snnprintf(mk_lib_fmt_inl_defd_char_pt const dst_buf, mk_lang_types_sint_t const dst_len, mk_lib_fmt_inl_defd_char_pct const fmt_buf, mk_lang_types_sint_t const fmt_len, ...) mk_lang_noexcept
{
	va_list va;
	mk_lang_types_sint_t ret;

	mk_lang_assert(dst_buf);
	mk_lang_assert(dst_len >= 0);
	mk_lang_assert(fmt_buf);
	mk_lang_assert(fmt_len >= 0);
	mk_lang_assert(dst_buf != fmt_buf);

	va_start(va, fmt_len);
	ret = mk_lib_fmt_inl_defd_vsnnprintf(dst_buf, dst_len, fmt_buf, fmt_len, &va);
	va_end(va);
	return ret;
}


#undef mk_lib_fmt_inl_filec_overlap_name
#undef mk_lib_fmt_inl_filec_overlap_fn


#include "mk_lib_fmt_inl_defu.h"
