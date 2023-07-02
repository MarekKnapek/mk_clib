#define mk_lang_jumbo_want 1

#include "../../src/mk_lang_assert.h"
#include "../../src/mk_lang_constexpr.h"
#include "../../src/mk_lang_cpp.h"
#include "../../src/mk_lang_emscripten.h"
#include "../../src/mk_lang_inline.h"
#include "../../src/mk_lang_likely.h"
#include "../../src/mk_lang_nodiscard.h"
#include "../../src/mk_lang_noexcept.h"
#include "../../src/mk_lang_static_assert.h"
#include "../../src/mk_lang_stringify.h"
#include "../../src/mk_lang_types.h"
#include "../../src/mk_lib_crypto_hash_stream_blake2b_256.h"
#include "../../src/mk_lib_crypto_hash_stream_blake2b_384.h"
#include "../../src/mk_lib_crypto_hash_stream_blake2b_512.h"
#include "../../src/mk_lib_crypto_hash_stream_blake2s_128.h"
#include "../../src/mk_lib_crypto_hash_stream_blake2s_160.h"
#include "../../src/mk_lib_crypto_hash_stream_blake2s_224.h"
#include "../../src/mk_lib_crypto_hash_stream_blake2s_256.h"
#include "../../src/mk_lib_crypto_hash_stream_blake3.h"
#include "../../src/mk_lib_crypto_hash_stream_md2.h"
#include "../../src/mk_lib_crypto_hash_stream_md4.h"
#include "../../src/mk_lib_crypto_hash_stream_md5.h"
#include "../../src/mk_lib_crypto_hash_stream_sha0.h"
#include "../../src/mk_lib_crypto_hash_stream_sha1.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_224.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_256.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_384.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_512.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_512_224.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_512_256.h"
#include "../../src/mk_lib_crypto_hash_stream_sha3_224.h"
#include "../../src/mk_lib_crypto_hash_stream_sha3_256.h"
#include "../../src/mk_lib_crypto_hash_stream_sha3_384.h"
#include "../../src/mk_lib_crypto_hash_stream_sha3_512.h"
#include "../../src/mk_lib_crypto_hash_stream_tiger2_128.h"
#include "../../src/mk_lib_crypto_hash_stream_tiger2_160.h"
#include "../../src/mk_lib_crypto_hash_stream_tiger2_192.h"
#include "../../src/mk_lib_crypto_hash_stream_tiger_128.h"
#include "../../src/mk_lib_crypto_hash_stream_tiger_160.h"
#include "../../src/mk_lib_crypto_hash_stream_tiger_192.h"
#include "../../src/mk_lib_crypto_xof_stream_shake_128.h"
#include "../../src/mk_lib_crypto_xof_stream_shake_256.h"
#include "../../src/mk_sl_uint8.h"


enum alg_id_e
{
	alg_id_e_hash_blake2b_256 ,
	alg_id_e_hash_blake2b_384 ,
	alg_id_e_hash_blake2b_512 ,
	alg_id_e_hash_blake2s_128 ,
	alg_id_e_hash_blake2s_160 ,
	alg_id_e_hash_blake2s_224 ,
	alg_id_e_hash_blake2s_256 ,
	alg_id_e_hash_blake3      ,
	alg_id_e_hash_md2         ,
	alg_id_e_hash_md4         ,
	alg_id_e_hash_md5         ,
	alg_id_e_hash_sha0        ,
	alg_id_e_hash_sha1        ,
	alg_id_e_hash_sha2_224    ,
	alg_id_e_hash_sha2_256    ,
	alg_id_e_hash_sha2_384    ,
	alg_id_e_hash_sha2_512    ,
	alg_id_e_hash_sha2_512_224,
	alg_id_e_hash_sha2_512_256,
	alg_id_e_hash_sha3_224    ,
	alg_id_e_hash_sha3_256    ,
	alg_id_e_hash_sha3_384    ,
	alg_id_e_hash_sha3_512    ,
	alg_id_e_hash_tiger2_128  ,
	alg_id_e_hash_tiger2_160  ,
	alg_id_e_hash_tiger2_192  ,
	alg_id_e_hash_tiger_128   ,
	alg_id_e_hash_tiger_160   ,
	alg_id_e_hash_tiger_192   ,
	alg_id_e_xof_shake_128    ,
	alg_id_e_xof_shake_256    ,
	alg_id_e_dummy_end
};
typedef enum alg_id_e alg_id_t;

#define alg_name_dn_hash_blake2b_256  "blake2b_256"
#define alg_name_dn_hash_blake2b_384  "blake2b_384"
#define alg_name_dn_hash_blake2b_512  "blake2b_512"
#define alg_name_dn_hash_blake2s_128  "blake2s_128"
#define alg_name_dn_hash_blake2s_160  "blake2s_160"
#define alg_name_dn_hash_blake2s_224  "blake2s_224"
#define alg_name_dn_hash_blake2s_256  "blake2s_256"
#define alg_name_dn_hash_blake3       "blake3"
#define alg_name_dn_hash_md2          "md2"
#define alg_name_dn_hash_md4          "md4"
#define alg_name_dn_hash_md5          "md5"
#define alg_name_dn_hash_sha0         "sha0"
#define alg_name_dn_hash_sha1         "sha1"
#define alg_name_dn_hash_sha2_224     "sha2_224"
#define alg_name_dn_hash_sha2_256     "sha2_256"
#define alg_name_dn_hash_sha2_384     "sha2_384"
#define alg_name_dn_hash_sha2_512     "sha2_512"
#define alg_name_dn_hash_sha2_512_224 "sha2_512_224"
#define alg_name_dn_hash_sha2_512_256 "sha2_512_256"
#define alg_name_dn_hash_sha3_224     "sha3_224"
#define alg_name_dn_hash_sha3_256     "sha3_256"
#define alg_name_dn_hash_sha3_384     "sha3_384"
#define alg_name_dn_hash_sha3_512     "sha3_512"
#define alg_name_dn_hash_tiger2_128   "tiger2_128"
#define alg_name_dn_hash_tiger2_160   "tiger2_160"
#define alg_name_dn_hash_tiger2_192   "tiger2_192"
#define alg_name_dn_hash_tiger_128    "tiger_128"
#define alg_name_dn_hash_tiger_160    "tiger_160"
#define alg_name_dn_hash_tiger_192    "tiger_192"
#define alg_name_dn_xof_shake_128     "shake_128"
#define alg_name_dn_xof_shake_256     "shake_256"

#define alg_name_dl_hash_blake2b_256  ((int)(sizeof(alg_name_dn_hash_blake2b_256 ) / sizeof(alg_name_dn_hash_blake2b_256 [0]) - 1))
#define alg_name_dl_hash_blake2b_384  ((int)(sizeof(alg_name_dn_hash_blake2b_384 ) / sizeof(alg_name_dn_hash_blake2b_384 [0]) - 1))
#define alg_name_dl_hash_blake2b_512  ((int)(sizeof(alg_name_dn_hash_blake2b_512 ) / sizeof(alg_name_dn_hash_blake2b_512 [0]) - 1))
#define alg_name_dl_hash_blake2s_128  ((int)(sizeof(alg_name_dn_hash_blake2s_128 ) / sizeof(alg_name_dn_hash_blake2s_128 [0]) - 1))
#define alg_name_dl_hash_blake2s_160  ((int)(sizeof(alg_name_dn_hash_blake2s_160 ) / sizeof(alg_name_dn_hash_blake2s_160 [0]) - 1))
#define alg_name_dl_hash_blake2s_224  ((int)(sizeof(alg_name_dn_hash_blake2s_224 ) / sizeof(alg_name_dn_hash_blake2s_224 [0]) - 1))
#define alg_name_dl_hash_blake2s_256  ((int)(sizeof(alg_name_dn_hash_blake2s_256 ) / sizeof(alg_name_dn_hash_blake2s_256 [0]) - 1))
#define alg_name_dl_hash_blake3       ((int)(sizeof(alg_name_dn_hash_blake3      ) / sizeof(alg_name_dn_hash_blake3      [0]) - 1))
#define alg_name_dl_hash_md2          ((int)(sizeof(alg_name_dn_hash_md2         ) / sizeof(alg_name_dn_hash_md2         [0]) - 1))
#define alg_name_dl_hash_md4          ((int)(sizeof(alg_name_dn_hash_md4         ) / sizeof(alg_name_dn_hash_md4         [0]) - 1))
#define alg_name_dl_hash_md5          ((int)(sizeof(alg_name_dn_hash_md5         ) / sizeof(alg_name_dn_hash_md5         [0]) - 1))
#define alg_name_dl_hash_sha0         ((int)(sizeof(alg_name_dn_hash_sha0        ) / sizeof(alg_name_dn_hash_sha0        [0]) - 1))
#define alg_name_dl_hash_sha1         ((int)(sizeof(alg_name_dn_hash_sha1        ) / sizeof(alg_name_dn_hash_sha1        [0]) - 1))
#define alg_name_dl_hash_sha2_224     ((int)(sizeof(alg_name_dn_hash_sha2_224    ) / sizeof(alg_name_dn_hash_sha2_224    [0]) - 1))
#define alg_name_dl_hash_sha2_256     ((int)(sizeof(alg_name_dn_hash_sha2_256    ) / sizeof(alg_name_dn_hash_sha2_256    [0]) - 1))
#define alg_name_dl_hash_sha2_384     ((int)(sizeof(alg_name_dn_hash_sha2_384    ) / sizeof(alg_name_dn_hash_sha2_384    [0]) - 1))
#define alg_name_dl_hash_sha2_512     ((int)(sizeof(alg_name_dn_hash_sha2_512    ) / sizeof(alg_name_dn_hash_sha2_512    [0]) - 1))
#define alg_name_dl_hash_sha2_512_224 ((int)(sizeof(alg_name_dn_hash_sha2_512_224) / sizeof(alg_name_dn_hash_sha2_512_224[0]) - 1))
#define alg_name_dl_hash_sha2_512_256 ((int)(sizeof(alg_name_dn_hash_sha2_512_256) / sizeof(alg_name_dn_hash_sha2_512_256[0]) - 1))
#define alg_name_dl_hash_sha3_224     ((int)(sizeof(alg_name_dn_hash_sha3_224    ) / sizeof(alg_name_dn_hash_sha3_224    [0]) - 1))
#define alg_name_dl_hash_sha3_256     ((int)(sizeof(alg_name_dn_hash_sha3_256    ) / sizeof(alg_name_dn_hash_sha3_256    [0]) - 1))
#define alg_name_dl_hash_sha3_384     ((int)(sizeof(alg_name_dn_hash_sha3_384    ) / sizeof(alg_name_dn_hash_sha3_384    [0]) - 1))
#define alg_name_dl_hash_sha3_512     ((int)(sizeof(alg_name_dn_hash_sha3_512    ) / sizeof(alg_name_dn_hash_sha3_512    [0]) - 1))
#define alg_name_dl_hash_tiger2_128   ((int)(sizeof(alg_name_dn_hash_tiger2_128  ) / sizeof(alg_name_dn_hash_tiger2_128  [0]) - 1))
#define alg_name_dl_hash_tiger2_160   ((int)(sizeof(alg_name_dn_hash_tiger2_160  ) / sizeof(alg_name_dn_hash_tiger2_160  [0]) - 1))
#define alg_name_dl_hash_tiger2_192   ((int)(sizeof(alg_name_dn_hash_tiger2_192  ) / sizeof(alg_name_dn_hash_tiger2_192  [0]) - 1))
#define alg_name_dl_hash_tiger_128    ((int)(sizeof(alg_name_dn_hash_tiger_128   ) / sizeof(alg_name_dn_hash_tiger_128   [0]) - 1))
#define alg_name_dl_hash_tiger_160    ((int)(sizeof(alg_name_dn_hash_tiger_160   ) / sizeof(alg_name_dn_hash_tiger_160   [0]) - 1))
#define alg_name_dl_hash_tiger_192    ((int)(sizeof(alg_name_dn_hash_tiger_192   ) / sizeof(alg_name_dn_hash_tiger_192   [0]) - 1))
#define alg_name_dl_xof_shake_128     ((int)(sizeof(alg_name_dn_xof_shake_128    ) / sizeof(alg_name_dn_xof_shake_128    [0]) - 1))
#define alg_name_dl_xof_shake_256     ((int)(sizeof(alg_name_dn_xof_shake_256    ) / sizeof(alg_name_dn_xof_shake_256    [0]) - 1))

mk_lang_constexpr_static_inline char const s_alg_names[] =
	alg_name_dn_hash_blake2b_256
	alg_name_dn_hash_blake2b_384
	alg_name_dn_hash_blake2b_512
	alg_name_dn_hash_blake2s_128
	alg_name_dn_hash_blake2s_160
	alg_name_dn_hash_blake2s_224
	alg_name_dn_hash_blake2s_256
	alg_name_dn_hash_blake3
	alg_name_dn_hash_md2
	alg_name_dn_hash_md4
	alg_name_dn_hash_md5
	alg_name_dn_hash_sha0
	alg_name_dn_hash_sha1
	alg_name_dn_hash_sha2_224
	alg_name_dn_hash_sha2_256
	alg_name_dn_hash_sha2_384
	alg_name_dn_hash_sha2_512
	alg_name_dn_hash_sha2_512_224
	alg_name_dn_hash_sha2_512_256
	alg_name_dn_hash_sha3_224
	alg_name_dn_hash_sha3_256
	alg_name_dn_hash_sha3_384
	alg_name_dn_hash_sha3_512
	alg_name_dn_hash_tiger2_128
	alg_name_dn_hash_tiger2_160
	alg_name_dn_hash_tiger2_192
	alg_name_dn_hash_tiger_128
	alg_name_dn_hash_tiger_160
	alg_name_dn_hash_tiger_192
	alg_name_dn_xof_shake_128
	alg_name_dn_xof_shake_256
;

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_alg_name_lens[] =
{
	((mk_lang_types_uchar_t)(alg_name_dl_hash_blake2b_256 )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_blake2b_384 )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_blake2b_512 )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_blake2s_128 )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_blake2s_160 )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_blake2s_224 )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_blake2s_256 )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_blake3      )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_md2         )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_md4         )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_md5         )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha0        )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha1        )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha2_224    )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha2_256    )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha2_384    )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha2_512    )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha2_512_224)),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha2_512_256)),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha3_224    )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha3_256    )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha3_384    )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_sha3_512    )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_tiger2_128  )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_tiger2_160  )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_tiger2_192  )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_tiger_128   )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_tiger_160   )),
	((mk_lang_types_uchar_t)(alg_name_dl_hash_tiger_192   )),
	((mk_lang_types_uchar_t)(alg_name_dl_xof_shake_128    )),
	((mk_lang_types_uchar_t)(alg_name_dl_xof_shake_256    )),
};

mk_lang_constexpr_static_inline char const s_alg_pretty_names[] =
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_256_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_384_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_512_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_128_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_160_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_224_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_256_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_blake3_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_md2_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_md4_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_md5_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha0_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha1_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_224_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_256_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_384_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_224_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_256_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha3_224_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha3_256_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha3_384_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_sha3_512_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_128_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_160_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_192_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger_128_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger_160_name_def)
	mk_lang_stringify(mk_lib_crypto_hash_block_tiger_192_name_def)
	mk_lang_stringify(mk_lib_crypto_xof_block_shake_128_name_def)
	mk_lang_stringify(mk_lib_crypto_xof_block_shake_256_name_def)
;

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_alg_pretty_name_lens[] =
{
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_256_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_384_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2b_512_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_128_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_160_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_224_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake2s_256_name_def )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_blake3_name_def      )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_md2_name_def         )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_md4_name_def         )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_md5_name_def         )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha0_name_def        )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha1_name_def        )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_224_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_256_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_384_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_224_name_def)) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha2_512_256_name_def)) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha3_224_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha3_256_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha3_384_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_sha3_512_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_128_name_def  )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_160_name_def  )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger2_192_name_def  )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger_128_name_def   )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger_160_name_def   )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_hash_block_tiger_192_name_def   )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_xof_block_shake_128_name_def    )) - 1)))),
	((mk_lang_types_uchar_t)(((int)(sizeof(mk_lang_stringify(mk_lib_crypto_xof_block_shake_256_name_def    )) - 1)))),
};

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_alg_order[] =
{
	((mk_lang_types_uchar_t)(alg_id_e_hash_md2         )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_md4         )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_md5         )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha0        )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha1        )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha2_224    )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha2_256    )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha2_384    )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha2_512    )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha2_512_224)),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha2_512_256)),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha3_224    )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha3_256    )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha3_384    )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_sha3_512    )),
	((mk_lang_types_uchar_t)(alg_id_e_xof_shake_128    )),
	((mk_lang_types_uchar_t)(alg_id_e_xof_shake_256    )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_tiger_128   )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_tiger_160   )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_tiger_192   )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_tiger2_128  )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_tiger2_160  )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_tiger2_192  )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_blake2b_256 )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_blake2b_384 )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_blake2b_512 )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_blake2s_128 )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_blake2s_160 )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_blake2s_224 )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_blake2s_256 )),
	((mk_lang_types_uchar_t)(alg_id_e_hash_blake3      )),
};

union alg_u
{
	mk_lib_crypto_hash_stream_blake2b_256_t  m_blake2b_256 ;
	mk_lib_crypto_hash_stream_blake2b_384_t  m_blake2b_384 ;
	mk_lib_crypto_hash_stream_blake2b_512_t  m_blake2b_512 ;
	mk_lib_crypto_hash_stream_blake2s_128_t  m_blake2s_128 ;
	mk_lib_crypto_hash_stream_blake2s_160_t  m_blake2s_160 ;
	mk_lib_crypto_hash_stream_blake2s_224_t  m_blake2s_224 ;
	mk_lib_crypto_hash_stream_blake2s_256_t  m_blake2s_256 ;
	mk_lib_crypto_hash_stream_blake3_t       m_blake3      ;
	mk_lib_crypto_hash_stream_md2_t          m_md2         ;
	mk_lib_crypto_hash_stream_md4_t          m_md4         ;
	mk_lib_crypto_hash_stream_md5_t          m_md5         ;
	mk_lib_crypto_hash_stream_sha0_t         m_sha0        ;
	mk_lib_crypto_hash_stream_sha1_t         m_sha1        ;
	mk_lib_crypto_hash_stream_sha2_224_t     m_sha2_224    ;
	mk_lib_crypto_hash_stream_sha2_256_t     m_sha2_256    ;
	mk_lib_crypto_hash_stream_sha2_384_t     m_sha2_384    ;
	mk_lib_crypto_hash_stream_sha2_512_224_t m_sha2_512_224;
	mk_lib_crypto_hash_stream_sha2_512_256_t m_sha2_512_256;
	mk_lib_crypto_hash_stream_sha2_512_t     m_sha2_512    ;
	mk_lib_crypto_hash_stream_sha3_224_t     m_sha3_224    ;
	mk_lib_crypto_hash_stream_sha3_256_t     m_sha3_256    ;
	mk_lib_crypto_hash_stream_sha3_384_t     m_sha3_384    ;
	mk_lib_crypto_hash_stream_sha3_512_t     m_sha3_512    ;
	mk_lib_crypto_hash_stream_tiger2_128_t   m_tiger2_128  ;
	mk_lib_crypto_hash_stream_tiger2_160_t   m_tiger2_160  ;
	mk_lib_crypto_hash_stream_tiger2_192_t   m_tiger2_192  ;
	mk_lib_crypto_hash_stream_tiger_128_t    m_tiger_128   ;
	mk_lib_crypto_hash_stream_tiger_160_t    m_tiger_160   ;
	mk_lib_crypto_hash_stream_tiger_192_t    m_tiger_192   ;
	mk_lib_crypto_xof_stream_shake_128_t     m_shake_128   ;
	mk_lib_crypto_xof_stream_shake_256_t     m_shake_256   ;
};
typedef union alg_u alg_t;
typedef alg_t* alg_pt;


union aligned16k_u
{
	mk_sl_cui_uint8_t m_uint8s[16 * 1024];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union aligned16k_u aligned16k_t;
typedef aligned16k_t const aligned16k_ct;
typedef aligned16k_t* aligned16k_pt;
typedef aligned16k_t const* aligned16k_pct;

union aligned1m_u
{
	mk_sl_cui_uint8_t m_uint8s[1 * 1024 * 1024];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union aligned1m_u aligned1m_t;
typedef aligned1m_t const aligned1m_ct;
typedef aligned1m_t* aligned1m_pt;
typedef aligned1m_t const* aligned1m_pct;


static mk_lang_inline void init(alg_pt const alg, alg_id_t const id) mk_lang_noexcept
{
	switch(id)
	{
		case alg_id_e_hash_blake2b_256 : mk_lib_crypto_hash_stream_blake2b_256_init (&alg->m_blake2b_256 ); break;
		case alg_id_e_hash_blake2b_384 : mk_lib_crypto_hash_stream_blake2b_384_init (&alg->m_blake2b_384 ); break;
		case alg_id_e_hash_blake2b_512 : mk_lib_crypto_hash_stream_blake2b_512_init (&alg->m_blake2b_512 ); break;
		case alg_id_e_hash_blake2s_128 : mk_lib_crypto_hash_stream_blake2s_128_init (&alg->m_blake2s_128 ); break;
		case alg_id_e_hash_blake2s_160 : mk_lib_crypto_hash_stream_blake2s_160_init (&alg->m_blake2s_160 ); break;
		case alg_id_e_hash_blake2s_224 : mk_lib_crypto_hash_stream_blake2s_224_init (&alg->m_blake2s_224 ); break;
		case alg_id_e_hash_blake2s_256 : mk_lib_crypto_hash_stream_blake2s_256_init (&alg->m_blake2s_256 ); break;
		case alg_id_e_hash_blake3      : mk_lib_crypto_hash_stream_blake3_init      (&alg->m_blake3      ); break;
		case alg_id_e_hash_md2         : mk_lib_crypto_hash_stream_md2_init         (&alg->m_md2         ); break;
		case alg_id_e_hash_md4         : mk_lib_crypto_hash_stream_md4_init         (&alg->m_md4         ); break;
		case alg_id_e_hash_md5         : mk_lib_crypto_hash_stream_md5_init         (&alg->m_md5         ); break;
		case alg_id_e_hash_sha0        : mk_lib_crypto_hash_stream_sha0_init        (&alg->m_sha0        ); break;
		case alg_id_e_hash_sha1        : mk_lib_crypto_hash_stream_sha1_init        (&alg->m_sha1        ); break;
		case alg_id_e_hash_sha2_224    : mk_lib_crypto_hash_stream_sha2_224_init    (&alg->m_sha2_224    ); break;
		case alg_id_e_hash_sha2_256    : mk_lib_crypto_hash_stream_sha2_256_init    (&alg->m_sha2_256    ); break;
		case alg_id_e_hash_sha2_384    : mk_lib_crypto_hash_stream_sha2_384_init    (&alg->m_sha2_384    ); break;
		case alg_id_e_hash_sha2_512    : mk_lib_crypto_hash_stream_sha2_512_init    (&alg->m_sha2_512    ); break;
		case alg_id_e_hash_sha2_512_224: mk_lib_crypto_hash_stream_sha2_512_224_init(&alg->m_sha2_512_224); break;
		case alg_id_e_hash_sha2_512_256: mk_lib_crypto_hash_stream_sha2_512_256_init(&alg->m_sha2_512_256); break;
		case alg_id_e_hash_sha3_224    : mk_lib_crypto_hash_stream_sha3_224_init    (&alg->m_sha3_224    ); break;
		case alg_id_e_hash_sha3_256    : mk_lib_crypto_hash_stream_sha3_256_init    (&alg->m_sha3_256    ); break;
		case alg_id_e_hash_sha3_384    : mk_lib_crypto_hash_stream_sha3_384_init    (&alg->m_sha3_384    ); break;
		case alg_id_e_hash_sha3_512    : mk_lib_crypto_hash_stream_sha3_512_init    (&alg->m_sha3_512    ); break;
		case alg_id_e_hash_tiger2_128  : mk_lib_crypto_hash_stream_tiger2_128_init  (&alg->m_tiger2_128  ); break;
		case alg_id_e_hash_tiger2_160  : mk_lib_crypto_hash_stream_tiger2_160_init  (&alg->m_tiger2_160  ); break;
		case alg_id_e_hash_tiger2_192  : mk_lib_crypto_hash_stream_tiger2_192_init  (&alg->m_tiger2_192  ); break;
		case alg_id_e_hash_tiger_128   : mk_lib_crypto_hash_stream_tiger_128_init   (&alg->m_tiger_128   ); break;
		case alg_id_e_hash_tiger_160   : mk_lib_crypto_hash_stream_tiger_160_init   (&alg->m_tiger_160   ); break;
		case alg_id_e_hash_tiger_192   : mk_lib_crypto_hash_stream_tiger_192_init   (&alg->m_tiger_192   ); break;
		case alg_id_e_xof_shake_128    : mk_lib_crypto_xof_stream_shake_128_init    (&alg->m_shake_128   ); break;
		case alg_id_e_xof_shake_256    : mk_lib_crypto_xof_stream_shake_256_init    (&alg->m_shake_256   ); break;
	}
}

static mk_lang_inline void append(alg_pt const alg, alg_id_t const id, mk_lang_types_uchar_pct const msg, mk_lang_types_usize_t const msg_len) mk_lang_noexcept
{
	switch(id)
	{
		case alg_id_e_hash_blake2b_256 : mk_lib_crypto_hash_stream_blake2b_256_append (&alg->m_blake2b_256 , msg, msg_len); break;
		case alg_id_e_hash_blake2b_384 : mk_lib_crypto_hash_stream_blake2b_384_append (&alg->m_blake2b_384 , msg, msg_len); break;
		case alg_id_e_hash_blake2b_512 : mk_lib_crypto_hash_stream_blake2b_512_append (&alg->m_blake2b_512 , msg, msg_len); break;
		case alg_id_e_hash_blake2s_128 : mk_lib_crypto_hash_stream_blake2s_128_append (&alg->m_blake2s_128 , msg, msg_len); break;
		case alg_id_e_hash_blake2s_160 : mk_lib_crypto_hash_stream_blake2s_160_append (&alg->m_blake2s_160 , msg, msg_len); break;
		case alg_id_e_hash_blake2s_224 : mk_lib_crypto_hash_stream_blake2s_224_append (&alg->m_blake2s_224 , msg, msg_len); break;
		case alg_id_e_hash_blake2s_256 : mk_lib_crypto_hash_stream_blake2s_256_append (&alg->m_blake2s_256 , msg, msg_len); break;
		case alg_id_e_hash_blake3      : mk_lib_crypto_hash_stream_blake3_append      (&alg->m_blake3      , msg, msg_len); break;
		case alg_id_e_hash_md2         : mk_lib_crypto_hash_stream_md2_append         (&alg->m_md2         , msg, msg_len); break;
		case alg_id_e_hash_md4         : mk_lib_crypto_hash_stream_md4_append         (&alg->m_md4         , msg, msg_len); break;
		case alg_id_e_hash_md5         : mk_lib_crypto_hash_stream_md5_append         (&alg->m_md5         , msg, msg_len); break;
		case alg_id_e_hash_sha0        : mk_lib_crypto_hash_stream_sha0_append        (&alg->m_sha0        , msg, msg_len); break;
		case alg_id_e_hash_sha1        : mk_lib_crypto_hash_stream_sha1_append        (&alg->m_sha1        , msg, msg_len); break;
		case alg_id_e_hash_sha2_224    : mk_lib_crypto_hash_stream_sha2_224_append    (&alg->m_sha2_224    , msg, msg_len); break;
		case alg_id_e_hash_sha2_256    : mk_lib_crypto_hash_stream_sha2_256_append    (&alg->m_sha2_256    , msg, msg_len); break;
		case alg_id_e_hash_sha2_384    : mk_lib_crypto_hash_stream_sha2_384_append    (&alg->m_sha2_384    , msg, msg_len); break;
		case alg_id_e_hash_sha2_512    : mk_lib_crypto_hash_stream_sha2_512_append    (&alg->m_sha2_512    , msg, msg_len); break;
		case alg_id_e_hash_sha2_512_224: mk_lib_crypto_hash_stream_sha2_512_224_append(&alg->m_sha2_512_224, msg, msg_len); break;
		case alg_id_e_hash_sha2_512_256: mk_lib_crypto_hash_stream_sha2_512_256_append(&alg->m_sha2_512_256, msg, msg_len); break;
		case alg_id_e_hash_sha3_224    : mk_lib_crypto_hash_stream_sha3_224_append    (&alg->m_sha3_224    , msg, msg_len); break;
		case alg_id_e_hash_sha3_256    : mk_lib_crypto_hash_stream_sha3_256_append    (&alg->m_sha3_256    , msg, msg_len); break;
		case alg_id_e_hash_sha3_384    : mk_lib_crypto_hash_stream_sha3_384_append    (&alg->m_sha3_384    , msg, msg_len); break;
		case alg_id_e_hash_sha3_512    : mk_lib_crypto_hash_stream_sha3_512_append    (&alg->m_sha3_512    , msg, msg_len); break;
		case alg_id_e_hash_tiger2_128  : mk_lib_crypto_hash_stream_tiger2_128_append  (&alg->m_tiger2_128  , msg, msg_len); break;
		case alg_id_e_hash_tiger2_160  : mk_lib_crypto_hash_stream_tiger2_160_append  (&alg->m_tiger2_160  , msg, msg_len); break;
		case alg_id_e_hash_tiger2_192  : mk_lib_crypto_hash_stream_tiger2_192_append  (&alg->m_tiger2_192  , msg, msg_len); break;
		case alg_id_e_hash_tiger_128   : mk_lib_crypto_hash_stream_tiger_128_append   (&alg->m_tiger_128   , msg, msg_len); break;
		case alg_id_e_hash_tiger_160   : mk_lib_crypto_hash_stream_tiger_160_append   (&alg->m_tiger_160   , msg, msg_len); break;
		case alg_id_e_hash_tiger_192   : mk_lib_crypto_hash_stream_tiger_192_append   (&alg->m_tiger_192   , msg, msg_len); break;
		case alg_id_e_xof_shake_128    : mk_lib_crypto_xof_stream_shake_128_append    (&alg->m_shake_128   , msg, msg_len); break;
		case alg_id_e_xof_shake_256    : mk_lib_crypto_xof_stream_shake_256_append    (&alg->m_shake_256   , msg, msg_len); break;
	}
}

static mk_lang_inline int finish(alg_pt const alg, alg_id_t const id, int const xof_len, aligned16k_pt const digest) mk_lang_noexcept
{
	switch(id)
	{
		case alg_id_e_hash_blake2b_256 : mk_lib_crypto_hash_stream_blake2b_256_finish (&alg->m_blake2b_256 ,          ((mk_lib_crypto_hash_block_blake2b_256_digest_pt )(digest))); return mk_lib_crypto_hash_block_blake2b_256_digest_len ; break;
		case alg_id_e_hash_blake2b_384 : mk_lib_crypto_hash_stream_blake2b_384_finish (&alg->m_blake2b_384 ,          ((mk_lib_crypto_hash_block_blake2b_384_digest_pt )(digest))); return mk_lib_crypto_hash_block_blake2b_384_digest_len ; break;
		case alg_id_e_hash_blake2b_512 : mk_lib_crypto_hash_stream_blake2b_512_finish (&alg->m_blake2b_512 ,          ((mk_lib_crypto_hash_block_blake2b_512_digest_pt )(digest))); return mk_lib_crypto_hash_block_blake2b_512_digest_len ; break;
		case alg_id_e_hash_blake2s_128 : mk_lib_crypto_hash_stream_blake2s_128_finish (&alg->m_blake2s_128 ,          ((mk_lib_crypto_hash_block_blake2s_128_digest_pt )(digest))); return mk_lib_crypto_hash_block_blake2s_128_digest_len ; break;
		case alg_id_e_hash_blake2s_160 : mk_lib_crypto_hash_stream_blake2s_160_finish (&alg->m_blake2s_160 ,          ((mk_lib_crypto_hash_block_blake2s_160_digest_pt )(digest))); return mk_lib_crypto_hash_block_blake2s_160_digest_len ; break;
		case alg_id_e_hash_blake2s_224 : mk_lib_crypto_hash_stream_blake2s_224_finish (&alg->m_blake2s_224 ,          ((mk_lib_crypto_hash_block_blake2s_224_digest_pt )(digest))); return mk_lib_crypto_hash_block_blake2s_224_digest_len ; break;
		case alg_id_e_hash_blake2s_256 : mk_lib_crypto_hash_stream_blake2s_256_finish (&alg->m_blake2s_256 ,          ((mk_lib_crypto_hash_block_blake2s_256_digest_pt )(digest))); return mk_lib_crypto_hash_block_blake2s_256_digest_len ; break;
		case alg_id_e_hash_blake3      : mk_lib_crypto_hash_stream_blake3_finish      (&alg->m_blake3      ,          ((mk_lib_crypto_hash_block_blake3_digest_pt      )(digest))); return mk_lib_crypto_hash_block_blake3_digest_len      ; break;
		case alg_id_e_hash_md2         : mk_lib_crypto_hash_stream_md2_finish         (&alg->m_md2         ,          ((mk_lib_crypto_hash_block_md2_digest_pt         )(digest))); return mk_lib_crypto_hash_block_md2_digest_len         ; break;
		case alg_id_e_hash_md4         : mk_lib_crypto_hash_stream_md4_finish         (&alg->m_md4         ,          ((mk_lib_crypto_hash_block_md4_digest_pt         )(digest))); return mk_lib_crypto_hash_block_md4_digest_len         ; break;
		case alg_id_e_hash_md5         : mk_lib_crypto_hash_stream_md5_finish         (&alg->m_md5         ,          ((mk_lib_crypto_hash_block_md5_digest_pt         )(digest))); return mk_lib_crypto_hash_block_md5_digest_len         ; break;
		case alg_id_e_hash_sha0        : mk_lib_crypto_hash_stream_sha0_finish        (&alg->m_sha0        ,          ((mk_lib_crypto_hash_block_sha0_digest_pt        )(digest))); return mk_lib_crypto_hash_block_sha0_digest_len        ; break;
		case alg_id_e_hash_sha1        : mk_lib_crypto_hash_stream_sha1_finish        (&alg->m_sha1        ,          ((mk_lib_crypto_hash_block_sha1_digest_pt        )(digest))); return mk_lib_crypto_hash_block_sha1_digest_len        ; break;
		case alg_id_e_hash_sha2_224    : mk_lib_crypto_hash_stream_sha2_224_finish    (&alg->m_sha2_224    ,          ((mk_lib_crypto_hash_block_sha2_224_digest_pt    )(digest))); return mk_lib_crypto_hash_block_sha2_224_digest_len    ; break;
		case alg_id_e_hash_sha2_256    : mk_lib_crypto_hash_stream_sha2_256_finish    (&alg->m_sha2_256    ,          ((mk_lib_crypto_hash_block_sha2_256_digest_pt    )(digest))); return mk_lib_crypto_hash_block_sha2_256_digest_len    ; break;
		case alg_id_e_hash_sha2_384    : mk_lib_crypto_hash_stream_sha2_384_finish    (&alg->m_sha2_384    ,          ((mk_lib_crypto_hash_block_sha2_384_digest_pt    )(digest))); return mk_lib_crypto_hash_block_sha2_384_digest_len    ; break;
		case alg_id_e_hash_sha2_512    : mk_lib_crypto_hash_stream_sha2_512_finish    (&alg->m_sha2_512    ,          ((mk_lib_crypto_hash_block_sha2_512_digest_pt    )(digest))); return mk_lib_crypto_hash_block_sha2_512_digest_len    ; break;
		case alg_id_e_hash_sha2_512_224: mk_lib_crypto_hash_stream_sha2_512_224_finish(&alg->m_sha2_512_224,          ((mk_lib_crypto_hash_block_sha2_512_224_digest_pt)(digest))); return mk_lib_crypto_hash_block_sha2_512_224_digest_len; break;
		case alg_id_e_hash_sha2_512_256: mk_lib_crypto_hash_stream_sha2_512_256_finish(&alg->m_sha2_512_256,          ((mk_lib_crypto_hash_block_sha2_512_256_digest_pt)(digest))); return mk_lib_crypto_hash_block_sha2_512_256_digest_len; break;
		case alg_id_e_hash_sha3_224    : mk_lib_crypto_hash_stream_sha3_224_finish    (&alg->m_sha3_224    ,          ((mk_lib_crypto_hash_block_sha3_224_digest_pt    )(digest))); return mk_lib_crypto_hash_block_sha3_224_digest_len    ; break;
		case alg_id_e_hash_sha3_256    : mk_lib_crypto_hash_stream_sha3_256_finish    (&alg->m_sha3_256    ,          ((mk_lib_crypto_hash_block_sha3_256_digest_pt    )(digest))); return mk_lib_crypto_hash_block_sha3_256_digest_len    ; break;
		case alg_id_e_hash_sha3_384    : mk_lib_crypto_hash_stream_sha3_384_finish    (&alg->m_sha3_384    ,          ((mk_lib_crypto_hash_block_sha3_384_digest_pt    )(digest))); return mk_lib_crypto_hash_block_sha3_384_digest_len    ; break;
		case alg_id_e_hash_sha3_512    : mk_lib_crypto_hash_stream_sha3_512_finish    (&alg->m_sha3_512    ,          ((mk_lib_crypto_hash_block_sha3_512_digest_pt    )(digest))); return mk_lib_crypto_hash_block_sha3_512_digest_len    ; break;
		case alg_id_e_hash_tiger2_128  : mk_lib_crypto_hash_stream_tiger2_128_finish  (&alg->m_tiger2_128  ,          ((mk_lib_crypto_hash_block_tiger2_128_digest_pt  )(digest))); return mk_lib_crypto_hash_block_tiger2_128_digest_len  ; break;
		case alg_id_e_hash_tiger2_160  : mk_lib_crypto_hash_stream_tiger2_160_finish  (&alg->m_tiger2_160  ,          ((mk_lib_crypto_hash_block_tiger2_160_digest_pt  )(digest))); return mk_lib_crypto_hash_block_tiger2_160_digest_len  ; break;
		case alg_id_e_hash_tiger2_192  : mk_lib_crypto_hash_stream_tiger2_192_finish  (&alg->m_tiger2_192  ,          ((mk_lib_crypto_hash_block_tiger2_192_digest_pt  )(digest))); return mk_lib_crypto_hash_block_tiger2_192_digest_len  ; break;
		case alg_id_e_hash_tiger_128   : mk_lib_crypto_hash_stream_tiger_128_finish   (&alg->m_tiger_128   ,          ((mk_lib_crypto_hash_block_tiger_128_digest_pt   )(digest))); return mk_lib_crypto_hash_block_tiger_128_digest_len   ; break;
		case alg_id_e_hash_tiger_160   : mk_lib_crypto_hash_stream_tiger_160_finish   (&alg->m_tiger_160   ,          ((mk_lib_crypto_hash_block_tiger_160_digest_pt   )(digest))); return mk_lib_crypto_hash_block_tiger_160_digest_len   ; break;
		case alg_id_e_hash_tiger_192   : mk_lib_crypto_hash_stream_tiger_192_finish   (&alg->m_tiger_192   ,          ((mk_lib_crypto_hash_block_tiger_192_digest_pt   )(digest))); return mk_lib_crypto_hash_block_tiger_192_digest_len   ; break;
		case alg_id_e_xof_shake_128    : mk_lib_crypto_xof_stream_shake_128_finish    (&alg->m_shake_128   , xof_len, ((mk_lib_crypto_xof_block_shake_128_digest_pt    )(digest))); return xof_len                                         ; break;
		case alg_id_e_xof_shake_256    : mk_lib_crypto_xof_stream_shake_256_finish    (&alg->m_shake_256   , xof_len, ((mk_lib_crypto_xof_block_shake_256_digest_pt    )(digest))); return xof_len                                         ; break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t compare(mk_lang_types_pchar_prct const a, mk_lang_types_pchar_prct const b, int const len) mk_lang_noexcept
{
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);
	mk_lang_assert(!(a >= b && a < b + len));
	mk_lang_assert(!(b >= a && b < a + len));
	mk_lang_assert(len >= 1);
	mk_lang_assert(len <= 0xff);

	for(i = 0; i != len; ++i)
	{
		if(a[i] != b[i])
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
}


alg_t g_alg;
alg_id_t g_id;
mk_lang_types_pchar_t g_alg_name[0xff];
aligned1m_t g_msg;
aligned16k_t g_digest;


#define check(x) if(!(x)){ mk_lang_unlikely return 0; }


mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_usize_t mkch_get_alg_name_addr(void) mk_lang_noexcept
{
	return ((mk_lang_types_usize_t)(((mk_lang_types_uintptr_t)(&g_alg_name))));
}

mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_usize_t mkch_get_alg_name_size(void) mk_lang_noexcept
{
	return ((mk_lang_types_usize_t)(sizeof(g_alg_name) / sizeof(g_alg_name[0])));
}

mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_usize_t mkch_get_msg_addr(void) mk_lang_noexcept
{
	return ((mk_lang_types_usize_t)(((mk_lang_types_uintptr_t)(&g_msg))));
}

mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_usize_t mkch_get_msg_size(void) mk_lang_noexcept
{
	return ((mk_lang_types_usize_t)(sizeof(g_msg.m_uint8s) / sizeof(g_msg.m_uint8s[0])));
}

mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_usize_t mkch_get_digest_addr(void) mk_lang_noexcept
{
	return ((mk_lang_types_usize_t)(((mk_lang_types_uintptr_t)(&g_digest))));
}

mk_lang_extern_c mk_lang_emscripten_keepalive mk_lang_types_usize_t mkch_get_digest_size(void) mk_lang_noexcept
{
	return ((mk_lang_types_usize_t)(sizeof(g_digest.m_uint8s) / sizeof(g_digest.m_uint8s[0])));
}

mk_lang_extern_c mk_lang_emscripten_keepalive int mkch_get_alg_count(void) mk_lang_noexcept
{
	return ((int)(sizeof(s_alg_name_lens) / sizeof(s_alg_name_lens[0])));
}

mk_lang_extern_c mk_lang_emscripten_keepalive int mkch_get_alg_name(int const alg_idx) mk_lang_noexcept
{
	mk_lang_types_pchar_pct ptr;
	int n;
	int i;

	ptr = s_alg_names;
	n = ((int)(sizeof(s_alg_name_lens) / sizeof(s_alg_name_lens[0])));
	for(i = 0; i != n; ++i)
	{
		if(s_alg_order[alg_idx] == i)
		{
			n = s_alg_name_lens[i];
			for(i = 0; i != n; ++i){ g_alg_name[i] = ptr[i]; }
			return n;
		}
		else
		{
			ptr += s_alg_name_lens[i];
		}
	}
	return 0;
}

mk_lang_extern_c mk_lang_emscripten_keepalive int mkch_get_alg_pretty_name(int const alg_idx) mk_lang_noexcept
{
	mk_lang_types_pchar_pct ptr;
	int n;
	int i;

	ptr = s_alg_pretty_names;
	n = ((int)(alg_id_e_dummy_end));
	for(i = 0; i != n; ++i)
	{
		if(s_alg_order[alg_idx] == i)
		{
			n = s_alg_pretty_name_lens[i];
			for(i = 0; i != n; ++i){ g_alg_name[i] = ptr[i]; }
			return n;
		}
		else
		{
			ptr += s_alg_pretty_name_lens[i];
		}
	}
	return 0;
}

mk_lang_extern_c mk_lang_emscripten_keepalive int mkch_init(int const alg_name_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pct ptr;
	int n;
	int i;
	alg_id_t id;

	check(alg_name_len >= 1);
	check(alg_name_len <= 0xff);

	ptr = s_alg_names;
	n = ((int)(alg_id_e_dummy_end));
	for(i = 0; i != n; ++i)
	{
		if(alg_name_len == s_alg_name_lens[i])
		{
			if(compare(g_alg_name, ptr, alg_name_len))
			{
				break;
			}
			else
			{
				ptr += s_alg_name_lens[i];
			}
		}
		else
		{
			ptr += s_alg_name_lens[i];
		}
	}
	check(i != n);
	check(i >= 0);
	check(i < alg_id_e_dummy_end);
	id = ((alg_id_t)(i));
	g_id = id;
	init(&g_alg, g_id);
	return 1;
}

mk_lang_extern_c mk_lang_emscripten_keepalive int mkch_append(int const buffer_len) mk_lang_noexcept
{
	check(buffer_len >= 0);
	check(buffer_len <= ((int)(sizeof(g_msg.m_uint8s) / sizeof(g_msg.m_uint8s[0]))));

	append(&g_alg, g_id, ((mk_lang_types_uchar_pt)(&g_msg.m_uint8s[0])), buffer_len);
	return 1;
}

mk_lang_extern_c mk_lang_emscripten_keepalive int mkch_finish(int const xof_len) mk_lang_noexcept
{
	int ret;

	check(xof_len >= 1);
	check(xof_len <= ((int)(sizeof(g_digest.m_uint8s) / sizeof(g_digest.m_uint8s[0]))));

	ret = finish(&g_alg, g_id, xof_len, &g_digest);
	return ret;
}

mk_lang_extern_c mk_lang_emscripten_keepalive int mkch(int const alg_name_len, int const buffer_len, int const xof_len) mk_lang_noexcept
{
	int ret;

	mk_lang_static_assert(((int)(sizeof(s_alg_name_lens) / sizeof(s_alg_name_lens[0]))) == ((int)(alg_id_e_dummy_end)));
	mk_lang_static_assert(((int)(sizeof(s_alg_pretty_name_lens) / sizeof(s_alg_pretty_name_lens[0]))) == ((int)(alg_id_e_dummy_end)));
	mk_lang_static_assert(((int)(sizeof(s_alg_order) / sizeof(s_alg_order[0]))) == ((int)(alg_id_e_dummy_end)));

	ret = mkch_init(alg_name_len); check(ret != 0);
	ret = mkch_append(buffer_len); check(ret != 0);
	ret = mkch_finish(xof_len); check(ret != 0);
	return ret;
}


#undef check
