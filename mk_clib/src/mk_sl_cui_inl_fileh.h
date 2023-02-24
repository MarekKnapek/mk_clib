#include "mk_lang_bool.h"
#include "mk_lang_for_constants.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"


#include "mk_sl_cui_inl_defd.h"


struct mk_sl_cui_inl_defd_s
{
	mk_sl_cui_inl_defd_base_type m_data[mk_sl_cui_inl_defd_count];
};
typedef struct mk_sl_cui_inl_defd_s mk_sl_cui_inl_defd_t;


mk_lang_jumbo void mk_sl_cui_inl_defd_set_zero(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_set_max(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_set_one(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_set_bit(mk_sl_cui_inl_defd_t* const x, int const bit_idx) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_set_mask(mk_sl_cui_inl_defd_t* const x, int const bits_count) mk_lang_noexcept;

#define mk_lang_forb1_id mk_lang_for_constants_bi
#define mk_lang_forb_file "mk_sl_cui_inl_tofrom_bi_inl_fileh.h"
#define mk_sl_cui_inl_tofrom_bi_for_bi mk_lang_forb_bi
#include "mk_lang_forb1.h"
#undef mk_lang_forb1_id
#undef mk_lang_forb_file
#undef mk_sl_cui_inl_tofrom_bi_for_bi

#define mk_lang_forb2_id mk_lang_for_constants_bui
#define mk_lang_forb1_id mk_lang_for_constants_endian
#define mk_lang_forb_file "mk_sl_cui_inl_tofrom_buis_inl_fileh.h"
#define mk_sl_cui_inl_tofrom_buis_for_bui mk_lang_forb_bui
#define mk_sl_cui_inl_tofrom_buis_for_endian mk_lang_forb_endian
#include "mk_lang_forb2.h"
#undef mk_lang_forb2_id
#undef mk_lang_forb1_id
#undef mk_lang_forb_file
#undef mk_sl_cui_inl_tofrom_buis_for_bui
#undef mk_sl_cui_inl_tofrom_buis_for_endian

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_is_zero(mk_sl_cui_inl_defd_t const* const x) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_is_max(mk_sl_cui_inl_defd_t const* const x) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_eq(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_ne(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_lt(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_le(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_gt(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_ge(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;

mk_lang_jumbo void mk_sl_cui_inl_defd_inc2(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_dec2(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_inc1(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_dec1(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept;

mk_lang_jumbo void mk_sl_cui_inl_defd_not2(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_or3(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_and3(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_xor3(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_not1(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_or2(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_and2(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_xor2(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;

mk_lang_jumbo void mk_sl_cui_inl_defd_shl3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_shr3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_rotl3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_rotr3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_shl2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_shr2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_rotl2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_rotr2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_add_cc(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_add_cs(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_add(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const cf) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_sub_cc(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_sub_cs(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_sub(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const cf) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_mul(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;

mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cid_cod(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cid_coe(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cie_cod(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cie_coe(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_sl_cui_inl_defd_t* const c, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_add2_wrap_cid_cod(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_add2_wrap_cid_coe(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_add2_wrap_cie_cod(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_add2_wrap_cie_coe(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_lang_bool_t* const co) mk_lang_noexcept;

mk_lang_jumbo void mk_sl_cui_inl_defd_sub3_wrap_cid_cod(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_sub3_wrap_cid_coe(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_sub3_wrap_cie_cod(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_sub3_wrap_cie_coe(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_sl_cui_inl_defd_t* const c, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_sub2_wrap_cid_cod(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_sub2_wrap_cid_coe(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t* const co) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_sub2_wrap_cie_cod(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_sub2_wrap_cie_coe(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_lang_bool_t* const co) mk_lang_noexcept;

mk_lang_jumbo void mk_sl_cui_inl_defd_mul3_wrap_lo(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_mul3_wrap_hi(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_mul4_wrap_wi(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_sl_cui_inl_defd_t* const d) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_mul2_wrap_lo(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_mul2_wrap_hi(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_mul2_wrap_wi(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept;

mk_lang_jumbo void mk_sl_cui_inl_defd_div3_wrap(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_mod3_wrap(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_divmod4_wrap(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_sl_cui_inl_defd_t* const d) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_div2_wrap(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_mod2_wrap(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_cui_inl_defd_divmod2_wrap(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept;


#include "mk_sl_cui_inl_defu.h"
