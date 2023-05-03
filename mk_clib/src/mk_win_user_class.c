#include "mk_win_user_class.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_win_base.h"
#include "mk_win_kernel_atom.h"
#include "mk_win_sal.h"
#include "mk_win_tstring.h"
#include "mk_win_unicode_api.h"


mk_win_base_dll_import mk_win_kernel_atom_t mk_win_base_stdcall RegisterClassA(mk_win_sal_in mk_win_user_class_a_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall UnregisterClassA(mk_win_sal_in mk_win_base_pchar_lpct, mk_win_sal_in_opt mk_win_base_instance_t) mk_lang_noexcept;

mk_win_base_dll_import mk_win_kernel_atom_t mk_win_base_stdcall RegisterClassW(mk_win_sal_in mk_win_user_class_w_lpct) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall UnregisterClassW(mk_win_sal_in mk_win_base_wchar_lpct, mk_win_sal_in_opt mk_win_base_instance_t) mk_lang_noexcept;


mk_lang_jumbo mk_win_kernel_atom_t mk_win_user_class_a_register(mk_win_user_class_a_lpct klass) mk_lang_noexcept
{
	mk_win_kernel_atom_t atom;

	mk_lang_assert(klass);

	atom = RegisterClassA(klass);
	return atom;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_a_unregister_by_name(mk_win_base_pchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept
{
	mk_win_base_bool_t unregistered;

	mk_lang_assert(name);

	unregistered = UnregisterClassA(name, instance);
	mk_lang_assert(unregistered == mk_win_base_false || unregistered == mk_win_base_true);
	return unregistered;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_a_unregister_by_atom(mk_win_kernel_atom_t const atom, mk_win_base_instance_t const instance) mk_lang_noexcept
{
	mk_win_base_bool_t unregistered;

	unregistered = UnregisterClassA(((mk_win_base_pchar_lpct)(((mk_win_base_uintptr_t)(atom)))), instance);
	mk_lang_assert(unregistered == mk_win_base_false || unregistered == mk_win_base_true);
	return unregistered;
}


mk_lang_jumbo mk_win_kernel_atom_t mk_win_user_class_w_register(mk_win_user_class_w_lpct klass) mk_lang_noexcept
{
	mk_win_kernel_atom_t atom;

	mk_lang_assert(klass);

	atom = RegisterClassW(klass);
	return atom;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_w_unregister_by_name(mk_win_base_wchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept
{
	mk_win_base_bool_t unregistered;

	mk_lang_assert(name);

	unregistered = UnregisterClassW(name, instance);
	mk_lang_assert(unregistered == mk_win_base_false || unregistered == mk_win_base_true);
	return unregistered;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_w_unregister_by_atom(mk_win_kernel_atom_t const atom, mk_win_base_instance_t const instance) mk_lang_noexcept
{
	mk_win_base_bool_t unregistered;

	unregistered = UnregisterClassW(((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(atom)))), instance);
	mk_lang_assert(unregistered == mk_win_base_false || unregistered == mk_win_base_true);
	return unregistered;
}


mk_lang_jumbo mk_win_kernel_atom_t mk_win_user_class_t_register(mk_win_user_class_t_lpct klass) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_class_a_register(((mk_win_user_class_a_lpct)(klass)));
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	mk_win_user_class_a_t klassa;
	mk_win_kernel_atom_t atom;

	klassa.m_style = klass->m_style;
	klassa.m_wndproc = klass->m_wndproc;
	klassa.m_class_extra = klass->m_class_extra;
	klassa.m_wnd_extra = klass->m_wnd_extra;
	klassa.m_instance = klass->m_instance;
	klassa.m_icon = klass->m_icon;
	klassa.m_cursor = klass->m_cursor;
	klassa.m_brush = klass->m_brush;
	klassa.m_menu_name = mk_win_tstring_tstr_to_ansi_zt_nofail(klass->m_menu_name).m_str;;
	klassa.m_class_name = mk_win_tstring_tstr_to_ansi_zt_nofail(klass->m_class_name).m_str;;
	atom = mk_win_user_class_a_register(&klassa);
	return atom;
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_class_w_register(((mk_win_user_class_w_lpct)(klass)));
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	mk_win_user_class_w_t klassw;
	mk_win_kernel_atom_t atom;

	klassw.m_style = klass->m_style;
	klassw.m_wndproc = klass->m_wndproc;
	klassw.m_class_extra = klass->m_class_extra;
	klassw.m_wnd_extra = klass->m_wnd_extra;
	klassw.m_instance = klass->m_instance;
	klassw.m_icon = klass->m_icon;
	klassw.m_cursor = klass->m_cursor;
	klassw.m_brush = klass->m_brush;
	klassw.m_menu_name = mk_win_tstring_tstr_to_wide_zt_nofail(klass->m_menu_name).m_str;;
	klassw.m_class_name = mk_win_tstring_tstr_to_wide_zt_nofail(klass->m_class_name).m_str;;
	atom = mk_win_user_class_w_register(&klassw);
	return atom;
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_class_a_register(((mk_win_user_class_a_lpct)(klass)));
		#else
			mk_win_user_class_a_t klassa;
			mk_win_kernel_atom_t atom;

			klassa.m_style = klass->m_style;
			klassa.m_wndproc = klass->m_wndproc;
			klassa.m_class_extra = klass->m_class_extra;
			klassa.m_wnd_extra = klass->m_wnd_extra;
			klassa.m_instance = klass->m_instance;
			klassa.m_icon = klass->m_icon;
			klassa.m_cursor = klass->m_cursor;
			klassa.m_background = klass->m_background;
			klassa.m_menu_name = mk_win_tstring_tstr_to_ansi_zt_nofail(klass->m_menu_name).m_str;;
			klassa.m_class_name = mk_win_tstring_tstr_to_ansi_zt_nofail(klass->m_class_name).m_str;;
			atom = mk_win_user_class_a_register(&klassa);
			return atom;
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_class_w_register(((mk_win_user_class_w_lpct)(klass)));
		#else
			mk_win_user_class_w_t klassw;
			mk_win_kernel_atom_t atom;

			klassw.m_style = klass->m_style;
			klassw.m_wndproc = klass->m_wndproc;
			klassw.m_class_extra = klass->m_class_extra;
			klassw.m_wnd_extra = klass->m_wnd_extra;
			klassw.m_instance = klass->m_instance;
			klassw.m_icon = klass->m_icon;
			klassw.m_cursor = klass->m_cursor;
			klassw.m_background = klass->m_background;
			klassw.m_menu_name = mk_win_tstring_tstr_to_wide_zt_nofail(klass->m_menu_name).m_str;;
			klassw.m_class_name = mk_win_tstring_tstr_to_wide_zt_nofail(klass->m_class_name).m_str;;
			atom = mk_win_user_class_w_register(&klassw);
			return atom;
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_t_unregister_by_name(mk_win_tstring_tchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_class_a_unregister_by_name(name, instance);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_class_a_unregister_by_name(mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str, instance);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_class_w_unregister_by_name(name, instance);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_class_w_unregister_by_name(mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str, instance);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_class_a_unregister_by_name(name, instance);
		#else
			return mk_win_user_class_a_unregister_by_name(mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str, instance);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_class_w_unregister_by_name(name, instance);
		#else
			return mk_win_user_class_w_unregister_by_name(mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str, instance);
		#endif
	}
#endif
}

mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_t_unregister_by_atom(mk_win_kernel_atom_t const atom, mk_win_base_instance_t const instance) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_user_class_a_unregister_by_atom(atom, instance);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_user_class_a_unregister_by_atom(atom, instance);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_user_class_w_unregister_by_atom(atom, instance);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_user_class_w_unregister_by_atom(atom, instance);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_user_class_a_unregister_by_atom(atom, instance);
		#else
			return mk_win_user_class_a_unregister_by_atom(atom, instance);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_user_class_w_unregister_by_atom(atom, instance);
		#else
			return mk_win_user_class_w_unregister_by_atom(atom, instance);
		#endif
	}
#endif
}
