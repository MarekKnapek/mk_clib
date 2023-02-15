#include "mk_lang_endian.h"


#define mk_lang_fora_endian_value mk_lang_endian_little
#define mk_lang_fora_endian_name le
#include mk_lang_fora_endian_file
#undef mk_lang_fora_endian_value
#undef mk_lang_fora_endian_name

#define mk_lang_fora_endian_value mk_lang_endian_big
#define mk_lang_fora_endian_name be
#include mk_lang_fora_endian_file
#undef mk_lang_fora_endian_value
#undef mk_lang_fora_endian_name

#undef mk_lang_fora_endian_file
