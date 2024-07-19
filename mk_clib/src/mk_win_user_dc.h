#ifndef mk_include_guard_mk_win_user_dc
#define mk_include_guard_mk_win_user_dc


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"


mk_win_base_make_handle(mk_win_user_base_gdi_obj)


enum mk_win_user_dc_flag_e
{
	mk_win_user_dc_flag_e_left                 = 0x00000000ul,
	mk_win_user_dc_flag_e_center               = 0x00000001ul,
	mk_win_user_dc_flag_e_right                = 0x00000002ul,
	mk_win_user_dc_flag_e_vcenter              = 0x00000004ul,
	mk_win_user_dc_flag_e_bottom               = 0x00000008ul,
	mk_win_user_dc_flag_e_wordbreak            = 0x00000010ul,
	mk_win_user_dc_flag_e_singleline           = 0x00000020ul,
	mk_win_user_dc_flag_e_expandtabs           = 0x00000040ul,
	mk_win_user_dc_flag_e_tabstop              = 0x00000080ul,
	mk_win_user_dc_flag_e_noclip               = 0x00000100ul,
	mk_win_user_dc_flag_e_externalleading      = 0x00000200ul,
	mk_win_user_dc_flag_e_calcrect             = 0x00000400ul,
	mk_win_user_dc_flag_e_noprefix             = 0x00000800ul,
	mk_win_user_dc_flag_e_internal             = 0x00001000ul,
	mk_win_user_dc_flag_e_editcontrol          = 0x00002000ul, /* winver >= 0x0400 */
	mk_win_user_dc_flag_e_path_ellipsis        = 0x00004000ul, /* winver >= 0x0400 */
	mk_win_user_dc_flag_e_end_ellipsis         = 0x00008000ul, /* winver >= 0x0400 */
	mk_win_user_dc_flag_e_modifystring         = 0x00010000ul, /* winver >= 0x0400 */
	mk_win_user_dc_flag_e_rtlreading           = 0x00020000ul, /* winver >= 0x0400 */
	mk_win_user_dc_flag_e_word_ellipsis        = 0x00040000ul, /* winver >= 0x0400 */
	mk_win_user_dc_flag_e_nofullwidthcharbreak = 0x00080000ul, /* winver >= 0x0500 */
	mk_win_user_dc_flag_e_hideprefix           = 0x00100000ul, /* _win32_winnt >= 0x0500 */
	mk_win_user_dc_flag_e_prefixonly           = 0x00200000ul, /* _win32_winnt >= 0x0500 */
	mk_win_user_dc_flag_e_dummy_end
};
typedef enum mk_win_user_dc_flag_e mk_win_user_dc_flag_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_user_dc_t mk_win_user_dc_create_compatible(mk_win_user_dc_t const dc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_colorref_t mk_win_user_dc_set_text_color(mk_win_user_dc_t const dc, mk_win_user_base_colorref_t const color) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_colorref_t mk_win_user_dc_set_bk_color(mk_win_user_dc_t const dc, mk_win_user_base_colorref_t const color) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_dc_delete(mk_win_user_dc_t const dc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_user_dc_draw_text_w(mk_win_user_dc_t const dc, mk_win_base_wchar_lpct const text, mk_win_base_sint_t const len, mk_win_base_rect_lpt const rect, mk_win_base_uint_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_user_dc_fill_rect(mk_win_user_dc_t const dc, mk_win_base_rect_lpct const rect, mk_win_user_brush_t const brush) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_bitmap_t mk_win_user_dc_select_bitmap(mk_win_user_dc_t const dc, mk_win_user_bitmap_t const bitmap) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_bitmap_t mk_win_user_bitmap_create_compatible(mk_win_user_dc_t const dc, mk_win_base_sint_t const width, mk_win_base_sint_t const height) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_gdi_obj_delete(mk_win_user_base_gdi_obj_t const gdi_obj) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t bitblast(mk_win_user_dc_t const dst, mk_win_base_sint_t const dst_x, mk_win_base_sint_t const dst_y, mk_win_base_sint_t const width, mk_win_base_sint_t const height, mk_win_user_dc_t const src, mk_win_base_sint_t const src_x, mk_win_base_sint_t const src_y, mk_win_base_dword_t const rop) mk_lang_noexcept;


enum bitblast_rop_e
{
	bitblast_rop_e_blackness      = ((mk_win_base_dword_t)(0x00000042ul)),
	bitblast_rop_e_notsrcerase    = ((mk_win_base_dword_t)(0x001100a6ul)),
	bitblast_rop_e_notsrccopy     = ((mk_win_base_dword_t)(0x00330008ul)),
	bitblast_rop_e_srcerase       = ((mk_win_base_dword_t)(0x00440328ul)),
	bitblast_rop_e_dstinvert      = ((mk_win_base_dword_t)(0x00550009ul)),
	bitblast_rop_e_patinvert      = ((mk_win_base_dword_t)(0x005a0049ul)),
	bitblast_rop_e_srcinvert      = ((mk_win_base_dword_t)(0x00660046ul)),
	bitblast_rop_e_srcand         = ((mk_win_base_dword_t)(0x008800c6ul)),
	bitblast_rop_e_mergepaint     = ((mk_win_base_dword_t)(0x00bb0226ul)),
	bitblast_rop_e_mergecopy      = ((mk_win_base_dword_t)(0x00c000caul)),
	bitblast_rop_e_srccopy        = ((mk_win_base_dword_t)(0x00cc0020ul)),
	bitblast_rop_e_srcpaint       = ((mk_win_base_dword_t)(0x00ee0086ul)),
	bitblast_rop_e_patcopy        = ((mk_win_base_dword_t)(0x00f00021ul)),
	bitblast_rop_e_patpaint       = ((mk_win_base_dword_t)(0x00fb0a09ul)),
	bitblast_rop_e_whiteness      = ((mk_win_base_dword_t)(0x00ff0062ul)),
	bitblast_rop_e_captureblt     = ((mk_win_base_dword_t)(0x40000000ul)), /* winver >= 0x0500 */
	bitblast_rop_e_nomirrorbitmap = ((mk_win_base_dword_t)(0x80000000ul)), /* winver >= 0x0500 */
	bitblast_rop_e_dummy_end
};
typedef enum bitblast_rop_e bitblast_rop_t;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_dc.c"
#endif
#endif
