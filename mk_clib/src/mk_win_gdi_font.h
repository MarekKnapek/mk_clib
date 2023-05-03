#ifndef mk_include_guard_win_gdi_font
#define mk_include_guard_win_gdi_font


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


#define mk_win_gdi_font_face_size 32


struct mk_win_gdi_font_a_s
{
	mk_win_base_slong_t m_height;
	mk_win_base_slong_t m_width;
	mk_win_base_slong_t m_escapement;
	mk_win_base_slong_t m_orientation;
	mk_win_base_slong_t m_weight;
	mk_win_base_uchar_t m_italic;
	mk_win_base_uchar_t m_underline;
	mk_win_base_uchar_t m_strikeout;
	mk_win_base_uchar_t m_charset;
	mk_win_base_uchar_t m_outprecision;
	mk_win_base_uchar_t m_clipprecision;
	mk_win_base_uchar_t m_quality;
	mk_win_base_uchar_t m_pitchandfamily;
	mk_win_base_pchar_t m_facename[mk_win_gdi_font_face_size];
};
typedef struct mk_win_gdi_font_a_s mk_win_gdi_font_a_t;
typedef mk_win_gdi_font_a_t const mk_win_gdi_font_a_ct;
typedef mk_win_gdi_font_a_t* mk_win_gdi_font_a_pt;
typedef mk_win_gdi_font_a_t const* mk_win_gdi_font_a_pct;
typedef mk_win_gdi_font_a_t mk_win_base_far* mk_win_gdi_font_a_lpt;
typedef mk_win_gdi_font_a_t mk_win_base_far const* mk_win_gdi_font_a_lpct;
typedef mk_win_gdi_font_a_t mk_win_base_near* mk_win_gdi_font_a_npt;
typedef mk_win_gdi_font_a_t mk_win_base_near const* mk_win_gdi_font_a_npct;

struct mk_win_gdi_font_w_s
{
	mk_win_base_slong_t m_height;
	mk_win_base_slong_t m_width;
	mk_win_base_slong_t m_escapement;
	mk_win_base_slong_t m_orientation;
	mk_win_base_slong_t m_weight;
	mk_win_base_uchar_t m_italic;
	mk_win_base_uchar_t m_underline;
	mk_win_base_uchar_t m_strikeout;
	mk_win_base_uchar_t m_charset;
	mk_win_base_uchar_t m_outprecision;
	mk_win_base_uchar_t m_clipprecision;
	mk_win_base_uchar_t m_quality;
	mk_win_base_uchar_t m_pitchandfamily;
	mk_win_base_wchar_t m_facename[mk_win_gdi_font_face_size];
};
typedef struct mk_win_gdi_font_w_s mk_win_gdi_font_w_t;
typedef mk_win_gdi_font_w_t const mk_win_gdi_font_w_ct;
typedef mk_win_gdi_font_w_t* mk_win_gdi_font_w_pt;
typedef mk_win_gdi_font_w_t const* mk_win_gdi_font_w_pct;
typedef mk_win_gdi_font_w_t mk_win_base_far* mk_win_gdi_font_w_lpt;
typedef mk_win_gdi_font_w_t mk_win_base_far const* mk_win_gdi_font_w_lpct;
typedef mk_win_gdi_font_w_t mk_win_base_near* mk_win_gdi_font_w_npt;
typedef mk_win_gdi_font_w_t mk_win_base_near const* mk_win_gdi_font_w_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_gdi_font_a_create_indirect(mk_win_gdi_font_a_lpct const font) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_gdi_font_w_create_indirect(mk_win_gdi_font_w_lpct const font) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_gdi_font_t_create_indirect(mk_win_base_void_lpct const font) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_gdi_font.c"
#endif
#endif
