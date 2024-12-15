#include "mk_win_api_ms_win_core_synch_l1_2_0.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


#pragma comment(lib, "synchronization.lib")


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall WaitOnAddress(mk_win_base_void_pvt const address, mk_win_base_void_pt const compare_address, mk_win_base_usize_t const address_size, mk_win_base_dword_t const milliseconds) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall WakeByAddressSingle(mk_win_base_void_pt const address) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall WakeByAddressAll(mk_win_base_void_pt const address) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_api_ms_win_core_synch_l1_2_0_wait_on_address(mk_win_base_void_pvt const address, mk_win_base_void_pt const compare_address, mk_win_base_usize_t const address_size, mk_win_base_dword_t const milliseconds) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = WaitOnAddress(address, compare_address, address_size, milliseconds);
	return ret;
}

mk_lang_jumbo mk_lang_types_void_t mk_win_api_ms_win_core_synch_l1_2_0_wake_by_address_single(mk_win_base_void_pt const address) mk_lang_noexcept
{
	WakeByAddressSingle(address);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_api_ms_win_core_synch_l1_2_0_wake_by_address_all(mk_win_base_void_pt const address) mk_lang_noexcept
{
	WakeByAddressAll(address);
}
