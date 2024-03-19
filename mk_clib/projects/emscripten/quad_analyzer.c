#define mk_lang_jumbo_want 1

#include "../../src/mk_lang_assert.h"
#include "../../src/mk_lang_charbit.h"
#include "../../src/mk_lang_constexpr.h"
#include "../../src/mk_lang_cpp.h"
#include "../../src/mk_lang_emscripten.h"
#include "../../src/mk_lang_inline.h"
#include "../../src/mk_lang_likely.h"
#include "../../src/mk_lang_nodiscard.h"
#include "../../src/mk_lang_noexcept.h"
#include "../../src/mk_lang_static_assert.h"
#include "../../src/mk_lang_stringify.h"
#include "../../src/mk_lang_types.h"
#include "../../src/mk_lib_flt_analyzer_quad.h"
#include "../../src/mk_sl_uint128.h"


static mk_lib_flt_analyzer_quad_t g_quad_analyzer;


mk_lang_extern_c mk_lang_emscripten_keepalive mk_lib_flt_analyzer_quad_pct quad_analyzer_analyze(mk_lang_types_uint_t const a, mk_lang_types_uint_t const b, mk_lang_types_uint_t const c, mk_lang_types_uint_t const d, mk_lang_types_uint_t const e, mk_lang_types_uint_t const f, mk_lang_types_uint_t const g, mk_lang_types_uint_t const h, mk_lang_types_uint_t const i, mk_lang_types_uint_t const j, mk_lang_types_uint_t const k, mk_lang_types_uint_t const l, mk_lang_types_uint_t const m, mk_lang_types_uint_t const n, mk_lang_types_uint_t const o, mk_lang_types_uint_t const p) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint128_t tcuia;
	mk_sl_cui_uint128_t tcuib;

	tuc = ((mk_lang_types_uchar_t)(p)); mk_sl_cui_uint128_from_bi_uchar(&tcuib, &tuc);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(o)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(n)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(m)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(l)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(k)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(j)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(i)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(h)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(g)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(f)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(e)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(d)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(c)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(b)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_shl2(&tcuib, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(a)); mk_sl_cui_uint128_from_bi_uchar(&tcuia, &tuc); mk_sl_cui_uint128_or2(&tcuib, &tcuia);
	mk_sl_cui_uint128_to_buis_uchar_le(&tcuib, &g_quad_analyzer.m_bytes[0]);
	mk_lib_flt_analyzer_quad_analyze(&g_quad_analyzer);
	return &g_quad_analyzer;
}
