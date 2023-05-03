#include "mk_clib_app_simple_window.h"

#include "mk_lang_assert.h"
#include "mk_lang_exception.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_ctrl_impl_mprogressbar.h"
#include "mk_win_gdi_font.h"
#include "mk_win_main_heap.h"
#include "mk_win_tstring.h"
#include "mk_win_user_brush.h"
#include "mk_win_user_class.h"
#include "mk_win_user_color.h"
#include "mk_win_user_ctrl_edit.h"
#include "mk_win_user_ctrl_mprogressbar.h"
#include "mk_win_user_ctrl_static.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_dialog.h"
#include "mk_win_user_icon.h"
#include "mk_win_user_message.h"
#include "mk_win_user_timer.h"
#include "mk_win_user_window.h"


static mk_win_base_instance_t g_instance;
static mk_win_user_dialog_two_ints_t g_size_margin;
static mk_win_user_dialog_two_ints_t g_size_related_unrelated;
static mk_win_user_dialog_two_ints_t g_size_edit;
static mk_win_user_dialog_two_ints_t g_size_static;
static mk_win_user_dialog_two_ints_t g_size_progressbar;


struct mk_clib_app_simple_window_context_s
{
	mk_win_user_window_t m_self;
	mk_win_user_window_t m_edit;
	mk_win_user_window_t m_static;
	mk_win_user_window_t m_progressbar;
	mk_win_base_dword_t m_time;
};
typedef struct mk_clib_app_simple_window_context_s mk_clib_app_simple_window_context_t;
typedef mk_clib_app_simple_window_context_t const mk_clib_app_simple_window_context_ct;
typedef mk_clib_app_simple_window_context_t* mk_clib_app_simple_window_context_pt;
typedef mk_clib_app_simple_window_context_t const* mk_clib_app_simple_window_context_pct;
typedef mk_clib_app_simple_window_context_t mk_win_base_far* mk_clib_app_simple_window_context_lpt;
typedef mk_clib_app_simple_window_context_t mk_win_base_far const* mk_clib_app_simple_window_context_lpct;
typedef mk_clib_app_simple_window_context_t mk_win_base_near* mk_clib_app_simple_window_context_npt;
typedef mk_clib_app_simple_window_context_t mk_win_base_near const* mk_clib_app_simple_window_context_npct;


mk_win_base_dll_import void mk_win_base_stdcall InitCommonControls(void) mk_lang_noexcept; /* todo move to commctrls */
mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetTickCount(void) mk_lang_noexcept; /* todo move to time */


static mk_lang_inline void mk_clib_app_simple_window_on_msg_create(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_simple_window_on_msg_destroy(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_simple_window_on_msg_setfocus(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_simple_window_on_msg_command_menu(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_simple_window_on_msg_command_acc(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_simple_window_on_msg_command_ctrl_edit_change(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_simple_window_on_msg_command_ctrl_edit(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_simple_window_on_msg_command_ctrl(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_simple_window_on_msg_command(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_simple_window_on_msg_timer(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_simple_window_on_msg_ctlcolorstatic(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_lang_inline void mk_clib_app_simple_window_on_msg(mk_clib_app_simple_window_context_lpt const context, mk_win_user_message_id_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept;
static mk_win_user_window_lresult_t mk_win_base_stdcall mk_clib_app_simple_window_wndproc(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;


static mk_win_base_uintptr_t const s_timer_id = 42;


mk_lang_jumbo int mk_clib_app_simple_window_winmain(mk_win_base_instance_t const instance, mk_win_base_instance_t const previous, mk_win_tstring_tchar_lpct const cmd, int const show) mk_lang_noexcept
{
	static mk_win_tstring_tchar_t const s_class_name[] = mk_win_tstring_tchar_c("simple_window");
	static mk_win_tstring_tchar_t const s_window_name[] = mk_win_tstring_tchar_c("Simple Window");

	mk_win_user_class_t_t wc;
	mk_win_kernel_atom_t atom;
	mk_win_user_window_t window;
	mk_win_base_bool_t shown;
	mk_win_base_bool_t updated;
	mk_win_base_uintptr_t timer;
	mk_win_base_bool_t got_message;
	mk_win_user_message_t message;
	mk_win_base_bool_t translated;
	mk_win_user_window_lresult_t lresult;
	mk_win_base_bool_t unregistered;

	mk_lang_assert(instance);

	mk_lang_exception_test();
	mk_win_main_heap_create();
	mk_win_tstring_init();
	InitCommonControls();
	mk_win_ctrl_impl_mprogressbar_register();

	g_instance = instance;
	g_size_margin = mk_win_user_dialog_get_ctrl_size_margins(g_instance);
	g_size_related_unrelated = mk_win_user_dialog_get_ctrl_size_related_unrelated(g_instance);
	g_size_edit = mk_win_user_dialog_get_ctrl_size_edit(g_instance);
	g_size_static = mk_win_user_dialog_get_ctrl_size_static(g_instance);
	g_size_progressbar = mk_win_user_dialog_get_ctrl_size_progressbar(g_instance);

	wc.m_style = mk_win_user_class_style_e_vredraw | mk_win_user_class_style_e_hredraw;
	wc.m_wndproc = &mk_clib_app_simple_window_wndproc;
	wc.m_class_extra = 0;
	wc.m_wnd_extra = sizeof(mk_win_base_void_lpt);
	wc.m_instance = g_instance;
	wc.m_icon = mk_win_user_icon_t_load_by_id(mk_win_base_null, mk_win_user_icon_id_e_application);
	wc.m_cursor = mk_win_user_cursor_t_load_by_id(mk_win_user_cursor_id_e_arrow);
	wc.m_background = ((mk_win_user_brush_t)(((mk_win_base_uintptr_t)(mk_win_user_color_id_e_window + 1))));
	wc.m_menu_name = mk_win_base_null;
	wc.m_class_name = s_class_name;
	atom = mk_win_user_class_t_register(&wc);
	mk_lang_assert(atom != 0);

	window = mk_win_user_window_t_create_by_name
	(
		mk_win_user_window_style_ex_e_overlappedwindow,
		s_class_name,
		s_window_name,
		mk_win_user_window_style_e_overlappedwindow,
		mk_win_user_window_usedefault,
		mk_win_user_window_usedefault,
		mk_win_user_window_usedefault,
		mk_win_user_window_usedefault,
		mk_win_base_null,
		mk_win_base_null,
		g_instance,
		mk_win_base_null
	);
	mk_lang_assert(window);
	shown = mk_win_user_window_show(window, show); ((void)(shown));
	updated = mk_win_user_window_update(window);
	mk_lang_assert(updated != mk_win_base_false);

	timer = mk_win_user_timer_set(window, s_timer_id, 1, mk_win_base_null);
	mk_lang_assert(timer == s_timer_id); /* todo rly? */

	for(;;)
	{
		got_message = mk_win_user_message_t_get(&message, mk_win_base_null, 0, 0);
		mk_lang_assert(got_message != -1);
		mk_lang_assert(got_message != 0 || message.m_message_id == mk_win_user_message_id_e_quit);
		if(got_message == 0)
		{
			break;
		}
		translated = mk_win_user_message_translate(&message); ((void)(translated));
		lresult = mk_win_user_message_t_dispatch(&message); ((void)(lresult));
	}

	unregistered = mk_win_user_class_t_unregister_by_atom(atom, g_instance);
	mk_lang_assert(unregistered == mk_win_base_true);

	mk_win_ctrl_impl_mprogressbar_unregister();
	mk_win_tstring_deinit();
	mk_win_main_heap_destroy();

	return 0;
}


static mk_lang_inline void mk_clib_app_simple_window_on_msg_create(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
	mk_win_base_void_lpct font_data;
	mk_win_base_handle_t font;
	mk_win_user_window_lresult_t sent;
	mk_win_user_window_t edit;
	mk_win_user_window_t statik;
	mk_win_user_window_t progressbar;
	int width;
	int height;
	mk_win_base_bool_t got;
	mk_win_base_rect_t window_rect;
	mk_win_base_rect_t client_rect;
	mk_win_base_bool_t set;

	mk_lang_assert(context);
	mk_lang_assert(context->m_self);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	font_data = mk_win_user_dialog_get_ctrl_font();
	mk_lang_assert(font_data);
	font = mk_win_gdi_font_t_create_indirect(font_data); /* todo destroy font? */
	mk_lang_assert(font);
	sent = mk_win_user_message_t_send(context->m_self, mk_win_user_message_id_e_setfont, ((mk_win_user_window_lparam_t)(font)), 0);
	((void)(sent));

	edit = mk_win_user_window_t_create_by_name
	(
		0,
		mk_win_user_ctrl_edit_name_t,
		mk_win_tstring_tchar_c(""),
			mk_win_user_ctrl_edit_style_e_nohidesel |
			mk_win_user_window_style_e_tabstop |
			mk_win_user_window_style_e_border |
			mk_win_user_window_style_e_visible |
			mk_win_user_window_style_e_child |
			0,
		g_size_margin.m_a,
		g_size_margin.m_b,
		g_size_edit.m_a,
		g_size_edit.m_b,
		context->m_self,
		mk_win_base_null,
		g_instance,
		mk_win_base_null
	);
	mk_lang_assert(edit);
	context->m_edit = edit;
	sent = mk_win_user_message_t_send(context->m_edit, mk_win_user_message_id_e_setfont, ((mk_win_user_window_lparam_t)(font)), 0);
	((void)(sent));

	statik = mk_win_user_window_t_create_by_name
	(
		0,
		mk_win_user_ctrl_static_name_t,
		mk_win_tstring_tchar_c(""),
			0 |
			mk_win_user_window_style_e_visible |
			mk_win_user_window_style_e_child |
			0,
		g_size_margin.m_a,
		g_size_margin.m_b + g_size_edit.m_b + g_size_related_unrelated.m_a,
		g_size_static.m_a,
		g_size_static.m_b,
		context->m_self,
		mk_win_base_null,
		g_instance,
		mk_win_base_null
	);
	mk_lang_assert(statik);
	context->m_static = statik;
	sent = mk_win_user_message_t_send(context->m_static, mk_win_user_message_id_e_setfont, ((mk_win_user_window_lparam_t)(font)), 0);
	((void)(sent));

	progressbar = mk_win_user_window_t_create_by_name
	(
		0,
		mk_win_user_ctrl_mprogressbar_name_t,
		mk_win_tstring_tchar_c(""),
			0 |
			mk_win_user_window_style_e_visible |
			mk_win_user_window_style_e_child |
			0,
		g_size_margin.m_a,
		g_size_margin.m_b + g_size_edit.m_b + g_size_related_unrelated.m_a + g_size_static.m_b + g_size_related_unrelated.m_a,
		g_size_progressbar.m_a,
		g_size_progressbar.m_b,
		context->m_self,
		mk_win_base_null,
		g_instance,
		mk_win_base_null
	);
	mk_lang_assert(progressbar);
	context->m_progressbar = progressbar;
	sent = mk_win_user_message_t_send(context->m_progressbar, mk_win_user_message_id_e_setfont, ((mk_win_user_window_lparam_t)(font)), 0);
	((void)(sent));

	context->m_time = GetTickCount();

	width = g_size_margin.m_a + mk_lang_max(mk_lang_max(g_size_edit.m_a, g_size_static.m_a), g_size_progressbar.m_a) + g_size_margin.m_a;
	height = g_size_margin.m_b + g_size_edit.m_b + g_size_related_unrelated.m_a + g_size_static.m_b + g_size_related_unrelated.m_b + g_size_progressbar.m_b + g_size_margin.m_b;
	got = mk_win_user_window_get_rect(context->m_self, &window_rect);
	mk_lang_assert(got != 0);
	got = mk_win_user_window_get_client_rect(context->m_self, &client_rect);
	mk_lang_assert(got != 0);
	mk_lang_assert(client_rect.m_left == 0 && client_rect.m_top == 0);
	set = mk_win_user_window_set_pos(context->m_self, mk_win_base_null, 0, 0, width + ((window_rect.m_right - window_rect.m_left) - client_rect.m_right), height + ((window_rect.m_bottom - window_rect.m_top) - client_rect.m_bottom), mk_win_user_window_swp_e_nomove | mk_win_user_window_swp_e_nozorder);
	mk_lang_assert(set != 0);
}

static mk_lang_inline void mk_clib_app_simple_window_on_msg_destroy(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
	mk_win_base_bool_t killed;

	mk_lang_assert(context);
	mk_lang_assert(context->m_self);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	killed = mk_win_user_timer_kill(context->m_self, s_timer_id);
	mk_lang_assert(killed != 0);
}

static mk_lang_inline void mk_clib_app_simple_window_on_msg_setfocus(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
	mk_win_user_window_t prev;

	mk_lang_assert(context);
	mk_lang_assert(context->m_self);
	mk_lang_assert(context->m_edit);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	prev = mk_win_user_window_set_focus(context->m_edit); ((void)(prev));
}

static mk_lang_inline void mk_clib_app_simple_window_on_msg_command_menu(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
}

static mk_lang_inline void mk_clib_app_simple_window_on_msg_command_acc(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
}

static mk_lang_inline void mk_clib_app_simple_window_on_msg_command_ctrl_edit_change(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
	#define text_len 1024

	mk_win_tstring_tchar_t text[text_len];
	int got;
	mk_win_base_bool_t set;

	mk_lang_assert(context);
	mk_lang_assert(context->m_self);
	mk_lang_assert(context->m_edit);
	mk_lang_assert(((mk_win_base_ushort_t)(wparam >> 16)) == mk_win_user_ctrl_edit_notify_e_change);
	mk_lang_assert(((mk_win_user_window_t)(lparam)) == context->m_edit);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	text[0] = mk_win_tstring_tchar_c('\0');
	got = mk_win_user_window_t_get_text(context->m_edit, text, text_len);
	mk_lang_assert(got >= 0);
	set = mk_win_user_window_t_set_text(context->m_static, text);
	mk_lang_assert(set != 0);

	#undef text_len
}

static mk_lang_inline void mk_clib_app_simple_window_on_msg_command_ctrl_edit(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
	mk_win_base_ushort_t code;

	mk_lang_assert(context);
	mk_lang_assert(context->m_self);
	mk_lang_assert(context->m_edit);
	mk_lang_assert(((mk_win_user_window_t)(lparam)) == context->m_edit);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	code = ((mk_win_base_ushort_t)(wparam >> 16));
	switch(code)
	{
		case mk_win_user_ctrl_edit_notify_e_setfocus: break;
		case mk_win_user_ctrl_edit_notify_e_killfocus: break;
		case mk_win_user_ctrl_edit_notify_e_change: mk_clib_app_simple_window_on_msg_command_ctrl_edit_change(context, wparam, lparam, override_lres, lres); break;
		case mk_win_user_ctrl_edit_notify_e_update: break;
		case mk_win_user_ctrl_edit_notify_e_errspace: break;
		case mk_win_user_ctrl_edit_notify_e_maxtext: break;
		case mk_win_user_ctrl_edit_notify_e_hscroll: break;
		case mk_win_user_ctrl_edit_notify_e_vscroll: break;
		case mk_win_user_ctrl_edit_notify_e_align_ltr_ec: break;
		case mk_win_user_ctrl_edit_notify_e_align_rtl_ec: break;
		case mk_win_user_ctrl_edit_notify_e_before_paste: break;
		case mk_win_user_ctrl_edit_notify_e_after_paste: break;
	}
}

static mk_lang_inline void mk_clib_app_simple_window_on_msg_command_ctrl(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
	mk_win_user_window_t ctrl;

	mk_lang_assert(context);
	mk_lang_assert(context->m_self);
	mk_lang_assert(context->m_edit);
	mk_lang_assert(lparam != 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	ctrl = ((mk_win_user_window_t)(lparam));
	if(ctrl == context->m_edit)
	{
		mk_clib_app_simple_window_on_msg_command_ctrl_edit(context, wparam, lparam, override_lres, lres);
	}
}

static mk_lang_inline void mk_clib_app_simple_window_on_msg_command(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
	mk_lang_assert(context);
	mk_lang_assert(context->m_self);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	switch(wparam)
	{
		case 0: mk_clib_app_simple_window_on_msg_command_menu(context, wparam, lparam, override_lres, lres); break;
		case 1: mk_clib_app_simple_window_on_msg_command_acc(context, wparam, lparam, override_lres, lres); break;
		default: mk_clib_app_simple_window_on_msg_command_ctrl(context, wparam, lparam, override_lres, lres); break;
	}
}

static mk_lang_inline void mk_clib_app_simple_window_on_msg_timer(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
	mk_win_base_dword_t time;
	mk_win_base_dword_t time_delta;
	mk_win_user_window_lresult_t lrpos;
	int ipos;
	mk_win_user_window_wparam_t wpos;
	mk_win_user_window_lresult_t set;

	mk_lang_assert(context);
	mk_lang_assert(context->m_self);
	mk_lang_assert(context->m_progressbar);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);
	mk_lang_assert(((mk_win_base_uintptr_t)(wparam)) == s_timer_id);
	mk_lang_assert(lparam == 0);

	time = GetTickCount();
	time_delta = mk_lang_min(1000, time - context->m_time);
	context->m_time = time;
	lrpos = mk_win_user_message_t_send(context->m_progressbar, mk_win_user_ctrl_mprogressbar_message_e_get_position, 0, 0);
	mk_lang_assert(lrpos >= 0 && lrpos <= 10000);
	ipos = ((int)(lrpos));
	ipos += (time_delta * 10000) / (5 * 1000); /* 5 seconds round trip */
	if(ipos > 10000) ipos -= 10000;
	wpos = ((mk_win_user_window_wparam_t)(ipos));
	set = mk_win_user_message_t_send(context->m_progressbar, mk_win_user_ctrl_mprogressbar_message_e_set_position, wpos, 0);
	((void)(set));
}

static mk_lang_inline void mk_clib_app_simple_window_on_msg_ctlcolorstatic(mk_clib_app_simple_window_context_lpt const context, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
	mk_win_gdi_dc_t dc;
	mk_win_user_brush_t brush;

	mk_lang_assert(context);
	mk_lang_assert(context->m_self);
	mk_lang_assert(context->m_static);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);
	mk_lang_assert(wparam != 0);
	mk_lang_assert(lparam != 0);

	dc = ((mk_win_gdi_dc_t)(wparam));
	brush = mk_win_user_brush_get_syscolor(mk_win_user_color_id_e_window); mk_lang_assert(brush);
	*lres = ((mk_win_user_window_lresult_t)(brush));
	*override_lres = mk_lang_true;
}

static mk_lang_inline void mk_clib_app_simple_window_on_msg(mk_clib_app_simple_window_context_lpt const context, mk_win_user_message_id_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_t* const override_lres, mk_win_user_window_lresult_t* const lres) mk_lang_noexcept
{
	mk_lang_assert(context);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	switch(message)
	{
		case mk_win_user_message_id_e_create: mk_clib_app_simple_window_on_msg_create(context, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_destroy: mk_clib_app_simple_window_on_msg_destroy(context, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_setfocus: mk_clib_app_simple_window_on_msg_setfocus(context, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_command: mk_clib_app_simple_window_on_msg_command(context, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_timer: mk_clib_app_simple_window_on_msg_timer(context, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_ctlcolorstatic: mk_clib_app_simple_window_on_msg_ctlcolorstatic(context, wparam, lparam, override_lres, lres); break;
	}
}

static mk_win_user_window_lresult_t mk_win_base_stdcall mk_clib_app_simple_window_wndproc(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_message_id_t message_id;
	mk_lang_exception_t ex;
	mk_clib_app_simple_window_context_lpt context;
	mk_win_base_uintptr_t data;
	mk_lang_bool_t override_lres;
	mk_win_user_window_lresult_t lres;

	message_id = ((mk_win_user_message_id_t)(message));
	if(message_id == mk_win_user_message_id_e_create)
	{
		mk_lang_exception_make_none(&ex);
		mk_win_main_heap_allocate(&ex, sizeof(*context), &context);
		if(mk_lang_exception_is(&ex))
		{
			return -1;
		}
		mk_lang_assert(context);
		context->m_self = window;
		data = mk_win_user_window_t_set_data(window, mk_win_user_window_data_idx_e_custom, ((mk_win_base_uintptr_t)(context)));
		mk_lang_assert(data == 0);
	}
	context = ((mk_clib_app_simple_window_context_lpt)(mk_win_user_window_t_get_data(window, mk_win_user_window_data_idx_e_custom)));
	mk_lang_assert(!context || context->m_self == window);
	override_lres = mk_lang_false;
	if(context)
	{
		mk_clib_app_simple_window_on_msg(context, message_id, wparam, lparam, &override_lres, &lres);
	}
	if(message_id == mk_win_user_message_id_e_destroy)
	{
		data = mk_win_user_window_t_set_data(window, mk_win_user_window_data_idx_e_custom, 0);
		mk_lang_assert(data == 0 || data == ((mk_win_base_uintptr_t)(context)));
		mk_win_main_heap_deallocate(context, sizeof(*context));
		mk_win_user_message_post_quit(0);
	}
	if(!override_lres)
	{
		lres = mk_win_user_window_t_defproc(window, message, wparam, lparam);
	}
	return lres;
}
