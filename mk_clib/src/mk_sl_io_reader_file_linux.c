#include "mk_sl_io_reader_file_linux.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_os.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_io_transaction_linux.h"
#include "mk_sl_uint8.h"


#if mk_lang_os == mk_lang_os_linux


/* close lseek O_CLOEXEC O_RDONLY off_t open read SEEK_CUR */
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#define mk_sl_io_reader_file_linux_is_valid(x) ((x) >= 0)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_open_n(mk_sl_io_reader_file_linux_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept
{
	mk_sl_io_reader_file_linux_handle_t handle;

	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');

	handle = open(name, O_RDONLY | O_CLOEXEC); mk_lang_check_return(handle >= 0);
	reader->m_file_handle = handle;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_open_w(mk_sl_io_reader_file_linux_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != L'\0');

	mk_lang_assert(mk_lang_false);
	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_open_tx_n(mk_sl_io_reader_file_linux_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_transaction_linux_pt const tx) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx);

	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_open_tx_w(mk_sl_io_reader_file_linux_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_transaction_linux_pt const tx) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(name && name[0] != '\0');
	mk_lang_assert(tx);

	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_read(mk_sl_io_reader_file_linux_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const read_) mk_lang_noexcept
{
	mk_lang_types_ssize_t ret;

	mk_lang_assert(reader);
	mk_lang_assert(buf);
	mk_lang_assert(len >= 1);
	mk_lang_assert(read);
	mk_lang_assert(mk_sl_io_reader_file_linux_is_valid(reader->m_file_handle));

	ret = read(reader->m_file_handle, buf, len); mk_lang_check_return(ret >= 0);
	*read_ = ((mk_lang_types_usize_t)(ret));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_seek_rel(mk_sl_io_reader_file_linux_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept
{
	off_t ret;

	mk_lang_assert(reader);
	mk_lang_assert(offset != 0);
	mk_lang_assert(mk_sl_io_reader_file_linux_is_valid(reader->m_file_handle));

	ret = lseek(reader->m_file_handle, ((off_t)(offset)), SEEK_CUR); mk_lang_check_return(ret != ((off_t)(-1)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_linux_close(mk_sl_io_reader_file_linux_pt const reader) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(reader);
	mk_lang_assert(mk_sl_io_reader_file_linux_is_valid(reader->m_file_handle));

	ret = close(reader->m_file_handle); mk_lang_check_return(ret == 0);
	return 0;
}


#endif
