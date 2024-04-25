#ifndef mk_include_guard_mk_win_tstring
#define mk_include_guard_mk_win_tstring


#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_unicode_api.h"


#define mk_win_tstring_enc_asci 1001
#define mk_win_tstring_enc_ansi 1002
#define mk_win_tstring_enc_utf8 1003
#define mk_win_tstring_enc_wide 1004

#if mk_win_unicode_api == mk_win_unicode_api_oold
#define mk_win_tstring_enc mk_win_tstring_enc_asci
#elif mk_win_unicode_api == mk_win_unicode_api_ansi
#define mk_win_tstring_enc mk_win_tstring_enc_ansi
#elif mk_win_unicode_api == mk_win_unicode_api_both
#define mk_win_tstring_enc mk_win_tstring_enc_utf8
#elif mk_win_unicode_api == mk_win_unicode_api_wide
#define mk_win_tstring_enc mk_win_tstring_enc_wide
#else
#pragma error xxxxxxxxxx
#endif


#if mk_win_tstring_enc == mk_win_tstring_enc_asci
typedef mk_win_base_pchar_t mk_win_tstring_tchar_t;
#define mk_win_tstring_tchar_c(x) x
#define mk_win_tstring_tstr_with_size_s mk_win_tstring_pstr_with_size_s
#elif mk_win_tstring_enc == mk_win_tstring_enc_ansi
typedef mk_win_base_pchar_t mk_win_tstring_tchar_t;
#define mk_win_tstring_tchar_c(x) x
#define mk_win_tstring_tstr_with_size_s mk_win_tstring_pstr_with_size_s
#elif mk_win_tstring_enc == mk_win_tstring_enc_utf8
typedef mk_win_base_pchar_t mk_win_tstring_tchar_t;
#define mk_win_tstring_tchar_c(x) x
#define mk_win_tstring_tstr_with_size_s mk_win_tstring_pstr_with_size_s
#elif mk_win_tstring_enc == mk_win_tstring_enc_wide
typedef mk_win_base_wchar_t mk_win_tstring_tchar_t;
#define mk_win_tstring_tchar_c(x) L ## x
#define mk_win_tstring_tstr_with_size_s mk_win_tstring_wstr_with_size_s
#else
#pragma error xxxxxxxxxx
#endif
typedef mk_win_tstring_tchar_t const mk_win_tstring_tchar_ct;
typedef mk_win_tstring_tchar_t* mk_win_tstring_tchar_pt;
typedef mk_win_tstring_tchar_t const* mk_win_tstring_tchar_pct;
typedef mk_win_tstring_tchar_t mk_win_base_far* mk_win_tstring_tchar_lpt;
typedef mk_win_tstring_tchar_t mk_win_base_far const* mk_win_tstring_tchar_lpct;
typedef mk_win_tstring_tchar_t mk_win_base_near* mk_win_tstring_tchar_npt;
typedef mk_win_tstring_tchar_t mk_win_base_near const* mk_win_tstring_tchar_npct;


struct mk_win_tstring_mem_with_size_s
{
	mk_win_base_void_lpt m_mem;
	mk_lang_types_sint_t m_size_bytes;
};
typedef struct mk_win_tstring_mem_with_size_s mk_win_tstring_mem_with_size_t;
typedef mk_win_tstring_mem_with_size_t const mk_win_tstring_mem_with_size_ct;
typedef mk_win_tstring_mem_with_size_t* mk_win_tstring_mem_with_size_pt;
typedef mk_win_tstring_mem_with_size_t const* mk_win_tstring_mem_with_size_pct;
typedef mk_win_tstring_mem_with_size_t mk_win_base_far* mk_win_tstring_mem_with_size_lpt;
typedef mk_win_tstring_mem_with_size_t mk_win_base_far const* mk_win_tstring_mem_with_size_lpct;
typedef mk_win_tstring_mem_with_size_t mk_win_base_near* mk_win_tstring_mem_with_size_npt;
typedef mk_win_tstring_mem_with_size_t mk_win_base_near const* mk_win_tstring_mem_with_size_npct;

struct mk_win_tstring_pstr_with_size_s
{
	mk_win_base_pchar_lpct m_str;
	mk_lang_types_sint_t m_length_elements;
};
typedef struct mk_win_tstring_pstr_with_size_s mk_win_tstring_pstr_with_size_t;
typedef mk_win_tstring_pstr_with_size_t const mk_win_tstring_pstr_with_size_ct;
typedef mk_win_tstring_pstr_with_size_t* mk_win_tstring_pstr_with_size_pt;
typedef mk_win_tstring_pstr_with_size_t const* mk_win_tstring_pstr_with_size_pct;
typedef mk_win_tstring_pstr_with_size_t mk_win_base_far* mk_win_tstring_pstr_with_size_lpt;
typedef mk_win_tstring_pstr_with_size_t mk_win_base_far const* mk_win_tstring_pstr_with_size_lpct;
typedef mk_win_tstring_pstr_with_size_t mk_win_base_near* mk_win_tstring_pstr_with_size_npt;
typedef mk_win_tstring_pstr_with_size_t mk_win_base_near const* mk_win_tstring_pstr_with_size_npct;

struct mk_win_tstring_wstr_with_size_s
{
	mk_win_base_wchar_lpct m_str;
	mk_lang_types_sint_t m_length_elements;
};
typedef struct mk_win_tstring_wstr_with_size_s mk_win_tstring_wstr_with_size_t;
typedef mk_win_tstring_wstr_with_size_t const mk_win_tstring_wstr_with_size_ct;
typedef mk_win_tstring_wstr_with_size_t* mk_win_tstring_wstr_with_size_pt;
typedef mk_win_tstring_wstr_with_size_t const* mk_win_tstring_wstr_with_size_pct;
typedef mk_win_tstring_wstr_with_size_t mk_win_base_far* mk_win_tstring_wstr_with_size_lpt;
typedef mk_win_tstring_wstr_with_size_t mk_win_base_far const* mk_win_tstring_wstr_with_size_lpct;
typedef mk_win_tstring_wstr_with_size_t mk_win_base_near* mk_win_tstring_wstr_with_size_npt;
typedef mk_win_tstring_wstr_with_size_t mk_win_base_near const* mk_win_tstring_wstr_with_size_npct;

typedef struct mk_win_tstring_tstr_with_size_s mk_win_tstring_tstr_with_size_t;
typedef mk_win_tstring_tstr_with_size_t const mk_win_tstring_tstr_with_size_ct;
typedef mk_win_tstring_tstr_with_size_t* mk_win_tstring_tstr_with_size_pt;
typedef mk_win_tstring_tstr_with_size_t const* mk_win_tstring_tstr_with_size_pct;
typedef mk_win_tstring_tstr_with_size_t mk_win_base_far* mk_win_tstring_tstr_with_size_lpt;
typedef mk_win_tstring_tstr_with_size_t mk_win_base_far const* mk_win_tstring_tstr_with_size_lpct;
typedef mk_win_tstring_tstr_with_size_t mk_win_base_near* mk_win_tstring_tstr_with_size_npt;
typedef mk_win_tstring_tstr_with_size_t mk_win_base_near const* mk_win_tstring_tstr_with_size_npct;


mk_lang_jumbo mk_lang_types_void_t mk_win_tstring_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_tstring_deinit(mk_lang_types_void_t) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_ansi_to_tstr_buff_sz_nofail(mk_win_base_pchar_lpct const ansi, mk_lang_types_sint_t const ansi_len_elements, mk_win_tstring_tchar_lpt const tstr, mk_lang_types_sint_t const tstr_len_elements) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_wide_to_tstr_buff_sz_nofail(mk_win_base_wchar_lpct const wide, mk_lang_types_sint_t const wide_len_elements, mk_win_tstring_tchar_lpt const tstr, mk_lang_types_sint_t const tstr_len_elements) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_ansi_to_tstr_buff_zt_nofail(mk_win_base_pchar_lpct const ansi, mk_win_tstring_tchar_lpt const tstr, mk_lang_types_sint_t const tstr_len_elements) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_wide_to_tstr_buff_zt_nofail(mk_win_base_wchar_lpct const wide, mk_win_tstring_tchar_lpt const tstr, mk_lang_types_sint_t const tstr_len_elements) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_pstr_with_size_t mk_win_tstring_tstr_to_ansi_sz_nofail(mk_win_tstring_tchar_lpct const tstr, mk_lang_types_sint_t const tstr_len_elements) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_wstr_with_size_t mk_win_tstring_tstr_to_wide_sz_nofail(mk_win_tstring_tchar_lpct const tstr, mk_lang_types_sint_t const tstr_len_elements) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_pstr_with_size_t mk_win_tstring_tstr_to_ansi_zt_nofail(mk_win_tstring_tchar_lpct const tstr) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_wstr_with_size_t mk_win_tstring_tstr_to_wide_zt_nofail(mk_win_tstring_tchar_lpct const tstr) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_asci_to_tstr_zt_nofail(mk_win_base_pchar_lpct const asci) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_ansi_to_tstr_zt_nofail(mk_win_base_pchar_lpct const ansi) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tstr_with_size_t mk_win_tstring_wide_to_tstr_zt_nofail(mk_win_base_wchar_lpct const wide) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpct mk_win_tstring_tstr_to_wnds_zt_nofail(mk_win_tstring_tchar_lpct const tstr) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_pchar_lpt mk_win_tstring_allocate_ansi_nofail(mk_lang_types_sint_t const ansi_len_elements) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_wchar_lpt mk_win_tstring_allocate_wide_nofail(mk_lang_types_sint_t const wide_len_elements) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_tstring.c"
#endif
#endif
