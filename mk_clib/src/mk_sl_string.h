#ifndef mk_include_guard_mk_sl_string
#define mk_include_guard_mk_sl_string


#include "mk_lang_types.h"
#include "mk_sl_mallocatorg.h"


#define mk_sl_vector_t_name mk_sl_string
#define mk_sl_vector_t_element mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_fileh.h"
#undef mk_sl_vector_t_name
#undef mk_sl_vector_t_element
#undef mk_sl_vector_t_mallocatorg

#define mk_sl_vector_t_name mk_sl_strings
#define mk_sl_vector_t_element mk_sl_string_t
#define mk_sl_vector_t_element_construct_void mk_sl_string_rw_construct
#define mk_sl_vector_t_element_destruct mk_sl_string_rw_destroy
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_fileh.h"
#undef mk_sl_vector_t_name
#undef mk_sl_vector_t_element
#undef mk_sl_vector_t_element_construct_void
#undef mk_sl_vector_t_element_destruct
#undef mk_sl_vector_t_mallocatorg


#if mk_lang_jumbo_want == 1
#include "mk_sl_string.c"
#endif
#endif
