#ifndef include_guard_mk_lib_fe
#define include_guard_mk_lib_fe


#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_kernel_files.h"
#include "mk_win_tstring.h"


enum mk_lib_fe_state_e;
typedef enum mk_lib_fe_state_e mk_lib_fe_state_t;

struct mk_lib_fe_s;
typedef struct mk_lib_fe_s mk_lib_fe_t;
typedef mk_lib_fe_t const mk_lib_fe_ct;
typedef mk_lib_fe_t* mk_lib_fe_pt;
typedef mk_lib_fe_t const* mk_lib_fe_pct;
typedef mk_lib_fe_t mk_win_base_far* mk_lib_fe_lpt;
typedef mk_lib_fe_t mk_win_base_far const* mk_lib_fe_lpct;
typedef mk_lib_fe_t mk_win_base_near* mk_lib_fe_npt;
typedef mk_lib_fe_t mk_win_base_near const* mk_lib_fe_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_size_t mk_lib_fe_get_size(void) mk_lang_noexcept;
mk_lang_jumbo void mk_lib_fe_construct(mk_lib_fe_lpt const fe) mk_lang_noexcept;
mk_lang_jumbo void mk_lib_fe_destroy(mk_lib_fe_lpt const fe) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lib_fe_state_t mk_lib_fe_get_state(mk_lib_fe_lpct const fe) mk_lang_nodiscard;
mk_lang_jumbo void mk_lib_fe_go_to_root(mk_lib_fe_lpt const fe) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lib_fe_go_to_item(mk_lib_fe_lpt const fe, int const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lib_fe_go_up(mk_lib_fe_lpt const fe) mk_lang_noexcept;
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
