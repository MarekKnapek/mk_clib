#include "mk_lib_fmt.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <stdarg.h> /* va_list va_start va_arg va_end */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_lib_fmt_v(mk_lang_types_pchar_pct const fmt, va_list const vp, mk_lang_types_pchar_pt const dst) mk_lang_noexcept
{
	mk_lang_types_pchar_pct f;
	mk_lang_types_pchar_pt d;
	va_list va;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t ch;
	mk_lang_types_pchar_pct vas;
	mk_lang_types_sint_t vai;
	mk_lang_types_sint_t i;
	mk_lang_types_usize_t ret;

	mk_lang_assert(fmt);
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
				vas = va_arg(va, mk_lang_types_pchar_pct);
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
					vai = va_arg(va, mk_lang_types_sint_t);
					len = vai;
					++f;
					ch = *f;
					if(ch == 's')
					{
						vas = va_arg(va, mk_lang_types_pchar_pct);
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
	ret = mk_lib_fmt_v(fmt, va, dst);
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
	ret = mk_lib_fmt_v(fmt, va, dst);
	va_end(va);
	mk_lang_assert(ret <= mk_lang_limits_sint_max);
	return ((mk_lang_types_sint_t)(ret));
}
