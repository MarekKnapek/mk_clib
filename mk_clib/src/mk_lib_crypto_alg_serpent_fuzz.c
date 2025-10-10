#ifndef mk_include_guard_mk_lib_crypto_alg_serpent_fuzz_c
#define mk_include_guard_mk_lib_crypto_alg_serpent_fuzz_c
#include "mk_lib_crypto_alg_serpent_fuzz.h"

#include "mk_lang_alignas.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_serpent.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_alg_serpent_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t cpuida;
	mk_lang_types_uint_t cpuidb;
	mk_lib_crypto_alg_serpent_key_t key;
	mk_lang_types_uint_t nmsgs;
	mk_lang_alignas(64) mk_lib_crypto_alg_serpent_msg_t msgs_a[64];
	mk_lang_types_uint_t n;
	mk_lang_types_uint_t i;
	mk_lib_crypto_alg_serpent_schedule_t schedule;
	mk_lang_alignas(64) mk_lib_crypto_alg_serpent_msg_t msgs_b[64];
	mk_lang_alignas(64) mk_lib_crypto_alg_serpent_msg_t msgs_c[64];

	d = data;
	s = size;
	if(!(s >= 1)) return 0; cpuida = d[0] % 2 == 0; ++d; --s;
	if(!(s >= 1)) return 0; cpuidb = d[0] % 2 == 0; ++d; --s;
	if(!(s >= mk_lib_crypto_alg_serpent_key_len_v)) return 0; mk_sl_cui_uint8_from_bi_uchar_many(&key.m_data.m_uint8s[0], &d[0], mk_lib_crypto_alg_serpent_key_len_v); d += mk_lib_crypto_alg_serpent_key_len_v; s -= mk_lib_crypto_alg_serpent_key_len_v;
	nmsgs = ((mk_lang_types_uint_t)(s / mk_lib_crypto_alg_serpent_msg_len_v));
	if(nmsgs == 0) return 0;
	nmsgs = mk_lang_min(nmsgs, mk_lang_countof(msgs_a));
	n = nmsgs;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_uchar_many(&msgs_a[i].m_data.m_uint8s[i], &d[0], mk_lib_crypto_alg_serpent_msg_len_v); d += mk_lib_crypto_alg_serpent_msg_len_v; s -= mk_lib_crypto_alg_serpent_msg_len_v;
	}
	if(cpuida){ mk_lang_cpuid_init(); }else{ mk_lang_cpuid_reset(); }
	mk_lib_crypto_alg_serpent_expand_enc(&key, &schedule);
	mk_lib_crypto_alg_serpent_schedule_encrypt(&schedule, &msgs_a[0], &msgs_b[0], nmsgs);
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_alg_serpent_schedule_encrypt(&schedule, &msgs_a[i], &msgs_c[i], 1);
		mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&msgs_b[i].m_data.m_uint8s[0], &msgs_c[i].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v) == 0);
	}
	if(cpuidb){ mk_lang_cpuid_init(); }else{ mk_lang_cpuid_reset(); }
	mk_lib_crypto_alg_serpent_expand_dec(&key, &schedule);
	mk_lib_crypto_alg_serpent_schedule_decrypt(&schedule, &msgs_b[0], &msgs_c[0], nmsgs);
	for(i = 0; i != n; ++i)
	{
		mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&msgs_c[i].m_data.m_uint8s[0], &msgs_a[i].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v) == 0);
		mk_lib_crypto_alg_serpent_schedule_decrypt(&schedule, &msgs_b[i], &msgs_c[i], 1);
		mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&msgs_c[i].m_data.m_uint8s[0], &msgs_a[i].m_data.m_uint8s[0], mk_lib_crypto_alg_serpent_msg_len_v) == 0);
	}
	return 0;
}


#endif
