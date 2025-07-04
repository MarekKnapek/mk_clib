#ifndef mk_include_guard_mk_lib_iip_http_buffer_c
#define mk_include_guard_mk_lib_iip_http_buffer_c
#include "mk_lib_iip_http_buffer.h"

#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_sl_cui_uint8.h"


#define mk_sl_vector_t_name mk_lib_iip_http_buffer
#define mk_sl_vector_t_element_type mk_sl_cui_uint8_t
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
