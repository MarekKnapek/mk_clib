#include "mk_lang_crash.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_null.h"
#include "mk_lang_noexcept.h"

#if mk_lang_crash_detail_impl
#include "mk_win_base.h"
struct mk_win_user_window_handle_s; typedef struct mk_win_user_window_handle_s mk_win_user_window_handle_t; typedef mk_win_user_window_handle_t const* mk_win_user_window_t;
mk_win_base_dll_import int mk_win_base_stdcall MessageBoxA(mk_win_user_window_t, mk_win_base_pchar_lpct, mk_win_base_pchar_lpct, mk_win_base_uint_t) mk_lang_noexcept;
#else
#endif

#include <stdlib.h> /* abort */


#if mk_lang_crash_detail_impl
mk_lang_noreturn mk_lang_jumbo void mk_lang_crash_impl(char const* const file, int const line, char const* const line_str) mk_lang_noexcept
#else
mk_lang_noreturn mk_lang_jumbo void mk_lang_crash(void) mk_lang_noexcept
#endif
{
	int volatile* volatile ptr;

	#if mk_lang_crash_detail_impl
	((void)(MessageBoxA(mk_win_base_null, file, "crash", 0)));
	((void)(MessageBoxA(mk_win_base_null, line_str, "crash", 0)));
	#else
	#endif

	ptr = mk_lang_null;
	#if mk_lang_crash_detail_impl
	*ptr = file[line];
	#else
	*ptr = 0;
	#endif

	#if defined _MSC_VER >= 1200 /* todo version */
	__debugbreak();
	#endif

	#if defined __has_builtin
	#if __has_builtin(__builtin_debugtrap)
	__builtin_debugtrap();
	#endif
	#endif

	#if defined __has_builtin
	#if __has_builtin(__builtin_trap)
	__builtin_trap();
	#endif
	#endif

	abort();
}
