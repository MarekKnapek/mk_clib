#ifndef mk_include_guard_mk_sl_io_directory_iterator_windows_h
#define mk_include_guard_mk_sl_io_directory_iterator_windows_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_files.h"


typedef mk_win_base_handle_t mk_sl_io_directory_iterator_windows_handle_t;

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_sl_io_directory_iterator_windows_s
{
	mk_sl_io_directory_iterator_windows_handle_t m_handle;
	mk_win_dll_kernel_files_a_find_data_t m_data;
	mk_lang_types_bool_t m_is_end;
};
typedef struct mk_sl_io_directory_iterator_windows_s mk_sl_io_directory_iterator_windows_t;
mk_lang_typedef(mk_sl_io_directory_iterator_windows);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_construct_void(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_construct(mk_sl_io_directory_iterator_windows_pt const directory_iterator, mk_lang_types_pchar_pct const path) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_destroy(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_reset(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_get_name(mk_sl_io_directory_iterator_windows_pt const directory_iterator, mk_lang_types_pchar_ppct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_next(mk_sl_io_directory_iterator_windows_pt const directory_iterator) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_windows_rw_is_end(mk_sl_io_directory_iterator_windows_pt const directory_iterator, mk_lang_types_bool_pt const is) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_sl_io_directory_iterator_windows.c"
#endif
#endif
