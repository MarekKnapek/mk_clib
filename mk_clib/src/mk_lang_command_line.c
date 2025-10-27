#ifndef mk_include_guard_mk_lang_command_line_c
#define mk_include_guard_mk_lang_command_line_c
#include "mk_lang_command_line.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_entry_point.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_str_len.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_command_line_parse_std(mk_lang_types_sint_t const argc_in, mk_lang_types_pchar_pcpct const argv_in, mk_lang_types_pchar_ppct const argv_out, mk_lang_types_sint_pt const lens_out, mk_lang_types_sint_t const count, mk_lang_types_sint_pt const argc_out) mk_lang_noexcept
{
#if !mk_lang_entry_point_have
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(argc_in >= 1);
	mk_lang_assert(argc_in <= count);
	mk_lang_assert(argv_in);
	mk_lang_assert(argv_out);
	mk_lang_assert(lens_out);
	mk_lang_assert(count >= 1);
	mk_lang_assert(argc_out);

	n = argc_in;
	for(i = 0; i != n; ++i)
	{
		mk_lang_check_return(argv_in[i]);
		mk_lang_check_return(argv_in[i][0] != '\0');
		argv_out[i] = argv_in[i];
		lens_out[i] = mk_lang_str_len_n(argv_in[i]); mk_lang_check_return(((mk_lang_types_slong_t)(lens_out[i])) <= 64l * 1024l);
	}
	*argc_out = argc_in;
	return 0;
#else
	mk_lang_assert(argc_in >= 1);
	mk_lang_assert(argc_in <= count);
	mk_lang_assert(argv_in);
	mk_lang_assert(argv_out);
	mk_lang_assert(lens_out);
	mk_lang_assert(count >= 1);
	mk_lang_assert(argc_out);

	((mk_lang_types_void_t)(argc_in));
	((mk_lang_types_void_t)(argv_in));
	((mk_lang_types_void_t)(argv_out));
	((mk_lang_types_void_t)(lens_out));
	((mk_lang_types_void_t)(count));
	((mk_lang_types_void_t)(argc_out));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_command_line_parse_win(mk_lang_types_wchar_pct const cmdline, mk_lang_types_wchar_ppct const argv, mk_lang_types_sint_pt const lens, mk_lang_types_sint_t const count, mk_lang_types_sint_pt const argc) mk_lang_noexcept
{
	mk_lang_types_sint_t curr_argc;
	mk_lang_types_wchar_pct ptr;
	mk_lang_types_wchar_pct arg;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(cmdline);
	mk_lang_assert(cmdline[0] != L'\0');
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(count >= 1 && count <= 64);
	mk_lang_assert(argc);

	curr_argc = 0;
	ptr = cmdline;
	for(;;)
	{
		while(ptr[0] == L' ')
		{
			++ptr;
		}
		if(ptr[0] == L'\0')
		{
			break;
		}
		if(ptr[0] == L'"')
		{
			arg = ptr + 1;
			do
			{
				++ptr;
			}while(ptr[0] != L'"' && ptr[0] != L'\0');
			len = ((mk_lang_types_sint_t)(((mk_lang_types_sintptr_t)(ptr - arg))));
			if(ptr[0] == L'"')
			{
				++ptr;
			}
		}
		else
		{
			arg = ptr;
			do
			{
				++ptr;
			}while(ptr[0] != L' ' && ptr[0] != L'\0');
			len = ((mk_lang_types_sint_t)(((mk_lang_types_sintptr_t)(ptr - arg))));
		}
		if(len == 0)
		{
			continue;
		}
		argv[curr_argc] = arg;
		lens[curr_argc] = len;
		++curr_argc;
		if(curr_argc == count)
		{
			break;
		}
	}
	n = curr_argc;
	for(i = 0; i != n; ++i)
	{
		((mk_lang_types_wchar_pt)(argv[i]))[lens[i]] = L'\0';
	}
	*argc = curr_argc;
	return 0;
}


#endif
