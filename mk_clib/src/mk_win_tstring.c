#if defined _MSC_VER && _MSC_VER == 1936
#pragma warning(push)
#pragma warning(disable:4365)
#endif


#include "mk_win_tstring.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_clobber.h"
#include "mk_lang_cpp.h"
#include "mk_lang_crash.h"
#include "mk_lang_exception.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_win_base.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_mallocator_main_heap.h"
#include "mk_win_unicode_api.h"


enum mk_win_tstring_cp_e
{
	mk_win_tstring_cp_e_acp        =     0ul,
	mk_win_tstring_cp_e_oemcp      =     1ul,
	mk_win_tstring_cp_e_maccp      =     2ul,
	mk_win_tstring_cp_e_thread_acp =     3ul,
	mk_win_tstring_cp_e_symbol     =    42ul,
	mk_win_tstring_cp_e_utf7       = 65000ul,
	mk_win_tstring_cp_e_utf8       = 65001ul,
	mk_win_tstring_cp_e_dummy_end = 0
};
typedef enum mk_win_tstring_cp_e mk_win_tstring_cp_t;

enum mk_win_tstring_flags_mb_e
{
	mk_win_tstring_flags_mb_e_none              = 0x00000000ul,
	mk_win_tstring_flags_mb_e_precomposed       = 0x00000001ul,
	mk_win_tstring_flags_mb_e_composite         = 0x00000002ul,
	mk_win_tstring_flags_mb_e_useglyphchars     = 0x00000004ul,
	mk_win_tstring_flags_mb_e_err_invalid_chars = 0x00000008ul,
	mk_win_tstring_flags_mb_e_dummy_end = 0
};
typedef enum mk_win_tstring_flags_mb_e mk_win_tstring_flags_mb_t;

enum mk_win_tstring_flags_wc_e
{
	mk_win_tstring_flags_wc_e_none              = 0x00000000ul,
	mk_win_tstring_flags_wc_e_discardns         = 0x00000010ul,
	mk_win_tstring_flags_wc_e_sepchars          = 0x00000020ul,
	mk_win_tstring_flags_wc_e_defaultchar       = 0x00000040ul,
	mk_win_tstring_flags_wc_e_err_invalid_chars = 0x00000080ul,
	mk_win_tstring_flags_wc_e_compositecheck    = 0x00000200ul,
	mk_win_tstring_flags_wc_e_no_best_fit_chars = 0x00000400ul,
	mk_win_tstring_flags_wc_e_dummy_end = 0
};
typedef enum mk_win_tstring_flags_wc_e mk_win_tstring_flags_wc_t;


mk_lang_extern_c mk_win_base_dll_import int mk_win_base_stdcall MultiByteToWideChar(mk_win_base_uint_t, mk_win_base_dword_t, mk_win_base_pchar_lpct, int, mk_win_base_wchar_lpt, int) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import int mk_win_base_stdcall WideCharToMultiByte(mk_win_base_uint_t, mk_win_base_dword_t, mk_win_base_wchar_lpct, int, mk_win_base_pchar_lpt, int, mk_win_base_pchar_lpct, mk_win_base_bool_lpt) mk_lang_noexcept;


#if defined _MSC_VER && _MSC_VER == 1936
#pragma warning(push)
#pragma warning(disable:4132) /* warning C4132: 'xxx': const object should be initialized */
#endif
#define s_mk_win_tstring_mws_elements 16
static mk_win_base_pchar_t const s_mk_win_tstring_null_pchar = mk_win_base_null;
static mk_win_base_wchar_t const s_mk_win_tstring_null_wchar = mk_win_base_null;
#if defined _MSC_VER && _MSC_VER == 1936
#pragma warning(pop)
#endif


static mk_win_tstring_mem_with_size_t g_mk_win_tstring_mems_with_sizes[s_mk_win_tstring_mws_elements];
static unsigned int g_mk_win_tstring_mems_with_sizes_idx;


mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_ansi_to_wide(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_mb_t const flags, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_wchar_lpt const wide, int const wide_len_elements) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_wide_to_ansi(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_wc_t const flags, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const ansi, int const ansi_len_elements, mk_win_base_pchar_lpct const default_char, mk_win_base_bool_lpt const used_default_char) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_mem_with_size_pt mk_win_tstring_get_next_mws(void) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_resize_mws(mk_lang_exception_pt const ex, mk_win_tstring_mem_with_size_pt const mws, int const size_bytes) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_win_tstring_validate_asci(mk_win_base_pchar_lpct const asci) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_win_tstring_validate_utf8(mk_win_base_pchar_lpct const utf8) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_win_tstring_validate_wide(mk_win_base_wchar_lpct const wide) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_ansi_to_wide_fallback(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_mb_t const flags, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_wchar_lpt const wide, int const wide_len_elements) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_wide_to_ansi_fallback(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_wc_t const flags, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const ansi, int const ansi_len_elements, mk_win_base_pchar_lpct const default_char, mk_win_base_bool_lpt const used_default_char) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_mb_t const flags, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_wchar_lpt const wide, int const wide_len_elements) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_wc_t const flags, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const ansi, int const ansi_len_elements, mk_win_base_pchar_lpct const default_char, mk_win_base_bool_lpt const used_default_char) mk_lang_noexcept;

mk_lang_jumbo void mk_win_tstring_asci_to_ansi_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, int const asci_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_utf8_to_ansi_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, int const utf8_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_ansi_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_asci_to_wide_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, int const asci_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_wide_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_utf8_to_wide_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, int const utf8_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_asci_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_asci_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_utf8_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept;

mk_lang_jumbo void mk_win_tstring_asci_to_ansi_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, int const asci_len_elements, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_utf8_to_ansi_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, int const utf8_len_elements, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_ansi_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_asci_to_wide_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, int const asci_len_elements, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_wide_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_utf8_to_wide_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, int const utf8_len_elements, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_asci_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_asci_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_utf8_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept;

mk_lang_jumbo void mk_win_tstring_asci_to_ansi_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_utf8_to_ansi_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_ansi_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_asci_to_wide_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_wide_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_utf8_to_wide_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_asci_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_asci_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_utf8_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_asci_to_utf8_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept;

mk_lang_jumbo void mk_win_tstring_asci_to_ansi_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_utf8_to_ansi_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_ansi_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_asci_to_wide_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_wide_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_utf8_to_wide_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_asci_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_asci_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_utf8_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_asci_to_utf8_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept;

mk_lang_jumbo void mk_win_tstring_ansi_to_asci_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_pchar_lpt const asci, int const asci_len_elements, mk_win_tstring_pstr_with_size_pt const asci_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_pchar_lpt const utf8, int const utf8_len_elements, mk_win_tstring_pstr_with_size_pt const utf8_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_wide_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_wchar_lpt const wide, int const wide_len_elements, mk_win_tstring_wstr_with_size_pt const wide_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_asci_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const asci, int const asci_len_elements, mk_win_tstring_pstr_with_size_pt const asci_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_ansi_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const ansi, int const ansi_len_elements, mk_win_tstring_pstr_with_size_pt const ansi_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_utf8_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const utf8, int const utf8_len_elements, mk_win_tstring_pstr_with_size_pt const utf8_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_asci_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_base_pchar_lpt const asci, int const asci_len_elements, mk_win_tstring_pstr_with_size_pt const asci_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_base_pchar_lpt const utf8, int const utf8_len_elements, mk_win_tstring_pstr_with_size_pt const utf8_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_wide_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_base_wchar_lpt const wide, int const wide_len_elements, mk_win_tstring_wstr_with_size_pt const wide_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_asci_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_base_pchar_lpt const asci, int const asci_len_elements, mk_win_tstring_pstr_with_size_pt const asci_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_ansi_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_base_pchar_lpt const ansi, int const ansi_len_elements, mk_win_tstring_pstr_with_size_pt const ansi_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_utf8_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_base_pchar_lpt const utf8, int const utf8_len_elements, mk_win_tstring_pstr_with_size_pt const utf8_out) mk_lang_noexcept;

mk_lang_jumbo void mk_win_tstring_ansi_to_tstr_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements, mk_win_tstring_tstr_with_size_pt const tstr_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_tstr_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements, mk_win_tstring_tstr_with_size_pt const tstr_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_tstr_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements, mk_win_tstring_tstr_with_size_pt const tstr_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_tstr_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements, mk_win_tstring_tstr_with_size_pt const tstr_out) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_tstr_to_ansi_sz_nmws(mk_lang_exception_pt const ex, mk_win_tstring_tchar_lpct const tstr, int const tstr_len_elements, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_tstr_to_wide_sz_nmws(mk_lang_exception_pt const ex, mk_win_tstring_tchar_lpct const tstr, int const tstr_len_elements, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_tstr_to_ansi_zt_nmws(mk_lang_exception_pt const ex, mk_win_tstring_tchar_lpct const tstr, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_tstr_to_wide_zt_nmws(mk_lang_exception_pt const ex, mk_win_tstring_tchar_lpct const tstr, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_asci_to_tstr_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_tstr_with_size_pt const tstr) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_ansi_to_tstr_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_tstr_with_size_pt const tstr) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_wide_to_tstr_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_tstr_with_size_pt const tstr) mk_lang_noexcept;

mk_lang_jumbo void mk_win_tstring_allocate_ansi_ex(mk_lang_exception_pt const ex, int const ansi_len_elements, mk_win_base_pchar_lpt* const ansi) mk_lang_noexcept;
mk_lang_jumbo void mk_win_tstring_allocate_wide_ex(mk_lang_exception_pt const ex, int const wide_len_elements, mk_win_base_wchar_lpt* const wide) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_ansi_to_wide(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_mb_t const flags, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_wchar_lpt const wide, int const wide_len_elements) mk_lang_noexcept
{
	int converted;

	converted = MultiByteToWideChar(((mk_win_base_uint_t)(cp)), ((mk_win_base_dword_t)(flags)), ansi, ansi_len_elements, wide, wide_len_elements);
	return converted;
}

mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_wide_to_ansi(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_wc_t const flags, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const ansi, int const ansi_len_elements, mk_win_base_pchar_lpct const default_char, mk_win_base_bool_lpt const used_default_char) mk_lang_noexcept
{
	int converted;

	converted = WideCharToMultiByte(((mk_win_base_uint_t)(cp)), ((mk_win_base_dword_t)(flags)), wide, wide_len_elements, ansi, ansi_len_elements, default_char, used_default_char);
	return converted;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_mem_with_size_pt mk_win_tstring_get_next_mws(void) mk_lang_noexcept
{
	mk_win_tstring_mem_with_size_pt mws;

	mws = &g_mk_win_tstring_mems_with_sizes[g_mk_win_tstring_mems_with_sizes_idx];
	g_mk_win_tstring_mems_with_sizes_idx = (g_mk_win_tstring_mems_with_sizes_idx + 1) & (s_mk_win_tstring_mws_elements - 1);
	return mws;
}

mk_lang_jumbo void mk_win_tstring_resize_mws(mk_lang_exception_pt const ex, mk_win_tstring_mem_with_size_pt const mws, int const size_bytes) mk_lang_noexcept
{
	mk_win_base_void_lpt new_mem;

	mk_lang_assert(ex);
	mk_lang_assert(mws);
	mk_lang_assert(size_bytes > 0);

	if(!mws->m_mem)
	{
		mk_lang_assert(mws->m_size_bytes == 0);
		mk_win_mallocator_main_heap_allocate(ex, size_bytes, &new_mem);
		mk_lang_exception_if_is_return(ex);
		mk_lang_assert(new_mem);
		mws->m_mem = new_mem;
		mws->m_size_bytes = size_bytes;
	}
	else if(size_bytes > mws->m_size_bytes)
	{
		mk_win_mallocator_main_heap_reallocate(ex, mws->m_mem, mws->m_size_bytes, size_bytes, &new_mem);
		mk_lang_exception_if_is_return(ex);
		mk_lang_assert(new_mem);
		mws->m_mem = new_mem;
		mws->m_size_bytes = size_bytes;
	}
}

#if defined _MSC_VER && _MSC_VER == 1936
#pragma warning(push)
#pragma warning(disable:4706) /* warning C4706: assignment within conditional expression */
#endif
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_win_tstring_validate_asci(mk_win_base_pchar_lpct const asci) mk_lang_noexcept
{

	mk_win_base_uchar_lpct ptr;
	mk_win_base_uchar_t e;

	if(asci)
	{
		for(ptr = ((mk_win_base_uchar_lpct)(asci)); e = *ptr; ++ptr)
		{
			if(!(e >= 0x20 && e <= 0x7e)) return mk_lang_false;
		}
	}
	return mk_lang_true;
}
#if defined _MSC_VER && _MSC_VER == 1936
#pragma warning(pop)
#endif

#if defined _MSC_VER && _MSC_VER == 1936
#pragma warning(push)
#pragma warning(disable:4706) /* warning C4706: assignment within conditional expression */
#endif
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_win_tstring_validate_utf8(mk_win_base_pchar_lpct const utf8) mk_lang_noexcept
{
	int expecting;
	int len;
	mk_win_base_uchar_lpct ptr;
	mk_win_base_uchar_t e;
	mk_win_base_uchar_t prev[3];
	mk_win_base_ulong_t u;

	if(utf8)
	{
		expecting = 0;
		len = 0;
		for(ptr = ((mk_win_base_uchar_lpct)(utf8)); e = *ptr; ++ptr)
		{
			if(((e & 0x80) == 0x00) && (expecting == 0))
			{
			}
			else if(((e & 0xe0) == 0xc0) && (expecting == 0))
			{
				expecting = 1;
				len = 2;
				prev[0] = e & 0x1f;
				prev[1] = 0x00;
				prev[2] = 0x00;
			}
			else if(((e & 0xf0) == 0xe0) && (expecting == 0))
			{
				expecting = 2;
				len = 3;
				prev[1] = e & 0x0f;
				prev[2] = 0x00;
			}
			else if(((e & 0xf8) == 0xf0) && (expecting == 0))
			{
				expecting = 3;
				len = 4;
				prev[2] = e & 0x07;
			}
			else if(((e & 0xc0) == 0x80) && (expecting != 0))
			{
				--expecting;
				if(expecting == 0)
				{
					u =
					((mk_win_base_ulong_t)
					(
						((mk_win_base_ulong_t)(((mk_win_base_ulong_t)(prev[2])) << 18)) |
						((mk_win_base_ulong_t)(((mk_win_base_ulong_t)(prev[1])) << 12)) |
						((mk_win_base_ulong_t)(((mk_win_base_ulong_t)(prev[0])) << 6)) |
						((mk_win_base_ulong_t)(e & 0x3f))
					));
					if(!
					(
						((len == 2) && (u >= 0x00000080ul && u <= 0x00007ffful)) ||
						((len == 3) && (u >= 0x00000800ul && u <= 0x0000fffful)) ||
						((len == 4) && (u >= 0x00010000ul && u <= 0x0010fffful))
					))
					{
						return mk_lang_false;
					}
				}
				else
				{
					prev[expecting - 1] = e & 0x3f;
				}
			}
			else
			{
				return mk_lang_false;
			}
		}
		if(expecting != 0)
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
}
#if defined _MSC_VER && _MSC_VER == 1936
#pragma warning(pop)
#endif

#if defined _MSC_VER && _MSC_VER == 1936
#pragma warning(push)
#pragma warning(disable:4706) /* warning C4706: assignment within conditional expression */
#endif
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_win_tstring_validate_wide(mk_win_base_wchar_lpct const wide) mk_lang_noexcept
{
	int expecting;
	mk_win_base_ushort_t prev;
	mk_win_base_ushort_lpct ptr;
	mk_win_base_ushort_t e;
	mk_win_base_ulong_t u;

	if(wide)
	{
		expecting = 0;
		mk_lang_clobber(&prev);
		for(ptr = ((mk_win_base_ushort_lpct)(wide)); e = *ptr; ++ptr)
		{
			if(((e >= 0x0000 && e <= 0xd7ff) || (e >= 0xe000 && e <= 0xffff)) && (expecting == 0))
			{
			}
			else if(((e & 0xfc00) == 0xd800) && (expecting == 0))
			{
				prev = e;
				expecting = 1;
			}
			else if(((e & 0xfc00) == 0xdc00) && (expecting == 1))
			{
				u =
				((mk_win_base_ulong_t)
				(
					((mk_win_base_ulong_t)(((mk_win_base_ulong_t)(prev & 0x03ff)) << 10)) |
					((mk_win_base_ulong_t)(e & 0x03ff))
				));
				if(!(u >= 0x00010000ul && u <= 0x0010fffful))
				{
					return mk_lang_false;
				}
				expecting = 0;
			}
			else
			{
				return mk_lang_false;
			}
		}
		if(expecting != 0)
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
}
#if defined _MSC_VER && _MSC_VER == 1936
#pragma warning(pop)
#endif

mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_ansi_to_wide_fallback(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_mb_t const flags, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_wchar_lpt const wide, int const wide_len_elements) mk_lang_noexcept
{
	int ret_wide_len;
	mk_win_base_wchar_lpt wide_ptr;
	int expecting;
	int len;
	mk_win_base_uchar_lpct ptr;
	mk_win_base_uchar_t e;
	mk_win_base_uchar_t prev[3];
	mk_win_base_ulong_t u;

	mk_lang_assert(cp == mk_win_tstring_cp_e_utf8);
	mk_lang_assert(flags == mk_win_tstring_flags_mb_e_none);
	mk_lang_assert(ansi);
	mk_lang_assert(ansi_len_elements >= 1 || ansi_len_elements == -1);
	mk_lang_assert((wide && wide_len_elements >= 1) || (!wide && wide_len_elements == 0));
	/* todo wide len is enough */
	mk_lang_assert(mk_win_tstring_validate_utf8(ansi));

	ret_wide_len = 0;
	wide_ptr = wide;
	expecting = 0;
	len = 0;
	for(ptr = ((mk_win_base_uchar_lpct)(ansi)); (ansi_len_elements != -1 && ((mk_win_base_pchar_lpct)(ptr)) - ansi != ansi_len_elements) || (ansi_len_elements == -1 && *ptr); ++ptr)
	{
		e = *ptr;
		if(((e & 0x80) == 0x00) && (expecting == 0))
		{
			u = ((mk_win_base_ulong_t)(e));
			if(wide_len_elements != 0)
			{
				if(ret_wide_len == wide_len_elements)
				{
					/* error_insufficient_buffer */
					return 0;
				}
				wide_ptr[ret_wide_len] = ((mk_win_base_wchar_t)(u));
			}
			++ret_wide_len;
		}
		else if(((e & 0xe0) == 0xc0) && (expecting == 0))
		{
			expecting = 1;
			len = 2;
			prev[0] = e & 0x1f;
			prev[1] = 0x00;
			prev[2] = 0x00;
		}
		else if(((e & 0xf0) == 0xe0) && (expecting == 0))
		{
			expecting = 2;
			len = 3;
			prev[1] = e & 0x0f;
			prev[2] = 0x00;
		}
		else if(((e & 0xf8) == 0xf0) && (expecting == 0))
		{
			expecting = 3;
			len = 4;
			prev[2] = e & 0x07;
		}
		else if(((e & 0xc0) == 0x80) && (expecting != 0))
		{
			--expecting;
			if(expecting == 0)
			{
				u =
				((mk_win_base_ulong_t)
				(
					((mk_win_base_ulong_t)(((mk_win_base_ulong_t)(prev[2])) << 18)) |
					((mk_win_base_ulong_t)(((mk_win_base_ulong_t)(prev[1])) << 12)) |
					((mk_win_base_ulong_t)(((mk_win_base_ulong_t)(prev[0])) << 6)) |
					((mk_win_base_ulong_t)(e & 0x3f))
				));
				mk_lang_assert
				(
					((len == 2) && (u >= 0x00000080ul && u <= 0x00007ffful)) ||
					((len == 3) && (u >= 0x00000800ul && u <= 0x0000fffful)) ||
					((len == 4) && (u >= 0x00010000ul && u <= 0x0010fffful))
				);
				if(!(u >= 0x00010000ul && u <= 0x0010fffful))
				{
					if(wide_len_elements != 0)
					{
						if(ret_wide_len == wide_len_elements)
						{
							/* error_insufficient_buffer */
							return 0;
						}
						wide_ptr[ret_wide_len] = ((mk_win_base_wchar_t)(u));
					}
					++ret_wide_len;
				}
				else
				{
					if(wide_len_elements != 0)
					{
						if((ret_wide_len == wide_len_elements) || ((ret_wide_len + 1) == wide_len_elements))
						{
							/* error_insufficient_buffer */
							return 0;
						}
						wide_ptr[ret_wide_len + 0] = ((mk_win_base_wchar_t)(((mk_win_base_wchar_t)(0xd800)) | ((mk_win_base_wchar_t)(u >> 10))));
						wide_ptr[ret_wide_len + 1] = ((mk_win_base_wchar_t)(((mk_win_base_wchar_t)(0xdc00)) | ((mk_win_base_wchar_t)(u & 0x03ff))));
					}
					ret_wide_len += 2;
				}
			}
			else
			{
				prev[expecting - 1] = e & 0x3f;
			}
		}
		else
		{
			mk_lang_assert(0);
		}
	}
	mk_lang_assert(expecting == 0);
	if(ansi_len_elements == -1)
	{
		if(wide_len_elements != 0)
		{
			if(ret_wide_len == wide_len_elements)
			{
				/* error_insufficient_buffer */
				return 0;
			}
			wide_ptr[ret_wide_len] = ((mk_win_base_wchar_t)(0));
		}
		++ret_wide_len;
	}
	return ret_wide_len;
}

mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_wide_to_ansi_fallback(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_wc_t const flags, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const ansi, int const ansi_len_elements, mk_win_base_pchar_lpct const default_char, mk_win_base_bool_lpt const used_default_char) mk_lang_noexcept
{
	int ret_ansi_len;
	mk_win_base_pchar_lpt ansi_ptr;
	int expecting;
	mk_win_base_ulong_t u;
	mk_win_base_ushort_t prev;
	mk_win_base_ushort_lpct ptr;
	mk_win_base_ushort_t e;

	mk_lang_assert(cp == mk_win_tstring_cp_e_utf8);
	mk_lang_assert(flags == mk_win_tstring_flags_wc_e_none);
	mk_lang_assert(wide);
	mk_lang_assert(wide_len_elements >= 1 || wide_len_elements == -1);
	mk_lang_assert((ansi && ansi_len_elements >= 1) || (!ansi && ansi_len_elements == 0));
	mk_lang_assert(!default_char);
	mk_lang_assert(!used_default_char);
	/* todo ansi len is enough */
	mk_lang_assert(mk_win_tstring_validate_wide(wide));

	ret_ansi_len = 0;
	ansi_ptr = ansi;
	expecting = 0;
	mk_lang_clobber(&u);
	mk_lang_clobber(&prev);
	for(ptr = ((mk_win_base_ushort_lpct)(wide)); (wide_len_elements != -1 && ((mk_win_base_wchar_lpct)(ptr)) - wide != wide_len_elements) || (wide_len_elements == -1 && *ptr); ++ptr)
	{
		e = *ptr;
		if(((e >= 0x0000 && e <= 0xd7ff) || (e >= 0xe000 && e <= 0xffff)) && (expecting == 0))
		{
			u = ((mk_win_base_ulong_t)(e));
		}
		else if(((e & 0xfc00) == 0xd800) && (expecting == 0))
		{
			prev = e;
			expecting = 1;
		}
		else if(((e & 0xfc00) == 0xdc00) && (expecting == 1))
		{
			u =
			((mk_win_base_ulong_t)
			(
				((mk_win_base_ulong_t)(((mk_win_base_ulong_t)(prev & 0x03ff)) << 10)) |
				((mk_win_base_ulong_t)(e & 0x03ff))
			));
			mk_lang_assert(u >= 0x00010000ul && u <= 0x0010fffful);
			expecting = 0;
		}
		else
		{
			mk_lang_assert(0);
		}
		if(expecting == 0)
		{
			if(/*u >= 0x00000000ul && */u <= 0x0000007ful)
			{
				if(ansi_len_elements != 0)
				{
					if(ret_ansi_len == ansi_len_elements)
					{
						/* error_insufficient_buffer */
						return 0;
					}
					ansi_ptr[ret_ansi_len] = ((mk_win_base_pchar_t)(u));
				}
				++ret_ansi_len;
			}
			else if(u >= 0x00000080ul && u <= 0x000007fful)
			{
				if(ansi_len_elements != 0)
				{
					if((ret_ansi_len == ansi_len_elements) || ((ret_ansi_len + 1) == ansi_len_elements))
					{
						/* error_insufficient_buffer */
						return 0;
					}
					ansi_ptr[ret_ansi_len + 0] = ((mk_win_base_pchar_t)(((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(0xc0)) | ((mk_win_base_uchar_t)(u >> 6))))));
					ansi_ptr[ret_ansi_len + 1] = ((mk_win_base_pchar_t)(((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(0x80)) | ((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(u)) & ((mk_win_base_uchar_t)(0x3f))))))));
				}
				ret_ansi_len += 2;
			}
			else if(u >= 0x00000800ul && u <= 0x0000fffful)
			{
				if(ansi_len_elements != 0)
				{
					if((ret_ansi_len == ansi_len_elements) || ((ret_ansi_len + 1) == ansi_len_elements) || ((ret_ansi_len + 2) == ansi_len_elements))
					{
						/* error_insufficient_buffer */
						return 0;
					}
					ansi_ptr[ret_ansi_len + 0] = ((mk_win_base_pchar_t)(((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(0xe0)) | ((mk_win_base_uchar_t)(u >> 12))))));
					ansi_ptr[ret_ansi_len + 1] = ((mk_win_base_pchar_t)(((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(0x80)) | ((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(u >> 6)) & ((mk_win_base_uchar_t)(0x3f))))))));
					ansi_ptr[ret_ansi_len + 2] = ((mk_win_base_pchar_t)(((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(0x80)) | ((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(u)) & ((mk_win_base_uchar_t)(0x3f))))))));
				}
				ret_ansi_len += 3;
			}
			else if(u >= 0x00010000ul && u <= 0x0010fffful)
			{
				if(ansi_len_elements != 0)
				{
					if((ret_ansi_len == ansi_len_elements) || ((ret_ansi_len + 1) == ansi_len_elements) || ((ret_ansi_len + 2) == ansi_len_elements) || ((ret_ansi_len + 3) == ansi_len_elements))
					{
						/* error_insufficient_buffer */
						return 0;
					}
					ansi_ptr[ret_ansi_len + 0] = ((mk_win_base_pchar_t)(((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(0xf0)) | ((mk_win_base_uchar_t)(u >> 18))))));
					ansi_ptr[ret_ansi_len + 1] = ((mk_win_base_pchar_t)(((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(0x80)) | ((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(u >> 12)) & ((mk_win_base_uchar_t)(0x3f))))))));
					ansi_ptr[ret_ansi_len + 2] = ((mk_win_base_pchar_t)(((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(0x80)) | ((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(u >> 6)) & ((mk_win_base_uchar_t)(0x3f))))))));
					ansi_ptr[ret_ansi_len + 3] = ((mk_win_base_pchar_t)(((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(0x80)) | ((mk_win_base_uchar_t)(((mk_win_base_uchar_t)(u)) & ((mk_win_base_uchar_t)(0x3f))))))));
				}
				ret_ansi_len += 4;
			}
			else
			{
				mk_lang_assert(0);
			}
		}
	}
	mk_lang_assert(expecting == 0);
	if(wide_len_elements == -1)
	{
		if(ansi_len_elements != 0)
		{
			if(ret_ansi_len == ansi_len_elements)
			{
				/* error_insufficient_buffer */
				return 0;
			}
			ansi_ptr[ret_ansi_len] = ((mk_win_base_pchar_t)(0));
		}
		++ret_ansi_len;
	}
	return ret_ansi_len;
}

mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_mb_t const flags, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_wchar_lpt const wide, int const wide_len_elements) mk_lang_noexcept
{
	int converted;

	converted = mk_win_tstring_ansi_to_wide(cp, flags, ansi, ansi_len_elements, wide, wide_len_elements);
	if(cp == mk_win_tstring_cp_e_utf8 && converted == 0 && mk_win_kernel_errors_get_last() == mk_win_kernel_errors_id_e_invalid_parameter)
	{
		converted = mk_win_tstring_ansi_to_wide_fallback(cp, flags, ansi, ansi_len_elements, wide, wide_len_elements);
	}
	return converted;
}

mk_lang_nodiscard mk_lang_jumbo int mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_t const cp, mk_win_tstring_flags_wc_t const flags, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const ansi, int const ansi_len_elements, mk_win_base_pchar_lpct const default_char, mk_win_base_bool_lpt const used_default_char) mk_lang_noexcept
{
	int converted;

	converted = mk_win_tstring_wide_to_ansi(cp, flags, wide, wide_len_elements, ansi, ansi_len_elements, default_char, used_default_char);
	if(cp == mk_win_tstring_cp_e_utf8 && converted == 0 && mk_win_kernel_errors_get_last() == mk_win_kernel_errors_id_e_invalid_parameter)
	{
		converted = mk_win_tstring_wide_to_ansi_fallback(cp, flags, wide, wide_len_elements, ansi, ansi_len_elements, default_char, used_default_char);
	}
	return converted;
}


mk_lang_jumbo void mk_win_tstring_asci_to_ansi_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, int const asci_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(asci));
	((void)(asci_len_elements));
	((void)(mws));
	((void)(ansi));
	/* todo */
}

mk_lang_jumbo void mk_win_tstring_utf8_to_ansi_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, int const utf8_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept
{
	mk_win_tstring_wstr_with_size_t wide;

	mk_lang_assert(ex);
	mk_lang_assert(mws);
	mk_lang_assert(ansi);

	mk_win_tstring_utf8_to_wide_sz_wmws(ex, utf8, utf8_len_elements, mws, &wide);
	mk_lang_exception_if_is_return(ex);
	mk_win_tstring_wide_to_ansi_sz_nmws(ex, wide.m_str, wide.m_length_elements, ansi);
}

mk_lang_jumbo void mk_win_tstring_wide_to_ansi_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept
{
	static mk_win_base_pchar_t const s_default = 'x';

	int converted1;
	int converted2;
	mk_win_base_bool_t defaulted;

	mk_lang_assert(ex);
	mk_lang_assert((wide || wide_len_elements == 0) && (!wide || *wide || wide_len_elements == 1));
	mk_lang_assert(wide_len_elements >= 0);
	mk_lang_assert(mws);
	mk_lang_assert(ansi);

	if(wide_len_elements == 0)
	{
		ansi->m_str = mk_win_base_null;
		ansi->m_length_elements = 0;
		return;
	}
	if(wide_len_elements == 1)
	{
		ansi->m_str = &s_mk_win_tstring_null_pchar;
		ansi->m_length_elements = 1;
		return;
	}
	converted1 = mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_wc_e_no_best_fit_chars, wide, wide_len_elements, mk_win_base_null, 0, mk_win_base_null, mk_win_base_null);
	mk_lang_assert(converted1 >= 2);
	mk_win_tstring_resize_mws(ex, mws, converted1 * sizeof(mk_win_base_pchar_t));
	mk_lang_exception_if_is_return(ex);
	converted2 = mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_wc_e_no_best_fit_chars, wide, wide_len_elements, ((mk_win_base_pchar_lpt)(mws->m_mem)), converted1, &s_default, &defaulted);
	mk_lang_assert(converted2 == converted1);
	((void)(defaulted));
	ansi->m_str = ((mk_win_base_pchar_lpct)(mws->m_mem));
	ansi->m_length_elements = converted1;
}

mk_lang_jumbo void mk_win_tstring_asci_to_wide_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, int const asci_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(asci));
	((void)(asci_len_elements));
	((void)(mws));
	((void)(wide));
	/* todo */
}

mk_lang_jumbo void mk_win_tstring_ansi_to_wide_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept
{
	int converted1;
	int converted2;

	mk_lang_assert(ex);
	mk_lang_assert((ansi || ansi_len_elements == 0) && (!ansi || *ansi || ansi_len_elements == 1));
	mk_lang_assert(ansi_len_elements >= 0);
	mk_lang_assert(mws);
	mk_lang_assert(wide);

	if(ansi_len_elements == 0)
	{
		wide->m_str = mk_win_base_null;
		wide->m_length_elements = 0;
		return;
	}
	if(ansi_len_elements == 1)
	{
		wide->m_str = &s_mk_win_tstring_null_wchar;
		wide->m_length_elements = 1;
		return;
	}
	converted1 = mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_mb_e_none, ansi, ansi_len_elements, mk_win_base_null, 0);
	mk_lang_assert(converted1 >= 1);
	mk_win_tstring_resize_mws(ex, mws, converted1 * sizeof(mk_win_base_wchar_t));
	mk_lang_exception_if_is_return(ex);
	converted2 = mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_mb_e_none, ansi, ansi_len_elements, ((mk_win_base_wchar_lpt)(mws->m_mem)), converted1);
	mk_lang_assert(converted2 == converted1);
	wide->m_str = ((mk_win_base_wchar_lpct)(mws->m_mem));
	wide->m_length_elements = converted1;
}

mk_lang_jumbo void mk_win_tstring_utf8_to_wide_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, int const utf8_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept
{
	int converted1;
	int converted2;

	mk_lang_assert(ex);
	mk_lang_assert(mws);
	mk_lang_assert(wide);

	converted1 = mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_e_utf8, mk_win_tstring_flags_mb_e_none, utf8, utf8_len_elements, mk_win_base_null, 0);
	mk_lang_assert(converted1 >= 1);
	mk_win_tstring_resize_mws(ex, mws, converted1 * sizeof(mk_win_base_wchar_t));
	mk_lang_exception_if_is_return(ex);
	converted2 = mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_e_utf8, mk_win_tstring_flags_mb_e_none, utf8, utf8_len_elements, ((mk_win_base_wchar_lpt)(mws->m_mem)), converted1);
	mk_lang_assert(converted2 == converted1);
	wide->m_str = ((mk_win_base_wchar_lpct)(mws->m_mem));
	wide->m_length_elements = converted1;
}

mk_lang_jumbo void mk_win_tstring_ansi_to_asci_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(ansi));
	((void)(ansi_len_elements));
	((void)(mws));
	((void)(asci));
}

mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(ansi));
	((void)(ansi_len_elements));
	((void)(mws));
	((void)(utf8));
}

mk_lang_jumbo void mk_win_tstring_wide_to_asci_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(wide));
	((void)(wide_len_elements));
	((void)(mws));
	((void)(asci));
}

mk_lang_jumbo void mk_win_tstring_wide_to_utf8_sz_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(wide));
	((void)(wide_len_elements));
	((void)(mws));
	((void)(utf8));
}


mk_lang_jumbo void mk_win_tstring_asci_to_ansi_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, int const asci_len_elements, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept { mk_win_tstring_asci_to_ansi_sz_wmws(ex, asci, asci_len_elements, mk_win_tstring_get_next_mws(), ansi); }
mk_lang_jumbo void mk_win_tstring_utf8_to_ansi_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, int const utf8_len_elements, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept { mk_win_tstring_utf8_to_ansi_sz_wmws(ex, utf8, utf8_len_elements, mk_win_tstring_get_next_mws(), ansi); }
mk_lang_jumbo void mk_win_tstring_wide_to_ansi_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept { mk_win_tstring_wide_to_ansi_sz_wmws(ex, wide, wide_len_elements, mk_win_tstring_get_next_mws(), ansi); }
mk_lang_jumbo void mk_win_tstring_asci_to_wide_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, int const asci_len_elements, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept { mk_win_tstring_asci_to_wide_sz_wmws(ex, asci, asci_len_elements, mk_win_tstring_get_next_mws(), wide); }
mk_lang_jumbo void mk_win_tstring_ansi_to_wide_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept { mk_win_tstring_ansi_to_wide_sz_wmws(ex, ansi, ansi_len_elements, mk_win_tstring_get_next_mws(), wide); }
mk_lang_jumbo void mk_win_tstring_utf8_to_wide_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, int const utf8_len_elements, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept { mk_win_tstring_utf8_to_wide_sz_wmws(ex, utf8, utf8_len_elements, mk_win_tstring_get_next_mws(), wide); }
mk_lang_jumbo void mk_win_tstring_ansi_to_asci_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept { mk_win_tstring_ansi_to_asci_sz_wmws(ex, ansi, ansi_len_elements, mk_win_tstring_get_next_mws(), asci); }
mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept { mk_win_tstring_ansi_to_utf8_sz_wmws(ex, ansi, ansi_len_elements, mk_win_tstring_get_next_mws(), utf8); }
mk_lang_jumbo void mk_win_tstring_wide_to_asci_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept { mk_win_tstring_wide_to_asci_sz_wmws(ex, wide, wide_len_elements, mk_win_tstring_get_next_mws(), asci); }
mk_lang_jumbo void mk_win_tstring_wide_to_utf8_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept { mk_win_tstring_wide_to_utf8_sz_wmws(ex, wide, wide_len_elements, mk_win_tstring_get_next_mws(), utf8); }


mk_lang_jumbo void mk_win_tstring_asci_to_ansi_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept
{
	mk_win_tstring_wstr_with_size_t wide;

	mk_lang_assert(ex);
	mk_lang_assert(mk_win_tstring_validate_asci(asci));
	mk_lang_assert(mws);
	mk_lang_assert(ansi);

	mk_win_tstring_asci_to_wide_zt_wmws(ex, asci, mws, &wide);
	mk_lang_exception_if_is_return(ex);
	mk_win_tstring_wide_to_ansi_sz_nmws(ex, wide.m_str, wide.m_length_elements, ansi);
}

mk_lang_jumbo void mk_win_tstring_utf8_to_ansi_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept
{
	mk_win_tstring_wstr_with_size_t wide;

	mk_lang_assert(ex);
	mk_lang_assert(mws);
	mk_lang_assert(ansi);

	mk_win_tstring_utf8_to_wide_zt_wmws(ex, utf8, mws, &wide);
	mk_lang_exception_if_is_return(ex);
	mk_win_tstring_wide_to_ansi_sz_nmws(ex, wide.m_str, wide.m_length_elements, ansi);
}

mk_lang_jumbo void mk_win_tstring_wide_to_ansi_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept
{
	static mk_win_base_pchar_t const s_default = 'x';

	int converted1;
	int converted2;
	mk_win_base_bool_t defaulted;

	mk_lang_assert(ex);
	mk_lang_assert(mws);
	mk_lang_assert(ansi);

	if(!wide)
	{
		ansi->m_str = mk_win_base_null;
		ansi->m_length_elements = 0;
		return;
	}
	if(!*wide)
	{
		ansi->m_str = &s_mk_win_tstring_null_pchar;
		ansi->m_length_elements = 1;
		return;
	}
	converted1 = mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_wc_e_no_best_fit_chars, wide, -1, mk_win_base_null, 0, mk_win_base_null, mk_win_base_null);
	mk_lang_assert(converted1 >= 2);
	mk_win_tstring_resize_mws(ex, mws, converted1 * sizeof(mk_win_base_pchar_t));
	mk_lang_exception_if_is_return(ex);
	converted2 = mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_wc_e_no_best_fit_chars, wide, -1, ((mk_win_base_pchar_lpt)(mws->m_mem)), converted1, &s_default, &defaulted);
	mk_lang_assert(converted2 == converted1);
	((void)(defaulted));
	ansi->m_str = ((mk_win_base_pchar_lpct)(mws->m_mem));
	ansi->m_length_elements = converted1;
}

mk_lang_jumbo void mk_win_tstring_asci_to_wide_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept
{
	int n;
	int i;

	mk_lang_assert(ex);
	mk_lang_assert(mk_win_tstring_validate_asci(asci));
	mk_lang_assert(mws);
	mk_lang_assert(wide);

	if(!asci)
	{
		wide->m_str = mk_win_base_null;
		wide->m_length_elements = 0;
		return;
	}
	if(!*asci)
	{
		wide->m_str = &s_mk_win_tstring_null_wchar;
		wide->m_length_elements = 1;
		return;
	}
	n = 0;
	while(asci[++n]);
	++n;
	mk_win_tstring_resize_mws(ex, mws, n * sizeof(mk_win_base_wchar_t));
	mk_lang_exception_if_is_return(ex);
	for(i = 0; i != n; ++i) { ((mk_win_base_wchar_lpt)(mws->m_mem))[i] = ((mk_win_base_wchar_t)(asci[i])); }
	wide->m_str = ((mk_win_base_wchar_lpct)(mws->m_mem));
	wide->m_length_elements = n;
}

mk_lang_jumbo void mk_win_tstring_ansi_to_wide_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept
{
	int converted1;
	int converted2;

	mk_lang_assert(ex);
	mk_lang_assert(mws);
	mk_lang_assert(wide);

	if(!ansi)
	{
		wide->m_str = mk_win_base_null;
		wide->m_length_elements = 0;
		return;
	}
	if(!*ansi)
	{
		wide->m_str = &s_mk_win_tstring_null_wchar;
		wide->m_length_elements = 1;
		return;
	}
	converted1 = mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_mb_e_none, ansi, -1, mk_win_base_null, 0);
	mk_lang_assert(converted1 >= 2);
	mk_win_tstring_resize_mws(ex, mws, converted1 * sizeof(mk_win_base_wchar_t));
	mk_lang_exception_if_is_return(ex);
	converted2 = mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_mb_e_none, ansi, -1, ((mk_win_base_wchar_lpt)(mws->m_mem)), converted1);
	mk_lang_assert(converted2 == converted1);
	wide->m_str = ((mk_win_base_wchar_lpct)(mws->m_mem));
	wide->m_length_elements = converted1;
}

mk_lang_jumbo void mk_win_tstring_utf8_to_wide_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept
{
	int converted1;
	int converted2;

	mk_lang_assert(ex);
	mk_lang_assert(mws);
	mk_lang_assert(wide);

	if(!utf8)
	{
		wide->m_str = mk_win_base_null;
		wide->m_length_elements = 0;
		return;
	}
	if(!*utf8)
	{
		wide->m_str = &s_mk_win_tstring_null_wchar;
		wide->m_length_elements = 1;
		return;
	}
	converted1 = mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_e_utf8, mk_win_tstring_flags_mb_e_none, utf8, -1, mk_win_base_null, 0);
	mk_lang_assert(converted1 >= 2);
	mk_win_tstring_resize_mws(ex, mws, converted1 * sizeof(mk_win_base_wchar_t));
	mk_lang_exception_if_is_return(ex);
	converted2 = mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_e_utf8, mk_win_tstring_flags_mb_e_none, utf8, -1, ((mk_win_base_wchar_lpt)(mws->m_mem)), converted1);
	mk_lang_assert(converted2 == converted1);
	wide->m_str = ((mk_win_base_wchar_lpct)(mws->m_mem));
	wide->m_length_elements = converted1;
}

mk_lang_jumbo void mk_win_tstring_ansi_to_asci_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(ansi));
	((void)(mws));
	((void)(asci));
	/* todo */
}

mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(ansi));
	((void)(mws));
	((void)(utf8));
	/* todo */
}

mk_lang_jumbo void mk_win_tstring_wide_to_asci_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(wide));
	((void)(mws));
	((void)(asci));
	/* todo */
}

mk_lang_jumbo void mk_win_tstring_wide_to_utf8_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(wide));
	((void)(mws));
	((void)(utf8));
	/* todo */
}

mk_lang_jumbo void mk_win_tstring_asci_to_utf8_zt_wmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_mem_with_size_pt const mws, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept
{
	int n;
	int i;

	mk_lang_assert(ex);
	mk_lang_assert(mk_win_tstring_validate_asci(asci));
	mk_lang_assert(mws);
	mk_lang_assert(utf8);

	if(!asci)
	{
		utf8->m_str = mk_win_base_null;
		utf8->m_length_elements = 0;
		return;
	}
	if(!*asci)
	{
		utf8->m_str = &s_mk_win_tstring_null_pchar;
		utf8->m_length_elements = 1;
		return;
	}
	n = 0;
	while(asci[++n]);
	++n;
	mk_win_tstring_resize_mws(ex, mws, n * sizeof(mk_win_base_pchar_t));
	mk_lang_exception_if_is_return(ex);
	for(i = 0; i != n; ++i) { ((mk_win_base_pchar_lpt)(mws->m_mem))[i] = asci[i]; }
	utf8->m_str = ((mk_win_base_pchar_lpct)(mws->m_mem));
	utf8->m_length_elements = n;
}


mk_lang_jumbo void mk_win_tstring_asci_to_ansi_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept { mk_win_tstring_asci_to_ansi_zt_wmws(ex, asci, mk_win_tstring_get_next_mws(), ansi); }
mk_lang_jumbo void mk_win_tstring_utf8_to_ansi_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept { mk_win_tstring_utf8_to_ansi_zt_wmws(ex, utf8, mk_win_tstring_get_next_mws(), ansi); }
mk_lang_jumbo void mk_win_tstring_wide_to_ansi_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept { mk_win_tstring_wide_to_ansi_zt_wmws(ex, wide, mk_win_tstring_get_next_mws(), ansi); }
mk_lang_jumbo void mk_win_tstring_asci_to_wide_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept { mk_win_tstring_asci_to_wide_zt_wmws(ex, asci, mk_win_tstring_get_next_mws(), wide); }
mk_lang_jumbo void mk_win_tstring_ansi_to_wide_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept { mk_win_tstring_ansi_to_wide_zt_wmws(ex, ansi, mk_win_tstring_get_next_mws(), wide); }
mk_lang_jumbo void mk_win_tstring_utf8_to_wide_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const utf8, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept { mk_win_tstring_utf8_to_wide_zt_wmws(ex, utf8, mk_win_tstring_get_next_mws(), wide); }
mk_lang_jumbo void mk_win_tstring_ansi_to_asci_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept { mk_win_tstring_ansi_to_asci_zt_wmws(ex, ansi, mk_win_tstring_get_next_mws(), asci); }
mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept { mk_win_tstring_ansi_to_utf8_zt_wmws(ex, ansi, mk_win_tstring_get_next_mws(), utf8); }
mk_lang_jumbo void mk_win_tstring_wide_to_asci_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_pstr_with_size_pt const asci) mk_lang_noexcept { mk_win_tstring_wide_to_asci_zt_wmws(ex, wide, mk_win_tstring_get_next_mws(), asci); }
mk_lang_jumbo void mk_win_tstring_wide_to_utf8_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept { mk_win_tstring_wide_to_utf8_zt_wmws(ex, wide, mk_win_tstring_get_next_mws(), utf8); }
mk_lang_jumbo void mk_win_tstring_asci_to_utf8_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_pstr_with_size_pt const utf8) mk_lang_noexcept { mk_win_tstring_asci_to_utf8_zt_wmws(ex, asci, mk_win_tstring_get_next_mws(), utf8); }


mk_lang_jumbo void mk_win_tstring_ansi_to_asci_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_pchar_lpt const asci, int const asci_len_elements, mk_win_tstring_pstr_with_size_pt const asci_out) mk_lang_noexcept
{
	mk_win_tstring_wstr_with_size_t wide;

	mk_lang_assert(ex);
	mk_lang_assert((ansi || ansi_len_elements == 0) && (!ansi || *ansi || ansi_len_elements == 1));
	mk_lang_assert(ansi_len_elements >= 0);
	mk_lang_assert(asci);
	mk_lang_assert(asci_len_elements >= 0);
	mk_lang_assert(asci_out);

	mk_win_tstring_ansi_to_wide_sz_nmws(ex, ansi, ansi_len_elements, &wide);
	mk_lang_exception_if_is_return(ex);
	mk_win_tstring_wide_to_asci_buff_sz_nmws(ex, wide.m_str, wide.m_length_elements, asci, asci_len_elements, asci_out);
}

mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_pchar_lpt const utf8, int const utf8_len_elements, mk_win_tstring_pstr_with_size_pt const utf8_out) mk_lang_noexcept
{
	mk_win_tstring_wstr_with_size_t wide;

	mk_lang_assert(ex);
	mk_lang_assert((ansi || ansi_len_elements == 0) && (!ansi || *ansi || ansi_len_elements == 1));
	mk_lang_assert(ansi_len_elements >= 0);
	mk_lang_assert(utf8);
	mk_lang_assert(utf8_len_elements >= 0);
	mk_lang_assert(utf8_out);

	mk_win_tstring_ansi_to_wide_sz_nmws(ex, ansi, ansi_len_elements, &wide);
	mk_lang_exception_if_is_return(ex);
	mk_win_tstring_wide_to_utf8_buff_sz_nmws(ex, wide.m_str, wide.m_length_elements, utf8, utf8_len_elements, utf8_out);
}

mk_lang_jumbo void mk_win_tstring_ansi_to_wide_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_base_wchar_lpt const wide, int const wide_len_elements, mk_win_tstring_wstr_with_size_pt const wide_out) mk_lang_noexcept
{
	int converted1;
	int converted2;

	mk_lang_assert(ex);
	mk_lang_assert((ansi || ansi_len_elements == 0) && (!ansi || *ansi || ansi_len_elements == 1));
	mk_lang_assert(ansi_len_elements >= 0);
	mk_lang_assert(wide);
	mk_lang_assert(wide_len_elements >= 0);
	mk_lang_assert(wide_out);

	if(ansi_len_elements == 0)
	{
		wide_out->m_str = mk_win_base_null;
		wide_out->m_length_elements = 0;
		return;
	}
	if(ansi_len_elements == 1)
	{
		mk_lang_assert(wide_len_elements >= 1);
		*wide = s_mk_win_tstring_null_wchar;
		wide_out->m_str = wide;
		wide_out->m_length_elements = 1;
		return;
	}
	converted1 = mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_mb_e_none, ansi, ansi_len_elements, mk_win_base_null, 0);
	mk_lang_assert(converted1 > 0);
	mk_lang_assert(wide_len_elements >= converted1);
	converted2 = mk_win_tstring_ansi_to_wide_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_mb_e_none, ansi, ansi_len_elements, wide, converted1);
	mk_lang_assert(converted2 == converted1);
	wide_out->m_str = wide;
	wide_out->m_length_elements = converted1;
}

mk_lang_jumbo void mk_win_tstring_wide_to_asci_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const asci, int const asci_len_elements, mk_win_tstring_pstr_with_size_pt const asci_out) mk_lang_noexcept
{
	static mk_win_base_pchar_t const s_default = 'x';

	int i;

	mk_lang_assert(ex);
	mk_lang_assert((wide || wide_len_elements == 0) && (!wide || *wide || wide_len_elements == 1));
	mk_lang_assert(wide_len_elements >= 0);
	mk_lang_assert(asci);
	mk_lang_assert(asci_len_elements >= 0);
	mk_lang_assert(asci_out);
	mk_lang_assert(asci_len_elements >= wide_len_elements);

	for(i = 0; i != wide_len_elements; ++i)
	{
		if((wide[i] >= 0x0020 && wide[i] <= 0x007e) || wide[i] == 0x0000)
		{
			asci[i] = ((mk_win_base_pchar_t)(wide[i]));
		}
		else
		{
			asci[i] = s_default;
		}
	}
	asci_out->m_str = asci;
	asci_out->m_length_elements = wide_len_elements;
}

mk_lang_jumbo void mk_win_tstring_wide_to_ansi_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const ansi, int const ansi_len_elements, mk_win_tstring_pstr_with_size_pt const ansi_out) mk_lang_noexcept
{
	static mk_win_base_pchar_t const s_default = 'x';

	int converted1;
	int converted2;
	mk_win_base_bool_t defaulted;

	mk_lang_assert(ex);
	mk_lang_assert((wide || wide_len_elements == 0) && (!wide || *wide || wide_len_elements == 1));
	mk_lang_assert(wide_len_elements >= 0);
	mk_lang_assert(ansi);
	mk_lang_assert(ansi_len_elements >= 0);
	mk_lang_assert(ansi_out);

	if(wide_len_elements == 0)
	{
		ansi_out->m_str = mk_win_base_null;
		ansi_out->m_length_elements = 0;
		return;
	}
	if(wide_len_elements == 1)
	{
		mk_lang_assert(ansi_len_elements >= 1);
		*ansi = s_mk_win_tstring_null_pchar;
		ansi_out->m_str = ansi;
		ansi_out->m_length_elements = 1;
		return;
	}
	converted1 = mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_wc_e_no_best_fit_chars, wide, wide_len_elements, mk_win_base_null, 0, mk_win_base_null, mk_win_base_null);
	mk_lang_assert(converted1 >= 2);
	mk_lang_assert(ansi_len_elements >= converted1);
	converted2 = mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_e_acp, mk_win_tstring_flags_wc_e_no_best_fit_chars, wide, wide_len_elements, ansi, converted1, &s_default, &defaulted);
	mk_lang_assert(converted2 == converted1);
	((void)(defaulted));
	ansi_out->m_str = ansi;
	ansi_out->m_length_elements = converted1;
}

mk_lang_jumbo void mk_win_tstring_wide_to_utf8_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_base_pchar_lpt const utf8, int const utf8_len_elements, mk_win_tstring_pstr_with_size_pt const utf8_out) mk_lang_noexcept
{
	int converted1;
	int converted2;

	mk_lang_assert(ex);
	mk_lang_assert((wide || wide_len_elements == 0) && (!wide || *wide || wide_len_elements == 1));
	mk_lang_assert(wide_len_elements >= 0);
	mk_lang_assert(utf8);
	mk_lang_assert(utf8_len_elements >= 0);
	mk_lang_assert(utf8_out);
	mk_lang_assert(utf8_len_elements >= wide_len_elements); /* todo shrink? */

	converted1 = mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_e_utf8, mk_win_tstring_flags_wc_e_none, wide, wide_len_elements, mk_win_base_null, 0, mk_win_base_null, mk_win_base_null);
	mk_lang_assert(converted1 > 0);
	mk_lang_assert(utf8_len_elements >= converted1);
	converted2 = mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_e_utf8, mk_win_tstring_flags_wc_e_none, wide, wide_len_elements, utf8, converted1, mk_win_base_null, mk_win_base_null);
	mk_lang_assert(converted2 == converted1);
	utf8_out->m_str = utf8;
	utf8_out->m_length_elements = converted1;
}

mk_lang_jumbo void mk_win_tstring_ansi_to_asci_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_base_pchar_lpt const asci, int const asci_len_elements, mk_win_tstring_pstr_with_size_pt const asci_out) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(ansi));
	((void)(asci));
	((void)(asci_len_elements));
	((void)(asci_out));
	/* todo */
}

mk_lang_jumbo void mk_win_tstring_ansi_to_utf8_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_base_pchar_lpt const utf8, int const utf8_len_elements, mk_win_tstring_pstr_with_size_pt const utf8_out) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(ansi));
	((void)(utf8));
	((void)(utf8_len_elements));
	((void)(utf8_out));
	/* todo */
}

mk_lang_jumbo void mk_win_tstring_ansi_to_wide_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_base_wchar_lpt const wide, int const wide_len_elements, mk_win_tstring_wstr_with_size_pt const wide_out) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(ansi));
	((void)(wide));
	((void)(wide_len_elements));
	((void)(wide_out));
	/* todo */
}

mk_lang_jumbo void mk_win_tstring_wide_to_asci_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_base_pchar_lpt const asci, int const asci_len_elements, mk_win_tstring_pstr_with_size_pt const asci_out) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(wide));
	((void)(asci));
	((void)(asci_len_elements));
	((void)(asci_out));
	/* todo */
}

mk_lang_jumbo void mk_win_tstring_wide_to_ansi_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_base_pchar_lpt const ansi, int const ansi_len_elements, mk_win_tstring_pstr_with_size_pt const ansi_out) mk_lang_noexcept
{
	mk_lang_assert(0);
	mk_lang_crash();
	((void)(ex));
	((void)(wide));
	((void)(ansi));
	((void)(ansi_len_elements));
	((void)(ansi_out));
	/* todo */
}

mk_lang_jumbo void mk_win_tstring_wide_to_utf8_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_base_pchar_lpt const utf8, int const utf8_len_elements, mk_win_tstring_pstr_with_size_pt const utf8_out) mk_lang_noexcept
{
	int converted1;
	int converted2;

	mk_lang_assert(ex);
	mk_lang_assert(utf8);
	mk_lang_assert(utf8_len_elements >= 0);
	mk_lang_assert(utf8_out);

	if(!wide)
	{
		utf8_out->m_str = mk_win_base_null;
		utf8_out->m_length_elements = 0;
		return;
	}
	if(!*wide)
	{
		*utf8 = s_mk_win_tstring_null_pchar;
		utf8_out->m_str = utf8;
		utf8_out->m_length_elements = 1;
		return;
	}
	converted1 = mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_e_utf8, mk_win_tstring_flags_wc_e_none, wide, -1, mk_win_base_null, 0, mk_win_base_null, mk_win_base_null);
	mk_lang_assert(converted1 >= 2);
	mk_lang_assert(utf8_len_elements >= converted1);
	converted2 = mk_win_tstring_wide_to_ansi_my(mk_win_tstring_cp_e_utf8, mk_win_tstring_flags_wc_e_none, wide, -1, utf8, converted1, mk_win_base_null, mk_win_base_null);
	mk_lang_assert(converted2 == converted1);
	utf8_out->m_str = utf8;
	utf8_out->m_length_elements = converted1;
}


mk_lang_jumbo void mk_win_tstring_ansi_to_tstr_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements, mk_win_tstring_tstr_with_size_pt const tstr_out) mk_lang_noexcept
{
#if mk_win_tstring_enc == mk_win_tstring_enc_asci
	mk_win_tstring_ansi_to_asci_buff_sz_nmws(ex, ansi, ansi_len_elements, tstr, tstr_len_elements, tstr_out);
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
	mk_lang_crash();
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
	mk_win_tstring_ansi_to_utf8_buff_sz_nmws(ex, ansi, ansi_len_elements, tstr, tstr_len_elements, tstr_out);
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
	mk_win_tstring_ansi_to_wide_buff_sz_nmws(ex, ansi, ansi_len_elements, tstr, tstr_len_elements, tstr_out);
#endif
}

mk_lang_jumbo void mk_win_tstring_wide_to_tstr_buff_sz_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements, mk_win_tstring_tstr_with_size_pt const tstr_out) mk_lang_noexcept
{
#if mk_win_tstring_enc == mk_win_tstring_enc_asci
	mk_win_tstring_wide_to_asci_buff_sz_nmws(ex, wide, wide_len_elements, tstr, tstr_len_elements, tstr_out);
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
	mk_win_tstring_wide_to_ansi_buff_sz_nmws(ex, wide, wide_len_elements, tstr, tstr_len_elements, tstr_out);
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
	mk_win_tstring_wide_to_utf8_buff_sz_nmws(ex, wide, wide_len_elements, tstr, tstr_len_elements, tstr_out);
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
	((void)(ex));
	((void)(wide));
	((void)(wide_len_elements));
	((void)(tstr));
	((void)(tstr_len_elements));
	((void)(tstr_out));
	mk_lang_assert(0);
	mk_lang_crash();
#endif
}

mk_lang_jumbo void mk_win_tstring_ansi_to_tstr_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements, mk_win_tstring_tstr_with_size_pt const tstr_out) mk_lang_noexcept
{
#if mk_win_tstring_enc == mk_win_tstring_enc_asci
	mk_win_tstring_ansi_to_asci_buff_zt_nmws(ex, ansi, tstr, tstr_len_elements, tstr_out);
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
	mk_lang_crash();
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
	mk_win_tstring_ansi_to_utf8_buff_zt_nmws(ex, ansi, tstr, tstr_len_elements, tstr_out);
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
	mk_win_tstring_ansi_to_wide_buff_zt_nmws(ex, ansi, tstr, tstr_len_elements, tstr_out);
#endif
}

mk_lang_jumbo void mk_win_tstring_wide_to_tstr_buff_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements, mk_win_tstring_tstr_with_size_pt const tstr_out) mk_lang_noexcept
{
#if mk_win_tstring_enc == mk_win_tstring_enc_asci
	mk_win_tstring_wide_to_asci_buff_zt_nmws(ex, wide, tstr, tstr_len_elements, tstr_out);
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
	mk_win_tstring_wide_to_ansi_buff_zt_nmws(ex, wide, tstr, tstr_len_elements, tstr_out);
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
	mk_win_tstring_wide_to_utf8_buff_zt_nmws(ex, wide, tstr, tstr_len_elements, tstr_out);
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
	((void)(ex));
	((void)(wide));
	((void)(tstr));
	((void)(tstr_len_elements));
	((void)(tstr_out));
	mk_lang_assert(0);
	mk_lang_crash();
#endif
}

mk_lang_jumbo void mk_win_tstring_tstr_to_ansi_sz_nmws(mk_lang_exception_pt const ex, mk_win_tstring_tchar_lpct const tstr, int const tstr_len_elements, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept
{
#if mk_win_tstring_enc == mk_win_tstring_enc_asci
	mk_win_tstring_asci_to_ansi_sz_nmws(ex, tstr, tstr_len_elements, ansi);
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
	mk_lang_crash();
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
	mk_win_tstring_utf8_to_ansi_sz_nmws(ex, tstr, tstr_len_elements, ansi);
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
	mk_win_tstring_wide_to_ansi_sz_nmws(ex, tstr, tstr_len_elements, ansi);
#endif
}

mk_lang_jumbo void mk_win_tstring_tstr_to_wide_sz_nmws(mk_lang_exception_pt const ex, mk_win_tstring_tchar_lpct const tstr, int const tstr_len_elements, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept
{
#if mk_win_tstring_enc == mk_win_tstring_enc_asci
	mk_win_tstring_asci_to_wide_sz_nmws(ex, tstr, tstr_len_elements, wide);
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
	mk_win_tstring_ansi_to_wide_sz_nmws(ex, tstr, tstr_len_elements, wide);
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
	mk_win_tstring_utf8_to_wide_sz_nmws(ex, tstr, tstr_len_elements, wide);
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
	((void)(ex));
	((void)(tstr));
	((void)(tstr_len_elements));
	((void)(wide));
	mk_lang_assert(0);
	mk_lang_crash();
#endif
}

mk_lang_jumbo void mk_win_tstring_tstr_to_ansi_zt_nmws(mk_lang_exception_pt const ex, mk_win_tstring_tchar_lpct const tstr, mk_win_tstring_pstr_with_size_pt const ansi) mk_lang_noexcept
{
#if mk_win_tstring_enc == mk_win_tstring_enc_asci
	mk_win_tstring_asci_to_ansi_zt_nmws(ex, tstr, ansi);
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
	mk_lang_crash();
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
	mk_win_tstring_utf8_to_ansi_zt_nmws(ex, tstr, ansi);
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
	mk_win_tstring_wide_to_ansi_zt_nmws(ex, tstr, ansi);
#endif
}

mk_lang_jumbo void mk_win_tstring_tstr_to_wide_zt_nmws(mk_lang_exception_pt const ex, mk_win_tstring_tchar_lpct const tstr, mk_win_tstring_wstr_with_size_pt const wide) mk_lang_noexcept
{
#if mk_win_tstring_enc == mk_win_tstring_enc_asci
	mk_win_tstring_asci_to_wide_zt_nmws(ex, tstr, wide);
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
	mk_win_tstring_ansi_to_wide_zt_nmws(ex, tstr, wide);
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
	mk_win_tstring_utf8_to_wide_zt_nmws(ex, tstr, wide);
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
	((void)(ex));
	((void)(tstr));
	((void)(wide));
	mk_lang_assert(0);
	mk_lang_crash();
#endif
}

mk_lang_jumbo void mk_win_tstring_asci_to_tstr_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const asci, mk_win_tstring_tstr_with_size_pt const tstr) mk_lang_noexcept
{
#if mk_win_tstring_enc == mk_win_tstring_enc_asci
	mk_win_tstring_asci_to_asci_zt_nmws(ex, asci, tstr);
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
	mk_lang_crash();
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
	mk_win_tstring_asci_to_utf8_zt_nmws(ex, asci, tstr);
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
	mk_win_tstring_asci_to_wide_zt_nmws(ex, asci, tstr);
#endif
}

mk_lang_jumbo void mk_win_tstring_ansi_to_tstr_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_pchar_lpct const ansi, mk_win_tstring_tstr_with_size_pt const tstr) mk_lang_noexcept
{
#if mk_win_tstring_enc == mk_win_tstring_enc_asci
	mk_win_tstring_ansi_to_asci_zt_nmws(ex, ansi, tstr);
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
	mk_lang_crash();
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
	mk_win_tstring_ansi_to_utf8_zt_nmws(ex, ansi, tstr);
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
	mk_win_tstring_ansi_to_wide_zt_nmws(ex, ansi, tstr);
#endif
}

mk_lang_jumbo void mk_win_tstring_wide_to_tstr_zt_nmws(mk_lang_exception_pt const ex, mk_win_base_wchar_lpct const wide, mk_win_tstring_tstr_with_size_pt const tstr) mk_lang_noexcept
{
#if mk_win_tstring_enc == mk_win_tstring_enc_asci
	mk_win_tstring_wide_to_asci_zt_nmws(ex, wide, tstr);
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
	mk_win_tstring_wide_to_ansi_zt_nmws(ex, wide, tstr);
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
	mk_win_tstring_wide_to_utf8_zt_nmws(ex, wide, tstr);
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
	((void)(ex));
	((void)(wide));
	((void)(tstr));
	mk_lang_assert(0);
	mk_lang_crash();
#endif
}


mk_lang_jumbo void mk_win_tstring_allocate_ansi_ex(mk_lang_exception_pt const ex, int const ansi_len_elements, mk_win_base_pchar_lpt* const ansi) mk_lang_noexcept
{
	mk_win_tstring_mem_with_size_pt mws;

	mk_lang_assert(ex);
	mk_lang_assert(ansi_len_elements >= 2);
	mk_lang_assert(ansi);

	mws = mk_win_tstring_get_next_mws();
	mk_win_tstring_resize_mws(ex, mws, ansi_len_elements * ((int)(sizeof(mk_win_base_pchar_t))));
	mk_lang_exception_if_is_return(ex);
	*ansi = ((mk_win_base_pchar_lpt)(mws->m_mem));
}

mk_lang_jumbo void mk_win_tstring_allocate_wide_ex(mk_lang_exception_pt const ex, int const wide_len_elements, mk_win_base_wchar_lpt* const wide) mk_lang_noexcept
{
	mk_win_tstring_mem_with_size_pt mws;

	mk_lang_assert(ex);
	mk_lang_assert(wide_len_elements >= 2);
	mk_lang_assert(wide);

	mws = mk_win_tstring_get_next_mws();
	mk_win_tstring_resize_mws(ex, mws, wide_len_elements * ((int)(sizeof(mk_win_base_wchar_t))));
	mk_lang_exception_if_is_return(ex);
	*wide = ((mk_win_base_wchar_lpt)(mws->m_mem));
}


mk_lang_jumbo void mk_win_tstring_init(void) mk_lang_noexcept
{
	int i;
	mk_win_tstring_mem_with_size_pt mws;

	for(i = 0; i != s_mk_win_tstring_mws_elements; ++i)
	{
		mws = &g_mk_win_tstring_mems_with_sizes[i];
		mk_lang_assert(!mws->m_mem);
		mk_lang_assert(!mws->m_size_bytes);
	}
}

mk_lang_jumbo void mk_win_tstring_deinit(void) mk_lang_noexcept
{
	int i;
	mk_win_tstring_mem_with_size_pt mws;

	for(i = 0; i != s_mk_win_tstring_mws_elements; ++i)
	{
		mws = &g_mk_win_tstring_mems_with_sizes[i];
		mk_win_mallocator_main_heap_deallocate(mws->m_mem, mws->m_size_bytes);
	}
}


mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_ansi_to_tstr_buff_sz_nofail(mk_win_base_pchar_lpct const ansi, int const ansi_len_elements, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_tstring_tstr_with_size_t tstr_ret;

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_ansi_to_tstr_buff_sz_nmws(&ex, ansi, ansi_len_elements, tstr, tstr_len_elements, &tstr_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return tstr_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_wide_to_tstr_buff_sz_nofail(mk_win_base_wchar_lpct const wide, int const wide_len_elements, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_tstring_tstr_with_size_t tstr_ret;

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_wide_to_tstr_buff_sz_nmws(&ex, wide, wide_len_elements, tstr, tstr_len_elements, &tstr_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return tstr_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_ansi_to_tstr_buff_zt_nofail(mk_win_base_pchar_lpct const ansi, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_tstring_tstr_with_size_t tstr_ret;

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_ansi_to_tstr_buff_zt_nmws(&ex, ansi, tstr, tstr_len_elements, &tstr_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return tstr_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_wide_to_tstr_buff_zt_nofail(mk_win_base_wchar_lpct const wide, mk_win_tstring_tchar_lpt const tstr, int const tstr_len_elements) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_tstring_tstr_with_size_t tstr_ret;

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_wide_to_tstr_buff_zt_nmws(&ex, wide, tstr, tstr_len_elements, &tstr_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return tstr_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_pstr_with_size_t mk_win_tstring_tstr_to_ansi_sz_nofail(mk_win_tstring_tchar_lpct const tstr, int const tstr_len_elements) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_tstring_pstr_with_size_t ansi_ret;

	mk_lang_assert(tstr || tstr_len_elements == 0);
	mk_lang_assert(tstr_len_elements >= 0);

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_tstr_to_ansi_sz_nmws(&ex, tstr, tstr_len_elements, &ansi_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return ansi_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_wstr_with_size_t mk_win_tstring_tstr_to_wide_sz_nofail(mk_win_tstring_tchar_lpct const tstr, int const tstr_len_elements) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_tstring_wstr_with_size_t wide_ret;

	mk_lang_assert(tstr || tstr_len_elements == 0);
	mk_lang_assert(tstr_len_elements >= 0);

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_tstr_to_wide_sz_nmws(&ex, tstr, tstr_len_elements, &wide_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return wide_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_pstr_with_size_t mk_win_tstring_tstr_to_ansi_zt_nofail(mk_win_tstring_tchar_lpct const tstr) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_tstring_pstr_with_size_t ansi_ret;

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_tstr_to_ansi_zt_nmws(&ex, tstr, &ansi_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return ansi_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_wstr_with_size_t mk_win_tstring_tstr_to_wide_zt_nofail(mk_win_tstring_tchar_lpct const tstr) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_tstring_wstr_with_size_t wide_ret;

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_tstr_to_wide_zt_nmws(&ex, tstr, &wide_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return wide_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_asci_to_tstr_zt_nofail(mk_win_base_pchar_lpct const asci) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_tstring_tstr_with_size_t tstr_ret;

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_asci_to_tstr_zt_nmws(&ex, asci, &tstr_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return tstr_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_ansi_to_tstr_zt_nofail(mk_win_base_pchar_lpct const ansi) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_tstring_tstr_with_size_t tstr_ret;

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_ansi_to_tstr_zt_nmws(&ex, ansi, &tstr_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return tstr_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_wide_to_tstr_zt_nofail(mk_win_base_wchar_lpct const wide) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_tstring_tstr_with_size_t tstr_ret;

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_wide_to_tstr_zt_nmws(&ex, wide, &tstr_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return tstr_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpct mk_win_tstring_tstr_to_wnds_zt_nofail(mk_win_tstring_tchar_lpct const tstr) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return tstr;
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_tstring_tstr_to_ansi_zt_nofail(tstr).m_str;
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return tstr;
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_tstring_tstr_to_wide_zt_nofail(text).m_str;
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return tstr;
		#else
			return mk_win_tstring_tstr_to_ansi_zt_nofail(tstr).m_str;
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return tstr;
		#else
			return mk_win_tstring_tstr_to_wide_zt_nofail(tstr).m_str;
		#endif
	}
#endif
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_pchar_lpt mk_win_tstring_allocate_ansi_nofail(int const ansi_len_elements) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_base_pchar_lpt ansi_ret;

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_allocate_ansi_ex(&ex, ansi_len_elements, &ansi_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return ansi_ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_wchar_lpt mk_win_tstring_allocate_wide_nofail(int const wide_len_elements) mk_lang_noexcept
{
	mk_lang_exception_t ex;
	mk_win_base_wchar_lpt wide_ret;

	mk_lang_exception_make_none(&ex);
	mk_win_tstring_allocate_wide_ex(&ex, wide_len_elements, &wide_ret);
	if(mk_lang_exception_is(&ex)) mk_lang_crash();
	return wide_ret;
}


#if defined _MSC_VER && _MSC_VER == 1936
#pragma warning(pop)
#endif
