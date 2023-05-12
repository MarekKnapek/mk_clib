#ifndef include_guard_mk_win_gdi_dc
#define include_guard_mk_win_gdi_dc


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_gdi_object.h"
#include "mk_win_tstring.h"
#include "mk_win_user_brush.h"


enum mk_win_gdi_dc_bk_mode_e
{
	mk_win_gdi_dc_bk_mode_e_transparent = 1,
	mk_win_gdi_dc_bk_mode_e_opaque      = 2,
	mk_win_gdi_dc_bk_mode_e_dummy_end = 0
};
typedef enum mk_win_gdi_dc_bk_mode_e mk_win_gdi_dc_bk_mode_t;

enum mk_win_gdi_dc_ext_text_out_options_e
{
	mk_win_gdi_dc_ext_text_out_options_e_none = 0,
	mk_win_gdi_dc_ext_text_out_options_e_opaque            =     0x0002ul,
	mk_win_gdi_dc_ext_text_out_options_e_clipped           =     0x0004ul,
	mk_win_gdi_dc_ext_text_out_options_e_glyph_index       =     0x0010ul, /* winver >= 0x0400 */
	mk_win_gdi_dc_ext_text_out_options_e_rtlreading        =     0x0080ul, /* winver >= 0x0400 */
	mk_win_gdi_dc_ext_text_out_options_e_numericslocal     =     0x0400ul, /* winver >= 0x0400 */
	mk_win_gdi_dc_ext_text_out_options_e_numericslatin     =     0x0800ul, /* winver >= 0x0400 */
	mk_win_gdi_dc_ext_text_out_options_e_ignorelanguage    =     0x1000ul, /* winver >= 0x0400 */
	mk_win_gdi_dc_ext_text_out_options_e_pdy               =     0x2000ul, /* win32_winnt >= win32_winnt_win2k */
	mk_win_gdi_dc_ext_text_out_options_e_reverse_index_map = 0x00010000ul, /* win32_winnt >= win32_winnt_longhorn */
	mk_win_gdi_dc_ext_text_out_options_e_dummy_end = 0
};
typedef enum mk_win_gdi_dc_ext_text_out_options_e mk_win_gdi_dc_ext_text_out_options_t;


struct mk_win_gdi_handle_dc_s; typedef struct mk_win_gdi_handle_dc_s mk_win_gdi_handle_dc_t; typedef mk_win_gdi_handle_dc_t const* mk_win_gdi_dc_t;
typedef mk_win_gdi_dc_t const mk_win_gdi_dc_ct;
typedef mk_win_gdi_dc_t* mk_win_gdi_dc_pt;
typedef mk_win_gdi_dc_t const* mk_win_gdi_dc_pct;
typedef mk_win_gdi_dc_t mk_win_base_far* mk_win_gdi_dc_lpt;
typedef mk_win_gdi_dc_t mk_win_base_far const* mk_win_gdi_dc_lpct;
typedef mk_win_gdi_dc_t mk_win_base_near* mk_win_gdi_dc_npt;
typedef mk_win_gdi_dc_t mk_win_base_near const* mk_win_gdi_dc_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_a_get_text_extent_point_32(mk_win_gdi_dc_t const dc, mk_win_base_pchar_lpct const text, int const text_len, mk_win_base_sizer_lpt const size) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_a_ext_text_out(mk_win_gdi_dc_t const dc, int const x, int const y, mk_win_gdi_dc_ext_text_out_options_t const options, mk_win_base_rect_lpct const rect, mk_win_base_pchar_lpct const text, int const text_len, mk_win_base_sint_lpct const dx) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_w_get_text_extent_point_32(mk_win_gdi_dc_t const dc, mk_win_base_wchar_lpct const text, int const text_len, mk_win_base_sizer_lpt const size) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_w_ext_text_out(mk_win_gdi_dc_t const dc, int const x, int const y, mk_win_gdi_dc_ext_text_out_options_t const options, mk_win_base_rect_lpct const rect, mk_win_base_wchar_lpct const text, int const text_len, mk_win_base_sint_lpct const dx) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_t_get_text_extent_point_32(mk_win_gdi_dc_t const dc, mk_win_tstring_tchar_lpct const text, int const text_len, mk_win_base_sizer_lpt const size) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_t_ext_text_out(mk_win_gdi_dc_t const dc, int const x, int const y, mk_win_gdi_dc_ext_text_out_options_t const options, mk_win_base_rect_lpct const rect, mk_win_tstring_tchar_lpct const text, int const text_len, mk_win_base_sint_lpct const dx) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_dc_t mk_win_gdi_dc_create_compatible(mk_win_gdi_dc_t const dc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_delete(mk_win_gdi_dc_t const dc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_object_t mk_win_gdi_dc_select_object(mk_win_gdi_dc_t const dc, mk_win_gdi_object_t const object) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_dc_bk_mode_t mk_win_gdi_dc_set_bk_mode(mk_win_gdi_dc_t const dc, mk_win_gdi_dc_bk_mode_t const mode) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_gdi_dc_fill_rect(mk_win_gdi_dc_t const dc, mk_win_base_rect_lpct const rect, mk_win_user_brush_t const brush) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_gdi_dc_frame_rect(mk_win_gdi_dc_t const dc, mk_win_base_rect_lpct const rect, mk_win_user_brush_t const brush) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_dc_draw_focus_rect(mk_win_gdi_dc_t const dc, mk_win_base_rect_lpct const rect) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_gdi_dc_set_text_color(mk_win_gdi_dc_t const dc, mk_win_base_dword_t const color) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_gdi_dc_set_background_color(mk_win_gdi_dc_t const dc, mk_win_base_dword_t const color) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_gdi_dc.c"
#endif
#endif
