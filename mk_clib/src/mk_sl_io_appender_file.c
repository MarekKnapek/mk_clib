#ifndef mk_include_guard_mk_sl_io_appender_file_c
#define mk_include_guard_mk_sl_io_appender_file_c
#include "mk_sl_io_appender_file.h"

#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"

mk_lang_forward(mk_sl_cui_uint8);


#if mk_lang_platform_is_windows_at_least_any
#include "mk_sl_io_appender_file_windows.h"
#define mk_sl_io_appender_file_impl_base_name windows
#else
#include "mk_sl_io_appender_file_portable.h"
#define mk_sl_io_appender_file_impl_base_name portable
#endif
#define mk_sl_io_appender_file_impl_base_prefix mk_lang_concat(mk_sl_io_appender_file_, mk_sl_io_appender_file_impl_base_name)

#define mk_sl_io_appender_file_impl_open_n mk_lang_concat(mk_sl_io_appender_file_impl_base_prefix, _open_n)
#define mk_sl_io_appender_file_impl_open_w mk_lang_concat(mk_sl_io_appender_file_impl_base_prefix, _open_w)
#define mk_sl_io_appender_file_impl_append mk_lang_concat(mk_sl_io_appender_file_impl_base_prefix, _append)
#define mk_sl_io_appender_file_impl_close mk_lang_concat(mk_sl_io_appender_file_impl_base_prefix, _close)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_open_n(mk_sl_io_appender_file_pt const appender, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	return mk_sl_io_appender_file_impl_open_n(&appender->m_base, name);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_open_w(mk_sl_io_appender_file_pt const appender, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	return mk_sl_io_appender_file_impl_open_w(&appender->m_base, name);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_append(mk_sl_io_appender_file_pt const appender, mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const written) mk_lang_noexcept
{
	return mk_sl_io_appender_file_impl_append(&appender->m_base, buf, len, written);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_appender_file_close(mk_sl_io_appender_file_pt const appender) mk_lang_noexcept
{
	return mk_sl_io_appender_file_impl_close(&appender->m_base);
}


#endif
