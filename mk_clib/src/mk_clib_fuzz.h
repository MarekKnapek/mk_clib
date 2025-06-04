#ifndef mk_include_guard_mk_clib_fuzz_h
#define mk_include_guard_mk_clib_fuzz_h


#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_fuzz_ctx_s
{
	mk_lang_types_sint_t m_argc;
	mk_lang_types_pchar_pcpct m_argv;
	mk_lang_types_sint_t m_line;
};
typedef struct mk_clib_fuzz_ctx_s mk_clib_fuzz_ctx_t;
mk_lang_typedef(mk_clib_fuzz_ctx);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_inline mk_lang_types_sint_t mk_clib_fuzz_init_ctx(mk_clib_fuzz_ctx_pt const ctx, mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_lang_inline mk_lang_types_sint_t mk_clib_fuzz_init_mallocator(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_lang_inline mk_lang_types_sint_t mk_clib_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size, mk_lang_types_bool_t const allow_all, mk_clib_fuzz_ctx_pt const ctx) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_clib_fuzz.c"
#endif
#endif
