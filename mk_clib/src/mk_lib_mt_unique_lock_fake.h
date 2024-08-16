#ifndef mk_include_guard_mk_lib_mt_unique_lock_fake
#define mk_include_guard_mk_lib_mt_unique_lock_fake


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_mutex_fake.h"


struct mk_lib_mt_unique_lock_exclusive_fake_s
{
	mk_lib_mt_mutex_fake_pt m_mutex;
};
typedef struct mk_lib_mt_unique_lock_exclusive_fake_s mk_lib_mt_unique_lock_exclusive_fake_t;
typedef mk_lib_mt_unique_lock_exclusive_fake_t const mk_lib_mt_unique_lock_exclusive_fake_ct;
typedef mk_lib_mt_unique_lock_exclusive_fake_t* mk_lib_mt_unique_lock_exclusive_fake_pt;
typedef mk_lib_mt_unique_lock_exclusive_fake_t const* mk_lib_mt_unique_lock_exclusive_fake_pct;

struct mk_lib_mt_unique_lock_shared_fake_s
{
	mk_lib_mt_mutex_fake_pt m_mutex;
};
typedef struct mk_lib_mt_unique_lock_shared_fake_s mk_lib_mt_unique_lock_shared_fake_t;
typedef mk_lib_mt_unique_lock_shared_fake_t const mk_lib_mt_unique_lock_shared_fake_ct;
typedef mk_lib_mt_unique_lock_shared_fake_t* mk_lib_mt_unique_lock_shared_fake_pt;
typedef mk_lib_mt_unique_lock_shared_fake_t const* mk_lib_mt_unique_lock_shared_fake_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_fake_construct(mk_lib_mt_unique_lock_exclusive_fake_pt const unique_lock, mk_lib_mt_mutex_fake_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_fake_destruct(mk_lib_mt_unique_lock_exclusive_fake_pt const unique_lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_fake_construct(mk_lib_mt_unique_lock_shared_fake_pt const unique_lock, mk_lib_mt_mutex_fake_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_fake_destruct(mk_lib_mt_unique_lock_shared_fake_pt const unique_lock) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_unique_lock_fake.c"
#endif
#endif
