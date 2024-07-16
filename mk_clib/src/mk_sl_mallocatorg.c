#include "mk_sl_mallocatorg.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_sl_uint128.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows
#include "mk_sl_mallocatorg_windows.h"
#define mk_sl_mallocatorg_impl_init                              mk_sl_mallocatorg_windows_init
#define mk_sl_mallocatorg_impl_deinit                            mk_sl_mallocatorg_windows_deinit
#define mk_sl_mallocatorg_impl_allocate                          mk_sl_mallocatorg_windows_allocate
#define mk_sl_mallocatorg_impl_deallocate                        mk_sl_mallocatorg_windows_deallocate
#define mk_sl_mallocatorg_impl_reallocate                        mk_sl_mallocatorg_windows_reallocate
#define mk_sl_mallocatorg_impl_statistics_get_bytes_allocated    mk_sl_mallocatorg_windows_statistics_get_bytes_allocated
#define mk_sl_mallocatorg_impl_statistics_get_bytes_deallocated  mk_sl_mallocatorg_windows_statistics_get_bytes_deallocated
#define mk_sl_mallocatorg_impl_statistics_get_bytes_live         mk_sl_mallocatorg_windows_statistics_get_bytes_live
#define mk_sl_mallocatorg_impl_statistics_get_bytes_peak         mk_sl_mallocatorg_windows_statistics_get_bytes_peak
#define mk_sl_mallocatorg_impl_statistics_get_blocks_allocated   mk_sl_mallocatorg_windows_statistics_get_blocks_allocated
#define mk_sl_mallocatorg_impl_statistics_get_blocks_deallocated mk_sl_mallocatorg_windows_statistics_get_blocks_deallocated
#define mk_sl_mallocatorg_impl_statistics_get_blocks_live        mk_sl_mallocatorg_windows_statistics_get_blocks_live
#define mk_sl_mallocatorg_impl_statistics_get_blocks_peak        mk_sl_mallocatorg_windows_statistics_get_blocks_peak
#elif defined __cplusplus
#include "mk_sl_mallocatorg_portablecpp.hpp"
#define mk_sl_mallocatorg_impl_init                              mk_sl_mallocatorg_portablecpp_init
#define mk_sl_mallocatorg_impl_deinit                            mk_sl_mallocatorg_portablecpp_deinit
#define mk_sl_mallocatorg_impl_allocate                          mk_sl_mallocatorg_portablecpp_allocate
#define mk_sl_mallocatorg_impl_deallocate                        mk_sl_mallocatorg_portablecpp_deallocate
#define mk_sl_mallocatorg_impl_reallocate                        mk_sl_mallocatorg_portablecpp_reallocate
#define mk_sl_mallocatorg_impl_statistics_get_bytes_allocated    mk_sl_mallocatorg_portablecpp_statistics_get_bytes_allocated
#define mk_sl_mallocatorg_impl_statistics_get_bytes_deallocated  mk_sl_mallocatorg_portablecpp_statistics_get_bytes_deallocated
#define mk_sl_mallocatorg_impl_statistics_get_bytes_live         mk_sl_mallocatorg_portablecpp_statistics_get_bytes_live
#define mk_sl_mallocatorg_impl_statistics_get_bytes_peak         mk_sl_mallocatorg_portablecpp_statistics_get_bytes_peak
#define mk_sl_mallocatorg_impl_statistics_get_blocks_allocated   mk_sl_mallocatorg_portablecpp_statistics_get_blocks_allocated
#define mk_sl_mallocatorg_impl_statistics_get_blocks_deallocated mk_sl_mallocatorg_portablecpp_statistics_get_blocks_deallocated
#define mk_sl_mallocatorg_impl_statistics_get_blocks_live        mk_sl_mallocatorg_portablecpp_statistics_get_blocks_live
#define mk_sl_mallocatorg_impl_statistics_get_blocks_peak        mk_sl_mallocatorg_portablecpp_statistics_get_blocks_peak
#else
#include "mk_sl_mallocatorg_portablec.h"
#define mk_sl_mallocatorg_impl_init                              mk_sl_mallocatorg_portablec_init
#define mk_sl_mallocatorg_impl_deinit                            mk_sl_mallocatorg_portablec_deinit
#define mk_sl_mallocatorg_impl_allocate                          mk_sl_mallocatorg_portablec_allocate
#define mk_sl_mallocatorg_impl_deallocate                        mk_sl_mallocatorg_portablec_deallocate
#define mk_sl_mallocatorg_impl_reallocate                        mk_sl_mallocatorg_portablec_reallocate
#define mk_sl_mallocatorg_impl_statistics_get_bytes_allocated    mk_sl_mallocatorg_portablec_statistics_get_bytes_allocated
#define mk_sl_mallocatorg_impl_statistics_get_bytes_deallocated  mk_sl_mallocatorg_portablec_statistics_get_bytes_deallocated
#define mk_sl_mallocatorg_impl_statistics_get_bytes_live         mk_sl_mallocatorg_portablec_statistics_get_bytes_live
#define mk_sl_mallocatorg_impl_statistics_get_bytes_peak         mk_sl_mallocatorg_portablec_statistics_get_bytes_peak
#define mk_sl_mallocatorg_impl_statistics_get_blocks_allocated   mk_sl_mallocatorg_portablec_statistics_get_blocks_allocated
#define mk_sl_mallocatorg_impl_statistics_get_blocks_deallocated mk_sl_mallocatorg_portablec_statistics_get_blocks_deallocated
#define mk_sl_mallocatorg_impl_statistics_get_blocks_live        mk_sl_mallocatorg_portablec_statistics_get_blocks_live
#define mk_sl_mallocatorg_impl_statistics_get_blocks_peak        mk_sl_mallocatorg_portablec_statistics_get_blocks_peak
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_init();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_deinit();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_allocate(mk_lang_types_usize_t const size, mk_lang_types_void_ppt const mem) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_allocate(size, mem);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_deallocate(mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_deallocate(mem, size);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_reallocate(mk_lang_types_void_pct const old_mem, mk_lang_types_usize_t const old_size, mk_lang_types_usize_t const new_size, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_reallocate(old_mem, old_size, new_size, new_mem);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_statistics_get_bytes_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_statistics_get_bytes_allocated(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_statistics_get_bytes_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_statistics_get_bytes_deallocated(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_statistics_get_bytes_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_statistics_get_bytes_live(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_statistics_get_bytes_peak(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_statistics_get_bytes_peak(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_statistics_get_blocks_allocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_statistics_get_blocks_allocated(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_statistics_get_blocks_deallocated(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_statistics_get_blocks_deallocated(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_statistics_get_blocks_live(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_statistics_get_blocks_live(cnt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_mallocatorg_statistics_get_blocks_peak(mk_sl_cui_uint128_pt const cnt) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_mallocatorg_impl_statistics_get_blocks_peak(cnt);
	return ret;
}
