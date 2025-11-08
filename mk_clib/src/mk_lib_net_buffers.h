#ifndef mk_include_guard_mk_lib_net_buffers_h
#define mk_include_guard_mk_lib_net_buffers_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_buffers_buffer);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_buffers_rw_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_buffers_rw_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_buffers_rw_allocate_one(mk_sl_buffers_buffer_ppt const buffer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_buffers_rw_deallocate_one(mk_sl_buffers_buffer_pt const buffer) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net_buffers.c"
#endif
#endif
