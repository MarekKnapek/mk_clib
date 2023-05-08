#ifndef mk_include_guard_lib_fe
#define mk_include_guard_lib_fe


#include "mk_lang_bool.h"
#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_kernel_files.h"
#include "mk_win_tstring.h"


enum mk_lib_fe_state_e
{
	mk_lib_fe_state_e_init,
	mk_lib_fe_state_e_roots,
	mk_lib_fe_state_e_folders,
	mk_lib_fe_state_e_err_path_not_found,
	mk_lib_fe_state_e_err_access_denied,
	mk_lib_fe_state_e_err_not_ready
};
typedef enum mk_lib_fe_state_e mk_lib_fe_state_t;


#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_lib_fe_s
{
	mk_lib_fe_state_t m_state;
	mk_win_base_dword_t m_drives_mask;
	int m_drives_count;
	mk_win_tstring_tchar_lpt m_str;
	mk_win_base_size_t m_str_capacity;
	int m_str_len;
	int m_addon_len;
	mk_win_base_uchar_lpt m_strs;
	mk_win_base_size_t m_strs_capacity;
	int m_strs_count;
	mk_win_base_uchar_lpt m_sort;
	mk_win_base_size_t m_sort_capacity;
	mk_win_base_sint_lpt m_breadcrumb;
	mk_win_base_size_t m_breadcrumb_capacity;
	int m_breadcrumb_cnt;
};
typedef struct mk_lib_fe_s mk_lib_fe_t;
typedef mk_lib_fe_t const mk_lib_fe_ct;
typedef mk_lib_fe_t* mk_lib_fe_pt;
typedef mk_lib_fe_t const* mk_lib_fe_pct;
typedef mk_lib_fe_t mk_win_base_far* mk_lib_fe_lpt;
typedef mk_lib_fe_t mk_win_base_far const* mk_lib_fe_lpct;
typedef mk_lib_fe_t mk_win_base_near* mk_lib_fe_npt;
typedef mk_lib_fe_t mk_win_base_near const* mk_lib_fe_npct;
#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(pop)
#endif


mk_lang_nodiscard mk_lang_jumbo mk_win_base_size_t mk_lib_fe_get_size(void) mk_lang_noexcept;
mk_lang_jumbo void mk_lib_fe_construct(mk_lib_fe_lpt const fe) mk_lang_noexcept;
mk_lang_jumbo void mk_lib_fe_destroy(mk_lib_fe_lpt const fe) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lib_fe_state_t mk_lib_fe_get_state(mk_lib_fe_lpct const fe) mk_lang_nodiscard;
mk_lang_jumbo void mk_lib_fe_go_to_root(mk_lib_fe_lpt const fe) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lib_fe_go_to_item(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_lib_fe_get_count(mk_lib_fe_lpt const fe) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_lib_fe_get_breadcrumb_depth(mk_lib_fe_lpt const fe) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_lib_fe_get_breadcrumb_value(mk_lib_fe_lpt const fe) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tchar_lpct mk_lib_fe_get_name_short_str(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_lib_fe_get_name_short_str_len(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tchar_lpct mk_lib_fe_get_name_long_str(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tchar_lpct mk_lib_fe_get_type_str(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_tstring_tchar_lpct mk_lib_fe_get_detail_str(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lib_fe_has_attributes(mk_lib_fe_lpct const fe, int const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_kernel_files_attribute_t mk_lib_fe_get_attributes(mk_lib_fe_lpct const fe, int const idx) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_fe.c"
#endif
#endif
