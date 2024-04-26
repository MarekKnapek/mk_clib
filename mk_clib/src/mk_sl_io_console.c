#include "mk_sl_io_console.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_os.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#if mk_lang_os == mk_lang_os_windows
#include "mk_sl_io_console_windows.h"
#define mk_sl_io_console_impl_write_n mk_sl_io_console_windows_write_n
#define mk_sl_io_console_impl_write_w mk_sl_io_console_windows_write_w
#elif mk_lang_os == mk_lang_os_c
#include "mk_sl_io_console_portable.h"
#define mk_sl_io_console_impl_write_n mk_sl_io_console_portable_write_n
#define mk_sl_io_console_impl_write_w mk_sl_io_console_portable_write_w
#else
#error todo xxxxxxxxxx
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_console_write_n(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	return mk_sl_io_console_impl_write_n(buf, len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_console_write_w(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	return mk_sl_io_console_impl_write_w(buf, len);
}
