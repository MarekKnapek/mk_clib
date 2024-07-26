#include "mk_lib_statistics.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_platform.h"


#if !defined mk_lib_statistics_mallocatorg_want
#define mk_lib_statistics_mallocatorg_want 11
#endif


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows_51 || mk_lang_platform == mk_lang_platform_windows
#define mk_lib_statistics_windows_mallocatorg_want mk_lib_statistics_mallocatorg_want
#include "mk_lib_statistics_windows.h"
#define mk_lib_statistics_impl_init       mk_lib_statistics_windows_init
#define mk_lib_statistics_impl_deinit     mk_lib_statistics_windows_deinit
#define mk_lib_statistics_impl_show       mk_lib_statistics_windows_show
#define mk_lib_statistics_impl_hide       mk_lib_statistics_windows_hide
#define mk_lib_statistics_impl_invalidate mk_lib_statistics_windows_invalidate
#define mk_lib_statistics_impl_pump       mk_lib_statistics_windows_pump
#elif mk_lang_platform_x11_have == 1
#define mk_lib_statistics_x11_mallocatorg_want mk_lib_statistics_mallocatorg_want
#include "mk_lib_statistics_x11.h"
#define mk_lib_statistics_impl_init       mk_lib_statistics_x11_init
#define mk_lib_statistics_impl_deinit     mk_lib_statistics_x11_deinit
#define mk_lib_statistics_impl_show       mk_lib_statistics_x11_show
#define mk_lib_statistics_impl_hide       mk_lib_statistics_x11_hide
#define mk_lib_statistics_impl_invalidate mk_lib_statistics_x11_invalidate
#define mk_lib_statistics_impl_pump       mk_lib_statistics_x11_pump
#else
#error todo xxxxxxxxxx
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_statistics_impl_init();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_statistics_impl_deinit();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_show(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_statistics_impl_show();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_hide(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_statistics_impl_hide();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_invalidate(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_statistics_impl_invalidate();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_pump(mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	return mk_lib_statistics_impl_pump(at_least_one);
}
