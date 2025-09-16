#ifndef mk_include_guard_mk_lib_wasm_info_h
#define mk_include_guard_mk_lib_wasm_info_h


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo mk_lang_types_void_t mk_lib_wasm_info_main(mk_lang_types_void_t) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_wasm_info.c"
#endif
#endif
