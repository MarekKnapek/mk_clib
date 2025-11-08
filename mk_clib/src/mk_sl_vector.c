#ifndef mk_include_guard_mk_sl_vector_c
#define mk_include_guard_mk_sl_vector_c
#include "mk_sl_vector.h"

#include "mk_lang_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_vector_copy.h"


#define mk_sl_vector_t_name mk_sl_vector_u8
#define mk_sl_vector_t_element_type mk_sl_cui_uint8_t
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_copy_style mk_sl_vector_copy_use_bitblt
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#define mk_sl_vector_t_name mk_sl_vector_vp
#define mk_sl_vector_t_element_type mk_lang_types_void_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_copy_style mk_sl_vector_copy_use_bitblt
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
