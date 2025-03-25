#ifndef mk_include_guard_mk_lang_compiler_h
#define mk_include_guard_mk_lang_compiler_h


#if defined __WATCOMC__
#define mk_lang_compiler_is_at_least_watcom_c(maj, min) \
( \
	((maj) >= 1 && (maj) <= 99) && \
	((min) >= 0 && (min) <= 99) && \
	((__WATCOMC__) >= 100 && (__WATCOMC__) <= 9999) && \
	( \
		( \
			((min) >= 0 && (min) <= 9) && \
			((__WATCOMC__) >= (100 * (maj) + 10 * (min))) \
		) || \
		( \
			((min) >= 10 && (min) <= 99) && \
			((__WATCOMC__) >= (100 * (maj) + 1 * (min))) \
		) \
	) \
)
#else
#define mk_lang_compiler_is_at_least_watcom_c(maj, min) 0
#endif

#if defined __WATCOM_CPLUSPLUS__
#define mk_lang_compiler_is_at_least_watcom_cpp(maj, min) \
( \
	((maj) >= 1 && (maj) <= 99) && \
	((min) >= 0 && (min) <= 99) && \
	((__WATCOM_CPLUSPLUS__) >= 100 && (__WATCOM_CPLUSPLUS__) <= 9999) && \
	( \
		( \
			((min) >= 0 && (min) <= 9) && \
			((__WATCOM_CPLUSPLUS__) >= (100 * (maj) + 10 * (min))) \
		) || \
		( \
			((min) >= 10 && (min) <= 99) && \
			((__WATCOM_CPLUSPLUS__) >= (100 * (maj) + 1 * (min))) \
		) \
	) \
)
#else
#define mk_lang_compiler_is_at_least_watcom_cpp(maj, min) 0
#endif

#if 0
#elif defined __WATCOMC__ && !defined __WATCOM_CPLUSPLUS__
#define mk_lang_compiler_is_at_least_watcom(maj, min) mk_lang_compiler_is_at_least_watcom_c((maj), (min))
#elif !defined __WATCOMC__ && defined __WATCOM_CPLUSPLUS__
#define mk_lang_compiler_is_at_least_watcom(maj, min) mk_lang_compiler_is_at_least_watcom_cpp((maj), (min))
#elif defined __WATCOMC__ && defined __WATCOM_CPLUSPLUS__
#define mk_lang_compiler_is_at_least_watcom(maj, min) mk_lang_compiler_is_at_least_watcom_cpp((maj), (min))
#elif !defined __WATCOMC__ && !defined __WATCOM_CPLUSPLUS__
#define mk_lang_compiler_is_at_least_watcom(maj, min) 0
#endif

#if defined __clang__ && defined __clang_major__ && defined __clang_minor__
#define mk_lang_compiler_is_at_least_clang(maj, min) \
( \
	((maj) >= 1 && (maj) <= 99) && \
	((min) >= 0 && (min) <= 99) && \
	((__clang_major__) >= 1 && (__clang_major__) <= 99) && \
	((__clang_minor__) >= 0 && (__clang_minor__) <= 99) && \
	( \
		((__clang_major__) > (maj)) || \
		(((__clang_major__) == (maj)) && ((__clang_minor__) >= (min))) \
	) \
)
#else
#define mk_lang_compiler_is_at_least_clang(maj, min) 0
#endif

#if defined __GNUC__ && defined __GNUC_MINOR__ && !defined __clang__ && !defined __clang_major__ && !defined __clang_minor__
#define mk_lang_compiler_is_at_least_gcc(maj, min) \
( \
	((maj) >= 1 && (maj) <= 99) && \
	((min) >= 0 && (min) <= 99) && \
	((__GNUC__) >= 1 && (__GNUC__) <= 99) && \
	((__GNUC_MINOR__) >= 0 && (__GNUC_MINOR__) <= 99) && \
	( \
		((__GNUC__) > (maj)) || \
		(((__GNUC__) == (maj)) && ((__GNUC_MINOR__) >= (min))) \
	) \
)
#else
#define mk_lang_compiler_is_at_least_gcc(maj, min) 0
#endif


#endif
