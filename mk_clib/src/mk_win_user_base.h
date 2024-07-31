#ifndef mk_include_guard_mk_win_user_base
#define mk_include_guard_mk_win_user_base


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_win_base_make_handle(mk_win_user_base_wnd)
mk_win_base_make_handle(mk_win_user_bitmap)
mk_win_base_make_handle(mk_win_user_brush)
mk_win_base_make_handle(mk_win_user_dc)
mk_win_base_make_handle(mk_win_user_font)


enum mk_win_user_base_color_id_e
{
	mk_win_user_base_color_id_e_scrollbar               = 0,
	mk_win_user_base_color_id_e_background              = 1,
	mk_win_user_base_color_id_e_activecaption           = 2,
	mk_win_user_base_color_id_e_inactivecaption         = 3,
	mk_win_user_base_color_id_e_menu                    = 4,
	mk_win_user_base_color_id_e_window                  = 5,
	mk_win_user_base_color_id_e_windowframe             = 6,
	mk_win_user_base_color_id_e_menutext                = 7,
	mk_win_user_base_color_id_e_windowtext              = 8,
	mk_win_user_base_color_id_e_captiontext             = 9,
	mk_win_user_base_color_id_e_activeborder            = 10,
	mk_win_user_base_color_id_e_inactiveborder          = 11,
	mk_win_user_base_color_id_e_appworkspace            = 12,
	mk_win_user_base_color_id_e_highlight               = 13,
	mk_win_user_base_color_id_e_highlighttext           = 14,
	mk_win_user_base_color_id_e_btnface                 = 15,
	mk_win_user_base_color_id_e_btnshadow               = 16,
	mk_win_user_base_color_id_e_graytext                = 17,
	mk_win_user_base_color_id_e_btntext                 = 18,
	mk_win_user_base_color_id_e_inactivecaptiontext     = 19,
	mk_win_user_base_color_id_e_btnhighlight            = 20,
	mk_win_user_base_color_id_e_3ddkshadow              = 21, /* winver >= 0x0400 */
	mk_win_user_base_color_id_e_3dlight                 = 22, /* winver >= 0x0400 */
	mk_win_user_base_color_id_e_infotext                = 23, /* winver >= 0x0400 */
	mk_win_user_base_color_id_e_infobk                  = 24, /* winver >= 0x0400 */
	mk_win_user_base_color_id_e_hotlight                = 26, /* winver >= 0x0500 */
	mk_win_user_base_color_id_e_gradientactivecaption   = 27, /* winver >= 0x0500 */
	mk_win_user_base_color_id_e_gradientinactivecaption = 28, /* winver >= 0x0500 */
	mk_win_user_base_color_id_e_menuhilight             = 29, /* winver >= 0x0501 */
	mk_win_user_base_color_id_e_menubar                 = 30, /* winver >= 0x0501 */
	mk_win_user_base_color_id_e_desktop                 = mk_win_user_base_color_id_e_background, /* winver >= 0x0400 */
	mk_win_user_base_color_id_e_3dface                  = mk_win_user_base_color_id_e_btnface, /* winver >= 0x0400 */
	mk_win_user_base_color_id_e_3dshadow                = mk_win_user_base_color_id_e_btnshadow, /* winver >= 0x0400 */
	mk_win_user_base_color_id_e_3dhighlight             = mk_win_user_base_color_id_e_btnhighlight, /* winver >= 0x0400 */
	mk_win_user_base_color_id_e_3dhilight               = mk_win_user_base_color_id_e_btnhighlight, /* winver >= 0x0400 */
	mk_win_user_base_color_id_e_btnhilight              = mk_win_user_base_color_id_e_btnhighlight, /* winver >= 0x0400 */
	mk_win_user_base_color_id_e_dummy_end
};
typedef enum mk_win_user_base_color_id_e mk_win_user_base_color_id_t;


typedef mk_win_base_ushort_t mk_win_user_base_atom_t;
typedef mk_win_user_base_atom_t const mk_win_user_base_atom_ct;
typedef mk_win_user_base_atom_t* mk_win_user_base_atom_pt;
typedef mk_win_user_base_atom_t const* mk_win_user_base_atom_pct;
typedef mk_win_user_base_atom_t mk_win_base_far* mk_win_user_base_atom_lpt;
typedef mk_win_user_base_atom_t mk_win_base_far const* mk_win_user_base_atom_lpct;
typedef mk_win_user_base_atom_t mk_win_base_near* mk_win_user_base_atom_npt;
typedef mk_win_user_base_atom_t mk_win_base_near const* mk_win_user_base_atom_npct;
typedef mk_win_user_base_atom_t* mk_lang_restrict mk_win_user_base_atom_prt;
typedef mk_win_user_base_atom_t const* mk_lang_restrict mk_win_user_base_atom_prct;
typedef mk_win_user_base_atom_t mk_win_base_far* mk_lang_restrict mk_win_user_base_atom_lprt;
typedef mk_win_user_base_atom_t mk_win_base_far const* mk_lang_restrict mk_win_user_base_atom_lprct;
typedef mk_win_user_base_atom_t mk_win_base_near* mk_lang_restrict mk_win_user_base_atom_nprt;
typedef mk_win_user_base_atom_t mk_win_base_near const* mk_lang_restrict mk_win_user_base_atom_nprct;

typedef mk_win_base_ssize_t mk_win_user_base_lresult_t;
typedef mk_win_user_base_lresult_t const mk_win_user_base_lresult_ct;
typedef mk_win_user_base_lresult_t* mk_win_user_base_lresult_pt;
typedef mk_win_user_base_lresult_t const* mk_win_user_base_lresult_pct;
typedef mk_win_user_base_lresult_t mk_win_base_far* mk_win_user_base_lresult_lpt;
typedef mk_win_user_base_lresult_t mk_win_base_far const* mk_win_user_base_lresult_lpct;
typedef mk_win_user_base_lresult_t mk_win_base_near* mk_win_user_base_lresult_npt;
typedef mk_win_user_base_lresult_t mk_win_base_near const* mk_win_user_base_lresult_npct;
typedef mk_win_user_base_lresult_t* mk_lang_restrict mk_win_user_base_lresult_prt;
typedef mk_win_user_base_lresult_t const* mk_lang_restrict mk_win_user_base_lresult_prct;
typedef mk_win_user_base_lresult_t mk_win_base_far* mk_lang_restrict mk_win_user_base_lresult_lprt;
typedef mk_win_user_base_lresult_t mk_win_base_far const* mk_lang_restrict mk_win_user_base_lresult_lprct;
typedef mk_win_user_base_lresult_t mk_win_base_near* mk_lang_restrict mk_win_user_base_lresult_nprt;
typedef mk_win_user_base_lresult_t mk_win_base_near const* mk_lang_restrict mk_win_user_base_lresult_nprct;

typedef mk_win_base_usize_t mk_win_user_base_wparam_t;
typedef mk_win_user_base_wparam_t const mk_win_user_base_wparam_ct;
typedef mk_win_user_base_wparam_t* mk_win_user_base_wparam_pt;
typedef mk_win_user_base_wparam_t const* mk_win_user_base_wparam_pct;
typedef mk_win_user_base_wparam_t mk_win_base_far* mk_win_user_base_wparam_lpt;
typedef mk_win_user_base_wparam_t mk_win_base_far const* mk_win_user_base_wparam_lpct;
typedef mk_win_user_base_wparam_t mk_win_base_near* mk_win_user_base_wparam_npt;
typedef mk_win_user_base_wparam_t mk_win_base_near const* mk_win_user_base_wparam_npct;
typedef mk_win_user_base_wparam_t* mk_lang_restrict mk_win_user_base_wparam_prt;
typedef mk_win_user_base_wparam_t const* mk_lang_restrict mk_win_user_base_wparam_prct;
typedef mk_win_user_base_wparam_t mk_win_base_far* mk_lang_restrict mk_win_user_base_wparam_lprt;
typedef mk_win_user_base_wparam_t mk_win_base_far const* mk_lang_restrict mk_win_user_base_wparam_lprct;
typedef mk_win_user_base_wparam_t mk_win_base_near* mk_lang_restrict mk_win_user_base_wparam_nprt;
typedef mk_win_user_base_wparam_t mk_win_base_near const* mk_lang_restrict mk_win_user_base_wparam_nprct;

typedef mk_win_base_ssize_t mk_win_user_base_lparam_t;
typedef mk_win_user_base_lparam_t const mk_win_user_base_lparam_ct;
typedef mk_win_user_base_lparam_t* mk_win_user_base_lparam_pt;
typedef mk_win_user_base_lparam_t const* mk_win_user_base_lparam_pct;
typedef mk_win_user_base_lparam_t mk_win_base_far* mk_win_user_base_lparam_lpt;
typedef mk_win_user_base_lparam_t mk_win_base_far const* mk_win_user_base_lparam_lpct;
typedef mk_win_user_base_lparam_t mk_win_base_near* mk_win_user_base_lparam_npt;
typedef mk_win_user_base_lparam_t mk_win_base_near const* mk_win_user_base_lparam_npct;
typedef mk_win_user_base_lparam_t* mk_lang_restrict mk_win_user_base_lparam_prt;
typedef mk_win_user_base_lparam_t const* mk_lang_restrict mk_win_user_base_lparam_prct;
typedef mk_win_user_base_lparam_t mk_win_base_far* mk_lang_restrict mk_win_user_base_lparam_lprt;
typedef mk_win_user_base_lparam_t mk_win_base_far const* mk_lang_restrict mk_win_user_base_lparam_lprct;
typedef mk_win_user_base_lparam_t mk_win_base_near* mk_lang_restrict mk_win_user_base_lparam_nprt;
typedef mk_win_user_base_lparam_t mk_win_base_near const* mk_lang_restrict mk_win_user_base_lparam_nprct;

typedef mk_win_base_dword_t mk_win_user_base_colorref_t;
typedef mk_win_user_base_colorref_t const mk_win_user_base_colorref_ct;
typedef mk_win_user_base_colorref_t* mk_win_user_base_colorref_pt;
typedef mk_win_user_base_colorref_t const* mk_win_user_base_colorref_pct;
typedef mk_win_user_base_colorref_t mk_win_base_far* mk_win_user_base_colorref_lpt;
typedef mk_win_user_base_colorref_t mk_win_base_far const* mk_win_user_base_colorref_lpct;
typedef mk_win_user_base_colorref_t mk_win_base_near* mk_win_user_base_colorref_npt;
typedef mk_win_user_base_colorref_t mk_win_base_near const* mk_win_user_base_colorref_npct;
typedef mk_win_user_base_colorref_t* mk_lang_restrict mk_win_user_base_colorref_prt;
typedef mk_win_user_base_colorref_t const* mk_lang_restrict mk_win_user_base_colorref_prct;
typedef mk_win_user_base_colorref_t mk_win_base_far* mk_lang_restrict mk_win_user_base_colorref_lprt;
typedef mk_win_user_base_colorref_t mk_win_base_far const* mk_lang_restrict mk_win_user_base_colorref_lprct;
typedef mk_win_user_base_colorref_t mk_win_base_near* mk_lang_restrict mk_win_user_base_colorref_nprt;
typedef mk_win_user_base_colorref_t mk_win_base_near const* mk_lang_restrict mk_win_user_base_colorref_nprct;

struct mk_win_user_base_ps_s
{
	mk_win_user_dc_t m_dc;
	mk_win_base_bool_t m_erase;
	mk_win_base_rect_t m_rect;
	mk_win_base_bool_t m_reserved_a;
	mk_win_base_bool_t m_reserved_b;
	mk_win_base_uchar_t m_reserved_c[32];
};
typedef struct mk_win_user_base_ps_s mk_win_user_base_ps_t;
typedef mk_win_user_base_ps_t const mk_win_user_base_ps_ct;
typedef mk_win_user_base_ps_t* mk_win_user_base_ps_pt;
typedef mk_win_user_base_ps_t const* mk_win_user_base_ps_pct;
typedef mk_win_user_base_ps_t mk_win_base_far* mk_win_user_base_ps_lpt;
typedef mk_win_user_base_ps_t mk_win_base_far const* mk_win_user_base_ps_lpct;
typedef mk_win_user_base_ps_t mk_win_base_near* mk_win_user_base_ps_npt;
typedef mk_win_user_base_ps_t mk_win_base_near const* mk_win_user_base_ps_npct;
typedef mk_win_user_base_ps_t* mk_lang_restrict mk_win_user_base_ps_prt;
typedef mk_win_user_base_ps_t const* mk_lang_restrict mk_win_user_base_ps_prct;
typedef mk_win_user_base_ps_t mk_win_base_far* mk_lang_restrict mk_win_user_base_ps_lprt;
typedef mk_win_user_base_ps_t mk_win_base_far const* mk_lang_restrict mk_win_user_base_ps_lprct;
typedef mk_win_user_base_ps_t mk_win_base_near* mk_lang_restrict mk_win_user_base_ps_nprt;
typedef mk_win_user_base_ps_t mk_win_base_near const* mk_lang_restrict mk_win_user_base_ps_nprct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_user_base_get_sys_color(mk_win_base_sint_t const color_idx) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_base.c"
#endif
#endif
