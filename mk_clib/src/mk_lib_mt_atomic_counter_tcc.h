#ifndef mk_include_guard_mk_lib_mt_atomic_counter_tcc
#define mk_include_guard_mk_lib_mt_atomic_counter_tcc


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


#if defined __TINYC__ && __TINYC__ >= 928 /* todo version */


typedef mk_win_base_slong_t mk_lib_mt_atomic_counter_tcc_int_t;
typedef mk_lib_mt_atomic_counter_tcc_int_t const mk_lib_mt_atomic_counter_tcc_int_ct;
typedef mk_lib_mt_atomic_counter_tcc_int_t* mk_lib_mt_atomic_counter_tcc_int_pt;
typedef mk_lib_mt_atomic_counter_tcc_int_t const* mk_lib_mt_atomic_counter_tcc_int_pct;

struct mk_lib_mt_atomic_counter_tcc_s
{
	mk_lib_mt_atomic_counter_tcc_int_t m_value;
};
typedef struct mk_lib_mt_atomic_counter_tcc_s mk_lib_mt_atomic_counter_tcc_t;
typedef mk_lib_mt_atomic_counter_tcc_t const mk_lib_mt_atomic_counter_tcc_ct;
typedef mk_lib_mt_atomic_counter_tcc_t* mk_lib_mt_atomic_counter_tcc_pt;
typedef mk_lib_mt_atomic_counter_tcc_t const* mk_lib_mt_atomic_counter_tcc_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_tcc_construct(mk_lib_mt_atomic_counter_tcc_pt const atomic_counter) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_tcc_destruct(mk_lib_mt_atomic_counter_tcc_pt const atomic_counter) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_tcc_increment(mk_lib_mt_atomic_counter_tcc_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_tcc_decrement(mk_lib_mt_atomic_counter_tcc_pt const atomic_counter, mk_lang_types_sint_pt const cmp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_atomic_counter_tcc_exchange(mk_lib_mt_atomic_counter_tcc_pt const atomic_counter, mk_lib_mt_atomic_counter_tcc_int_t const desired, mk_lib_mt_atomic_counter_tcc_int_pt const previous) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_atomic_counter_tcc.c"
#endif
#endif
