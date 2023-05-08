#include "mk_clib_app_file_explorer.h"

#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_clobber.h"
#include "mk_lang_exception.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lib_fe.h"
#include "mk_win_base.h"
#include "mk_win_ctrl_impl_mlistbox.h"
#include "mk_win_gdi_font.h"
#include "mk_win_kernel_files.h"
#include "mk_win_kernel_system_information.h"
#include "mk_win_main_heap.h"
#include "mk_win_tstring.h"
#include "mk_win_user_brush.h"
#include "mk_win_user_class.h"
#include "mk_win_user_color.h"
#include "mk_win_user_ctrl_edit.h"
#include "mk_win_user_ctrl_mlistbox.h"
#include "mk_win_user_ctrl_static.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_dialog.h"
#include "mk_win_user_icon.h"
#include "mk_win_user_message.h"
#include "mk_win_user_timer.h"
#include "mk_win_user_window.h"

#define mk_lang_bui_name fe
#define mk_lang_bui_type mk_lang_bi_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name fe
#define mk_sl_cui_base_type mk_lang_bi_uint_t
#define mk_sl_cui_base_name mk_lang_bui_fe
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(32, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"


static mk_win_base_instance_t g_instance;
static mk_win_user_dialog_two_ints_t g_size_margin;
static mk_win_user_dialog_two_ints_t g_size_related_unrelated;
static mk_win_user_dialog_two_ints_t g_size_edit;
static mk_win_user_dialog_two_ints_t g_size_static;


#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_clib_app_file_explorer_context_s
{
	mk_win_user_window_t m_self;
	mk_win_user_window_t m_edit;
	mk_win_user_window_t m_static;
	mk_win_base_dword_t m_time;
};
typedef struct mk_clib_app_file_explorer_context_s mk_clib_app_file_explorer_context_t;
typedef mk_clib_app_file_explorer_context_t const mk_clib_app_file_explorer_context_ct;
typedef mk_clib_app_file_explorer_context_t* mk_clib_app_file_explorer_context_pt;
typedef mk_clib_app_file_explorer_context_t const* mk_clib_app_file_explorer_context_pct;
typedef mk_clib_app_file_explorer_context_t mk_win_base_far* mk_clib_app_file_explorer_context_lpt;
typedef mk_clib_app_file_explorer_context_t mk_win_base_far const* mk_clib_app_file_explorer_context_lpct;
typedef mk_clib_app_file_explorer_context_t mk_win_base_near* mk_clib_app_file_explorer_context_npt;
typedef mk_clib_app_file_explorer_context_t mk_win_base_near const* mk_clib_app_file_explorer_context_npct;
#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(pop)
#endif


mk_win_base_dll_import void mk_win_base_stdcall InitCommonControls(void) mk_lang_noexcept; /* todo move to commctrls */
mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetTickCount(void) mk_lang_noexcept; /* todo move to time */


#define s_timer_id 42
#define s_mk_clib_app_file_explorer_ctrl_id_listbox_main 0
#define s_mk_clib_app_file_explorer_ctrl_id_static_name_label 1
#define s_mk_clib_app_file_explorer_ctrl_id_edit_name_value 2
#define s_mk_clib_app_file_explorer_ctrl_id_static_type_label 3
#define s_mk_clib_app_file_explorer_ctrl_id_edit_type_value 4
#define s_mk_clib_app_file_explorer_ctrl_id_static_detail_label 5
#define s_mk_clib_app_file_explorer_ctrl_id_edit_detail_value 6
#define s_mk_clib_app_file_explorer_ctrl_id_static_attributes_label 7
#define s_mk_clib_app_file_explorer_ctrl_id_edit_attributes_value 8
#define s_mk_clib_app_file_explorer_ctrl_id_listbox_attributes_data 9


mk_lang_nodiscard static mk_lang_inline int mk_clib_app_file_explorer_run_dialog(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline int mk_clib_app_file_explorer_run_dialog_ex(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_base_sshort_t mk_clib_app_file_explorer_max_f(mk_win_base_sshort_t const a, mk_win_base_sshort_t const b) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline void* mk_clib_app_file_explorer_round_up_s(void const* ptr, mk_win_base_size_t const size) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline void* mk_clib_app_file_explorer_round_up_i(void const* ptr, int const size) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_labels_clear(mk_win_user_window_t const dialog) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_selection(mk_win_user_window_t const dialog) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_listbox_repopulate(mk_win_user_window_t const dialog, mk_lib_fe_lpt const fe, int const select_idx) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_go_to_root(mk_win_user_window_t const dialog) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_go_to_item_idx(mk_win_user_window_t const dialog, int const idx) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_go_to_item_curr(mk_win_user_window_t const dialog) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_destroy(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_close(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify_listbox_main_return(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify_listbox_main_get_string(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify_listbox_main(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify_listbox_attributes_get_string(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify_listbox_attributes(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_initdialog(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_command_list_selchange(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_command_list_dblclk(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_command_list(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_file_explorer_on_msg_command(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept;
static mk_win_base_sintptr_t mk_win_base_stdcall mk_clib_app_file_explorer_dlgproc(mk_win_user_window_t const dialog, mk_win_base_uint_t const msg_uid, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;


#if defined _MSC_VER && _MSC_VER < 1935
#define mk_clib_app_file_explorer_max_m mk_clib_app_file_explorer_max_f
#else
#define mk_clib_app_file_explorer_max_m mk_lang_max
#endif


mk_lang_jumbo int mk_clib_app_file_explorer_winmain(mk_win_base_instance_t const instance, mk_win_base_instance_t const previous, mk_win_tstring_tchar_lpct const cmd, int const show) mk_lang_noexcept
{
	mk_win_base_dword_t version;
	mk_lang_bool_t nt;
	unsigned char major;
	unsigned char minor;
	int ret;

	mk_lang_assert(instance);
	((void)(previous));
	((void)(cmd));
	((void)(show));

	mk_lang_exception_test();
	mk_win_main_heap_create();
	mk_win_tstring_init();
	InitCommonControls();
	mk_win_ctrl_impl_mlistbox_register();

	g_instance = instance;
	g_size_margin = mk_win_user_dialog_get_ctrl_size_margins(g_instance);
	g_size_related_unrelated = mk_win_user_dialog_get_ctrl_size_related_unrelated(g_instance);
	g_size_edit = mk_win_user_dialog_get_ctrl_size_edit(g_instance);
	g_size_static = mk_win_user_dialog_get_ctrl_size_static(g_instance);

	version = mk_win_kernel_system_information_get_version();
	nt = (version >> 31) == 0;
	major = ((unsigned char)((version >> 0) & 0xff));
	minor = ((unsigned char)((version >> 8) & 0xff));
	if(nt && (major > 3 || (major == 3 && minor >= 51)))
	{
		ret = mk_clib_app_file_explorer_run_dialog_ex();
	}
	else
	{
		ret = mk_clib_app_file_explorer_run_dialog();
	}

	mk_win_ctrl_impl_mlistbox_unregister();
	mk_win_tstring_deinit();
	mk_win_main_heap_destroy();

	return ret;
}


mk_lang_nodiscard static mk_lang_inline int mk_clib_app_file_explorer_run_dialog(void) mk_lang_noexcept
{
	static mk_win_base_wchar_t const s_msshelldlg[] = L"MS Shell Dlg";
	static mk_win_base_wchar_t const s_window_title[] = L"File Explorer";
	static mk_win_base_wchar_t const s_name_title[] = L"Name";
	static mk_win_base_wchar_t const s_type_title[] = L"Type";
	static mk_win_base_wchar_t const s_detail_title[] = L"Detail";
	static mk_win_base_wchar_t const s_attributes_title[] = L"Attributes";
	static int const s_msshelldlg_len = ((int)(sizeof(s_msshelldlg) / sizeof(s_msshelldlg[0])));
	static int const s_window_title_len = ((int)(sizeof(s_window_title) / sizeof(s_window_title[0])));
	static int const s_name_title_len = ((int)(sizeof(s_name_title) / sizeof(s_name_title[0])));
	static int const s_type_title_len = ((int)(sizeof(s_type_title) / sizeof(s_type_title[0])));
	static int const s_detail_title_len = ((int)(sizeof(s_detail_title) / sizeof(s_detail_title[0])));
	static int const s_attributes_title_len = ((int)(sizeof(s_attributes_title) / sizeof(s_attributes_title[0])));

	mk_win_base_sshort_t ctrl_listbox_x;
	mk_win_base_sshort_t ctrl_listbox_y;
	mk_win_base_sshort_t ctrl_listbox_w;
	mk_win_base_sshort_t ctrl_listbox_h;
	mk_win_base_sshort_t ctrl_static_name_label_x;
	mk_win_base_sshort_t ctrl_static_name_label_y;
	mk_win_base_sshort_t ctrl_static_name_label_w;
	mk_win_base_sshort_t ctrl_static_name_label_h;
	mk_win_base_sshort_t ctrl_edit_name_value_x;
	mk_win_base_sshort_t ctrl_edit_name_value_y;
	mk_win_base_sshort_t ctrl_edit_name_value_w;
	mk_win_base_sshort_t ctrl_edit_name_value_h;
	mk_win_base_sshort_t ctrl_static_type_label_x;
	mk_win_base_sshort_t ctrl_static_type_label_y;
	mk_win_base_sshort_t ctrl_static_type_label_w;
	mk_win_base_sshort_t ctrl_static_type_label_h;
	mk_win_base_sshort_t ctrl_edit_type_value_x;
	mk_win_base_sshort_t ctrl_edit_type_value_y;
	mk_win_base_sshort_t ctrl_edit_type_value_w;
	mk_win_base_sshort_t ctrl_edit_type_value_h;
	mk_win_base_sshort_t ctrl_static_detail_label_x;
	mk_win_base_sshort_t ctrl_static_detail_label_y;
	mk_win_base_sshort_t ctrl_static_detail_label_w;
	mk_win_base_sshort_t ctrl_static_detail_label_h;
	mk_win_base_sshort_t ctrl_edit_detail_value_x;
	mk_win_base_sshort_t ctrl_edit_detail_value_y;
	mk_win_base_sshort_t ctrl_edit_detail_value_w;
	mk_win_base_sshort_t ctrl_edit_detail_value_h;
	mk_win_base_sshort_t ctrl_static_attributes_label_x;
	mk_win_base_sshort_t ctrl_static_attributes_label_y;
	mk_win_base_sshort_t ctrl_static_attributes_label_w;
	mk_win_base_sshort_t ctrl_static_attributes_label_h;
	mk_win_base_sshort_t ctrl_static_attributes_value_x;
	mk_win_base_sshort_t ctrl_static_attributes_value_y;
	mk_win_base_sshort_t ctrl_static_attributes_value_w;
	mk_win_base_sshort_t ctrl_static_attributes_value_h;
	mk_win_base_sshort_t ctrl_listbox_attributes_x;
	mk_win_base_sshort_t ctrl_listbox_attributes_y;
	mk_win_base_sshort_t ctrl_listbox_attributes_w;
	mk_win_base_sshort_t ctrl_listbox_attributes_h;
	mk_win_base_sshort_t dlg_w;
	mk_win_base_sshort_t dlg_h;
	mk_win_user_dialog_dlg_template_pt dlg;
	unsigned char template_buffer[1024];
	int n;
	int i;
	mk_win_user_dialog_dlg_template_pt dlg2;
	mk_win_user_dialog_itm_template_pt ctrl_listbox;
	mk_win_user_dialog_itm_template_pt ctrl2;
	mk_win_user_dialog_itm_template_pt ctrl_static_name_label;
	mk_win_user_dialog_itm_template_pt ctrl_edit_name_value;
	mk_win_user_dialog_itm_template_pt ctrl_static_type_label;
	mk_win_user_dialog_itm_template_pt ctrl_edit_type_value;
	mk_win_user_dialog_itm_template_pt ctrl_static_detail_label;
	mk_win_user_dialog_itm_template_pt ctrl_edit_detail_value;
	mk_win_user_dialog_itm_template_pt ctrl_static_attributes;
	mk_win_user_dialog_itm_template_pt ctrl_edit_attributes;
	mk_win_user_dialog_itm_template_pt ctrl_listbox_attributes;
	mk_win_base_sintptr_t res;
	int ret;

	ctrl_listbox_x = mk_win_user_dialog_space_dlg_margin;
	ctrl_listbox_y = mk_win_user_dialog_space_dlg_margin;
	ctrl_listbox_w = mk_win_user_dialog_size_progressb_w;
	ctrl_listbox_h = mk_win_user_dialog_size_static_h * (8 + 1);
	ctrl_static_name_label_x = ctrl_listbox_x;
	ctrl_static_name_label_y = ctrl_listbox_y + ctrl_listbox_h + mk_win_user_dialog_space_related_ctrl;
	ctrl_static_name_label_w = mk_win_user_dialog_size_button_w;
	ctrl_static_name_label_h = mk_lang_max(mk_win_user_dialog_size_static_h, mk_win_user_dialog_size_edit1_h);
	ctrl_edit_name_value_x = ctrl_static_name_label_x + ctrl_static_name_label_w + mk_win_user_dialog_space_related_ctrl;
	ctrl_edit_name_value_y = ctrl_static_name_label_y;
	ctrl_edit_name_value_w = mk_win_user_dialog_size_progressb_w - mk_win_user_dialog_space_related_ctrl - mk_win_user_dialog_size_button_w;
	ctrl_edit_name_value_h = ctrl_static_name_label_h;
	ctrl_static_type_label_x = ctrl_static_name_label_x;
	ctrl_static_type_label_y = ctrl_static_name_label_y + mk_lang_max(ctrl_static_name_label_h, ctrl_edit_name_value_h) + mk_win_user_dialog_space_related_ctrl;
	ctrl_static_type_label_w = ctrl_static_name_label_w;
	ctrl_static_type_label_h = ctrl_static_name_label_h;
	ctrl_edit_type_value_x = ctrl_edit_name_value_x;
	ctrl_edit_type_value_y = ctrl_static_type_label_y;
	ctrl_edit_type_value_w = ctrl_edit_name_value_w;
	ctrl_edit_type_value_h = ctrl_edit_name_value_h;
	ctrl_static_detail_label_x = ctrl_static_type_label_x;
	ctrl_static_detail_label_y = ctrl_static_type_label_y + mk_lang_max(ctrl_static_type_label_h, ctrl_edit_type_value_h) + mk_win_user_dialog_space_related_ctrl;
	ctrl_static_detail_label_w = ctrl_static_type_label_w;
	ctrl_static_detail_label_h = ctrl_static_type_label_h;
	ctrl_edit_detail_value_x = ctrl_edit_type_value_x;
	ctrl_edit_detail_value_y = ctrl_static_detail_label_y;
	ctrl_edit_detail_value_w = ctrl_edit_type_value_w;
	ctrl_edit_detail_value_h = ctrl_edit_type_value_h;
	ctrl_static_attributes_label_x = ctrl_static_detail_label_x;
	ctrl_static_attributes_label_y = ctrl_static_detail_label_y + mk_lang_max(ctrl_static_detail_label_h, ctrl_edit_detail_value_h) + mk_win_user_dialog_space_related_ctrl;
	ctrl_static_attributes_label_w = ctrl_static_detail_label_w;
	ctrl_static_attributes_label_h = ctrl_static_detail_label_h;
	ctrl_static_attributes_value_x = ctrl_edit_detail_value_x;
	ctrl_static_attributes_value_y = ctrl_static_attributes_label_y;
	ctrl_static_attributes_value_w = ctrl_edit_detail_value_w;
	ctrl_static_attributes_value_h = ctrl_edit_detail_value_h;
	ctrl_listbox_attributes_x = ctrl_static_attributes_label_x;
	ctrl_listbox_attributes_y = ctrl_static_attributes_label_y + mk_lang_max(ctrl_static_attributes_label_h, ctrl_static_attributes_value_h) + mk_win_user_dialog_space_related_ctrl;
	ctrl_listbox_attributes_w = ctrl_listbox_w;
	ctrl_listbox_attributes_h = mk_win_user_dialog_size_static_h * (3 + 1);
	dlg_w = mk_win_user_dialog_space_dlg_margin + mk_win_user_dialog_size_progressb_w + mk_win_user_dialog_space_dlg_margin;
	dlg_h = mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(
		0,
		ctrl_listbox_y + ctrl_listbox_h),
		ctrl_static_name_label_y + ctrl_static_name_label_h),
		ctrl_static_type_label_y + ctrl_static_type_label_h),
		ctrl_edit_type_value_y + ctrl_edit_type_value_h),
		ctrl_static_detail_label_y + ctrl_static_detail_label_h),
		ctrl_edit_detail_value_y + ctrl_edit_detail_value_h),
		ctrl_static_attributes_label_y + ctrl_static_attributes_label_h),
		ctrl_static_attributes_value_y + ctrl_static_attributes_value_h),
		ctrl_listbox_attributes_y + ctrl_listbox_attributes_h),
		0) +
		mk_win_user_dialog_space_dlg_margin;
	dlg = ((mk_win_user_dialog_dlg_template_pt)(mk_clib_app_file_explorer_round_up_s(template_buffer, sizeof(mk_win_base_dword_t))));
	dlg->m_style = mk_win_user_dialog_style_e_shellfont | mk_win_user_window_style_e_overlappedwindow &~ mk_win_user_window_style_e_maximizebox &~ mk_win_user_window_style_e_thickframe;
	dlg->m_style_ex = 0;
	dlg->m_count = 10;
	dlg->m_left = 0;
	dlg->m_top = 0;
	dlg->m_width = dlg_w;
	dlg->m_height = dlg_h;
	dlg->m_menu = 0;
	dlg->m_class = 0;
	for(i = 0; i != s_window_title_len; ++i) (&dlg->m_title)[i] = s_window_title[i];
	dlg2 = ((mk_win_user_dialog_dlg_template_pt)(((mk_win_base_wchar_pt)(dlg)) + (s_window_title_len - 1)));
	dlg2->m_point_size = 8;
	for(i = 0; i != s_msshelldlg_len; ++i) (&dlg2->m_typeface)[i] = s_msshelldlg[i];

	ctrl_listbox = ((mk_win_user_dialog_itm_template_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_base_wchar_pct)(dlg + 1)) + (s_window_title_len - 1) + (s_msshelldlg_len - 1), sizeof(mk_win_base_dword_t))));
	ctrl_listbox->m_style =
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_hscroll |
		mk_win_user_window_style_e_vscroll |
		mk_win_user_window_style_e_border |
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_listbox->m_style_ex = 0;
	ctrl_listbox->m_left = ctrl_listbox_x;
	ctrl_listbox->m_top = ctrl_listbox_y;
	ctrl_listbox->m_width = ctrl_listbox_w;
	ctrl_listbox->m_height = ctrl_listbox_h;
	ctrl_listbox->m_id = s_mk_clib_app_file_explorer_ctrl_id_listbox_main;
	n = ((int)(sizeof(mk_win_user_ctrl_mlistbox_name_w) / sizeof(mk_win_user_ctrl_mlistbox_name_w[0])));
	for(i = 0; i != n; ++i) ctrl_listbox->m_class[i] = mk_win_user_ctrl_mlistbox_name_w[i];
	ctrl2 = ((mk_win_user_dialog_itm_template_pt)(((mk_win_base_wchar_pt)(ctrl_listbox)) + (n - 2)));
	ctrl2->m_title = 0;
	ctrl2->m_extra_count = 0;

	ctrl_static_name_label = ((mk_win_user_dialog_itm_template_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_tstring_tchar_pct)(ctrl_listbox + 1)) + (n - 2), sizeof(mk_win_base_dword_t))));
	ctrl_static_name_label->m_style =
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_static_name_label->m_style_ex = 0;
	ctrl_static_name_label->m_left = ctrl_static_name_label_x;
	ctrl_static_name_label->m_top = ctrl_static_name_label_y;
	ctrl_static_name_label->m_width = ctrl_static_name_label_w;
	ctrl_static_name_label->m_height = ctrl_static_name_label_h;
	ctrl_static_name_label->m_id = s_mk_clib_app_file_explorer_ctrl_id_static_name_label;
	ctrl_static_name_label->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_static_name_label->m_class[1] = mk_win_user_dialog_class_id_static;
	for(i = 0; i != s_name_title_len; ++i) (&ctrl_static_name_label->m_title)[i] = s_name_title[i];
	ctrl2 = ((mk_win_user_dialog_itm_template_pt)(((mk_win_base_wchar_pt)(ctrl_static_name_label)) + (s_name_title_len - 1)));
	ctrl2->m_extra_count = 0;

	ctrl_edit_name_value = ((mk_win_user_dialog_itm_template_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_base_wchar_pct)(ctrl_static_name_label + 1)) + (s_name_title_len - 1), sizeof(mk_win_base_dword_t))));
	ctrl_edit_name_value->m_style =
		mk_win_user_ctrl_edit_style_e_autohscroll |
		mk_win_user_ctrl_edit_style_e_readonly |
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_edit_name_value->m_style_ex = 0;
	ctrl_edit_name_value->m_left = ctrl_edit_name_value_x;
	ctrl_edit_name_value->m_top = ctrl_edit_name_value_y;
	ctrl_edit_name_value->m_width = ctrl_edit_name_value_w;
	ctrl_edit_name_value->m_height = ctrl_edit_name_value_h;
	ctrl_edit_name_value->m_id = s_mk_clib_app_file_explorer_ctrl_id_edit_name_value;
	ctrl_edit_name_value->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_edit_name_value->m_class[1] = mk_win_user_dialog_class_id_edit;
	ctrl_edit_name_value->m_title = 0;
	ctrl_edit_name_value->m_extra_count = 0;

	ctrl_static_type_label = ((mk_win_user_dialog_itm_template_pt)(mk_clib_app_file_explorer_round_up_s(ctrl_edit_name_value + 1, sizeof(mk_win_base_dword_t))));
	ctrl_static_type_label->m_style =
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_static_type_label->m_style_ex = 0;
	ctrl_static_type_label->m_left = ctrl_static_type_label_x;
	ctrl_static_type_label->m_top = ctrl_static_type_label_y;
	ctrl_static_type_label->m_width = ctrl_static_type_label_w;
	ctrl_static_type_label->m_height = ctrl_static_type_label_h;
	ctrl_static_type_label->m_id = s_mk_clib_app_file_explorer_ctrl_id_static_type_label;
	ctrl_static_type_label->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_static_type_label->m_class[1] = mk_win_user_dialog_class_id_static;
	for(i = 0; i != s_type_title_len; ++i) (&ctrl_static_type_label->m_title)[i] = s_type_title[i];
	ctrl2 = ((mk_win_user_dialog_itm_template_pt)(((mk_win_base_wchar_pt)(ctrl_static_type_label)) + (s_type_title_len - 1)));
	ctrl2->m_extra_count = 0;

	ctrl_edit_type_value = ((mk_win_user_dialog_itm_template_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_base_wchar_pct)(ctrl_static_type_label + 1)) + (s_type_title_len - 1), sizeof(mk_win_base_dword_t))));
	ctrl_edit_type_value->m_style =
		mk_win_user_ctrl_edit_style_e_autohscroll |
		mk_win_user_ctrl_edit_style_e_readonly |
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_edit_type_value->m_style_ex = 0;
	ctrl_edit_type_value->m_left = ctrl_edit_type_value_x;
	ctrl_edit_type_value->m_top = ctrl_edit_type_value_y;
	ctrl_edit_type_value->m_width = ctrl_edit_type_value_w;
	ctrl_edit_type_value->m_height = ctrl_edit_type_value_h;
	ctrl_edit_type_value->m_id = s_mk_clib_app_file_explorer_ctrl_id_edit_type_value;
	ctrl_edit_type_value->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_edit_type_value->m_class[1] = mk_win_user_dialog_class_id_edit;
	ctrl_edit_type_value->m_title = 0;
	ctrl_edit_type_value->m_extra_count = 0;

	ctrl_static_detail_label = ((mk_win_user_dialog_itm_template_pt)(mk_clib_app_file_explorer_round_up_s(ctrl_edit_type_value + 1, sizeof(mk_win_base_dword_t))));
	ctrl_static_detail_label->m_style =
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_static_detail_label->m_style_ex = 0;
	ctrl_static_detail_label->m_left = ctrl_static_detail_label_x;
	ctrl_static_detail_label->m_top = ctrl_static_detail_label_y;
	ctrl_static_detail_label->m_width = ctrl_static_detail_label_w;
	ctrl_static_detail_label->m_height = ctrl_static_detail_label_h;
	ctrl_static_detail_label->m_id = s_mk_clib_app_file_explorer_ctrl_id_static_detail_label;
	ctrl_static_detail_label->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_static_detail_label->m_class[1] = mk_win_user_dialog_class_id_static;
	for(i = 0; i != s_detail_title_len; ++i) (&ctrl_static_detail_label->m_title)[i] = s_detail_title[i];
	ctrl2 = ((mk_win_user_dialog_itm_template_pt)(((mk_win_base_wchar_pt)(ctrl_static_detail_label)) + (s_detail_title_len - 1)));
	ctrl2->m_extra_count = 0;

	ctrl_edit_detail_value = ((mk_win_user_dialog_itm_template_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_base_wchar_pct)(ctrl_static_detail_label + 1)) + (s_detail_title_len - 1), sizeof(mk_win_base_dword_t))));
	ctrl_edit_detail_value->m_style =
		mk_win_user_ctrl_edit_style_e_autohscroll |
		mk_win_user_ctrl_edit_style_e_readonly |
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_edit_detail_value->m_style_ex = 0;
	ctrl_edit_detail_value->m_left = ctrl_edit_detail_value_x;
	ctrl_edit_detail_value->m_top = ctrl_edit_detail_value_y;
	ctrl_edit_detail_value->m_width = ctrl_edit_detail_value_w;
	ctrl_edit_detail_value->m_height = ctrl_edit_detail_value_h;
	ctrl_edit_detail_value->m_id = s_mk_clib_app_file_explorer_ctrl_id_edit_detail_value;
	ctrl_edit_detail_value->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_edit_detail_value->m_class[1] = mk_win_user_dialog_class_id_edit;
	ctrl_edit_detail_value->m_title = 0;
	ctrl_edit_detail_value->m_extra_count = 0;

	ctrl_static_attributes = ((mk_win_user_dialog_itm_template_pt)(mk_clib_app_file_explorer_round_up_s(ctrl_edit_detail_value + 1, sizeof(mk_win_base_dword_t))));
	ctrl_static_attributes->m_style =
		mk_win_user_window_style_e_child |
		0;
	ctrl_static_attributes->m_style_ex = 0;
	ctrl_static_attributes->m_left = ctrl_static_attributes_label_x;
	ctrl_static_attributes->m_top = ctrl_static_attributes_label_y;
	ctrl_static_attributes->m_width = ctrl_static_attributes_label_w;
	ctrl_static_attributes->m_height = ctrl_static_attributes_label_h;
	ctrl_static_attributes->m_id = s_mk_clib_app_file_explorer_ctrl_id_static_attributes_label;
	ctrl_static_attributes->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_static_attributes->m_class[1] = mk_win_user_dialog_class_id_static;
	for(i = 0; i != s_attributes_title_len; ++i) (&ctrl_static_attributes->m_title)[i] = s_attributes_title[i];
	ctrl2 = ((mk_win_user_dialog_itm_template_pt)(((mk_win_base_wchar_pt)(ctrl_static_attributes)) + (s_attributes_title_len - 1)));
	ctrl2->m_extra_count = 0;

	ctrl_edit_attributes = ((mk_win_user_dialog_itm_template_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_base_wchar_pct)(ctrl_static_attributes + 1)) + (s_attributes_title_len - 1), sizeof(mk_win_base_dword_t))));
	ctrl_edit_attributes->m_style =
		mk_win_user_ctrl_edit_style_e_autohscroll |
		mk_win_user_ctrl_edit_style_e_readonly |
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_edit_attributes->m_style_ex = 0;
	ctrl_edit_attributes->m_left = ctrl_static_attributes_value_x;
	ctrl_edit_attributes->m_top = ctrl_static_attributes_value_y;
	ctrl_edit_attributes->m_width = ctrl_static_attributes_value_w;
	ctrl_edit_attributes->m_height = ctrl_static_attributes_value_h;
	ctrl_edit_attributes->m_id = s_mk_clib_app_file_explorer_ctrl_id_edit_attributes_value;
	ctrl_edit_attributes->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_edit_attributes->m_class[1] = mk_win_user_dialog_class_id_edit;
	ctrl_edit_attributes->m_title = 0;
	ctrl_edit_attributes->m_extra_count = 0;

	ctrl_listbox_attributes = ((mk_win_user_dialog_itm_template_pt)(mk_clib_app_file_explorer_round_up_s(ctrl_edit_attributes + 1, sizeof(mk_win_base_dword_t))));
	ctrl_listbox_attributes->m_style =
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_vscroll |
		mk_win_user_window_style_e_border |
		mk_win_user_window_style_e_child |
		0;
	ctrl_listbox_attributes->m_style_ex = 0;
	ctrl_listbox_attributes->m_left = ctrl_listbox_attributes_x;
	ctrl_listbox_attributes->m_top = ctrl_listbox_attributes_y;
	ctrl_listbox_attributes->m_width = ctrl_listbox_attributes_w;
	ctrl_listbox_attributes->m_height = ctrl_listbox_attributes_h;
	ctrl_listbox_attributes->m_id = s_mk_clib_app_file_explorer_ctrl_id_listbox_attributes_data;
	n = ((int)(sizeof(mk_win_user_ctrl_mlistbox_name_w) / sizeof(mk_win_user_ctrl_mlistbox_name_w[0])));
	for(i = 0; i != n; ++i) ctrl_listbox_attributes->m_class[i] = mk_win_user_ctrl_mlistbox_name_w[i];
	ctrl2 = ((mk_win_user_dialog_itm_template_pt)(((mk_win_base_wchar_pt)(ctrl_listbox_attributes)) + (n - 1)));
	ctrl2->m_title = 0;
	ctrl2->m_extra_count = 0;

	res = mk_win_user_dialog_t_indirect_param(g_instance, dlg, mk_win_base_null, &mk_clib_app_file_explorer_dlgproc, 0);
	ret = ((int)(res));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline int mk_clib_app_file_explorer_run_dialog_ex(void) mk_lang_noexcept
{
	static mk_win_base_wchar_t const s_msshelldlg[] = L"MS Shell Dlg";
	static mk_win_base_wchar_t const s_window_title[] = L"File Explorer";
	static mk_win_base_wchar_t const s_name_title[] = L"Name";
	static mk_win_base_wchar_t const s_type_title[] = L"Type";
	static mk_win_base_wchar_t const s_detail_title[] = L"Detail";
	static mk_win_base_wchar_t const s_attributes_title[] = L"Attributes";
	static int const s_msshelldlg_len = ((int)(sizeof(s_msshelldlg) / sizeof(s_msshelldlg[0])));
	static int const s_window_title_len = ((int)(sizeof(s_window_title) / sizeof(s_window_title[0])));
	static int const s_name_title_len = ((int)(sizeof(s_name_title) / sizeof(s_name_title[0])));
	static int const s_type_title_len = ((int)(sizeof(s_type_title) / sizeof(s_type_title[0])));
	static int const s_detail_title_len = ((int)(sizeof(s_detail_title) / sizeof(s_detail_title[0])));
	static int const s_attributes_title_len = ((int)(sizeof(s_attributes_title) / sizeof(s_attributes_title[0])));

	mk_win_base_sshort_t ctrl_listbox_x;
	mk_win_base_sshort_t ctrl_listbox_y;
	mk_win_base_sshort_t ctrl_listbox_w;
	mk_win_base_sshort_t ctrl_listbox_h;
	mk_win_base_sshort_t ctrl_static_name_label_x;
	mk_win_base_sshort_t ctrl_static_name_label_y;
	mk_win_base_sshort_t ctrl_static_name_label_w;
	mk_win_base_sshort_t ctrl_static_name_label_h;
	mk_win_base_sshort_t ctrl_edit_name_value_x;
	mk_win_base_sshort_t ctrl_edit_name_value_y;
	mk_win_base_sshort_t ctrl_edit_name_value_w;
	mk_win_base_sshort_t ctrl_edit_name_value_h;
	mk_win_base_sshort_t ctrl_static_type_label_x;
	mk_win_base_sshort_t ctrl_static_type_label_y;
	mk_win_base_sshort_t ctrl_static_type_label_w;
	mk_win_base_sshort_t ctrl_static_type_label_h;
	mk_win_base_sshort_t ctrl_edit_type_value_x;
	mk_win_base_sshort_t ctrl_edit_type_value_y;
	mk_win_base_sshort_t ctrl_edit_type_value_w;
	mk_win_base_sshort_t ctrl_edit_type_value_h;
	mk_win_base_sshort_t ctrl_static_detail_label_x;
	mk_win_base_sshort_t ctrl_static_detail_label_y;
	mk_win_base_sshort_t ctrl_static_detail_label_w;
	mk_win_base_sshort_t ctrl_static_detail_label_h;
	mk_win_base_sshort_t ctrl_edit_detail_value_x;
	mk_win_base_sshort_t ctrl_edit_detail_value_y;
	mk_win_base_sshort_t ctrl_edit_detail_value_w;
	mk_win_base_sshort_t ctrl_edit_detail_value_h;
	mk_win_base_sshort_t ctrl_static_attributes_label_x;
	mk_win_base_sshort_t ctrl_static_attributes_label_y;
	mk_win_base_sshort_t ctrl_static_attributes_label_w;
	mk_win_base_sshort_t ctrl_static_attributes_label_h;
	mk_win_base_sshort_t ctrl_static_attributes_value_x;
	mk_win_base_sshort_t ctrl_static_attributes_value_y;
	mk_win_base_sshort_t ctrl_static_attributes_value_w;
	mk_win_base_sshort_t ctrl_static_attributes_value_h;
	mk_win_base_sshort_t ctrl_listbox_attributes_x;
	mk_win_base_sshort_t ctrl_listbox_attributes_y;
	mk_win_base_sshort_t ctrl_listbox_attributes_w;
	mk_win_base_sshort_t ctrl_listbox_attributes_h;
	mk_win_base_sshort_t dlg_w;
	mk_win_base_sshort_t dlg_h;
	mk_win_user_dialog_dlg_templateex_pt dlg;
	unsigned char template_buffer[1024];
	int n;
	int i;
	mk_win_user_dialog_dlg_templateex_pt dlg2;
	mk_win_user_dialog_itm_templateex_pt ctrl_listbox;
	mk_win_user_dialog_itm_templateex_pt ctrl2;
	mk_win_user_dialog_itm_templateex_pt ctrl_static_name_label;
	mk_win_user_dialog_itm_templateex_pt ctrl_edit_name_value;
	mk_win_user_dialog_itm_templateex_pt ctrl_static_type_label;
	mk_win_user_dialog_itm_templateex_pt ctrl_edit_type_value;
	mk_win_user_dialog_itm_templateex_pt ctrl_static_detail_label;
	mk_win_user_dialog_itm_templateex_pt ctrl_edit_detail_value;
	mk_win_user_dialog_itm_templateex_pt ctrl_static_attributes;
	mk_win_user_dialog_itm_templateex_pt ctrl_edit_attributes;
	mk_win_user_dialog_itm_templateex_pt ctrl_listbox_attributes;
	mk_win_base_sintptr_t res;
	int ret;

	ctrl_listbox_x = mk_win_user_dialog_space_dlg_margin;
	ctrl_listbox_y = mk_win_user_dialog_space_dlg_margin;
	ctrl_listbox_w = mk_win_user_dialog_size_progressb_w;
	ctrl_listbox_h = mk_win_user_dialog_size_static_h * (8 + 1);
	ctrl_static_name_label_x = ctrl_listbox_x;
	ctrl_static_name_label_y = ctrl_listbox_y + ctrl_listbox_h + mk_win_user_dialog_space_related_ctrl;
	ctrl_static_name_label_w = mk_win_user_dialog_size_button_w;
	ctrl_static_name_label_h = mk_lang_max(mk_win_user_dialog_size_static_h, mk_win_user_dialog_size_edit1_h);
	ctrl_edit_name_value_x = ctrl_static_name_label_x + ctrl_static_name_label_w + mk_win_user_dialog_space_related_ctrl;
	ctrl_edit_name_value_y = ctrl_static_name_label_y;
	ctrl_edit_name_value_w = mk_win_user_dialog_size_progressb_w - mk_win_user_dialog_space_related_ctrl - mk_win_user_dialog_size_button_w;
	ctrl_edit_name_value_h = ctrl_static_name_label_h;
	ctrl_static_type_label_x = ctrl_static_name_label_x;
	ctrl_static_type_label_y = ctrl_static_name_label_y + mk_lang_max(ctrl_static_name_label_h, ctrl_edit_name_value_h) + mk_win_user_dialog_space_related_ctrl;
	ctrl_static_type_label_w = ctrl_static_name_label_w;
	ctrl_static_type_label_h = ctrl_static_name_label_h;
	ctrl_edit_type_value_x = ctrl_edit_name_value_x;
	ctrl_edit_type_value_y = ctrl_static_type_label_y;
	ctrl_edit_type_value_w = ctrl_edit_name_value_w;
	ctrl_edit_type_value_h = ctrl_edit_name_value_h;
	ctrl_static_detail_label_x = ctrl_static_type_label_x;
	ctrl_static_detail_label_y = ctrl_static_type_label_y + mk_lang_max(ctrl_static_type_label_h, ctrl_edit_type_value_h) + mk_win_user_dialog_space_related_ctrl;
	ctrl_static_detail_label_w = ctrl_static_type_label_w;
	ctrl_static_detail_label_h = ctrl_static_type_label_h;
	ctrl_edit_detail_value_x = ctrl_edit_type_value_x;
	ctrl_edit_detail_value_y = ctrl_static_detail_label_y;
	ctrl_edit_detail_value_w = ctrl_edit_type_value_w;
	ctrl_edit_detail_value_h = ctrl_edit_type_value_h;
	ctrl_static_attributes_label_x = ctrl_static_detail_label_x;
	ctrl_static_attributes_label_y = ctrl_static_detail_label_y + mk_lang_max(ctrl_static_detail_label_h, ctrl_edit_detail_value_h) + mk_win_user_dialog_space_related_ctrl;
	ctrl_static_attributes_label_w = ctrl_static_detail_label_w;
	ctrl_static_attributes_label_h = ctrl_static_detail_label_h;
	ctrl_static_attributes_value_x = ctrl_edit_detail_value_x;
	ctrl_static_attributes_value_y = ctrl_static_attributes_label_y;
	ctrl_static_attributes_value_w = ctrl_edit_detail_value_w;
	ctrl_static_attributes_value_h = ctrl_edit_detail_value_h;
	ctrl_listbox_attributes_x = ctrl_static_attributes_label_x;
	ctrl_listbox_attributes_y = ctrl_static_attributes_label_y + mk_lang_max(ctrl_static_attributes_label_h, ctrl_static_attributes_value_h) + mk_win_user_dialog_space_related_ctrl;
	ctrl_listbox_attributes_w = ctrl_listbox_w;
	ctrl_listbox_attributes_h = mk_win_user_dialog_size_static_h * (3 + 1);
	dlg_w = mk_win_user_dialog_space_dlg_margin + mk_win_user_dialog_size_progressb_w + mk_win_user_dialog_space_dlg_margin;
	dlg_h = mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(mk_clib_app_file_explorer_max_m(
		0,
		ctrl_listbox_y + ctrl_listbox_h),
		ctrl_static_name_label_y + ctrl_static_name_label_h),
		ctrl_static_type_label_y + ctrl_static_type_label_h),
		ctrl_edit_type_value_y + ctrl_edit_type_value_h),
		ctrl_static_detail_label_y + ctrl_static_detail_label_h),
		ctrl_edit_detail_value_y + ctrl_edit_detail_value_h),
		ctrl_static_attributes_label_y + ctrl_static_attributes_label_h),
		ctrl_static_attributes_value_y + ctrl_static_attributes_value_h),
		ctrl_listbox_attributes_y + ctrl_listbox_attributes_h),
		0) +
		mk_win_user_dialog_space_dlg_margin;
	dlg = ((mk_win_user_dialog_dlg_templateex_pt)(mk_clib_app_file_explorer_round_up_s(template_buffer, sizeof(mk_win_base_dword_t))));
	dlg->m_version = 1;
	dlg->m_signature = 0xffff;
	dlg->m_help_id = 0;
	dlg->m_style_ex = 0;
	dlg->m_style = mk_win_user_dialog_style_e_shellfont | mk_win_user_window_style_e_overlappedwindow &~ mk_win_user_window_style_e_maximizebox &~ mk_win_user_window_style_e_thickframe;
	dlg->m_count = 10;
	dlg->m_left = 0;
	dlg->m_top = 0;
	dlg->m_width = dlg_w;
	dlg->m_height = dlg_h;
	dlg->m_menu = 0;
	dlg->m_class = 0;
	for(i = 0; i != s_window_title_len; ++i) (&dlg->m_title)[i] = s_window_title[i];
	dlg2 = ((mk_win_user_dialog_dlg_templateex_pt)(((mk_win_base_wchar_pt)(dlg)) + (s_window_title_len - 1)));
	dlg2->m_point_size = 8;
	dlg2->m_weight = mk_win_user_dialog_font_weight_e_normal;
	dlg2->m_italic = 0;
	dlg2->m_charset = mk_win_user_dialog_font_charset_e_default;
	for(i = 0; i != s_msshelldlg_len; ++i) (&dlg2->m_typeface)[i] = s_msshelldlg[i];

	ctrl_listbox = ((mk_win_user_dialog_itm_templateex_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_base_wchar_pct)(dlg + 1)) + (s_window_title_len - 1) + (s_msshelldlg_len - 1), sizeof(mk_win_base_dword_t))));
	ctrl_listbox->m_help_id = 0;
	ctrl_listbox->m_style_ex = 0;
	ctrl_listbox->m_style =
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_hscroll |
		mk_win_user_window_style_e_vscroll |
		mk_win_user_window_style_e_border |
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_listbox->m_left = ctrl_listbox_x;
	ctrl_listbox->m_top = ctrl_listbox_y;
	ctrl_listbox->m_width = ctrl_listbox_w;
	ctrl_listbox->m_height = ctrl_listbox_h;
	ctrl_listbox->m_id = s_mk_clib_app_file_explorer_ctrl_id_listbox_main;
	n = ((int)(sizeof(mk_win_user_ctrl_mlistbox_name_w) / sizeof(mk_win_user_ctrl_mlistbox_name_w[0])));
	for(i = 0; i != n; ++i) ctrl_listbox->m_class[i] = mk_win_user_ctrl_mlistbox_name_w[i];
	ctrl2 = ((mk_win_user_dialog_itm_templateex_pt)(((mk_win_base_wchar_pt)(ctrl_listbox)) + (n - 2)));
	ctrl2->m_title = 0;
	ctrl2->m_extra_count = 0;

	ctrl_static_name_label = ((mk_win_user_dialog_itm_templateex_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_base_wchar_pct)(ctrl_listbox + 1)) + (n - 2), sizeof(mk_win_base_dword_t))));
	ctrl_static_name_label->m_help_id = 0;
	ctrl_static_name_label->m_style_ex = 0;
	ctrl_static_name_label->m_style =
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_static_name_label->m_left = ctrl_static_name_label_x;
	ctrl_static_name_label->m_top = ctrl_static_name_label_y;
	ctrl_static_name_label->m_width = ctrl_static_name_label_w;
	ctrl_static_name_label->m_height = ctrl_static_name_label_h;
	ctrl_static_name_label->m_id = s_mk_clib_app_file_explorer_ctrl_id_static_name_label;
	ctrl_static_name_label->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_static_name_label->m_class[1] = mk_win_user_dialog_class_id_static;
	for(i = 0; i != s_name_title_len; ++i) (&ctrl_static_name_label->m_title)[i] = s_name_title[i];
	ctrl2 = ((mk_win_user_dialog_itm_templateex_pt)(((mk_win_base_wchar_pt)(ctrl_static_name_label)) + (s_name_title_len - 1)));
	ctrl2->m_extra_count = 0;

	ctrl_edit_name_value = ((mk_win_user_dialog_itm_templateex_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_base_wchar_pct)(ctrl_static_name_label + 1)) + (s_name_title_len - 1), sizeof(mk_win_base_dword_t))));
	ctrl_edit_name_value->m_help_id = 0;
	ctrl_edit_name_value->m_style_ex = 0;
	ctrl_edit_name_value->m_style =
		mk_win_user_ctrl_edit_style_e_autohscroll |
		mk_win_user_ctrl_edit_style_e_readonly |
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_edit_name_value->m_left = ctrl_edit_name_value_x;
	ctrl_edit_name_value->m_top = ctrl_edit_name_value_y;
	ctrl_edit_name_value->m_width = ctrl_edit_name_value_w;
	ctrl_edit_name_value->m_height = ctrl_edit_name_value_h;
	ctrl_edit_name_value->m_id = s_mk_clib_app_file_explorer_ctrl_id_edit_name_value;
	ctrl_edit_name_value->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_edit_name_value->m_class[1] = mk_win_user_dialog_class_id_edit;
	ctrl_edit_name_value->m_title = 0;
	ctrl_edit_name_value->m_extra_count = 0;

	ctrl_static_type_label = ((mk_win_user_dialog_itm_templateex_pt)(mk_clib_app_file_explorer_round_up_s(ctrl_edit_name_value + 1, sizeof(mk_win_base_dword_t))));
	ctrl_static_type_label->m_help_id = 0;
	ctrl_static_type_label->m_style_ex = 0;
	ctrl_static_type_label->m_style =
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_static_type_label->m_left = ctrl_static_type_label_x;
	ctrl_static_type_label->m_top = ctrl_static_type_label_y;
	ctrl_static_type_label->m_width = ctrl_static_type_label_w;
	ctrl_static_type_label->m_height = ctrl_static_type_label_h;
	ctrl_static_type_label->m_id = s_mk_clib_app_file_explorer_ctrl_id_static_type_label;
	ctrl_static_type_label->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_static_type_label->m_class[1] = mk_win_user_dialog_class_id_static;
	for(i = 0; i != s_type_title_len; ++i) (&ctrl_static_type_label->m_title)[i] = s_type_title[i];
	ctrl2 = ((mk_win_user_dialog_itm_templateex_pt)(((mk_win_base_wchar_pt)(ctrl_static_type_label)) + (s_type_title_len - 1)));
	ctrl2->m_extra_count = 0;

	ctrl_edit_type_value = ((mk_win_user_dialog_itm_templateex_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_base_wchar_pct)(ctrl_static_type_label + 1)) + (s_type_title_len - 1), sizeof(mk_win_base_dword_t))));
	ctrl_edit_type_value->m_help_id = 0;
	ctrl_edit_type_value->m_style_ex = 0;
	ctrl_edit_type_value->m_style =
		mk_win_user_ctrl_edit_style_e_autohscroll |
		mk_win_user_ctrl_edit_style_e_readonly |
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_edit_type_value->m_left = ctrl_edit_type_value_x;
	ctrl_edit_type_value->m_top = ctrl_edit_type_value_y;
	ctrl_edit_type_value->m_width = ctrl_edit_type_value_w;
	ctrl_edit_type_value->m_height = ctrl_edit_type_value_h;
	ctrl_edit_type_value->m_id = s_mk_clib_app_file_explorer_ctrl_id_edit_type_value;
	ctrl_edit_type_value->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_edit_type_value->m_class[1] = mk_win_user_dialog_class_id_edit;
	ctrl_edit_type_value->m_title = 0;
	ctrl_edit_type_value->m_extra_count = 0;

	ctrl_static_detail_label = ((mk_win_user_dialog_itm_templateex_pt)(mk_clib_app_file_explorer_round_up_s(ctrl_edit_type_value + 1, sizeof(mk_win_base_dword_t))));
	ctrl_static_detail_label->m_help_id = 0;
	ctrl_static_detail_label->m_style_ex = 0;
	ctrl_static_detail_label->m_style =
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_static_detail_label->m_left = ctrl_static_detail_label_x;
	ctrl_static_detail_label->m_top = ctrl_static_detail_label_y;
	ctrl_static_detail_label->m_width = ctrl_static_detail_label_w;
	ctrl_static_detail_label->m_height = ctrl_static_detail_label_h;
	ctrl_static_detail_label->m_id = s_mk_clib_app_file_explorer_ctrl_id_static_detail_label;
	ctrl_static_detail_label->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_static_detail_label->m_class[1] = mk_win_user_dialog_class_id_static;
	for(i = 0; i != s_detail_title_len; ++i) (&ctrl_static_detail_label->m_title)[i] = s_detail_title[i];
	ctrl2 = ((mk_win_user_dialog_itm_templateex_pt)(((mk_win_base_wchar_pt)(ctrl_static_detail_label)) + (s_detail_title_len - 1)));
	ctrl2->m_extra_count = 0;

	ctrl_edit_detail_value = ((mk_win_user_dialog_itm_templateex_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_base_wchar_pct)(ctrl_static_detail_label + 1)) + (s_detail_title_len - 1), sizeof(mk_win_base_dword_t))));
	ctrl_edit_detail_value->m_help_id = 0;
	ctrl_edit_detail_value->m_style_ex = 0;
	ctrl_edit_detail_value->m_style =
		mk_win_user_ctrl_edit_style_e_autohscroll |
		mk_win_user_ctrl_edit_style_e_readonly |
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_edit_detail_value->m_left = ctrl_edit_detail_value_x;
	ctrl_edit_detail_value->m_top = ctrl_edit_detail_value_y;
	ctrl_edit_detail_value->m_width = ctrl_edit_detail_value_w;
	ctrl_edit_detail_value->m_height = ctrl_edit_detail_value_h;
	ctrl_edit_detail_value->m_id = s_mk_clib_app_file_explorer_ctrl_id_edit_detail_value;
	ctrl_edit_detail_value->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_edit_detail_value->m_class[1] = mk_win_user_dialog_class_id_edit;
	ctrl_edit_detail_value->m_title = 0;
	ctrl_edit_detail_value->m_extra_count = 0;

	ctrl_static_attributes = ((mk_win_user_dialog_itm_templateex_pt)(mk_clib_app_file_explorer_round_up_s(ctrl_edit_detail_value + 1, sizeof(mk_win_base_dword_t))));
	ctrl_static_attributes->m_help_id = 0;
	ctrl_static_attributes->m_style_ex = 0;
	ctrl_static_attributes->m_style =
		mk_win_user_window_style_e_child |
		0;
	ctrl_static_attributes->m_left = ctrl_static_attributes_label_x;
	ctrl_static_attributes->m_top = ctrl_static_attributes_label_y;
	ctrl_static_attributes->m_width = ctrl_static_attributes_label_w;
	ctrl_static_attributes->m_height = ctrl_static_attributes_label_h;
	ctrl_static_attributes->m_id = s_mk_clib_app_file_explorer_ctrl_id_static_attributes_label;
	ctrl_static_attributes->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_static_attributes->m_class[1] = mk_win_user_dialog_class_id_static;
	for(i = 0; i != s_attributes_title_len; ++i) (&ctrl_static_attributes->m_title)[i] = s_attributes_title[i];
	ctrl2 = ((mk_win_user_dialog_itm_templateex_pt)(((mk_win_base_wchar_pt)(ctrl_static_attributes)) + (s_attributes_title_len - 1)));
	ctrl2->m_extra_count = 0;

	ctrl_edit_attributes = ((mk_win_user_dialog_itm_templateex_pt)(mk_clib_app_file_explorer_round_up_s(((mk_win_base_wchar_pct)(ctrl_static_attributes + 1)) + (s_attributes_title_len - 1), sizeof(mk_win_base_dword_t))));
	ctrl_edit_attributes->m_help_id = 0;
	ctrl_edit_attributes->m_style_ex = 0;
	ctrl_edit_attributes->m_style =
		mk_win_user_ctrl_edit_style_e_autohscroll |
		mk_win_user_ctrl_edit_style_e_readonly |
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_visible |
		mk_win_user_window_style_e_child |
		0;
	ctrl_edit_attributes->m_left = ctrl_static_attributes_value_x;
	ctrl_edit_attributes->m_top = ctrl_static_attributes_value_y;
	ctrl_edit_attributes->m_width = ctrl_static_attributes_value_w;
	ctrl_edit_attributes->m_height = ctrl_static_attributes_value_h;
	ctrl_edit_attributes->m_id = s_mk_clib_app_file_explorer_ctrl_id_edit_attributes_value;
	ctrl_edit_attributes->m_class[0] = mk_win_user_dialog_class_is_atom;
	ctrl_edit_attributes->m_class[1] = mk_win_user_dialog_class_id_edit;
	ctrl_edit_attributes->m_title = 0;
	ctrl_edit_attributes->m_extra_count = 0;

	ctrl_listbox_attributes = ((mk_win_user_dialog_itm_templateex_pt)(mk_clib_app_file_explorer_round_up_s(ctrl_edit_attributes + 1, sizeof(mk_win_base_dword_t))));
	ctrl_listbox_attributes->m_help_id = 0;
	ctrl_listbox_attributes->m_style_ex = 0;
	ctrl_listbox_attributes->m_style =
		mk_win_user_window_style_e_tabstop |
		mk_win_user_window_style_e_vscroll |
		mk_win_user_window_style_e_border |
		mk_win_user_window_style_e_child |
		0;
	ctrl_listbox_attributes->m_left = ctrl_listbox_attributes_x;
	ctrl_listbox_attributes->m_top = ctrl_listbox_attributes_y;
	ctrl_listbox_attributes->m_width = ctrl_listbox_attributes_w;
	ctrl_listbox_attributes->m_height = ctrl_listbox_attributes_h;
	ctrl_listbox_attributes->m_id = s_mk_clib_app_file_explorer_ctrl_id_listbox_attributes_data;
	n = ((int)(sizeof(mk_win_user_ctrl_mlistbox_name_w) / sizeof(mk_win_user_ctrl_mlistbox_name_w[0])));
	for(i = 0; i != n; ++i) ctrl_listbox_attributes->m_class[i] = mk_win_user_ctrl_mlistbox_name_w[i];
	ctrl2 = ((mk_win_user_dialog_itm_templateex_pt)(((mk_win_base_wchar_pt)(ctrl_listbox_attributes)) + (n - 1)));
	ctrl2->m_title = 0;
	ctrl2->m_extra_count = 0;

	res = mk_win_user_dialog_t_indirect_param_ex(g_instance, dlg, mk_win_base_null, &mk_clib_app_file_explorer_dlgproc, 0);
	ret = ((int)(res));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_win_base_sshort_t mk_clib_app_file_explorer_max_f(mk_win_base_sshort_t const a, mk_win_base_sshort_t const b) mk_lang_noexcept
{
	return b < a ? a : b;
}

mk_lang_nodiscard static mk_lang_inline void* mk_clib_app_file_explorer_round_up_s(void const* ptr, mk_win_base_size_t const size) mk_lang_noexcept
{
	mk_lang_assert(ptr);
	mk_lang_assert(size > 0);

	return
	((void*)
	(
		((mk_win_base_uintptr_t)
		(
			((mk_win_base_uintptr_t)
			(
				((mk_win_base_uintptr_t)
				(
					((mk_win_base_uintptr_t)(((unsigned char const*)(ptr)))) +
					((mk_win_base_uintptr_t)(((mk_win_base_uintptr_t)(size)) - ((mk_win_base_uintptr_t)(1))))
				)) /
				((mk_win_base_uintptr_t)(size))
			)) *
			((mk_win_base_uintptr_t)(size))
		))
	));
}

mk_lang_nodiscard static mk_lang_inline void* mk_clib_app_file_explorer_round_up_i(void const* ptr, int const size) mk_lang_noexcept
{
	mk_lang_assert(ptr);
	mk_lang_assert(size > 0);

	return mk_clib_app_file_explorer_round_up_s(ptr, ((mk_win_base_size_t)(size)));
}

static mk_lang_inline void mk_clib_app_file_explorer_labels_clear(mk_win_user_window_t const dialog) mk_lang_noexcept
{
	static mk_win_tstring_tchar_t const s_text[] = mk_win_tstring_tchar_c("");

	mk_win_user_window_t ctrl;
	mk_win_user_window_lresult_t lr;

	mk_lang_assert(dialog);

	ctrl = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_edit_name_value); mk_lang_assert(ctrl);
	lr = mk_win_user_message_t_send(ctrl, mk_win_user_message_id_e_settext, 0, ((mk_win_user_window_lparam_t)(s_text))); ((void)(lr));

	ctrl = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_edit_type_value); mk_lang_assert(ctrl);
	lr = mk_win_user_message_t_send(ctrl, mk_win_user_message_id_e_settext, 0, ((mk_win_user_window_lparam_t)(s_text))); ((void)(lr));

	ctrl = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_edit_detail_value); mk_lang_assert(ctrl);
	lr = mk_win_user_message_t_send(ctrl, mk_win_user_message_id_e_settext, 0, ((mk_win_user_window_lparam_t)(s_text))); ((void)(lr));
}

static mk_lang_inline void mk_clib_app_file_explorer_on_selection(mk_win_user_window_t const dialog) mk_lang_noexcept
{
	mk_win_user_window_t listbox;
	mk_win_user_window_lresult_t lres;
	int idx;
	mk_lib_fe_lpt fe;
	mk_win_user_window_t ctrl;
	mk_win_tstring_tchar_lpct text;
	mk_win_user_window_t attr_label;
	mk_win_user_window_t attr_value;
	mk_win_user_window_t attr_data;
	mk_lang_bool_t has_attributes;
	mk_win_base_bool_t prev;
	mk_win_kernel_files_attribute_t attr;
	unsigned long int ul;
	mk_sl_cui_fe_t cui;
	char attr_str[2 + mk_sl_cui_fe_to_str_hex_full_len + 1];
	char* pstr;
	int len;

	mk_lang_assert(dialog);

	listbox = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_listbox_main); mk_lang_assert(listbox);
	lres = mk_win_user_message_t_send(listbox, mk_win_user_ctrl_mlistbox_message_e_getcursel, 0, 0);
	if(lres == ((mk_win_user_window_lresult_t)(mk_win_user_ctrl_mlistbox_err_e_err)))
	{
		mk_clib_app_file_explorer_labels_clear(dialog);
		return;
	}
	idx = ((int)(lres)); mk_lang_assert(idx >= 0);
	fe = ((mk_lib_fe_lpt)(mk_win_user_window_t_get_data(dialog, mk_win_user_window_data_idx_e_dlg_user))); mk_lang_assert(fe);

	ctrl = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_edit_name_value); mk_lang_assert(ctrl);
	text = mk_lib_fe_get_name_long_str(fe, idx); mk_lang_assert(text);
	lres = mk_win_user_message_t_send(ctrl, mk_win_user_message_id_e_settext, 0, ((mk_win_user_window_lparam_t)(mk_win_tstring_tstr_to_wnds_zt_nofail(text)))); ((void)(lres));

	ctrl = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_edit_type_value); mk_lang_assert(ctrl);
	text = mk_lib_fe_get_type_str(fe, idx); mk_lang_assert(text);
	lres = mk_win_user_message_t_send(ctrl, mk_win_user_message_id_e_settext, 0, ((mk_win_user_window_lparam_t)(mk_win_tstring_tstr_to_wnds_zt_nofail(text)))); ((void)(lres));

	ctrl = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_edit_detail_value); mk_lang_assert(ctrl);
	text = mk_lib_fe_get_detail_str(fe, idx); mk_lang_assert(text);
	lres = mk_win_user_message_t_send(ctrl, mk_win_user_message_id_e_settext, 0, ((mk_win_user_window_lparam_t)(mk_win_tstring_tstr_to_wnds_zt_nofail(text)))); ((void)(lres));

	attr_label = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_static_attributes_label); mk_lang_assert(ctrl);
	attr_value = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_edit_attributes_value); mk_lang_assert(ctrl);
	attr_data = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_listbox_attributes_data); mk_lang_assert(ctrl);
	has_attributes = mk_lib_fe_has_attributes(fe, idx);
	prev = mk_win_user_window_show(attr_label, has_attributes ? mk_win_user_window_show_e_showna : mk_win_user_window_show_e_hide); ((void)(prev));
	prev = mk_win_user_window_show(attr_value, has_attributes ? mk_win_user_window_show_e_showna : mk_win_user_window_show_e_hide); ((void)(prev));
	prev = mk_win_user_window_show(attr_data, has_attributes ? mk_win_user_window_show_e_showna : mk_win_user_window_show_e_hide); ((void)(prev));
	if(has_attributes)
	{
		attr = mk_lib_fe_get_attributes(fe, idx);
		ul = ((unsigned long int)(attr));
		mk_sl_cui_fe_from_bi_ulong(&cui, &ul);
		attr_str[0] = '0';
		attr_str[1] = 'x';
		pstr = attr_str + 2;
		len = mk_sl_cui_fe_to_str_hex_full_n(&cui, pstr, mk_sl_cui_fe_to_str_hex_full_len); mk_lang_assert(len == mk_sl_cui_fe_to_str_hex_full_len);
		pstr[len] = '\0';
		lres = mk_win_user_message_t_send(attr_value, mk_win_user_message_id_e_settext, 0, ((mk_win_user_window_lparam_t)(mk_win_tstring_tstr_to_wnds_zt_nofail(mk_win_tstring_asci_to_tstr_zt_nofail(attr_str).m_str)))); ((void)(lres));
		lres = mk_win_user_message_t_send(attr_data, mk_win_user_ctrl_mlistbox_message_e_set_strings_count, ((mk_win_user_window_wparam_t)(mk_sl_cui_fe_count_ones(&cui))), 0); ((void)(lres));
	}
}

static mk_lang_inline void mk_clib_app_file_explorer_listbox_repopulate(mk_win_user_window_t const dialog, mk_lib_fe_lpt const fe, int const select_idx) mk_lang_noexcept
{
	mk_win_user_window_t listbox;
	mk_win_user_window_lresult_t lres;
	int n;

	mk_lang_assert(dialog);
	mk_lang_assert(fe);

	listbox = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_listbox_main); mk_lang_assert(listbox);
	n = mk_lib_fe_get_count(fe); mk_lang_assert(n != 0); mk_lang_assert(select_idx < n);
	lres = mk_win_user_message_t_send(listbox, mk_win_user_ctrl_mlistbox_message_e_set_strings_count, ((mk_win_user_window_wparam_t)(n)), ((mk_win_user_window_lparam_t)(0))); ((void)(lres));
	lres = mk_win_user_message_t_send(listbox, mk_win_user_ctrl_mlistbox_message_e_setcursel, ((mk_win_user_window_wparam_t)(select_idx)), ((mk_win_user_window_lparam_t)(0))); mk_lang_assert(lres != ((mk_win_user_window_lresult_t)(mk_win_user_ctrl_mlistbox_err_e_err)));
	mk_clib_app_file_explorer_on_selection(dialog);
}

static mk_lang_inline void mk_clib_app_file_explorer_go_to_root(mk_win_user_window_t const dialog) mk_lang_noexcept
{
	mk_lib_fe_lpt fe;

	mk_lang_assert(dialog);

	fe = ((mk_lib_fe_lpt)(mk_win_user_window_t_get_data(dialog, mk_win_user_window_data_idx_e_dlg_user))); mk_lang_assert(fe);
	mk_lib_fe_go_to_root(fe);
	mk_clib_app_file_explorer_listbox_repopulate(dialog, fe, 0);
}

static mk_lang_inline void mk_clib_app_file_explorer_go_to_item_idx(mk_win_user_window_t const dialog, int const idx) mk_lang_noexcept
{
	mk_lib_fe_lpt fe;
	int depth_prev;
	int depth_post;
	int select_idx;

	mk_lang_assert(dialog);
	mk_lang_assert(idx >= 0);

	fe = ((mk_lib_fe_lpt)(mk_win_user_window_t_get_data(dialog, mk_win_user_window_data_idx_e_dlg_user))); mk_lang_assert(fe);
	depth_prev = mk_lib_fe_get_breadcrumb_depth(fe);
	if(mk_lib_fe_go_to_item(fe, idx))
	{
		depth_post = mk_lib_fe_get_breadcrumb_depth(fe);
		select_idx = ((depth_post < depth_prev) ? (mk_lang_min(mk_lib_fe_get_count(fe) - 1, mk_lib_fe_get_breadcrumb_value(fe))) : (0));
		mk_clib_app_file_explorer_listbox_repopulate(dialog, fe, select_idx);
	}
}

static mk_lang_inline void mk_clib_app_file_explorer_go_to_item_curr(mk_win_user_window_t const dialog) mk_lang_noexcept
{
	mk_win_user_window_t listbox_main;
	mk_win_user_window_lresult_t lr;
	int idx;

	listbox_main = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_listbox_main); mk_lang_assert(listbox_main);
	lr = mk_win_user_message_t_send(listbox_main, mk_win_user_ctrl_mlistbox_message_e_getcursel, 0, 0);
	if(lr == ((mk_win_user_window_lresult_t)(mk_win_user_ctrl_mlistbox_err_e_err)))
	{
		return;
	}
	idx = ((int)(lr)); mk_lang_assert(idx >= 0);
	mk_clib_app_file_explorer_go_to_item_idx(dialog, idx);
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_destroy(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_win_base_size_t size;
	mk_lib_fe_lpt fe;
	mk_win_base_uintptr_t prev_data;

	mk_lang_assert(dialog);
	((void)(wparam));
	((void)(lparam));
	((void)(override_lres));
	((void)(lres));

	size = mk_lib_fe_get_size(); mk_lang_assert(size != 0);
	fe = ((mk_lib_fe_lpt)(mk_win_user_window_t_get_data(dialog, mk_win_user_window_data_idx_e_dlg_user))); mk_lang_assert(fe);
	prev_data = mk_win_user_window_a_set_data(dialog, mk_win_user_window_data_idx_e_dlg_user, 0); mk_lang_assert(prev_data == ((mk_win_base_uintptr_t)(fe)));
	mk_lib_fe_destroy(fe);
	mk_win_main_heap_deallocate(fe, size);
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_close(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_win_base_bool_t ended;

	mk_lang_assert(dialog);
	((void)(wparam));
	((void)(lparam));
	((void)(override_lres));
	((void)(lres));

	ended = mk_win_user_dialog_end(dialog, 0); mk_lang_assert(ended != 0);
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify_listbox_main_return(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(dialog);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	mk_clib_app_file_explorer_go_to_item_curr(dialog);
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify_listbox_main_get_string(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_win_user_ctrl_mlistbox_notify_get_string_lpt get_string;
	mk_lib_fe_lpt fe;

	mk_lang_assert(dialog);
	mk_lang_assert(wparam == s_mk_clib_app_file_explorer_ctrl_id_listbox_main);
	mk_lang_assert(lparam != 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	get_string = ((mk_win_user_ctrl_mlistbox_notify_get_string_lpt)(lparam));
	mk_lang_assert(get_string->m_hdr.m_from_window == mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_listbox_main));
	mk_lang_assert(get_string->m_hdr.m_from_id == s_mk_clib_app_file_explorer_ctrl_id_listbox_main);
	mk_lang_assert(get_string->m_hdr.m_code == mk_win_user_ctrl_mlistbox_notify_e_get_string);

	fe = ((mk_lib_fe_lpt)(mk_win_user_window_t_get_data(dialog, mk_win_user_window_data_idx_e_dlg_user))); mk_lang_assert(fe);
	get_string->m_string = mk_lib_fe_get_name_short_str(fe, get_string->m_idx);
	get_string->m_string_length = mk_lib_fe_get_name_short_str_len(fe, get_string->m_idx);
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify_listbox_main(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_win_user_ctrl_mlistbox_nmhdr_lpt hdr;

	mk_lang_assert(dialog);
	mk_lang_assert(wparam == s_mk_clib_app_file_explorer_ctrl_id_listbox_main);
	mk_lang_assert(lparam != 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	hdr = ((mk_win_user_ctrl_mlistbox_nmhdr_lpt)(lparam));
	mk_lang_assert(hdr->m_from_window == mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_listbox_main));
	mk_lang_assert(hdr->m_from_id == s_mk_clib_app_file_explorer_ctrl_id_listbox_main);
	switch(hdr->m_code)
	{
		case mk_win_user_ctrl_mlistbox_notify_e_return: mk_clib_app_file_explorer_on_msg_notify_listbox_main_return(dialog, wparam, lparam, override_lres, lres); break;
		case mk_win_user_ctrl_mlistbox_notify_e_get_string: mk_clib_app_file_explorer_on_msg_notify_listbox_main_get_string(dialog, wparam, lparam, override_lres, lres); break;
	}
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify_listbox_attributes_get_string(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	static mk_win_tstring_tchar_t const* const s_attr_names[] =
	{
		mk_win_kernel_files_attribute_namet_e_readonly,
		mk_win_kernel_files_attribute_namet_e_hidden,
		mk_win_kernel_files_attribute_namet_e_system,
		mk_win_kernel_files_attribute_namet_e_unknown_3,
		mk_win_kernel_files_attribute_namet_e_directory,
		mk_win_kernel_files_attribute_namet_e_archive,
		mk_win_kernel_files_attribute_namet_e_device,
		mk_win_kernel_files_attribute_namet_e_normal,
		mk_win_kernel_files_attribute_namet_e_temporary,
		mk_win_kernel_files_attribute_namet_e_sparse_file,
		mk_win_kernel_files_attribute_namet_e_reparse_point,
		mk_win_kernel_files_attribute_namet_e_compressed,
		mk_win_kernel_files_attribute_namet_e_offline,
		mk_win_kernel_files_attribute_namet_e_not_content_indexed,
		mk_win_kernel_files_attribute_namet_e_encrypted,
		mk_win_kernel_files_attribute_namet_e_integrity_stream,
		mk_win_kernel_files_attribute_namet_e_virtual,
		mk_win_kernel_files_attribute_namet_e_no_scrub_data,
		mk_win_kernel_files_attribute_namet_e_ea,
		mk_win_kernel_files_attribute_namet_e_pinned,
		mk_win_kernel_files_attribute_namet_e_unpinned,
		mk_win_kernel_files_attribute_namet_e_unknown_21,
		mk_win_kernel_files_attribute_namet_e_recall_on_data_access,
		mk_win_kernel_files_attribute_namet_e_unknown_23,
		mk_win_kernel_files_attribute_namet_e_unknown_24,
		mk_win_kernel_files_attribute_namet_e_unknown_25,
		mk_win_kernel_files_attribute_namet_e_unknown_26,
		mk_win_kernel_files_attribute_namet_e_unknown_27,
		mk_win_kernel_files_attribute_namet_e_unknown_28,
		mk_win_kernel_files_attribute_namet_e_strictly_sequential,
		mk_win_kernel_files_attribute_namet_e_unknown_30,
		mk_win_kernel_files_attribute_namet_e_unknown_31,
	};
	static int const s_attr_names_lens[] =
	{
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_readonly) / sizeof(mk_win_kernel_files_attribute_namet_e_readonly[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_hidden) / sizeof(mk_win_kernel_files_attribute_namet_e_hidden[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_system) / sizeof(mk_win_kernel_files_attribute_namet_e_system[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_unknown_3) / sizeof(mk_win_kernel_files_attribute_namet_e_unknown_3[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_directory) / sizeof(mk_win_kernel_files_attribute_namet_e_directory[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_archive) / sizeof(mk_win_kernel_files_attribute_namet_e_archive[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_device) / sizeof(mk_win_kernel_files_attribute_namet_e_device[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_normal) / sizeof(mk_win_kernel_files_attribute_namet_e_normal[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_temporary) / sizeof(mk_win_kernel_files_attribute_namet_e_temporary[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_sparse_file) / sizeof(mk_win_kernel_files_attribute_namet_e_sparse_file[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_reparse_point) / sizeof(mk_win_kernel_files_attribute_namet_e_reparse_point[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_compressed) / sizeof(mk_win_kernel_files_attribute_namet_e_compressed[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_offline) / sizeof(mk_win_kernel_files_attribute_namet_e_offline[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_not_content_indexed) / sizeof(mk_win_kernel_files_attribute_namet_e_not_content_indexed[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_encrypted) / sizeof(mk_win_kernel_files_attribute_namet_e_encrypted[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_integrity_stream) / sizeof(mk_win_kernel_files_attribute_namet_e_integrity_stream[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_virtual) / sizeof(mk_win_kernel_files_attribute_namet_e_virtual[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_no_scrub_data) / sizeof(mk_win_kernel_files_attribute_namet_e_no_scrub_data[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_ea) / sizeof(mk_win_kernel_files_attribute_namet_e_ea[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_pinned) / sizeof(mk_win_kernel_files_attribute_namet_e_pinned[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_unpinned) / sizeof(mk_win_kernel_files_attribute_namet_e_unpinned[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_unknown_21) / sizeof(mk_win_kernel_files_attribute_namet_e_unknown_21[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_recall_on_data_access) / sizeof(mk_win_kernel_files_attribute_namet_e_recall_on_data_access[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_unknown_23) / sizeof(mk_win_kernel_files_attribute_namet_e_unknown_23[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_unknown_24) / sizeof(mk_win_kernel_files_attribute_namet_e_unknown_24[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_unknown_25) / sizeof(mk_win_kernel_files_attribute_namet_e_unknown_25[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_unknown_26) / sizeof(mk_win_kernel_files_attribute_namet_e_unknown_26[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_unknown_27) / sizeof(mk_win_kernel_files_attribute_namet_e_unknown_27[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_unknown_28) / sizeof(mk_win_kernel_files_attribute_namet_e_unknown_28[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_strictly_sequential) / sizeof(mk_win_kernel_files_attribute_namet_e_strictly_sequential[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_unknown_30) / sizeof(mk_win_kernel_files_attribute_namet_e_unknown_30[0]) - 1)),
		((int)(sizeof(mk_win_kernel_files_attribute_namet_e_unknown_31) / sizeof(mk_win_kernel_files_attribute_namet_e_unknown_31[0]) - 1)),
	};

	mk_win_user_ctrl_mlistbox_notify_get_string_lpt get_string;
	int attr_idx;
	mk_win_user_window_t listbox;
	mk_win_user_window_lresult_t lr;
	int item_idx;
	mk_lib_fe_lpt fe;
	mk_win_kernel_files_attribute_t attr;
	unsigned long int ul;
	int i;

	mk_lang_assert(dialog);
	mk_lang_assert(wparam == s_mk_clib_app_file_explorer_ctrl_id_listbox_attributes_data);
	mk_lang_assert(lparam != 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	get_string = ((mk_win_user_ctrl_mlistbox_notify_get_string_lpt)(lparam));
	mk_lang_assert(get_string->m_hdr.m_from_window == mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_listbox_attributes_data));
	mk_lang_assert(get_string->m_hdr.m_from_id == s_mk_clib_app_file_explorer_ctrl_id_listbox_attributes_data);
	mk_lang_assert(get_string->m_hdr.m_code == mk_win_user_ctrl_mlistbox_notify_e_get_string);
	attr_idx = ((int)(get_string->m_idx)); mk_lang_assert(attr_idx >= 0);

	listbox = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_listbox_main); mk_lang_assert(listbox);
	lr = mk_win_user_message_t_send(listbox, mk_win_user_ctrl_mlistbox_message_e_getcursel, 0, 0);
	mk_lang_assert(lr != ((mk_win_user_window_lresult_t)(mk_win_user_ctrl_mlistbox_err_e_err)));
	item_idx = ((int)(lr)); mk_lang_assert(item_idx >= 0);

	fe = ((mk_lib_fe_lpt)(mk_win_user_window_t_get_data(dialog, mk_win_user_window_data_idx_e_dlg_user))); mk_lang_assert(fe);
	mk_lang_assert(mk_lib_fe_has_attributes(fe, item_idx));
	attr = mk_lib_fe_get_attributes(fe, item_idx);
	ul = ((unsigned long int)(attr));

	for(i = 0; i != 32; ++i)
	{
		if((ul & 0x01) != 0)
		{
			if(attr_idx == 0)
			{
				break;
			}
			--attr_idx;
		}
		ul >>= 1;
	}
	mk_lang_assert(i != 32);
	get_string->m_string = s_attr_names[i];
	get_string->m_string_length = s_attr_names_lens[i];
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify_listbox_attributes(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_win_user_ctrl_mlistbox_nmhdr_lpt hdr;

	mk_lang_assert(dialog);
	mk_lang_assert(wparam == s_mk_clib_app_file_explorer_ctrl_id_listbox_attributes_data);
	mk_lang_assert(lparam != 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	hdr = ((mk_win_user_ctrl_mlistbox_nmhdr_lpt)(lparam));
	mk_lang_assert(hdr->m_from_window == mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_listbox_attributes_data));
	mk_lang_assert(hdr->m_from_id == s_mk_clib_app_file_explorer_ctrl_id_listbox_attributes_data);
	switch(hdr->m_code)
	{
		case mk_win_user_ctrl_mlistbox_notify_e_get_string: mk_clib_app_file_explorer_on_msg_notify_listbox_attributes_get_string(dialog, wparam, lparam, override_lres, lres); break;
	}
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_notify(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(dialog);
	mk_lang_assert(lparam != 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	switch(wparam)
	{
		case s_mk_clib_app_file_explorer_ctrl_id_listbox_main: mk_clib_app_file_explorer_on_msg_notify_listbox_main(dialog, wparam, lparam, override_lres, lres); break;
		case s_mk_clib_app_file_explorer_ctrl_id_listbox_attributes_data: mk_clib_app_file_explorer_on_msg_notify_listbox_attributes(dialog, wparam, lparam, override_lres, lres); break;
	}
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_initdialog(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_win_user_window_t parent;
	mk_win_base_bool_t got;
	mk_win_base_rect_t parent_rect;
	mk_win_base_rect_t dialog_rect;
	mk_win_base_bool_t set;
	mk_lang_exception_t ex;
	mk_win_base_size_t size;
	mk_lib_fe_lpt fe;
	mk_win_base_uintptr_t prev_data;
	mk_win_user_window_t listbox;
	mk_win_user_window_t prev_focus;

	mk_lang_assert(dialog);
	((void)(wparam));
	((void)(lparam));
	((void)(override_lres));
	((void)(lres));

	parent = mk_win_user_window_get_parent(dialog);
	if(!parent)
	{
		parent = mk_win_user_window_get_desktop();
	}
	mk_lang_assert(parent);
	got = mk_win_user_window_get_rect(parent, &parent_rect); mk_lang_assert(got != 0);
	got = mk_win_user_window_get_rect(dialog, &dialog_rect); mk_lang_assert(got != 0);
	set = mk_win_user_window_set_pos(dialog, mk_win_base_null, ((parent_rect.m_right - parent_rect.m_left) - (dialog_rect.m_right - dialog_rect.m_left)) / 2, ((parent_rect.m_bottom - parent_rect.m_top) - (dialog_rect.m_bottom - dialog_rect.m_top)) / 2, 0, 0, mk_win_user_window_swp_e_nosize) mk_lang_noexcept; mk_lang_assert(set != 0);

	mk_lang_exception_make_none(&ex);
	size = mk_lib_fe_get_size(); mk_lang_assert(size != 0);
	mk_win_main_heap_allocate(&ex, size, &fe); mk_lang_assert(!mk_lang_exception_is(&ex));
	mk_lib_fe_construct(fe);
	prev_data = mk_win_user_window_a_set_data(dialog, mk_win_user_window_data_idx_e_dlg_user, ((mk_win_base_uintptr_t)(fe))); mk_lang_assert(prev_data == 0);

	mk_clib_app_file_explorer_go_to_root(dialog);
	listbox = mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_listbox_main); mk_lang_assert(listbox);
	prev_focus = mk_win_user_window_set_focus(listbox); ((void)(prev_focus));
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_command_list_selchange(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(dialog);
	((void)(wparam));
	mk_lang_assert(lparam != 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);
	mk_lang_assert(((mk_win_user_window_t)(lparam)) == mk_win_user_dialog_get_item(dialog, s_mk_clib_app_file_explorer_ctrl_id_listbox_main));

	mk_clib_app_file_explorer_on_selection(dialog);
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_command_list_dblclk(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(dialog);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	mk_clib_app_file_explorer_go_to_item_curr(dialog);
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_command_list(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_win_base_word_t hi;
	mk_win_base_word_t notify_id;

	mk_lang_assert(dialog);

	hi = ((mk_win_base_word_t)(wparam >> 16));
	notify_id = hi;
	switch(notify_id)
	{
		case mk_win_user_ctrl_mlistbox_notify_e_selchange: mk_clib_app_file_explorer_on_msg_command_list_selchange(dialog, wparam, lparam, override_lres, lres); break;
		case mk_win_user_ctrl_mlistbox_notify_e_dblclk: mk_clib_app_file_explorer_on_msg_command_list_dblclk(dialog, wparam, lparam, override_lres, lres); break;
	}
}

static mk_lang_inline void mk_clib_app_file_explorer_on_msg_command(mk_win_user_window_t const dialog, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_base_sintptr_pt const lres) mk_lang_noexcept
{
	mk_win_base_word_t lo;
	mk_win_base_word_t hi;
	mk_win_base_word_t menu_id;
	mk_win_base_word_t acc_id;
	mk_win_base_word_t notify_id;
	mk_win_base_word_t ctrl_id;
	mk_win_user_window_t ctrl;

	mk_lang_assert(dialog);

	lo = ((mk_win_base_word_t)(wparam >>  0));
	hi = ((mk_win_base_word_t)(wparam >> 16));
	if(hi == 0 && lparam == 0)
	{
		menu_id = lo;
	}
	else if(hi == 1 && lparam == 0)
	{
		acc_id = lo;
	}
	else
	{
		mk_lang_assert(lparam != 0);
		notify_id = hi;
		ctrl_id = lo;
		ctrl = ((mk_win_user_window_t)(lparam));
		mk_lang_assert(mk_win_user_dialog_get_item(dialog, ctrl_id) == ctrl);
		switch(ctrl_id)
		{
			case s_mk_clib_app_file_explorer_ctrl_id_listbox_main: mk_clib_app_file_explorer_on_msg_command_list(dialog, wparam, lparam, override_lres, lres); break;
		}
	}
}

static mk_win_base_sintptr_t mk_win_base_stdcall mk_clib_app_file_explorer_dlgproc(mk_win_user_window_t const dialog, mk_win_base_uint_t const msg_uid, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(push)
	#pragma warning(disable:4062) /* warning C4062: enumerator 'xxx' in switch of enum 'xxx' is not handled */
	#endif

	mk_win_user_message_id_t msg_id;
	mk_lang_bool_t override_lres;
	mk_win_base_sintptr_t lres;
	mk_win_base_uintptr_t prev;

	mk_lang_assert(dialog);

	msg_id = ((mk_win_user_message_id_t)(msg_uid));
	override_lres = mk_lang_false;
	mk_lang_clobber(&lres);
	switch(msg_id)
	{
		case mk_win_user_message_id_e_destroy: mk_clib_app_file_explorer_on_msg_destroy(dialog, wparam, lparam, &override_lres, &lres); break;
		case mk_win_user_message_id_e_close: mk_clib_app_file_explorer_on_msg_close(dialog, wparam, lparam, &override_lres, &lres); break;
		case mk_win_user_message_id_e_notify: mk_clib_app_file_explorer_on_msg_notify(dialog, wparam, lparam, &override_lres, &lres); break;
		case mk_win_user_message_id_e_initdialog: mk_clib_app_file_explorer_on_msg_initdialog(dialog, wparam, lparam, &override_lres, &lres); break;
		case mk_win_user_message_id_e_command: mk_clib_app_file_explorer_on_msg_command(dialog, wparam, lparam, &override_lres, &lres); break;
	}
	if(override_lres)
	{
		if
		(
			msg_id == mk_win_user_message_id_e_vkeytoitem ||
			msg_id == mk_win_user_message_id_e_chartoitem ||
			msg_id == mk_win_user_message_id_e_querydragicon ||
			msg_id == mk_win_user_message_id_e_compareitem ||
			msg_id == mk_win_user_message_id_e_initdialog ||
			msg_id == mk_win_user_message_id_e_ctlcoloredit ||
			msg_id == mk_win_user_message_id_e_ctlcolorlistbox ||
			msg_id == mk_win_user_message_id_e_ctlcolorbtn ||
			msg_id == mk_win_user_message_id_e_ctlcolordlg ||
			msg_id == mk_win_user_message_id_e_ctlcolorscrollbar ||
			msg_id == mk_win_user_message_id_e_ctlcolorstatic ||
			mk_lang_false
		)
		{
			return ((mk_win_base_sintptr_t)(lres));
		}
		else
		{
			prev = mk_win_user_window_t_set_data(dialog, mk_win_user_window_data_idx_e_dlg_msgresult, ((mk_win_base_uintptr_t)(override_lres))); mk_lang_assert(prev == 0);
			return ((mk_win_base_sintptr_t)(mk_win_base_true));
		}
	}
	return ((mk_win_base_sintptr_t)(mk_win_base_false));

	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(pop)
	#endif
}
