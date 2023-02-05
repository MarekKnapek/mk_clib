#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"


#include "mk_sl_cui_inl_def.h"


struct mk_sl_cui_inl_def_s
{
	mk_sl_cui_inl_def_base_type m_data[mk_sl_cui_inl_def_count];
};
typedef struct mk_sl_cui_inl_def_s mk_sl_cui_inl_def_t;


mk_lang_jumbo void mk_sl_cui_inl_def_set_zero(mk_sl_cui_inl_def_t* x);
mk_lang_jumbo void mk_sl_cui_inl_def_set_max(mk_sl_cui_inl_def_t* x);
mk_lang_jumbo void mk_sl_cui_inl_def_set_one(mk_sl_cui_inl_def_t* x);
mk_lang_jumbo void mk_sl_cui_inl_def_set_bit(mk_sl_cui_inl_def_t* x, int bit_idx);
mk_lang_jumbo void mk_sl_cui_inl_def_set_mask(mk_sl_cui_inl_def_t* x, int bits_count);

#include "mk_sl_cui_inl_to_bi.h"
#include "mk_sl_cui_inl_from_bi.h"

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_is_zero(mk_sl_cui_inl_def_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_is_max(mk_sl_cui_inl_def_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_eq(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_ne(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_lt(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_le(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_gt(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_ge(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b);

mk_lang_jumbo void mk_sl_cui_inl_def_inc2(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t* b);
mk_lang_jumbo void mk_sl_cui_inl_def_dec2(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t* b);
mk_lang_jumbo void mk_sl_cui_inl_def_inc1(mk_sl_cui_inl_def_t* x);
mk_lang_jumbo void mk_sl_cui_inl_def_dec1(mk_sl_cui_inl_def_t* x);

mk_lang_jumbo void mk_sl_cui_inl_def_not2(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t* b);
mk_lang_jumbo void mk_sl_cui_inl_def_or3(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_and3(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_xor3(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_not1(mk_sl_cui_inl_def_t* x);
mk_lang_jumbo void mk_sl_cui_inl_def_or2(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b);
mk_lang_jumbo void mk_sl_cui_inl_def_and2(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b);
mk_lang_jumbo void mk_sl_cui_inl_def_xor2(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b);

mk_lang_jumbo void mk_sl_cui_inl_def_shl3(mk_sl_cui_inl_def_t const* a, int b, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_shr3(mk_sl_cui_inl_def_t const* a, int b, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_rotl3(mk_sl_cui_inl_def_t const* a, int b, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_rotr3(mk_sl_cui_inl_def_t const* a, int b, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_shl2(mk_sl_cui_inl_def_t* a, int b);
mk_lang_jumbo void mk_sl_cui_inl_def_shr2(mk_sl_cui_inl_def_t* a, int b);
mk_lang_jumbo void mk_sl_cui_inl_def_rotl2(mk_sl_cui_inl_def_t* a, int b);
mk_lang_jumbo void mk_sl_cui_inl_def_rotr2(mk_sl_cui_inl_def_t* a, int b);

mk_lang_jumbo void mk_sl_cui_inl_def_add3_wrap_cid_cod(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_add3_wrap_cid_coe(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c, mk_lang_bool_t* co);
mk_lang_jumbo void mk_sl_cui_inl_def_add3_wrap_cie_cod(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_add3_wrap_cie_coe(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_sl_cui_inl_def_t* c, mk_lang_bool_t* co);
mk_lang_jumbo void mk_sl_cui_inl_def_add2_wrap_cid_cod(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b);
mk_lang_jumbo void mk_sl_cui_inl_def_add2_wrap_cid_coe(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t* co);
mk_lang_jumbo void mk_sl_cui_inl_def_add2_wrap_cie_cod(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci);
mk_lang_jumbo void mk_sl_cui_inl_def_add2_wrap_cie_coe(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_lang_bool_t* co);

mk_lang_jumbo void mk_sl_cui_inl_def_sub3_wrap_cid_cod(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_sub3_wrap_cid_coe(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c, mk_lang_bool_t* co);
mk_lang_jumbo void mk_sl_cui_inl_def_sub3_wrap_cie_cod(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_sub3_wrap_cie_coe(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_sl_cui_inl_def_t* c, mk_lang_bool_t* co);
mk_lang_jumbo void mk_sl_cui_inl_def_sub2_wrap_cid_cod(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b);
mk_lang_jumbo void mk_sl_cui_inl_def_sub2_wrap_cid_coe(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t* co);
mk_lang_jumbo void mk_sl_cui_inl_def_sub2_wrap_cie_cod(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci);
mk_lang_jumbo void mk_sl_cui_inl_def_sub2_wrap_cie_coe(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_lang_bool_t* co);

mk_lang_jumbo void mk_sl_cui_inl_def_mul3_wrap_lo(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_mul3_wrap_hi(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c);
mk_lang_jumbo void mk_sl_cui_inl_def_mul4_wrap_wi(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c, mk_sl_cui_inl_def_t* d);
mk_lang_jumbo void mk_sl_cui_inl_def_mul2_wrap_lo(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b);
mk_lang_jumbo void mk_sl_cui_inl_def_mul2_wrap_hi(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b);
mk_lang_jumbo void mk_sl_cui_inl_def_mul2_wrap_wi(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t* b);


#include "mk_sl_cui_inl_undef.h"
