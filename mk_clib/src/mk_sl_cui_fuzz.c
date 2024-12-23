#include "mk_sl_cui_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#define mk_lang_bui_t_name mk_sl_cui_fuzz_zzz_buiuc
#define mk_lang_bui_t_base uchar
#define mk_lang_bui_t_inline 0
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_fuzz_zzz_buiuc_sizebits_d (mk_lang_sizeof_bi_uchar_t * mk_lang_charbit)

#define mk_lang_bui_t_name mk_sl_cui_fuzz_zzz_buius
#define mk_lang_bui_t_base ushort
#define mk_lang_bui_t_inline 0
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_fuzz_zzz_buius_sizebits_d (mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)

#define mk_lang_bui_t_name mk_sl_cui_fuzz_zzz_buiui
#define mk_lang_bui_t_base uint
#define mk_lang_bui_t_inline 0
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_fuzz_zzz_buiui_sizebits_d (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)

#define mk_sl_cui_t_name mk_sl_cui_fuzz_zzz_cuia
#define mk_sl_cui_t_base mk_sl_cui_fuzz_zzz_buiuc
#define mk_sl_cui_t_count (mk_sl_cui_fuzz_zzz_buiui_sizebits_d / mk_sl_cui_fuzz_zzz_buiuc_sizebits_d)
#define mk_sl_cui_t_base_sizebits_d mk_sl_cui_fuzz_zzz_buiuc_sizebits_d
#define mk_sl_cui_t_str_style 1001
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#define mk_sl_cui_t_name mk_sl_cui_fuzz_zzz_cuib
#define mk_sl_cui_t_base mk_sl_cui_fuzz_zzz_buiuc
#define mk_sl_cui_t_count (mk_sl_cui_fuzz_zzz_buiui_sizebits_d / mk_sl_cui_fuzz_zzz_buiuc_sizebits_d)
#define mk_sl_cui_t_base_sizebits_d mk_sl_cui_fuzz_zzz_buiuc_sizebits_d
#define mk_sl_cui_t_str_style 1003
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#define mk_sl_cui_t_name mk_sl_cui_fuzz_zzz_cuic
#define mk_sl_cui_t_base mk_sl_cui_fuzz_zzz_buius
#define mk_sl_cui_t_count (mk_sl_cui_fuzz_zzz_buiui_sizebits_d / mk_sl_cui_fuzz_zzz_buius_sizebits_d)
#define mk_sl_cui_t_base_sizebits_d mk_sl_cui_fuzz_zzz_buius_sizebits_d
#define mk_sl_cui_t_str_style 1001
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#define mk_sl_cui_t_name mk_sl_cui_fuzz_zzz_cuid
#define mk_sl_cui_t_base mk_sl_cui_fuzz_zzz_buius
#define mk_sl_cui_t_count (mk_sl_cui_fuzz_zzz_buiui_sizebits_d / mk_sl_cui_fuzz_zzz_buius_sizebits_d)
#define mk_sl_cui_t_base_sizebits_d mk_sl_cui_fuzz_zzz_buius_sizebits_d
#define mk_sl_cui_t_str_style 1003
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_bin_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_bin_n(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_bin_n(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_bin_n(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_bin_n(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_bin_n(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_bin_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_bin_w(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_bin_w(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_bin_w(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_bin_w(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_bin_w(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_from_str_bin_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_pchar_t str[4 * mk_sl_cui_fuzz_zzz_buiui_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t sz mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t tui mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));

	if(!(size >= 0 && size <= mk_lang_countof(str)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str[i] = ((mk_lang_types_pchar_t)(data[i]));
	}
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_from_str_bin_n(&buiui, &str[0], sz);
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_from_str_bin_n(&cuia, &str[0], sz);
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_from_str_bin_n(&cuib, &str[0], sz);
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_from_str_bin_n(&cuic, &str[0], sz);
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_from_str_bin_n(&cuid, &str[0], sz);
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	if(len_buiui >= 1)
	{
		mk_sl_cui_fuzz_zzz_cuia_to_bi_uint(&cuia, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuib_to_bi_uint(&cuib, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuic_to_bi_uint(&cuic, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuid_to_bi_uint(&cuid, &tui); mk_lang_test(tui == buiui);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_from_str_bin_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_wchar_t str[4 * mk_sl_cui_fuzz_zzz_buiui_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t sz mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t tui mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));

	if(!(size >= 0 && size <= mk_lang_countof(str)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str[i] = ((mk_lang_types_wchar_t)(data[i]));
	}
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_from_str_bin_w(&buiui, &str[0], sz);
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_from_str_bin_w(&cuia, &str[0], sz);
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_from_str_bin_w(&cuib, &str[0], sz);
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_from_str_bin_w(&cuic, &str[0], sz);
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_from_str_bin_w(&cuid, &str[0], sz);
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	if(len_buiui >= 1)
	{
		mk_sl_cui_fuzz_zzz_cuia_to_bi_uint(&cuia, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuib_to_bi_uint(&cuib, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuic_to_bi_uint(&cuic, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuid_to_bi_uint(&cuid, &tui); mk_lang_test(tui == buiui);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_oct_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_oct_n(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_oct_n(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_oct_n(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_oct_n(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_oct_n(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_oct_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_oct_w(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_oct_w(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_oct_w(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_oct_w(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_oct_w(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_from_str_oct_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_pchar_t str[4 * mk_sl_cui_fuzz_zzz_buiui_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t sz mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t tui mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));

	if(!(size >= 0 && size <= mk_lang_countof(str)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str[i] = ((mk_lang_types_pchar_t)(data[i]));
	}
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_from_str_oct_n(&buiui, &str[0], sz);
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_from_str_oct_n(&cuia, &str[0], sz);
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_from_str_oct_n(&cuib, &str[0], sz);
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_from_str_oct_n(&cuic, &str[0], sz);
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_from_str_oct_n(&cuid, &str[0], sz);
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	if(len_buiui >= 1)
	{
		mk_sl_cui_fuzz_zzz_cuia_to_bi_uint(&cuia, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuib_to_bi_uint(&cuib, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuic_to_bi_uint(&cuic, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuid_to_bi_uint(&cuid, &tui); mk_lang_test(tui == buiui);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_from_str_oct_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_wchar_t str[4 * mk_sl_cui_fuzz_zzz_buiui_strlenoct_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t sz mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t tui mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));

	if(!(size >= 0 && size <= mk_lang_countof(str)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str[i] = ((mk_lang_types_wchar_t)(data[i]));
	}
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_from_str_oct_w(&buiui, &str[0], sz);
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_from_str_oct_w(&cuia, &str[0], sz);
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_from_str_oct_w(&cuib, &str[0], sz);
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_from_str_oct_w(&cuic, &str[0], sz);
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_from_str_oct_w(&cuid, &str[0], sz);
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	if(len_buiui >= 1)
	{
		mk_sl_cui_fuzz_zzz_cuia_to_bi_uint(&cuia, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuib_to_bi_uint(&cuib, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuic_to_bi_uint(&cuic, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuid_to_bi_uint(&cuid, &tui); mk_lang_test(tui == buiui);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_dec_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_dec_n(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_dec_n(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_dec_n(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_dec_n(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_dec_n(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_dec_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_dec_w(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_dec_w(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_dec_w(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_dec_w(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_dec_w(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_from_str_dec_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_pchar_t str[4 * mk_sl_cui_fuzz_zzz_buiui_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t sz mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t tui mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));

	if(!(size >= 0 && size <= mk_lang_countof(str)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str[i] = ((mk_lang_types_pchar_t)(data[i]));
	}
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_from_str_dec_n(&buiui, &str[0], sz);
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_from_str_dec_n(&cuia, &str[0], sz);
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_from_str_dec_n(&cuib, &str[0], sz);
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_from_str_dec_n(&cuic, &str[0], sz);
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_from_str_dec_n(&cuid, &str[0], sz);
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	if(len_buiui >= 1)
	{
		mk_sl_cui_fuzz_zzz_cuia_to_bi_uint(&cuia, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuib_to_bi_uint(&cuib, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuic_to_bi_uint(&cuic, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuid_to_bi_uint(&cuid, &tui); mk_lang_test(tui == buiui);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_from_str_dec_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_wchar_t str[4 * mk_sl_cui_fuzz_zzz_buiui_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t sz mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t tui mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));

	if(!(size >= 0 && size <= mk_lang_countof(str)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str[i] = ((mk_lang_types_wchar_t)(data[i]));
	}
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_from_str_dec_w(&buiui, &str[0], sz);
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_from_str_dec_w(&cuia, &str[0], sz);
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_from_str_dec_w(&cuib, &str[0], sz);
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_from_str_dec_w(&cuic, &str[0], sz);
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_from_str_dec_w(&cuid, &str[0], sz);
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	if(len_buiui >= 1)
	{
		mk_sl_cui_fuzz_zzz_cuia_to_bi_uint(&cuia, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuib_to_bi_uint(&cuib, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuic_to_bi_uint(&cuic, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuid_to_bi_uint(&cuid, &tui); mk_lang_test(tui == buiui);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_hex_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_hex_n(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_hex_n(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_hex_n(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_hex_n(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_hex_n(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_hex_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_hex_w(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_hex_w(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_hex_w(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_hex_w(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_hex_w(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_from_str_hex_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_pchar_t str[4 * mk_sl_cui_fuzz_zzz_buiui_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t sz mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t tui mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));

	if(!(size >= 0 && size <= mk_lang_countof(str)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str[i] = ((mk_lang_types_pchar_t)(data[i]));
	}
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_from_str_hex_n(&buiui, &str[0], sz);
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_from_str_hex_n(&cuia, &str[0], sz);
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_from_str_hex_n(&cuib, &str[0], sz);
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_from_str_hex_n(&cuic, &str[0], sz);
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_from_str_hex_n(&cuid, &str[0], sz);
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	if(len_buiui >= 1)
	{
		mk_sl_cui_fuzz_zzz_cuia_to_bi_uint(&cuia, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuib_to_bi_uint(&cuib, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuic_to_bi_uint(&cuic, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuid_to_bi_uint(&cuid, &tui); mk_lang_test(tui == buiui);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_from_str_hex_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_wchar_t str[4 * mk_sl_cui_fuzz_zzz_buiui_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t sz mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_buiui_t tui mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));

	if(!(size >= 0 && size <= mk_lang_countof(str)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str[i] = ((mk_lang_types_wchar_t)(data[i]));
	}
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_from_str_hex_w(&buiui, &str[0], sz);
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_from_str_hex_w(&cuia, &str[0], sz);
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_from_str_hex_w(&cuib, &str[0], sz);
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_from_str_hex_w(&cuic, &str[0], sz);
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_from_str_hex_w(&cuid, &str[0], sz);
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	if(len_buiui >= 1)
	{
		mk_sl_cui_fuzz_zzz_cuia_to_bi_uint(&cuia, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuib_to_bi_uint(&cuib, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuic_to_bi_uint(&cuic, &tui); mk_lang_test(tui == buiui);
		mk_sl_cui_fuzz_zzz_cuid_to_bi_uint(&cuid, &tui); mk_lang_test(tui == buiui);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_binf_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_binf_n(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_binf_n(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_binf_n(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_binf_n(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_binf_n(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_binf_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlenbin_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_binf_w(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_binf_w(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_binf_w(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_binf_w(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_binf_w(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_hexf_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_hexf_n(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_hexf_n(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_hexf_n(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_hexf_n(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_hexf_n(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_to_str_hexf_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_zzz_buiui_t buiui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuia_t cuia mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuib_t cuib mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuic_t cuic mk_lang_constexpr_init;
	mk_sl_cui_fuzz_zzz_cuid_t cuid mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_buiui[mk_sl_cui_fuzz_zzz_buiui_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuia[mk_sl_cui_fuzz_zzz_cuia_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuib[mk_sl_cui_fuzz_zzz_cuib_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuic[mk_sl_cui_fuzz_zzz_cuic_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_cuid[mk_sl_cui_fuzz_zzz_cuid_strlenhex_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_buiui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuia mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuib mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuic mk_lang_constexpr_init;
	mk_lang_types_sint_t len_cuid mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_static_assert(sizeof(cuia) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuib) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuic) == sizeof(buiui));
	mk_lang_static_assert(sizeof(cuid) == sizeof(buiui));
	mk_lang_static_assert(sizeof(str_cuia) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuib) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuic) == sizeof(str_buiui));
	mk_lang_static_assert(sizeof(str_cuid) == sizeof(str_buiui));

	if(!(size == sizeof(buiui)))
	{
		return;
	}
	mk_sl_cui_fuzz_zzz_buiui_from_buis_uchar_le(&buiui, &data[0]);
	mk_sl_cui_fuzz_zzz_cuia_from_buis_uchar_le(&cuia, &data[0]);
	mk_sl_cui_fuzz_zzz_cuib_from_buis_uchar_le(&cuib, &data[0]);
	mk_sl_cui_fuzz_zzz_cuic_from_buis_uchar_le(&cuic, &data[0]);
	mk_sl_cui_fuzz_zzz_cuid_from_buis_uchar_le(&cuid, &data[0]);
	len_buiui = mk_sl_cui_fuzz_zzz_buiui_to_str_hexf_w(&buiui, &str_buiui[0], mk_lang_countof(str_buiui));
	len_cuia = mk_sl_cui_fuzz_zzz_cuia_to_str_hexf_w(&cuia, &str_cuia[0], mk_lang_countof(str_cuia));
	len_cuib = mk_sl_cui_fuzz_zzz_cuib_to_str_hexf_w(&cuib, &str_cuib[0], mk_lang_countof(str_cuib));
	len_cuic = mk_sl_cui_fuzz_zzz_cuic_to_str_hexf_w(&cuic, &str_cuic[0], mk_lang_countof(str_cuic));
	len_cuid = mk_sl_cui_fuzz_zzz_cuid_to_str_hexf_w(&cuid, &str_cuid[0], mk_lang_countof(str_cuid));
	mk_lang_test(len_cuia == len_buiui);
	mk_lang_test(len_cuib == len_buiui);
	mk_lang_test(len_cuic == len_buiui);
	mk_lang_test(len_cuid == len_buiui);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuia[0], &str_buiui[0], len_cuia) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuib[0], &str_buiui[0], len_cuib) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuic[0], &str_buiui[0], len_cuic) == 0);
	mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_cuid[0], &str_buiui[0], len_cuid) == 0);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_to_str_bin_n(data, size);
	mk_sl_cui_fuzz_to_str_bin_w(data, size);
	mk_sl_cui_fuzz_from_str_bin_n(data, size);
	mk_sl_cui_fuzz_from_str_bin_w(data, size);
	mk_sl_cui_fuzz_to_str_oct_n(data, size);
	mk_sl_cui_fuzz_to_str_oct_w(data, size);
	mk_sl_cui_fuzz_from_str_oct_n(data, size);
	mk_sl_cui_fuzz_from_str_oct_w(data, size);
	mk_sl_cui_fuzz_to_str_dec_n(data, size);
	mk_sl_cui_fuzz_to_str_dec_w(data, size);
	mk_sl_cui_fuzz_from_str_dec_n(data, size);
	mk_sl_cui_fuzz_from_str_dec_w(data, size);
	mk_sl_cui_fuzz_to_str_hex_n(data, size);
	mk_sl_cui_fuzz_to_str_hex_w(data, size);
	mk_sl_cui_fuzz_from_str_hex_n(data, size);
	mk_sl_cui_fuzz_from_str_hex_w(data, size);
	mk_sl_cui_fuzz_to_str_binf_n(data, size);
	mk_sl_cui_fuzz_to_str_binf_w(data, size);
	mk_sl_cui_fuzz_to_str_hexf_n(data, size);
	mk_sl_cui_fuzz_to_str_hexf_w(data, size);
}
