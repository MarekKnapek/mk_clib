#ifndef mk_include_guard_mk_lib_iip_cp_client_socket_c
#define mk_include_guard_mk_lib_iip_cp_client_socket_c
#include "mk_lib_iip_cp_client_socket.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_runtime_bool.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_lib_compress_deflate.h"
#include "mk_lib_fmt.h"
#include "mk_lib_hash_crc32.h"
#include "mk_lib_iip_base32_encoder.h"
#include "mk_lib_iip_buffer.h"
#include "mk_lib_iip_cp_client_shared.h"
#include "mk_lib_iip_cp_destination.h"
#include "mk_lib_iip_cp_dynamic_ring.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_iip_http.h"
#include "mk_lib_iip_key_sgn.h"
#include "mk_lib_iip_key_sgn_dsa_sha1.h"
#include "mk_lib_iip_logger.h"
#include "mk_lib_iip_logger_more.h"
#include "mk_lib_iip_net_streaming_packet.h"
#include "mk_lib_iip_random.h"
#include "mk_lib_iip_time.h"
#include "mk_lib_zlib.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


#if defined mk_lib_iip_cp_client_socket_debug_print_want
#if (mk_lib_iip_cp_client_socket_debug_print_want) == 0
#define mk_lib_iip_cp_client_socket_debug_print_have 0
#elif (mk_lib_iip_cp_client_socket_debug_print_want) == 1
#define mk_lib_iip_cp_client_socket_debug_print_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_lib_iip_cp_client_socket_debug_print_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lib_iip_cp_client_socket_debug_print_have 0
#else
#define mk_lib_iip_cp_client_socket_debug_print_have 1
#endif
#endif
#endif


#define mk_sl_cui_t_name mk_lib_iip_cp_client_socket_handle
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packet_with_payload_rw_destroy(mk_lib_iip_cp_client_socket_packet_with_payload_pt const x) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	((mk_lang_types_void_t)(x->m_packet));
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_destroy(&x->m_payload); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_construct_void(mk_lib_iip_cp_client_socket_packet_with_payload_ppt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_check_todo();
	((mk_lang_types_void_t)(elements_ptr));
	((mk_lang_types_void_t)(elements_cnt));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_destroy(mk_lib_iip_cp_client_socket_packet_with_payload_ppt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_socket_packet_with_payload_pt obj;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	n = elements_cnt;
	for(i = 0; i != n; ++i)
	{
		obj = elements_ptr[i];
		if(obj)
		{
			err = mk_lib_iip_cp_client_socket_packet_with_payload_rw_destroy(obj); mk_lang_check_rereturn(err);
			err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_construct_copy(mk_lib_iip_cp_client_socket_packet_with_payload_ppt const dst, mk_lib_iip_cp_client_socket_packet_with_payload_pcpt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_check_todo();
	((mk_lang_types_void_t)(dst));
	((mk_lang_types_void_t)(src));
	((mk_lang_types_void_t)(cnt));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_construct_move(mk_lib_iip_cp_client_socket_packet_with_payload_ppt const dst, mk_lib_iip_cp_client_socket_packet_with_payload_ppt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	n = cnt;
	for(i = 0; i != n; ++i)
	{
		dst[i] = src[i];
		src[i] = mk_lang_null;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_assign_copy(mk_lib_iip_cp_client_socket_packet_with_payload_ppt const dst, mk_lib_iip_cp_client_socket_packet_with_payload_pcpt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_check_todo();
	((mk_lang_types_void_t)(dst));
	((mk_lang_types_void_t)(src));
	((mk_lang_types_void_t)(cnt));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_assign_move(mk_lib_iip_cp_client_socket_packet_with_payload_ppt const dst, mk_lib_iip_cp_client_socket_packet_with_payload_ppt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	n = cnt;
	for(i = 0; i != n; ++i)
	{
		dst[i] = src[i];
		src[i] = mk_lang_null;
	}
	return 0;
}

#define mk_sl_dynamic_ring_t_name mk_lib_iip_cp_client_socket_packets_with_payload
#define mk_sl_dynamic_ring_t_element_type mk_lib_iip_cp_client_socket_packet_with_payload_pt
#define mk_sl_dynamic_ring_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_dynamic_ring_t_element_construct_void mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_construct_void
#define mk_sl_dynamic_ring_t_element_destruct mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_destroy
#define mk_sl_dynamic_ring_t_element_construct_copy mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_construct_copy
#define mk_sl_dynamic_ring_t_element_construct_move mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_construct_move
#define mk_sl_dynamic_ring_t_element_assign_copy mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_assign_copy
#define mk_sl_dynamic_ring_t_element_assign_move mk_lib_iip_cp_client_socket_packet_with_payload_ptr_rw_assign_move
#include "mk_sl_dynamic_ring_inl_filec.h"
#include "mk_sl_dynamic_ring_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packet_rw_construct(mk_lib_iip_cp_client_socket_packet_pt const x) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	mk_lib_iip_time_get_now(&x->m_created_at);
	x->m_next = mk_lang_false;
	x->m_failed = mk_lang_false;
	err = mk_lib_iip_cp_message_construct(&x->m_msg, mk_lib_iip_cp_message_message_type_id_e_dummy_end); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packet_rw_destroy(mk_lib_iip_cp_client_socket_packet_pt const x) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	err = mk_lib_iip_cp_message_destroy(&x->m_msg); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packets_ptr_rw_construct_void(mk_lib_iip_cp_client_socket_packet_ppt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	n = elements_cnt;
	for(i = 0; i != n; ++i)
	{
		elements_ptr[i] = mk_lang_null;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packets_ptr_rw_destroy(mk_lib_iip_cp_client_socket_packet_ppt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_socket_packet_pt obj;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	n = elements_cnt;
	for(i = 0; i != n; ++i)
	{
		obj = elements_ptr[i];
		if(obj)
		{
			err = mk_lib_iip_cp_client_socket_packet_rw_destroy(obj); mk_lang_check_rereturn(err);
			err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packets_ptr_rw_construct_copy(mk_lib_iip_cp_client_socket_packet_ppt const dst, mk_lib_iip_cp_client_socket_packet_pcpt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_assert_false();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packets_ptr_rw_construct_move(mk_lib_iip_cp_client_socket_packet_ppt const dst, mk_lib_iip_cp_client_socket_packet_ppt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	n = cnt;
	for(i = 0; i != n; ++i)
	{
		dst[i] = src[i];
		src[i] = mk_lang_null;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packets_ptr_rw_assign_copy(mk_lib_iip_cp_client_socket_packet_ppt const dst, mk_lib_iip_cp_client_socket_packet_pcpt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_assert_false();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_packets_ptr_rw_assign_move(mk_lib_iip_cp_client_socket_packet_ppt const dst, mk_lib_iip_cp_client_socket_packet_ppt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	n = cnt;
	for(i = 0; i != n; ++i)
	{
		dst[i] = src[i];
		src[i] = mk_lang_null;
	}
	return 0;
}

#define mk_sl_dynamic_ring_t_name mk_lib_iip_cp_client_socket_packets
#define mk_sl_dynamic_ring_t_element_type mk_lib_iip_cp_client_socket_packet_pt
#define mk_sl_dynamic_ring_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_dynamic_ring_t_element_construct_void mk_lib_iip_cp_client_socket_packets_ptr_rw_construct_void
#define mk_sl_dynamic_ring_t_element_destruct mk_lib_iip_cp_client_socket_packets_ptr_rw_destroy
#define mk_sl_dynamic_ring_t_element_construct_copy mk_lib_iip_cp_client_socket_packets_ptr_rw_construct_copy
#define mk_sl_dynamic_ring_t_element_construct_move mk_lib_iip_cp_client_socket_packets_ptr_rw_construct_move
#define mk_sl_dynamic_ring_t_element_assign_copy mk_lib_iip_cp_client_socket_packets_ptr_rw_assign_copy
#define mk_sl_dynamic_ring_t_element_assign_move mk_lib_iip_cp_client_socket_packets_ptr_rw_assign_move
#include "mk_sl_dynamic_ring_inl_filec.h"
#include "mk_sl_dynamic_ring_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_write_request_rw_construct_void(mk_lib_iip_cp_client_socket_write_request_pt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(elements_ptr));
	((mk_lang_types_void_t)(elements_cnt));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_write_request_rw_destroy(mk_lib_iip_cp_client_socket_write_request_pt const elements_ptr, mk_lang_types_usize_t const elements_cnt) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(elements_ptr || elements_cnt == 0);
	mk_lang_assert(elements_cnt >= 0);
	mk_lang_assert(elements_cnt <= mk_lang_limits_usize_max / sizeof(*elements_ptr));
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(elements_ptr));
	((mk_lang_types_void_t)(elements_cnt));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_write_request_rw_construct_copy(mk_lib_iip_cp_client_socket_write_request_pt const dst, mk_lib_iip_cp_client_socket_write_request_pct const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	n = cnt;
	for(i = 0; i != n; ++i)
	{
		dst[i] = src[i];
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_write_request_rw_construct_move(mk_lib_iip_cp_client_socket_write_request_pt const dst, mk_lib_iip_cp_client_socket_write_request_pt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	n = cnt;
	for(i = 0; i != n; ++i)
	{
		dst[i] = src[i];
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_write_request_rw_assign_copy(mk_lib_iip_cp_client_socket_write_request_pt const dst, mk_lib_iip_cp_client_socket_write_request_pct const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	n = cnt;
	for(i = 0; i != n; ++i)
	{
		dst[i] = src[i];
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_write_request_rw_assign_move(mk_lib_iip_cp_client_socket_write_request_pt const dst, mk_lib_iip_cp_client_socket_write_request_pt const src, mk_lang_types_usize_t const cnt) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || cnt == 0);
	mk_lang_assert(src || cnt == 0);
	mk_lang_assert(cnt >= 0);
	mk_lang_assert(cnt <= mk_lang_limits_usize_max / sizeof(*dst));
	#include "mk_lang_warning_msvc_pop.h"

	n = cnt;
	for(i = 0; i != n; ++i)
	{
		dst[i] = src[i];
	}
	return 0;
}

#define mk_sl_dynamic_ring_t_name mk_lib_iip_cp_client_socket_write_requests
#define mk_sl_dynamic_ring_t_element_type mk_lib_iip_cp_client_socket_write_request_t
#define mk_sl_dynamic_ring_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_dynamic_ring_t_element_construct_void mk_lib_iip_cp_client_socket_write_request_rw_construct_void
#define mk_sl_dynamic_ring_t_element_destruct mk_lib_iip_cp_client_socket_write_request_rw_destroy
#define mk_sl_dynamic_ring_t_element_construct_copy mk_lib_iip_cp_client_socket_write_request_rw_construct_copy
#define mk_sl_dynamic_ring_t_element_construct_move mk_lib_iip_cp_client_socket_write_request_rw_construct_move
#define mk_sl_dynamic_ring_t_element_assign_copy mk_lib_iip_cp_client_socket_write_request_rw_assign_copy
#define mk_sl_dynamic_ring_t_element_assign_move mk_lib_iip_cp_client_socket_write_request_rw_assign_move
#include "mk_sl_dynamic_ring_inl_filec.h"
#include "mk_sl_dynamic_ring_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_construct(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_client_socket_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(settings->m_shared);
	mk_lang_assert(settings->m_session_id);
	mk_lang_assert(settings->m_is_listener == mk_lang_false || settings->m_is_listener == mk_lang_true);
	mk_lang_assert(settings->m_local_destination);
	mk_lang_assert(!mk_sl_cui_uint32_is_zero(&settings->m_stream_id));
	mk_lang_assert(!mk_sl_cui_uint32_is_max(&settings->m_stream_id));

	task->m_step = ((mk_lib_iip_cp_client_socket_task_step_t)(0));
	task->m_socket.m_settings = *settings;
	task->m_socket.m_state.m_stop_requested = mk_lang_false;
	task->m_socket.m_state.m_stop_acknowledged = mk_lang_false;
	err = mk_lib_iip_cp_client_socket_packets_with_payload_rw_construct(&task->m_socket.m_state.m_packets_in_arrived); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_with_payload_rw_construct(&task->m_socket.m_state.m_packets_in_to_ack); mk_lang_check_rereturn(err);
	task->m_socket.m_state.m_waiting_for_syn = mk_lang_true;
	task->m_socket.m_state.m_our_syn_sent = mk_lang_false;
	mk_sl_cui_uint16_set_zero(&task->m_socket.m_state.m_local_port);
	mk_sl_cui_uint16_set_zero(&task->m_socket.m_state.m_remote_port);
	mk_sl_cui_uint32_set_zero(&task->m_socket.m_state.m_local_stream_id);
	mk_sl_cui_uint32_set_zero(&task->m_socket.m_state.m_remote_stream_id);
	mk_sl_cui_uint32_set_zero(&task->m_socket.m_state.m_local_sequence_number);
	mk_sl_cui_uint32_set_zero(&task->m_socket.m_state.m_remote_sequence_number);
	task->m_socket.m_state.m_remote_destination.m_certificate.m_cert_type = mk_lib_iip_cp_destination_cert_type_e_dummy_end;
	mk_lang_string_memclr_pc_fn(&task->m_socket.m_state.m_remote_b32[0], mk_lang_countof(task->m_socket.m_state.m_remote_b32));
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_construct(&task->m_socket.m_state.m_data_to_sent); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_construct(&task->m_socket.m_state.m_data_received); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_construct(&task->m_socket.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_dummy_end); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_write_requests_rw_construct(&task->m_socket.m_state.m_write_requests); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_rw_construct(&task->m_socket.m_state.m_packets_out_ready); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_rw_construct(&task->m_socket.m_state.m_packets_out_sent); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_rw_construct(&task->m_socket.m_state.m_packets_out_accepted); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_rw_construct(&task->m_socket.m_state.m_packets_out_succeeded); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_rw_construct(&task->m_socket.m_state.m_packets_out_paused); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_destroy(mk_lib_iip_cp_client_socket_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_client_socket_packets_with_payload_rw_destroy(&task->m_socket.m_state.m_packets_in_arrived); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_with_payload_rw_destroy(&task->m_socket.m_state.m_packets_in_to_ack); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_destroy(&task->m_socket.m_state.m_data_to_sent); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_destroy(&task->m_socket.m_state.m_data_received); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_destroy(&task->m_socket.m_state.m_msg); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_write_requests_rw_destroy(&task->m_socket.m_state.m_write_requests); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_rw_destroy(&task->m_socket.m_state.m_packets_out_ready); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_rw_destroy(&task->m_socket.m_state.m_packets_out_sent); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_rw_destroy(&task->m_socket.m_state.m_packets_out_accepted); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_rw_destroy(&task->m_socket.m_state.m_packets_out_succeeded); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_rw_destroy(&task->m_socket.m_state.m_packets_out_paused); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_request_close(mk_lib_iip_cp_client_socket_task_pt const task) mk_lang_noexcept
{
	mk_lang_assert(task);

	task->m_socket.m_state.m_stop_requested = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_want_die(mk_lib_iip_cp_client_socket_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lang_types_bool_t wand;

	mk_lang_assert(task);
	mk_lang_assert(want);

	wand =
		(mk_lang_false);
	*want = wand;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_is_connected(mk_lib_iip_cp_client_socket_task_pt const task, mk_lang_types_bool_pt const is) mk_lang_noexcept
{
	mk_lang_types_bool_t is_connected;

	mk_lang_assert(task);
	mk_lang_assert(is);

	is_connected =
		(!task->m_socket.m_settings.m_is_listener) &&
		(task->m_socket.m_state.m_our_syn_sent) &&
		(!task->m_socket.m_state.m_waiting_for_syn) &&
		(mk_lang_true);
	*is = is_connected;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_on_packet_eat_incoming(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_net_streaming_packet_pt const packet) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_socket_packet_with_payload_pt packet_with_payload;
	mk_lang_types_void_pt mem;

	mk_lang_assert(task);
	mk_lang_assert(packet);

	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*packet_with_payload), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); packet_with_payload = ((mk_lib_iip_cp_client_socket_packet_with_payload_pt)(mem)); mk_lang_assert(packet_with_payload);

	packet_with_payload->m_packet = *packet;
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_construct(&packet_with_payload->m_payload); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_push_back_move_many(&packet_with_payload->m_payload, packet->m_payload_buf, ((mk_lang_types_usize_t)(packet->m_payload_len))); mk_lang_check_rereturn(err);

	err = mk_lib_iip_cp_client_socket_packets_with_payload_rw_push_back_move_single(&task->m_socket.m_state.m_packets_in_arrived, &packet_with_payload); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_on_packet_connector_initial_sync(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint16_pct const src_port, mk_sl_cui_uint16_pct const dst_port, mk_lib_iip_net_streaming_packet_pt const packet, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_bool_t eaten;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(src_port);
	mk_lang_assert(dst_port);
	mk_lang_assert(packet);
	mk_lang_assert(consumed);
	mk_lang_assert(!task->m_socket.m_settings.m_is_listener);

	/*mk_lang_assert(mk_sl_cui_uint16_eq(dst_port, &task->m_socket.m_settings.m_local_port));*/
	mk_lang_assert((packet->m_flags & mk_lib_iip_net_streaming_packet_flag_e_synchronize) != 0);
	mk_lang_assert((packet->m_flags & mk_lib_iip_net_streaming_packet_flag_e_signature_included) != 0);
	mk_lang_assert((packet->m_flags & mk_lib_iip_net_streaming_packet_flag_e_from_included) != 0);
	mk_lang_assert(mk_sl_cui_uint32_eq(&packet->m_send_stream_id, &task->m_socket.m_state.m_local_stream_id));
	mk_lang_assert(mk_sl_cui_uint32_is_zero(&packet->m_sequence_number));
	mk_lang_assert(task->m_socket.m_state.m_our_syn_sent);
	mk_lang_assert(task->m_socket.m_state.m_waiting_for_syn);
	mk_lang_assert(!mk_sl_cui_uint32_is_zero(&packet->m_recv_stream_id));

	eaten = mk_lang_true;
	task->m_socket.m_state.m_waiting_for_syn = mk_lang_false;
	task->m_socket.m_state.m_remote_stream_id = packet->m_recv_stream_id;
	mk_sl_cui_uint32_set_zero(&task->m_socket.m_state.m_remote_sequence_number);
	mk_sl_cui_uint32_inc1(&task->m_socket.m_state.m_remote_sequence_number);
	err = mk_lib_iip_cp_client_socket_task_prrw_on_packet_eat_incoming(task, packet); mk_lang_check_rereturn(err);
	*consumed = eaten;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_on_packet_connector_incoming(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint16_pct const src_port, mk_sl_cui_uint16_pct const dst_port, mk_lib_iip_net_streaming_packet_pt const packet, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_bool_t eaten;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(src_port);
	mk_lang_assert(dst_port);
	mk_lang_assert(packet);
	mk_lang_assert(consumed);
	mk_lang_assert(!task->m_socket.m_settings.m_is_listener);

	/*mk_lang_assert(mk_sl_cui_uint16_eq(dst_port, &task->m_socket.m_settings.m_local_port));*/
	mk_lang_assert(task->m_socket.m_state.m_our_syn_sent);
	mk_lang_assert(!task->m_socket.m_state.m_waiting_for_syn);
	mk_lang_assert(mk_sl_cui_uint32_eq(&packet->m_send_stream_id, &task->m_socket.m_state.m_local_stream_id));
	mk_lang_assert(mk_sl_cui_uint32_eq(&packet->m_recv_stream_id, &task->m_socket.m_state.m_remote_stream_id));
	mk_lang_assert(mk_sl_cui_uint32_eq(&packet->m_sequence_number, &task->m_socket.m_state.m_remote_sequence_number));

	eaten = mk_lang_true;
	mk_sl_cui_uint32_inc1(&task->m_socket.m_state.m_remote_sequence_number);
	err = mk_lib_iip_cp_client_socket_task_prrw_on_packet_eat_incoming(task, packet); mk_lang_check_rereturn(err);
	*consumed = eaten;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_on_packet_connector(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint16_pct const src_port, mk_sl_cui_uint16_pct const dst_port, mk_lib_iip_net_streaming_packet_pt const packet, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_bool_t eaten;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(src_port);
	mk_lang_assert(dst_port);
	mk_lang_assert(packet);
	mk_lang_assert(consumed);
	mk_lang_assert(!task->m_socket.m_settings.m_is_listener);

	eaten = mk_lang_false;
	if
	(
		/*(mk_sl_cui_uint16_eq(dst_port, &task->m_socket.m_settings.m_local_port)) &&*/
		((packet->m_flags & mk_lib_iip_net_streaming_packet_flag_e_synchronize) != 0) &&
		((packet->m_flags & mk_lib_iip_net_streaming_packet_flag_e_signature_included) != 0) &&
		((packet->m_flags & mk_lib_iip_net_streaming_packet_flag_e_from_included) != 0) &&
		(mk_sl_cui_uint32_eq(&packet->m_send_stream_id, &task->m_socket.m_state.m_local_stream_id)) &&
		(mk_sl_cui_uint32_is_zero(&packet->m_sequence_number)) &&
		(task->m_socket.m_state.m_our_syn_sent) &&
		(task->m_socket.m_state.m_waiting_for_syn) &&
		(!mk_sl_cui_uint32_is_zero(&packet->m_recv_stream_id)) &&
		(mk_lang_true)
	)
	{
		err = mk_lib_iip_cp_client_socket_task_prrw_on_packet_connector_initial_sync(task, src_port, dst_port, packet, &eaten); mk_lang_check_rereturn(err);
	}
	else if
	(
		/*(mk_sl_cui_uint16_eq(dst_port, &task->m_socket.m_settings.m_local_port)) &&*/
		(task->m_socket.m_state.m_our_syn_sent) &&
		(!task->m_socket.m_state.m_waiting_for_syn) &&
		(mk_sl_cui_uint32_eq(&packet->m_send_stream_id, &task->m_socket.m_state.m_local_stream_id)) &&
		(mk_sl_cui_uint32_eq(&packet->m_recv_stream_id, &task->m_socket.m_state.m_remote_stream_id)) &&
		(mk_sl_cui_uint32_eq(&packet->m_sequence_number, &task->m_socket.m_state.m_remote_sequence_number)) &&
		(mk_lang_true)
	)
	{
		err = mk_lib_iip_cp_client_socket_task_prrw_on_packet_connector_incoming(task, src_port, dst_port, packet, &eaten); mk_lang_check_rereturn(err);
	}
	*consumed = eaten;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_log_on_packet(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_net_streaming_packet_pt const packet) mk_lang_noexcept
{
	#define mk_lib_iip_cp_client_socket_task_prrw_log_on_packet_fmt "Packet arrived, seqence numer %u."

	mk_lib_iip_logger_pt logger;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t str_buf[64];
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(packet);

	logger = &task->m_socket.m_settings.m_shared->m_logger;
	len = mk_lib_fmt_n_snnprintf(&str_buf[0], mk_lang_countof(str_buf), &mk_lib_iip_cp_client_socket_task_prrw_log_on_packet_fmt[0], mk_lang_countstr(mk_lib_iip_cp_client_socket_task_prrw_log_on_packet_fmt), &packet->m_sequence_number); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(str_buf));
	err = mk_lib_iip_logger_rw_begin_line(logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_append_current_time(logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print(logger, &str_buf[0], len); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_line(logger); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_on_packet(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint16_pct const src_port, mk_sl_cui_uint16_pct const dst_port, mk_sl_cui_uint8_pt const decompressed_packet_buf, mk_lang_types_sint_t const decompressed_packet_len, mk_lib_iip_net_streaming_packet_pt const packet, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t eaten;

	mk_lang_assert(task);
	mk_lang_assert(src_port);
	mk_lang_assert(dst_port);
	mk_lang_assert(decompressed_packet_buf || decompressed_packet_len == 0);
	mk_lang_assert(decompressed_packet_len >= 0);
	mk_lang_assert(packet);
	mk_lang_assert(consumed);

	gud = mk_lang_true;
	err = mk_lib_iip_net_streaming_packet_rw_parse(packet, &task->m_socket.m_settings.m_remote_destination, decompressed_packet_buf, decompressed_packet_len, &gud); mk_lang_check_rereturn(err); mk_lang_check_return(gud);
	err = mk_lib_iip_cp_client_socket_task_prrw_log_on_packet(task, packet); mk_lang_check_rereturn(err);
	if(!task->m_socket.m_settings.m_is_listener)
	{
		err = mk_lib_iip_cp_client_socket_task_prrw_on_packet_connector(task, src_port, dst_port, packet, &eaten); mk_lang_check_rereturn(err);
	}
	else
	{
		eaten = mk_lang_false;
		mk_lang_check_todo();
	}
	*consumed = eaten;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_on_msg_status_accepted(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_types_nonce_pct const nonce) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_socket_packet_ppt packet_ptr;
	mk_lib_iip_cp_client_socket_packet_pt packet_val;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(nonce);

	n = mk_lib_iip_cp_client_socket_packets_rw_get_size(&task->m_socket.m_state.m_packets_out_sent);
	for(i = 0; i != n; ++i)
	{
		packet_ptr = mk_lib_iip_cp_client_socket_packets_rw_get_at(&task->m_socket.m_state.m_packets_out_sent, i); mk_lang_assert(packet_ptr); packet_val = *packet_ptr; mk_lang_assert(packet_val);
		if(packet_val->m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_send_message && mk_lib_iip_cp_types_nonce_eq(&packet_val->m_msg.m_mix.m_data.m_send_message.m_nonce, nonce))
		{
			packet_val->m_next = mk_lang_true;
			break;
		}
	}
	mk_lang_check_return(i != n);
	do
	{
		packet_ptr = mk_lib_iip_cp_client_socket_packets_rw_get_front(&task->m_socket.m_state.m_packets_out_sent); mk_lang_assert(packet_ptr); packet_val = *packet_ptr; mk_lang_assert(packet_val);
		if(!packet_val->m_next)
		{
			break;
		}
		packet_val->m_next = mk_lang_false;
		err = mk_lib_iip_cp_client_socket_packets_rw_push_back_move_single(&task->m_socket.m_state.m_packets_out_accepted, packet_ptr); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_client_socket_packets_rw_pop_front_single(&task->m_socket.m_state.m_packets_out_sent); mk_lang_check_rereturn(err);
	}
	while(!mk_lib_iip_cp_client_socket_packets_rw_is_empty(&task->m_socket.m_state.m_packets_out_sent));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_on_msg_status_guaranteed_success(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_types_nonce_pct const nonce) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_socket_packet_ppt packet_ptr;
	mk_lib_iip_cp_client_socket_packet_pt packet_val;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(nonce);

	n = mk_lib_iip_cp_client_socket_packets_rw_get_size(&task->m_socket.m_state.m_packets_out_accepted);
	for(i = 0; i != n; ++i)
	{
		packet_ptr = mk_lib_iip_cp_client_socket_packets_rw_get_at(&task->m_socket.m_state.m_packets_out_accepted, i); mk_lang_assert(packet_ptr); packet_val = *packet_ptr; mk_lang_assert(packet_val);
		if(packet_val->m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_send_message && mk_lib_iip_cp_types_nonce_eq(&packet_val->m_msg.m_mix.m_data.m_send_message.m_nonce, nonce))
		{
			packet_val->m_next = mk_lang_true;
			break;
		}
	}
	mk_lang_check_return(i != n);
	do
	{
		packet_ptr = mk_lib_iip_cp_client_socket_packets_rw_get_front(&task->m_socket.m_state.m_packets_out_accepted); mk_lang_assert(packet_ptr); packet_val = *packet_ptr; mk_lang_assert(packet_val);
		if(!packet_val->m_next)
		{
			break;
		}
		packet_val->m_next = mk_lang_false;
		err = mk_lib_iip_cp_client_socket_packets_rw_push_back_move_single(&task->m_socket.m_state.m_packets_out_succeeded, packet_ptr); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_client_socket_packets_rw_pop_front_single(&task->m_socket.m_state.m_packets_out_accepted); mk_lang_check_rereturn(err);
	}
	while(!mk_lib_iip_cp_client_socket_packets_rw_is_empty(&task->m_socket.m_state.m_packets_out_accepted));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_on_msg_status_no_leaseset(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_types_nonce_pct const nonce) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_socket_packet_ppt packet_ptr;
	mk_lib_iip_cp_client_socket_packet_pt packet_val;
	mk_lang_types_sint_t tsi;
	mk_lib_iip_time_timestamp_t diff;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(nonce);

	n = mk_lib_iip_cp_client_socket_packets_rw_get_size(&task->m_socket.m_state.m_packets_out_accepted);
	for(i = 0; i != n; ++i)
	{
		packet_ptr = mk_lib_iip_cp_client_socket_packets_rw_get_at(&task->m_socket.m_state.m_packets_out_accepted, i); mk_lang_assert(packet_ptr); packet_val = *packet_ptr; mk_lang_assert(packet_val);
		if(packet_val->m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_send_message && mk_lib_iip_cp_types_nonce_eq(&packet_val->m_msg.m_mix.m_data.m_send_message.m_nonce, nonce))
		{
			packet_val->m_failed = mk_lang_true;
			break;
		}
	}
	mk_lang_check_return(i != n);
	do
	{
		packet_ptr = mk_lib_iip_cp_client_socket_packets_rw_get_front(&task->m_socket.m_state.m_packets_out_accepted); mk_lang_assert(packet_ptr); packet_val = *packet_ptr; mk_lang_assert(packet_val);
		if(!packet_val->m_failed)
		{
			break;
		}
		packet_val->m_failed = mk_lang_false;
		tsi = 10 * 1000; mk_lib_iip_time_timestamp_from_bi_sint(&diff, &tsi);
		mk_lib_iip_time_get_now(&packet_val->m_resurrect_at);
		mk_lib_iip_time_timestamp_add2_wrap_cid_cod(&packet_val->m_resurrect_at, &diff);
		err = mk_lib_iip_cp_client_socket_packets_rw_push_back_move_single(&task->m_socket.m_state.m_packets_out_paused, packet_ptr); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_client_socket_packets_rw_pop_front_single(&task->m_socket.m_state.m_packets_out_accepted); mk_lang_check_rereturn(err);
	}
	while(!mk_lib_iip_cp_client_socket_packets_rw_is_empty(&task->m_socket.m_state.m_packets_out_accepted));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_process_incoming_packet(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_net_streaming_packet_pt const packet) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(packet);

	((void)(task));
	((void)(packet));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_recv(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const recvd) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lib_iip_cp_client_socket_packet_with_payload_ppt oldest_packet_ptr;
	mk_lib_iip_cp_client_socket_packet_with_payload_pt oldest_packet_val;
	mk_sl_cui_uint8_pct bytes_buf;
	mk_lang_types_sint_t bytes_len;
	mk_lang_types_sint_t to_copy;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t transferred;

	mk_lang_assert(task);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(recvd);

	ptr = data_buf;
	rem = data_len;
	while(rem != 0 && !mk_lib_iip_cp_client_socket_packets_with_payload_rw_is_empty(&task->m_socket.m_state.m_packets_in_arrived))
	{
		oldest_packet_ptr = mk_lib_iip_cp_client_socket_packets_with_payload_rw_get_front(&task->m_socket.m_state.m_packets_in_arrived); mk_lang_assert(oldest_packet_ptr); oldest_packet_val = *oldest_packet_ptr; mk_lang_assert(oldest_packet_val);
		err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&oldest_packet_val->m_payload); mk_lang_check_rereturn(err);
		bytes_buf = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&oldest_packet_val->m_payload);
		bytes_len = mk_lib_iip_cp_dynamic_ring_u8_rw_get_sise_a(&oldest_packet_val->m_payload);
		to_copy = mk_lang_min(rem, bytes_len);
		mk_sl_cui_uint8_memcpy_fn(ptr, bytes_buf, ((mk_lang_types_usize_t)(to_copy)));
		err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&oldest_packet_val->m_payload, ((mk_lang_types_usize_t)(to_copy))); mk_lang_check_rereturn(err);
		ptr += to_copy;
		rem -= to_copy;
		if(mk_lib_iip_cp_dynamic_ring_u8_rw_is_empty(&oldest_packet_val->m_payload))
		{
			err = mk_lib_iip_cp_client_socket_task_prrw_process_incoming_packet(task, &oldest_packet_val->m_packet); mk_lang_check_rereturn(err);
			err = mk_lib_iip_cp_client_socket_packets_with_payload_rw_push_back_move_single(&task->m_socket.m_state.m_packets_in_to_ack, oldest_packet_ptr); mk_lang_check_rereturn(err);
			err = mk_lib_iip_cp_client_socket_packets_with_payload_rw_pop_front_single(&task->m_socket.m_state.m_packets_in_arrived); mk_lang_check_rereturn(err);
		}
	}
	transferred = data_len - rem;
	*recvd = transferred;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_send(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const sent) mk_lang_noexcept
{
	mk_lib_iip_cp_client_socket_write_request_t write_request;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(sent);

	write_request.m_data_buf = data_buf;
	write_request.m_data_len = data_len;
	write_request.m_data_sent = sent;
	err = mk_lib_iip_cp_client_socket_write_requests_rw_push_back_copy_single(&task->m_socket.m_state.m_write_requests, &write_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_compress(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint16_pct const local_port, mk_sl_cui_uint16_pct const remote_port, mk_sl_cui_uint8_pct const decompressed_buf, mk_lang_types_sint_t const decompressed_len, mk_sl_cui_uint8_pt const compressed_buf, mk_lang_types_sint_t const compressed_cap, mk_lang_types_sint_pt const compressed_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint8_t tu8;
	mk_lib_compress_deflate_t compressor;
	mk_lang_types_sint_t in;
	mk_lang_types_sint_t out;
	mk_lang_types_sint_t out_2;
	mk_lib_hash_crc32_t hasher;
	mk_lib_hash_crc32_digest_t digest;
	mk_sl_cui_uint32_t u32;

	mk_lang_assert(task);
	mk_lang_assert(local_port);
	mk_lang_assert(remote_port);
	mk_lang_assert(decompressed_buf || decompressed_len == 0);
	mk_lang_assert(decompressed_len >= 0);
	mk_lang_assert(compressed_buf || compressed_cap == 0);
	mk_lang_assert(compressed_cap >= 10);
	mk_lang_assert(compressed_len);

	ptr = compressed_buf;
	rem = compressed_cap;

	tuc = 0x1f; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); ptr[0] = tu8; ++ptr; --rem; /* magic */
	tuc = 0x8b; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); ptr[0] = tu8; ++ptr; --rem; /* magic */
	tuc = 0x08; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); ptr[0] = tu8; ++ptr; --rem; /* alg = deflate */
	tuc = 0x00; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); ptr[0] = tu8; ++ptr; --rem; /* flags */
	mk_sl_uint_convert_16_8_be_to_sml(local_port, &ptr[0]); ptr += mk_sl_cui_uint16_size_bytes_v; rem -= mk_sl_cui_uint16_size_bytes_v;
	mk_sl_uint_convert_16_8_be_to_sml(remote_port, &ptr[0]); ptr += mk_sl_cui_uint16_size_bytes_v; rem -= mk_sl_cui_uint16_size_bytes_v;
	tuc = 0x02; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); ptr[0] = tu8; ++ptr; --rem; /* xflags = max compression */
	tuc = 6; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); ptr[0] = tu8; ++ptr; --rem; /* os = i2p protocol */

	mk_lib_compress_deflate_init(&compressor);
	mk_lib_compress_deflate_append(&compressor, decompressed_buf, decompressed_len, ptr, rem, &in, &out); mk_lang_check_return(in == decompressed_len); mk_lang_check_return(out <= rem);
	mk_lib_compress_deflate_finish(&compressor, ptr + out, rem - out, &out_2);
	mk_lang_check_return(out_2 <= rem);
	mk_lang_check_return(out + out_2 <= rem);
	ptr += out + out_2;
	rem -= out + out_2;

	mk_lib_hash_crc32_init(&hasher);
	mk_lib_hash_crc32_append(&hasher, decompressed_buf, ((mk_lang_types_usize_t)(decompressed_len)));
	mk_lib_hash_crc32_finish(&hasher, &digest);
	mk_sl_cui_uint8_memcpy_fn(ptr, &digest.m_data.m_uint8s[0], mk_lib_hash_crc32_digest_len_v);
	ptr += mk_lib_hash_crc32_digest_len_v;
	rem -= mk_lib_hash_crc32_digest_len_v;

	mk_sl_cui_uint32_from_bi_sint(&u32, &decompressed_len);
	mk_sl_uint_convert_32_8_le_to_sml(&u32, ptr);
	ptr += mk_sl_cui_uint32_size_bytes_v;
	rem -= mk_sl_cui_uint32_size_bytes_v;

	*compressed_len = compressed_cap - rem;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_compute_remote_b32(mk_lib_iip_cp_client_socket_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_destination_remote_ro_to_b32(&task->m_socket.m_settings.m_remote_destination, &task->m_socket.m_state.m_remote_b32[0], mk_lang_countof(task->m_socket.m_state.m_remote_b32), &tlen); mk_lang_check_rereturn(err); mk_lang_assert(tlen == mk_lang_countof(task->m_socket.m_state.m_remote_b32));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_compute_remote_sha256(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint32_pt const acks) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_t dst_buf[4 * 1024];
	mk_lang_types_sint_t consumed;
	mk_lib_crypto_hash_stream_sha2_256_t hasher;
	mk_lib_crypto_hash_stream_sha2_256_digest_pt digest;

	mk_lang_assert(task);
	mk_lang_assert(acks);

	gud = mk_lang_true;
	err = mk_lib_iip_cp_destination_remote_ro_to_bytes(&task->m_socket.m_settings.m_remote_destination, &dst_buf[0], mk_lang_countof(dst_buf), &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 256 + 128 + 1 + 2); mk_lang_assert(consumed <= mk_lang_countof(dst_buf));
	mk_lib_crypto_hash_stream_sha2_256_init(&hasher);
	mk_lib_crypto_hash_stream_sha2_256_append_u8s(&hasher, &dst_buf[0], ((mk_lang_types_usize_t)(consumed)));
	#include "mk_lang_warning_clang_push_cast_align.h"
	digest = ((mk_lib_crypto_hash_stream_sha2_256_digest_pt)(acks)); /* todo better serialization */
	#include "mk_lang_warning_clang_pop.h"
	mk_lib_crypto_hash_stream_sha2_256_finish(&hasher, digest);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_make_initial_connect_packet(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint8_pct const additional_data_buf, mk_lang_types_sint_t const additional_data_len, mk_sl_cui_uint32_pct const random_uint, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_send_message_pt send_message;
	mk_lib_iip_net_streaming_packet_t packet;
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint8_t decompressed_buf[4 * 1024];
	mk_lang_types_sint_t decompressed_len;
	mk_lang_types_sint_t signature_len;

	mk_lang_assert(task);
	mk_lang_assert(additional_data_buf || additional_data_len == 0);
	mk_lang_assert(additional_data_len >= 0);
	mk_lang_assert(random_uint);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_socket.m_settings.m_session_id);
	mk_lang_assert(!mk_lib_iip_cp_types_sessionid_is_zero(task->m_socket.m_settings.m_session_id));
	mk_lang_assert(!mk_lib_iip_cp_types_sessionid_is_max(task->m_socket.m_settings.m_session_id));
	mk_lang_assert(!mk_sl_cui_uint32_is_zero(&task->m_socket.m_settings.m_stream_id));
	mk_lang_assert(!mk_sl_cui_uint32_is_max(&task->m_socket.m_settings.m_stream_id));
	mk_lang_assert(mk_sl_cui_uint32_is_zero(&task->m_socket.m_state.m_remote_stream_id));
	mk_lang_assert(mk_sl_cui_uint32_is_zero(&task->m_socket.m_state.m_local_sequence_number));

	task->m_socket.m_state.m_local_stream_id = task->m_socket.m_settings.m_stream_id;
	err = mk_lib_iip_cp_message_reconstruct(msg, mk_lib_iip_cp_message_message_type_id_e_send_message); mk_lang_check_rereturn(err);
	send_message = &msg->m_mix.m_data.m_send_message;
	send_message->m_session_id = *task->m_socket.m_settings.m_session_id;
	send_message->m_remote_destination = task->m_socket.m_settings.m_remote_destination;

	err = mk_lib_iip_net_streaming_packet_rw_construct(&packet); mk_lang_check_rereturn(err);
	packet.m_send_stream_id = task->m_socket.m_state.m_remote_stream_id;
	packet.m_recv_stream_id = task->m_socket.m_state.m_local_stream_id;
	packet.m_sequence_number = task->m_socket.m_state.m_local_sequence_number;
	mk_sl_cui_uint32_set_zero(&packet.m_ack_through);
	err = mk_lib_iip_net_streaming_packet_nacks_rw_construct_void(&packet.m_nacks); mk_lang_check_rereturn(err);
	/*packet.m_nacks.m_size = 8;
	err = mk_lib_iip_cp_client_socket_task_prrw_compute_remote_sha256(task, &packet.m_nacks.m_arr[0]); mk_lang_check_rereturn(err);*/
	packet.m_resend_delay = 0;
	packet.m_flags =
	((mk_lib_iip_net_streaming_packet_flag_t)(
		mk_lib_iip_net_streaming_packet_flag_e_synchronize |
		mk_lib_iip_net_streaming_packet_flag_e_signature_included |
		mk_lib_iip_net_streaming_packet_flag_e_from_included |
		mk_lib_iip_net_streaming_packet_flag_e_none
	));
	packet.m_options.m_from = task->m_socket.m_settings.m_local_destination->m_remote_destination;
	packet.m_payload_buf = ((mk_sl_cui_uint8_pt)(additional_data_buf));
	packet.m_payload_len = additional_data_len;

	{
		static char const req[] =
			//"GET / HTTP/1.1" "\x0d\x0a"
			"GET /images/logo.png HTTP/1.1" "\x0d\x0a"
			/*"Host: reg.i2p" "\x0d\x0a"*/
			"Host: i2pforum.i2p" "\x0d\x0a"
			/*"Host: hiddenbooru.i2p" "\x0d\x0a"*/
			"User-Agent: MYOB/6.66 (AN/ON)" "\x0d\x0a"
			"" "\x0d\x0a";
		#include "mk_lang_warning_clang_push_cast_qual.h"
		packet.m_payload_buf = ((mk_sl_cui_uint8_pt)(req));
		packet.m_payload_len = mk_lang_countstr(req);
		#include "mk_lang_warning_clang_pop.h"
	}

	gud = mk_lang_true;
	err = mk_lib_iip_net_streaming_packet_ro_serialize(&packet, &decompressed_buf[0], mk_lang_countof(decompressed_buf), &gud, &decompressed_len); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(decompressed_len >= 1); mk_lang_assert(decompressed_len <= mk_lang_countof(decompressed_buf));
	err = mk_lib_iip_key_sgn_rw_sign_data(task->m_socket.m_settings.m_local_destination, &decompressed_buf[0], decompressed_len, packet.m_signature_buf, mk_lib_iip_key_sgn_dsa_sha1_signature_len_v, &signature_len); mk_lang_check_rereturn(err); mk_lang_check_return(signature_len == mk_lib_iip_key_sgn_dsa_sha1_signature_len_v); /* todo sgn len */
	err = mk_lib_iip_cp_client_socket_task_prrw_compress(task, &task->m_socket.m_state.m_local_port, &task->m_socket.m_settings.m_remote_port, &decompressed_buf[0], decompressed_len, &send_message->m_payload.m_buf[0], mk_lang_countof(send_message->m_payload.m_buf), &send_message->m_payload.m_len); mk_lang_check_rereturn(err);

	/*err = mk_lib_iip_random_generate_u32_non_zero(&u32); mk_lang_check_rereturn(err);*/
	mk_lib_iip_cp_types_nonce_from_base(&send_message->m_nonce, random_uint);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_log_ack_all(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint32_pct const seq_num_to_ack) mk_lang_noexcept
{
	#define mk_lib_iip_cp_client_socket_task_prrw_log_ack_all_fmt "ACKing packets,seqence numer %u."

	mk_lib_iip_logger_pt logger;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t str_buf[64];
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(seq_num_to_ack);

	logger = &task->m_socket.m_settings.m_shared->m_logger;
	len = mk_lib_fmt_n_snnprintf(&str_buf[0], mk_lang_countof(str_buf), &mk_lib_iip_cp_client_socket_task_prrw_log_ack_all_fmt[0], mk_lang_countstr(mk_lib_iip_cp_client_socket_task_prrw_log_ack_all_fmt), seq_num_to_ack); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(str_buf));
	err = mk_lib_iip_logger_rw_begin_line(logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_append_current_time(logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print(logger, &str_buf[0], len); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_line(logger); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_ack_all(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint8_pct const additional_data_buf, mk_lang_types_sint_t const additional_data_len, mk_sl_cui_uint32_pct const random_uint, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_client_socket_packet_with_payload_ppt last_packet_ptr;
	mk_lib_iip_cp_client_socket_packet_with_payload_pt last_packet_obj;
	mk_sl_cui_uint32_t seq_num_to_ack;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_send_message_pt send_message;
	mk_lib_iip_net_streaming_packet_t packet;
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint8_t decompressed_buf[4 * 1024];
	mk_lang_types_sint_t decompressed_len;

	mk_lang_assert(task);
	mk_lang_assert(additional_data_buf || additional_data_len == 0);
	mk_lang_assert(additional_data_len >= 0);
	mk_lang_assert(random_uint);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_socket.m_settings.m_session_id);
	mk_lang_assert(!mk_lib_iip_cp_types_sessionid_is_zero(task->m_socket.m_settings.m_session_id));
	mk_lang_assert(!mk_lib_iip_cp_types_sessionid_is_max(task->m_socket.m_settings.m_session_id));
	mk_lang_assert(task->m_socket.m_settings.m_remote_destination.m_certificate.m_cert_type != mk_lib_iip_cp_destination_cert_type_e_dummy_end);
	mk_lang_assert(!mk_sl_cui_uint32_is_zero(&task->m_socket.m_state.m_local_stream_id));
	mk_lang_assert(!mk_sl_cui_uint32_is_max(&task->m_socket.m_state.m_local_stream_id));
	mk_lang_assert(!mk_sl_cui_uint32_is_zero(&task->m_socket.m_state.m_remote_stream_id));
	mk_lang_assert(!mk_lib_iip_cp_client_socket_packets_with_payload_rw_is_empty(&task->m_socket.m_state.m_packets_in_to_ack));

	last_packet_ptr = mk_lib_iip_cp_client_socket_packets_with_payload_rw_get_back(&task->m_socket.m_state.m_packets_in_to_ack); mk_lang_assert(last_packet_ptr); last_packet_obj = *last_packet_ptr; mk_lang_assert(last_packet_obj);
	seq_num_to_ack = last_packet_obj->m_packet.m_sequence_number;

	err = mk_lib_iip_cp_client_socket_task_prrw_log_ack_all(task, &seq_num_to_ack); mk_lang_check_rereturn(err);

	err = mk_lib_iip_cp_message_reconstruct(msg, mk_lib_iip_cp_message_message_type_id_e_send_message); mk_lang_check_rereturn(err);
	send_message = &msg->m_mix.m_data.m_send_message;
	send_message->m_session_id = *task->m_socket.m_settings.m_session_id;
	send_message->m_remote_destination = task->m_socket.m_settings.m_remote_destination;

	err = mk_lib_iip_net_streaming_packet_rw_construct(&packet); mk_lang_check_rereturn(err);
	packet.m_send_stream_id = task->m_socket.m_state.m_remote_stream_id;
	packet.m_recv_stream_id = task->m_socket.m_state.m_local_stream_id;
	mk_sl_cui_uint32_set_zero(&task->m_socket.m_state.m_local_sequence_number);
	packet.m_ack_through = seq_num_to_ack;
	err = mk_lib_iip_net_streaming_packet_nacks_rw_construct_void(&packet.m_nacks); mk_lang_check_rereturn(err);
	packet.m_resend_delay = 0;
	packet.m_flags =
	((mk_lib_iip_net_streaming_packet_flag_t)(
		mk_lib_iip_net_streaming_packet_flag_e_none
	));
	packet.m_payload_buf = ((mk_sl_cui_uint8_pt)(additional_data_buf));
	packet.m_payload_len = additional_data_len;

	gud = mk_lang_true;
	err = mk_lib_iip_net_streaming_packet_ro_serialize(&packet, &decompressed_buf[0], mk_lang_countof(decompressed_buf), &gud, &decompressed_len); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(decompressed_len >= 1); mk_lang_assert(decompressed_len <= mk_lang_countof(decompressed_buf));
	err = mk_lib_iip_cp_client_socket_task_prrw_compress(task, &task->m_socket.m_state.m_local_port, &task->m_socket.m_settings.m_remote_port, &decompressed_buf[0], decompressed_len, &send_message->m_payload.m_buf[0], mk_lang_countof(send_message->m_payload.m_buf), &send_message->m_payload.m_len); mk_lang_check_rereturn(err);

	mk_lib_iip_cp_types_nonce_from_base(&send_message->m_nonce, random_uint);

	err = mk_lib_iip_cp_client_socket_packets_with_payload_rw_clear(&task->m_socket.m_state.m_packets_in_to_ack); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_drop(mk_lib_iip_cp_client_socket_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_client_socket_task_prrw_request_close(task); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_gimme_msg(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint32_pct const random_uint, mk_lib_iip_cp_message_ppt const msg) mk_lang_noexcept
{
	mk_lang_types_void_pt mem;
	mk_lib_iip_cp_client_socket_packet_pt pckt_obj;
	mk_lib_iip_cp_client_socket_packet_ppt pckt_ptr;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_send_message_pt send_message;
	mk_lib_iip_cp_message_pt my_msg;
	mk_sl_cui_uint32_t u32;
	mk_lib_iip_net_streaming_packet_t packet;
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint8_t decompressed_buf[4 * 1024];
	mk_lang_types_sint_t decompressed_len;
	/*mk_sl_cui_uint8_pt data_buf;*/
	/*mk_lang_types_usize_t data_len;*/
	mk_lang_types_sint_t signature_len;

	mk_lang_assert(task);
	mk_lang_assert(random_uint);
	mk_lang_assert(msg);

	if(task->m_socket.m_settings.m_is_listener && !task->m_socket.m_state.m_waiting_for_syn && !task->m_socket.m_state.m_our_syn_sent)
	{
		task->m_socket.m_state.m_our_syn_sent = mk_lang_true;
		err = mk_lib_iip_cp_message_reconstruct(&task->m_socket.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_send_message); mk_lang_check_rereturn(err);
		send_message = &task->m_socket.m_state.m_msg.m_mix.m_data.m_send_message;
		send_message->m_session_id = *task->m_socket.m_settings.m_session_id;
		send_message->m_remote_destination = task->m_socket.m_state.m_remote_destination;

		err = mk_lib_iip_net_streaming_packet_rw_construct(&packet); mk_lang_check_rereturn(err);
		packet.m_send_stream_id = task->m_socket.m_state.m_remote_stream_id;
		packet.m_recv_stream_id = task->m_socket.m_state.m_local_stream_id;
		packet.m_sequence_number = task->m_socket.m_state.m_local_sequence_number;
		mk_sl_cui_uint32_set_zero(&packet.m_ack_through);
		packet.m_nacks.m_size = 0;
		packet.m_resend_delay = 0;
		packet.m_flags =
			((mk_lib_iip_net_streaming_packet_flag_t)(
			mk_lib_iip_net_streaming_packet_flag_e_synchronize |
			mk_lib_iip_net_streaming_packet_flag_e_signature_included |
			mk_lib_iip_net_streaming_packet_flag_e_from_included |
			mk_lib_iip_net_streaming_packet_flag_e_no_ack |
			mk_lib_iip_net_streaming_packet_flag_e_none
			));
		packet.m_options.m_from = task->m_socket.m_settings.m_local_destination->m_remote_destination;
		/*char const reply[] =
			"HTTP/1.1 200 OK" "\x0d\x0a"
			"Content-Length: 3" "\x0d\x0a"
			"Content-Type: text/html; charset=utf-8" "\x0d\x0a"
			"" "\x0d\x0a"
			"gud";
		packet.m_payload_buf = ((mk_sl_cui_uint8_pt)(reply));
		packet.m_payload_len = mk_lang_countstr(reply);*/
		packet.m_payload_buf = mk_lang_null;
		packet.m_payload_len = 0;
		gud = mk_lang_true;
		err = mk_lib_iip_net_streaming_packet_ro_serialize(&packet, &decompressed_buf[0], mk_lang_countof(decompressed_buf), &gud, &decompressed_len); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(decompressed_len >= 1); mk_lang_assert(decompressed_len <= mk_lang_countof(decompressed_buf));
		err = mk_lib_iip_key_sgn_rw_sign_data(task->m_socket.m_settings.m_local_destination, &decompressed_buf[0], decompressed_len, packet.m_signature_buf, mk_lib_iip_key_sgn_dsa_sha1_signature_len_v, &signature_len); mk_lang_check_rereturn(err); mk_lang_check_return(signature_len == mk_lib_iip_key_sgn_dsa_sha1_signature_len_v); /* todo sgn len */
		err = mk_lib_iip_cp_client_socket_task_prrw_compress(task, &task->m_socket.m_state.m_local_port, &task->m_socket.m_state.m_remote_port, &decompressed_buf[0], decompressed_len, &send_message->m_payload.m_buf[0], mk_lang_countof(send_message->m_payload.m_buf), &send_message->m_payload.m_len); mk_lang_check_rereturn(err);

		err = mk_lib_iip_random_generate_u32_non_zero(&u32); mk_lang_check_rereturn(err);
		mk_lib_iip_cp_types_nonce_from_base(&send_message->m_nonce, &u32);
		*msg = &task->m_socket.m_state.m_msg;
	}
	/*else if(!mk_lib_iip_cp_client_socket_packets_with_payload_rw_is_empty(&task->m_socket.m_state.m_packets_in_to_ack))
	{
		*msg = mk_lang_null;
	}*/
	else if(task->m_socket.m_settings.m_is_listener && !task->m_socket.m_state.m_waiting_for_syn && task->m_socket.m_state.m_our_syn_sent && !mk_lib_iip_cp_dynamic_ring_u8_rw_is_empty(&task->m_socket.m_state.m_data_to_sent))
	{
#if 0
		err = mk_lib_iip_cp_message_reconstruct(&task->m_socket.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_send_message); mk_lang_check_rereturn(err);
		send_message = &task->m_socket.m_state.m_msg.m_mix.m_data.m_send_message;
		send_message->m_session_id = *task->m_socket.m_settings.m_session_id;
		send_message->m_remote_destination = task->m_socket.m_state.m_remote_destination;

		err = mk_lib_iip_net_streaming_packet_rw_construct(&packet); mk_lang_check_rereturn(err);
		packet.m_send_stream_id = task->m_socket.m_state.m_remote_stream_id;
		packet.m_recv_stream_id = task->m_socket.m_state.m_local_stream_id;
		packet.m_sequence_number = task->m_socket.m_state.m_local_sequence_number; /* todo increment? */
		mk_sl_cui_uint32_set_zero(&packet.m_ack_through);
		packet.m_nacks.m_size = 0;
		packet.m_resend_delay = 0;
		packet.m_flags =
			((mk_lib_iip_net_streaming_packet_flag_t)(
			mk_lib_iip_net_streaming_packet_flag_e_none
			));
		err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&task->m_socket.m_state.m_data_to_sent); mk_lang_check_rereturn(err);
		data_buf = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&task->m_socket.m_state.m_data_to_sent); mk_lang_assert(data_buf);
		data_len = mk_lib_iip_cp_dynamic_ring_u8_rw_get_size_a(&task->m_socket.m_state.m_data_to_sent); mk_lang_assert(data_len >= 1);
		packet.m_payload_buf = data_buf;
		packet.m_payload_len = ((mk_lang_types_sint_t)(data_len));
		gud = mk_lang_true;
		err = mk_lib_iip_net_streaming_packet_ro_serialize(&packet, &decompressed_buf[0], mk_lang_countof(decompressed_buf), &gud, &decompressed_len); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(decompressed_len >= 1); mk_lang_assert(decompressed_len <= mk_lang_countof(decompressed_buf));
		err = mk_lib_iip_cp_client_socket_task_prrw_compress(task, &task->m_socket.m_state.m_local_port, &task->m_socket.m_state.m_remote_port, &decompressed_buf[0], decompressed_len, &send_message->m_payload.m_buf[0], mk_lang_countof(send_message->m_payload.m_buf), &send_message->m_payload.m_len); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&task->m_socket.m_state.m_data_to_sent, data_len); mk_lang_check_rereturn(err);

		err = mk_lib_iip_random_generate_u32_non_zero(&u32); mk_lang_check_rereturn(err);
		mk_lib_iip_cp_types_nonce_from_base(&send_message->m_nonce, &u32);
		*msg = &task->m_socket.m_state.m_msg;
#endif
	}
	else if
	(
		(!task->m_socket.m_settings.m_is_listener) &&
		(!task->m_socket.m_state.m_our_syn_sent) &&
		(mk_lang_true)
	)
	{
		task->m_socket.m_state.m_our_syn_sent = mk_lang_true;
		err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*pckt_obj), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); pckt_obj = ((mk_lib_iip_cp_client_socket_packet_pt)(mem)); mk_lang_assert(pckt_obj);
		err = mk_lib_iip_cp_client_socket_packet_rw_construct(pckt_obj); mk_lang_check_rereturn(err);
		my_msg = &pckt_obj->m_msg;
		err = mk_lib_iip_cp_client_socket_task_prrw_make_initial_connect_packet(task, mk_lang_null, 0, random_uint, my_msg); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_client_socket_packets_rw_push_back_move_single(&task->m_socket.m_state.m_packets_out_sent, &pckt_obj); mk_lang_check_rereturn(err);
		*msg = my_msg;
	}
	else if
	(
		(!task->m_socket.m_settings.m_is_listener) &&
		(task->m_socket.m_state.m_our_syn_sent) &&
		(!mk_lib_iip_cp_client_socket_packets_rw_is_empty(&task->m_socket.m_state.m_packets_out_ready)) &&
		(mk_lang_true)
	)
	{
		pckt_ptr = mk_lib_iip_cp_client_socket_packets_rw_get_front(&task->m_socket.m_state.m_packets_out_ready); mk_lang_assert(pckt_ptr); pckt_obj = *pckt_ptr; mk_lang_assert(pckt_obj);
		*msg = &pckt_obj->m_msg;
		err = mk_lib_iip_cp_client_socket_packets_rw_push_back_move_single(&task->m_socket.m_state.m_packets_out_sent, &pckt_obj); mk_lang_check_rereturn(err);
	}
	else if
	(
		(!task->m_socket.m_settings.m_is_listener) &&
		(!mk_lib_iip_cp_client_socket_packets_with_payload_rw_is_empty(&task->m_socket.m_state.m_packets_in_to_ack)) &&
		(mk_lang_true)
	)
	{
		task->m_socket.m_state.m_our_syn_sent = mk_lang_true;
		err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*pckt_obj), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); pckt_obj = ((mk_lib_iip_cp_client_socket_packet_pt)(mem)); mk_lang_assert(pckt_obj);
		err = mk_lib_iip_cp_client_socket_packet_rw_construct(pckt_obj); mk_lang_check_rereturn(err);
		my_msg = &pckt_obj->m_msg;
		err = mk_lib_iip_cp_client_socket_task_prrw_ack_all(task, mk_lang_null, 0, random_uint, my_msg); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_client_socket_packets_rw_push_back_move_single(&task->m_socket.m_state.m_packets_out_sent, &pckt_obj); mk_lang_check_rereturn(err);
		*msg = my_msg;
	}
	else
	{
		*msg = mk_lang_null;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_step_idle_ack(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_client_socket_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_socket_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_socket_task_step_e_idle);

	if(!mk_lib_iip_cp_client_socket_packets_with_payload_rw_is_empty(&task->m_socket.m_state.m_packets_in_to_ack))
	{
		*step_result = mk_lib_iip_cp_client_socket_task_result_e_want_send;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_socket_task_result_e_idling;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_step_idle_last(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_client_socket_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_socket_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_socket_task_step_e_idle);

	if
	(
		(!task->m_socket.m_settings.m_is_listener && !task->m_socket.m_state.m_our_syn_sent) ||
		(!task->m_socket.m_settings.m_is_listener && task->m_socket.m_state.m_our_syn_sent && !mk_lib_iip_cp_client_socket_packets_rw_is_empty(&task->m_socket.m_state.m_packets_out_ready)) ||
		(mk_lang_false)
	)
	{
		*step_result = mk_lib_iip_cp_client_socket_task_result_e_want_send;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_socket_task_result_e_idling;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_step_idle(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_client_socket_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_socket_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_socket_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_socket_task_step_e_idle);

	stp_res = mk_lib_iip_cp_client_socket_task_result_e_idling;
	if(stp_res == mk_lib_iip_cp_client_socket_task_result_e_idling){ stp_res = mk_lib_iip_cp_client_socket_task_result_e_dummy_end; err = mk_lib_iip_cp_client_socket_task_prrw_step_idle_ack (task, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_socket_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_socket_task_result_e_idling){ stp_res = mk_lib_iip_cp_client_socket_task_result_e_dummy_end; err = mk_lib_iip_cp_client_socket_task_prrw_step_idle_last(task, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_socket_task_result_e_dummy_end); }
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_prrw_step(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_client_socket_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_socket_task_result_e_dummy_end);

	switch(task->m_step)
	{
		case mk_lib_iip_cp_client_socket_task_step_e_idle: err = mk_lib_iip_cp_client_socket_task_prrw_step_idle(task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_socket_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_socket_task_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_construct(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_client_socket_settings_pct const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_construct(task, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_destroy(mk_lib_iip_cp_client_socket_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_destroy(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_request_close(mk_lib_iip_cp_client_socket_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_request_close(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_want_die(mk_lib_iip_cp_client_socket_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_want_die(task, want);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_is_connected(mk_lib_iip_cp_client_socket_task_pt const task, mk_lang_types_bool_pt const is) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_is_connected(task, is);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_on_packet(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint16_pct const src_port, mk_sl_cui_uint16_pct const dst_port, mk_sl_cui_uint8_pt const decompressed_packet_buf, mk_lang_types_sint_t const decompressed_packet_len, mk_lib_iip_net_streaming_packet_pt const packet, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_on_packet(task, src_port, dst_port, decompressed_packet_buf, decompressed_packet_len, packet, consumed);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_on_msg_status_accepted(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_types_nonce_pct const nonce) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_on_msg_status_accepted(task, nonce);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_on_msg_status_guaranteed_success(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_types_nonce_pct const nonce) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_on_msg_status_guaranteed_success(task, nonce);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_on_msg_status_no_leaseset(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_types_nonce_pct const nonce) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_on_msg_status_no_leaseset(task, nonce);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_recv(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const recvd) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_recv(task, data_buf, data_len, recvd);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_send(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const sent) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_send(task, data_buf, data_len, sent);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_drop(mk_lib_iip_cp_client_socket_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_drop(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_gimme_msg(mk_lib_iip_cp_client_socket_task_pt const task, mk_sl_cui_uint32_pct const random_uint, mk_lib_iip_cp_message_ppt const msg) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_gimme_msg(task, random_uint, msg);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_rw_step(mk_lib_iip_cp_client_socket_task_pt const task, mk_lib_iip_cp_client_socket_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_socket_task_prrw_step(task, step_result);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_ptr_rw_construct_void(mk_lib_iip_cp_client_socket_task_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_ptr_rw_destroy(mk_lib_iip_cp_client_socket_task_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_cp_client_socket_task_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_cp_client_socket_task_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_ptr_rw_construct_copy(mk_lib_iip_cp_client_socket_task_ppt const dst, mk_lib_iip_cp_client_socket_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_ptr_rw_construct_move(mk_lib_iip_cp_client_socket_task_ppt const dst, mk_lib_iip_cp_client_socket_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_ptr_rw_assign_copy(mk_lib_iip_cp_client_socket_task_ppt const dst, mk_lib_iip_cp_client_socket_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_socket_task_ptr_rw_assign_move(mk_lib_iip_cp_client_socket_task_ppt const dst, mk_lib_iip_cp_client_socket_task_ppt const src) mk_lang_noexcept
{
	mk_lib_iip_cp_client_socket_task_pt tmp;

	mk_lang_assert(dst);
	mk_lang_assert(src);

	tmp = *dst;
	*dst = *src;
	*src = tmp;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_client_socket_task_ptr_ro_eq(mk_lib_iip_cp_client_socket_task_pcpt const a, mk_lib_iip_cp_client_socket_task_pcpt const b) mk_lang_noexcept
{
	mk_lang_types_bool_t eq;

	mk_lang_assert(a);
	mk_lang_assert(b);

	eq = *a == *b;
	return eq;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_socket_tasks
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_socket_task_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_socket_task_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_socket_task_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_socket_task_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_socket_task_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_socket_task_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_socket_task_ptr_rw_assign_move
#define mk_sl_vector_t_element_eq mk_lib_iip_cp_client_socket_task_ptr_ro_eq
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
