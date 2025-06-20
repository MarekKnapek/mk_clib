#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


#include "mk_sl_mallocator_global_forwarder_inl_defd.h"


#define mk_sl_cui_t_name mk_sl_mallocator_global_forwarder_inl_defd_blocks
#define mk_sl_cui_t_base mk_sl_mallocator_global_forwarder_inl_defd_base_blocks
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_mallocator_global_forwarder_inl_defd_bytes
#define mk_sl_cui_t_base mk_sl_mallocator_global_forwarder_inl_defd_base_bytes
#define mk_sl_cui_t_count 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#if defined mk_sl_mallocator_global_forwarder_inl_defd_statistics_want
#if (mk_sl_mallocator_global_forwarder_inl_defd_statistics_want) == 0
#define mk_sl_mallocator_global_forwarder_inl_defd_statistics_have 0
#elif (mk_sl_mallocator_global_forwarder_inl_defd_statistics_want) == 1
#define mk_sl_mallocator_global_forwarder_inl_defd_statistics_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_sl_mallocator_global_forwarder_inl_defd_statistics_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_sl_mallocator_global_forwarder_inl_defd_statistics_have 0
#else
#define mk_sl_mallocator_global_forwarder_inl_defd_statistics_have 1
#endif
#endif
#endif


struct mk_sl_mallocator_global_forwarder_inl_defd_statistics_s
{
	mk_sl_mallocator_global_forwarder_inl_defd_blocks_t m_blocks_allocated;
	mk_sl_mallocator_global_forwarder_inl_defd_blocks_t m_blocks_deallocated;
	mk_sl_mallocator_global_forwarder_inl_defd_blocks_t m_blocks_peak;
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_t m_bytes_allocated;
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_t m_bytes_deallocated;
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_t m_bytes_peak;
};
typedef struct mk_sl_mallocator_global_forwarder_inl_defd_statistics_s mk_sl_mallocator_global_forwarder_inl_defd_statistics_t;
mk_lang_typedef(mk_sl_mallocator_global_forwarder_inl_defd_statistics);


#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
static mk_sl_mallocator_global_forwarder_inl_defd_statistics_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_g;
#endif


static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_init(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_sl_mallocator_global_forwarder_inl_defd_blocks_set_zero(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_allocated);
	mk_sl_mallocator_global_forwarder_inl_defd_blocks_set_zero(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_deallocated);
	mk_sl_mallocator_global_forwarder_inl_defd_blocks_set_zero(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_peak);
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_set_zero(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_allocated);
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_set_zero(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_deallocated);
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_set_zero(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_peak);
#else
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_sl_mallocator_global_forwarder_inl_defd_blocks_t blocks_live;
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_t bytes_live;

	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_blocks_live(&blocks_live);
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_bytes_live(&bytes_live);
	mk_lang_assert(mk_sl_mallocator_global_forwarder_inl_defd_blocks_is_zero(&blocks_live));
	mk_lang_assert(mk_sl_mallocator_global_forwarder_inl_defd_bytes_is_zero(&bytes_live));
#else
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_update_peak(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_sl_mallocator_global_forwarder_inl_defd_blocks_t blocks_live;
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_t bytes_live;

	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_blocks_live(&blocks_live);
	if(mk_sl_mallocator_global_forwarder_inl_defd_blocks_gt(&blocks_live, &mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_peak))
	{
		mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_peak = blocks_live;
	}
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_bytes_live(&bytes_live);
	if(mk_sl_mallocator_global_forwarder_inl_defd_bytes_gt(&bytes_live, &mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_peak))
	{
		mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_peak = bytes_live;
	}
#else
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_allocated(mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_t bytes;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_global_forwarder_inl_defd_blocks_inc1(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_allocated);
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_from_bi_usize(&bytes, &size_bytes);
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_add2_wrap_cid_cod(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_allocated, &bytes);
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_update_peak();
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(size_bytes));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_deallocated(mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_t bytes;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_mallocator_global_forwarder_inl_defd_blocks_inc1(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_deallocated);
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_from_bi_usize(&bytes, &size_bytes);
	mk_sl_mallocator_global_forwarder_inl_defd_bytes_add2_wrap_cid_cod(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_deallocated, &bytes);
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(size_bytes));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_reallocated(mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes) mk_lang_noexcept
{
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_allocated(new_size_bytes);
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_deallocated(old_size_bytes);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_global_forwarder_inl_defd_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_init();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_global_forwarder_inl_defd_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_deinit();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_global_forwarder_inl_defd_allocate(mk_lang_types_usize_t const size_bytes, mk_lang_types_void_ppt const mem) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt m;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(size_bytes >= 0);
	mk_lang_assert(mem || size_bytes == 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size_bytes != 0)
	{
		err = mk_sl_mallocator_global_forwarder_inl_defd_base_allocate(size_bytes, &m); mk_lang_check_rereturn(err);
		if(m)
		{
			mk_sl_mallocator_global_forwarder_inl_defd_statistics_allocated(size_bytes);
		}
		*mem = m;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_global_forwarder_inl_defd_deallocate(mk_lang_types_void_pt const mem, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(mem || size_bytes == 0);
	mk_lang_assert(size_bytes >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(size_bytes != 0)
	{
		err = mk_sl_mallocator_global_forwarder_inl_defd_base_deallocate(mem, size_bytes); mk_lang_check_rereturn(err);
		mk_sl_mallocator_global_forwarder_inl_defd_statistics_deallocated(size_bytes);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocator_global_forwarder_inl_defd_reallocate(mk_lang_types_void_pt const old_mem, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt m;

	mk_lang_assert(old_mem);
	mk_lang_assert(old_size_bytes >= 1);
	mk_lang_assert(new_size_bytes >= 1);
	mk_lang_assert(new_mem);

	err = mk_sl_mallocator_global_forwarder_inl_defd_base_reallocate(old_mem, old_size_bytes, new_size_bytes, &m); mk_lang_check_rereturn(err);
	if(m)
	{
		mk_sl_mallocator_global_forwarder_inl_defd_statistics_reallocated(old_size_bytes, new_size_bytes);
	}
	*new_mem = m;
	return 0;
}


mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_blocks_allocated(mk_sl_mallocator_global_forwarder_inl_defd_blocks_pt const blocks_allocated) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_lang_assert(blocks_allocated);

	*blocks_allocated = mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_allocated;
#else
	mk_lang_assert(blocks_allocated);
	((mk_lang_types_void_t)(blocks_allocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_blocks_dealocated(mk_sl_mallocator_global_forwarder_inl_defd_blocks_pt const blocks_deallocated) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_lang_assert(blocks_deallocated);

	*blocks_deallocated = mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_deallocated;
#else
	mk_lang_assert(blocks_deallocated);
	((mk_lang_types_void_t)(blocks_deallocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_blocks_peak(mk_sl_mallocator_global_forwarder_inl_defd_blocks_pt const blocks_peak) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_lang_assert(blocks_peak);

	*blocks_peak = mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_peak;
#else
	mk_lang_assert(blocks_peak);
	((mk_lang_types_void_t)(blocks_peak));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_blocks_live(mk_sl_mallocator_global_forwarder_inl_defd_blocks_pt const blocks_live) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_lang_assert(blocks_live);

	mk_sl_mallocator_global_forwarder_inl_defd_blocks_sub3_wrap_cid_cod(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_allocated, &mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_blocks_deallocated, blocks_live);
#else
	mk_lang_assert(blocks_live);
	((mk_lang_types_void_t)(blocks_live));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_bytes_allocated(mk_sl_mallocator_global_forwarder_inl_defd_bytes_pt const bytes_allocated) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_lang_assert(bytes_allocated);

	*bytes_allocated = mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_allocated;
#else
	mk_lang_assert(bytes_allocated);
	((mk_lang_types_void_t)(bytes_allocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_bytes_dealocated(mk_sl_mallocator_global_forwarder_inl_defd_bytes_pt const bytes_deallocated) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_lang_assert(bytes_deallocated);

	*bytes_deallocated = mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_deallocated;
#else
	mk_lang_assert(bytes_deallocated);
	((mk_lang_types_void_t)(bytes_deallocated));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_bytes_peak(mk_sl_mallocator_global_forwarder_inl_defd_bytes_pt const bytes_peak) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_lang_assert(bytes_peak);

	*bytes_peak = mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_peak;
#else
	mk_lang_assert(bytes_peak);
	((mk_lang_types_void_t)(bytes_peak));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_bytes_live(mk_sl_mallocator_global_forwarder_inl_defd_bytes_pt const bytes_live) mk_lang_noexcept
{
#if mk_sl_mallocator_global_forwarder_inl_defd_statistics_have
	mk_lang_assert(bytes_live);

	mk_sl_mallocator_global_forwarder_inl_defd_bytes_sub3_wrap_cid_cod(&mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_allocated, &mk_sl_mallocator_global_forwarder_inl_defd_statistics_g.m_bytes_deallocated, bytes_live);
#else
	mk_lang_assert(bytes_live);
	((mk_lang_types_void_t)(bytes_live));
#endif
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_all(mk_lang_static_param(mk_sl_mallocator_global_forwarder_inl_defd_blocks_t, blocks_all, 4), mk_lang_static_param(mk_sl_mallocator_global_forwarder_inl_defd_bytes_t, bytes_all, 4)) mk_lang_noexcept
{
	mk_lang_assert(blocks_all);
	mk_lang_assert(bytes_all);

	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_blocks_allocated(&blocks_all[0]);
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_blocks_dealocated(&blocks_all[1]);
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_blocks_peak(&blocks_all[2]);
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_blocks_live(&blocks_all[3]);
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_bytes_allocated(&bytes_all[0]);
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_bytes_dealocated(&bytes_all[1]);
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_bytes_peak(&bytes_all[2]);
	mk_sl_mallocator_global_forwarder_inl_defd_statistics_get_bytes_live(&bytes_all[3]);
}


#undef mk_sl_mallocator_global_forwarder_inl_defd_statistics_have


#include "mk_sl_mallocator_global_forwarder_inl_defu.h"
