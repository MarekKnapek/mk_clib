#ifndef mk_include_guard_mk_win_kernel_cs
#define mk_include_guard_mk_win_kernel_cs


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_win_kernel_cs_debug_s;
typedef struct mk_win_kernel_cs_debug_s mk_win_kernel_cs_debug_t;
typedef mk_win_kernel_cs_debug_t const mk_win_kernel_cs_debug_ct;
typedef mk_win_kernel_cs_debug_t* mk_win_kernel_cs_debug_pt;
typedef mk_win_kernel_cs_debug_t const* mk_win_kernel_cs_debug_pct;

struct mk_win_kernel_cs_s;
typedef struct mk_win_kernel_cs_s mk_win_kernel_cs_t;
typedef mk_win_kernel_cs_t const mk_win_kernel_cs_ct;
typedef mk_win_kernel_cs_t* mk_win_kernel_cs_pt;
typedef mk_win_kernel_cs_t const* mk_win_kernel_cs_pct;

struct mk_win_kernel_cs_debug_s
{
	mk_win_base_word_t m_type;
	mk_win_base_word_t m_creator_back_trace_index;
	mk_win_kernel_cs_pt m_critical_section;
	mk_win_base_list_entry_t m_process_locks_list;
	mk_win_base_dword_t m_entry_count;
	mk_win_base_dword_t m_contention_count;
	mk_win_base_dword_t m_flags;
	mk_win_base_word_t m_creator_back_trace_index_high;
	mk_win_base_word_t m_identifier;
};
typedef struct mk_win_kernel_cs_debug_s mk_win_kernel_cs_debug_t;
typedef mk_win_kernel_cs_debug_t const mk_win_kernel_cs_debug_ct;
typedef mk_win_kernel_cs_debug_t* mk_win_kernel_cs_debug_pt;
typedef mk_win_kernel_cs_debug_t const* mk_win_kernel_cs_debug_pct;

struct mk_win_kernel_cs_s
{
	mk_win_kernel_cs_debug_pt m_debug_info;
	mk_win_base_slong_t m_lock_count;
	mk_win_base_slong_t m_recursion_count;
	mk_win_base_handle_t m_owning_thread;
	mk_win_base_handle_t m_lock_semaphore;
	mk_win_base_uintptr_t m_spin_count;
};
typedef struct mk_win_kernel_cs_s mk_win_kernel_cs_t;
typedef mk_win_kernel_cs_t const mk_win_kernel_cs_ct;
typedef mk_win_kernel_cs_t* mk_win_kernel_cs_pt;
typedef mk_win_kernel_cs_t const* mk_win_kernel_cs_pct;


mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cs_construct(mk_win_kernel_cs_pt const cs) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cs_destroy(mk_win_kernel_cs_pt const cs) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cs_lock(mk_win_kernel_cs_pt const cs) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_kernel_cs_unlock(mk_win_kernel_cs_pt const cs) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_cs_try_lock(mk_win_kernel_cs_pt const cs) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_cs.c"
#endif
#endif
