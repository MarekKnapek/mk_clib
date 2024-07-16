#include "mk_sl_mallocg_tracer.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_mutex.h"
#include "mk_lib_mt_unique_lock.h"
#include "mk_lib_stack_trace.h"
#include "mk_sl_mallocatorg.h"
#include "mk_sl_uint128.h"

#define mk_sl_tree_wavl_t_name mk_sl_mallocg_tracer_stack_traces
#define mk_sl_tree_wavl_t_element_type mk_lib_stack_trace_t
#define mk_sl_tree_wavl_t_elements_compare mk_lib_stack_trace_ro_cmp
#define mk_sl_tree_wavl_t_mallocatorg_name mk_sl_mallocatorg
#define mk_sl_tree_wavl_t_constexpr_want 0
#include "mk_sl_tree_wavl_inl_fileh.h"
#include "mk_sl_tree_wavl_inl_filec.h"


struct mk_sl_mallocg_tracer_alloc_s
{
	mk_lang_types_usize_t m_id;
	mk_lang_types_pchar_pct m_file_buf;
	mk_lang_types_sint_t m_file_len;
	mk_lang_types_sint_t m_line;
	mk_lang_types_pchar_pct m_func_buf;
	mk_lang_types_sint_t m_func_len;
	mk_lang_types_usize_t m_size;
	mk_lang_types_void_pt m_mem;
	#if mk_lib_stack_trace_has
	mk_sl_mallocg_tracer_stack_traces_node_pct m_stack_trace;
	#endif
};
typedef struct mk_sl_mallocg_tracer_alloc_s mk_sl_mallocg_tracer_alloc_t;
typedef mk_sl_mallocg_tracer_alloc_t const mk_sl_mallocg_tracer_alloc_ct;
typedef mk_sl_mallocg_tracer_alloc_t* mk_sl_mallocg_tracer_alloc_pt;
typedef mk_sl_mallocg_tracer_alloc_t const* mk_sl_mallocg_tracer_alloc_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_mallocg_tracer_alloc_ro_cmp(mk_sl_mallocg_tracer_alloc_pct const a, mk_sl_mallocg_tracer_alloc_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_types_void_pt mema;
	mk_lang_types_void_pt memb;
	mk_lang_types_uintptr_t vala;
	mk_lang_types_uintptr_t valb;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(cmp);

	mema = a->m_mem;
	memb = b->m_mem;
	vala = ((mk_lang_types_uintptr_t)(mema));
	valb = ((mk_lang_types_uintptr_t)(memb));
	if(vala < valb)
	{
		*cmp = -1;
	}
	else if(valb < vala)
	{
		*cmp = +1;
	}
	else
	{
		*cmp = 0;
	}
	return 0;
}

#define mk_sl_tree_wavl_t_name mk_sl_mallocg_tracer_allocs
#define mk_sl_tree_wavl_t_element_type mk_sl_mallocg_tracer_alloc_t
#define mk_sl_tree_wavl_t_elements_compare mk_sl_mallocg_tracer_alloc_ro_cmp
#define mk_sl_tree_wavl_t_mallocatorg_name mk_sl_mallocatorg
#define mk_sl_tree_wavl_t_constexpr_want 0
#include "mk_sl_tree_wavl_inl_fileh.h"
#include "mk_sl_tree_wavl_inl_filec.h"


struct mk_sl_mallocg_tracer_db_s
{
	mk_lib_mt_mutex_t m_mtx;
	mk_lang_types_usize_t m_counter;
	mk_sl_mallocg_tracer_allocs_t m_allocs;
	#if mk_lib_stack_trace_has
	mk_sl_mallocg_tracer_stack_traces_t m_stacks;
	#endif
};
typedef struct mk_sl_mallocg_tracer_db_s mk_sl_mallocg_tracer_db_t;
typedef mk_sl_mallocg_tracer_db_t const mk_sl_mallocg_tracer_db_ct;
typedef mk_sl_mallocg_tracer_db_t* mk_sl_mallocg_tracer_db_pt;
typedef mk_sl_mallocg_tracer_db_t const* mk_sl_mallocg_tracer_db_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_mallocg_tracer_db_rw_construct(mk_sl_mallocg_tracer_db_pt const db) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(db);

	err = mk_lib_mt_mutex_construct(&db->m_mtx); mk_lang_check_rereturn(err);
	db->m_counter = 0;
	err = mk_sl_mallocg_tracer_allocs_rw_construct(&db->m_allocs); mk_lang_check_rereturn(err);
	#if mk_lib_stack_trace_has
	err = mk_sl_mallocg_tracer_stack_traces_rw_construct(&db->m_stacks); mk_lang_check_rereturn(err);
	#endif
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_mallocg_tracer_db_rw_destroy(mk_sl_mallocg_tracer_db_pt const db) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(db);
	mk_lang_assert(db->m_allocs.m_cnt == 0);
	#if mk_lib_stack_trace_has
	mk_lang_assert(db->m_stacks.m_cnt == 0);
	#endif

	#if mk_lib_stack_trace_has
	err = mk_sl_mallocg_tracer_stack_traces_rw_destroy(&db->m_stacks); mk_lang_check_rereturn(err);
	#endif
	err = mk_sl_mallocg_tracer_allocs_rw_destroy(&db->m_allocs); mk_lang_check_rereturn(err);
	err = mk_lib_mt_mutex_destruct(&db->m_mtx); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_mallocg_tracer_db_rw_trace(mk_sl_mallocg_tracer_db_pt const db, mk_lang_types_pchar_pct const file_buf, mk_lang_types_sint_t const file_len, mk_lang_types_sint_t const line, mk_lang_types_pchar_pct const func_buf, mk_lang_types_sint_t const func_len, mk_lang_types_usize_t const size, mk_lang_types_void_pt const mem) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;
	mk_lib_stack_trace_t stack;
	mk_sl_mallocg_tracer_stack_traces_node_pct stack_node;
	mk_sl_mallocg_tracer_alloc_t alloc;
	mk_sl_mallocg_tracer_allocs_node_pct alloc_node;

	mk_lang_assert(db);
	mk_lang_assert(file_buf && file_buf[0] != '\0');
	mk_lang_assert(file_len >= 1);
	mk_lang_assert(line >= 1);
	mk_lang_assert(func_buf && func_buf[0] != '\0');
	mk_lang_assert(func_len >= 1);
	mk_lang_assert(size >= 0);
	mk_lang_assert(mem || size == 0);

	if(size >= 1 && mem)
	{
		err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &db->m_mtx); mk_lang_check_rereturn(err);
		++db->m_counter;
		#if mk_lib_stack_trace_has
		err = mk_lib_stack_trace_rw_construct_capture(&stack); mk_lang_check_rereturn(err);
		err = mk_sl_mallocg_tracer_stack_traces_rw_insert(&db->m_stacks, &stack, &stack_node); mk_lang_check_rereturn(err);
		#else
		((mk_lang_types_void_t)(stack));
		((mk_lang_types_void_t)(stack_node));
		#endif
		alloc.m_id = db->m_counter - 1;
		alloc.m_file_buf = file_buf;
		alloc.m_file_len = file_len;
		alloc.m_line = line;
		alloc.m_func_buf = func_buf;
		alloc.m_func_len = func_len;
		alloc.m_size = size;
		alloc.m_mem = mem;
		#if mk_lib_stack_trace_has
		alloc.m_stack_trace = stack_node;
		#endif
		err = mk_sl_mallocg_tracer_allocs_rw_insert(&db->m_allocs, &alloc, &alloc_node); mk_lang_check_rereturn(err);
		err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_mallocg_tracer_db_detrace(mk_sl_mallocg_tracer_db_pt const db, mk_lang_types_void_pt const mem, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;
	mk_sl_mallocg_tracer_alloc_t alloc_to_find;
	mk_sl_mallocg_tracer_alloc_pct alloc_found;
	mk_sl_mallocg_tracer_allocs_node_pct alloc_node;
	mk_sl_mallocg_tracer_stack_traces_node_pct stack_trace_node;

	mk_lang_assert(db);
	mk_lang_assert(mem || size == 0);
	mk_lang_assert(size >= 0);

	if(mem && size >= 1)
	{
		err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &db->m_mtx); mk_lang_check_rereturn(err);
		alloc_to_find.m_mem = mem;
		err = mk_sl_mallocg_tracer_allocs_rw_find(&db->m_allocs, &alloc_to_find, &alloc_node); mk_lang_check_rereturn(err); mk_lang_assert(alloc_node);
		err = mk_sl_mallocg_tracer_allocs_ro_node_get_element(alloc_node, &alloc_found); mk_lang_check_rereturn(err); mk_lang_assert(alloc_found);
		#if mk_lib_stack_trace_has
		stack_trace_node = alloc_found->m_stack_trace;
		#else
		((mk_lang_types_void_t)(stack_trace_node));
		#endif
		err = mk_sl_mallocg_tracer_allocs_rw_remove(&db->m_allocs, alloc_node); mk_lang_check_rereturn(err);
		#if mk_lib_stack_trace_has
		err = mk_sl_mallocg_tracer_stack_traces_rw_remove(&db->m_stacks, stack_trace_node); mk_lang_check_rereturn(err);
		#endif
		err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_sl_mallocg_tracer_db_t g_mk_sl_mallocg_tracer_db;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_mallocatorg_init(); mk_lang_check_rereturn(err);
	err = mk_sl_mallocg_tracer_db_rw_construct(&g_mk_sl_mallocg_tracer_db); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_mallocg_tracer_db_rw_destroy(&g_mk_sl_mallocg_tracer_db); mk_lang_check_rereturn(err);
	err = mk_sl_mallocatorg_deinit();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_allocate_impl(mk_lang_types_pchar_pct const file_buf, mk_lang_types_sint_t const file_len, mk_lang_types_sint_t const line, mk_lang_types_pchar_pct const func_buf, mk_lang_types_sint_t const func_len, mk_lang_types_usize_t const size, mk_lang_types_void_ppt const mem) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(mem);

	err = mk_sl_mallocatorg_allocate(size, mem); mk_lang_check_rereturn(err);
	err = mk_sl_mallocg_tracer_db_rw_trace(&g_mk_sl_mallocg_tracer_db, file_buf, file_len, line, func_buf, func_len, size, *mem); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_deallocate(mk_lang_types_void_pt const mem, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_mallocg_tracer_db_detrace(&g_mk_sl_mallocg_tracer_db, mem, size); mk_lang_check_rereturn(err);
	err = mk_sl_mallocatorg_deallocate(mem, size); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_reallocate_impl(mk_lang_types_pchar_pct const file_buf, mk_lang_types_sint_t const file_len, mk_lang_types_sint_t const line, mk_lang_types_pchar_pct const func_buf, mk_lang_types_sint_t const func_len, mk_lang_types_void_pt const old_mem, mk_lang_types_usize_t const old_size, mk_lang_types_usize_t const new_size, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(new_mem);

	err = mk_sl_mallocg_tracer_db_detrace(&g_mk_sl_mallocg_tracer_db, old_mem, old_size); mk_lang_check_rereturn(err);
	err = mk_sl_mallocatorg_reallocate(old_mem, old_size, new_size, new_mem); mk_lang_check_rereturn(err);
	err = mk_sl_mallocg_tracer_db_rw_trace(&g_mk_sl_mallocg_tracer_db, file_buf, file_len, line, func_buf, func_len, new_size, *new_mem); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_blocks_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_statistics_get_blocks_allocated(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_blocks_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_statistics_get_blocks_deallocated(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_blocks_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_statistics_get_blocks_live(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_bytes_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_statistics_get_bytes_allocated(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_bytes_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_statistics_get_bytes_deallocated(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocg_tracer_statistics_get_bytes_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_statistics_get_bytes_live(cnt);
	return ret;
}
