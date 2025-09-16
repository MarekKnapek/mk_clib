#ifndef mk_include_guard_mk_lib_wasm_float_analyzer_b64_h
#define mk_include_guard_mk_lib_wasm_float_analyzer_b64_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_lib_float_analyzer_b64);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_float_analyzer_b64_main(mk_lib_float_analyzer_b64_pt const analyzer, mk_lang_types_uintptr_t const fnc, mk_lang_types_uintptr_t const arg) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_wasm_float_analyzer_b64.c"
#endif
#endif
