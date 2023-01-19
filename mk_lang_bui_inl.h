#include "mk_lang_bi.h"
#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"


#include "mk_lang_bui_inl_def.h"


mk_lang_jumbo void mk_lang_bui_set_zero(mk_lang_bui_t* x);
mk_lang_jumbo void mk_lang_bui_set_one(mk_lang_bui_t* x);
mk_lang_jumbo void mk_lang_bui_set_bit(mk_lang_bui_t* x, int bit_idx);
mk_lang_jumbo void mk_lang_bui_set_mask(mk_lang_bui_t* x, int bits_count);

#include "mk_lang_bui_inl_to_bi.h"
#include "mk_lang_bui_inl_from_bi.h"
#include "mk_lang_bui_inl_to_buis_le.h"
#include "mk_lang_bui_inl_to_buis_be.h"
#include "mk_lang_bui_inl_from_buis_le.h"
#include "mk_lang_bui_inl_from_buis_be.h"

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_is_zero(mk_lang_bui_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_is_max(mk_lang_bui_t const* x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_eq(mk_lang_bui_t const* a, mk_lang_bui_t const* b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_ne(mk_lang_bui_t const* a, mk_lang_bui_t const* b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_lt(mk_lang_bui_t const* a, mk_lang_bui_t const* b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_le(mk_lang_bui_t const* a, mk_lang_bui_t const* b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_gt(mk_lang_bui_t const* a, mk_lang_bui_t const* b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_ge(mk_lang_bui_t const* a, mk_lang_bui_t const* b);

mk_lang_jumbo void mk_lang_bui_inc2(mk_lang_bui_t const* a, mk_lang_bui_t* b);
mk_lang_jumbo void mk_lang_bui_dec2(mk_lang_bui_t const* a, mk_lang_bui_t* b);
mk_lang_jumbo void mk_lang_bui_inc1(mk_lang_bui_t* x);
mk_lang_jumbo void mk_lang_bui_dec1(mk_lang_bui_t* x);

mk_lang_jumbo void mk_lang_bui_not2(mk_lang_bui_t const* a, mk_lang_bui_t* b);
mk_lang_jumbo void mk_lang_bui_or3(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c);
mk_lang_jumbo void mk_lang_bui_and3(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c);
mk_lang_jumbo void mk_lang_bui_xor3(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c);
mk_lang_jumbo void mk_lang_bui_not1(mk_lang_bui_t* x);
mk_lang_jumbo void mk_lang_bui_or2(mk_lang_bui_t* a, mk_lang_bui_t const* b);
mk_lang_jumbo void mk_lang_bui_and2(mk_lang_bui_t* a, mk_lang_bui_t const* b);
mk_lang_jumbo void mk_lang_bui_xor2(mk_lang_bui_t* a, mk_lang_bui_t const* b);

mk_lang_jumbo void mk_lang_bui_shl3(mk_lang_bui_t const* a, int b, mk_lang_bui_t* c);
mk_lang_jumbo void mk_lang_bui_shr3(mk_lang_bui_t const* a, int b, mk_lang_bui_t* c);
mk_lang_jumbo void mk_lang_bui_rotl3(mk_lang_bui_t const* a, int b, mk_lang_bui_t* c);
mk_lang_jumbo void mk_lang_bui_rotr3(mk_lang_bui_t const* a, int b, mk_lang_bui_t* c);
mk_lang_jumbo void mk_lang_bui_shl2(mk_lang_bui_t* a, int b);
mk_lang_jumbo void mk_lang_bui_shr2(mk_lang_bui_t* a, int b);
mk_lang_jumbo void mk_lang_bui_rotl2(mk_lang_bui_t* a, int b);
mk_lang_jumbo void mk_lang_bui_rotr2(mk_lang_bui_t* a, int b);

mk_lang_jumbo void mk_lang_bui_add3_wrap_cid_cod(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c);
mk_lang_jumbo void mk_lang_bui_add3_wrap_cid_coe(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c, mk_lang_bool_t* co);
mk_lang_jumbo void mk_lang_bui_add3_wrap_cie_cod(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bui_t* c);
mk_lang_jumbo void mk_lang_bui_add3_wrap_cie_coe(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bui_t* c, mk_lang_bool_t* co);
mk_lang_jumbo void mk_lang_bui_add2_wrap_cid_cod(mk_lang_bui_t* a, mk_lang_bui_t const* b);
mk_lang_jumbo void mk_lang_bui_add2_wrap_cid_coe(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t* co);
mk_lang_jumbo void mk_lang_bui_add2_wrap_cie_cod(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t ci);
mk_lang_jumbo void mk_lang_bui_add2_wrap_cie_coe(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bool_t* co);

mk_lang_jumbo void mk_lang_bui_sub3_wrap_cid_cod(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c);
mk_lang_jumbo void mk_lang_bui_sub3_wrap_cid_coe(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c, mk_lang_bool_t* co);
mk_lang_jumbo void mk_lang_bui_sub3_wrap_cie_cod(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bui_t* c);
mk_lang_jumbo void mk_lang_bui_sub3_wrap_cie_coe(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bui_t* c, mk_lang_bool_t* co);
mk_lang_jumbo void mk_lang_bui_sub2_wrap_cid_cod(mk_lang_bui_t* a, mk_lang_bui_t const* b);
mk_lang_jumbo void mk_lang_bui_sub2_wrap_cid_coe(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t* co);
mk_lang_jumbo void mk_lang_bui_sub2_wrap_cie_cod(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t ci);
mk_lang_jumbo void mk_lang_bui_sub2_wrap_cie_coe(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bool_t* co);


#include "mk_lang_bui_inl_undef.h"


#undef mk_lang_bui_btn
#undef mk_lang_bui_n
