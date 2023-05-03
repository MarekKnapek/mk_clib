#include "../src/mk_clib_app_simple_window.h"
#include "../src/mk_lang_cpp.h"
#include "../src/mk_lang_noexcept.h"
#include "../src/mk_lang_sizet.h"
#include "../src/mk_win_base.h"
#include "../src/mk_win_winmain.h"


int mk_win_base_stdcall mk_win_winmain(mk_win_base_instance_t const instance, mk_win_base_instance_t const previous, mk_win_tstring_tchar_lpct const cmd, int const show) mk_lang_noexcept
{
	return mk_clib_app_simple_window_winmain(instance, previous, cmd, show);
}

mk_lang_extern_c int LLVMFuzzerTestOneInput(unsigned char const* data, mk_lang_size_t size)
{
	((void)(data));
	((void)(size));
	return 0;
}
