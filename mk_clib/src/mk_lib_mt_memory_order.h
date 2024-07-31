#ifndef mk_include_guard_mk_lib_mt_memory_order
#define mk_include_guard_mk_lib_mt_memory_order


#include "mk_lang_jumbo.h"


enum mk_lib_mt_memory_order_e
{
	mk_lib_mt_memory_order_e_relaxed,
	mk_lib_mt_memory_order_e_acquire,
	mk_lib_mt_memory_order_e_release,
	mk_lib_mt_memory_order_e_acq_rel,
	mk_lib_mt_memory_order_e_seq_cst,
	mk_lib_mt_memory_order_e_dummy_end
};
typedef enum mk_lib_mt_memory_order_e mk_lib_mt_memory_order_t;


#if mk_lang_jumbo_want == 1
/*#include "mk_lib_mt_memory_order.c"*/
#endif
#endif
