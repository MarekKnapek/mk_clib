#ifndef mk_include_guard_lang_bool
#define mk_include_guard_lang_bool


#if defined __cplusplus
#define mk_lang_bool_t bool
#define mk_lang_true ((mk_lang_bool_t)(true))
#define mk_lang_false ((mk_lang_bool_t)(false))
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 202299l /* todo c23 */
#define mk_lang_bool_t bool
#define mk_lang_true ((mk_lang_bool_t)(true))
#define mk_lang_false ((mk_lang_bool_t)(false))
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901l
#define mk_lang_bool_t _Bool
#define mk_lang_true ((mk_lang_bool_t)(1))
#define mk_lang_false ((mk_lang_bool_t)(0))
#else
#define mk_lang_bool_t int
#define mk_lang_true ((mk_lang_bool_t)(1))
#define mk_lang_false ((mk_lang_bool_t)(0))
#endif


#endif
