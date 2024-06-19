#include "mk_win_kernel_communication.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_kernel_files.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall DeviceIoControl(mk_win_base_handle_t const device, mk_win_base_dword_t const control_code, mk_win_base_void_lpct const inbuf, mk_win_base_dword_t const inlen, mk_win_base_void_lpt const outbuf, mk_win_base_dword_t const outlen, mk_win_base_dword_lpt const written, mk_win_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_communication_device_io_control(mk_win_base_handle_t const device, mk_win_base_dword_t const control_code, mk_win_base_void_lpct const inbuf, mk_win_base_dword_t const inlen, mk_win_base_void_lpt const outbuf, mk_win_base_dword_t const outlen, mk_win_base_dword_lpt const written, mk_win_kernel_files_overlapped_lpt const overlapped) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = DeviceIoControl(device, control_code, inbuf, inlen, outbuf, outlen, written, overlapped);
	return ret;
}
