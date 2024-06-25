#include "mk_lib_text_encoding_windows.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_string.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_text_encoding_windows_wide_to_utf8(mk_lang_types_wchar_pct const wide_str, mk_lang_types_sint_t const wide_len, mk_lang_types_pchar_pt const utf8_str, mk_lang_types_sint_t const utf8_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_sint_t r;

	mk_lang_assert(out_len);

	r = mk_win_kernel_string_wide_to_ansi(((mk_win_base_uint_t)(mk_win_kernel_string_cp_id_e_utf8)), 0, wide_str, wide_len, utf8_str, utf8_len, mk_win_base_null, mk_win_base_null);
	*out_len = r;
	return 0;
}
