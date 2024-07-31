#include "mk_win_comctl_dynamic.h"

#include "mk_lang_bool.h"
#include "mk_lang_arch.h"
#include "mk_lang_bitness.h"
#include "mk_lang_check.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_inline.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


#if defined _MSC_VER && defined _MSC_FULL_VER
#define mk_win_comctl_dynamic_has_resource 1
#elif defined __TINYC__
#define mk_win_comctl_dynamic_has_resource 0
#else
#error todo xxxxxxxxxx
#endif


mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall InitCommonControls(mk_lang_types_void_t) mk_lang_noexcept;


#if mk_win_comctl_dynamic_has_resource == 0


mk_lang_constexpr_static_inline mk_lang_types_uchar_t s_mk_win_comctl_dynamic_manifest[] =
"
#if mk_lang_arch == mk_lang_arch_x8632
#include "mk_win_comctl_manifest_i386.xml"
#elif mk_lang_arch == mk_lang_arch_x8664
#include "mk_win_comctl_manifest_amd64.xml"
#else
#error todo xxxxxxxxxx
#endif
";


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_win_comctl_dynamic_init_from_memory(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}


#endif


mk_lang_jumbo mk_lang_types_void_t mk_win_comctl_dynamic_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#if mk_win_comctl_dynamic_has_resource == 1
	/* todo */
	#elif mk_win_comctl_dynamic_has_resource == 0
	err = mk_win_comctl_dynamic_init_from_memory(); ((mk_lang_types_void_t)(err));
	#else
	#error xxxxxxxxxx
	#endif
}
