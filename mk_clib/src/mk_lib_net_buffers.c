#ifndef mk_include_guard_mk_lib_net_buffers_c
#define mk_include_guard_mk_lib_net_buffers_c
#include "mk_lib_net_buffers.h"

#include "mk_lang_assert.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_buffers.h"


static mk_sl_buffers_t mk_lib_net_buffers_g;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_buffers_prrw_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_sl_buffers_rw_construct(&mk_lib_net_buffers_g);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_buffers_prrw_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_sl_buffers_rw_destroy(&mk_lib_net_buffers_g);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_buffers_prrw_allocate_one(mk_sl_buffers_buffer_ppt const buffer) mk_lang_noexcept
{
	return mk_sl_buffers_rw_allocate_one(&mk_lib_net_buffers_g, buffer);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_buffers_prrw_deallocate_one(mk_sl_buffers_buffer_pt const buffer) mk_lang_noexcept
{
	return mk_sl_buffers_rw_deallocate_one(&mk_lib_net_buffers_g, buffer);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_buffers_rw_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_net_buffers_prrw_init();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_buffers_rw_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_net_buffers_prrw_deinit();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_buffers_rw_allocate_one(mk_sl_buffers_buffer_ppt const buffer) mk_lang_noexcept
{
	return mk_lib_net_buffers_prrw_allocate_one(buffer);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_buffers_rw_deallocate_one(mk_sl_buffers_buffer_pt const buffer) mk_lang_noexcept
{
	return mk_lib_net_buffers_prrw_deallocate_one(buffer);
}


#endif
