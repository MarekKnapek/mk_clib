#include "mk_win_kernel_processor.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_word_t mk_win_base_stdcall GetActiveProcessorGroupCount(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetActiveProcessorCount(mk_win_base_word_t const group_idx) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetThreadIdealProcessorEx(mk_win_base_handle_t const thread, mk_win_kernel_processor_number_pct const ideal_processor_new, mk_win_kernel_processor_number_pt const ideal_processor_old) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_word_t mk_win_kernel_processor_group_active_count(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_word_t ret;

	ret = GetActiveProcessorGroupCount();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_processor_active_count(mk_win_base_word_t const group_idx) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetActiveProcessorCount(group_idx);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_processor_set_ideal(mk_win_base_handle_t const thread, mk_win_kernel_processor_number_pct const ideal_processor_new, mk_win_kernel_processor_number_pt const ideal_processor_old) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(thread.m_data);
	mk_lang_assert(ideal_processor_new);

	ret = SetThreadIdealProcessorEx(thread, ideal_processor_new, ideal_processor_old);
	return ret;
}
