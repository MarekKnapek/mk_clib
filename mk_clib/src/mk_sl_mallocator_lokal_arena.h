#ifndef mk_include_guard_mk_sl_mallocator_lokal_arena_h
#define mk_include_guard_mk_sl_mallocator_lokal_arena_h


#include "mk_lang_jumbo.h"


#if defined mk_sl_mallocator_lokal_arena_statistics_want
#if (mk_sl_mallocator_lokal_arena_statistics_want) == 0
#define mk_sl_mallocator_lokal_arena_statistics_have 0
#elif (mk_sl_mallocator_lokal_arena_statistics_want) == 1
#define mk_sl_mallocator_lokal_arena_statistics_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_sl_mallocator_lokal_arena_statistics_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_sl_mallocator_lokal_arena_statistics_have 0
#else
#define mk_sl_mallocator_lokal_arena_statistics_have 1
#endif
#endif
#endif

#if defined mk_sl_mallocator_lokal_arena_verify_want
#if (mk_sl_mallocator_lokal_arena_verify_want) == 0
#define mk_sl_mallocator_lokal_arena_verify_have 0
#elif (mk_sl_mallocator_lokal_arena_verify_want) == 1
#define mk_sl_mallocator_lokal_arena_verify_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_sl_mallocator_lokal_arena_verify_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_sl_mallocator_lokal_arena_verify_have 0
#else
#define mk_sl_mallocator_lokal_arena_verify_have 1
#endif
#endif
#endif


#define mk_sl_mallocator_lokal_arena_t_name mk_sl_mallocator_lokal_arena_ver1
#define mk_sl_mallocator_lokal_arena_t_size 4 * 64 * 1024
#define mk_sl_mallocator_lokal_arena_t_statistics_want mk_sl_mallocator_lokal_arena_statistics_have
#define mk_sl_mallocator_lokal_arena_t_verify_want mk_sl_mallocator_lokal_arena_verify_have
#include "mk_sl_mallocator_lokal_arena_inl_fileh.h"
#include "mk_sl_mallocator_lokal_arena_inl_fileu.h"

#define mk_sl_mallocator_lokal_arena_t_name mk_sl_mallocator_lokal_arena_ver2
#define mk_sl_mallocator_lokal_arena_t_size 2 * 1024 * 1024
#define mk_sl_mallocator_lokal_arena_t_statistics_want mk_sl_mallocator_lokal_arena_statistics_have
#define mk_sl_mallocator_lokal_arena_t_verify_want mk_sl_mallocator_lokal_arena_verify_have
#include "mk_sl_mallocator_lokal_arena_inl_fileh.h"
#include "mk_sl_mallocator_lokal_arena_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_sl_mallocator_lokal_arena.c"
#endif
#endif
