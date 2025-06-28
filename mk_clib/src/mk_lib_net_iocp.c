#ifndef mk_include_guard_mk_lib_net_iocp_c
#define mk_include_guard_mk_lib_net_iocp_c
#include "mk_lib_net_iocp.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_net.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_handle.h"
#include "mk_win_dll_kernel_iocp.h"
#include "mk_win_dll_ws2.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_construct_void(mk_lib_net_iocp_pt const iocp) mk_lang_noexcept
{
	mk_lang_assert(iocp);

	iocp->m_handle = mk_win_dll_kernel_iocp_get_null();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_construct(mk_lib_net_iocp_pt const iocp, mk_lang_types_sint_t const concurrency) mk_lang_noexcept
{
	mk_win_dll_kernel_iocp_t handle;

	mk_lang_assert(iocp);
	mk_lang_assert(concurrency >= 0);

	handle = mk_win_dll_kernel_iocp_create(mk_win_base_handle_get_invalid(), mk_win_dll_kernel_iocp_get_null(), ((mk_win_base_uintptr_t)(0)), ((mk_win_base_dword_t)(concurrency))); mk_lang_check_return(!mk_win_dll_kernel_iocp_is_null(handle));
	iocp->m_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_reconstruct(mk_lib_net_iocp_pt const iocp, mk_lang_types_sint_t const concurrency) mk_lang_noexcept
{
	mk_win_dll_kernel_iocp_t handle;

	mk_lang_assert(iocp);
	mk_lang_assert(concurrency >= 0);

	if(mk_win_dll_kernel_iocp_is_null(iocp->m_handle))
	{
		handle = mk_win_dll_kernel_iocp_create(mk_win_base_handle_get_invalid(), mk_win_dll_kernel_iocp_get_null(), ((mk_win_base_uintptr_t)(0)), ((mk_win_base_dword_t)(concurrency))); mk_lang_check_return(!mk_win_dll_kernel_iocp_is_null(handle));
		iocp->m_handle = handle;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_destroy(mk_lib_net_iocp_pt const iocp) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(iocp);

	if(!mk_win_dll_kernel_iocp_is_null(iocp->m_handle))
	{
		b = mk_win_dll_kernel_handle_close(mk_win_base_handle_from(iocp->m_handle.m_data)); mk_lang_check_return(b != mk_win_base_false);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_associate_with_socket(mk_lib_net_iocp_pt const iocp, mk_lang_types_uintptr_t const key, mk_lib_net_socket_pt const socket) mk_lang_noexcept
{
	mk_win_dll_kernel_iocp_t handle;

	mk_lang_assert(iocp);
	mk_lang_assert(key || !key);
	mk_lang_assert(socket);
	mk_lang_assert(!mk_win_dll_kernel_iocp_is_null(iocp->m_handle));
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	handle = mk_win_dll_kernel_iocp_create(mk_win_base_handle_from(((mk_win_base_void_pt)(socket->m_handle.m_elements[0]))), iocp->m_handle, ((mk_win_base_uintptr_t)(key)), ((mk_win_base_dword_t)(0))); mk_lang_check_return(handle.m_data == iocp->m_handle.m_data);
	return 0;
}


#endif
