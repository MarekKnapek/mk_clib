#include "mk_lang_llong.h"
#include "mk_lang_static_assert.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint64.h"


static mk_lang_inline void mk_lib_crypto_alg_serpent_64_ui_and2(mk_sl_cui_uint64_pt const a, mk_sl_cui_uint64_pct const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint64_and2(a, b);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_ui_not1(mk_sl_cui_uint64_pt const a) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);

	mk_sl_cui_uint64_not1(a);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_ui_or2(mk_sl_cui_uint64_pt const a, mk_sl_cui_uint64_pct const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint64_or2(a, b);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_ui_rotl2(mk_sl_cui_uint64_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept
{
	mk_sl_cui_uint32_t tu32s[2];

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);

	mk_sl_uint_64_to_32_le(a, &tu32s[0]);
	mk_sl_cui_uint32_rotl2(&tu32s[0], b);
	mk_sl_cui_uint32_rotl2(&tu32s[1], b);
	mk_sl_uint_64_from_32_le(a, &tu32s[0]);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_ui_rotr2(mk_sl_cui_uint64_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept
{
	mk_sl_cui_uint32_t tu32s[2];

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);

	mk_sl_uint_64_to_32_le(a, &tu32s[0]);
	mk_sl_cui_uint32_rotr2(&tu32s[0], b);
	mk_sl_cui_uint32_rotr2(&tu32s[1], b);
	mk_sl_uint_64_from_32_le(a, &tu32s[0]);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_ui_shl3(mk_sl_cui_uint64_pct const a, mk_lang_types_sint_t const b, mk_sl_cui_uint64_pt const c) mk_lang_noexcept
{
	mk_sl_cui_uint32_t tu32s[2];

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b <= 31);
	mk_lang_assert(c);
	mk_lang_assert(a != c);

	mk_sl_uint_64_to_32_le(a, &tu32s[0]);
	mk_sl_cui_uint32_shl2(&tu32s[0], b);
	mk_sl_cui_uint32_shl2(&tu32s[1], b);
	mk_sl_uint_64_from_32_le(c, &tu32s[0]);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_ui_xor2(mk_sl_cui_uint64_pt const a, mk_sl_cui_uint64_pct const b) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_sl_cui_uint64_xor2(a, b);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_ui_xor3(mk_sl_cui_uint64_pct const a, mk_sl_cui_uint64_pct const b, mk_sl_cui_uint64_pt const c) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	mk_sl_cui_uint64_xor3(a, b, c);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_transpose_load(mk_sl_cui_uint64_pt const ta, mk_sl_cui_uint64_pt const tb, mk_sl_cui_uint64_pt const tc, mk_sl_cui_uint64_pt const td) mk_lang_noexcept
{
	mk_sl_cui_uint64_t a;
	mk_sl_cui_uint64_t b;
	mk_sl_cui_uint64_t tta;
	mk_sl_cui_uint64_t ttb;
	mk_sl_cui_uint64_t ttc;
	mk_sl_cui_uint64_t ttd;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tc != td);

	mk_sl_cui_uint64_shl3(ta, 32, &a);
	mk_sl_cui_uint64_shr2(&a, 32);
	mk_sl_cui_uint64_shl3(tc, 32, &b);
	mk_sl_cui_uint64_or3(&a, &b, &tta);
	mk_sl_cui_uint64_shr3(ta, 32, &a);
	mk_sl_cui_uint64_shr3(tc, 32, &b);
	mk_sl_cui_uint64_shl2(&b, 32);
	mk_sl_cui_uint64_or3(&a, &b, &ttb);
	mk_sl_cui_uint64_shl3(tb, 32, &a);
	mk_sl_cui_uint64_shr2(&a, 32);
	mk_sl_cui_uint64_shl3(td, 32, &b);
	mk_sl_cui_uint64_or3(&a, &b, &ttc);
	mk_sl_cui_uint64_shr3(tb, 32, &a);
	mk_sl_cui_uint64_shr3(td, 32, &b);
	mk_sl_cui_uint64_shl2(&b, 32);
	mk_sl_cui_uint64_or3(&a, &b, &ttd);
	*ta = tta;
	*tb = ttb;
	*tc = ttc;
	*td = ttd;
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_transpose_store(mk_sl_cui_uint64_pt const ta, mk_sl_cui_uint64_pt const tb, mk_sl_cui_uint64_pt const tc, mk_sl_cui_uint64_pt const td) mk_lang_noexcept
{
	mk_sl_cui_uint64_t a;
	mk_sl_cui_uint64_t b;
	mk_sl_cui_uint64_t tta;
	mk_sl_cui_uint64_t ttb;
	mk_sl_cui_uint64_t ttc;
	mk_sl_cui_uint64_t ttd;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tc != td);

	mk_sl_cui_uint64_shl3(ta, 32, &a);
	mk_sl_cui_uint64_shr2(&a, 32);
	mk_sl_cui_uint64_shl3(tb, 32, &b);
	mk_sl_cui_uint64_or3(&a, &b, &tta);
	mk_sl_cui_uint64_shl3(tc, 32, &a);
	mk_sl_cui_uint64_shr2(&a, 32);
	mk_sl_cui_uint64_shl3(td, 32, &b);
	mk_sl_cui_uint64_or3(&a, &b, &ttb);
	mk_sl_cui_uint64_shr3(ta, 32, &a);
	mk_sl_cui_uint64_shr3(tb, 32, &b);
	mk_sl_cui_uint64_shl2(&b, 32);
	mk_sl_cui_uint64_or3(&a, &b, &ttc);
	mk_sl_cui_uint64_shr3(tc, 32, &a);
	mk_sl_cui_uint64_shr3(td, 32, &b);
	mk_sl_cui_uint64_shl2(&b, 32);
	mk_sl_cui_uint64_or3(&a, &b, &ttd);
	*ta = tta;
	*tb = ttb;
	*tc = ttc;
	*td = ttd;
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_load(mk_lib_crypto_alg_serpent_msg_pct const msgs, mk_sl_cui_uint64_pt const ta, mk_sl_cui_uint64_pt const tb, mk_sl_cui_uint64_pt const tc, mk_sl_cui_uint64_pt const td) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tc != td);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_sl_cui_uint64_from_buis_uchar_le(ta, ((mk_lang_types_uchar_pct)(&msgs->m_data.m_uint8s[0 * 8])));
	mk_sl_cui_uint64_from_buis_uchar_le(tb, ((mk_lang_types_uchar_pct)(&msgs->m_data.m_uint8s[1 * 8])));
	mk_sl_cui_uint64_from_buis_uchar_le(tc, ((mk_lang_types_uchar_pct)(&msgs->m_data.m_uint8s[2 * 8])));
	mk_sl_cui_uint64_from_buis_uchar_le(td, ((mk_lang_types_uchar_pct)(&msgs->m_data.m_uint8s[3 * 8])));
	mk_lib_crypto_alg_serpent_64_transpose_load(ta, tb, tc, td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_store(mk_lib_crypto_alg_serpent_msg_pt const msgs, mk_sl_cui_uint64_pt const ta, mk_sl_cui_uint64_pt const tb, mk_sl_cui_uint64_pt const tc, mk_sl_cui_uint64_pt const td) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tc != td);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_transpose_store(ta, tb, tc, td);
	mk_sl_cui_uint64_to_buis_uchar_le(ta, ((mk_lang_types_uchar_pt)(&msgs->m_data.m_uint8s[0 * 8])));
	mk_sl_cui_uint64_to_buis_uchar_le(tb, ((mk_lang_types_uchar_pt)(&msgs->m_data.m_uint8s[1 * 8])));
	mk_sl_cui_uint64_to_buis_uchar_le(tc, ((mk_lang_types_uchar_pt)(&msgs->m_data.m_uint8s[2 * 8])));
	mk_sl_cui_uint64_to_buis_uchar_le(td, ((mk_lang_types_uchar_pt)(&msgs->m_data.m_uint8s[3 * 8])));
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_xor2(mk_lib_crypto_alg_serpent_msg_pt const a, mk_lib_crypto_alg_serpent_msg_pct const b) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ba;
	mk_sl_cui_uint64_t bb;
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert((((mk_lang_types_uintptr_t)(a)) & 0x7) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(b)) & 0x7) == 0);

	mk_sl_cui_uint64_from_buis_uchar_le(&ba, ((mk_lang_types_uchar_pct)(b)) + 0 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&bb, ((mk_lang_types_uchar_pct)(b)) + 1 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&ta, ((mk_lang_types_uchar_pct)(a)) + 0 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&tb, ((mk_lang_types_uchar_pct)(a)) + 1 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&tc, ((mk_lang_types_uchar_pct)(a)) + 2 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&td, ((mk_lang_types_uchar_pct)(a)) + 3 * 8);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &ba);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &bb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &ba);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &bb);
	mk_sl_cui_uint64_to_buis_uchar_le(&ta, ((mk_lang_types_uchar_pt)(a)) + 0 * 8);
	mk_sl_cui_uint64_to_buis_uchar_le(&tb, ((mk_lang_types_uchar_pt)(a)) + 1 * 8);
	mk_sl_cui_uint64_to_buis_uchar_le(&tc, ((mk_lang_types_uchar_pt)(a)) + 2 * 8);
	mk_sl_cui_uint64_to_buis_uchar_le(&td, ((mk_lang_types_uchar_pt)(a)) + 3 * 8);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_xor3(mk_lib_crypto_alg_serpent_msg_pct const a, mk_lib_crypto_alg_serpent_msg_pct const b, mk_lib_crypto_alg_serpent_msg_pt const c) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ba;
	mk_sl_cui_uint64_t bb;
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(b != c);
	mk_lang_assert((((mk_lang_types_uintptr_t)(a)) & 0x7) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(b)) & 0x7) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(c)) & 0x7) == 0);

	mk_sl_cui_uint64_from_buis_uchar_le(&ba, ((mk_lang_types_uchar_pct)(b)) + 0 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&bb, ((mk_lang_types_uchar_pct)(b)) + 1 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&ta, ((mk_lang_types_uchar_pct)(a)) + 0 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&tb, ((mk_lang_types_uchar_pct)(a)) + 1 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&tc, ((mk_lang_types_uchar_pct)(a)) + 2 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&td, ((mk_lang_types_uchar_pct)(a)) + 3 * 8);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &ba);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &bb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &ba);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &bb);
	mk_sl_cui_uint64_to_buis_uchar_le(&ta, ((mk_lang_types_uchar_pt)(c)) + 0 * 8);
	mk_sl_cui_uint64_to_buis_uchar_le(&tb, ((mk_lang_types_uchar_pt)(c)) + 1 * 8);
	mk_sl_cui_uint64_to_buis_uchar_le(&tc, ((mk_lang_types_uchar_pt)(c)) + 2 * 8);
	mk_sl_cui_uint64_to_buis_uchar_le(&td, ((mk_lang_types_uchar_pt)(c)) + 3 * 8);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_copy(mk_lib_crypto_alg_serpent_msg_pct const a, mk_lib_crypto_alg_serpent_msg_pct const b) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert((((mk_lang_types_uintptr_t)(a)) & 0x7) == 0);
	mk_lang_assert((((mk_lang_types_uintptr_t)(b)) & 0x7) == 0);

	if(a == b) return;
	mk_sl_cui_uint64_from_buis_uchar_le(&ta, ((mk_lang_types_uchar_pct)(a)) + 0 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&tb, ((mk_lang_types_uchar_pct)(a)) + 1 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&tc, ((mk_lang_types_uchar_pct)(a)) + 2 * 8);
	mk_sl_cui_uint64_from_buis_uchar_le(&td, ((mk_lang_types_uchar_pct)(a)) + 3 * 8);
	mk_sl_cui_uint64_to_buis_uchar_le(&ta, ((mk_lang_types_uchar_pt)(b)) + 0 * 8);
	mk_sl_cui_uint64_to_buis_uchar_le(&tb, ((mk_lang_types_uchar_pt)(b)) + 1 * 8);
	mk_sl_cui_uint64_to_buis_uchar_le(&tc, ((mk_lang_types_uchar_pt)(b)) + 2 * 8);
	mk_sl_cui_uint64_to_buis_uchar_le(&td, ((mk_lang_types_uchar_pt)(b)) + 3 * 8);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_enc_0(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta); te = tb;
	mk_lib_crypto_alg_serpent_64_ui_and2(&tb, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &ta); mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &te); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tc); mk_lib_crypto_alg_serpent_64_ui_or2(&tc, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &te); mk_lib_crypto_alg_serpent_64_ui_not1(&te);
	mk_lib_crypto_alg_serpent_64_ui_or2(&te, &tb);  mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &te); mk_lib_crypto_alg_serpent_64_ui_or2(&td, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_64_store(msgs, &tb, &te, &tc, &ta);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_enc_1(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_not1(&ta);      mk_lib_crypto_alg_serpent_64_ui_not1(&tc);
	te = ta;                                        mk_lib_crypto_alg_serpent_64_ui_and2(&ta, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &ta); mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tc); mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &te); mk_lib_crypto_alg_serpent_64_ui_or2(&te, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_64_ui_or2(&tc, &ta);
	mk_lib_crypto_alg_serpent_64_ui_and2(&tc, &te); mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tb);
	mk_lib_crypto_alg_serpent_64_ui_and2(&tb, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &ta); mk_lib_crypto_alg_serpent_64_ui_and2(&ta, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_64_store(msgs, &tc, &ta, &td, &tb);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_enc_2(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	te = ta;                                        mk_lib_crypto_alg_serpent_64_ui_and2(&ta, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &ta); mk_lib_crypto_alg_serpent_64_ui_or2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tb); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	tb = td;                                        mk_lib_crypto_alg_serpent_64_ui_or2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta); mk_lib_crypto_alg_serpent_64_ui_and2(&ta, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &te); mk_lib_crypto_alg_serpent_64_ui_not1(&te);
	mk_lib_crypto_alg_serpent_64_store(msgs, &tc, &td, &tb, &te);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_enc_3(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	te = ta;                                        mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tb); mk_lib_crypto_alg_serpent_64_ui_and2(&tb, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc); mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_and2(&td, &ta); mk_lib_crypto_alg_serpent_64_ui_or2(&te, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &te); mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tb);
	mk_lib_crypto_alg_serpent_64_ui_and2(&te, &ta); mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc); mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &tc); mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &td);
	tc = tb;                                        mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &ta);
	mk_lib_crypto_alg_serpent_64_store(msgs, &tb, &tc, &td, &te);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_enc_4(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_64_ui_not1(&td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta);
	te = tb;                                        mk_lib_crypto_alg_serpent_64_ui_and2(&tb, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &tc); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &te); mk_lib_crypto_alg_serpent_64_ui_and2(&tc, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &ta); mk_lib_crypto_alg_serpent_64_ui_and2(&ta, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta); mk_lib_crypto_alg_serpent_64_ui_or2(&te, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_64_ui_and2(&tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_not1(&ta);      mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_store(msgs, &tb, &te, &ta, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_enc_5(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tb); mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_64_ui_not1(&td);      te = tb;
	mk_lib_crypto_alg_serpent_64_ui_and2(&tb, &ta); mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &tc); mk_lib_crypto_alg_serpent_64_ui_or2(&tc, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &td); mk_lib_crypto_alg_serpent_64_ui_and2(&td, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc); mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &ta);
	mk_lib_crypto_alg_serpent_64_ui_and2(&ta, &td); mk_lib_crypto_alg_serpent_64_ui_not1(&tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &te); mk_lib_crypto_alg_serpent_64_ui_or2(&te, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &te);
	mk_lib_crypto_alg_serpent_64_store(msgs, &tb, &td, &ta, &tc);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_enc_6(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_not1(&tc);      te = td;
	mk_lib_crypto_alg_serpent_64_ui_and2(&td, &ta); mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tc); mk_lib_crypto_alg_serpent_64_ui_or2(&tc, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &ta);
	mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &tb);  mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_64_ui_not1(&td);
	mk_lib_crypto_alg_serpent_64_ui_and2(&tc, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &td);
	mk_lib_crypto_alg_serpent_64_store(msgs, &ta, &tb, &te, &tc);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_enc_7(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	te = tb;                                        mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &tb); mk_lib_crypto_alg_serpent_64_ui_or2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_and2(&td, &ta); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tb); mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &ta); mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &tb); mk_lib_crypto_alg_serpent_64_ui_and2(&tb, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &te); mk_lib_crypto_alg_serpent_64_ui_not1(&tc);
	mk_lib_crypto_alg_serpent_64_ui_or2(&tc, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_store(msgs, &te, &td, &tb, &ta);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_enc(int const sbox_idx, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(sbox_idx >= 0 && sbox_idx < 8);
	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	switch(sbox_idx)
	{
		case 0: mk_lib_crypto_alg_serpent_64_substitute_enc_0(msgs); break;
		case 1: mk_lib_crypto_alg_serpent_64_substitute_enc_1(msgs); break;
		case 2: mk_lib_crypto_alg_serpent_64_substitute_enc_2(msgs); break;
		case 3: mk_lib_crypto_alg_serpent_64_substitute_enc_3(msgs); break;
		case 4: mk_lib_crypto_alg_serpent_64_substitute_enc_4(msgs); break;
		case 5: mk_lib_crypto_alg_serpent_64_substitute_enc_5(msgs); break;
		case 6: mk_lib_crypto_alg_serpent_64_substitute_enc_6(msgs); break;
		case 7: mk_lib_crypto_alg_serpent_64_substitute_enc_7(msgs); break;
		default: mk_lang_assert(0); break;
	}
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_dec_0(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_not1(&tc);      te = tb;
	mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &ta);  mk_lib_crypto_alg_serpent_64_ui_not1(&te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &tc); mk_lib_crypto_alg_serpent_64_ui_or2(&tc, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &ta); mk_lib_crypto_alg_serpent_64_ui_and2(&ta, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &tb); mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_64_ui_and2(&tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_store(msgs, &ta, &te, &tb, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_dec_1(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	te = tb;                                        mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_64_ui_and2(&td, &tb); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta); mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &tc);  mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tb); mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &ta); mk_lib_crypto_alg_serpent_64_ui_not1(&te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tb); mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &ta);
	mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_64_store(msgs, &te, &ta, &td, &tc);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_dec_2(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta);
	te = td;                                        mk_lib_crypto_alg_serpent_64_ui_and2(&td, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tb); mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &te); mk_lib_crypto_alg_serpent_64_ui_and2(&te, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_64_ui_and2(&te, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc); mk_lib_crypto_alg_serpent_64_ui_and2(&tc, &tb);
	mk_lib_crypto_alg_serpent_64_ui_or2(&tc, &ta);  mk_lib_crypto_alg_serpent_64_ui_not1(&td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &td);
	mk_lib_crypto_alg_serpent_64_ui_and2(&ta, &tb); mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_64_store(msgs, &tb, &te, &tc, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_dec_3(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	te = tc;                                        mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_64_ui_and2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &ta); mk_lib_crypto_alg_serpent_64_ui_and2(&ta, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_64_ui_or2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &te); mk_lib_crypto_alg_serpent_64_ui_and2(&td, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tb); mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &ta);
	mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &tc);  mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tb);
	mk_lib_crypto_alg_serpent_64_store(msgs, &tc, &tb, &td, &ta);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_dec_4(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	te = tc;                                        mk_lib_crypto_alg_serpent_64_ui_and2(&tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &tb); mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &td);
	mk_lib_crypto_alg_serpent_64_ui_and2(&tb, &ta); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tb); mk_lib_crypto_alg_serpent_64_ui_and2(&tb, &tc);
	mk_lib_crypto_alg_serpent_64_ui_not1(&ta);      mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_64_ui_and2(&td, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tc); mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tb);
	mk_lib_crypto_alg_serpent_64_ui_and2(&tc, &ta); mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &te);
	mk_lib_crypto_alg_serpent_64_ui_or2(&tc, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &tb);
	mk_lib_crypto_alg_serpent_64_store(msgs, &ta, &td, &tc, &te);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_dec_5(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_not1(&tb);      te = td;
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &tb); mk_lib_crypto_alg_serpent_64_ui_or2(&td, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tc); mk_lib_crypto_alg_serpent_64_ui_or2(&tc, &tb);
	mk_lib_crypto_alg_serpent_64_ui_and2(&tc, &ta); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &te); mk_lib_crypto_alg_serpent_64_ui_or2(&te, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tb); mk_lib_crypto_alg_serpent_64_ui_and2(&tb, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_ui_and2(&td, &te); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &te); mk_lib_crypto_alg_serpent_64_ui_not1(&te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_64_store(msgs, &tb, &te, &td, &tc);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_dec_6(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tc); te = tc;
	mk_lib_crypto_alg_serpent_64_ui_and2(&tc, &ta); mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_64_ui_not1(&tc);      mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &td); mk_lib_crypto_alg_serpent_64_ui_or2(&te, &ta);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tc); mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tb); mk_lib_crypto_alg_serpent_64_ui_and2(&tb, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &ta); mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &td);
	mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &tc);  mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &ta);
	mk_lib_crypto_alg_serpent_64_store(msgs, &tb, &tc, &te, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_dec_7(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	te = tc;                                        mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &ta);
	mk_lib_crypto_alg_serpent_64_ui_and2(&ta, &td); mk_lib_crypto_alg_serpent_64_ui_or2(&te, &td);
	mk_lib_crypto_alg_serpent_64_ui_not1(&tc);      mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_64_ui_or2(&tb, &ta);  mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &tc);
	mk_lib_crypto_alg_serpent_64_ui_and2(&tc, &te); mk_lib_crypto_alg_serpent_64_ui_and2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &tc); mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &ta);
	mk_lib_crypto_alg_serpent_64_ui_or2(&ta, &tc);  mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tb);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &td); mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_or2(&te, &ta);  mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_store(msgs, &td, &ta, &tb, &te);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_substitute_dec(int const sbox_idx, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_llong_has);

	mk_lang_assert(sbox_idx >= 0 && sbox_idx < 8);
	mk_lang_assert(msgs);
	mk_lang_assert((((mk_lang_types_uintptr_t)(msgs)) & 0x7) == 0);

	switch(sbox_idx)
	{
		case 0: mk_lib_crypto_alg_serpent_64_substitute_dec_0(msgs); break;
		case 1: mk_lib_crypto_alg_serpent_64_substitute_dec_1(msgs); break;
		case 2: mk_lib_crypto_alg_serpent_64_substitute_dec_2(msgs); break;
		case 3: mk_lib_crypto_alg_serpent_64_substitute_dec_3(msgs); break;
		case 4: mk_lib_crypto_alg_serpent_64_substitute_dec_4(msgs); break;
		case 5: mk_lib_crypto_alg_serpent_64_substitute_dec_5(msgs); break;
		case 6: mk_lib_crypto_alg_serpent_64_substitute_dec_6(msgs); break;
		case 7: mk_lib_crypto_alg_serpent_64_substitute_dec_7(msgs); break;
		default: mk_lang_assert(0); break;
	}
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_lt_enc(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_rotl2(&ta, 13);
	mk_lib_crypto_alg_serpent_64_ui_rotl2(&tc, 3);
	mk_lib_crypto_alg_serpent_64_ui_xor3(&ta, &tc, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &te);
	mk_lib_crypto_alg_serpent_64_ui_shl3(&ta, 3, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_rotl2(&tb, 1);
	mk_lib_crypto_alg_serpent_64_ui_rotl2(&td, 7);
	mk_lib_crypto_alg_serpent_64_ui_xor3(&tb, &td, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_64_ui_shl3(&tb, 7, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &te);
	mk_lib_crypto_alg_serpent_64_ui_rotl2(&ta, 5);
	mk_lib_crypto_alg_serpent_64_ui_rotl2(&tc, 22);
	mk_lib_crypto_alg_serpent_64_store(msgs, &ta, &tb, &tc, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_round_middle_enc(mk_lib_crypto_alg_serpent_schedule_pct const schedule, int const rnd_idx, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(rnd_idx >= 0 && rnd_idx < mk_lib_crypto_alg_serpent_nr - 1);
	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_64_xor2(msgs, &schedule->m_data.m_msgs[rnd_idx]);
	mk_lib_crypto_alg_serpent_64_substitute_enc(rnd_idx % mk_lib_crypto_alg_serpent_sbox_count, msgs);
	mk_lib_crypto_alg_serpent_64_lt_enc(msgs);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_round_last_enc(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_64_xor2(msgs, &schedule->m_data.m_msgs[mk_lib_crypto_alg_serpent_nr - 1]);
	mk_lib_crypto_alg_serpent_64_substitute_enc((mk_lib_crypto_alg_serpent_nr - 1) % mk_lib_crypto_alg_serpent_sbox_count, msgs);
	mk_lib_crypto_alg_serpent_64_xor2(msgs, &schedule->m_data.m_msgs[mk_lib_crypto_alg_serpent_nr - 0]);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_lt_dec(mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta;
	mk_sl_cui_uint64_t tb;
	mk_sl_cui_uint64_t tc;
	mk_sl_cui_uint64_t td;
	mk_sl_cui_uint64_t te;

	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_64_load(msgs, &ta, &tb, &tc, &td);
	mk_lib_crypto_alg_serpent_64_ui_rotr2(&tc, 22);
	mk_lib_crypto_alg_serpent_64_ui_rotr2(&ta, 5);
	mk_lib_crypto_alg_serpent_64_ui_shl3(&tb, 7, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tc, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor3(&tb, &td, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_64_ui_rotr2(&td, 7);
	mk_lib_crypto_alg_serpent_64_ui_rotr2(&tb, 1);
	mk_lib_crypto_alg_serpent_64_ui_shl3(&ta, 3, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&td, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor3(&ta, &tc, &te);
	mk_lib_crypto_alg_serpent_64_ui_xor2(&tb, &te);
	mk_lib_crypto_alg_serpent_64_ui_rotr2(&tc, 3);
	mk_lib_crypto_alg_serpent_64_ui_rotr2(&ta, 13);
	mk_lib_crypto_alg_serpent_64_store(msgs, &ta, &tb, &tc, &td);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_round_first_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_serpent_64_xor3(input, &schedule->m_data.m_msgs[(mk_lib_crypto_alg_serpent_nr - 0)], output);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_round_middle_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, int const rnd_idx, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(rnd_idx >= 0 && rnd_idx < mk_lib_crypto_alg_serpent_nr - 1);
	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_64_substitute_dec(((mk_lib_crypto_alg_serpent_nr - 1) - rnd_idx) % mk_lib_crypto_alg_serpent_sbox_count, msgs);
	mk_lib_crypto_alg_serpent_64_xor2(msgs, &schedule->m_data.m_msgs[(mk_lib_crypto_alg_serpent_nr - 1) - rnd_idx]);
	mk_lib_crypto_alg_serpent_64_lt_dec(msgs);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_64_round_last_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pt const msgs) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(msgs);

	mk_lib_crypto_alg_serpent_64_substitute_dec(0 % mk_lib_crypto_alg_serpent_sbox_count, msgs);
	mk_lib_crypto_alg_serpent_64_xor2(msgs, &schedule->m_data.m_msgs[0]);
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_schedule_encrypt_64(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock;
	mk_lang_types_sint_t i;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks % 2 == 0);

	for(iblock = 0; iblock != nblocks; iblock += 2)
	{
		mk_lib_crypto_alg_serpent_64_copy(&input[iblock], &output[iblock]);
		for(i = 0; i != mk_lib_crypto_alg_serpent_nr - 1; ++i)
		{
			mk_lib_crypto_alg_serpent_64_round_middle_enc(schedule, i, &output[iblock]);
		}
		mk_lib_crypto_alg_serpent_64_round_last_enc(schedule, &output[iblock]);
	}
}

static mk_lang_inline void mk_lib_crypto_alg_serpent_schedule_decrypt_64(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock;
	mk_lang_types_sint_t i;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks % 2 == 0);

	for(iblock = 0; iblock != nblocks; iblock += 2)
	{
		mk_lib_crypto_alg_serpent_64_round_first_dec(schedule, &input[iblock], &output[iblock]);
		for(i = 0; i != mk_lib_crypto_alg_serpent_nr - 1; ++i)
		{
			mk_lib_crypto_alg_serpent_64_round_middle_dec(schedule, i, &output[iblock]);
		}
		mk_lib_crypto_alg_serpent_64_round_last_dec(schedule, &output[iblock]);
	}
}
