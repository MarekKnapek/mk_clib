#ifndef mk_include_guard_mk_lang_typedef_h
#define mk_include_guard_mk_lang_typedef_h


#include "mk_lang_bitness.h"
#include "mk_lang_concat.h"
#include "mk_lang_platform.h"
#include "mk_lang_restrict.h"


#if mk_lang_bitness == mk_lang_bitness_16 && mk_lang_platform_is_windows_at_least_any
#define mk_lang_typedef_far __far
#define mk_lang_typedef_near __near
#else
#define mk_lang_typedef_far
#define mk_lang_typedef_near
#endif


#define mk_lang_typedef_next_a(a, b) \
	typedef a##_##b const a##_c##b; \
	typedef a##_##b volatile a##_v##b; \
	typedef a##_##b const volatile a##_cv##b; \
	typedef a##_##b* a##_p##b; \
	typedef a##_##b const* a##_pc##b; \
	typedef a##_##b volatile* a##_pv##b; \
	typedef a##_##b const volatile* a##_pcv##b; \
	typedef a##_##b* mk_lang_restrict a##_pr##b; \
	typedef a##_##b const* mk_lang_restrict a##_prc##b; \
	typedef a##_##b volatile* mk_lang_restrict a##_prv##b; \
	typedef a##_##b const volatile* mk_lang_restrict a##_prcv##b; \
	typedef a##_##b mk_lang_typedef_far* a##_lp##b; \
	typedef a##_##b const mk_lang_typedef_far* a##_lpc##b; \
	typedef a##_##b volatile mk_lang_typedef_far* a##_lpv##b; \
	typedef a##_##b const volatile mk_lang_typedef_far* a##_lpcv##b; \
	typedef a##_##b mk_lang_typedef_far* mk_lang_restrict a##_lpr##b; \
	typedef a##_##b const mk_lang_typedef_far* mk_lang_restrict a##_lprc##b; \
	typedef a##_##b volatile mk_lang_typedef_far* mk_lang_restrict a##_lprv##b; \
	typedef a##_##b const volatile mk_lang_typedef_far* mk_lang_restrict a##_lprcv##b; \
	typedef a##_##b mk_lang_typedef_near* a##_np##b; \
	typedef a##_##b const mk_lang_typedef_near* a##_npc##b; \
	typedef a##_##b volatile mk_lang_typedef_near* a##_npv##b; \
	typedef a##_##b const volatile mk_lang_typedef_near* a##_npcv##b; \
	typedef a##_##b mk_lang_typedef_near* mk_lang_restrict a##_npr##b; \
	typedef a##_##b const mk_lang_typedef_near* mk_lang_restrict a##_nprc##b; \
	typedef a##_##b volatile mk_lang_typedef_near* mk_lang_restrict a##_nprv##b; \
	typedef a##_##b const volatile mk_lang_typedef_near* mk_lang_restrict a##_nprcv##b \

#define mk_lang_typedef(x) \
	mk_lang_typedef_next_a(x, t)

#define mk_lang_forward(x) \
	struct x##_s; \
	typedef struct x##_s x##_t; \
	mk_lang_typedef(x);


#endif
