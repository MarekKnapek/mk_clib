#ifndef mk_include_guard_mk_lib_fast_import_h
#define mk_include_guard_mk_lib_fast_import_h


#include "mk_lang_jumbo.h"
#include "mk_lang_types.h"
#include "mk_sl_mallocator.c"


#define mk_sl_vector_t_name mk_sl_string
#define mk_sl_vector_t_element_type mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#define mk_sl_vector_t_element_eq mk_lang_types_pchar_eq
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_fast_import.c"
#endif
#endif
