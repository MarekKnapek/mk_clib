#ifndef mk_include_guard_mk_lib_posix_headers
#define mk_include_guard_mk_lib_posix_headers


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if defined mk_lib_posix_headers_want && (mk_lib_posix_headers_want) == 1
#define mk_lib_posix_headers_have 1
#else
#define mk_lib_posix_headers_have 0
#endif


#if mk_lib_posix_headers_have


#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>


#else


#if !defined errno
extern mk_lang_types_sint_t errno;
#endif
typedef mk_lang_types_sint_t zzz_some_int_ino_t;
typedef mk_lang_types_sint_t zzz_some_int_off_t;
typedef mk_lang_types_sint_t zzz_some_int_mode_t;


struct DIR; typedef struct DIR DIR;
struct dirent
{
	zzz_some_int_ino_t d_ino;
	zzz_some_int_off_t d_off;
	mk_lang_types_ushort_t d_reclen;
	mk_lang_types_uchar_t d_type;
	mk_lang_types_pchar_t d_name[256];
};
mk_lang_nodiscard mk_lang_jumbo DIR* opendir(mk_lang_types_pchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t closedir(DIR* const dir) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo struct dirent* readdir(DIR* const dir) mk_lang_noexcept;


struct stat
{
	zzz_some_int_mode_t st_mode; /* todo add moar members */
};
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t stat(mk_lang_types_pchar_pct const path, struct stat* const st) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t S_ISDIR(zzz_some_int_mode_t const st_mode) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_want == 1
#include "mk_lib_posix_headers.c"
#endif
#endif
