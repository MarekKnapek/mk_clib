#ifndef mk_include_guard_win_user_dialog
#define mk_include_guard_win_user_dialog


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"
#include "mk_win_user_window.h"


#define mk_win_user_dialog_size_check_h 10
#define mk_win_user_dialog_size_combo 14
#define mk_win_user_dialog_size_button_w 50
#define mk_win_user_dialog_size_button_h 14
#define mk_win_user_dialog_size_link1_h 25
#define mk_win_user_dialog_size_link2_h 35
#define mk_win_user_dialog_size_list_h 14
#define mk_win_user_dialog_size_progressa_w 107
#define mk_win_user_dialog_size_progressb_w 237
#define mk_win_user_dialog_size_progress_h 8
#define mk_win_user_dialog_size_radio_h 10
#define mk_win_user_dialog_size_slider_h 15
#define mk_win_user_dialog_size_static_h 8
#define mk_win_user_dialog_size_edit1_h 14
#define mk_win_user_dialog_size_edit2_h 10

#define mk_win_user_dialog_space_dlg_margin 7
#define mk_win_user_dialog_space_label_ctrl 3
#define mk_win_user_dialog_space_related_ctrl 4
#define mk_win_user_dialog_space_unrelated_ctrl 7
#define mk_win_user_dialog_space_box_first 11
#define mk_win_user_dialog_space_box_ctrl 4
#define mk_win_user_dialog_space_buttons 4
#define mk_win_user_dialog_space_box_last 7
#define mk_win_user_dialog_space_box_left 6
#define mk_win_user_dialog_space_label_down 3
#define mk_win_user_dialog_space_paragraphs 7
#define mk_win_user_dialog_space_smallest_interactive 3
#define mk_win_user_dialog_space_smallest_noninteractive 2

#define mk_win_user_dialog_class_is_atom 0xffff
#define mk_win_user_dialog_class_id_button 0x0080
#define mk_win_user_dialog_class_id_edit 0x0081
#define mk_win_user_dialog_class_id_static 0x0082
#define mk_win_user_dialog_class_id_listbox 0x0083
#define mk_win_user_dialog_class_id_scrollbar 0x0084
#define mk_win_user_dialog_class_id_combobox 0x0085

enum mk_win_user_dialog_style_e
{
	mk_win_user_dialog_style_e_absalign      = 0x0001ul,
	mk_win_user_dialog_style_e_sysmodal      = 0x0002ul,
	mk_win_user_dialog_style_e_3dlook        = 0x0004ul, /* winver >= 0x0400 */
	mk_win_user_dialog_style_e_fixedsys      = 0x0008ul, /* winver >= 0x0400 */
	mk_win_user_dialog_style_e_nofailcreate  = 0x0010ul, /* winver >= 0x0400 */
	mk_win_user_dialog_style_e_localedit     = 0x0020ul,
	mk_win_user_dialog_style_e_setfont       = 0x0040ul,
	mk_win_user_dialog_style_e_modalframe    = 0x0080ul,
	mk_win_user_dialog_style_e_noidlemsg     = 0x0100ul,
	mk_win_user_dialog_style_e_setforeground = 0x0200ul, /* not in win3.1 */
	mk_win_user_dialog_style_e_control       = 0x0400ul, /* winver >= 0x0400 */
	mk_win_user_dialog_style_e_center        = 0x0800ul, /* winver >= 0x0400 */
	mk_win_user_dialog_style_e_centermouse   = 0x1000ul, /* winver >= 0x0400 */
	mk_win_user_dialog_style_e_contexthelp   = 0x2000ul, /* winver >= 0x0400 */
	mk_win_user_dialog_style_e_usepixels     = 0x8000ul, /* _win32_wce && _win32_wce >= 0x0500 */
	mk_win_user_dialog_style_e_shellfont     = (mk_win_user_dialog_style_e_fixedsys | mk_win_user_dialog_style_e_setfont), /* winver >= 0x0400 */
	mk_win_user_dialog_style_e_dummy_end = 0
};
typedef enum mk_win_user_dialog_style_e mk_win_user_dialog_style_t;

enum mk_win_user_dialog_font_weight_e
{
	mk_win_user_dialog_font_weight_e_dontcare   = 0,
	mk_win_user_dialog_font_weight_e_thin       = 100,
	mk_win_user_dialog_font_weight_e_extralight = 200,
	mk_win_user_dialog_font_weight_e_light      = 300,
	mk_win_user_dialog_font_weight_e_normal     = 400,
	mk_win_user_dialog_font_weight_e_medium     = 500,
	mk_win_user_dialog_font_weight_e_semibold   = 600,
	mk_win_user_dialog_font_weight_e_bold       = 700,
	mk_win_user_dialog_font_weight_e_extrabold  = 800,
	mk_win_user_dialog_font_weight_e_heavy      = 900,
	mk_win_user_dialog_font_weight_e_ultralight = mk_win_user_dialog_font_weight_e_extralight,
	mk_win_user_dialog_font_weight_e_regular    = mk_win_user_dialog_font_weight_e_normal,
	mk_win_user_dialog_font_weight_e_demibold   = mk_win_user_dialog_font_weight_e_semibold,
	mk_win_user_dialog_font_weight_e_ultrabold  = mk_win_user_dialog_font_weight_e_extrabold,
	mk_win_user_dialog_font_weight_e_black      = mk_win_user_dialog_font_weight_e_heavy,
	mk_win_user_dialog_font_weight_e_dummy_end = 0
};
typedef enum mk_win_user_dialog_font_weight_e mk_win_user_dialog_font_weight_t;

enum mk_win_user_dialog_font_charset_e
{
	mk_win_user_dialog_font_charset_e_ansi        = 0, 
	mk_win_user_dialog_font_charset_e_default     = 1, 
	mk_win_user_dialog_font_charset_e_symbol      = 2, 
	mk_win_user_dialog_font_charset_e_mac         = 77, /* winver >= 0x0400 */
	mk_win_user_dialog_font_charset_e_shiftjis    = 128, 
	mk_win_user_dialog_font_charset_e_hangeul     = 129, 
	mk_win_user_dialog_font_charset_e_hangul      = 129, 
	mk_win_user_dialog_font_charset_e_johab       = 130, /* winver >= 0x0400 */
	mk_win_user_dialog_font_charset_e_gb2312      = 134, 
	mk_win_user_dialog_font_charset_e_chinesebig5 = 136, 
	mk_win_user_dialog_font_charset_e_greek       = 161, /* winver >= 0x0400 */
	mk_win_user_dialog_font_charset_e_turkish     = 162, /* winver >= 0x0400 */
	mk_win_user_dialog_font_charset_e_vietnamese  = 163, /* winver >= 0x0400 */
	mk_win_user_dialog_font_charset_e_hebrew      = 177, /* winver >= 0x0400 */
	mk_win_user_dialog_font_charset_e_arabic      = 178, /* winver >= 0x0400 */
	mk_win_user_dialog_font_charset_e_baltic      = 186, /* winver >= 0x0400 */
	mk_win_user_dialog_font_charset_e_russian     = 204, /* winver >= 0x0400 */
	mk_win_user_dialog_font_charset_e_thai        = 222, /* winver >= 0x0400 */
	mk_win_user_dialog_font_charset_e_easteurope  = 238, /* winver >= 0x0400 */
	mk_win_user_dialog_font_charset_e_oem         = 255, 
	mk_win_user_dialog_font_charset_e_dummy_end = 0
};
typedef enum mk_win_user_dialog_font_charset_e mk_win_user_dialog_font_charset_t;

enum mk_win_user_dialog_messagebox_e
{
	mk_win_user_dialog_messagebox_e_ok                        = 0x00000000ul,
	mk_win_user_dialog_messagebox_e_okcancel                  = 0x00000001ul,
	mk_win_user_dialog_messagebox_e_abortretryignore          = 0x00000002ul,
	mk_win_user_dialog_messagebox_e_yesnocancel               = 0x00000003ul,
	mk_win_user_dialog_messagebox_e_yesno                     = 0x00000004ul,
	mk_win_user_dialog_messagebox_e_retrycancel               = 0x00000005ul,
	mk_win_user_dialog_messagebox_e_canceltrycontinue         = 0x00000006ul, /* winver >= 0x0500 */
	mk_win_user_dialog_messagebox_e_iconhand                  = 0x00000010ul,
	mk_win_user_dialog_messagebox_e_iconquestion              = 0x00000020ul,
	mk_win_user_dialog_messagebox_e_iconexclamation           = 0x00000030ul,
	mk_win_user_dialog_messagebox_e_iconasterisk              = 0x00000040ul,
	mk_win_user_dialog_messagebox_e_usericon                  = 0x00000080ul, /* winver >= 0x0400 */
	mk_win_user_dialog_messagebox_e_iconerror                 = mk_win_user_dialog_messagebox_e_iconhand, /* winver >= 0x0400 */
	mk_win_user_dialog_messagebox_e_iconwarning               = mk_win_user_dialog_messagebox_e_iconexclamation, /* winver >= 0x0400 */
	mk_win_user_dialog_messagebox_e_iconinformation           = mk_win_user_dialog_messagebox_e_iconasterisk,
	mk_win_user_dialog_messagebox_e_iconstop                  = mk_win_user_dialog_messagebox_e_iconhand,
	mk_win_user_dialog_messagebox_e_defbutton1                = 0x00000000ul,
	mk_win_user_dialog_messagebox_e_defbutton2                = 0x00000100ul,
	mk_win_user_dialog_messagebox_e_defbutton3                = 0x00000200ul,
	mk_win_user_dialog_messagebox_e_defbutton4                = 0x00000300ul, /* winver >= 0x0400 */
	mk_win_user_dialog_messagebox_e_applmodal                 = 0x00000000ul,
	mk_win_user_dialog_messagebox_e_systemmodal               = 0x00001000ul,
	mk_win_user_dialog_messagebox_e_taskmodal                 = 0x00002000ul,
	mk_win_user_dialog_messagebox_e_help                      = 0x00004000ul, /* winver >= 0x0400 */
	mk_win_user_dialog_messagebox_e_nofocus                   = 0x00008000ul,
	mk_win_user_dialog_messagebox_e_setforeground             = 0x00010000ul,
	mk_win_user_dialog_messagebox_e_default_desktop_only      = 0x00020000ul,
	mk_win_user_dialog_messagebox_e_topmost                   = 0x00040000ul, /* winver >= 0x0400 */
	mk_win_user_dialog_messagebox_e_right                     = 0x00080000ul, /* winver >= 0x0400 */
	mk_win_user_dialog_messagebox_e_rtlreading                = 0x00100000ul, /* winver >= 0x0400 */
	mk_win_user_dialog_messagebox_e_service_notification      = 0x00200000ul, /* win32_winnt >= 0x0400 */
	mk_win_user_dialog_messagebox_e_service_notification_nt3x = 0x00040000ul,
	mk_win_user_dialog_messagebox_e_typemask                  = 0x0000000ful,
	mk_win_user_dialog_messagebox_e_iconmask                  = 0x000000f0ul,
	mk_win_user_dialog_messagebox_e_defmask                   = 0x00000f00ul,
	mk_win_user_dialog_messagebox_e_modemask                  = 0x00003000ul,
	mk_win_user_dialog_messagebox_e_miscmask                  = 0x0000c000ul,
	mk_win_user_dialog_messagebox_e_dummy_end = 0
};
typedef enum mk_win_user_dialog_messagebox_e mk_win_user_dialog_messagebox_t;


#if defined _MSC_VER
#pragma pack(push, 1) /* todo rly needed? */
#endif
struct mk_win_user_dialog_dlg_template_s
{
	mk_win_base_dword_t m_style;
	mk_win_base_dword_t m_style_ex;
	mk_win_base_word_t m_count;
	mk_win_base_sshort_t m_left;
	mk_win_base_sshort_t m_top;
	mk_win_base_sshort_t m_width;
	mk_win_base_sshort_t m_height;
	mk_win_base_word_t m_menu;
	mk_win_base_word_t m_class;
	mk_win_base_wchar_t m_title;
	mk_win_base_word_t m_point_size;
	mk_win_base_wchar_t m_typeface;
};
typedef struct mk_win_user_dialog_dlg_template_s mk_win_user_dialog_dlg_template_t;
typedef mk_win_user_dialog_dlg_template_t const mk_win_user_dialog_dlg_template_ct;
typedef mk_win_user_dialog_dlg_template_t* mk_win_user_dialog_dlg_template_pt;
typedef mk_win_user_dialog_dlg_template_t const* mk_win_user_dialog_dlg_template_pct;
typedef mk_win_user_dialog_dlg_template_t mk_win_base_far* mk_win_user_dialog_dlg_template_lpt;
typedef mk_win_user_dialog_dlg_template_t mk_win_base_far const* mk_win_user_dialog_dlg_template_lpct;
typedef mk_win_user_dialog_dlg_template_t mk_win_base_near* mk_win_user_dialog_dlg_template_npt;
typedef mk_win_user_dialog_dlg_template_t mk_win_base_near const* mk_win_user_dialog_dlg_template_npct;
#if defined _MSC_VER
#pragma pack(pop)
#endif

#if defined _MSC_VER
#pragma pack(push, 1) /* todo rly needed? */
#endif
struct mk_win_user_dialog_itm_template_s
{
	mk_win_base_dword_t m_style;
	mk_win_base_dword_t m_style_ex;
	mk_win_base_sshort_t m_left;
	mk_win_base_sshort_t m_top;
	mk_win_base_sshort_t m_width;
	mk_win_base_sshort_t m_height;
	mk_win_base_word_t m_id;
	mk_win_base_wchar_t m_class[2];
	mk_win_base_wchar_t m_title;
	mk_win_base_word_t m_extra_count;
};
typedef struct mk_win_user_dialog_itm_template_s mk_win_user_dialog_itm_template_t;
typedef mk_win_user_dialog_itm_template_t const mk_win_user_dialog_itm_template_ct;
typedef mk_win_user_dialog_itm_template_t* mk_win_user_dialog_itm_template_pt;
typedef mk_win_user_dialog_itm_template_t const* mk_win_user_dialog_itm_template_pct;
typedef mk_win_user_dialog_itm_template_t mk_win_base_far* mk_win_user_dialog_itm_template_lpt;
typedef mk_win_user_dialog_itm_template_t mk_win_base_far const* mk_win_user_dialog_itm_template_lpct;
typedef mk_win_user_dialog_itm_template_t mk_win_base_near* mk_win_user_dialog_itm_template_npt;
typedef mk_win_user_dialog_itm_template_t mk_win_base_near const* mk_win_user_dialog_itm_template_npct;
#if defined _MSC_VER
#pragma pack(pop)
#endif

#if defined _MSC_VER
#pragma pack(push, 1) /* todo rly needed? */
#endif
struct mk_win_user_dialog_dlg_templateex_s
{
	mk_win_base_word_t m_version;
	mk_win_base_word_t m_signature;
	mk_win_base_dword_t m_help_id;
	mk_win_base_dword_t m_style_ex;
	mk_win_base_dword_t m_style;
	mk_win_base_word_t m_count;
	mk_win_base_sshort_t m_left;
	mk_win_base_sshort_t m_top;
	mk_win_base_sshort_t m_width;
	mk_win_base_sshort_t m_height;
	mk_win_base_word_t m_menu;
	mk_win_base_word_t m_class;
	mk_win_base_wchar_t m_title;
	mk_win_base_word_t m_point_size;
	mk_win_base_word_t m_weight;
	mk_win_base_uchar_t m_italic;
	mk_win_base_uchar_t m_charset;
	mk_win_base_wchar_t m_typeface;
};
typedef struct mk_win_user_dialog_dlg_templateex_s mk_win_user_dialog_dlg_templateex_t;
typedef mk_win_user_dialog_dlg_templateex_t const mk_win_user_dialog_dlg_templateex_ct;
typedef mk_win_user_dialog_dlg_templateex_t* mk_win_user_dialog_dlg_templateex_pt;
typedef mk_win_user_dialog_dlg_templateex_t const* mk_win_user_dialog_dlg_templateex_pct;
typedef mk_win_user_dialog_dlg_templateex_t mk_win_base_far* mk_win_user_dialog_dlg_templateex_lpt;
typedef mk_win_user_dialog_dlg_templateex_t mk_win_base_far const* mk_win_user_dialog_dlg_templateex_lpct;
typedef mk_win_user_dialog_dlg_templateex_t mk_win_base_near* mk_win_user_dialog_dlg_templateex_npt;
typedef mk_win_user_dialog_dlg_templateex_t mk_win_base_near const* mk_win_user_dialog_dlg_templateex_npct;
#if defined _MSC_VER
#pragma pack(pop)
#endif

#if defined _MSC_VER
#pragma pack(push, 1) /* todo rly needed? */
#endif
struct mk_win_user_dialog_itm_templateex_s
{
	mk_win_base_dword_t m_help_id;
	mk_win_base_dword_t m_style_ex;
	mk_win_base_dword_t m_style;
	mk_win_base_sshort_t m_left;
	mk_win_base_sshort_t m_top;
	mk_win_base_sshort_t m_width;
	mk_win_base_sshort_t m_height;
	mk_win_base_dword_t m_id;
	mk_win_base_wchar_t m_class[2];
	mk_win_base_wchar_t m_title;
	mk_win_base_word_t m_extra_count;
};
typedef struct mk_win_user_dialog_itm_templateex_s mk_win_user_dialog_itm_templateex_t;
typedef mk_win_user_dialog_itm_templateex_t const mk_win_user_dialog_itm_templateex_ct;
typedef mk_win_user_dialog_itm_templateex_t* mk_win_user_dialog_itm_templateex_pt;
typedef mk_win_user_dialog_itm_templateex_t const* mk_win_user_dialog_itm_templateex_pct;
typedef mk_win_user_dialog_itm_templateex_t mk_win_base_far* mk_win_user_dialog_itm_templateex_lpt;
typedef mk_win_user_dialog_itm_templateex_t mk_win_base_far const* mk_win_user_dialog_itm_templateex_lpct;
typedef mk_win_user_dialog_itm_templateex_t mk_win_base_near* mk_win_user_dialog_itm_templateex_npt;
typedef mk_win_user_dialog_itm_templateex_t mk_win_base_near const* mk_win_user_dialog_itm_templateex_npct;
#if defined _MSC_VER
#pragma pack(pop)
#endif


struct mk_win_user_dialog_two_ints_s
{
	int m_a;
	int m_b;
};
typedef struct mk_win_user_dialog_two_ints_s mk_win_user_dialog_two_ints_t;


typedef mk_win_base_sintptr_t(mk_win_base_far mk_win_base_stdcall*mk_win_user_dialog_dlgproc_t)(mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_a_indirect_param(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_template_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_a_indirect_param_ex(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_templateex_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_user_dialog_a_msgbox(mk_win_user_window_t const parent, mk_win_base_pchar_lpct const text, mk_win_base_pchar_lpct const caption, mk_win_user_dialog_messagebox_t const type) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_w_indirect_param(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_template_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_w_indirect_param_ex(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_templateex_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_t_indirect_param(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_template_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sintptr_t mk_win_user_dialog_t_indirect_param_ex(mk_win_base_instance_t const instance, mk_win_user_dialog_dlg_templateex_lpct const dlg, mk_win_user_window_t const parent, mk_win_user_dialog_dlgproc_t const proc, mk_win_user_window_lparam_t const param) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_user_dialog_w_msgbox(mk_win_user_window_t const parent, mk_win_base_wchar_lpct const text, mk_win_base_wchar_lpct const caption, mk_win_user_dialog_messagebox_t const type) mk_lang_noexcept;

mk_lang_jumbo mk_win_base_bool_t mk_win_user_dialog_end(mk_win_user_window_t const dialog, mk_win_base_sintptr_t const result) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_window_t mk_win_user_dialog_get_item(mk_win_user_window_t const dialog, int const ctrl_id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo int mk_win_user_dialog_t_msgbox(mk_win_user_window_t const parent, mk_win_tstring_tchar_lpct const text, mk_win_tstring_tchar_lpct const caption, mk_win_user_dialog_messagebox_t const type) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpct mk_win_user_dialog_get_ctrl_font(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_margins(mk_win_base_instance_t const instance) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_related_unrelated(mk_win_base_instance_t const instance) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_button(mk_win_base_instance_t const instance) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_edit(mk_win_base_instance_t const instance) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_static(mk_win_base_instance_t const instance) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_dialog_two_ints_t mk_win_user_dialog_get_ctrl_size_progressbar(mk_win_base_instance_t const instance) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_dialog.c"
#endif
#endif
