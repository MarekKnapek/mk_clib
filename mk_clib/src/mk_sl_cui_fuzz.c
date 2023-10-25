#include "mk_sl_cui_fuzz.h"

#include "mk_lang_for_constants.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui.h"


#define mk_lang_fora3_id mk_lang_for_constants_bui
#define mk_lang_fora2_id mk_lang_for_constants_count
#define mk_lang_fora1_id mk_lang_for_constants_endian
#define mk_lang_fora_file "mk_sl_cui_fuzz_inl_func.h"
#define mk_sl_cui_for_bui mk_lang_fora_bui
#define mk_sl_cui_for_count mk_lang_fora_count
#define mk_sl_cui_for_endian mk_lang_fora_endian
#define mk_sl_cui_fuzz_for_bui mk_lang_fora_bui
#define mk_sl_cui_fuzz_for_count mk_lang_fora_count
#define mk_sl_cui_fuzz_for_endian mk_lang_fora_endian
#include "mk_lang_fora3.h"
#undef mk_lang_fora3_id
#undef mk_lang_fora2_id
#undef mk_lang_fora1_id
#undef mk_lang_fora_file
#undef mk_sl_cui_for_bui
#undef mk_sl_cui_for_count
#undef mk_sl_cui_for_endian
#undef mk_sl_cui_fuzz_for_bui
#undef mk_sl_cui_fuzz_for_count
#undef mk_sl_cui_fuzz_for_endian


mk_lang_jumbo void mk_sl_cui_fuzz(unsigned char const* const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
#define mk_lang_fora3_id mk_lang_for_constants_bui
#define mk_lang_fora2_id mk_lang_for_constants_count
#define mk_lang_fora1_id mk_lang_for_constants_endian
#define mk_lang_fora_file "mk_sl_cui_fuzz_inl_call.h"
#define mk_sl_cui_for_bui mk_lang_fora_bui
#define mk_sl_cui_for_count mk_lang_fora_count
#define mk_sl_cui_for_endian mk_lang_fora_endian
#define mk_sl_cui_fuzz_for_bui mk_lang_fora_bui
#define mk_sl_cui_fuzz_for_count mk_lang_fora_count
#define mk_sl_cui_fuzz_for_endian mk_lang_fora_endian
#include "mk_lang_fora3.h"
#undef mk_lang_fora3_id
#undef mk_lang_fora2_id
#undef mk_lang_fora1_id
#undef mk_lang_fora_file
#undef mk_sl_cui_for_bui
#undef mk_sl_cui_for_count
#undef mk_sl_cui_for_endian
#undef mk_sl_cui_fuzz_for_bui
#undef mk_sl_cui_fuzz_for_count
#undef mk_sl_cui_fuzz_for_endian
}
