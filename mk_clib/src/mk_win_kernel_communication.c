#include "mk_win_kernel_communication.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall DeviceIoControl(mk_win_base_handle_t const handle, mk_win_base_dword_t const control_code, mk_win_base_void_lpct const in_buf, mk_win_base_dword_t const in_len, mk_win_base_void_lpt const out_buf, mk_win_base_dword_t const out_len, mk_win_base_dword_lpt const nwritten, mk_win_kernel_communication_overlapped_lpt const overlapped) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_communication_device_io_control(mk_win_base_handle_t const handle, mk_win_base_dword_t const control_code, mk_win_base_void_lpct const in_buf, mk_win_base_dword_t const in_len, mk_win_base_void_lpt const out_buf, mk_win_base_dword_t const out_len, mk_win_base_dword_lpt const nwritten, mk_win_kernel_communication_overlapped_lpt const overlapped) mk_lang_noexcept
{
	mk_win_base_bool_t r;

	r = DeviceIoControl(handle, control_code, in_buf, in_len, out_buf, out_len, nwritten, overlapped);
	return r;
}
