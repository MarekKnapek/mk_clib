#include "mk_lib_statistics_windows.h"

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
#include "mk_sl_uint.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"
#include "mk_win_base.h"
#include "mk_win_comctl_base.h"
#include "mk_win_comctl_list_view.h"
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


#define mk_lib_statistics_windows_mallocatorg_id_disp        11
#define mk_lib_statistics_windows_mallocatorg_id_portablec   12
#define mk_lib_statistics_windows_mallocatorg_id_portablecpp 13
#define mk_lib_statistics_windows_mallocatorg_id_windows     14
#define mk_lib_statistics_windows_mallocatorg_id_tracer      15

#if defined mk_lib_statistics_windows_mallocatorg_want && (mk_lib_statistics_windows_mallocatorg_want) == mk_lib_statistics_windows_mallocatorg_id_disp
#define mk_lib_statistics_windows_mallocatorg_id mk_lib_statistics_windows_mallocatorg_id_disp
#elif defined mk_lib_statistics_windows_mallocatorg_want && (mk_lib_statistics_windows_mallocatorg_want) == mk_lib_statistics_windows_mallocatorg_id_portablec
#define mk_lib_statistics_windows_mallocatorg_id mk_lib_statistics_windows_mallocatorg_id_portablec
#elif defined mk_lib_statistics_windows_mallocatorg_want && (mk_lib_statistics_windows_mallocatorg_want) == mk_lib_statistics_windows_mallocatorg_id_portablecpp
#define mk_lib_statistics_windows_mallocatorg_id mk_lib_statistics_windows_mallocatorg_id_portablecpp
#elif defined mk_lib_statistics_windows_mallocatorg_want && (mk_lib_statistics_windows_mallocatorg_want) == mk_lib_statistics_windows_mallocatorg_id_windows
#define mk_lib_statistics_windows_mallocatorg_id mk_lib_statistics_windows_mallocatorg_id_windows
#elif defined mk_lib_statistics_windows_mallocatorg_want && (mk_lib_statistics_windows_mallocatorg_want) == mk_lib_statistics_windows_mallocatorg_id_tracer
#define mk_lib_statistics_windows_mallocatorg_id mk_lib_statistics_windows_mallocatorg_id_tracer
#elif !defined mk_lib_statistics_windows_mallocatorg_want
#if defined NDEBUG
#define mk_lib_statistics_windows_mallocatorg_id mk_lib_statistics_windows_mallocatorg_id_disp
#else
#define mk_lib_statistics_windows_mallocatorg_id mk_lib_statistics_windows_mallocatorg_id_tracer
#endif
#else
#error xxxxxxxxxx
#endif

#if mk_lib_statistics_windows_mallocatorg_id == mk_lib_statistics_windows_mallocatorg_id_disp
#include "mk_sl_mallocatorg.h"
#define mk_lib_statistics_windows_mallocatorg_name mk_sl_mallocatorg
#elif mk_lib_statistics_windows_mallocatorg_id == mk_lib_statistics_windows_mallocatorg_id_portablec
#include "mk_sl_mallocatorg_portablec.h"
#define mk_lib_statistics_windows_mallocatorg_name mk_sl_mallocatorg_portablec
#elif mk_lib_statistics_windows_mallocatorg_id == mk_lib_statistics_windows_mallocatorg_id_portablecpp
#include "mk_sl_mallocatorg_portablecpp.hpp"
#define mk_lib_statistics_windows_mallocatorg_name mk_sl_mallocatorg_portablecpp
#elif mk_lib_statistics_windows_mallocatorg_id == mk_lib_statistics_windows_mallocatorg_id_windows
#include "mk_sl_mallocatorg_windows.h"
#define mk_lib_statistics_windows_mallocatorg_name mk_sl_mallocatorg_windows
#elif mk_lib_statistics_windows_mallocatorg_id == mk_lib_statistics_windows_mallocatorg_id_tracer
#include "mk_sl_mallocg_tracer.h"
#define mk_lib_statistics_windows_mallocatorg_name mk_sl_mallocg_tracer
#else
#error xxxxxxxxxx
#endif
#define mk_lib_statistics_windows_mallocatorg_init                              mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _init)
#define mk_lib_statistics_windows_mallocatorg_deinit                            mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _deinit)
#define mk_lib_statistics_windows_mallocatorg_allocate                          mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _allocate)
#define mk_lib_statistics_windows_mallocatorg_deallocate                        mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _deallocate)
#define mk_lib_statistics_windows_mallocatorg_reallocate                        mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _reallocate)
#define mk_lib_statistics_windows_mallocatorg_statistics_get_bytes_allocated    mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _statistics_get_bytes_allocated)
#define mk_lib_statistics_windows_mallocatorg_statistics_get_bytes_deallocated  mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _statistics_get_bytes_deallocated)
#define mk_lib_statistics_windows_mallocatorg_statistics_get_bytes_live         mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _statistics_get_bytes_live)
#define mk_lib_statistics_windows_mallocatorg_statistics_get_bytes_peak         mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _statistics_get_bytes_peak)
#define mk_lib_statistics_windows_mallocatorg_statistics_get_blocks_allocated   mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _statistics_get_blocks_allocated)
#define mk_lib_statistics_windows_mallocatorg_statistics_get_blocks_deallocated mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _statistics_get_blocks_deallocated)
#define mk_lib_statistics_windows_mallocatorg_statistics_get_blocks_live        mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _statistics_get_blocks_live)
#define mk_lib_statistics_windows_mallocatorg_statistics_get_blocks_peak        mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _statistics_get_blocks_peak)
#define mk_lib_statistics_windows_mallocatorg_statistics_get_all                mk_lang_concat(mk_lib_statistics_windows_mallocatorg_name, _statistics_get_all)


#define mk_lib_statistics_windows_class_name_n  "mk_lib_statistics_windows"
#define mk_lib_statistics_windows_class_name_w L"mk_lib_statistics_windows"
mk_lang_constexpr_static_inline mk_lang_types_wchar_pct const mk_lib_statistics_windows_labels[] =
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


struct mk_lib_statistics_windows_cntrs_data_arrn_s
{
	mk_sl_cui_uint128_t m_bytes_allocated;
	mk_sl_cui_uint128_t m_bytes_deallocated;
	mk_sl_cui_uint128_t m_bytes_peak;
	mk_sl_cui_uint128_t m_bytes_live;
	mk_sl_cui_uint128_t m_blocks_allocated;
	mk_sl_cui_uint128_t m_blocks_deallocated;
	mk_sl_cui_uint128_t m_blocks_peak;
	mk_sl_cui_uint128_t m_blocks_live;
};
typedef struct mk_lib_statistics_windows_cntrs_data_arrn_s mk_lib_statistics_windows_cntrs_data_arrn_t;
struct mk_lib_statistics_windows_cntrs_data_arry_s
{
	mk_sl_cui_uint128_t m_cntrs[8];
};
typedef struct mk_lib_statistics_windows_cntrs_data_arry_s mk_lib_statistics_windows_cntrs_data_arry_t;
union mk_lib_statistics_windows_cntrs_data_u
{
	mk_lib_statistics_windows_cntrs_data_arrn_t m_arrn;
	mk_lib_statistics_windows_cntrs_data_arry_t m_arry;
};
typedef union mk_lib_statistics_windows_cntrs_data_u mk_lib_statistics_windows_cntrs_data_t;
struct mk_lib_statistics_windows_cntrs_s
{
	mk_lib_statistics_windows_cntrs_data_t m_data;
};
typedef struct mk_lib_statistics_windows_cntrs_s mk_lib_statistics_windows_cntrs_t;
typedef mk_lib_statistics_windows_cntrs_t const mk_lib_statistics_windows_cntrs_ct;
typedef mk_lib_statistics_windows_cntrs_t* mk_lib_statistics_windows_cntrs_pt;
typedef mk_lib_statistics_windows_cntrs_t const* mk_lib_statistics_windows_cntrs_pct;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_statistics_windows_cntrs_ro_eq(mk_lib_statistics_windows_cntrs_pct const a, mk_lib_statistics_windows_cntrs_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(a->m_data.m_arrn) == sizeof(a->m_data.m_arry));

	mk_lang_assert(a);
	mk_lang_assert(b);

	ret =
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[0], &b->m_data.m_arry.m_cntrs[0]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[1], &b->m_data.m_arry.m_cntrs[1]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[2], &b->m_data.m_arry.m_cntrs[2]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[3], &b->m_data.m_arry.m_cntrs[3]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[4], &b->m_data.m_arry.m_cntrs[4]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[5], &b->m_data.m_arry.m_cntrs[5]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[6], &b->m_data.m_arry.m_cntrs[6]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[7], &b->m_data.m_arry.m_cntrs[7]);
	return ret;
}

struct mk_lib_statistics_windows_s
{
	mk_win_user_base_atom_t m_atom;
	mk_win_user_base_wnd_t m_wnd;
	mk_win_user_base_wnd_t m_counters;
	mk_win_base_rect_t m_last_rect;
	mk_lib_statistics_windows_cntrs_t m_cntrs_last;
	mk_lang_types_uint_t m_cntr_as_text_idx;
	mk_lang_types_wchar_t m_cntr_as_text_buf[4][mk_sl_cui_uint128_strlendec_v + 1];
};
typedef struct mk_lib_statistics_windows_s mk_lib_statistics_windows_t;
typedef mk_lib_statistics_windows_t const mk_lib_statistics_windows_ct;
typedef mk_lib_statistics_windows_t* mk_lib_statistics_windows_pt;
typedef mk_lib_statistics_windows_t const* mk_lib_statistics_windows_pct;


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_statistics_windows_window_class_name_generate(mk_lang_static_param(mk_lang_types_wchar_t, res, 4 * 2)) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t arr[mk_lang_countstr(mk_lib_statistics_windows_class_name_n)] mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha1_t hasher mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_sha1_digest_t digest mk_lang_constexpr_init;
	mk_sl_cui_uint32_t u32 mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(res);

	n = mk_lang_countstr(mk_lib_statistics_windows_class_name_n);
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&arr[i], &mk_lib_statistics_windows_class_name_n[i]);
	}
	mk_lib_crypto_hash_stream_sha1_init(&hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8(&hasher, &arr[0], n);
	mk_lib_crypto_hash_stream_sha1_finish(&hasher, &digest);
	mk_sl_uint_32_from_8_le(&u32, &digest.m_uint8s[0]);
	len = mk_sl_cui_uint32_to_str_hexf_w(&u32, res, 4 * 2); mk_lang_assert(len == 4 * 2);
}

#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline auto mk_lib_statistics_windows_window_class_name_return(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_lang_types_wchar_t, 4 * 2 + 1> arr mk_lang_constexpr_init;

	mk_lib_statistics_windows_window_class_name_generate(arr.arr());
	arr[4 * 2 + 0] = L'\0';
	return arr;
}

mk_lang_constexpr_static_inline auto const s_mk_lib_statistics_windows_window_class_name = mk_lib_statistics_windows_window_class_name_return();

#endif

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_wchar_pct mk_lib_statistics_windows_window_class_name_get(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	return s_mk_lib_statistics_windows_window_class_name.cdata();
#else
	return mk_lib_statistics_windows_class_name_w;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_windows_on_create(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept
{
	mk_sl_cui_uint128_t zero;
	mk_win_user_msg_createw_lpct create;
	mk_lib_statistics_windows_pt statistics;
	mk_lang_types_sint_t err;
	mk_win_base_uintptr_t data;

	((mk_lang_types_void_t)(wparam));
	if(msg == mk_win_user_msg_id_e_create)
	{
		mk_lang_assert(lparam != 0);
		mk_sl_cui_uint128_set_zero(&zero);
		create = ((mk_win_user_msg_createw_lpct)(lparam)); mk_lang_assert(create); mk_lang_assert(create->m_param);
		statistics = ((mk_lib_statistics_windows_pt)(create->m_param));
		statistics->m_wnd = wnd;
		statistics->m_last_rect.m_left = 0;
		statistics->m_last_rect.m_top = 0;
		statistics->m_last_rect.m_right = 0;
		statistics->m_last_rect.m_bottom = 0;
		statistics->m_cntrs_last.m_data.m_arry.m_cntrs[0] = zero;
		statistics->m_cntrs_last.m_data.m_arry.m_cntrs[1] = zero;
		statistics->m_cntrs_last.m_data.m_arry.m_cntrs[2] = zero;
		statistics->m_cntrs_last.m_data.m_arry.m_cntrs[3] = zero;
		statistics->m_cntrs_last.m_data.m_arry.m_cntrs[4] = zero;
		statistics->m_cntrs_last.m_data.m_arry.m_cntrs[5] = zero;
		statistics->m_cntrs_last.m_data.m_arry.m_cntrs[6] = zero;
		statistics->m_cntrs_last.m_data.m_arry.m_cntrs[7] = zero;
		statistics->m_cntr_as_text_idx = 0;
		data = mk_win_user_window_w_data_set(wnd, ((mk_win_base_sint_t)(mk_win_user_window_data_id_e_userdata)), ((mk_win_base_uintptr_t)(statistics))); mk_lang_assert(data == 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_windows_on_destroy(mk_lib_statistics_windows_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_windows_on_paint(mk_lib_statistics_windows_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_windows_on_notify_counters_dispinfo(mk_lib_statistics_windows_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{

	mk_win_comctl_base_nmhdr_pt nmhdr;
	mk_lang_types_sint_t err;
	mk_win_comctl_list_view_notify_dispinfo_w_pt dispinfo;
	mk_sl_cui_uint128_pct cntr;
	mk_lang_types_wchar_pt buf;
	mk_lang_types_sint_t len;

	mk_lang_assert(statistics);
	mk_lang_assert(lparam);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	nmhdr = ((mk_win_comctl_base_nmhdr_pt)(lparam));
	mk_lang_assert(nmhdr->m_wnd.m_data == statistics->m_counters.m_data);
	mk_lang_assert(nmhdr->m_code == mk_win_comctl_list_view_notification_id_e_getdispinfow);
	dispinfo = ((mk_win_comctl_list_view_notify_dispinfo_w_pt)(nmhdr));
	mk_lang_assert(dispinfo->m_item.m_item != -1);
	if((dispinfo->m_item.m_mask & mk_win_comctl_list_view_item_mask_e_text) != 0)
	{
		if(dispinfo->m_item.m_sub_item == 0)
		{
			dispinfo->m_item.m_text_buf = ((mk_win_base_wchar_lpt)(mk_lib_statistics_windows_labels[dispinfo->m_item.m_item]));
		}
		else
		{
			mk_lang_assert(dispinfo->m_item.m_item >= 0 && dispinfo->m_item.m_item < mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs));
			cntr = &statistics->m_cntrs_last.m_data.m_arry.m_cntrs[dispinfo->m_item.m_item];
			buf = &statistics->m_cntr_as_text_buf[statistics->m_cntr_as_text_idx][0];
			statistics->m_cntr_as_text_idx = (statistics->m_cntr_as_text_idx + 1) % mk_lang_countof(statistics->m_cntr_as_text_buf);;
			len = mk_sl_cui_uint128_to_str_dec_w(cntr, &buf[0], mk_sl_cui_uint128_strlendec_v); mk_lang_assert(len >= 1 && len <= mk_sl_cui_uint128_strlendec_v);
			buf[len] = L'\0';
			dispinfo->m_item.m_text_buf = buf;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_windows_on_notify_counters_general(mk_lib_statistics_windows_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_win_comctl_base_nmhdr_pt nmhdr;
	mk_lang_types_sint_t err;

	mk_lang_assert(statistics);
	mk_lang_assert(lparam);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	nmhdr = ((mk_win_comctl_base_nmhdr_pt)(lparam));
	mk_lang_assert(nmhdr->m_wnd.m_data == statistics->m_counters.m_data);
	switch(nmhdr->m_code)
	{
		case mk_win_comctl_list_view_notification_id_e_getdispinfow: err = mk_lib_statistics_windows_on_notify_counters_dispinfo(statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_windows_on_notify(mk_lib_statistics_windows_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_win_comctl_base_nmhdr_pt nmhdr;
	mk_lang_types_sint_t err;

	mk_lang_assert(statistics);
	mk_lang_assert(lparam);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	((mk_lang_types_void_t)(wparam));
	nmhdr = ((mk_win_comctl_base_nmhdr_pt)(lparam));
	if(nmhdr->m_wnd.m_data == statistics->m_counters.m_data)
	{
		err = mk_lib_statistics_windows_on_notify_counters_general(statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_windows_on_user_1(mk_lib_statistics_windows_pt const statistics, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_windows_on_msg(mk_lib_statistics_windows_pt const statistics, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam, mk_lang_types_bool_pt const override_defproc, mk_win_user_base_lresult_pt const override_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(statistics);
	mk_lang_assert(override_defproc);
	mk_lang_assert(override_result);

	switch(msg)
	{
		case mk_win_user_msg_id_e_destroy : err = mk_lib_statistics_windows_on_destroy(statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_paint   : err = mk_lib_statistics_windows_on_paint  (statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_notify  : err = mk_lib_statistics_windows_on_notify (statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
		case mk_win_user_msg_id_e_user + 1: err = mk_lib_statistics_windows_on_user_1 (statistics, wparam, lparam, override_defproc, override_result); mk_lang_check_rereturn(err); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_win_user_base_lresult_t mk_win_base_stdcall mk_lib_statistics_windows_on_raw_msg(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t override_defproc;
	mk_win_base_uintptr_t data;
	mk_lib_statistics_windows_pt statistics;
	mk_win_user_base_lresult_t lr;

	err = mk_lib_statistics_windows_on_create(wnd, msg, wparam, lparam); mk_lang_check_recrash(err);
	override_defproc = mk_lang_false;
	data = mk_win_user_window_w_data_get(wnd, ((mk_win_base_sint_t)(mk_win_user_window_data_id_e_userdata))); statistics = ((mk_lib_statistics_windows_pt)(data));
	if(data != 0)
	{
		err = mk_lib_statistics_windows_on_msg(statistics, msg, wparam, lparam, &override_defproc, &lr); mk_lang_check_recrash(err);
	}
	if(!override_defproc)
	{
		lr = mk_win_user_window_w_def_proc(wnd, msg, wparam, lparam);
	}
	return lr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_windows_show_(mk_lib_statistics_windows_pt const statistics) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_module_t this_module;
	mk_win_user_base_wnd_t wnd;
	mk_win_comctl_list_view_column_descr_w_v1_t col_descr;
	mk_win_user_base_lresult_t lr;

	mk_lang_assert(statistics);

	b = mk_win_kernel_dll_w_get_module_handle_ex(((mk_win_base_dword_t)(mk_win_kernel_dll_get_module_handle_ex_flags_e_from_address)), ((mk_win_base_wchar_pct)(((mk_win_base_void_pt)(&mk_lib_statistics_windows_on_raw_msg)))), &this_module); mk_lang_check_return(b != 0); mk_lang_check_return(!mk_win_base_module_is_null(this_module));
	wnd = mk_win_user_window_w_createex(((mk_win_base_dword_t)(mk_win_user_window_styleex_id_e_overlappedwindow)), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(statistics->m_atom)))), L"statistics", ((mk_win_base_dword_t)(mk_win_user_window_style_id_e_overlappedwindow)), mk_win_user_window_use_default, mk_win_user_window_use_default, 250, 220, mk_win_user_base_wnd_get_null(), mk_win_user_menu_get_null(), mk_win_base_instance_from(this_module.m_data), statistics); mk_lang_check_return(!mk_win_user_base_wnd_is_null(wnd)); mk_lang_assert(statistics->m_wnd.m_data == wnd.m_data);

	wnd = mk_win_user_window_w_createex(((mk_win_base_dword_t)(0)), mk_win_comctl_list_view_class_name_w, L"", ((mk_win_base_dword_t)(mk_win_user_window_style_id_e_visible | mk_win_user_window_style_id_e_child)) | ((mk_win_base_dword_t)(mk_win_comctl_list_view_window_style_id_e_report | mk_win_comctl_list_view_window_style_id_e_showselalways | mk_win_comctl_list_view_window_style_id_e_ownerdata)), mk_win_user_window_use_default, mk_win_user_window_use_default, mk_win_user_window_use_default, mk_win_user_window_use_default, wnd, mk_win_user_menu_get_null(), mk_win_base_instance_from(this_module.m_data), mk_win_base_null); mk_lang_check_return(!mk_win_user_base_wnd_is_null(wnd)); statistics->m_counters = wnd;
	lr = mk_win_user_window_w_msg_send(statistics->m_counters, ((mk_win_base_uint_t)(mk_win_comctl_list_view_msg_id_e_setextendedlistviewstyle)), ((mk_win_base_dword_t)(mk_win_comctl_list_view_window_styleex_id_e_fullrowselect | mk_win_comctl_list_view_window_styleex_id_e_autosizecolumns | mk_win_comctl_list_view_window_styleex_id_e_doublebuffer)), ((mk_win_base_dword_t)(mk_win_comctl_list_view_window_styleex_id_e_fullrowselect | mk_win_comctl_list_view_window_styleex_id_e_autosizecolumns | mk_win_comctl_list_view_window_styleex_id_e_doublebuffer))); ((mk_lang_types_void_t)(lr));
	col_descr.m_mask = ((mk_win_base_uint_t)(mk_win_comctl_list_view_col_mask_e_width | mk_win_comctl_list_view_col_mask_e_text));
	col_descr.m_cx = 100;
	col_descr.m_text_buf = ((mk_win_base_wchar_lpt)(L"counter"));
	lr = mk_win_user_window_w_msg_send(statistics->m_counters, ((mk_win_base_uint_t)(mk_win_comctl_list_view_msg_id_e_insertcolumnw)), 0, ((mk_win_user_base_lparam_t)(&col_descr))); mk_lang_check_return(lr == 0);
	col_descr.m_mask = ((mk_win_base_uint_t)(mk_win_comctl_list_view_col_mask_e_fmt | mk_win_comctl_list_view_col_mask_e_width | mk_win_comctl_list_view_col_mask_e_text));
	col_descr.m_fmt = ((mk_win_base_sint_t)(mk_win_comctl_list_view_col_fmt_e_right));
	col_descr.m_text_buf = ((mk_win_base_wchar_lpt)(L"value"));
	lr = mk_win_user_window_w_msg_send(statistics->m_counters, ((mk_win_base_uint_t)(mk_win_comctl_list_view_msg_id_e_insertcolumnw)), 1, ((mk_win_user_base_lparam_t)(&col_descr))); mk_lang_check_return(lr == 1);
	lr = mk_win_user_window_w_msg_send(statistics->m_counters, ((mk_win_base_uint_t)(mk_win_comctl_list_view_msg_id_e_setitemcount)), 8, 0); /*mk_lang_check_return(lr == 0);*/

	b = mk_win_user_window_show(statistics->m_wnd, mk_win_user_window_show_e_shownormal); ((mk_lang_types_void_t)(b));
	return 0;
}


static mk_lib_statistics_windows_t g_mk_lib_statistics_windows;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_statistics_windows_pt statistics;
	mk_win_base_bool_t b;
	mk_win_base_module_t this_module;
	mk_win_user_class_exw_t cls;
	mk_win_user_base_atom_t atom;

	mk_win_comctl_base_init();
	statistics = &g_mk_lib_statistics_windows;
	b = mk_win_kernel_dll_w_get_module_handle_ex(((mk_win_base_dword_t)(mk_win_kernel_dll_get_module_handle_ex_flags_e_from_address)), ((mk_win_base_wchar_pct)(((mk_win_base_void_pt)(&mk_lib_statistics_windows_on_raw_msg)))), &this_module); mk_lang_check_return(b != 0); mk_lang_check_return(!mk_win_base_module_is_null(this_module));
	cls.m_len = ((mk_win_base_uint_t)(sizeof(cls)));
	cls.m_style = ((mk_win_base_uint_t)(mk_win_user_class_style_id_e_vredraw | mk_win_user_class_style_id_e_hredraw));
	cls.m_callback = &mk_lib_statistics_windows_on_raw_msg;
	cls.m_extra_cls = ((mk_win_base_sint_t)(0));
	cls.m_extra_wnd = ((mk_win_base_sint_t)(sizeof(statistics)));
	cls.m_instance = mk_win_base_instance_from(this_module.m_data);
	cls.m_icon_big = mk_win_user_icon_w_load(mk_win_base_instance_get_null(), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(((mk_win_base_ushort_t)(mk_win_user_icon_id_e_application)))))));
	cls.m_cursor = mk_win_user_cursor_w_load(mk_win_base_instance_get_null(), ((mk_win_base_wchar_lpct)(((mk_win_base_uintptr_t)(((mk_win_base_ushort_t)(mk_win_user_cursor_id_e_arrow)))))));
	cls.m_background = mk_win_user_brush_from_color_id(mk_win_user_base_color_id_e_window);
	cls.m_menu = ((mk_win_base_wchar_lpct)(mk_win_base_null));
	cls.m_name = mk_lib_statistics_windows_window_class_name_get();
	cls.m_icon_smol = cls.m_icon_big;
	atom = mk_win_user_class_register_exw(&cls); mk_lang_check_return(atom != 0);
	statistics->m_atom = atom;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_statistics_windows_pt statistics;
	mk_win_base_bool_t b;
	mk_win_base_module_t this_module;

	statistics = &g_mk_lib_statistics_windows;
	mk_lang_assert(statistics->m_atom != 0);
	b = mk_win_kernel_dll_w_get_module_handle_ex(((mk_win_base_dword_t)(mk_win_kernel_dll_get_module_handle_ex_flags_e_from_address)), ((mk_win_base_wchar_pct)(((mk_win_base_void_pt)(&mk_lib_statistics_windows_on_raw_msg)))), &this_module); mk_lang_check_return(b != 0); mk_lang_check_return(!mk_win_base_module_is_null(this_module));
	b = mk_win_user_class_w_unregister(((mk_win_base_wchar_pct)(((mk_win_base_uintptr_t)(statistics->m_atom)))), mk_win_base_instance_from(this_module.m_data)); mk_lang_check_return(b != 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_show(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_statistics_windows_pt statistics;
	mk_lang_types_sint_t err;

	statistics = &g_mk_lib_statistics_windows;
	err = mk_lib_statistics_windows_show_(statistics); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_hide(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_statistics_windows_pt statistics;
	mk_win_user_base_lresult_t lr;

	statistics = &g_mk_lib_statistics_windows;
	mk_lang_assert(statistics->m_atom != 0);
	if(!mk_win_user_base_wnd_is_null(statistics->m_wnd))
	{
		lr = mk_win_user_window_w_msg_send(statistics->m_wnd, ((mk_win_base_uint_t)(mk_win_user_msg_id_e_close)), 0, 0); ((mk_lang_types_void_t)(lr));
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_invalidate(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_statistics_windows_pt statistics;
	mk_win_base_sint_t err;
	mk_lib_statistics_windows_cntrs_t cntrs;
	mk_win_base_bool_t b;

	statistics = &g_mk_lib_statistics_windows;
	mk_lang_assert(statistics->m_atom != 0);
	if(!mk_win_user_base_wnd_is_null(statistics->m_wnd))
	{
		err = mk_lib_statistics_windows_mallocatorg_statistics_get_all(&cntrs.m_data.m_arry.m_cntrs[0]); mk_lang_check_rereturn(err);
		if(!mk_lib_statistics_windows_cntrs_ro_eq(&cntrs, &statistics->m_cntrs_last))
		{
			statistics->m_cntrs_last = cntrs;
			b = mk_win_user_window_invalidate_region(statistics->m_counters, mk_win_user_region_get_null(), mk_win_base_true); mk_lang_check_return(b != 0);
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_pump(mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	mk_lang_assert(at_least_one);
}
