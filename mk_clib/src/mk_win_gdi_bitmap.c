#include "mk_win_gdi_bitmap.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_gdi_dc.h"


mk_win_base_dll_import mk_win_gdi_bitmap_t mk_win_base_stdcall CreateCompatibleBitmap(mk_win_gdi_dc_t, int, int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall BitBlt(mk_win_gdi_dc_t, int, int, int, int, mk_win_gdi_dc_t, int, int, mk_win_base_dword_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_bitmap_t mk_win_gdi_bitmap_create_compatible(mk_win_gdi_dc_t const dc, int const width, int const height) mk_lang_noexcept
{
	mk_win_gdi_bitmap_t bm;

	bm = CreateCompatibleBitmap(dc, width, height);
	return bm;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_bitmap_bitblt(mk_win_gdi_dc_t const dc, int const x, int const y, int const width, int const height, mk_win_gdi_dc_t const src, int const xsrc, int const ysrc, mk_win_gdi_bitmap_rop_t const rop) mk_lang_noexcept
{
	mk_win_base_bool_t blted;

	blted = BitBlt(dc, x, y, width, height, src, xsrc, ysrc, ((mk_win_base_dword_t)(rop)));
	return blted;
}
