#ifndef mk_include_guard_mk_win_kernel_string
#define mk_include_guard_mk_win_kernel_string


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


enum mk_win_kernel_string_cp_id_e
{
	mk_win_kernel_string_cp_id_e_acp        =     0,
	mk_win_kernel_string_cp_id_e_oemcp      =     1,
	mk_win_kernel_string_cp_id_e_maccp      =     2,
	mk_win_kernel_string_cp_id_e_thread_acp =     3,
	mk_win_kernel_string_cp_id_e_symbol     =    42,
	mk_win_kernel_string_cp_id_e_utf7       = 65000,
	mk_win_kernel_string_cp_id_e_utf8       = 65001,
	mk_win_kernel_string_cp_id_e_dummy_end
};
typedef enum mk_win_kernel_string_cp_id_e mk_win_kernel_string_cp_id_t;

enum mk_win_kernel_string_flags_wc_e
{
	mk_win_kernel_string_flags_wc_e_discardns         = 0x00000010ul,
	mk_win_kernel_string_flags_wc_e_sepchars          = 0x00000020ul,
	mk_win_kernel_string_flags_wc_e_defaultchar       = 0x00000040ul,
	mk_win_kernel_string_flags_wc_e_err_invalid_chars = 0x00000080ul, /* WINVER >= 0x0600 */
	mk_win_kernel_string_flags_wc_e_compositecheck    = 0x00000200ul,
	mk_win_kernel_string_flags_wc_e_no_best_fit_chars = 0x00000400ul, /* WINVER >= 0x0500 */
	mk_win_kernel_string_flags_wc_e_dummy_end
};
typedef enum mk_win_kernel_string_flags_wc_e mk_win_kernel_string_flags_wc_t;

enum mk_win_kernel_string_flags_an_e
{
	mk_win_kernel_string_flags_an_e_precomposed       = 0x00000001ul, /* deprecated */
	mk_win_kernel_string_flags_an_e_composite         = 0x00000002ul, /* deprecated */
	mk_win_kernel_string_flags_an_e_useglyphchars     = 0x00000004ul, /* deprecated */
	mk_win_kernel_string_flags_an_e_err_invalid_chars = 0x00000008ul,
	mk_win_kernel_string_flags_an_e_dummy_end
};
typedef enum mk_win_kernel_string_flags_an_e mk_win_kernel_string_flags_an_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_kernel_string_wide_to_ansi(mk_win_base_uint_t const cp, mk_win_base_dword_t const flags, mk_win_base_wchar_lpct const wide_buf, mk_win_base_sint_t const wide_len, mk_win_base_pchar_lpt const ansi_buf, mk_win_base_sint_t const ansi_len, mk_win_base_pchar_lpct const def_char, mk_win_base_bool_lpt const def_used) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_kernel_string_ansi_to_wide(mk_win_base_uint_t const cp, mk_win_base_dword_t const flags, mk_win_base_pchar_lpct const ansi_buf, mk_win_base_sint_t const ansi_len, mk_win_base_wchar_lpt const wide_buf, mk_win_base_sint_t const wide_len) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_string.c"
#endif
#endif
