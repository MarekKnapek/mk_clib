#ifndef mk_include_guard_mk_lib_fe_posix
#define mk_include_guard_mk_lib_fe_posix


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_mallocatorg.h"


#define mk_sl_vector_t_name mk_lib_fe_posix_string
#define mk_sl_vector_t_element mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_fileh.h"
#undef mk_sl_vector_t_name
#undef mk_sl_vector_t_element
#undef mk_sl_vector_t_mallocatorg

struct mk_lib_fe_posix_file_s
{
	mk_lib_fe_posix_string_t m_name;
	mk_lang_types_bool_t m_is_dir;
};
typedef struct mk_lib_fe_posix_file_s mk_lib_fe_posix_file_t;
typedef mk_lib_fe_posix_file_t const mk_lib_fe_posix_file_ct;
typedef mk_lib_fe_posix_file_t* mk_lib_fe_posix_file_pt;
typedef mk_lib_fe_posix_file_t const* mk_lib_fe_posix_file_pct;

#define mk_sl_vector_t_name mk_lib_fe_posix_files
#define mk_sl_vector_t_element mk_lib_fe_posix_file_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_fileh.h"
#undef mk_sl_vector_t_name
#undef mk_sl_vector_t_element
#undef mk_sl_vector_t_mallocatorg

#define mk_sl_vector_t_name mk_lib_fe_posix_ints
#define mk_sl_vector_t_element mk_lang_types_sint_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_fileh.h"
#undef mk_sl_vector_t_name
#undef mk_sl_vector_t_element
#undef mk_sl_vector_t_mallocatorg


struct mk_lib_fe_posix_s
{
	mk_lib_fe_posix_string_t m_path;
	mk_lib_fe_posix_files_t m_files;
	mk_lib_fe_posix_ints_t m_sort;
	mk_lang_types_sint_t m_depth;
};
typedef struct mk_lib_fe_posix_s mk_lib_fe_posix_t;
typedef mk_lib_fe_posix_t const mk_lib_fe_posix_ct;
typedef mk_lib_fe_posix_t* mk_lib_fe_posix_pt;
typedef mk_lib_fe_posix_t const* mk_lib_fe_posix_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_rw_construct(mk_lib_fe_posix_pt const fe) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_rw_destruct(mk_lib_fe_posix_pt const fe) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_get_path(mk_lib_fe_posix_pct const fe, mk_lib_fe_posix_string_ppct const path_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_get_files(mk_lib_fe_posix_pct const fe, mk_lib_fe_posix_files_ppct const files_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_get_sort(mk_lib_fe_posix_pct const fe, mk_lib_fe_posix_ints_ppct const sort_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_get_count(mk_lib_fe_posix_pct const fe, mk_lang_types_sint_pt const count_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_get_depth(mk_lib_fe_posix_pct const fe, mk_lang_types_sint_pt const depth_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_ro_can_go_up(mk_lib_fe_posix_pct const fe, mk_lang_types_bool_pt const can_go_up_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_rw_go_dn(mk_lib_fe_posix_pt const fe, mk_lang_types_sint_t const idx, mk_lang_types_bool_pt const went) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_posix_rw_go_up(mk_lib_fe_posix_pt const fe, mk_lang_types_bool_pt const went) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_fe_posix.c"
#endif
#endif
