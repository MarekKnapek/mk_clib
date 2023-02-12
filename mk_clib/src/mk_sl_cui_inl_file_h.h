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

#include "mk_sl_cui_inl_to_bi_h.h"
#include "mk_sl_cui_inl_from_bi_h.h"


#include "mk_sl_cui_inl_undef.h"
