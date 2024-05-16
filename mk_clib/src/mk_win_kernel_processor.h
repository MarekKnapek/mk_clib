#ifndef mk_include_guard_mk_win_kernel_processor
#define mk_include_guard_mk_win_kernel_processor


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_jumbo mk_win_base_word_t mk_win_kernel_processor_group_active_count(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_processor_active_count(mk_win_base_word_t const group_idx) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_processor.c"
#endif
#endif
