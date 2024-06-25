#include "mk_lib_text_encoding_portable.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_text_encoding_portable_wide_to_utf8_work(mk_lang_types_bool_t const validate, mk_lang_types_wchar_pct const wide_str, mk_lang_types_sint_t const wide_len, mk_lang_types_pchar_pt const utf8_str, mk_lang_types_sint_t const utf8_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
#if mk_lang_sizeof_bi_wchar_t == 2 /* assuming UTF-16LE */
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_pchar_pt out mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_wchar_t twca mk_lang_constexpr_init;
	mk_lang_types_ushort_t tusa mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_wchar_t twcb mk_lang_constexpr_init;
	mk_lang_types_ushort_t tusb mk_lang_constexpr_init;

	mk_lang_assert(validate == mk_lang_false || validate == mk_lang_true);
	mk_lang_assert(wide_str);
	mk_lang_assert(wide_len >= 0);
	mk_lang_assert(utf8_str);
	mk_lang_assert(utf8_len >= 0);
	mk_lang_assert(out_len);

	len = 0;
	out = utf8_str;
	rem = utf8_len;
	n = wide_len;
	for(i = 0; i != n; ++i)
	{
		twca = wide_str[i];
		tusa = ((mk_lang_types_ushort_t)(twca));
		if(!((tusa & 0xfc00) == 0xd800))
		{
			tul = ((mk_lang_types_ulong_t)(tusa));
		}
		else
		{
			if(validate){ mk_lang_check_return(i + 1 != n); }else{ mk_lang_assert(i + 1 != n); }
			++i;
			twcb = wide_str[i];
			tusb = ((mk_lang_types_ushort_t)(twcb));
			if(validate){ mk_lang_check_return((tusb & 0xfc00) == 0xdc00); }else{ mk_lang_assert((tusb & 0xfc00) == 0xdc00); }
			tul = ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tusa)) & ((mk_lang_types_ulong_t)(0x03fful)))) << 10)) | ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tusb)) & ((mk_lang_types_ulong_t)(0x03fful)))))) + ((mk_lang_types_ulong_t)(0x10000ul))));
		}
		if(tul >= 0x00000000ul && tul <= 0x0000007ful)
		{
			mk_lang_check_return(rem >= 1);
			out[0] = ((mk_lang_types_pchar_t)(((mk_lang_types_uchar_t)(tul))));
			++len; ++out; --rem;
		}
		else if(tul >= 0x00000080ul && tul <= 0x000007fful)
		{
			mk_lang_check_return(rem >= 2);
			out[0] = ((mk_lang_types_pchar_t)(((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(0xc0ul)) | ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(tul >> (1 * 6))) & 0x0000001ful))))));
			out[1] = ((mk_lang_types_pchar_t)(((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(0x80ul)) | ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(tul >> (0 * 6))) & 0x0000003ful))))));
			++len; ++out; --rem;
			++len; ++out; --rem;
		}
		else if(tul >= 0x00000800ul && tul <= 0x0000fffful)
		{
			mk_lang_check_return(rem >= 3);
			out[0] = ((mk_lang_types_pchar_t)(((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(0xe0ul)) | ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(tul >> (2 * 6))) & 0x0000000ful))))));
			out[1] = ((mk_lang_types_pchar_t)(((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(0x80ul)) | ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(tul >> (1 * 6))) & 0x0000003ful))))));
			out[2] = ((mk_lang_types_pchar_t)(((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(0x80ul)) | ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(tul >> (0 * 6))) & 0x0000003ful))))));
			++len; ++out; --rem;
			++len; ++out; --rem;
			++len; ++out; --rem;
		}
		else if(tul >= 0x00010000ul && tul <= 0x10fffful)
		{
			mk_lang_check_return(rem >= 4);
			out[0] = ((mk_lang_types_pchar_t)(((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(0xf0ul)) | ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(tul >> (3 * 6))) & 0x00000007ul))))));
			out[1] = ((mk_lang_types_pchar_t)(((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(0x80ul)) | ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(tul >> (2 * 6))) & 0x0000003ful))))));
			out[2] = ((mk_lang_types_pchar_t)(((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(0x80ul)) | ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(tul >> (1 * 6))) & 0x0000003ful))))));
			out[3] = ((mk_lang_types_pchar_t)(((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(0x80ul)) | ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(tul >> (0 * 6))) & 0x0000003ful))))));
			++len; ++out; --rem;
			++len; ++out; --rem;
			++len; ++out; --rem;
			++len; ++out; --rem;
		}
		else
		{
			if(validate){ mk_lang_check_return(mk_lang_false); }else{ mk_lang_assert(mk_lang_false); }
		}
	}
	*out_len = len;
	return 0;
#else
	((mk_lang_types_void_t)(validate));
	((mk_lang_types_void_t)(wide_str));
	((mk_lang_types_void_t)(wide_len));
	((mk_lang_types_void_t)(utf8_str));
	((mk_lang_types_void_t)(utf8_len));
	((mk_lang_types_void_t)(out_len));
	mk_lang_check_return(mk_lang_false);
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_text_encoding_portable_wide_to_utf8_len(mk_lang_types_bool_t const validate, mk_lang_types_wchar_pct const wide_str, mk_lang_types_sint_t const wide_len, mk_lang_types_pchar_pt const utf8_str, mk_lang_types_sint_t const utf8_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
#if mk_lang_sizeof_bi_wchar_t == 2 /* assuming UTF-16LE */
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_wchar_t twca mk_lang_constexpr_init;
	mk_lang_types_ushort_t tusa mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_wchar_t twcb mk_lang_constexpr_init;
	mk_lang_types_ushort_t tusb mk_lang_constexpr_init;

	mk_lang_assert(validate == mk_lang_false || validate == mk_lang_true);
	mk_lang_assert(wide_str);
	mk_lang_assert(wide_len >= 0);
	mk_lang_assert(!utf8_str);
	mk_lang_assert(utf8_len == 0);
	mk_lang_assert(out_len);

	len = 0;
	n = wide_len;
	for(i = 0; i != n; ++i)
	{
		twca = wide_str[i];
		tusa = ((mk_lang_types_ushort_t)(twca));
		if(!((tusa & 0xfc00) == 0xd800))
		{
			tul = ((mk_lang_types_ulong_t)(tusa));
		}
		else
		{
			if(validate){ mk_lang_check_return(i + 1 != n); }else{ mk_lang_assert(i + 1 != n); }
			++i;
			twcb = wide_str[i];
			tusb = ((mk_lang_types_ushort_t)(twcb));
			if(validate){ mk_lang_check_return((tusb & 0xfc00) == 0xdc00); }else{ mk_lang_assert((tusb & 0xfc00) == 0xdc00); }
			tul = ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tusa)) & ((mk_lang_types_ulong_t)(0x03fful)))) << 10)) | ((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(tusb)) & ((mk_lang_types_ulong_t)(0x03fful)))))) + ((mk_lang_types_ulong_t)(0x10000ul))));
		}
		if(tul >= 0x00000000ul && tul <= 0x0000007ful)
		{
			++len;
		}
		else if(tul >= 0x00000080ul && tul <= 0x000007fful)
		{
			++len;
			++len;
		}
		else if(tul >= 0x00000800ul && tul <= 0x0000fffful)
		{
			++len;
			++len;
			++len;
		}
		else if(tul >= 0x00010000ul && tul <= 0x10fffful)
		{
			++len;
			++len;
			++len;
			++len;
		}
		else
		{
			if(validate){ mk_lang_check_return(mk_lang_false); }else{ mk_lang_assert(mk_lang_false); }
		}
	}
	*out_len = len;
	return 0;
#else
	((mk_lang_types_void_t)(validate));
	((mk_lang_types_void_t)(wide_str));
	((mk_lang_types_void_t)(wide_len));
	((mk_lang_types_void_t)(utf8_str));
	((mk_lang_types_void_t)(utf8_len));
	((mk_lang_types_void_t)(out_len));
	mk_lang_check_return(mk_lang_false);
	return 0;
#endif
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_text_encoding_portable_wide_to_utf8(mk_lang_types_wchar_pct const wide_str, mk_lang_types_sint_t const wide_len, mk_lang_types_pchar_pt const utf8_str, mk_lang_types_sint_t const utf8_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	if(!utf8_str && utf8_len == 0)
	{
		return mk_lib_text_encoding_portable_wide_to_utf8_len(mk_lang_false, wide_str, wide_len, utf8_str, utf8_len, out_len);
	}
	else
	{
		return mk_lib_text_encoding_portable_wide_to_utf8_work(mk_lang_false, wide_str, wide_len, utf8_str, utf8_len, out_len);
	}
}
