#ifndef mk_include_guard_mk_sl_io_directory_iterator_h
#define mk_include_guard_mk_sl_io_directory_iterator_h


#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


#if mk_lang_platform_is_windows_at_least_any
#include "mk_sl_io_directory_iterator_windows.h"
#define mk_sl_io_directory_iterator_prefix windows
#else
#error xxxxxxxxxx
#endif


#define mk_sl_io_directory_iterator_impl_t mk_lang_concat(mk_lang_concat(mk_sl_io_directory_iterator_, mk_sl_io_directory_iterator_prefix), _t)


struct mk_sl_io_directory_iterator_s
{
	mk_sl_io_directory_iterator_impl_t m_base;
};
typedef struct mk_sl_io_directory_iterator_s mk_sl_io_directory_iterator_t;
mk_lang_typedef(mk_sl_io_directory_iterator);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_construct_void(mk_sl_io_directory_iterator_pt const directory_iterator) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_construct(mk_sl_io_directory_iterator_pt const directory_iterator, mk_lang_types_pchar_pct const path) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_destroy(mk_sl_io_directory_iterator_pt const directory_iterator) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_reset(mk_sl_io_directory_iterator_pt const directory_iterator) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_get_name(mk_sl_io_directory_iterator_pt const directory_iterator, mk_lang_types_pchar_ppct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_next(mk_sl_io_directory_iterator_pt const directory_iterator) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_is_end(mk_sl_io_directory_iterator_pt const directory_iterator, mk_lang_types_bool_pt const is) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_io_directory_iterator.c"
#endif
#endif
