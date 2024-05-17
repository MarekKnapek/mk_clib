#ifndef mk_include_guard_mk_win_kernel_processor
#define mk_include_guard_mk_win_kernel_processor


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_win_kernel_processor_number_s
{
	mk_win_base_word_t m_group;
	mk_win_base_uchar_t m_number;
	mk_win_base_uchar_t m_reserved;
};
typedef struct mk_win_kernel_processor_number_s mk_win_kernel_processor_number_t;
typedef mk_win_kernel_processor_number_t const mk_win_kernel_processor_number_ct;
typedef mk_win_kernel_processor_number_t* mk_win_kernel_processor_number_pt;
typedef mk_win_kernel_processor_number_t const* mk_win_kernel_processor_number_pct;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_word_t mk_win_kernel_processor_group_active_count(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_processor_active_count(mk_win_base_word_t const group_idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_processor_set_ideal(mk_win_base_handle_t const thread, mk_win_kernel_processor_number_pct const ideal_processor_new, mk_win_kernel_processor_number_pt const ideal_processor_old) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_processor.c"
#endif
#endif
