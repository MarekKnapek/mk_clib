#ifndef mk_include_guard_lang_pow
#define mk_include_guard_lang_pow


#define mk_lang_pow_8(a, b) 1
#define mk_lang_pow_7(a, b) (((b) == 0) ? (1) : (((b) == 1) ? (a) : ((mk_lang_pow_8((a), ((b) / 2))) * (mk_lang_pow_8((a), ((b) / 2))) * ((((b) % 2) == 0) ? (1) : (a)))))
#define mk_lang_pow_6(a, b) (((b) == 0) ? (1) : (((b) == 1) ? (a) : ((mk_lang_pow_7((a), ((b) / 2))) * (mk_lang_pow_7((a), ((b) / 2))) * ((((b) % 2) == 0) ? (1) : (a)))))
#define mk_lang_pow_5(a, b) (((b) == 0) ? (1) : (((b) == 1) ? (a) : ((mk_lang_pow_6((a), ((b) / 2))) * (mk_lang_pow_6((a), ((b) / 2))) * ((((b) % 2) == 0) ? (1) : (a)))))
#define mk_lang_pow_4(a, b) (((b) == 0) ? (1) : (((b) == 1) ? (a) : ((mk_lang_pow_5((a), ((b) / 2))) * (mk_lang_pow_5((a), ((b) / 2))) * ((((b) % 2) == 0) ? (1) : (a)))))
#define mk_lang_pow_3(a, b) (((b) == 0) ? (1) : (((b) == 1) ? (a) : ((mk_lang_pow_4((a), ((b) / 2))) * (mk_lang_pow_4((a), ((b) / 2))) * ((((b) % 2) == 0) ? (1) : (a)))))
#define mk_lang_pow_2(a, b) (((b) == 0) ? (1) : (((b) == 1) ? (a) : ((mk_lang_pow_3((a), ((b) / 2))) * (mk_lang_pow_3((a), ((b) / 2))) * ((((b) % 2) == 0) ? (1) : (a)))))
#define mk_lang_pow_1(a, b) (((b) == 0) ? (1) : (((b) == 1) ? (a) : ((mk_lang_pow_2((a), ((b) / 2))) * (mk_lang_pow_2((a), ((b) / 2))) * ((((b) % 2) == 0) ? (1) : (a)))))
#define mk_lang_pow_0(a, b) (((b) == 0) ? (1) : (((b) == 1) ? (a) : ((mk_lang_pow_1((a), ((b) / 2))) * (mk_lang_pow_1((a), ((b) / 2))) * ((((b) % 2) == 0) ? (1) : (a)))))
#define mk_lang_pow(a, b) (mk_lang_pow_0((a), (b)))


#endif
