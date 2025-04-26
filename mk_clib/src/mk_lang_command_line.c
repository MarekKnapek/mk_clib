#ifndef mk_include_guard_mk_lang_command_line_c
#define mk_include_guard_mk_lang_command_line_c
#include "mk_lang_command_line.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_command_line_parse(mk_lang_types_wchar_pct const cmdline, mk_lang_types_wchar_ppct const argv, mk_lang_types_sint_pt const lens, mk_lang_types_sint_t const count, mk_lang_types_sint_pt const argc) mk_lang_noexcept
{
	mk_lang_types_sint_t curr_argc;
	mk_lang_types_wchar_pct ptr;
	mk_lang_types_wchar_pct arg;
	mk_lang_types_sint_t len;

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
	*argc = curr_argc;
	return 0;
}


#endif
