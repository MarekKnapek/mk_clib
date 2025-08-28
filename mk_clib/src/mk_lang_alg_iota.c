#ifndef mk_include_guard_mk_lang_alg_iota_c
#define mk_include_guard_mk_lang_alg_iota_c
#include "mk_lang_alg_iota.h"

#include "mk_lang_types.h"


#define mk_lang_alg_iota_t_name mk_lang_alg_iota_sint_sint
#define mk_lang_alg_iota_t_element_type mk_lang_types_sint_t
#define mk_lang_alg_iota_t_counter_type mk_lang_types_sint_t
#include "mk_lang_alg_iota_inl_filec.h"
#include "mk_lang_alg_iota_inl_fileu.h"

#define mk_lang_alg_iota_t_name mk_lang_alg_iota_sint_usize
#define mk_lang_alg_iota_t_element_type mk_lang_types_sint_t
#define mk_lang_alg_iota_t_counter_type mk_lang_types_usize_t
#include "mk_lang_alg_iota_inl_filec.h"
#include "mk_lang_alg_iota_inl_fileu.h"


#endif
