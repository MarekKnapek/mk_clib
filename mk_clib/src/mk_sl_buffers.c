#ifndef mk_include_guard_mk_sl_buffers_c
#define mk_include_guard_mk_sl_buffers_c
#include "mk_sl_buffers.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_configuration.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_vector.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_memory_management.h"


#define mk_sl_buffers_k_block_size_d (2ul * 1024ul * 1024ul)


#if mk_lang_configuration_is_debug
static mk_lang_types_sint_t mk_sl_buffers_g_debug;
#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_buffers_prrw_construct(mk_sl_buffers_pt const buffers) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(buffers);

	err = mk_sl_vector_vp_rw_construct(&buffers->m_blocks); mk_lang_check_rereturn(err);
	buffers->m_free_list = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_buffers_prrw_destroy(mk_sl_buffers_pt const buffers) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_void_ppt pelem;
	mk_lang_types_void_pt elem;
	mk_win_base_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(buffers);

	n = mk_sl_vector_vp_rw_size(&buffers->m_blocks);
	for(i = 0; i != n; ++i)
	{
		pelem = mk_sl_vector_vp_rw_at(&buffers->m_blocks, i); mk_lang_assert(pelem); elem = *pelem; mk_lang_assert(elem);
		b = mk_win_dll_kernel_memory_management_virtual_free(elem, 0, mk_win_dll_kernel_memory_management_k_dealloc_type_mem_release); mk_lang_check_return(b != mk_win_base_false);
		#if mk_lang_configuration_is_debug
		--mk_sl_buffers_g_debug;
		#endif
	}
	err = mk_sl_vector_vp_rw_destroy(&buffers->m_blocks); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_buffers_prrw_allocate_one(mk_sl_buffers_pt const buffers, mk_sl_buffers_buffer_ppt const buffer) mk_lang_noexcept
{
	mk_sl_buffers_buffer_pt old_free_item;
	mk_lang_types_sint_t err;
	mk_win_base_void_lpt mem;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_void_pt curr;
	mk_lang_types_void_pt next;
	mk_lang_types_void_ppt link;
	mk_lang_types_void_pt elem;

	mk_lang_static_assert(mk_sl_buffers_k_block_size_d / mk_sl_buffers_buffer_size_d >= 4);

	mk_lang_assert(buffers);
	mk_lang_assert(buffer);

	if(buffers->m_free_list)
	{
		old_free_item = buffers->m_free_list;
		buffers->m_free_list = *((mk_sl_buffers_buffer_ppt)(&old_free_item->m_data.m_uint8s[0]));
		*buffer = old_free_item;
	}
	else
	{
		err = mk_sl_vector_vp_rw_reserve_additional(&buffers->m_blocks, 1); mk_lang_check_rereturn(err);
		mem = mk_win_dll_kernel_memory_management_virtual_alloc(mk_win_base_null, mk_sl_buffers_k_block_size_d, mk_win_dll_kernel_memory_management_k_alloc_type_mem_reserve | mk_win_dll_kernel_memory_management_k_alloc_type_mem_commit, mk_win_dll_kernel_memory_management_k_protection_page_readwrite); mk_lang_check_return(mem);
		#if mk_lang_configuration_is_debug
		++mk_sl_buffers_g_debug;
		#endif
		n = mk_sl_buffers_k_block_size_d / mk_sl_buffers_buffer_size_d;
		for(i = 1; i != n - 1; ++i)
		{
			curr = ((mk_lang_types_void_pt)(((mk_lang_types_uchar_pt)(mem)) + (i + 0) * mk_sl_buffers_buffer_size_d));
			next = ((mk_lang_types_void_pt)(((mk_lang_types_uchar_pt)(mem)) + (i + 1) * mk_sl_buffers_buffer_size_d));
			link = ((mk_lang_types_void_ppt)(curr));
			*link = next;
		}
		curr = ((mk_lang_types_void_pt)(((mk_lang_types_uchar_pt)(mem)) + (i + 0) * mk_sl_buffers_buffer_size_d));
		next = mk_lang_null;
		link = ((mk_lang_types_void_ppt)(curr));
		*link = next;
		elem = mem;
		err = mk_sl_vector_vp_rw_push_back_copy_single(&buffers->m_blocks, &elem); mk_lang_check_rereturn(err);
		buffers->m_free_list = ((mk_sl_buffers_buffer_pt)(((mk_lang_types_uchar_pt)(mem)) + 1 * mk_sl_buffers_buffer_size_d));
		*buffer = ((mk_sl_buffers_buffer_pt)(((mk_lang_types_uchar_pt)(mem)) + 0 * mk_sl_buffers_buffer_size_d));
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_buffers_prrw_deallocate_one(mk_sl_buffers_pt const buffers, mk_sl_buffers_buffer_pt const buffer) mk_lang_noexcept
{
	mk_sl_buffers_buffer_pt old_free_item;
	mk_sl_buffers_buffer_ppt link;

	mk_lang_assert(buffers);
	mk_lang_assert(buffer);

	old_free_item = buffers->m_free_list;
	link = ((mk_sl_buffers_buffer_ppt)(&buffer->m_data.m_uint8s[0]));
	*link = old_free_item;
	buffers->m_free_list = buffer;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_buffers_rw_construct(mk_sl_buffers_pt const buffers) mk_lang_noexcept
{
	return mk_sl_buffers_prrw_construct(buffers);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_buffers_rw_destroy(mk_sl_buffers_pt const buffers) mk_lang_noexcept
{
	return mk_sl_buffers_prrw_destroy(buffers);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_buffers_rw_allocate_one(mk_sl_buffers_pt const buffers, mk_sl_buffers_buffer_ppt const buffer) mk_lang_noexcept
{
	return mk_sl_buffers_prrw_allocate_one(buffers, buffer);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_buffers_rw_deallocate_one(mk_sl_buffers_pt const buffers, mk_sl_buffers_buffer_pt const buffer) mk_lang_noexcept
{
	return mk_sl_buffers_prrw_deallocate_one(buffers, buffer);
}


#endif
