#ifndef mk_include_guard_mk_lib_iip_cp_mallocator_global_h
#define mk_include_guard_mk_lib_iip_cp_mallocator_global_h


#include "mk_sl_mallocator.h"


#define mk_sl_mallocator_global_forwarder_t_name mk_lib_iip_cp_mallocator_global
#define mk_sl_mallocator_global_forwarder_t_base_name mk_sl_mallocator
#include "mk_sl_mallocator_global_forwarder_inl_fileh.h"
#include "mk_sl_mallocator_global_forwarder_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_mallocator_global.c"
#endif
#endif
