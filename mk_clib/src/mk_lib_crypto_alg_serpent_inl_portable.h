mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_load(mk_lib_crypto_alg_serpent_msg_pct const msg, mk_sl_cui_uint32_pt const ta, mk_sl_cui_uint32_pt const tb, mk_sl_cui_uint32_pt const tc, mk_sl_cui_uint32_pt const td) mk_lang_noexcept
{
	mk_lang_assert(msg);
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

	mk_sl_uint_32_from_8_le(ta, &msg->m_data.m_uint8s[0 * 4]);
	mk_sl_uint_32_from_8_le(tb, &msg->m_data.m_uint8s[1 * 4]);
	mk_sl_uint_32_from_8_le(tc, &msg->m_data.m_uint8s[2 * 4]);
	mk_sl_uint_32_from_8_le(td, &msg->m_data.m_uint8s[3 * 4]);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_store(mk_lib_crypto_alg_serpent_msg_pt const msg, mk_sl_cui_uint32_pct const ta, mk_sl_cui_uint32_pct const tb, mk_sl_cui_uint32_pct const tc, mk_sl_cui_uint32_pct const td) mk_lang_noexcept
{
	mk_lang_assert(msg);
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

	mk_sl_uint_32_to_8_le(ta, &msg->m_data.m_uint8s[0 * 4]);
	mk_sl_uint_32_to_8_le(tb, &msg->m_data.m_uint8s[1 * 4]);
	mk_sl_uint_32_to_8_le(tc, &msg->m_data.m_uint8s[2 * 4]);
	mk_sl_uint_32_to_8_le(td, &msg->m_data.m_uint8s[3 * 4]);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_enc_0(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_xor2(&td, &ta); te = tb;
	mk_sl_cui_uint32_and2(&tb, &td); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&tb, &ta); mk_sl_cui_uint32_or2(&ta, &td);
	mk_sl_cui_uint32_xor2(&ta, &te); mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&td, &tc); mk_sl_cui_uint32_or2(&tc, &tb);
	mk_sl_cui_uint32_xor2(&tc, &te); mk_sl_cui_uint32_not1(&te);
	mk_sl_cui_uint32_or2(&te, &tb);  mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &te); mk_sl_cui_uint32_or2(&td, &ta);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_xor2(&te, &td);
	mk_lib_crypto_alg_serpent_portable_store(msg, &tb, &te, &tc, &ta);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_enc_1(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_not1(&ta);      mk_sl_cui_uint32_not1(&tc);
	te = ta;                         mk_sl_cui_uint32_and2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&tc, &ta); mk_sl_cui_uint32_or2(&ta, &td);
	mk_sl_cui_uint32_xor2(&td, &tc); mk_sl_cui_uint32_xor2(&tb, &ta);
	mk_sl_cui_uint32_xor2(&ta, &te); mk_sl_cui_uint32_or2(&te, &tb);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_or2(&tc, &ta);
	mk_sl_cui_uint32_and2(&tc, &te); mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_and2(&tb, &tc);
	mk_sl_cui_uint32_xor2(&tb, &ta); mk_sl_cui_uint32_and2(&ta, &tc);
	mk_sl_cui_uint32_xor2(&ta, &te);
	mk_lib_crypto_alg_serpent_portable_store(msg, &tc, &ta, &td, &tb);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_enc_2(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	te = ta;                         mk_sl_cui_uint32_and2(&ta, &tc);
	mk_sl_cui_uint32_xor2(&ta, &td); mk_sl_cui_uint32_xor2(&tc, &tb);
	mk_sl_cui_uint32_xor2(&tc, &ta); mk_sl_cui_uint32_or2(&td, &te);
	mk_sl_cui_uint32_xor2(&td, &tb); mk_sl_cui_uint32_xor2(&te, &tc);
	tb = td;                         mk_sl_cui_uint32_or2(&td, &te);
	mk_sl_cui_uint32_xor2(&td, &ta); mk_sl_cui_uint32_and2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &te); mk_sl_cui_uint32_not1(&te);
	mk_lib_crypto_alg_serpent_portable_store(msg, &tc, &td, &tb, &te);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_enc_3(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	te = ta;                         mk_sl_cui_uint32_or2(&ta, &td);
	mk_sl_cui_uint32_xor2(&td, &tb); mk_sl_cui_uint32_and2(&tb, &te);
	mk_sl_cui_uint32_xor2(&te, &tc); mk_sl_cui_uint32_xor2(&tc, &td);
	mk_sl_cui_uint32_and2(&td, &ta); mk_sl_cui_uint32_or2(&te, &tb);
	mk_sl_cui_uint32_xor2(&td, &te); mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_and2(&te, &ta); mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_xor2(&te, &tc); mk_sl_cui_uint32_or2(&tb, &ta);
	mk_sl_cui_uint32_xor2(&tb, &tc); mk_sl_cui_uint32_xor2(&ta, &td);
	tc = tb;                         mk_sl_cui_uint32_or2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &ta);
	mk_lib_crypto_alg_serpent_portable_store(msg, &tb, &tc, &td, &te);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_enc_4(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_not1(&td);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_xor2(&td, &ta);
	te = tb;                         mk_sl_cui_uint32_and2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &tc); mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&ta, &te); mk_sl_cui_uint32_and2(&tc, &te);
	mk_sl_cui_uint32_xor2(&tc, &ta); mk_sl_cui_uint32_and2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&td, &ta); mk_sl_cui_uint32_or2(&te, &tb);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_or2(&ta, &td);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_and2(&tc, &td);
	mk_sl_cui_uint32_not1(&ta);      mk_sl_cui_uint32_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_portable_store(msg, &tb, &te, &ta, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_enc_5(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_xor2(&ta, &tb); mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_not1(&td);      te = tb;
	mk_sl_cui_uint32_and2(&tb, &ta); mk_sl_cui_uint32_xor2(&tc, &td);
	mk_sl_cui_uint32_xor2(&tb, &tc); mk_sl_cui_uint32_or2(&tc, &te);
	mk_sl_cui_uint32_xor2(&te, &td); mk_sl_cui_uint32_and2(&td, &tb);
	mk_sl_cui_uint32_xor2(&td, &ta); mk_sl_cui_uint32_xor2(&te, &tb);
	mk_sl_cui_uint32_xor2(&te, &tc); mk_sl_cui_uint32_xor2(&tc, &ta);
	mk_sl_cui_uint32_and2(&ta, &td); mk_sl_cui_uint32_not1(&tc);
	mk_sl_cui_uint32_xor2(&ta, &te); mk_sl_cui_uint32_or2(&te, &td);
	mk_sl_cui_uint32_xor2(&tc, &te);
	mk_lib_crypto_alg_serpent_portable_store(msg, &tb, &td, &ta, &tc);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_enc_6(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_not1(&tc);      te = td;
	mk_sl_cui_uint32_and2(&td, &ta); mk_sl_cui_uint32_xor2(&ta, &te);
	mk_sl_cui_uint32_xor2(&td, &tc); mk_sl_cui_uint32_or2(&tc, &te);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_xor2(&tc, &ta);
	mk_sl_cui_uint32_or2(&ta, &tb);  mk_sl_cui_uint32_xor2(&tc, &tb);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_or2(&ta, &td);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_not1(&td);
	mk_sl_cui_uint32_and2(&tc, &te);
	mk_sl_cui_uint32_xor2(&tc, &td);
	mk_lib_crypto_alg_serpent_portable_store(msg, &ta, &tb, &te, &tc);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_enc_7(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	te = tb;                         mk_sl_cui_uint32_or2(&tb, &tc);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&tc, &tb); mk_sl_cui_uint32_or2(&td, &te);
	mk_sl_cui_uint32_and2(&td, &ta); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&td, &tb); mk_sl_cui_uint32_or2(&tb, &te);
	mk_sl_cui_uint32_xor2(&tb, &ta); mk_sl_cui_uint32_or2(&ta, &te);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_xor2(&tb, &te);
	mk_sl_cui_uint32_xor2(&tc, &tb); mk_sl_cui_uint32_and2(&tb, &ta);
	mk_sl_cui_uint32_xor2(&tb, &te); mk_sl_cui_uint32_not1(&tc);
	mk_sl_cui_uint32_or2(&tc, &ta);
	mk_sl_cui_uint32_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_portable_store(msg, &te, &td, &tb, &ta);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_enc(int const sbox_idx, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(sbox_idx >= 0 && sbox_idx < 8);
	mk_lang_assert(msg);

	switch(sbox_idx)
	{
		case 0: mk_lib_crypto_alg_serpent_portable_substitute_enc_0(msg); break;
		case 1: mk_lib_crypto_alg_serpent_portable_substitute_enc_1(msg); break;
		case 2: mk_lib_crypto_alg_serpent_portable_substitute_enc_2(msg); break;
		case 3: mk_lib_crypto_alg_serpent_portable_substitute_enc_3(msg); break;
		case 4: mk_lib_crypto_alg_serpent_portable_substitute_enc_4(msg); break;
		case 5: mk_lib_crypto_alg_serpent_portable_substitute_enc_5(msg); break;
		case 6: mk_lib_crypto_alg_serpent_portable_substitute_enc_6(msg); break;
		case 7: mk_lib_crypto_alg_serpent_portable_substitute_enc_7(msg); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_dec_0(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_not1(&tc);      te = tb;
	mk_sl_cui_uint32_or2(&tb, &ta);  mk_sl_cui_uint32_not1(&te);
	mk_sl_cui_uint32_xor2(&tb, &tc); mk_sl_cui_uint32_or2(&tc, &te);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_xor2(&ta, &te);
	mk_sl_cui_uint32_xor2(&tc, &ta); mk_sl_cui_uint32_and2(&ta, &td);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_or2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_xor2(&tc, &tb); mk_sl_cui_uint32_xor2(&td, &ta);
	mk_sl_cui_uint32_xor2(&td, &tb);
	mk_sl_cui_uint32_and2(&tc, &td);
	mk_sl_cui_uint32_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_portable_store(msg, &ta, &te, &tb, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_dec_1(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	te = tb;                         mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_and2(&td, &tb); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&td, &ta); mk_sl_cui_uint32_or2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_xor2(&ta, &te);
	mk_sl_cui_uint32_or2(&ta, &tc);  mk_sl_cui_uint32_xor2(&tb, &td);
	mk_sl_cui_uint32_xor2(&ta, &tb); mk_sl_cui_uint32_or2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &ta); mk_sl_cui_uint32_not1(&te);
	mk_sl_cui_uint32_xor2(&te, &tb); mk_sl_cui_uint32_or2(&tb, &ta);
	mk_sl_cui_uint32_xor2(&tb, &ta);
	mk_sl_cui_uint32_or2(&tb, &te);
	mk_sl_cui_uint32_xor2(&td, &tb);
	mk_lib_crypto_alg_serpent_portable_store(msg, &te, &ta, &td, &tc);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_dec_2(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_xor2(&td, &ta);
	te = td;                         mk_sl_cui_uint32_and2(&td, &tc);
	mk_sl_cui_uint32_xor2(&td, &tb); mk_sl_cui_uint32_or2(&tb, &tc);
	mk_sl_cui_uint32_xor2(&tb, &te); mk_sl_cui_uint32_and2(&te, &td);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_and2(&te, &ta);
	mk_sl_cui_uint32_xor2(&te, &tc); mk_sl_cui_uint32_and2(&tc, &tb);
	mk_sl_cui_uint32_or2(&tc, &ta);  mk_sl_cui_uint32_not1(&td);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_xor2(&ta, &td);
	mk_sl_cui_uint32_and2(&ta, &tb); mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_portable_store(msg, &tb, &te, &tc, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_dec_3(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	te = tc;                         mk_sl_cui_uint32_xor2(&tc, &tb);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_and2(&te, &tc);
	mk_sl_cui_uint32_xor2(&te, &ta); mk_sl_cui_uint32_and2(&ta, &tb);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_or2(&td, &te);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_xor2(&ta, &td);
	mk_sl_cui_uint32_xor2(&tb, &te); mk_sl_cui_uint32_and2(&td, &tc);
	mk_sl_cui_uint32_xor2(&td, &tb); mk_sl_cui_uint32_xor2(&tb, &ta);
	mk_sl_cui_uint32_or2(&tb, &tc);  mk_sl_cui_uint32_xor2(&ta, &td);
	mk_sl_cui_uint32_xor2(&tb, &te);
	mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_lib_crypto_alg_serpent_portable_store(msg, &tc, &tb, &td, &ta);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_dec_4(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	te = tc;                         mk_sl_cui_uint32_and2(&tc, &td);
	mk_sl_cui_uint32_xor2(&tc, &tb); mk_sl_cui_uint32_or2(&tb, &td);
	mk_sl_cui_uint32_and2(&tb, &ta); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&te, &tb); mk_sl_cui_uint32_and2(&tb, &tc);
	mk_sl_cui_uint32_not1(&ta);      mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_and2(&td, &ta);
	mk_sl_cui_uint32_xor2(&td, &tc); mk_sl_cui_uint32_xor2(&ta, &tb);
	mk_sl_cui_uint32_and2(&tc, &ta); mk_sl_cui_uint32_xor2(&td, &ta);
	mk_sl_cui_uint32_xor2(&tc, &te);
	mk_sl_cui_uint32_or2(&tc, &td); mk_sl_cui_uint32_xor2(&td, &ta);
	mk_sl_cui_uint32_xor2(&tc, &tb);
	mk_lib_crypto_alg_serpent_portable_store(msg, &ta, &td, &tc, &te);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_dec_5(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_not1(&tb);      te = td;
	mk_sl_cui_uint32_xor2(&tc, &tb); mk_sl_cui_uint32_or2(&td, &ta);
	mk_sl_cui_uint32_xor2(&td, &tc); mk_sl_cui_uint32_or2(&tc, &tb);
	mk_sl_cui_uint32_and2(&tc, &ta); mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&tc, &te); mk_sl_cui_uint32_or2(&te, &ta);
	mk_sl_cui_uint32_xor2(&te, &tb); mk_sl_cui_uint32_and2(&tb, &tc);
	mk_sl_cui_uint32_xor2(&tb, &td); mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_and2(&td, &te); mk_sl_cui_uint32_xor2(&te, &tb);
	mk_sl_cui_uint32_xor2(&td, &te); mk_sl_cui_uint32_not1(&te);
	mk_sl_cui_uint32_xor2(&td, &ta);
	mk_lib_crypto_alg_serpent_portable_store(msg, &tb, &te, &td, &tc);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_dec_6(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_xor2(&ta, &tc); te = tc;
	mk_sl_cui_uint32_and2(&tc, &ta); mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_not1(&tc);      mk_sl_cui_uint32_xor2(&td, &tb);
	mk_sl_cui_uint32_xor2(&tc, &td); mk_sl_cui_uint32_or2(&te, &ta);
	mk_sl_cui_uint32_xor2(&ta, &tc); mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_xor2(&te, &tb); mk_sl_cui_uint32_and2(&tb, &td);
	mk_sl_cui_uint32_xor2(&tb, &ta); mk_sl_cui_uint32_xor2(&ta, &td);
	mk_sl_cui_uint32_or2(&ta, &tc);  mk_sl_cui_uint32_xor2(&td, &tb);
	mk_sl_cui_uint32_xor2(&te, &ta);
	mk_lib_crypto_alg_serpent_portable_store(msg, &tb, &tc, &te, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_dec_7(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	te = tc;                         mk_sl_cui_uint32_xor2(&tc, &ta);
	mk_sl_cui_uint32_and2(&ta, &td); mk_sl_cui_uint32_or2(&te, &td);
	mk_sl_cui_uint32_not1(&tc);      mk_sl_cui_uint32_xor2(&td, &tb);
	mk_sl_cui_uint32_or2(&tb, &ta);  mk_sl_cui_uint32_xor2(&ta, &tc);
	mk_sl_cui_uint32_and2(&tc, &te); mk_sl_cui_uint32_and2(&td, &te);
	mk_sl_cui_uint32_xor2(&tb, &tc); mk_sl_cui_uint32_xor2(&tc, &ta);
	mk_sl_cui_uint32_or2(&ta, &tc);  mk_sl_cui_uint32_xor2(&te, &tb);
	mk_sl_cui_uint32_xor2(&ta, &td); mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_or2(&te, &ta);  mk_sl_cui_uint32_xor2(&td, &tc);
	mk_sl_cui_uint32_xor2(&te, &tc);
	mk_lib_crypto_alg_serpent_portable_store(msg, &td, &ta, &tb, &te);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_substitute_dec(int const sbox_idx, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(sbox_idx >= 0 && sbox_idx < 8);
	mk_lang_assert(msg);

	switch(sbox_idx)
	{
		case 0: mk_lib_crypto_alg_serpent_portable_substitute_dec_0(msg); break;
		case 1: mk_lib_crypto_alg_serpent_portable_substitute_dec_1(msg); break;
		case 2: mk_lib_crypto_alg_serpent_portable_substitute_dec_2(msg); break;
		case 3: mk_lib_crypto_alg_serpent_portable_substitute_dec_3(msg); break;
		case 4: mk_lib_crypto_alg_serpent_portable_substitute_dec_4(msg); break;
		case 5: mk_lib_crypto_alg_serpent_portable_substitute_dec_5(msg); break;
		case 6: mk_lib_crypto_alg_serpent_portable_substitute_dec_6(msg); break;
		case 7: mk_lib_crypto_alg_serpent_portable_substitute_dec_7(msg); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_lt_enc(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_rotl2(&ta, 13);
	mk_sl_cui_uint32_rotl2(&tc, 3);
	mk_sl_cui_uint32_xor3(&ta, &tc, &te);
	mk_sl_cui_uint32_xor2(&tb, &te);
	mk_sl_cui_uint32_shl3(&ta, 3, &te);
	mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_rotl2(&tb, 1);
	mk_sl_cui_uint32_rotl2(&td, 7);
	mk_sl_cui_uint32_xor3(&tb, &td, &te);
	mk_sl_cui_uint32_xor2(&ta, &te);
	mk_sl_cui_uint32_shl3(&tb, 7, &te);
	mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&tc, &te);
	mk_sl_cui_uint32_rotl2(&ta, 5);
	mk_sl_cui_uint32_rotl2(&tc, 22);
	mk_lib_crypto_alg_serpent_portable_store(msg, &ta, &tb, &tc, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_lt_dec(mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t td mk_lang_constexpr_init;
	mk_sl_cui_uint32_t te mk_lang_constexpr_init;

	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_load(msg, &ta, &tb, &tc, &td);
	mk_sl_cui_uint32_rotr2(&tc, 22);
	mk_sl_cui_uint32_rotr2(&ta, 5);
	mk_sl_cui_uint32_shl3(&tb, 7, &te);
	mk_sl_cui_uint32_xor2(&te, &td);
	mk_sl_cui_uint32_xor2(&tc, &te);
	mk_sl_cui_uint32_xor3(&tb, &td, &te);
	mk_sl_cui_uint32_xor2(&ta, &te);
	mk_sl_cui_uint32_rotr2(&td, 7);
	mk_sl_cui_uint32_rotr2(&tb, 1);
	mk_sl_cui_uint32_shl3(&ta, 3, &te);
	mk_sl_cui_uint32_xor2(&te, &tc);
	mk_sl_cui_uint32_xor2(&td, &te);
	mk_sl_cui_uint32_xor3(&ta, &tc, &te);
	mk_sl_cui_uint32_xor2(&tb, &te);
	mk_sl_cui_uint32_rotr2(&tc, 3);
	mk_sl_cui_uint32_rotr2(&ta, 13);
	mk_lib_crypto_alg_serpent_portable_store(msg, &ta, &tb, &tc, &td);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_round_middle_enc(mk_lib_crypto_alg_serpent_schedule_pct const schedule, int const rnd_idx, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(rnd_idx >= 0 && rnd_idx < mk_lib_crypto_alg_serpent_nr - 1);
	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_xor2(&msg->m_data.m_uint8s[0], &schedule->m_data.m_msgs[rnd_idx].m_data.m_uint8s[0]);
	mk_lib_crypto_alg_serpent_portable_substitute_enc(rnd_idx % mk_lib_crypto_alg_serpent_sbox_count, msg);
	mk_lib_crypto_alg_serpent_portable_lt_enc(msg);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_round_last_enc(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_xor2(&msg->m_data.m_uint8s[0], &schedule->m_data.m_msgs[mk_lib_crypto_alg_serpent_nr - 1].m_data.m_uint8s[0]);
	mk_lib_crypto_alg_serpent_portable_substitute_enc((mk_lib_crypto_alg_serpent_nr - 1) % mk_lib_crypto_alg_serpent_sbox_count, msg);
	mk_lib_crypto_alg_serpent_xor2(&msg->m_data.m_uint8s[0], &schedule->m_data.m_msgs[mk_lib_crypto_alg_serpent_nr - 0].m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_round_first_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_serpent_xor3(&input->m_data.m_uint8s[0], &schedule->m_data.m_msgs[mk_lib_crypto_alg_serpent_nr - 0].m_data.m_uint8s[0], &output->m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_round_middle_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, int const rnd_idx, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(rnd_idx >= 0 && rnd_idx < mk_lib_crypto_alg_serpent_nr - 1);
	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_substitute_dec(((mk_lib_crypto_alg_serpent_nr - 1) - rnd_idx) % mk_lib_crypto_alg_serpent_sbox_count, msg);
	mk_lib_crypto_alg_serpent_xor2(&msg->m_data.m_uint8s[0], &schedule->m_data.m_msgs[((mk_lib_crypto_alg_serpent_nr - 1)) - rnd_idx].m_data.m_uint8s[0]);
	mk_lib_crypto_alg_serpent_portable_lt_dec(msg);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_portable_round_last_dec(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pt const msg) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(msg);

	mk_lib_crypto_alg_serpent_portable_substitute_dec(0 % mk_lib_crypto_alg_serpent_sbox_count, msg);
	mk_lib_crypto_alg_serpent_xor2(&msg->m_data.m_uint8s[0], &schedule->m_data.m_msgs[0].m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_schedule_encrypt_portable(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		output[iblock] = input[iblock];
		for(i = 0; i != mk_lib_crypto_alg_serpent_nr - 1; ++i)
		{
			mk_lib_crypto_alg_serpent_portable_round_middle_enc(schedule, i, &output[iblock]);
		}
		mk_lib_crypto_alg_serpent_portable_round_last_enc(schedule, &output[iblock]);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_serpent_schedule_decrypt_portable(mk_lib_crypto_alg_serpent_schedule_pct const schedule, mk_lib_crypto_alg_serpent_msg_pct const input, mk_lib_crypto_alg_serpent_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_alg_serpent_portable_round_first_dec(schedule, &input[iblock], &output[iblock]);
		for(i = 0; i != mk_lib_crypto_alg_serpent_nr - 1; ++i)
		{
			mk_lib_crypto_alg_serpent_portable_round_middle_dec(schedule, i, &output[iblock]);
		}
		mk_lib_crypto_alg_serpent_portable_round_last_dec(schedule, &output[iblock]);
	}
}
