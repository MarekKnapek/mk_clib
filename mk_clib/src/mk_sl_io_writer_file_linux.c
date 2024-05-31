#include "mk_sl_io_writer_file_linux.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_io_transaction_portable.h"
#include "mk_sl_uint8.h"


#if mk_lang_platform == mk_lang_platform_linux


/* close O_CLOEXEC O_CREAT O_TRUNC O_WRONLY open S_IRGRP S_IROTH S_IRUSR S_IWUSR write */
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#define mk_sl_io_writer_file_linux_is_valid(x) ((x) >= 0)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_linux_open_n(mk_sl_io_writer_file_linux_pt const writer, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_sl_io_writer_file_linux_handle_t handle;

	mk_lang_assert(writer);
	mk_lang_assert(name && name[0] != '\0');

	handle = open(name, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); mk_lang_check_return(handle >= 0);
	writer->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_linux_open_w(mk_sl_io_writer_file_linux_pt const writer, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_lang_assert(writer);
	mk_lang_assert(name && name[0] != L'\0');

	mk_lang_assert(mk_lang_false);
	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_linux_open_tx_n(mk_sl_io_writer_file_linux_pt const writer, mk_lang_types_pchar_pct const name, mk_sl_io_transaction_portable_pt const tx) mk_lang_noexcept
{
	mk_lang_assert(writer);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx);

	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_linux_open_tx_w(mk_sl_io_writer_file_linux_pt const writer, mk_lang_types_wchar_pct const name, mk_sl_io_transaction_portable_pt const tx) mk_lang_noexcept
{
	mk_lang_assert(writer);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx);

	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_linux_write(mk_sl_io_writer_file_linux_pt const writer, mk_sl_cui_uint8_pct const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const written) mk_lang_noexcept
{
	mk_lang_types_ssize_t ret;

	mk_lang_assert(writer);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 1);
	mk_lang_assert(written);
	mk_lang_assert(mk_sl_io_writer_file_linux_is_valid(writer->m_file_handle));

	ret = write(writer->m_file_handle, buf, len); mk_lang_check_return(ret >= 0);
	*written = ((mk_lang_types_usize_t)(ret));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_linux_close(mk_sl_io_writer_file_linux_pt const writer) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(writer);
	mk_lang_assert(mk_sl_io_writer_file_linux_is_valid(writer->m_file_handle));

	ret = close(writer->m_file_handle); mk_lang_check_return(ret == 0);
	return 0;
}


#endif
