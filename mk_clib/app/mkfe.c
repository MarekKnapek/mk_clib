#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#pragma warning(disable:5045) /* C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified */
#endif
#include "../src/mk_clib_app_file_explorer.h"
#include "../src/mk_lang_cpp.h"
#include "../src/mk_lang_noexcept.h"
#include "../src/mk_lang_sizet.h"
#include "../src/mk_win_base.h"
#include "../src/mk_win_winmain.h"
#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(pop)
#endif


int mk_win_base_stdcall mk_win_winmain(mk_win_base_instance_t const instance, mk_win_base_instance_t const previous, mk_win_tstring_tchar_lpct const cmd, int const show) mk_lang_noexcept
{
	return mk_clib_app_file_explorer_winmain(instance, previous, cmd, show);
}

mk_lang_extern_c int LLVMFuzzerTestOneInput(unsigned char const* const data, mk_lang_size_t const size)
{
	((void)(data));
	((void)(size));
	return 0;
}
