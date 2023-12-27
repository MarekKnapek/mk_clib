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
#include "../../src/mk_lib_float_analyzer.h"
#include "../../src/mk_sl_uint32.h"


static mk_lib_float_analyzer_t g_float_analyzer;


mk_lang_extern_c mk_lang_emscripten_keepalive mk_lib_float_analyzer_pct float_analyzer_analyze(mk_lang_types_uint_t const a, mk_lang_types_uint_t const b, mk_lang_types_uint_t const c, mk_lang_types_uint_t const d) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint32_t tcui;

	tuc = ((mk_lang_types_uchar_t)(d)); mk_sl_cui_uint32_from_bi_uchar(&g_float_analyzer.m_bytes, &tuc);
	mk_sl_cui_uint32_shl2(&g_float_analyzer.m_bytes, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(c)); mk_sl_cui_uint32_from_bi_uchar(&tcui, &tuc); mk_sl_cui_uint32_or2(&g_float_analyzer.m_bytes, &tcui);
	mk_sl_cui_uint32_shl2(&g_float_analyzer.m_bytes, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(b)); mk_sl_cui_uint32_from_bi_uchar(&tcui, &tuc); mk_sl_cui_uint32_or2(&g_float_analyzer.m_bytes, &tcui);
	mk_sl_cui_uint32_shl2(&g_float_analyzer.m_bytes, mk_lang_charbit); tuc = ((mk_lang_types_uchar_t)(a)); mk_sl_cui_uint32_from_bi_uchar(&tcui, &tuc); mk_sl_cui_uint32_or2(&g_float_analyzer.m_bytes, &tcui);
	mk_lib_float_analyzer_analyze(&g_float_analyzer);
	return &g_float_analyzer;
}
