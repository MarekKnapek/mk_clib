#ifndef mk_include_guard_win_gdi_bitmap
#define mk_include_guard_win_gdi_bitmap


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_gdi_dc.h"


enum mk_win_gdi_bitmap_rop_e
{
	mk_win_gdi_bitmap_rop_e_blackness      = 0x00000042ul,
	mk_win_gdi_bitmap_rop_e_notsrcerase    = 0x001100a6ul,
	mk_win_gdi_bitmap_rop_e_notsrccopy     = 0x00330008ul,
	mk_win_gdi_bitmap_rop_e_srcerase       = 0x00440328ul,
	mk_win_gdi_bitmap_rop_e_dstinvert      = 0x00550009ul,
	mk_win_gdi_bitmap_rop_e_patinvert      = 0x005a0049ul,
	mk_win_gdi_bitmap_rop_e_srcinvert      = 0x00660046ul,
	mk_win_gdi_bitmap_rop_e_srcand         = 0x008800c6ul,
	mk_win_gdi_bitmap_rop_e_mergepaint     = 0x00bb0226ul,
	mk_win_gdi_bitmap_rop_e_mergecopy      = 0x00c000caul,
	mk_win_gdi_bitmap_rop_e_srccopy        = 0x00cc0020ul,
	mk_win_gdi_bitmap_rop_e_srcpaint       = 0x00ee0086ul,
	mk_win_gdi_bitmap_rop_e_patcopy        = 0x00f00021ul,
	mk_win_gdi_bitmap_rop_e_patpaint       = 0x00fb0a09ul,
	mk_win_gdi_bitmap_rop_e_whiteness      = 0x00ff0062ul,
	mk_win_gdi_bitmap_rop_e_captureblt     = 0x40000000ul, /* winver >= 0x0500 */
	mk_win_gdi_bitmap_rop_e_nomirrorbitmap = 0x80000000ul, /* winver >= 0x0500 */
	mk_win_gdi_bitmap_rop_e_dummy_end = 0
};
typedef enum mk_win_gdi_bitmap_rop_e mk_win_gdi_bitmap_rop_t;


struct mk_win_gdi_handle_bitmap_s; typedef struct mk_win_gdi_handle_bitmap_s mk_win_gdi_handle_bitmap_t; typedef mk_win_gdi_handle_bitmap_t const* mk_win_gdi_bitmap_t;
typedef mk_win_gdi_bitmap_t const mk_win_gdi_bitmap_ct;
typedef mk_win_gdi_bitmap_t* mk_win_gdi_bitmap_pt;
typedef mk_win_gdi_bitmap_t const* mk_win_gdi_bitmap_pct;
typedef mk_win_gdi_bitmap_t mk_win_base_far* mk_win_gdi_bitmap_lpt;
typedef mk_win_gdi_bitmap_t mk_win_base_far const* mk_win_gdi_bitmap_lpct;
typedef mk_win_gdi_bitmap_t mk_win_base_near* mk_win_gdi_bitmap_npt;
typedef mk_win_gdi_bitmap_t mk_win_base_near const* mk_win_gdi_bitmap_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_bitmap_t mk_win_gdi_bitmap_create_compatible(mk_win_gdi_dc_t const dc, int const width, int const height) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_bitmap_bitblt(mk_win_gdi_dc_t const dc, int const x, int const y, int const width, int const height, mk_win_gdi_dc_t const src, int const xsrc, int const ysrc, mk_win_gdi_bitmap_rop_t const rop) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_gdi_bitmap.c"
#endif
#endif
