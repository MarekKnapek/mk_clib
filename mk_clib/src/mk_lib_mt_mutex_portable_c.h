#ifndef mk_include_guard_mk_lib_mt_mutex_portable_c
#define mk_include_guard_mk_lib_mt_mutex_portable_c


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <threads.h> /* mtx_t */


struct mk_lib_mt_mutex_portable_c_s
{
	mtx_t m_mutex;
};
typedef struct mk_lib_mt_mutex_portable_c_s mk_lib_mt_mutex_portable_c_t;
typedef mk_lib_mt_mutex_portable_c_t const mk_lib_mt_mutex_portable_c_ct;
typedef mk_lib_mt_mutex_portable_c_t* mk_lib_mt_mutex_portable_c_pt;
typedef mk_lib_mt_mutex_portable_c_t const* mk_lib_mt_mutex_portable_c_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_c_construct(mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_c_destruct(mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_c_exclusive_lock(mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_c_exclusive_unlock(mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_c_shared_lock(mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_mutex_portable_c_shared_unlock(mk_lib_mt_mutex_portable_c_pt const mutex) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_mutex_portable_c.c"
#endif
#endif
