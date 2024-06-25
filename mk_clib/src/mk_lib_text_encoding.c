#include "mk_lib_text_encoding.h"

#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_lib_text_encoding_portable.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows
#include "mk_lib_text_encoding_windows.h"
#endif


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_text_encoding_wide_to_utf8(mk_lang_types_wchar_pct const wide_str, mk_lang_types_sint_t const wide_len, mk_lang_types_pchar_pt const utf8_str, mk_lang_types_sint_t const utf8_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lib_text_encoding_windows_wide_to_utf8(wide_str, wide_len, utf8_str, utf8_len, out_len);
	}
	else
	#endif
	{
		return mk_lib_text_encoding_portable_wide_to_utf8(wide_str, wide_len, utf8_str, utf8_len, out_len);
	}
}
