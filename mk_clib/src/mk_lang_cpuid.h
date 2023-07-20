#ifndef mk_include_guard_mk_lang_cpuid
#define mk_include_guard_mk_lang_cpuid


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo void mk_lang_cpuid_init(void) mk_lang_noexcept;
mk_lang_jumbo void mk_lang_cpuid_reset(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_aes_ni(void) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_cpuid_has_sse2(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_cpuid.c"
#endif
#endif
