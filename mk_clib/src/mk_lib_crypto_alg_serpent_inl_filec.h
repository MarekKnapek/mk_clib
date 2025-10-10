#include "mk_lang_assert.h"
#include "mk_lang_flatten.h"
#include "mk_lang_forceinline.h"
#include "mk_lang_inline.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_serpent_base.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_uint_convert.h"


#include "mk_lib_crypto_alg_serpent_inl_defd.h"


typedef mk_lib_crypto_alg_serpent_inl_defd_type mk_lib_crypto_alg_serpent_inl_defd_type_t;
typedef mk_lib_crypto_alg_serpent_inl_defd_type_t* mk_lib_crypto_alg_serpent_inl_defd_type_pt;
typedef mk_lib_crypto_alg_serpent_inl_defd_type* mk_lang_restrict mk_lib_crypto_alg_serpent_inl_defd_type_prt;
typedef mk_lib_crypto_alg_serpent_inl_defd_type const* mk_lang_restrict mk_lib_crypto_alg_serpent_inl_defd_type_prct;
typedef mk_lib_crypto_alg_serpent_inl_defd_type* mk_lang_restrict* mk_lang_restrict mk_lib_crypto_alg_serpent_inl_defd_type_prprt;


mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_lload(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_ct, msgs, mk_lib_crypto_alg_serpent_inl_defd_cnt), mk_lib_crypto_alg_serpent_inl_defd_type_prt const a, mk_lib_crypto_alg_serpent_inl_defd_type_prt const b, mk_lib_crypto_alg_serpent_inl_defd_type_prt const c, mk_lib_crypto_alg_serpent_inl_defd_type_prt const d) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(msgs);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	mk_lib_crypto_alg_serpent_inl_defd_load(msgs, a, b, c, d);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_sstore(mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_t, msgs, mk_lib_crypto_alg_serpent_inl_defd_cnt), mk_lib_crypto_alg_serpent_inl_defd_type_prt const a, mk_lib_crypto_alg_serpent_inl_defd_type_prt const b, mk_lib_crypto_alg_serpent_inl_defd_type_prt const c, mk_lib_crypto_alg_serpent_inl_defd_type_prt const d) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(msgs);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	mk_lib_crypto_alg_serpent_inl_defd_store(msgs, a, b, c, d);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_xor_rk_single(mk_lib_crypto_alg_serpent_base_msg_pct const schedule, mk_lang_types_sint_t const idx, mk_lib_crypto_alg_serpent_inl_defd_type_prt const x) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_inl_defd_uints_t sch_sml mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_t sch_big mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(idx >= 0);
	mk_lang_assert(idx <= 3);
	mk_lang_assert(x);

	mk_sl_uint_convert_32_8_le_to_big(&sch_sml.m_data.m_uint32s[0], &schedule->m_data.m_uint8s[idx * mk_sl_cui_uint32_size_bytes_v]);
	mk_lib_crypto_alg_serpent_inl_defd_ui_broadcast(&sch_big, &sch_sml);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(x, &sch_big);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(mk_lib_crypto_alg_serpent_base_msg_pct const schedule, mk_lib_crypto_alg_serpent_inl_defd_type_prt const a, mk_lib_crypto_alg_serpent_inl_defd_type_prt const b, mk_lib_crypto_alg_serpent_inl_defd_type_prt const c, mk_lib_crypto_alg_serpent_inl_defd_type_prt const d) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(schedule);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);

	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_single(schedule, 0, a);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_single(schedule, 1, b);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_single(schedule, 2, c);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_single(schedule, 3, d);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_swaparoo(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const da, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const db, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const dc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const dd, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const de, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const sa, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const sb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const sc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const sd, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const se) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_inl_defd_type_pt tta mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt ttb mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt ttc mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt ttd mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt tte mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;

	mk_lang_assert(da);
	mk_lang_assert(db);
	mk_lang_assert(dc);
	mk_lang_assert(dd);
	mk_lang_assert(de);
	mk_lang_assert(da != db);
	mk_lang_assert(da != dc);
	mk_lang_assert(da != dd);
	mk_lang_assert(da != de);
	mk_lang_assert(db != dc);
	mk_lang_assert(db != dd);
	mk_lang_assert(db != de);
	mk_lang_assert(dc != dd);
	mk_lang_assert(dc != de);
	mk_lang_assert(dd != de);
	mk_lang_assert(*da);
	mk_lang_assert(*db);
	mk_lang_assert(*dc);
	mk_lang_assert(*dd);
	mk_lang_assert(*de);
	mk_lang_assert(*da != *db);
	mk_lang_assert(*da != *dc);
	mk_lang_assert(*da != *dd);
	mk_lang_assert(*da != *de);
	mk_lang_assert(*db != *dc);
	mk_lang_assert(*db != *dd);
	mk_lang_assert(*db != *de);
	mk_lang_assert(*dc != *dd);
	mk_lang_assert(*dc != *de);
	mk_lang_assert(*dd != *de);
	mk_lang_assert(sa);
	mk_lang_assert(sb);
	mk_lang_assert(sc);
	mk_lang_assert(sd);
	mk_lang_assert(se);
	mk_lang_assert(sa != sb);
	mk_lang_assert(sa != sc);
	mk_lang_assert(sa != sd);
	mk_lang_assert(sa != se);
	mk_lang_assert(sb != sc);
	mk_lang_assert(sb != sd);
	mk_lang_assert(sb != se);
	mk_lang_assert(sc != sd);
	mk_lang_assert(sc != se);
	mk_lang_assert(sd != se);
	mk_lang_assert(*sa);
	mk_lang_assert(*sb);
	mk_lang_assert(*sc);
	mk_lang_assert(*sd);
	mk_lang_assert(*se);
	mk_lang_assert(*sa != *sb);
	mk_lang_assert(*sa != *sc);
	mk_lang_assert(*sa != *sd);
	mk_lang_assert(*sa != *se);
	mk_lang_assert(*sb != *sc);
	mk_lang_assert(*sb != *sd);
	mk_lang_assert(*sb != *se);
	mk_lang_assert(*sc != *sd);
	mk_lang_assert(*sc != *se);
	mk_lang_assert(*sd != *se);

	tta = *sa;
	ttb = *sb;
	ttc = *sc;
	ttd = *sd;
	tte = *se;
	*da = tta;
	*db = ttb;
	*dc = ttc;
	*dd = ttd;
	*de = tte;
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_enc_lt(mk_lib_crypto_alg_serpent_inl_defd_type_prt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_rotl2(ta, 13);
	mk_lib_crypto_alg_serpent_inl_defd_ui_rotl2(tc, 3);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor3 (ta, tc, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (tb, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_shl3 (ta, 3, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (te, tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (td, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_rotl2(tb, 1);
	mk_lib_crypto_alg_serpent_inl_defd_ui_rotl2(td, 7);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor3 (tb, td, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (ta, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_shl3 (tb, 7, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (te, td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (tc, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_rotl2(ta, 5);
	mk_lib_crypto_alg_serpent_inl_defd_ui_rotl2(tc, 22);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_dec_lt(mk_lib_crypto_alg_serpent_inl_defd_type_prt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_rotr2(tc, 22);
	mk_lib_crypto_alg_serpent_inl_defd_ui_rotr2(ta, 5);
	mk_lib_crypto_alg_serpent_inl_defd_ui_shl3 (tb, 7, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (te, td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (tc, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor3 (tb, td, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (ta, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_rotr2(td, 7);
	mk_lib_crypto_alg_serpent_inl_defd_ui_rotr2(tb, 1);
	mk_lib_crypto_alg_serpent_inl_defd_ui_shl3 (ta, 3, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (te, tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (td, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor3 (ta, tc, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2 (tb, te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_rotr2(tc, 3);
	mk_lib_crypto_alg_serpent_inl_defd_ui_rotr2(ta, 13);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_enc_0(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);
	mk_lang_assert(*ta);
	mk_lang_assert(*tb);
	mk_lang_assert(*tc);
	mk_lang_assert(*td);
	mk_lang_assert(*te);
	mk_lang_assert(*ta != *tb);
	mk_lang_assert(*ta != *tc);
	mk_lang_assert(*ta != *td);
	mk_lang_assert(*ta != *te);
	mk_lang_assert(*tb != *tc);
	mk_lang_assert(*tb != *td);
	mk_lang_assert(*tb != *te);
	mk_lang_assert(*tc != *td);
	mk_lang_assert(*tc != *te);
	mk_lang_assert(*td != *te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tb, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*ta, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*tc, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_not1  (*te    );
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*te, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*td, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *td);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, tb, te, tc, ta, td);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_enc_1(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);
	mk_lang_assert(*ta);
	mk_lang_assert(*tb);
	mk_lang_assert(*tc);
	mk_lang_assert(*td);
	mk_lang_assert(*te);
	mk_lang_assert(*ta != *tb);
	mk_lang_assert(*ta != *tc);
	mk_lang_assert(*ta != *td);
	mk_lang_assert(*ta != *te);
	mk_lang_assert(*tb != *tc);
	mk_lang_assert(*tb != *td);
	mk_lang_assert(*tb != *te);
	mk_lang_assert(*tc != *td);
	mk_lang_assert(*tc != *te);
	mk_lang_assert(*td != *te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_not1  (*ta     ); mk_lib_crypto_alg_serpent_inl_defd_ui_not1(*tc     );
	mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*ta, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*ta, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*te, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*tc, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*tc, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*tb, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*ta, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *te);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, tc, ta, td, tb, te);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_enc_2(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);
	mk_lang_assert(*ta);
	mk_lang_assert(*tb);
	mk_lang_assert(*tc);
	mk_lang_assert(*td);
	mk_lang_assert(*te);
	mk_lang_assert(*ta != *tb);
	mk_lang_assert(*ta != *tc);
	mk_lang_assert(*ta != *td);
	mk_lang_assert(*ta != *te);
	mk_lang_assert(*tb != *tc);
	mk_lang_assert(*tb != *td);
	mk_lang_assert(*tb != *te);
	mk_lang_assert(*tc != *td);
	mk_lang_assert(*tc != *te);
	mk_lang_assert(*td != *te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*ta, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*td, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*tb, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*td, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*ta, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_not1(*te     );
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, tc, td, tb, te, ta);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_enc_3(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);
	mk_lang_assert(*ta);
	mk_lang_assert(*tb);
	mk_lang_assert(*tc);
	mk_lang_assert(*td);
	mk_lang_assert(*te);
	mk_lang_assert(*ta != *tb);
	mk_lang_assert(*ta != *tc);
	mk_lang_assert(*ta != *td);
	mk_lang_assert(*ta != *te);
	mk_lang_assert(*tb != *tc);
	mk_lang_assert(*tb != *td);
	mk_lang_assert(*tb != *te);
	mk_lang_assert(*tc != *td);
	mk_lang_assert(*tc != *te);
	mk_lang_assert(*td != *te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*ta, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tb, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*td, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*te, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*te, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*tb, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*tc, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*tb, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, tb, tc, td, te, ta);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_enc_4(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);
	mk_lang_assert(*ta);
	mk_lang_assert(*tb);
	mk_lang_assert(*tc);
	mk_lang_assert(*td);
	mk_lang_assert(*te);
	mk_lang_assert(*ta != *tb);
	mk_lang_assert(*ta != *tc);
	mk_lang_assert(*ta != *td);
	mk_lang_assert(*ta != *te);
	mk_lang_assert(*tb != *tc);
	mk_lang_assert(*tb != *td);
	mk_lang_assert(*tb != *te);
	mk_lang_assert(*tc != *td);
	mk_lang_assert(*tc != *te);
	mk_lang_assert(*td != *te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_not1(*td     );
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tb, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tc, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*ta, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*te, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*ta, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tc, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_not1  (*ta     ); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, tb, te, ta, td, tc);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_enc_5(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);
	mk_lang_assert(*ta);
	mk_lang_assert(*tb);
	mk_lang_assert(*tc);
	mk_lang_assert(*td);
	mk_lang_assert(*te);
	mk_lang_assert(*ta != *tb);
	mk_lang_assert(*ta != *tc);
	mk_lang_assert(*ta != *td);
	mk_lang_assert(*ta != *te);
	mk_lang_assert(*tb != *tc);
	mk_lang_assert(*tb != *td);
	mk_lang_assert(*tb != *te);
	mk_lang_assert(*tc != *td);
	mk_lang_assert(*tc != *te);
	mk_lang_assert(*td != *te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_not1(*td);      mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tb, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*tc, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*td, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*ta, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_not1  (*tc     );
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*te, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *te);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, tb, td, ta, tc, te);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_enc_6(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);
	mk_lang_assert(*ta);
	mk_lang_assert(*tb);
	mk_lang_assert(*tc);
	mk_lang_assert(*td);
	mk_lang_assert(*te);
	mk_lang_assert(*ta != *tb);
	mk_lang_assert(*ta != *tc);
	mk_lang_assert(*ta != *td);
	mk_lang_assert(*ta != *te);
	mk_lang_assert(*tb != *tc);
	mk_lang_assert(*tb != *td);
	mk_lang_assert(*tb != *te);
	mk_lang_assert(*tc != *td);
	mk_lang_assert(*tc != *te);
	mk_lang_assert(*td != *te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_not1(*tc     ); mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*td, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*tc, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*ta, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*ta, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_not1  (*td     );
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tc, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *td);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, ta, tb, te, tc, td);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_enc_7(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);
	mk_lang_assert(*ta);
	mk_lang_assert(*tb);
	mk_lang_assert(*tc);
	mk_lang_assert(*td);
	mk_lang_assert(*te);
	mk_lang_assert(*ta != *tb);
	mk_lang_assert(*ta != *tc);
	mk_lang_assert(*ta != *td);
	mk_lang_assert(*ta != *te);
	mk_lang_assert(*tb != *tc);
	mk_lang_assert(*tb != *td);
	mk_lang_assert(*tb != *te);
	mk_lang_assert(*tc != *td);
	mk_lang_assert(*tc != *te);
	mk_lang_assert(*td != *te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*tb, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*td, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*td, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*tb, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*ta, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tb, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_not1(*tc     );
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*tc, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, te, td, tb, ta, tc);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_dec_0(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_not1(*tc     ); mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*tb, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_not1  (*te     );
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*tc, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*ta, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*ta, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tc, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, ta, te, tb, td, tc);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_dec_1(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_assign (*te, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2   (*td, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2   (*td, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*ta, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2   (*tc, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2    (*ta, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2   (*ta, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*tb, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2   (*tb, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_not1(*te     );
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2   (*te, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*tb, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*tb, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, te, ta, td, tc, tb);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_dec_2(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*td, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*tb, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*te, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*te, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tc, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*tc, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_not1(*td     );
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*ta, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, tb, te, tc, td, ta);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_dec_3(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*ta, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*td, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*td, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*tb, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, tc, tb, td, ta, te);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_dec_4(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tc, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*tb, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*tb, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tb, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_not1  (*ta     ); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*td, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*tc, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*tc, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tc, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, ta, td, tc, te, tb);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_dec_5(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_not1(*tb     ); mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*td, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*tc, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tc, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*te, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*tb, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*td, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_not1  (*te     );
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, tb, te, td, tc, ta);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_dec_6(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*tc, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_not1(*tc     ); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*te, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *tb); mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*tb, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tb, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*ta, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*td, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, tb, tc, te, td, ta);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_dec_7(mk_lib_crypto_alg_serpent_inl_defd_type_prprt const ta, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tb, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const tc, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const td, mk_lib_crypto_alg_serpent_inl_defd_type_prprt const te) mk_lang_noexcept { mk_lang_flatten
{
	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);
	mk_lang_assert(td);
	mk_lang_assert(te);
	mk_lang_assert(ta != tb);
	mk_lang_assert(ta != tc);
	mk_lang_assert(ta != td);
	mk_lang_assert(ta != te);
	mk_lang_assert(tb != tc);
	mk_lang_assert(tb != td);
	mk_lang_assert(tb != te);
	mk_lang_assert(tc != td);
	mk_lang_assert(tc != te);
	mk_lang_assert(td != te);

	mk_lib_crypto_alg_serpent_inl_defd_ui_assign(*te, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*ta, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_or2 (*te, *td);
	mk_lib_crypto_alg_serpent_inl_defd_ui_not1  (*tc     ); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*tb, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*ta, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_and2  (*tc, *te); mk_lib_crypto_alg_serpent_inl_defd_ui_and2(*td, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*tb, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*tc, *ta);
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*ta, *tc); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*te, *tb);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*ta, *td); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *te);
	mk_lib_crypto_alg_serpent_inl_defd_ui_or2   (*te, *ta); mk_lib_crypto_alg_serpent_inl_defd_ui_xor2(*td, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_ui_xor2  (*te, *tc);
	mk_lib_crypto_alg_serpent_inl_defd_swaparoo(ta, tb, tc, td, te, td, ta, tb, te, tc);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_encrypt_once(mk_lib_crypto_alg_serpent_base_schedule_pct const schedule, mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_ct, input, mk_lib_crypto_alg_serpent_inl_defd_cnt), mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_t, output, mk_lib_crypto_alg_serpent_inl_defd_cnt)) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_inl_defd_type_t ta mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_t tb mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_t tc mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_t td mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_t te mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt pta mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt ptb mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt ptc mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt ptd mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt pte mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	pta = &ta;
	ptb = &tb;
	ptc = &tc;
	ptd = &td;
	pte = &te;
	mk_lib_crypto_alg_serpent_inl_defd_lload(input, pta, ptb, ptc, ptd);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 0], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 1], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 2], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 3], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 4], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 5], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 6], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 7], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 8], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 9], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[10], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[11], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[12], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[13], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[14], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[15], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[16], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[17], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[18], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[19], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[20], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[21], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[22], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[23], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[24], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[25], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[26], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[27], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[28], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[29], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[30], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_enc_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[31], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_enc_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[32], pta, ptb, ptc, ptd);
	mk_lib_crypto_alg_serpent_inl_defd_sstore(output, pta, ptb, ptc, ptd);
}}

mk_lang_forceinline mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_decrypt_once(mk_lib_crypto_alg_serpent_base_schedule_pct const schedule, mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_ct, input, mk_lib_crypto_alg_serpent_inl_defd_cnt), mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_t, output, mk_lib_crypto_alg_serpent_inl_defd_cnt)) mk_lang_noexcept { mk_lang_flatten
{
	mk_lib_crypto_alg_serpent_inl_defd_type_t ta mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_t tb mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_t tc mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_t td mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_t te mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt pta mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt ptb mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt ptc mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt ptd mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lib_crypto_alg_serpent_inl_defd_type_pt pte mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	pta = &ta;
	ptb = &tb;
	ptc = &tc;
	ptd = &td;
	pte = &te;
	mk_lib_crypto_alg_serpent_inl_defd_lload(input, pta, ptb, ptc, ptd);
	mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[32], pta, ptb, ptc, ptd);
	mk_lib_crypto_alg_serpent_inl_defd_dec_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[31], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[30], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[29], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[28], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[27], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[26], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[25], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[24], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[23], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[22], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[21], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[20], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[19], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[18], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[17], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[16], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[15], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[14], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[13], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[12], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[11], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[10], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 9], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 8], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_7(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 7], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_6(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 6], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_5(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 5], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_4(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 4], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_3(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 3], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_2(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 2], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_1(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 1], pta, ptb, ptc, ptd); mk_lib_crypto_alg_serpent_inl_defd_dec_lt(pta, ptb, ptc, ptd, pte);
	mk_lib_crypto_alg_serpent_inl_defd_dec_0(&pta, &ptb, &ptc, &ptd, &pte); mk_lib_crypto_alg_serpent_inl_defd_xor_rk_multi(&schedule->m_data.m_msgs[ 0], pta, ptb, ptc, ptd);
	mk_lib_crypto_alg_serpent_inl_defd_sstore(output, pta, ptb, ptc, ptd);
}}

mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_encrypt_blocks(mk_lib_crypto_alg_serpent_base_schedule_pct const schedule, mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_ct, input, mk_lib_crypto_alg_serpent_inl_defd_cnt), mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_t, output, mk_lib_crypto_alg_serpent_inl_defd_cnt), mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lang_types_usize_t i mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_base_msg_len_d);
	mk_lang_assert(count % mk_lib_crypto_alg_serpent_inl_defd_cnt == 0);
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; i += mk_lib_crypto_alg_serpent_inl_defd_cnt)
	{
		mk_lib_crypto_alg_serpent_inl_defd_encrypt_once(schedule, &input[i], &output[i]);
	}
}

mk_lib_crypto_alg_serpent_inl_defd_constexpr_spec mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_serpent_target mk_lib_crypto_alg_serpent_inl_defd_decrypt_blocks(mk_lib_crypto_alg_serpent_base_schedule_pct const schedule, mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_ct, input, mk_lib_crypto_alg_serpent_inl_defd_cnt), mk_lang_static_param(mk_lib_crypto_alg_serpent_base_msg_t, output, mk_lib_crypto_alg_serpent_inl_defd_cnt), mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;
	mk_lang_types_usize_t i mk_lib_crypto_alg_serpent_inl_defd_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_alg_serpent_base_msg_len_d);
	mk_lang_assert(count % mk_lib_crypto_alg_serpent_inl_defd_cnt == 0);
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; i += mk_lib_crypto_alg_serpent_inl_defd_cnt)
	{
		mk_lib_crypto_alg_serpent_inl_defd_decrypt_once(schedule, &input[i], &output[i]);
	}
}


#include "mk_lib_crypto_alg_serpent_inl_defu.h"
