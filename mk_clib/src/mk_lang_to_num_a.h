#undef mk_lang_to_num_as
#if (mk_lang_to_num_a) >= 0 && (mk_lang_to_num_a) <= 9
#if (mk_lang_to_num_a) == 0
#define mk_lang_to_num_as 0
#elif (mk_lang_to_num_a) == 1
#define mk_lang_to_num_as 1
#elif (mk_lang_to_num_a) == 2
#define mk_lang_to_num_as 2
#elif (mk_lang_to_num_a) == 3
#define mk_lang_to_num_as 3
#elif (mk_lang_to_num_a) == 4
#define mk_lang_to_num_as 4
#elif (mk_lang_to_num_a) == 5
#define mk_lang_to_num_as 5
#elif (mk_lang_to_num_a) == 6
#define mk_lang_to_num_as 6
#elif (mk_lang_to_num_a) == 7
#define mk_lang_to_num_as 7
#elif (mk_lang_to_num_a) == 8
#define mk_lang_to_num_as 8
#elif (mk_lang_to_num_a) == 9
#define mk_lang_to_num_as 9
#endif
#elif (mk_lang_to_num_a) >= 10 && (mk_lang_to_num_a) <= 99
#define mk_lang_to_num_a1 ((mk_lang_to_num_a) % 10)
#define mk_lang_to_num_a2 ((mk_lang_to_num_a) / 10)
#include "mk_lang_to_num_a1.h"
#include "mk_lang_to_num_a2.h"
#undef mk_lang_to_num_as__
#undef mk_lang_to_num_as_
#define mk_lang_to_num_as__(a, b) a ## b
#define mk_lang_to_num_as_(a, b) mk_lang_to_num_as__(a, b)
#define mk_lang_to_num_as mk_lang_to_num_as_(mk_lang_to_num_as2, mk_lang_to_num_as1)
#endif
