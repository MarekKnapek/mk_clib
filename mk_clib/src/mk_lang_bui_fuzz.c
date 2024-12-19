#include "mk_lang_bui_fuzz.h"

#include "mk_lang_bui_fuzz_str_offset_bin_n.h"
#include "mk_lang_bui_fuzz_str_offset_bin_w.h"
#include "mk_lang_bui_fuzz_str_offset_dec_n.h"
#include "mk_lang_bui_fuzz_str_offset_dec_w.h"
#include "mk_lang_bui_fuzz_str_offset_hex_n.h"
#include "mk_lang_bui_fuzz_str_offset_hex_w.h"
#include "mk_lang_bui_fuzz_str_offset_oct_n.h"
#include "mk_lang_bui_fuzz_str_offset_oct_w.h"
#include "mk_lang_bui_fuzz_str_table_bin_n.h"
#include "mk_lang_bui_fuzz_str_table_bin_w.h"
#include "mk_lang_bui_fuzz_str_table_dec_n.h"
#include "mk_lang_bui_fuzz_str_table_dec_w.h"
#include "mk_lang_bui_fuzz_str_table_hex_n.h"
#include "mk_lang_bui_fuzz_str_table_hex_w.h"
#include "mk_lang_bui_fuzz_str_table_oct_n.h"
#include "mk_lang_bui_fuzz_str_table_oct_w.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_fuzz_str_offset_bin_n(data, size);
	mk_lang_bui_fuzz_str_offset_bin_w(data, size);
	mk_lang_bui_fuzz_str_offset_dec_n(data, size);
	mk_lang_bui_fuzz_str_offset_dec_w(data, size);
	mk_lang_bui_fuzz_str_offset_hex_n(data, size);
	mk_lang_bui_fuzz_str_offset_hex_w(data, size);
	mk_lang_bui_fuzz_str_offset_oct_n(data, size);
	mk_lang_bui_fuzz_str_offset_oct_w(data, size);
	mk_lang_bui_fuzz_str_table_bin_n(data, size);
	mk_lang_bui_fuzz_str_table_bin_w(data, size);
	mk_lang_bui_fuzz_str_table_dec_n(data, size);
	mk_lang_bui_fuzz_str_table_dec_w(data, size);
	mk_lang_bui_fuzz_str_table_hex_n(data, size);
	mk_lang_bui_fuzz_str_table_hex_w(data, size);
	mk_lang_bui_fuzz_str_table_oct_n(data, size);
	mk_lang_bui_fuzz_str_table_oct_w(data, size);
}
