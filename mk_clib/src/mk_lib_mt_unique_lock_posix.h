#ifndef mk_include_guard_mk_lib_mt_unique_lock_posix
#define mk_include_guard_mk_lib_mt_unique_lock_posix


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_mutex_posix.h"


#if defined mk_lib_mt_posix_has && mk_lib_mt_posix_has == 1


struct mk_lib_mt_unique_lock_exclusive_posix_s
{
	mk_lib_mt_mutex_posix_pt m_mutex;
};
typedef struct mk_lib_mt_unique_lock_exclusive_posix_s mk_lib_mt_unique_lock_exclusive_posix_t;
typedef mk_lib_mt_unique_lock_exclusive_posix_t const mk_lib_mt_unique_lock_exclusive_posix_ct;
typedef mk_lib_mt_unique_lock_exclusive_posix_t* mk_lib_mt_unique_lock_exclusive_posix_pt;
typedef mk_lib_mt_unique_lock_exclusive_posix_t const* mk_lib_mt_unique_lock_exclusive_posix_pct;

struct mk_lib_mt_unique_lock_shared_posix_s
{
	mk_lib_mt_mutex_posix_pt m_mutex;
};
typedef struct mk_lib_mt_unique_lock_shared_posix_s mk_lib_mt_unique_lock_shared_posix_t;
typedef mk_lib_mt_unique_lock_shared_posix_t const mk_lib_mt_unique_lock_shared_posix_ct;
typedef mk_lib_mt_unique_lock_shared_posix_t* mk_lib_mt_unique_lock_shared_posix_pt;
typedef mk_lib_mt_unique_lock_shared_posix_t const* mk_lib_mt_unique_lock_shared_posix_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_posix_construct(mk_lib_mt_unique_lock_exclusive_posix_pt const unique_lock, mk_lib_mt_mutex_posix_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_exclusive_posix_destruct(mk_lib_mt_unique_lock_exclusive_posix_pt const unique_lock) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_posix_construct(mk_lib_mt_unique_lock_shared_posix_pt const unique_lock, mk_lib_mt_mutex_posix_pt const mutex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_unique_lock_shared_posix_destruct(mk_lib_mt_unique_lock_shared_posix_pt const unique_lock) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_want == 1
#include "mk_lib_mt_unique_lock_posix.c"
#endif
#endif
