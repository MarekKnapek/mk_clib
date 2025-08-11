#ifndef mk_include_guard_mk_sl_random_tom_h
#define mk_include_guard_mk_sl_random_tom_h


#include "mk_lang_jumbo.h"
#include "mk_lang_external_ltc.h"
#if mk_lang_external_ltc_have


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_sl_random_tom_s
{
	prng_state m_tom_prng_state;
	mk_lang_types_sint_t m_tom_prng_idx;
};
typedef struct mk_sl_random_tom_s mk_sl_random_tom_t;
mk_lang_typedef(mk_sl_random_tom);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_tom_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_tom_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_tom_generate(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_sl_random_tom_pt mk_sl_random_tom_get_internal_state(mk_lang_types_void_t) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_sl_random_tom.c"
#endif
#endif
