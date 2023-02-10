#undef mk_lang_to_num_bs
#if (mk_lang_to_num_b) >= 0 && (mk_lang_to_num_b) <= 9
#if (mk_lang_to_num_b) == 0
#define mk_lang_to_num_bs 0
#elif (mk_lang_to_num_b) == 1
#define mk_lang_to_num_bs 1
#elif (mk_lang_to_num_b) == 2
#define mk_lang_to_num_bs 2
#elif (mk_lang_to_num_b) == 3
#define mk_lang_to_num_bs 3
#elif (mk_lang_to_num_b) == 4
#define mk_lang_to_num_bs 4
#elif (mk_lang_to_num_b) == 5
#define mk_lang_to_num_bs 5
#elif (mk_lang_to_num_b) == 6
#define mk_lang_to_num_bs 6
#elif (mk_lang_to_num_b) == 7
#define mk_lang_to_num_bs 7
#elif (mk_lang_to_num_b) == 8
#define mk_lang_to_num_bs 8
#elif (mk_lang_to_num_b) == 9
#define mk_lang_to_num_bs 9
#endif
#elif (mk_lang_to_num_b) >= 10 && (mk_lang_to_num_b) <= 99
#define mk_lang_to_num_b1 ((mk_lang_to_num_b) % 10)
#define mk_lang_to_num_b2 ((mk_lang_to_num_b) / 10)
#include "mk_lang_to_num_b1.h"
#include "mk_lang_to_num_b2.h"
#undef mk_lang_to_num_bs__
#undef mk_lang_to_num_bs_
#define mk_lang_to_num_bs__(a, b) a ## b
#define mk_lang_to_num_bs_(a, b) mk_lang_to_num_bs__(a, b)
#define mk_lang_to_num_bs mk_lang_to_num_bs_(mk_lang_to_num_bs2, mk_lang_to_num_bs1)
#endif
