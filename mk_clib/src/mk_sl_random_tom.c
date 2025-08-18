#ifndef mk_include_guard_mk_sl_random_tom_c
#define mk_include_guard_mk_sl_random_tom_c
#include "mk_sl_random_tom.h"

#include "mk_lang_external_ltc.h"
#if mk_lang_external_ltc_have

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_random.h"


static mk_sl_random_tom_t mk_sl_random_tom_g;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_tom_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_t random_buf[40];
	mk_lang_types_sint_t st;

	err = mk_sl_random_generate(&random_buf[0], mk_lang_countof(random_buf)); mk_lang_check_rereturn(err);
	mk_sl_random_tom_g.m_tom_prng_idx = register_prng(&chacha20_prng_desc); mk_lang_check_return(mk_sl_random_tom_g.m_tom_prng_idx != -1);
	st = chacha20_prng_start(&mk_sl_random_tom_g.m_tom_prng_state); mk_lang_check_return(st == CRYPT_OK);
	st = chacha20_prng_add_entropy(((mk_lang_types_uchar_pct)(&random_buf[0])), mk_lang_countof(random_buf), &mk_sl_random_tom_g.m_tom_prng_state); mk_lang_check_return(st == CRYPT_OK);
	st = chacha20_prng_ready(&mk_sl_random_tom_g.m_tom_prng_state); mk_lang_check_return(st == CRYPT_OK);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_tom_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	chacha20_prng_done(&mk_sl_random_tom_g.m_tom_prng_state);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_random_tom_generate(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_lang_types_ulong_t cnt;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	cnt = chacha20_prng_read(((mk_lang_types_uchar_pt)(data_buf)), ((mk_lang_types_ulong_t)(data_len)), &mk_sl_random_tom_g.m_tom_prng_state); mk_lang_check_return(cnt == ((mk_lang_types_ulong_t)(data_len)));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_random_tom_pt mk_sl_random_tom_get_internal_state(mk_lang_types_void_t) mk_lang_noexcept
{
	return &mk_sl_random_tom_g;
}


#else
void mk_sl_random_tom_dummy(void);
void mk_sl_random_tom_dummy(void){}
#endif
#endif
