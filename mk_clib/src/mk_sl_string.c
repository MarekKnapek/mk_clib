#include "mk_sl_string.h"

#include "mk_lang_types.h"
#include "mk_sl_mallocatorg.h"


#define mk_sl_vector_t_name mk_sl_string
#define mk_sl_vector_t_element mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_filec.h"

#define mk_sl_vector_t_name mk_sl_strings
#define mk_sl_vector_t_element mk_sl_string_t
#define mk_sl_vector_t_element_construct_void mk_sl_string_rw_construct
#define mk_sl_vector_t_element_destruct mk_sl_string_rw_destroy
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_filec.h"
