#ifndef mk_include_guard_win_gdi_object
#define mk_include_guard_win_gdi_object


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


enum mk_win_gdi_object_stock_id_e
{
	mk_win_gdi_object_stock_id_e_white_brush         =  0,
	mk_win_gdi_object_stock_id_e_ltgray_brush        =  1,
	mk_win_gdi_object_stock_id_e_gray_brush          =  2,
	mk_win_gdi_object_stock_id_e_dkgray_brush        =  3,
	mk_win_gdi_object_stock_id_e_black_brush         =  4,
	mk_win_gdi_object_stock_id_e_null_brush          =  5,
	mk_win_gdi_object_stock_id_e_white_pen           =  6,
	mk_win_gdi_object_stock_id_e_black_pen           =  7,
	mk_win_gdi_object_stock_id_e_null_pen            =  8,
	mk_win_gdi_object_stock_id_e_oem_fixed_font      = 10,
	mk_win_gdi_object_stock_id_e_ansi_fixed_font     = 11,
	mk_win_gdi_object_stock_id_e_ansi_var_font       = 12,
	mk_win_gdi_object_stock_id_e_system_font         = 13,
	mk_win_gdi_object_stock_id_e_device_default_font = 14,
	mk_win_gdi_object_stock_id_e_default_palette     = 15,
	mk_win_gdi_object_stock_id_e_system_fixed_font   = 16,
	mk_win_gdi_object_stock_id_e_default_gui_font    = 17, /* winver >= 0x0400 */
	mk_win_gdi_object_stock_id_e_dc_brush            = 18, /* _win32_winnt >= _win32_winnt_win2k */
	mk_win_gdi_object_stock_id_e_dc_pen              = 19, /* _win32_winnt >= _win32_winnt_win2k */
	mk_win_gdi_object_stock_id_e_hollow_brush        = mk_win_gdi_object_stock_id_e_null_brush,
	mk_win_gdi_object_stock_id_e_dummy_end = 0
};
typedef enum mk_win_gdi_object_stock_id_e mk_win_gdi_object_stock_id_t;


struct mk_win_gdi_handle_object_s; typedef struct mk_win_gdi_handle_object_s mk_win_gdi_handle_object_t; typedef mk_win_gdi_handle_object_t const* mk_win_gdi_object_t;
typedef mk_win_gdi_object_t const mk_win_gdi_object_ct;
typedef mk_win_gdi_object_t* mk_win_gdi_object_pt;
typedef mk_win_gdi_object_t const* mk_win_gdi_object_pct;
typedef mk_win_gdi_object_t mk_win_base_far* mk_win_gdi_object_lpt;
typedef mk_win_gdi_object_t mk_win_base_far const* mk_win_gdi_object_lpct;
typedef mk_win_gdi_object_t mk_win_base_near* mk_win_gdi_object_npt;
typedef mk_win_gdi_object_t mk_win_base_near const* mk_win_gdi_object_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_object_t mk_win_gdi_object_get_stock(mk_win_gdi_object_stock_id_t const id) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_object_delete(mk_win_gdi_object_t const object) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_gdi_object.c"
#endif
#endif
