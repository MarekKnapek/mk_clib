#include "mk_lib_crypto_serpent_fuzz.h"

#include "mk_lang_alignas.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_serpent.h"

#include <string.h> /* memcpy memcmp */


#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_crash(); } ((void)(0))
#define check_len(x) if(!(d && s >= (x))) { return; } ((void)(0))
#define advance(x) { d += (x); s -= (x); } ((void)(0))


mk_lang_jumbo void mk_lib_crypto_serpent_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t cpuida;
	mk_lang_types_uint_t cpuidb;
	mk_lang_types_sint_t i;
	mk_lib_crypto_alg_serpent_key_t key;
	mk_lang_types_uint_t nmsgs;
	mk_lang_alignas(64) mk_lib_crypto_alg_serpent_msg_t msgs[64];
	mk_lib_crypto_alg_serpent_schedule_t schedule;
	mk_lang_alignas(64) mk_lib_crypto_alg_serpent_msg_t cts[64];
	mk_lang_alignas(64) mk_lib_crypto_alg_serpent_msg_t pts[64];

	d = data;
	s = size;
	check_len(1); cpuida = d[0] % 2; advance(1);
	check_len(1); cpuidb = d[0] % 2; advance(1);
	check_len(mk_lib_crypto_alg_serpent_key_len_v); memcpy(&key, data, mk_lib_crypto_alg_serpent_key_len_v); advance(mk_lib_crypto_alg_serpent_key_len_v);
	nmsgs = size / mk_lib_crypto_alg_serpent_msg_len_v;
	if(nmsgs == 0) return;
	nmsgs = mk_lang_min(nmsgs, ((mk_lang_types_uint_t)(sizeof(msgs) / sizeof(msgs[0]))));
	memcpy(&msgs, data, nmsgs * mk_lib_crypto_alg_serpent_msg_len_v);
	mk_lib_crypto_alg_serpent_expand_enc(&key, &schedule);
	if(cpuida) mk_lang_cpuid_init(); else mk_lang_cpuid_reset();
	mk_lib_crypto_alg_serpent_schedule_encrypt(&schedule, &msgs[0], &cts[0], nmsgs);
	mk_lib_crypto_alg_serpent_expand_dec(&key, &schedule);
	if(cpuidb) mk_lang_cpuid_init(); else mk_lang_cpuid_reset();
	mk_lib_crypto_alg_serpent_schedule_decrypt(&schedule, &cts[0], &pts[0], nmsgs);
	test(memcmp(&pts, &msgs, nmsgs * mk_lib_crypto_alg_serpent_msg_len_v) == 0);
}


#undef test
#undef check_len
#undef advance
