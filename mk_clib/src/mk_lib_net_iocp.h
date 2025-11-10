#ifndef mk_include_guard_mk_lib_net_iocp_h
#define mk_include_guard_mk_lib_net_iocp_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_win_dll_kernel_iocp.h"


mk_lang_forward(mk_lib_net_socket);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_iocp_iop_s
{
	mk_lang_types_bool_t m_dequeued;
	mk_lang_types_bool_t m_successful_io_operation;
	mk_lang_types_sint_t m_bytes_transferred;
	mk_lang_types_uint_t m_fail_reason;
	mk_lang_types_uintptr_t m_key;
	mk_lang_types_void_pt m_overlapped;
};
typedef struct mk_lib_net_iocp_iop_s mk_lib_net_iocp_iop_t;
mk_lang_typedef(mk_lib_net_iocp_iop);
#include "mk_lang_warning_msvc_pop.h"


struct mk_lib_net_iocp_s
{
	mk_win_dll_kernel_iocp_t m_handle;
};
typedef struct mk_lib_net_iocp_s mk_lib_net_iocp_t;
mk_lang_typedef(mk_lib_net_iocp);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_construct_void(mk_lib_net_iocp_pt const iocp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_construct(mk_lib_net_iocp_pt const iocp, mk_lang_types_sint_t const concurrency) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_reconstruct(mk_lib_net_iocp_pt const iocp, mk_lang_types_sint_t const concurrency) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_destroy(mk_lib_net_iocp_pt const iocp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_associate_with_socket(mk_lib_net_iocp_pt const iocp, mk_lang_types_uintptr_t const key, mk_lib_net_socket_pt const socket) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_dequeue_packet_infinite(mk_lib_net_iocp_pt const iocp, mk_lang_types_bool_pt const dequeued, mk_lang_types_bool_pt const successful_io_operation, mk_lang_types_sint_pt const bytes_transferred, mk_lang_types_uintptr_pt const key, mk_lang_types_void_ppt const overlapped, mk_lang_types_uint_pt const fail_reason) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_dequeue_packet_tm(mk_lib_net_iocp_pt const iocp, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const is_ready, mk_lang_types_bool_pt const dequeued, mk_lang_types_bool_pt const successful_io_operation, mk_lang_types_sint_pt const bytes_transferred, mk_lang_types_uintptr_pt const key, mk_lang_types_void_ppt const overlapped, mk_lang_types_uint_pt const fail_reason) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_post(mk_lib_net_iocp_pt const iocp, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_uintptr_t const key, mk_lang_types_void_pt const overlapped) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net_iocp.c"
#endif
#endif
