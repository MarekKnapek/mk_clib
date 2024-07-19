#include "mk_lib_win_statistics.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_static_param.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_sl_mallocg_tracer.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"
#include "mk_win_base.h"
#include "mk_win_kernel_dll.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_process.h"
#include "mk_win_kernel_thread.h"
#include "mk_win_user_base.h"
#include "mk_win_user_class.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_icon.h"
#include "mk_win_user_msg.h"
#include "mk_win_user_window.h"


#define mk_lib_win_statistics_class_name_n  "mk_lib_win_statistics"
#define mk_lib_win_statistics_class_name_w L"mk_lib_win_statistics"
mk_lang_constexpr_static_inline mk_lang_types_wchar_pct const mk_lib_win_statistics_labels[] =
{
	L"bytes allocated",
	L"bytes deallocated",
	L"bytes peak",
	L"bytes live",
	L"blocks allocated",
	L"blocks deallocated",
	L"blocks peak",
	L"blocks live",
};


/* todo move this to window or something */
struct nmhdr_s
{
	mk_win_user_base_wnd_t m_wnd;
	mk_win_base_uintptr_t m_id_from;
	mk_win_base_uint_t m_code;
};
typedef struct nmhdr_s nmhdr_t;
typedef nmhdr_t* nmhdr_pt;
/* todo move this to window or something */
/* todo move this to list view class */
#define list_view_class_name_a  "SysListView32"
#define list_view_class_name_w L"SysListView32"
enum list_view_window_style_id_e
{
	list_view_window_style_id_e_aligntop        = 0x0000ul,
	list_view_window_style_id_e_icon            = 0x0000ul,
	list_view_window_style_id_e_report          = 0x0001ul,
	list_view_window_style_id_e_smallicon       = 0x0002ul,
	list_view_window_style_id_e_list            = 0x0003ul,
	list_view_window_style_id_e_typemask        = 0x0003ul,
	list_view_window_style_id_e_singlesel       = 0x0004ul,
	list_view_window_style_id_e_showselalways   = 0x0008ul,
	list_view_window_style_id_e_sortascending   = 0x0010ul,
	list_view_window_style_id_e_sortdescending  = 0x0020ul,
	list_view_window_style_id_e_shareimagelists = 0x0040ul,
	list_view_window_style_id_e_nolabelwrap     = 0x0080ul,
	list_view_window_style_id_e_autoarrange     = 0x0100ul,
	list_view_window_style_id_e_editlabels      = 0x0200ul,
	list_view_window_style_id_e_ownerdrawfixed  = 0x0400ul,
	list_view_window_style_id_e_alignleft       = 0x0800ul,
	list_view_window_style_id_e_alignmask       = 0x0c00ul,
	list_view_window_style_id_e_ownerdata       = 0x1000ul,
	list_view_window_style_id_e_noscroll        = 0x2000ul,
	list_view_window_style_id_e_nocolumnheader  = 0x4000ul,
	list_view_window_style_id_e_nosortheader    = 0x8000ul,
	list_view_window_style_id_e_typestylemask   = 0xfc00ul,
	list_view_window_style_id_e_dummy_end
};
typedef enum list_view_window_style_id_e list_view_window_style_id_t;
enum list_view_window_styleex_id_e
{
	list_view_window_styleex_id_e_gridlines             = 0x00000001ul,
	list_view_window_styleex_id_e_subitemimages         = 0x00000002ul,
	list_view_window_styleex_id_e_checkboxes            = 0x00000004ul,
	list_view_window_styleex_id_e_trackselect           = 0x00000008ul,
	list_view_window_styleex_id_e_headerdragdrop        = 0x00000010ul,
	list_view_window_styleex_id_e_fullrowselect         = 0x00000020ul,
	list_view_window_styleex_id_e_oneclickactivate      = 0x00000040ul,
	list_view_window_styleex_id_e_twoclickactivate      = 0x00000080ul,
	list_view_window_styleex_id_e_flatsb                = 0x00000100ul,
	list_view_window_styleex_id_e_regional              = 0x00000200ul,
	list_view_window_styleex_id_e_infotip               = 0x00000400ul,
	list_view_window_styleex_id_e_underlinehot          = 0x00000800ul,
	list_view_window_styleex_id_e_underlinecold         = 0x00001000ul,
	list_view_window_styleex_id_e_multiworkareas        = 0x00002000ul,
	list_view_window_styleex_id_e_labeltip              = 0x00004000ul,
	list_view_window_styleex_id_e_borderselect          = 0x00008000ul,
	list_view_window_styleex_id_e_doublebuffer          = 0x00010000ul, /* ntddi_version >= ntddi_winxp */
	list_view_window_styleex_id_e_hidelabels            = 0x00020000ul, /* ntddi_version >= ntddi_winxp */
	list_view_window_styleex_id_e_singlerow             = 0x00040000ul, /* ntddi_version >= ntddi_winxp */
	list_view_window_styleex_id_e_snaptogrid            = 0x00080000ul, /* ntddi_version >= ntddi_winxp */
	list_view_window_styleex_id_e_simpleselect          = 0x00100000ul, /* ntddi_version >= ntddi_winxp */
	list_view_window_styleex_id_e_justifycolumns        = 0x00200000ul, /* ntddi_version >= ntddi_vista */
	list_view_window_styleex_id_e_transparentbkgnd      = 0x00400000ul, /* ntddi_version >= ntddi_vista */
	list_view_window_styleex_id_e_transparentshadowtext = 0x00800000ul, /* ntddi_version >= ntddi_vista */
	list_view_window_styleex_id_e_autoautoarrange       = 0x01000000ul, /* ntddi_version >= ntddi_vista */
	list_view_window_styleex_id_e_headerinallviews      = 0x02000000ul, /* ntddi_version >= ntddi_vista */
	list_view_window_styleex_id_e_autocheckselect       = 0x08000000ul, /* ntddi_version >= ntddi_vista */
	list_view_window_styleex_id_e_autosizecolumns       = 0x10000000ul, /* ntddi_version >= ntddi_vista */
	list_view_window_styleex_id_e_columnsnappoints      = 0x40000000ul, /* ntddi_version >= ntddi_vista */
	list_view_window_styleex_id_e_columnoverflow        = 0x80000000ul, /* ntddi_version >= ntddi_vista */
	list_view_window_styleex_id_e_dummy_end
};
typedef enum list_view_window_styleex_id_e list_view_window_styleex_id_t;
enum list_view_msg_id_e
{
	list_view_msg_id_e_first                    = 0x1000ul,
	list_view_msg_id_e_setitemcount             = list_view_msg_id_e_first + 47ul,
	list_view_msg_id_e_setextendedlistviewstyle = list_view_msg_id_e_first + 54ul,
	list_view_msg_id_e_insertcolumnw            = list_view_msg_id_e_first + 97ul,
	list_view_msg_id_e_dummy_end
};
typedef enum list_view_msg_id_e list_view_msg_id_t;
enum list_view_col_mask_e
{
	list_view_col_mask_e_fmt          = 0x0001ul,
	list_view_col_mask_e_width        = 0x0002ul,
	list_view_col_mask_e_text         = 0x0004ul,
	list_view_col_mask_e_subitem      = 0x0008ul,
	list_view_col_mask_e_image        = 0x0010ul,
	list_view_col_mask_e_order        = 0x0020ul,
	list_view_col_mask_e_minwidth     = 0x0040ul, /* ntddi_version >= ntddi_vista */
	list_view_col_mask_e_defaultwidth = 0x0080ul, /* ntddi_version >= ntddi_vista */
	list_view_col_mask_e_idealwidth   = 0x0100ul, /* ntddi_version >= ntddi_vista */
	list_view_col_mask_e_dummy_end
};
typedef enum list_view_col_mask_e list_view_col_mask_t;
enum list_view_notification_id_e
{
	list_view_notification_id_e_first        = ((mk_win_base_dword_t)(0ul - 100ul)),
	list_view_notification_id_e_getdispinfow = ((mk_win_base_dword_t)(list_view_notification_id_e_first)) - 77ul,
	list_view_notification_id_e_dummy_end
};
typedef enum list_view_notification_id_e list_view_notification_id_t;
enum list_view_item_mask_e
{
	list_view_item_mask_e_text        = 0x00000001ul,
	list_view_item_mask_e_image       = 0x00000002ul,
	list_view_item_mask_e_param       = 0x00000004ul,
	list_view_item_mask_e_state       = 0x00000008ul,
	list_view_item_mask_e_indent      = 0x00000010ul,
	list_view_item_mask_e_groupid     = 0x00000100ul, /* ntddi_version >= ntddi_winxp */
	list_view_item_mask_e_columns     = 0x00000200ul, /* ntddi_version >= ntddi_winxp */
	list_view_item_mask_e_norecompute = 0x00000800ul,
	list_view_item_mask_e_colfmt      = 0x00010000ul, /* ntddi_version >= ntddi_vista */
	list_view_item_mask_e_dummy_end
};
typedef enum list_view_item_mask_e list_view_item_mask_t;
struct list_view_column_descr_w_s
{
	mk_win_base_uint_t m_mask;
	mk_win_base_sint_t m_fmt;
	mk_win_base_sint_t m_cx;
	mk_win_base_wchar_lpt m_text_buf;
	mk_win_base_sint_t m_text_len;
	mk_win_base_sint_t m_sub_item;
	mk_win_base_sint_t m_image;
	mk_win_base_sint_t m_order;
	#if defined _WIN32_WINNT && _WIN32_WINNT >= 0x0600
	mk_win_base_sint_t m_snap_min;
	mk_win_base_sint_t m_snap_def;
	mk_win_base_sint_t m_text_idl;
	#endif
};
typedef struct list_view_column_descr_w_s list_view_column_descr_w_t;
struct list_view_itemw_s
{
	mk_win_base_uint_t m_mask;
	mk_win_base_sint_t m_item;
	mk_win_base_sint_t m_sub_item;
	mk_win_base_uint_t m_state_value;
	mk_win_base_uint_t m_state_mask;
	mk_win_base_wchar_lpt m_text_buf;
	mk_win_base_sint_t m_text_len;
	mk_win_base_sint_t m_image;
	mk_win_user_base_lparam_t m_lparam;
	mk_win_base_sint_t m_indent;
	mk_win_base_sint_t m_group_id; /* NTDDI_VERSION >= NTDDI_WINXP */
	mk_win_base_uint_t m_columns_cnt; /* NTDDI_VERSION >= NTDDI_WINXP */
	mk_win_base_uint_pt m_columns_buf; /* NTDDI_VERSION >= NTDDI_WINXP */
	mk_win_base_sint_pt m_col_fmt; /* NTDDI_VERSION >= NTDDI_VISTA */
	mk_win_base_sint_t m_group; /* NTDDI_VERSION >= NTDDI_VISTA */
};
typedef struct list_view_itemw_s list_view_itemw_t;
struct list_view_notify_dispinfow_s
{
	nmhdr_t m_nmhdr;
	list_view_itemw_t m_item;
};
typedef struct list_view_notify_dispinfow_s list_view_notify_dispinfow_t;
typedef list_view_notify_dispinfow_t* list_view_notify_dispinfow_pt;
/* todo move this to list view class */


struct mk_lib_win_statistics_s
{
	mk_win_user_base_atom_t m_atom;
	mk_win_user_base_wnd_t m_wnd;
	mk_win_user_base_wnd_t m_counters;
	mk_win_base_rect_t m_last_rect;
	mk_lang_types_uint_t m_cntr_as_text_idx;
	mk_lang_types_wchar_t m_cntr_as_text_buf[8][mk_sl_cui_uint128_strlendec_v + 1];
};
typedef struct mk_lib_win_statistics_s mk_lib_win_statistics_t;
typedef mk_lib_win_statistics_t const mk_lib_win_statistics_ct;
typedef mk_lib_win_statistics_t* mk_lib_win_statistics_pt;
typedef mk_lib_win_statistics_t const* mk_lib_win_statistics_pct;


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_win_statistics_window_class_name_generate(mk_lang_static_param(mk_lang_types_wchar_t, res, 4 * 2)) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t arr[mk_lang_countstr(mk_lib_win_statistics_class_name_n)] mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha1_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_sha1_digest_t digest mk_lang_constexpr_init;
	mk_sl_cui_uint32_t u32 mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(res);

	n = mk_lang_countstr(mk_lib_win_statistics_class_name_n);
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&arr[i], &mk_lib_win_statistics_class_name_n[i]);
	}
	mk_lib_crypto_hash_stream_sha1_init(&hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8(&hasher, &arr[0], n);
	mk_lib_crypto_hash_stream_sha1_finish(&hasher, &digest);
	mk_sl_uint_32_from_8_le(&u32, &digest.m_uint8s[0]);
	len = mk_sl_cui_uint32_to_str_hexf_w(&u32, res, 4 * 2); mk_lang_assert(len == 4 * 2);
}

#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

mk_lang_constexpr static mk_lang_inline auto mk_lib_win_statistics_window_class_name_return(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_lang_types_wchar_t, 4 * 2 + 1> arr mk_lang_constexpr_init;

	mk_lib_win_statistics_window_class_name_generate(arr.arr());
	arr[4 * 2 + 0] = L'\0';
	return arr;
}

mk_lang_constexpr_static_inline auto const s_mk_lib_win_statistics_window_class_name = mk_lib_win_statistics_window_class_name_return();

#endif

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_wchar_pct mk_lib_win_statistics_window_class_name_get(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	return s_mk_lib_win_statistics_window_class_name.cdata();
#else
	return mk_lib_win_statistics_class_name_w;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_statistics_on_create(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_msg_createw_lpct create;
	mk_lib_win_statistics_pt statistics;
	mk_win_base_uintptr_t data;

	((mk_lang_types_void_t)(wparam));
	if(msg == mk_win_user_msg_id_e_create)
	{
		create = ((mk_win_user_msg_createw_lpct)(lparam)); mk_lang_assert(create);
		statistics = ((mk_lib_win_statistics_pt)(create->m_param));
		statistics->m_wnd = wnd;
		statistics->m_last_rect.m_left = 0;
		statistics->m_last_rect.m_top = 0;
		statistics->m_last_rect.m_right = 0;
		statistics->m_last_rect.m_bottom = 0;
		statistics->m_cntr_as_text_idx = 0;
		data = mk_win_user_window_w_data_set(wnd, ((mk_win_base_sint_t)(mk_win_user_window_data_id_e_userdata)), ((mk_win_base_uintptr_t)(statistics))); mk_lang_assert(data == 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_statistics_on_destroy(mk_lib_win_statistics_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_win_base_uintptr_t data;

	mk_lang_assert(statistics);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	((mk_lang_types_void_t)(lparam));
	data = mk_win_user_window_w_data_set(statistics->m_wnd, ((mk_win_base_sint_t)(mk_win_user_window_data_id_e_userdata)), ((mk_win_base_uintptr_t)(0))); mk_lang_assert(data == ((mk_win_base_uintptr_t)(statistics)));
	statistics->m_wnd = mk_win_user_base_wnd_get_null();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_statistics_on_paint(mk_lib_win_statistics_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_rect_t rect;

	mk_lang_assert(statistics);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	((mk_lang_types_void_t)(lparam));
	b = mk_win_user_window_get_rect_client(statistics->m_wnd, &rect); mk_lang_check_return(b != 0);
	if
	(
		statistics->m_last_rect.m_left != rect.m_left ||
		statistics->m_last_rect.m_top != rect.m_top ||
		statistics->m_last_rect.m_right != rect.m_right ||
		statistics->m_last_rect.m_bottom != rect.m_bottom
	)
	{
		b = mk_win_user_window_w_msg_post(statistics->m_wnd, ((mk_win_base_uint_t)(mk_win_user_msg_id_e_user + 1)), 0, 0); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_statistics_on_notify_counters_dispinfo(mk_lib_win_statistics_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{

	nmhdr_pt nmhdr;
	mk_lang_types_sint_t err;
	list_view_notify_dispinfow_pt dispinfo;
	mk_sl_cui_uint128_t cntr;
	mk_lang_types_wchar_pt buf;
	mk_lang_types_sint_t len;

	mk_lang_assert(statistics);
	mk_lang_assert(lparam);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	nmhdr = ((nmhdr_pt)(lparam));
	mk_lang_assert(nmhdr->m_wnd.m_data == statistics->m_counters.m_data);
	mk_lang_assert(nmhdr->m_code == list_view_notification_id_e_getdispinfow);
	dispinfo = ((list_view_notify_dispinfow_pt)(nmhdr));
	mk_lang_assert(dispinfo->m_item.m_item != -1);
	if((dispinfo->m_item.m_mask & list_view_item_mask_e_text) != 0)
	{
		if(dispinfo->m_item.m_sub_item == 0)
		{
			dispinfo->m_item.m_text_buf = ((mk_win_base_wchar_lpt)(mk_lib_win_statistics_labels[dispinfo->m_item.m_item]));
		}
		else
		{
			switch(dispinfo->m_item.m_item)
			{
				case 0: err = mk_sl_mallocg_tracer_statistics_get_bytes_allocated   (&cntr); mk_lang_check_rereturn(err); break;
				case 1: err = mk_sl_mallocg_tracer_statistics_get_bytes_deallocated (&cntr); mk_lang_check_rereturn(err); break;
				case 2: err = mk_sl_mallocg_tracer_statistics_get_bytes_peak        (&cntr); mk_lang_check_rereturn(err); break;
				case 3: err = mk_sl_mallocg_tracer_statistics_get_bytes_live        (&cntr); mk_lang_check_rereturn(err); break;
				case 4: err = mk_sl_mallocg_tracer_statistics_get_blocks_allocated  (&cntr); mk_lang_check_rereturn(err); break;
				case 5: err = mk_sl_mallocg_tracer_statistics_get_blocks_deallocated(&cntr); mk_lang_check_rereturn(err); break;
				case 6: err = mk_sl_mallocg_tracer_statistics_get_blocks_peak       (&cntr); mk_lang_check_rereturn(err); break;
				case 7: err = mk_sl_mallocg_tracer_statistics_get_blocks_live       (&cntr); mk_lang_check_rereturn(err); break;
			}
			buf = &statistics->m_cntr_as_text_buf[statistics->m_cntr_as_text_idx][0];
			statistics->m_cntr_as_text_idx = (statistics->m_cntr_as_text_idx + 1) % mk_lang_countof(statistics->m_cntr_as_text_buf);;
			len = mk_sl_cui_uint128_to_str_dec_w(&cntr, &buf[0], mk_sl_cui_uint128_strlendec_v); mk_lang_assert(len >= 1 && len <= mk_sl_cui_uint128_strlendec_v);
			buf[len] = L'\0';
			dispinfo->m_item.m_text_buf = buf;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_statistics_on_notify_counters_general(mk_lib_win_statistics_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	nmhdr_pt nmhdr;
	mk_lang_types_sint_t err;

	mk_lang_assert(statistics);
	mk_lang_assert(lparam);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	nmhdr = ((nmhdr_pt)(lparam));
	mk_lang_assert(nmhdr->m_wnd.m_data == statistics->m_counters.m_data);
	switch(nmhdr->m_code)
	{
		case list_view_notification_id_e_getdispinfow: err = mk_lib_win_statistics_on_notify_counters_dispinfo(statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_statistics_on_notify(mk_lib_win_statistics_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	nmhdr_pt nmhdr;
	mk_lang_types_sint_t err;

	mk_lang_assert(statistics);
	mk_lang_assert(lparam);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	nmhdr = ((nmhdr_pt)(lparam));
	if(nmhdr->m_wnd.m_data == statistics->m_counters.m_data)
	{
		err = mk_lib_win_statistics_on_notify_counters_general(statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_statistics_on_user_1(mk_lib_win_statistics_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_rect_t rect;

	mk_lang_assert(statistics);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	((mk_lang_types_void_t)(lparam));
	b = mk_win_user_window_get_rect_client(statistics->m_wnd, &rect); mk_lang_check_return(b != 0);
	if
	(
		statistics->m_last_rect.m_left != rect.m_left ||
		statistics->m_last_rect.m_top != rect.m_top ||
		statistics->m_last_rect.m_right != rect.m_right ||
		statistics->m_last_rect.m_bottom != rect.m_bottom
	)
	{
		statistics->m_last_rect = rect;
		b = mk_win_user_window_pos_set(statistics->m_counters, mk_win_user_base_wnd_get_null(), rect.m_left, rect.m_top, rect.m_right - rect.m_left, rect.m_bottom - rect.m_top, 0); mk_lang_check_return(b != 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_statistics_on_msg(mk_lib_win_statistics_pt const statistics, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(statistics);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	switch(msg)
	{
		case mk_win_user_msg_id_e_destroy : err = mk_lib_win_statistics_on_destroy(statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_paint   : err = mk_lib_win_statistics_on_paint  (statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_notify  : err = mk_lib_win_statistics_on_notify (statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_user + 1: err = mk_lib_win_statistics_on_user_1 (statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_win_user_base_lresult_t mk_win_base_stdcall mk_lib_win_statistics_on_raw_msg(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t override_defproc;
	mk_win_base_uintptr_t data;
	mk_lib_win_statistics_pt statistics;
	mk_win_user_base_lresult_t lr;

	err = mk_lib_win_statistics_on_create(wnd, msg, wparam, lparam); mk_lang_check_recrash(err);
	override_defproc = mk_lang_false;
	data = mk_win_user_window_w_data_get(wnd, ((mk_win_base_sint_t)(mk_win_user_window_data_id_e_userdata))); statistics = ((mk_lib_win_statistics_pt)(data));
	if(data != 0)
	{
		err = mk_lib_win_statistics_on_msg(statistics, msg, wparam, lparam, &override_defproc, &lr); mk_lang_check_recrash(err);
	}
	if(!override_defproc)
	{
		lr = mk_win_user_window_w_def_proc(wnd, msg, wparam, lparam);
	}
	return lr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_statistics_show(mk_lib_win_statistics_pt const statistics) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_module_t this_module;
	mk_win_user_base_wnd_t wnd;
	list_view_column_descr_w_t col_descr;
	mk_win_user_base_lresult_t lr;

	mk_lang_assert(statistics);

	b = mk_win_kernel_dll_w_get_module_handle_ex(((mk_win_base_dword_t)(mk_win_kernel_dll_get_module_handle_ex_flags_e_from_address)), ((mk_win_base_wchar_pct)(((mk_win_base_void_pt)(&mk_lib_win_statistics_on_raw_msg)))), &this_module); mk_lang_check_return(b != 0); mk_lang_check_return(!mk_win_base_module_is_null(this_module));
	wnd = mk_win_user_window_w_createex(((mk_win_base_dword_t)(mk_win_user_window_styleex_id_e_overlappedwindow)), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(statistics->m_atom)))), L"statistics", ((mk_win_base_dword_t)(mk_win_user_window_style_id_e_overlappedwindow)), mk_win_user_window_use_default, mk_win_user_window_use_default, 250, 220, mk_win_user_base_wnd_get_null(), mk_win_user_menu_get_null(), mk_win_base_instance_from(this_module.m_data), statistics); mk_lang_check_return(!mk_win_user_base_wnd_is_null(wnd)); mk_lang_assert(statistics->m_wnd.m_data == wnd.m_data);

	wnd = mk_win_user_window_w_createex(((mk_win_base_dword_t)(0)), list_view_class_name_w, L"", ((mk_win_base_dword_t)(mk_win_user_window_style_id_e_visible | mk_win_user_window_style_id_e_child)) | ((mk_win_base_dword_t)(list_view_window_style_id_e_report | list_view_window_style_id_e_showselalways | list_view_window_style_id_e_ownerdata)), mk_win_user_window_use_default, mk_win_user_window_use_default, mk_win_user_window_use_default, mk_win_user_window_use_default, wnd, mk_win_user_menu_get_null(), mk_win_base_instance_from(this_module.m_data), mk_win_base_null); mk_lang_check_return(!mk_win_user_base_wnd_is_null(wnd)); statistics->m_counters = wnd;
	lr = mk_win_user_window_w_msg_send(statistics->m_counters, ((mk_win_base_uint_t)(list_view_msg_id_e_setextendedlistviewstyle)), ((mk_win_base_dword_t)(list_view_window_styleex_id_e_fullrowselect | list_view_window_styleex_id_e_autosizecolumns | list_view_window_styleex_id_e_doublebuffer)), ((mk_win_base_dword_t)(list_view_window_styleex_id_e_fullrowselect | list_view_window_styleex_id_e_autosizecolumns | list_view_window_styleex_id_e_doublebuffer))); ((mk_lang_types_void_t)(lr));
	col_descr.m_mask = ((mk_win_base_uint_t)(list_view_col_mask_e_text | list_view_col_mask_e_width));
	col_descr.m_cx = 100;
	col_descr.m_text_buf = ((mk_win_base_wchar_lpt)(L"counter"));
	lr = mk_win_user_window_w_msg_send(statistics->m_counters, ((mk_win_base_uint_t)(list_view_msg_id_e_insertcolumnw)), 0, ((mk_win_user_base_lparam_t)(&col_descr))); mk_lang_check_return(lr == 0);
	col_descr.m_text_buf = ((mk_win_base_wchar_lpt)(L"value"));
	lr = mk_win_user_window_w_msg_send(statistics->m_counters, ((mk_win_base_uint_t)(list_view_msg_id_e_insertcolumnw)), 1, ((mk_win_user_base_lparam_t)(&col_descr))); mk_lang_check_return(lr == 1);
	lr = mk_win_user_window_w_msg_send(statistics->m_counters, ((mk_win_base_uint_t)(list_view_msg_id_e_setitemcount)), 8, 0); //mk_lang_check_return(lr == 0);

	b = mk_win_user_window_show(statistics->m_wnd, mk_win_user_window_show_e_shownormal); ((mk_lang_types_void_t)(b));
	return 0;
}


static mk_lib_win_statistics_t g_mk_lib_win_statistics;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_statistics_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_win_statistics_pt statistics;
	mk_win_base_bool_t b;
	mk_win_base_module_t this_module;
	mk_win_user_class_exw_t cls;
	mk_win_user_base_atom_t atom;

	statistics = &g_mk_lib_win_statistics;
	b = mk_win_kernel_dll_w_get_module_handle_ex(((mk_win_base_dword_t)(mk_win_kernel_dll_get_module_handle_ex_flags_e_from_address)), ((mk_win_base_wchar_pct)(((mk_win_base_void_pt)(&mk_lib_win_statistics_on_raw_msg)))), &this_module); mk_lang_check_return(b != 0); mk_lang_check_return(!mk_win_base_module_is_null(this_module));
	cls.m_len = ((mk_win_base_uint_t)(sizeof(cls)));
	cls.m_style = ((mk_win_base_uint_t)(mk_win_user_class_style_id_e_vredraw | mk_win_user_class_style_id_e_hredraw));
	cls.m_callback = &mk_lib_win_statistics_on_raw_msg;
	cls.m_extra_cls = ((mk_win_base_sint_t)(0));
	cls.m_extra_wnd = ((mk_win_base_sint_t)(sizeof(statistics)));
	cls.m_instance = mk_win_base_instance_from(this_module.m_data);
	cls.m_icon_big = mk_win_user_icon_w_load(mk_win_base_instance_get_null(), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(((mk_win_base_ushort_t)(mk_win_user_icon_id_e_application)))))));
	cls.m_cursor = mk_win_user_cursor_w_load(mk_win_base_instance_get_null(), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(((mk_win_base_ushort_t)(mk_win_user_cursor_id_e_arrow)))))));
	cls.m_background = mk_win_user_brush_from_color_id(mk_win_user_base_color_id_e_window);
	cls.m_menu = ((mk_win_base_wchar_lpct)(mk_win_base_null));
	cls.m_name = mk_lib_win_statistics_window_class_name_get();
	cls.m_icon_smol = cls.m_icon_big;
	atom = mk_win_user_class_register_exw(&cls); mk_lang_check_return(atom != 0);
	statistics->m_atom = atom;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_statistics_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_win_statistics_pt statistics;
	mk_win_base_bool_t b;
	mk_win_base_module_t this_module;

	statistics = &g_mk_lib_win_statistics;
	mk_lang_assert(statistics->m_atom != 0);
	b = mk_win_kernel_dll_w_get_module_handle_ex(((mk_win_base_dword_t)(mk_win_kernel_dll_get_module_handle_ex_flags_e_from_address)), ((mk_win_base_wchar_pct)(((mk_win_base_void_pt)(&mk_lib_win_statistics_on_raw_msg)))), &this_module); mk_lang_check_return(b != 0); mk_lang_check_return(!mk_win_base_module_is_null(this_module));
	b = mk_win_user_class_w_unregister(((mk_win_base_wchar_pct)(((mk_win_base_uintptr_t)(statistics->m_atom)))), mk_win_base_instance_from(this_module.m_data)); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_statistics_display(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_win_statistics_pt statistics;
	mk_lang_types_sint_t err;

	statistics = &g_mk_lib_win_statistics;
	err = mk_lib_win_statistics_show(statistics); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_statistics_close(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_win_statistics_pt statistics;
	mk_win_user_base_lresult_t lr;

	statistics = &g_mk_lib_win_statistics;
	mk_lang_assert(statistics->m_atom != 0);
	if(!mk_win_user_base_wnd_is_null(statistics->m_wnd))
	{
		lr = mk_win_user_window_w_msg_send(statistics->m_wnd, ((mk_win_base_uint_t)(mk_win_user_msg_id_e_close)), 0, 0); ((mk_lang_types_void_t)(lr));
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_statistics_invalidate(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_win_statistics_pt statistics;
	mk_win_base_bool_t b;

	statistics = &g_mk_lib_win_statistics;
	mk_lang_assert(statistics->m_atom != 0);
	if(!mk_win_user_base_wnd_is_null(statistics->m_wnd))
	{
		b = mk_win_user_window_invalidate_region(statistics->m_counters, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
	}
	return 0;
}
