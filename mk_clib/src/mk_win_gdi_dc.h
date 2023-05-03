#ifndef mk_include_guard_win_gdi_dc
#define mk_include_guard_win_gdi_dc


#include "mk_win_user_brush.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_gdi_object.h"


enum mk_win_gdi_dc_bk_mode_e
{
	mk_win_gdi_dc_bk_mode_e_transparent = 1,
	mk_win_gdi_dc_bk_mode_e_opaque      = 2,
	mk_win_gdi_dc_bk_mode_e_dummy_end = 0
};
typedef enum mk_win_gdi_dc_bk_mode_e mk_win_gdi_dc_bk_mode_t;


struct mk_win_gdi_handle_dc_s; typedef struct mk_win_gdi_handle_dc_s mk_win_gdi_handle_dc_t; typedef mk_win_gdi_handle_dc_t const* mk_win_gdi_dc_t;
typedef mk_win_gdi_dc_t const mk_win_gdi_dc_ct;
typedef mk_win_gdi_dc_t* mk_win_gdi_dc_pt;
typedef mk_win_gdi_dc_t const* mk_win_gdi_dc_pct;
typedef mk_win_gdi_dc_t mk_win_base_far* mk_win_gdi_dc_lpt;
typedef mk_win_gdi_dc_t mk_win_base_far const* mk_win_gdi_dc_lpct;
typedef mk_win_gdi_dc_t mk_win_base_near* mk_win_gdi_dc_npt;
typedef mk_win_gdi_dc_t mk_win_base_near const* mk_win_gdi_dc_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_dc_t mk_win_gdi_dc_create_compatible(mk_win_gdi_dc_t const dc) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_delete(mk_win_gdi_dc_t const dc) mk_lang_noexcept;
mk_lang_jumbo mk_win_gdi_object_t mk_win_gdi_dc_select_object(mk_win_gdi_dc_t const dc, mk_win_gdi_object_t const object) mk_lang_noexcept;
mk_lang_jumbo mk_win_gdi_dc_bk_mode_t mk_win_gdi_dc_set_bk_mode(mk_win_gdi_dc_t const dc, mk_win_gdi_dc_bk_mode_t const mode) mk_lang_noexcept;
mk_lang_jumbo int mk_win_gdi_dc_fill_rect(mk_win_gdi_dc_t const dc, mk_win_base_rect_lpct const rect, mk_win_user_brush_t const brush) mk_lang_noexcept;
mk_lang_jumbo int mk_win_gdi_dc_frame_rect(mk_win_gdi_dc_t const dc, mk_win_base_rect_lpct const rect, mk_win_user_brush_t const brush) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_gdi_dc.c"
#endif
#endif
