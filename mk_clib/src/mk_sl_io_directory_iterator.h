#ifndef mk_include_guard_mk_sl_io_directory_iterator_h
#define mk_include_guard_mk_sl_io_directory_iterator_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


#if mk_lang_platform_is_windows_at_least_any
#include "mk_sl_io_directory_iterator_windows.h"
typedef mk_sl_io_directory_iterator_windows_t mk_sl_io_directory_iterator_handle_t;
#elif mk_lang_platform_is_linux
#include "mk_sl_io_directory_iterator_linux.h"
typedef mk_sl_io_directory_iterator_linux_t mk_sl_io_directory_iterator_handle_t;
#elif mk_lang_platform_is_posix_at_least_any
#include "mk_sl_io_directory_iterator_posix.h"
typedef mk_sl_io_directory_iterator_posix_t mk_sl_io_directory_iterator_handle_t;
#elif mk_lang_platform_is_portable
#include "mk_sl_io_directory_iterator_portable.h"
typedef mk_sl_io_directory_iterator_portable_t mk_sl_io_directory_iterator_handle_t;
#else
#error xxxxxxxxxx
#endif


struct mk_sl_io_directory_iterator_s
{
	mk_sl_io_directory_iterator_handle_t m_file_handle;
};
typedef struct mk_sl_io_directory_iterator_s mk_sl_io_directory_iterator_t;
mk_lang_typedef(mk_sl_io_directory_iterator);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_open_n(mk_sl_io_directory_iterator_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_open_w(mk_sl_io_directory_iterator_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_open_t(mk_sl_io_directory_iterator_pt const reader, mk_lang_tchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_read(mk_sl_io_directory_iterator_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const read) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_seek_rel(mk_sl_io_directory_iterator_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_close(mk_sl_io_directory_iterator_pt const reader) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_io_directory_iterator.c"
#endif
#endif
