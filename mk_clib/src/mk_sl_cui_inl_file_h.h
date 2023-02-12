#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"


#include "mk_sl_cui_inl_def.h"


struct mk_sl_cui_inl_def_s
{
	mk_sl_cui_inl_def_base_type m_data[mk_sl_cui_inl_def_count];
};
typedef struct mk_sl_cui_inl_def_s mk_sl_cui_inl_def_t;


mk_lang_jumbo void mk_sl_cui_inl_def_set_zero(mk_sl_cui_inl_def_t* const x);
mk_lang_jumbo void mk_sl_cui_inl_def_set_max(mk_sl_cui_inl_def_t* const x);
mk_lang_jumbo void mk_sl_cui_inl_def_set_one(mk_sl_cui_inl_def_t* const x);
mk_lang_jumbo void mk_sl_cui_inl_def_set_bit(mk_sl_cui_inl_def_t* const x, int const bit_idx);
mk_lang_jumbo void mk_sl_cui_inl_def_set_mask(mk_sl_cui_inl_def_t* const x, int const bits_count);

#include "mk_sl_cui_inl_to_bi_h.h"
#include "mk_sl_cui_inl_from_bi_h.h"
#include "mk_sl_cui_inl_to_buis_h.h"

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_is_zero(mk_sl_cui_inl_def_t const* const x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_is_max(mk_sl_cui_inl_def_t const* const x);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_eq(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_ne(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_lt(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_le(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_gt(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b);
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_ge(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b);


#include "mk_sl_cui_inl_undef.h"
