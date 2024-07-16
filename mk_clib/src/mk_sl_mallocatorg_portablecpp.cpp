#include "mk_sl_mallocatorg_portablecpp.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_mutex.h"
#include "mk_lib_mt_unique_lock.h"
#include "mk_sl_uint128.h"

#include <cstdlib> /* std::malloc std::free std::realloc */


#if mk_sl_mallocatorg_portablecpp_statistics_have
static mk_lib_mt_mutex_t g_mk_sl_mallocatorg_portablecpp_mtx;
static mk_sl_cui_uint128_t g_mk_sl_mallocatorg_portablecpp_statistics_bytes_allocated;
static mk_sl_cui_uint128_t g_mk_sl_mallocatorg_portablecpp_statistics_bytes_deallocated;
static mk_sl_cui_uint128_t g_mk_sl_mallocatorg_portablecpp_statistics_bytes_peak;
static mk_sl_cui_uint128_t g_mk_sl_mallocatorg_portablecpp_statistics_blocks_allocated;
static mk_sl_cui_uint128_t g_mk_sl_mallocatorg_portablecpp_statistics_blocks_deallocated;
static mk_sl_cui_uint128_t g_mk_sl_mallocatorg_portablecpp_statistics_blocks_peak;
#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_init(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_lang_types_sint_t err;

	err = mk_lib_mt_mutex_construct(&g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
	mk_sl_cui_uint128_set_zero(&g_mk_sl_mallocatorg_portablecpp_statistics_bytes_allocated);
	mk_sl_cui_uint128_set_zero(&g_mk_sl_mallocatorg_portablecpp_statistics_bytes_deallocated);
	mk_sl_cui_uint128_set_zero(&g_mk_sl_mallocatorg_portablecpp_statistics_bytes_peak);
	mk_sl_cui_uint128_set_zero(&g_mk_sl_mallocatorg_portablecpp_statistics_blocks_allocated);
	mk_sl_cui_uint128_set_zero(&g_mk_sl_mallocatorg_portablecpp_statistics_blocks_deallocated);
	mk_sl_cui_uint128_set_zero(&g_mk_sl_mallocatorg_portablecpp_statistics_blocks_peak);
#endif
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_lang_types_sint_t err;
	mk_sl_cui_uint128_t c;

	mk_sl_cui_uint128_sub3_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_bytes_allocated, &g_mk_sl_mallocatorg_portablecpp_statistics_bytes_deallocated, &c); mk_lang_check_return(mk_sl_cui_uint128_is_zero(&c));
	mk_sl_cui_uint128_sub3_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_blocks_allocated, &g_mk_sl_mallocatorg_portablecpp_statistics_blocks_deallocated, &c); mk_lang_check_return(mk_sl_cui_uint128_is_zero(&c));
	err = mk_lib_mt_mutex_destruct(&g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
#endif
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_on_allocated(mk_lang_types_usize_t const size) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_sl_cui_uint128_t c;
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;

	mk_lang_assert(size >= 0);

	if(size != 0)
	{
		mk_sl_cui_uint128_from_bi_usize(&c, &size);
		err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
		mk_sl_cui_uint128_add2_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_bytes_allocated, &c);
		mk_sl_cui_uint128_sub3_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_bytes_allocated, &g_mk_sl_mallocatorg_portablecpp_statistics_bytes_deallocated, &c);
		if(mk_sl_cui_uint128_gt(&c, &g_mk_sl_mallocatorg_portablecpp_statistics_bytes_peak))
		{
			g_mk_sl_mallocatorg_portablecpp_statistics_bytes_peak = c;
		}
		mk_sl_cui_uint128_inc1(&g_mk_sl_mallocatorg_portablecpp_statistics_blocks_allocated);
		mk_sl_cui_uint128_sub3_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_blocks_allocated, &g_mk_sl_mallocatorg_portablecpp_statistics_blocks_deallocated, &c);
		if(mk_sl_cui_uint128_gt(&c, &g_mk_sl_mallocatorg_portablecpp_statistics_blocks_peak))
		{
			g_mk_sl_mallocatorg_portablecpp_statistics_blocks_peak = c;
		}
		err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	}
	return 0;
#else
	mk_lang_assert(size >= 0);
	((mk_lang_types_void_t)(size));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_on_deallocated(mk_lang_types_usize_t const size) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_sl_cui_uint128_t c;
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;

	mk_lang_assert(size >= 0);

	if(size != 0)
	{
		mk_sl_cui_uint128_from_bi_usize(&c, &size);
		err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
		mk_sl_cui_uint128_add2_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_bytes_deallocated, &c);
		mk_sl_cui_uint128_inc1(&g_mk_sl_mallocatorg_portablecpp_statistics_blocks_deallocated);
		err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	}
	return 0;
#else
	mk_lang_assert(size >= 0);
	((mk_lang_types_void_t)(size));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_on_reallocated(mk_lang_types_usize_t const old_size, mk_lang_types_usize_t const new_size) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_sl_cui_uint128_t c;
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;

	mk_lang_assert(old_size >= 0);
	mk_lang_assert(new_size >= 0);

	err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
	if(new_size != 0)
	{
		mk_sl_cui_uint128_from_bi_usize(&c, &new_size);
		mk_sl_cui_uint128_add2_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_bytes_allocated, &c);
		mk_sl_cui_uint128_sub3_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_bytes_allocated, &g_mk_sl_mallocatorg_portablecpp_statistics_bytes_deallocated, &c);
		if(mk_sl_cui_uint128_gt(&c, &g_mk_sl_mallocatorg_portablecpp_statistics_bytes_peak))
		{
			g_mk_sl_mallocatorg_portablecpp_statistics_bytes_peak = c;
		}
		mk_sl_cui_uint128_inc1(&g_mk_sl_mallocatorg_portablecpp_statistics_blocks_allocated);
		mk_sl_cui_uint128_sub3_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_blocks_allocated, &g_mk_sl_mallocatorg_portablecpp_statistics_blocks_deallocated, &c);
		if(mk_sl_cui_uint128_gt(&c, &g_mk_sl_mallocatorg_portablecpp_statistics_blocks_peak))
		{
			g_mk_sl_mallocatorg_portablecpp_statistics_blocks_peak = c;
		}
	}
	if(old_size != 0)
	{
		mk_sl_cui_uint128_from_bi_usize(&c, &old_size);
		mk_sl_cui_uint128_add2_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_bytes_deallocated, &c);
		mk_sl_cui_uint128_inc1(&g_mk_sl_mallocatorg_portablecpp_statistics_blocks_deallocated);
	}
	err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(old_size >= 0);
	mk_lang_assert(new_size >= 0);
	((mk_lang_types_void_t)(old_size));
	((mk_lang_types_void_t)(new_size));
	return 0;
#endif
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_mallocatorg_portablecpp_statistics_init(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_mallocatorg_portablecpp_statistics_deinit(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_allocate(mk_lang_types_usize_t const size, mk_lang_types_void_ppt const mem) mk_lang_noexcept
{
	mk_lang_types_void_pt m;
	mk_lang_types_sint_t err;

	mk_lang_assert(size >= 0);
	mk_lang_assert(mem);

	m = std::malloc(size); mk_lang_check_return(m);
	err = mk_sl_mallocatorg_portablecpp_statistics_on_allocated(size); mk_lang_check_rereturn(err);
	*mem = m;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_deallocate(mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(mem || size == 0);
	mk_lang_assert(size >= 0);

	std::free(((mk_lang_types_void_pt)(mem)));
	err = mk_sl_mallocatorg_portablecpp_statistics_on_deallocated(size); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_reallocate(mk_lang_types_void_pct const old_mem, mk_lang_types_usize_t const old_size, mk_lang_types_usize_t const new_size, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept
{
	mk_lang_types_void_pt m;
	mk_lang_types_sint_t err;

	mk_lang_assert(old_mem || old_size == 0);
	mk_lang_assert(old_size >= 0);
	mk_lang_assert(new_size >= 0);
	mk_lang_assert(new_mem);

	m = std::realloc(((mk_lang_types_void_pt)(old_mem)), new_size); mk_lang_check_return(m);
	err = mk_sl_mallocatorg_portablecpp_statistics_on_reallocated(old_size, new_size); mk_lang_check_rereturn(err);
	*new_mem = m;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_get_bytes_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;
	mk_sl_cui_uint128_t c;

	mk_lang_assert(cnt);

	err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
	c = g_mk_sl_mallocatorg_portablecpp_statistics_bytes_allocated;
	err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	*cnt = c;
	return 0;
#else
	mk_lang_assert(cnt);
	((mk_lang_types_void_t)(cnt));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_get_bytes_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;
	mk_sl_cui_uint128_t c;

	mk_lang_assert(cnt);

	err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
	c = g_mk_sl_mallocatorg_portablecpp_statistics_bytes_deallocated;
	err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	*cnt = c;
	return 0;
#else
	mk_lang_assert(cnt);
	((mk_lang_types_void_t)(cnt));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_get_bytes_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;
	mk_sl_cui_uint128_t c;

	mk_lang_assert(cnt);

	err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
	mk_sl_cui_uint128_sub3_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_bytes_allocated, &g_mk_sl_mallocatorg_portablecpp_statistics_bytes_deallocated, &c);
	err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	*cnt = c;
	return 0;
#else
	mk_lang_assert(cnt);
	((mk_lang_types_void_t)(cnt));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_get_bytes_peak(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;
	mk_sl_cui_uint128_t c;

	mk_lang_assert(cnt);

	err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
	c = g_mk_sl_mallocatorg_portablecpp_statistics_bytes_peak;
	err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	*cnt = c;
	return 0;
#else
	mk_lang_assert(cnt);
	((mk_lang_types_void_t)(cnt));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_get_blocks_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;
	mk_sl_cui_uint128_t c;

	mk_lang_assert(cnt);

	err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
	c = g_mk_sl_mallocatorg_portablecpp_statistics_blocks_allocated;
	err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	*cnt = c;
	return 0;
#else
	mk_lang_assert(cnt);
	((mk_lang_types_void_t)(cnt));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_get_blocks_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;
	mk_sl_cui_uint128_t c;

	mk_lang_assert(cnt);

	err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
	c = g_mk_sl_mallocatorg_portablecpp_statistics_blocks_deallocated;
	err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	*cnt = c;
	return 0;
#else
	mk_lang_assert(cnt);
	((mk_lang_types_void_t)(cnt));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_get_blocks_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;
	mk_sl_cui_uint128_t c;

	mk_lang_assert(cnt);

	err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
	mk_sl_cui_uint128_sub3_wrap_cid_cod(&g_mk_sl_mallocatorg_portablecpp_statistics_blocks_allocated, &g_mk_sl_mallocatorg_portablecpp_statistics_blocks_deallocated, &c);
	err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	*cnt = c;
	return 0;
#else
	mk_lang_assert(cnt);
	((mk_lang_types_void_t)(cnt));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_portablecpp_statistics_get_blocks_peak(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
#if mk_sl_mallocatorg_portablecpp_statistics_have
	mk_lang_types_sint_t err;
	mk_lib_mt_unique_lock_exclusive_t ul;
	mk_sl_cui_uint128_t c;

	mk_lang_assert(cnt);

	err = mk_lib_mt_unique_lock_exclusive_construct(&ul, &g_mk_sl_mallocatorg_portablecpp_mtx); mk_lang_check_rereturn(err);
	c = g_mk_sl_mallocatorg_portablecpp_statistics_blocks_peak;
	err = mk_lib_mt_unique_lock_exclusive_destruct(&ul); mk_lang_check_rereturn(err);
	*cnt = c;
	return 0;
#else
	mk_lang_assert(cnt);
	((mk_lang_types_void_t)(cnt));
	return 0;
#endif
}
