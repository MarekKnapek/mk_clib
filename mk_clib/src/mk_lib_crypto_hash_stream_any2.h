#ifndef mk_include_guard_mk_lib_crypto_hash_stream_any2_h
#define mk_include_guard_mk_lib_crypto_hash_stream_any2_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_any1.h"
#include "mk_sl_cui_uint8.h"

#include "mk_lib_crypto_hash_stream_md2.h"
#include "mk_lib_crypto_hash_stream_md4.h"
#include "mk_lib_crypto_hash_stream_md5.h"
#include "mk_lib_crypto_hash_stream_sha0.h"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_lib_crypto_hash_stream_sha2_224.h"
#include "mk_lib_crypto_hash_stream_sha2_256.h"
#include "mk_lib_crypto_hash_stream_sha2_384.h"
#include "mk_lib_crypto_hash_stream_sha2_512.h"
#include "mk_lib_crypto_hash_stream_sha2_512_224.h"
#include "mk_lib_crypto_hash_stream_sha2_512_256.h"
#include "mk_lib_crypto_hash_stream_sha3_224.h"
#include "mk_lib_crypto_hash_stream_sha3_256.h"
#include "mk_lib_crypto_hash_stream_sha3_384.h"
#include "mk_lib_crypto_hash_stream_sha3_512.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_crypto_hash_stream_any2_md2_s         { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_md2_t          m_md2;          }; typedef struct mk_lib_crypto_hash_stream_any2_md2_s          mk_lib_crypto_hash_stream_any2_md2_t         ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_md2         );
struct mk_lib_crypto_hash_stream_any2_md4_s         { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_md4_t          m_md4;          }; typedef struct mk_lib_crypto_hash_stream_any2_md4_s          mk_lib_crypto_hash_stream_any2_md4_t         ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_md4         );
struct mk_lib_crypto_hash_stream_any2_md5_s         { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_md5_t          m_md5;          }; typedef struct mk_lib_crypto_hash_stream_any2_md5_s          mk_lib_crypto_hash_stream_any2_md5_t         ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_md5         );
struct mk_lib_crypto_hash_stream_any2_sha0_s        { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha0_t         m_sha0;         }; typedef struct mk_lib_crypto_hash_stream_any2_sha0_s         mk_lib_crypto_hash_stream_any2_sha0_t        ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha0        );
struct mk_lib_crypto_hash_stream_any2_sha1_s        { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha1_t         m_sha1;         }; typedef struct mk_lib_crypto_hash_stream_any2_sha1_s         mk_lib_crypto_hash_stream_any2_sha1_t        ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha1        );
struct mk_lib_crypto_hash_stream_any2_sha2_224_s    { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha2_224_t     m_sha2_224;     }; typedef struct mk_lib_crypto_hash_stream_any2_sha2_224_s     mk_lib_crypto_hash_stream_any2_sha2_224_t    ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha2_224    );
struct mk_lib_crypto_hash_stream_any2_sha2_256_s    { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha2_256_t     m_sha2_256;     }; typedef struct mk_lib_crypto_hash_stream_any2_sha2_256_s     mk_lib_crypto_hash_stream_any2_sha2_256_t    ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha2_256    );
struct mk_lib_crypto_hash_stream_any2_sha2_384_s    { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha2_384_t     m_sha2_384;     }; typedef struct mk_lib_crypto_hash_stream_any2_sha2_384_s     mk_lib_crypto_hash_stream_any2_sha2_384_t    ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha2_384    );
struct mk_lib_crypto_hash_stream_any2_sha2_512_s    { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha2_512_t     m_sha2_512;     }; typedef struct mk_lib_crypto_hash_stream_any2_sha2_512_s     mk_lib_crypto_hash_stream_any2_sha2_512_t    ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha2_512    );
struct mk_lib_crypto_hash_stream_any2_sha2_512_224_s{ mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha2_512_224_t m_sha2_512_224; }; typedef struct mk_lib_crypto_hash_stream_any2_sha2_512_224_s mk_lib_crypto_hash_stream_any2_sha2_512_224_t; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha2_512_224);
struct mk_lib_crypto_hash_stream_any2_sha2_512_256_s{ mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha2_512_256_t m_sha2_512_256; }; typedef struct mk_lib_crypto_hash_stream_any2_sha2_512_256_s mk_lib_crypto_hash_stream_any2_sha2_512_256_t; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha2_512_256);
struct mk_lib_crypto_hash_stream_any2_sha3_224_s    { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha3_224_t     m_sha3_224;     }; typedef struct mk_lib_crypto_hash_stream_any2_sha3_224_s     mk_lib_crypto_hash_stream_any2_sha3_224_t    ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha3_224    );
struct mk_lib_crypto_hash_stream_any2_sha3_256_s    { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha3_256_t     m_sha3_256;     }; typedef struct mk_lib_crypto_hash_stream_any2_sha3_256_s     mk_lib_crypto_hash_stream_any2_sha3_256_t    ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha3_256    );
struct mk_lib_crypto_hash_stream_any2_sha3_384_s    { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha3_384_t     m_sha3_384;     }; typedef struct mk_lib_crypto_hash_stream_any2_sha3_384_s     mk_lib_crypto_hash_stream_any2_sha3_384_t    ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha3_384    );
struct mk_lib_crypto_hash_stream_any2_sha3_512_s    { mk_lib_crypto_hash_stream_any1_id_t m_id; mk_lib_crypto_hash_stream_sha3_512_t     m_sha3_512;     }; typedef struct mk_lib_crypto_hash_stream_any2_sha3_512_s     mk_lib_crypto_hash_stream_any2_sha3_512_t    ; mk_lang_typedef(mk_lib_crypto_hash_stream_any2_sha3_512    );
#include "mk_lang_warning_msvc_pop.h"


union mk_lib_crypto_hash_stream_any2_data_u
{
	mk_lib_crypto_hash_stream_any1_id_t m_id;
	mk_lib_crypto_hash_stream_any2_md2_t m_md2;
	mk_lib_crypto_hash_stream_any2_md4_t m_md4;
	mk_lib_crypto_hash_stream_any2_md5_t m_md5;
	mk_lib_crypto_hash_stream_any2_sha0_t m_sha0;
	mk_lib_crypto_hash_stream_any2_sha1_t m_sha1;
	mk_lib_crypto_hash_stream_any2_sha2_224_t m_sha2_224;
	mk_lib_crypto_hash_stream_any2_sha2_256_t m_sha2_256;
	mk_lib_crypto_hash_stream_any2_sha2_384_t m_sha2_384;
	mk_lib_crypto_hash_stream_any2_sha2_512_t m_sha2_512;
	mk_lib_crypto_hash_stream_any2_sha2_512_224_t m_sha2_512_224;
	mk_lib_crypto_hash_stream_any2_sha2_512_256_t m_sha2_512_256;
	mk_lib_crypto_hash_stream_any2_sha3_224_t m_sha3_224;
	mk_lib_crypto_hash_stream_any2_sha3_256_t m_sha3_256;
	mk_lib_crypto_hash_stream_any2_sha3_384_t m_sha3_384;
	mk_lib_crypto_hash_stream_any2_sha3_512_t m_sha3_512;
};
typedef union mk_lib_crypto_hash_stream_any2_data_u mk_lib_crypto_hash_stream_any2_data_t;
struct mk_lib_crypto_hash_stream_any2_s
{
	mk_lib_crypto_hash_stream_any2_data_t m_data;
};
typedef struct mk_lib_crypto_hash_stream_any2_s mk_lib_crypto_hash_stream_any2_t;
mk_lang_typedef(mk_lib_crypto_hash_stream_any2);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any2_init(mk_lib_crypto_hash_stream_any2_pt const hash_stream_any2, mk_lib_crypto_hash_stream_any1_id_t const id) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any2_append_u8s(mk_lib_crypto_hash_stream_any2_pt const hash_stream_any2, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any2_finish(mk_lib_crypto_hash_stream_any2_pt const hash_stream_any2, mk_sl_cui_uint8_pt const digest) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_hash_stream_any2_digest_len(mk_lib_crypto_hash_stream_any2_pct const hash_stream_any2) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_hash_stream_any2.c"
#endif
#endif
