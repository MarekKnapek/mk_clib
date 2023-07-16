#include "mk_lib_crypto_app.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpp.h"
#include "mk_lang_emscripten.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_null.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_stringify.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_crypto_alg_aes_128.h"
#include "mk_lib_crypto_alg_aes_192.h"
#include "mk_lib_crypto_alg_aes_256.h"
#include "mk_lib_crypto_kdf_pbkdf1_md2.h"
#include "mk_lib_crypto_kdf_pbkdf1_md5.h"
#include "mk_lib_crypto_kdf_pbkdf1_sha1.h"
#include "mk_lib_crypto_kdf_pbkdf2_blake2b_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_blake2b_384.h"
#include "mk_lib_crypto_kdf_pbkdf2_blake2b_512.h"
#include "mk_lib_crypto_kdf_pbkdf2_blake2s_128.h"
#include "mk_lib_crypto_kdf_pbkdf2_blake2s_160.h"
#include "mk_lib_crypto_kdf_pbkdf2_blake2s_224.h"
#include "mk_lib_crypto_kdf_pbkdf2_blake2s_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_blake3.h"
#include "mk_lib_crypto_kdf_pbkdf2_md2.h"
#include "mk_lib_crypto_kdf_pbkdf2_md4.h"
#include "mk_lib_crypto_kdf_pbkdf2_md5.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha0.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha1.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_224.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_384.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_512.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_512_224.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha2_512_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha3_224.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha3_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha3_384.h"
#include "mk_lib_crypto_kdf_pbkdf2_sha3_512.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger2_128.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger2_160.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger2_192.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger_128.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger_160.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger_192.h"
#include "mk_lib_crypto_mode_cbc_aes_128.h"
#include "mk_lib_crypto_mode_cbc_aes_192.h"
#include "mk_lib_crypto_mode_cbc_aes_256.h"
#include "mk_lib_crypto_mode_cfb_128_aes_128.h"
#include "mk_lib_crypto_mode_cfb_128_aes_192.h"
#include "mk_lib_crypto_mode_cfb_128_aes_256.h"
#include "mk_lib_crypto_mode_cfb_8_aes_128.h"
#include "mk_lib_crypto_mode_cfb_8_aes_192.h"
#include "mk_lib_crypto_mode_cfb_8_aes_256.h"
#include "mk_lib_crypto_mode_ctr_be_aes_128.h"
#include "mk_lib_crypto_mode_ctr_be_aes_192.h"
#include "mk_lib_crypto_mode_ctr_be_aes_256.h"
#include "mk_lib_crypto_mode_ofb_aes_128.h"
#include "mk_lib_crypto_mode_ofb_aes_192.h"
#include "mk_lib_crypto_mode_ofb_aes_256.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_app_name_code_alg_aes_128 "aes_128"
#define mk_lib_crypto_app_name_code_alg_aes_192 "aes_192"
#define mk_lib_crypto_app_name_code_alg_aes_256 "aes_256"

#define mk_lib_crypto_app_name_code_padding_pkcs7 "pkcs7"

#define mk_lib_crypto_app_name_code_mode_cbc     "cbc"
#define mk_lib_crypto_app_name_code_mode_cfb_128 "cfb_128"
#define mk_lib_crypto_app_name_code_mode_cfb_8   "cfb_8"
#define mk_lib_crypto_app_name_code_mode_ctr     "ctr"
#define mk_lib_crypto_app_name_code_mode_ecb     "ecb"
#define mk_lib_crypto_app_name_code_mode_ofb     "ofb"

#define mk_lib_crypto_app_name_code_kdf_pbkdf1_md2          "pbkdf1_md2"
#define mk_lib_crypto_app_name_code_kdf_pbkdf1_md5          "pbkdf1_md5"
#define mk_lib_crypto_app_name_code_kdf_pbkdf1_sha1         "pbkdf1_sha1"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_256  "pbkdf2_blake2b_256"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_384  "pbkdf2_blake2b_384"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_512  "pbkdf2_blake2b_512"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_128  "pbkdf2_blake2s_128"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_160  "pbkdf2_blake2s_160"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_224  "pbkdf2_blake2s_224"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_256  "pbkdf2_blake2s_256"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_blake3       "pbkdf2_blake3"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_md2          "pbkdf2_md2"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_md4          "pbkdf2_md4"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_md5          "pbkdf2_md5"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha0         "pbkdf2_sha0"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha1         "pbkdf2_sha1"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_224     "pbkdf2_sha2_224"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_256     "pbkdf2_sha2_256"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_384     "pbkdf2_sha2_384"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512     "pbkdf2_sha2_512"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512_224 "pbkdf2_sha2_512_224"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512_256 "pbkdf2_sha2_512_256"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_224     "pbkdf2_sha3_224"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_256     "pbkdf2_sha3_256"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_384     "pbkdf2_sha3_384"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_512     "pbkdf2_sha3_512"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_128   "pbkdf2_tiger2_128"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_160   "pbkdf2_tiger2_160"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_192   "pbkdf2_tiger2_192"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_128    "pbkdf2_tiger_128"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_160    "pbkdf2_tiger_160"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_192    "pbkdf2_tiger_192"


#define mk_lib_crypto_app_name_pretty_alg_aes_128 "AES-128"
#define mk_lib_crypto_app_name_pretty_alg_aes_192 "AES-192"
#define mk_lib_crypto_app_name_pretty_alg_aes_256 "AES-256"

#define mk_lib_crypto_app_name_pretty_padding_pkcs7 "PKCS #7"

#define mk_lib_crypto_app_name_pretty_mode_cbc     "CBC"
#define mk_lib_crypto_app_name_pretty_mode_cfb_128 "CFB-128"
#define mk_lib_crypto_app_name_pretty_mode_cfb_8   "CFB-8"
#define mk_lib_crypto_app_name_pretty_mode_ctr     "CTR"
#define mk_lib_crypto_app_name_pretty_mode_ecb     "ECB"
#define mk_lib_crypto_app_name_pretty_mode_ofb     "OFB"

#define mk_lib_crypto_app_name_pretty_kdf_pbkdf1_md2          "PBKDF1-MD2"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf1_md5          "PBKDF1-MD5"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf1_sha1         "PBKDF1-SHA1"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_256  "PBKDF2-BLAKE2b-256"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_384  "PBKDF2-BLAKE2b-384"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_512  "PBKDF2-BLAKE2b-512"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_128  "PBKDF2-BLAKE2s-128"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_160  "PBKDF2-BLAKE2s-160"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_224  "PBKDF2-BLAKE2s-224"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_256  "PBKDF2-BLAKE2s-256"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake3       "PBKDF2-BLAKE3"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md2          "PBKDF2-MD2"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md4          "PBKDF2-MD4"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md5          "PBKDF2-MD5"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha0         "PBKDF2-SHA-0"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha1         "PBKDF2-SHA-1"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_224     "PBKDF2-SHA-224"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_256     "PBKDF2-SHA-256"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_384     "PBKDF2-SHA-384"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512     "PBKDF2-SHA-512"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512_224 "PBKDF2-SHA-512/224"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512_256 "PBKDF2-SHA-512/256"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_224     "PBKDF2-SHA3-224"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_256     "PBKDF2-SHA3-256"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_384     "PBKDF2-SHA3-384"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_512     "PBKDF2-SHA3-512"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_128   "PBKDF2-Tiger2/128"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_160   "PBKDF2-Tiger2/160"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_192   "PBKDF2-Tiger2/192"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_128    "PBKDF2-Tiger/128"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_160    "PBKDF2-Tiger/160"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_192    "PBKDF2-Tiger/192"


#define mk_lib_crypto_app_namelen_code_alg_aes_128 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_alg_aes_128 ) / sizeof(mk_lib_crypto_app_name_code_alg_aes_128 [0]) - 1))
#define mk_lib_crypto_app_namelen_code_alg_aes_192 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_alg_aes_192 ) / sizeof(mk_lib_crypto_app_name_code_alg_aes_192 [0]) - 1))
#define mk_lib_crypto_app_namelen_code_alg_aes_256 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_alg_aes_256 ) / sizeof(mk_lib_crypto_app_name_code_alg_aes_256 [0]) - 1))

#define mk_lib_crypto_app_namelen_code_padding_pkcs7 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_padding_pkcs7 ) / sizeof(mk_lib_crypto_app_name_code_padding_pkcs7 [0]) - 1))

#define mk_lib_crypto_app_namelen_code_mode_cbc     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_mode_cbc     ) / sizeof(mk_lib_crypto_app_name_code_mode_cbc     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_mode_cfb_128 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_mode_cfb_128 ) / sizeof(mk_lib_crypto_app_name_code_mode_cfb_128 [0]) - 1))
#define mk_lib_crypto_app_namelen_code_mode_cfb_8   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_mode_cfb_8   ) / sizeof(mk_lib_crypto_app_name_code_mode_cfb_8   [0]) - 1))
#define mk_lib_crypto_app_namelen_code_mode_ctr     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_mode_ctr     ) / sizeof(mk_lib_crypto_app_name_code_mode_ctr     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_mode_ecb     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_mode_ecb     ) / sizeof(mk_lib_crypto_app_name_code_mode_ecb     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_mode_ofb     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_mode_ofb     ) / sizeof(mk_lib_crypto_app_name_code_mode_ofb     [0]) - 1))

#define mk_lib_crypto_app_namelen_code_kdf_pbkdf1_md2          ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf1_md2          ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf1_md2          [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf1_md5          ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf1_md5          ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf1_md5          [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf1_sha1         ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf1_sha1         ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf1_sha1         [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2b_256  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_256  ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_256  [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2b_384  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_384  ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_384  [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2b_512  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_512  ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_512  [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2s_128  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_128  ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_128  [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2s_160  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_160  ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_160  [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2s_224  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_224  ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_224  [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2s_256  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_256  ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_256  [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake3       ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake3       ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_blake3       [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_md2          ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_md2          ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_md2          [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_md4          ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_md4          ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_md4          [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_md5          ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_md5          ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_md5          [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha0         ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha0         ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha0         [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha1         ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha1         ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha1         [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_224     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_224     ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_224     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_256     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_256     ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_256     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_384     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_384     ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_384     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_512     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512     ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_512_224 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512_224 ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512_224 [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_512_256 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512_256 ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512_256 [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha3_224     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_224     ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_224     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha3_256     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_256     ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_256     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha3_384     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_384     ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_384     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha3_512     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_512     ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_512     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_128   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_128   ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_128   [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_160   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_160   ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_160   [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_192   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_192   ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_192   [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_128    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_128    ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_128    [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_160    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_160    ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_160    [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_192    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_192    ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_192    [0]) - 1))


#define mk_lib_crypto_app_namelen_pretty_alg_aes_128 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_alg_aes_128 ) / sizeof(mk_lib_crypto_app_name_pretty_alg_aes_128 [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_alg_aes_192 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_alg_aes_192 ) / sizeof(mk_lib_crypto_app_name_pretty_alg_aes_192 [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_alg_aes_256 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_alg_aes_256 ) / sizeof(mk_lib_crypto_app_name_pretty_alg_aes_256 [0]) - 1))

#define mk_lib_crypto_app_namelen_pretty_padding_pkcs7 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_padding_pkcs7 ) / sizeof(mk_lib_crypto_app_name_pretty_padding_pkcs7 [0]) - 1))

#define mk_lib_crypto_app_namelen_pretty_mode_cbc     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_mode_cbc     ) / sizeof(mk_lib_crypto_app_name_pretty_mode_cbc     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_mode_cfb_128 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_mode_cfb_128 ) / sizeof(mk_lib_crypto_app_name_pretty_mode_cfb_128 [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_mode_cfb_8   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_mode_cfb_8   ) / sizeof(mk_lib_crypto_app_name_pretty_mode_cfb_8   [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_mode_ctr     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_mode_ctr     ) / sizeof(mk_lib_crypto_app_name_pretty_mode_ctr     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_mode_ecb     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_mode_ecb     ) / sizeof(mk_lib_crypto_app_name_pretty_mode_ecb     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_mode_ofb     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_mode_ofb     ) / sizeof(mk_lib_crypto_app_name_pretty_mode_ofb     [0]) - 1))

#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf1_md2          ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf1_md2          ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf1_md2          [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf1_md5          ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf1_md5          ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf1_md5          [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf1_sha1         ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf1_sha1         ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf1_sha1         [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2b_256  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_256  ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_256  [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2b_384  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_384  ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_384  [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2b_512  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_512  ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_512  [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2s_128  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_128  ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_128  [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2s_160  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_160  ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_160  [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2s_224  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_224  ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_224  [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2s_256  ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_256  ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_256  [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake3       ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake3       ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake3       [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_md2          ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md2          ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md2          [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_md4          ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md4          ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md4          [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_md5          ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md5          ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md5          [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha0         ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha0         ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha0         [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha1         ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha1         ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha1         [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_224     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_224     ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_224     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_256     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_256     ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_256     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_384     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_384     ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_384     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_512     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512     ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_512_224 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512_224 ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512_224 [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_512_256 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512_256 ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512_256 [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha3_224     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_224     ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_224     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha3_256     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_256     ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_256     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha3_384     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_384     ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_384     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha3_512     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_512     ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_512     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_128   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_128   ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_128   [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_160   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_160   ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_160   [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_192   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_192   ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_192   [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_128    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_128    ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_128    [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_160    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_160    ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_160    [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_192    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_192    ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_192    [0]) - 1))


#define mk_lib_crypto_app_name_code_algs \
	mk_lib_crypto_app_name_code_alg_aes_128 \
	mk_lib_crypto_app_name_code_alg_aes_192 \
	mk_lib_crypto_app_name_code_alg_aes_256 \
	""

#define mk_lib_crypto_app_name_code_paddings \
	mk_lib_crypto_app_name_code_padding_pkcs7 \
	""

#define mk_lib_crypto_app_name_code_modes \
	mk_lib_crypto_app_name_code_mode_cbc     \
	mk_lib_crypto_app_name_code_mode_cfb_128 \
	mk_lib_crypto_app_name_code_mode_cfb_8   \
	mk_lib_crypto_app_name_code_mode_ctr     \
	mk_lib_crypto_app_name_code_mode_ecb     \
	mk_lib_crypto_app_name_code_mode_ofb     \
	""

#define mk_lib_crypto_app_name_code_kdfs \
	mk_lib_crypto_app_name_code_kdf_pbkdf1_md2          \
	mk_lib_crypto_app_name_code_kdf_pbkdf1_md5          \
	mk_lib_crypto_app_name_code_kdf_pbkdf1_sha1         \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_256  \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_384  \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2b_512  \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_128  \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_160  \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_224  \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_blake2s_256  \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_blake3       \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_md2          \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_md4          \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_md5          \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha0         \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha1         \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_224     \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_256     \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_384     \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512     \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512_224 \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha2_512_256 \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_224     \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_256     \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_384     \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_sha3_512     \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_128   \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_160   \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_192   \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_128    \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_160    \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_192    \
	""

#define mk_lib_crypto_app_name_pretty_algs \
	mk_lib_crypto_app_name_pretty_alg_aes_128 \
	mk_lib_crypto_app_name_pretty_alg_aes_192 \
	mk_lib_crypto_app_name_pretty_alg_aes_256 \
	""

#define mk_lib_crypto_app_name_pretty_paddings \
	mk_lib_crypto_app_name_pretty_padding_pkcs7 \
	""

#define mk_lib_crypto_app_name_pretty_modes \
	mk_lib_crypto_app_name_pretty_mode_cbc     \
	mk_lib_crypto_app_name_pretty_mode_cfb_128 \
	mk_lib_crypto_app_name_pretty_mode_cfb_8   \
	mk_lib_crypto_app_name_pretty_mode_ctr     \
	mk_lib_crypto_app_name_pretty_mode_ecb     \
	mk_lib_crypto_app_name_pretty_mode_ofb     \
	""

#define mk_lib_crypto_app_name_pretty_kdfs \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf1_md2          \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf1_md5          \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf1_sha1         \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_256  \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_384  \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2b_512  \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_128  \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_160  \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_224  \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake2s_256  \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_blake3       \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md2          \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md4          \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_md5          \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha0         \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha1         \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_224     \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_256     \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_384     \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512     \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512_224 \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha2_512_256 \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_224     \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_256     \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_384     \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_sha3_512     \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_128   \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_160   \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_192   \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_128    \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_160    \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_192    \
	""

#define mk_lib_crypto_app_namelen_code_algs \
	mk_lib_crypto_app_namelen_code_alg_aes_128, \
	mk_lib_crypto_app_namelen_code_alg_aes_192, \
	mk_lib_crypto_app_namelen_code_alg_aes_256, \

#define mk_lib_crypto_app_namelen_code_paddings \
	mk_lib_crypto_app_namelen_code_padding_pkcs7, \

#define mk_lib_crypto_app_namelen_code_modes \
	mk_lib_crypto_app_namelen_code_mode_cbc,     \
	mk_lib_crypto_app_namelen_code_mode_cfb_128, \
	mk_lib_crypto_app_namelen_code_mode_cfb_8,   \
	mk_lib_crypto_app_namelen_code_mode_ctr,     \
	mk_lib_crypto_app_namelen_code_mode_ecb,     \
	mk_lib_crypto_app_namelen_code_mode_ofb,     \

#define mk_lib_crypto_app_namelen_code_kdfs \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf1_md2,          \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf1_md5,          \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf1_sha1,         \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2b_256,  \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2b_384,  \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2b_512,  \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2s_128,  \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2s_160,  \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2s_224,  \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake2s_256,  \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_blake3,       \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_md2,          \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_md4,          \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_md5,          \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha0,         \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha1,         \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_224,     \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_256,     \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_384,     \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_512,     \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_512_224, \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha2_512_256, \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha3_224,     \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha3_256,     \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha3_384,     \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_sha3_512,     \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_128,   \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_160,   \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_192,   \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_128,    \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_160,    \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_192,    \

#define mk_lib_crypto_app_namelen_pretty_algs \
	mk_lib_crypto_app_namelen_pretty_alg_aes_128, \
	mk_lib_crypto_app_namelen_pretty_alg_aes_192, \
	mk_lib_crypto_app_namelen_pretty_alg_aes_256, \

#define mk_lib_crypto_app_namelen_pretty_paddings \
	mk_lib_crypto_app_namelen_pretty_padding_pkcs7, \

#define mk_lib_crypto_app_namelen_pretty_modes \
	mk_lib_crypto_app_namelen_pretty_mode_cbc,     \
	mk_lib_crypto_app_namelen_pretty_mode_cfb_128, \
	mk_lib_crypto_app_namelen_pretty_mode_cfb_8,   \
	mk_lib_crypto_app_namelen_pretty_mode_ctr,     \
	mk_lib_crypto_app_namelen_pretty_mode_ecb,     \
	mk_lib_crypto_app_namelen_pretty_mode_ofb,     \

#define mk_lib_crypto_app_namelen_pretty_kdfs \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf1_md2,          \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf1_md5,          \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf1_sha1,         \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2b_256,  \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2b_384,  \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2b_512,  \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2s_128,  \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2s_160,  \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2s_224,  \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake2s_256,  \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_blake3,       \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_md2,          \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_md4,          \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_md5,          \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha0,         \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha1,         \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_224,     \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_256,     \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_384,     \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_512,     \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_512_224, \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha2_512_256, \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha3_224,     \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha3_256,     \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha3_384,     \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_sha3_512,     \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_128,   \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_160,   \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_192,   \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_128,    \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_160,    \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_192,    \


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_lib_crypto_app_name_code_algs     [] = mk_lib_crypto_app_name_code_algs     ;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_lib_crypto_app_name_code_paddings [] = mk_lib_crypto_app_name_code_paddings ;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_lib_crypto_app_name_code_modes    [] = mk_lib_crypto_app_name_code_modes    ;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_lib_crypto_app_name_code_kdfs     [] = mk_lib_crypto_app_name_code_kdfs     ;

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_lib_crypto_app_name_pretty_algs     [] = mk_lib_crypto_app_name_pretty_algs     ;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_lib_crypto_app_name_pretty_paddings [] = mk_lib_crypto_app_name_pretty_paddings ;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_lib_crypto_app_name_pretty_modes    [] = mk_lib_crypto_app_name_pretty_modes    ;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const s_mk_lib_crypto_app_name_pretty_kdfs     [] = mk_lib_crypto_app_name_pretty_kdfs     ;

#define s_mk_lib_crypto_app_name_code_algs_len     ((int)(sizeof(mk_lib_crypto_app_name_code_algs     ) / sizeof(mk_lib_crypto_app_name_code_algs     [0]) - 1))
#define s_mk_lib_crypto_app_name_code_paddings_len ((int)(sizeof(mk_lib_crypto_app_name_code_paddings ) / sizeof(mk_lib_crypto_app_name_code_paddings [0]) - 1))
#define s_mk_lib_crypto_app_name_code_modes_len    ((int)(sizeof(mk_lib_crypto_app_name_code_modes    ) / sizeof(mk_lib_crypto_app_name_code_modes    [0]) - 1))
#define s_mk_lib_crypto_app_name_code_kdfs_len     ((int)(sizeof(mk_lib_crypto_app_name_code_kdfs     ) / sizeof(mk_lib_crypto_app_name_code_kdfs     [0]) - 1))

#define s_mk_lib_crypto_app_name_pretty_algs_len     ((int)(sizeof(mk_lib_crypto_app_name_pretty_algs     ) / sizeof(mk_lib_crypto_app_name_pretty_algs     [0]) - 1))
#define s_mk_lib_crypto_app_name_pretty_paddings_len ((int)(sizeof(mk_lib_crypto_app_name_pretty_paddings ) / sizeof(mk_lib_crypto_app_name_pretty_paddings [0]) - 1))
#define s_mk_lib_crypto_app_name_pretty_modes_len    ((int)(sizeof(mk_lib_crypto_app_name_pretty_modes    ) / sizeof(mk_lib_crypto_app_name_pretty_modes    [0]) - 1))
#define s_mk_lib_crypto_app_name_pretty_kdfs_len     ((int)(sizeof(mk_lib_crypto_app_name_pretty_kdfs     ) / sizeof(mk_lib_crypto_app_name_pretty_kdfs     [0]) - 1))

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_namelen_code_algs     [] = { mk_lib_crypto_app_namelen_code_algs     };
mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_namelen_code_paddings [] = { mk_lib_crypto_app_namelen_code_paddings };
mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_namelen_code_modes    [] = { mk_lib_crypto_app_namelen_code_modes    };
mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_namelen_code_kdfs     [] = { mk_lib_crypto_app_namelen_code_kdfs     };

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_namelen_pretty_algs     [] = { mk_lib_crypto_app_namelen_pretty_algs     };
mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_namelen_pretty_paddings [] = { mk_lib_crypto_app_namelen_pretty_paddings };
mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_namelen_pretty_modes    [] = { mk_lib_crypto_app_namelen_pretty_modes    };
mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_namelen_pretty_kdfs     [] = { mk_lib_crypto_app_namelen_pretty_kdfs     };

#define s_mk_lib_crypto_app_namelen_code_algs_len     ((int)(sizeof(s_mk_lib_crypto_app_namelen_code_algs     ) / sizeof(s_mk_lib_crypto_app_namelen_code_algs     [0])))
#define s_mk_lib_crypto_app_namelen_code_paddings_len ((int)(sizeof(s_mk_lib_crypto_app_namelen_code_paddings ) / sizeof(s_mk_lib_crypto_app_namelen_code_paddings [0])))
#define s_mk_lib_crypto_app_namelen_code_modes_len    ((int)(sizeof(s_mk_lib_crypto_app_namelen_code_modes    ) / sizeof(s_mk_lib_crypto_app_namelen_code_modes    [0])))
#define s_mk_lib_crypto_app_namelen_code_kdfs_len     ((int)(sizeof(s_mk_lib_crypto_app_namelen_code_kdfs     ) / sizeof(s_mk_lib_crypto_app_namelen_code_kdfs     [0])))

#define s_mk_lib_crypto_app_namelen_pretty_algs_len     ((int)(sizeof(s_mk_lib_crypto_app_namelen_pretty_algs     ) / sizeof(s_mk_lib_crypto_app_namelen_pretty_algs     [0])))
#define s_mk_lib_crypto_app_namelen_pretty_paddings_len ((int)(sizeof(s_mk_lib_crypto_app_namelen_pretty_paddings ) / sizeof(s_mk_lib_crypto_app_namelen_pretty_paddings [0])))
#define s_mk_lib_crypto_app_namelen_pretty_modes_len    ((int)(sizeof(s_mk_lib_crypto_app_namelen_pretty_modes    ) / sizeof(s_mk_lib_crypto_app_namelen_pretty_modes    [0])))
#define s_mk_lib_crypto_app_namelen_pretty_kdfs_len     ((int)(sizeof(s_mk_lib_crypto_app_namelen_pretty_kdfs     ) / sizeof(s_mk_lib_crypto_app_namelen_pretty_kdfs     [0])))


enum mk_lib_crypto_app_id_alg_e
{
	mk_lib_crypto_app_id_alg_e_aes_128,
	mk_lib_crypto_app_id_alg_e_aes_192,
	mk_lib_crypto_app_id_alg_e_aes_256,
	mk_lib_crypto_app_id_alg_e_dummy_end
};
typedef enum mk_lib_crypto_app_id_alg_e mk_lib_crypto_app_id_alg_t;
typedef mk_lib_crypto_app_id_alg_t const mk_lib_crypto_app_id_alg_ct;
typedef mk_lib_crypto_app_id_alg_t* mk_lib_crypto_app_id_alg_pt;
typedef mk_lib_crypto_app_id_alg_t const* mk_lib_crypto_app_id_alg_pct;

enum mk_lib_crypto_app_id_padding_e
{
	mk_lib_crypto_app_id_padding_e_pkcs7,
	mk_lib_crypto_app_id_padding_e_dummy_end
};
typedef enum mk_lib_crypto_app_id_padding_e mk_lib_crypto_app_id_padding_t;
typedef mk_lib_crypto_app_id_padding_t const mk_lib_crypto_app_id_padding_ct;
typedef mk_lib_crypto_app_id_padding_t* mk_lib_crypto_app_id_padding_pt;
typedef mk_lib_crypto_app_id_padding_t const* mk_lib_crypto_app_id_padding_pct;

enum mk_lib_crypto_app_id_mode_e
{
	mk_lib_crypto_app_id_mode_e_cbc,
	mk_lib_crypto_app_id_mode_e_cfb_128,
	mk_lib_crypto_app_id_mode_e_cfb_8,
	mk_lib_crypto_app_id_mode_e_ctr_be,
	mk_lib_crypto_app_id_mode_e_ecb,
	mk_lib_crypto_app_id_mode_e_ofb,
	mk_lib_crypto_app_id_mode_e_dummy_end
};
typedef enum mk_lib_crypto_app_id_mode_e mk_lib_crypto_app_id_mode_t;
typedef mk_lib_crypto_app_id_mode_t const mk_lib_crypto_app_id_mode_ct;
typedef mk_lib_crypto_app_id_mode_t* mk_lib_crypto_app_id_mode_pt;
typedef mk_lib_crypto_app_id_mode_t const* mk_lib_crypto_app_id_mode_pct;

enum mk_lib_crypto_app_id_kdf_e
{
	mk_lib_crypto_app_id_kdf_e_pbkdf1_md2,
	mk_lib_crypto_app_id_kdf_e_pbkdf1_md5,
	mk_lib_crypto_app_id_kdf_e_pbkdf1_sha1,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_256,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_384,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_512,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_128,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_160,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_224,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_256,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_blake3,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_md2,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_md4,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_md5,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha0,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha1,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_224,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_256,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_384,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512_224,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512_256,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_224,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_256,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_384,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_512,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_128,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_160,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_192,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_128,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_160,
	mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_192,
	mk_lib_crypto_app_id_kdf_e_dummy_end
};
typedef enum mk_lib_crypto_app_id_kdf_e mk_lib_crypto_app_id_kdf_t;
typedef mk_lib_crypto_app_id_kdf_t const mk_lib_crypto_app_id_kdf_ct;
typedef mk_lib_crypto_app_id_kdf_t* mk_lib_crypto_app_id_kdf_pt;
typedef mk_lib_crypto_app_id_kdf_t const* mk_lib_crypto_app_id_kdf_pct;


mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_order_algs[] =
{
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_alg_e_aes_128)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_alg_e_aes_192)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_alg_e_aes_256)),
};

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_order_paddings[] =
{
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_padding_e_pkcs7)),
};

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_order_modes[] =
{
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_mode_e_ecb)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_mode_e_cbc)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_mode_e_cfb_8)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_mode_e_cfb_128)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_mode_e_ctr_be)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_mode_e_ofb)),
};

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_order_kdfs[] =
{
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf1_md2)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf1_md5)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf1_sha1)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_md2)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_md4)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_md5)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha0)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha1)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_224)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_384)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512_224)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_224)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_384)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_512)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_128)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_160)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_192)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_128)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_160)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_192)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_384)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_512)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_128)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_160)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_224)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_id_kdf_e_pbkdf2_blake3)),
};


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline int mk_lib_crypto_app_get_key_size_max_f(void) mk_lang_noexcept
{
	int s mk_lang_constexpr_init;

	s = 0x00;
	s = mk_lang_max(s, mk_lib_crypto_alg_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_alg_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_alg_aes_256_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_256_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_256_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_256_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_256_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_256_key_len_v);
	return s;
}
#define mk_lib_crypto_app_get_key_size_max_m 32

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline int mk_lib_crypto_app_get_msg_size_max_f(void) mk_lang_noexcept
{
	int s mk_lang_constexpr_init;

	s = 0x00;
	s = mk_lang_max(s, mk_lib_crypto_alg_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_alg_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_alg_aes_256_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_256_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_256_msg_len_v);
	return s;
}
#define mk_lib_crypto_app_get_msg_size_max_m 16

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline int mk_lib_crypto_app_get_iv_size_max_f(void) mk_lang_noexcept
{
	int s mk_lang_constexpr_init;

	s = 0x00;
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_128_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_192_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_256_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_128_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_192_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_256_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_128_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_192_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_256_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_128_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_192_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_256_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_128_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_192_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_256_iv_len_v);
	return s;
}
#define mk_lib_crypto_app_get_iv_size_max_m 16


union mk_lib_crypto_app_aligned_mode_u
{
	mk_lib_crypto_mode_cbc_aes_128_t     m_cbc_aes_128     ;
	mk_lib_crypto_mode_cbc_aes_192_t     m_cbc_aes_192     ;
	mk_lib_crypto_mode_cbc_aes_256_t     m_cbc_aes_256     ;
	mk_lib_crypto_mode_cfb_128_aes_128_t m_cfb_128_aes_128 ;
	mk_lib_crypto_mode_cfb_128_aes_192_t m_cfb_128_aes_192 ;
	mk_lib_crypto_mode_cfb_128_aes_256_t m_cfb_128_aes_256 ;
	mk_lib_crypto_mode_cfb_8_aes_128_t   m_cfb_8_aes_128   ;
	mk_lib_crypto_mode_cfb_8_aes_192_t   m_cfb_8_aes_192   ;
	mk_lib_crypto_mode_cfb_8_aes_256_t   m_cfb_8_aes_256   ;
	mk_lib_crypto_mode_ctr_be_aes_128_t  m_ctr_be_aes_128  ;
	mk_lib_crypto_mode_ctr_be_aes_192_t  m_ctr_be_aes_192  ;
	mk_lib_crypto_mode_ctr_be_aes_256_t  m_ctr_be_aes_256  ;
	mk_lib_crypto_mode_ofb_aes_128_t     m_ofb_aes_128     ;
	mk_lib_crypto_mode_ofb_aes_192_t     m_ofb_aes_192     ;
	mk_lib_crypto_mode_ofb_aes_256_t     m_ofb_aes_256     ;
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_app_aligned_mode_u mk_lib_crypto_app_aligned_mode_t;

struct mk_lib_crypto_app_mode_s
{
	mk_lib_crypto_app_aligned_mode_t m_data;
};
typedef struct mk_lib_crypto_app_mode_s mk_lib_crypto_app_mode_t;

union mk_lib_crypto_app_aligned_key_u
{
	mk_lib_crypto_alg_aes_128_key_t          m_aes_128         ;
	mk_lib_crypto_alg_aes_192_key_t          m_aes_192         ;
	mk_lib_crypto_alg_aes_256_key_t          m_aes_256         ;
	mk_lib_crypto_mode_cbc_aes_128_key_t     m_cbc_aes_128     ;
	mk_lib_crypto_mode_cbc_aes_192_key_t     m_cbc_aes_192     ;
	mk_lib_crypto_mode_cbc_aes_256_key_t     m_cbc_aes_256     ;
	mk_lib_crypto_mode_cfb_128_aes_128_key_t m_cfb_128_aes_128 ;
	mk_lib_crypto_mode_cfb_128_aes_192_key_t m_cfb_128_aes_192 ;
	mk_lib_crypto_mode_cfb_128_aes_256_key_t m_cfb_128_aes_256 ;
	mk_lib_crypto_mode_cfb_8_aes_128_key_t   m_cfb_8_aes_128   ;
	mk_lib_crypto_mode_cfb_8_aes_192_key_t   m_cfb_8_aes_192   ;
	mk_lib_crypto_mode_cfb_8_aes_256_key_t   m_cfb_8_aes_256   ;
	mk_lib_crypto_mode_ctr_be_aes_128_key_t  m_ctr_be_aes_128  ;
	mk_lib_crypto_mode_ctr_be_aes_192_key_t  m_ctr_be_aes_192  ;
	mk_lib_crypto_mode_ctr_be_aes_256_key_t  m_ctr_be_aes_256  ;
	mk_lib_crypto_mode_ofb_aes_128_key_t     m_ofb_aes_128     ;
	mk_lib_crypto_mode_ofb_aes_192_key_t     m_ofb_aes_192     ;
	mk_lib_crypto_mode_ofb_aes_256_key_t     m_ofb_aes_256     ;
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_app_aligned_key_u mk_lib_crypto_app_aligned_key_t;

struct mk_lib_crypto_app_key_s
{
	mk_lib_crypto_app_aligned_key_t m_data;
};
typedef struct mk_lib_crypto_app_key_s mk_lib_crypto_app_key_t;

union mk_lib_crypto_app_aligned_msg_u
{
	mk_lib_crypto_alg_aes_128_msg_t m_cfb_128_aes_128;
	mk_lib_crypto_alg_aes_192_msg_t m_cfb_128_aes_192;
	mk_lib_crypto_alg_aes_256_msg_t m_cfb_128_aes_256;
	mk_lib_crypto_alg_aes_128_msg_t m_cfb_8_aes_128  ;
	mk_lib_crypto_alg_aes_192_msg_t m_cfb_8_aes_192  ;
	mk_lib_crypto_alg_aes_256_msg_t m_cfb_8_aes_256  ;
	mk_lib_crypto_mode_cbc_aes_128_msg_t     m_cbc_aes_128   ;
	mk_lib_crypto_mode_cbc_aes_192_msg_t     m_cbc_aes_192   ;
	mk_lib_crypto_mode_cbc_aes_256_msg_t     m_cbc_aes_256   ;
	mk_lib_crypto_mode_ctr_be_aes_128_msg_t  m_ctr_be_aes_128;
	mk_lib_crypto_mode_ctr_be_aes_192_msg_t  m_ctr_be_aes_192;
	mk_lib_crypto_mode_ctr_be_aes_256_msg_t  m_ctr_be_aes_256;
	mk_lib_crypto_mode_ofb_aes_128_msg_t     m_ofb_aes_128   ;
	mk_lib_crypto_mode_ofb_aes_192_msg_t     m_ofb_aes_192   ;
	mk_lib_crypto_mode_ofb_aes_256_msg_t     m_ofb_aes_256   ;
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_app_aligned_msg_u mk_lib_crypto_app_aligned_msg_t;

struct mk_lib_crypto_app_msg_s
{
	mk_lib_crypto_app_aligned_msg_t m_data;
};
typedef struct mk_lib_crypto_app_msg_s mk_lib_crypto_app_msg_t;
typedef mk_lib_crypto_app_msg_t const mk_lib_crypto_app_msg_ct;
typedef mk_lib_crypto_app_msg_t* mk_lib_crypto_app_msg_pt;
typedef mk_lib_crypto_app_msg_t const* mk_lib_crypto_app_msg_pct;

union mk_lib_crypto_app_aligned_buffer_u
{
	mk_sl_cui_uint8_t m_uint8s[1 * 1024 * 1024 + mk_lib_crypto_app_get_msg_size_max_m];
	mk_lib_crypto_app_msg_t m_msg;
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_app_aligned_buffer_u mk_lib_crypto_app_aligned_buffer_t;

struct mk_lib_crypto_app_buffer_s
{
	mk_lib_crypto_app_aligned_buffer_t m_data;
};
typedef struct mk_lib_crypto_app_buffer_s mk_lib_crypto_app_buffer_t;

struct mk_lib_crypto_app_s
{
	mk_lib_crypto_app_id_alg_t m_id_alg;
	mk_lib_crypto_app_id_padding_t m_id_padding;
	mk_lib_crypto_app_id_mode_t m_id_mode;
	mk_lib_crypto_app_key_t m_key;
	mk_lib_crypto_app_mode_t m_mode;
	mk_lib_crypto_app_buffer_t m_buffer;
};
typedef struct mk_lib_crypto_app_s mk_lib_crypto_app_t;
typedef mk_lib_crypto_app_t const mk_lib_crypto_app_ct;
typedef mk_lib_crypto_app_t* mk_lib_crypto_app_pt;
typedef mk_lib_crypto_app_t const* mk_lib_crypto_app_pct;


static mk_lib_crypto_app_t g_mk_lib_crypto_app;


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pt mk_lib_crypto_app_get_data_addr_u8_impl(void) mk_lang_noexcept
{
	return &g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[0];
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_lib_crypto_app_get_data_addr_us_impl(void) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_lang_types_usize_t) == sizeof(mk_lang_types_uintptr_t));
	mk_lang_static_assert(sizeof(mk_lang_types_usize_t) == sizeof(mk_sl_cui_uint8_pt));

	return ((mk_lang_types_usize_t)(((mk_lang_types_uintptr_t)(mk_lib_crypto_app_get_data_addr_u8_impl()))));
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_lib_crypto_app_get_data_size_impl(void) mk_lang_noexcept
{
	mk_lang_assert(mk_lib_crypto_app_get_msg_size_max_m == mk_lib_crypto_app_get_msg_size_max_f());

	return ((mk_lang_types_usize_t)(sizeof(g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s) / sizeof(g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[0]) - mk_lib_crypto_app_get_msg_size_max_m));
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pt mk_lib_crypto_app_get_names_append_cnt(mk_sl_cui_uint8_pt const ptr, int const ctr) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt p mk_lang_constexpr_init;
	mk_sl_cui_uint8_t u8 mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(ctr >= 0x00 && ctr <= 0xff);

	p = ptr;
	mk_sl_cui_uint8_from_bi_sint(&u8, &ctr);
	*p = u8; p += 1;
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pt mk_lib_crypto_app_get_names_append_nms(mk_sl_cui_uint8_pt const ptr, mk_lang_types_uchar_pct const nms, int const nms_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt p mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(nms);
	mk_lang_assert(nms_len >= 1);

	p = ptr;
	for(i = 0; i != nms_len; ++i){ mk_sl_cui_uint8_from_bi_uchar(&ptr[i], &nms[i]); } p += nms_len;
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pt mk_lib_crypto_app_get_names_append_str(mk_sl_cui_uint8_pt const ptr, mk_lang_types_pchar_pct const str, int const str_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt p mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(str);
	mk_lang_assert(str_len >= 1);

	p = ptr;
	for(i = 0; i != str_len; ++i){ mk_sl_cui_uint8_from_bi_pchar(&ptr[i], &str[i]); } p += str_len;
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline int mk_lib_crypto_app_get_names_impl_sum(int const cnt, mk_lang_types_uchar_pct const lens) mk_lang_noexcept
{
	int sum mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cnt >= 0x00 && cnt <= 0xff);
	mk_lang_assert(lens);

	sum = 0;
	for(i = 0; i != cnt; ++i)
	{
		sum += lens[i];
	}
	return sum;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pt mk_lib_crypto_app_get_names_impl_one(mk_sl_cui_uint8_pt const ptr, int const cnt, mk_lang_types_uchar_pct const order, mk_lang_types_uchar_pct const code_lens, mk_lang_types_pchar_pct const code, mk_lang_types_uchar_pct const pretty_lens, mk_lang_types_pchar_pct const pretty) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt p mk_lang_constexpr_init;

	mk_lang_assert(ptr);

	p = ptr;
	p = mk_lib_crypto_app_get_names_append_cnt(p, cnt);
	p = mk_lib_crypto_app_get_names_append_nms(p, order, cnt);
	p = mk_lib_crypto_app_get_names_append_nms(p, code_lens, cnt);
	p = mk_lib_crypto_app_get_names_append_str(p, code, mk_lib_crypto_app_get_names_impl_sum(cnt, code_lens));
	p = mk_lib_crypto_app_get_names_append_nms(p, pretty_lens, cnt);
	p = mk_lib_crypto_app_get_names_append_str(p, pretty, mk_lib_crypto_app_get_names_impl_sum(cnt, pretty_lens));
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_get_names_impl_4(mk_sl_cui_uint8_pt const ptr) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt p mk_lang_constexpr_init;

	mk_lang_static_assert(s_mk_lib_crypto_app_namelen_code_algs_len     == s_mk_lib_crypto_app_namelen_pretty_algs_len    );
	mk_lang_static_assert(s_mk_lib_crypto_app_namelen_code_paddings_len == s_mk_lib_crypto_app_namelen_pretty_paddings_len);
	mk_lang_static_assert(s_mk_lib_crypto_app_namelen_code_modes_len    == s_mk_lib_crypto_app_namelen_pretty_modes_len   );
	mk_lang_static_assert(s_mk_lib_crypto_app_namelen_code_kdfs_len     == s_mk_lib_crypto_app_namelen_pretty_kdfs_len    );

	p = ptr;

	p = mk_lib_crypto_app_get_names_impl_one(p, s_mk_lib_crypto_app_namelen_code_algs_len    , s_mk_lib_crypto_app_order_algs    , s_mk_lib_crypto_app_namelen_code_algs    , s_mk_lib_crypto_app_name_code_algs    , s_mk_lib_crypto_app_namelen_pretty_algs    , s_mk_lib_crypto_app_name_pretty_algs    );
	p = mk_lib_crypto_app_get_names_impl_one(p, s_mk_lib_crypto_app_namelen_code_paddings_len, s_mk_lib_crypto_app_order_paddings, s_mk_lib_crypto_app_namelen_code_paddings, s_mk_lib_crypto_app_name_code_paddings, s_mk_lib_crypto_app_namelen_pretty_paddings, s_mk_lib_crypto_app_name_pretty_paddings);
	p = mk_lib_crypto_app_get_names_impl_one(p, s_mk_lib_crypto_app_namelen_code_modes_len   , s_mk_lib_crypto_app_order_modes   , s_mk_lib_crypto_app_namelen_code_modes   , s_mk_lib_crypto_app_name_code_modes   , s_mk_lib_crypto_app_namelen_pretty_modes   , s_mk_lib_crypto_app_name_pretty_modes   );
	p = mk_lib_crypto_app_get_names_impl_one(p, s_mk_lib_crypto_app_namelen_code_kdfs_len    , s_mk_lib_crypto_app_order_kdfs    , s_mk_lib_crypto_app_namelen_code_kdfs    , s_mk_lib_crypto_app_name_code_kdfs    , s_mk_lib_crypto_app_namelen_pretty_kdfs    , s_mk_lib_crypto_app_name_pretty_kdfs    );

	mk_lang_assert(((int)(p - ptr)) <= ((int)(mk_lib_crypto_app_get_data_size_impl())));

	return ((mk_lang_types_ssize_t)(p - ptr));
}

#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t n>
struct mk_lib_crypto_app_get_names_impl_s
{
	static constexpr mk_lang_types_ssize_t s_size = n;
	mk_sl_cui_uint8_t m_data[n];
};

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_get_names_impl_3(void) mk_lang_noexcept
{
	mk_sl_cui_uint8_t buff[2 * 1024] mk_lang_constexpr_init;
	mk_lang_types_ssize_t s mk_lang_constexpr_init;

	s = mk_lib_crypto_app_get_names_impl_4(buff);
	return s;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline auto mk_lib_crypto_app_get_names_impl_2(void) mk_lang_noexcept
{
	mk_lib_crypto_app_get_names_impl_s<mk_lib_crypto_app_get_names_impl_3()> buff mk_lang_constexpr_init;
	mk_lang_types_ssize_t s mk_lang_constexpr_init;

	s = mk_lib_crypto_app_get_names_impl_4(buff.m_data);
	mk_lang_assert(s == buff.s_size);
	return buff;
}

#endif

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_get_names_impl(void) mk_lang_noexcept
{
	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_init = mk_lib_crypto_app_get_names_impl_2();

	int i mk_lang_constexpr_init;

	for(i = 0; i != s_init.s_size; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[i] = s_init.m_data[i]; }
	return s_init.s_size;

	#else

	return mk_lib_crypto_app_get_names_impl_4(&g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[0]);

	#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_get_iv_size_max_impl(void) mk_lang_noexcept
{
	mk_lang_assert(mk_lib_crypto_app_get_iv_size_max_m == mk_lib_crypto_app_get_iv_size_max_f());

	return mk_lib_crypto_app_get_iv_size_max_m;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_any_id(mk_sl_cui_uint8_pct const ptr, mk_lang_types_uchar_pt const any_id, int const cnt, mk_lang_types_uchar_pct const lens, mk_lang_types_pchar_pct const codes) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	mk_lang_types_uchar_t len mk_lang_constexpr_init;
	mk_lang_types_pchar_pct names mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(any_id);
	mk_lang_assert(cnt >= 0x01 && cnt <= 0xff);
	mk_lang_assert(lens);
	mk_lang_assert(codes);

	p = ptr;
	mk_sl_cui_uint8_to_bi_uchar(&p[0], &len); ++p;
	names = codes;
	for(i = 0; i != cnt; ++i)
	{
		if(lens[i] == len)
		{
			for(j = 0; j != len; ++j)
			{
				mk_sl_cui_uint8_to_bi_uchar(&p[j], &uc);
				if(names[j] != uc)
				{
					break;
				}
			}
			if(j == len)
			{
				*any_id = ((mk_lang_types_uchar_t)(i));
				p += len;
				return p;
			}
		}
		names += lens[i];
	}
	return mk_lang_null;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_alg_id(mk_sl_cui_uint8_pct const ptr, mk_lib_crypto_app_id_alg_pt const alg_id) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(alg_id);

	p = ptr;
	p = mk_lib_crypto_app_init_any_id(p, &uc, s_mk_lib_crypto_app_namelen_code_algs_len, s_mk_lib_crypto_app_namelen_code_algs, s_mk_lib_crypto_app_name_code_algs); if(!p) return mk_lang_null;
	mk_lang_assert(uc >= 0 && uc < mk_lib_crypto_app_id_alg_e_dummy_end);
	*alg_id = ((mk_lib_crypto_app_id_alg_t)(uc));
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_padding_id(mk_sl_cui_uint8_pct const ptr, mk_lib_crypto_app_id_padding_pt const padding_id) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(padding_id);

	p = ptr;
	p = mk_lib_crypto_app_init_any_id(p, &uc, s_mk_lib_crypto_app_namelen_code_paddings_len, s_mk_lib_crypto_app_namelen_code_paddings, s_mk_lib_crypto_app_name_code_paddings); if(!p) return mk_lang_null;
	mk_lang_assert(uc >= 0 && uc < mk_lib_crypto_app_id_padding_e_dummy_end);
	*padding_id = ((mk_lib_crypto_app_id_padding_t)(uc));
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_mode_id(mk_sl_cui_uint8_pct const ptr, mk_lib_crypto_app_id_mode_pt const mode_id) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(mode_id);

	p = ptr;
	p = mk_lib_crypto_app_init_any_id(p, &uc, s_mk_lib_crypto_app_namelen_code_modes_len, s_mk_lib_crypto_app_namelen_code_modes, s_mk_lib_crypto_app_name_code_modes); if(!p) return mk_lang_null;
	mk_lang_assert(uc >= 0 && uc < mk_lib_crypto_app_id_mode_e_dummy_end);
	*mode_id = ((mk_lib_crypto_app_id_mode_t)(uc));
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_kdf_id(mk_sl_cui_uint8_pct const ptr, mk_lib_crypto_app_id_kdf_pt const kdf_id) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(kdf_id);

	p = ptr;
	p = mk_lib_crypto_app_init_any_id(p, &uc, s_mk_lib_crypto_app_namelen_code_kdfs_len, s_mk_lib_crypto_app_namelen_code_kdfs, s_mk_lib_crypto_app_name_code_kdfs); if(!p) return mk_lang_null;
	mk_lang_assert(uc >= 0 && uc < mk_lib_crypto_app_id_kdf_e_dummy_end);
	*kdf_id = ((mk_lib_crypto_app_id_kdf_t)(uc));
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_buff(mk_sl_cui_uint8_pct const ptr, int const len, mk_sl_cui_uint8_pt const dst) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(len >= 1 && len <= 4 * 1024);
	mk_lang_assert(dst);

	p = ptr;
	for(i = 0; i != len; ++i){ dst[i] = p[i]; } p += len;
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_iv(mk_sl_cui_uint8_pct const ptr, mk_lib_crypto_app_id_alg_t const alg_id, mk_lib_crypto_app_id_mode_t const mode_id, mk_lib_crypto_app_msg_pt const iv) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(iv);

	p = ptr;
	if(0){}

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ecb){}
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ecb){}
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ecb){}

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cbc_aes_128_iv_len_v    , &iv->m_data.m_cbc_aes_128    .m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cbc_aes_192_iv_len_v    , &iv->m_data.m_cbc_aes_192    .m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cbc_aes_256_iv_len_v    , &iv->m_data.m_cbc_aes_256    .m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_128_aes_128_iv_len_v, &iv->m_data.m_cfb_128_aes_128.m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_128_aes_192_iv_len_v, &iv->m_data.m_cfb_128_aes_192.m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_128_aes_256_iv_len_v, &iv->m_data.m_cfb_128_aes_256.m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_8_aes_128_iv_len_v  , &iv->m_data.m_cfb_8_aes_128  .m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_8_aes_192_iv_len_v  , &iv->m_data.m_cfb_8_aes_192  .m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_8_aes_256_iv_len_v  , &iv->m_data.m_cfb_8_aes_256  .m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ctr_be_aes_128_iv_len_v , &iv->m_data.m_ctr_be_aes_128 .m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ctr_be_aes_192_iv_len_v , &iv->m_data.m_ctr_be_aes_192 .m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ctr_be_aes_256_iv_len_v , &iv->m_data.m_ctr_be_aes_256 .m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ofb_aes_128_iv_len_v    , &iv->m_data.m_ofb_aes_128    .m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ofb_aes_192_iv_len_v    , &iv->m_data.m_ofb_aes_192    .m_data.m_uint8s[0]))); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ofb_aes_256_iv_len_v    , &iv->m_data.m_ofb_aes_256    .m_data.m_uint8s[0]))); }

	else{ mk_lang_assert(0); }

	mk_lang_assert(mk_lib_crypto_app_get_iv_size_max_m == mk_lib_crypto_app_get_iv_size_max_f());
	p += mk_lib_crypto_app_get_iv_size_max_m;
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_num(mk_sl_cui_uint8_pct const ptr, mk_sl_cui_uint32_pt const num) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(num);

	p = ptr;
	mk_sl_uint_32_from_8_le(num, p); p += 32 / 8;
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_str(mk_sl_cui_uint8_pct const ptr, mk_lang_types_sint_pt const len, mk_sl_cui_uint8_pct* const str) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	mk_sl_cui_uint32_t u32 mk_lang_constexpr_init;
	mk_lang_types_ulong_t ul mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(len);
	mk_lang_assert(str);

	p = ptr;
	p = mk_lib_crypto_app_init_num(p, &u32); if(!p) return mk_lang_null;
	mk_sl_cui_uint32_to_bi_ulong(&u32, &ul);
	if(!(ul >= 0 && ul <= 4 * 1024)) return mk_lang_null;
	*len = ((int)(ul));
	*str = p; p += ul;
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_init_impl(void) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lib_crypto_app_id_alg_t alg_id mk_lang_constexpr_init;
	mk_lib_crypto_app_id_padding_t padding_id mk_lang_constexpr_init;
	mk_lib_crypto_app_id_mode_t mode_id mk_lang_constexpr_init;
	mk_lib_crypto_app_id_kdf_t kdf_id mk_lang_constexpr_init;
	mk_lib_crypto_app_msg_t iv mk_lang_constexpr_init;
	int pwd_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct pwd_buf mk_lang_constexpr_init;
	int slt_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct slt_buf mk_lang_constexpr_init;
	mk_sl_cui_uint32_t cost mk_lang_constexpr_init;
	mk_lang_types_ulong_t cost_ul mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t slt8[8] mk_lang_constexpr_init;
	int iv_len mk_lang_constexpr_init;
	int key_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_t key_data[mk_lib_crypto_app_get_key_size_max_m] mk_lang_constexpr_init;

	mk_lang_assert(mk_lib_crypto_app_get_key_size_max_m == mk_lib_crypto_app_get_key_size_max_f());

	ptr = &g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[0];
	ptr = mk_lib_crypto_app_init_alg_id    (ptr, &alg_id             ); if(!ptr) return -1;
	ptr = mk_lib_crypto_app_init_padding_id(ptr, &padding_id         ); if(!ptr) return -1;
	ptr = mk_lib_crypto_app_init_mode_id   (ptr, &mode_id            ); if(!ptr) return -1;
	ptr = mk_lib_crypto_app_init_kdf_id    (ptr, &kdf_id             ); if(!ptr) return -1;
	ptr = mk_lib_crypto_app_init_iv        (ptr, alg_id, mode_id, &iv); if(!ptr) return -1;
	ptr = mk_lib_crypto_app_init_num       (ptr, &cost               ); if(!ptr) return -1;
	ptr = mk_lib_crypto_app_init_str       (ptr, &pwd_len, &pwd_buf  ); if(!ptr) return -1;
	ptr = mk_lib_crypto_app_init_str       (ptr, &slt_len, &slt_buf  ); if(!ptr) return -1;

	g_mk_lib_crypto_app.m_id_alg = alg_id;
	g_mk_lib_crypto_app.m_id_padding = padding_id;
	g_mk_lib_crypto_app.m_id_mode = mode_id;
	mk_sl_cui_uint32_to_bi_ulong(&cost, &cost_ul);
	for(i = 0; i != mk_lang_min(8, slt_len); ++i){ slt8[i] = slt_buf[i]; }
	for(i = mk_lang_min(8, slt_len); i != 8; ++i){ mk_sl_cui_uint8_set_zero(&slt8[i]); }

	if(0){}

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ecb){ iv_len = 0;}
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ecb){ iv_len = 0;}
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ecb){ iv_len = 0;}

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ iv_len = mk_lib_crypto_mode_cbc_aes_128_iv_len_v     ; mk_lib_crypto_mode_cbc_aes_128_init    (&g_mk_lib_crypto_app.m_mode.m_data.m_cbc_aes_128    , &iv.m_data.m_cbc_aes_128    ); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ iv_len = mk_lib_crypto_mode_cbc_aes_192_iv_len_v     ; mk_lib_crypto_mode_cbc_aes_192_init    (&g_mk_lib_crypto_app.m_mode.m_data.m_cbc_aes_192    , &iv.m_data.m_cbc_aes_192    ); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ iv_len = mk_lib_crypto_mode_cbc_aes_256_iv_len_v     ; mk_lib_crypto_mode_cbc_aes_256_init    (&g_mk_lib_crypto_app.m_mode.m_data.m_cbc_aes_256    , &iv.m_data.m_cbc_aes_256    ); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ iv_len = mk_lib_crypto_mode_cfb_128_aes_128_iv_len_v ; mk_lib_crypto_mode_cfb_128_aes_128_init(&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_128_aes_128, &iv.m_data.m_cfb_128_aes_128); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ iv_len = mk_lib_crypto_mode_cfb_128_aes_192_iv_len_v ; mk_lib_crypto_mode_cfb_128_aes_192_init(&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_128_aes_192, &iv.m_data.m_cfb_128_aes_192); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ iv_len = mk_lib_crypto_mode_cfb_128_aes_256_iv_len_v ; mk_lib_crypto_mode_cfb_128_aes_256_init(&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_128_aes_256, &iv.m_data.m_cfb_128_aes_256); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ iv_len = mk_lib_crypto_mode_cfb_8_aes_128_iv_len_v   ; mk_lib_crypto_mode_cfb_8_aes_128_init  (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_8_aes_128  , &iv.m_data.m_cfb_8_aes_128  ); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ iv_len = mk_lib_crypto_mode_cfb_8_aes_192_iv_len_v   ; mk_lib_crypto_mode_cfb_8_aes_192_init  (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_8_aes_192  , &iv.m_data.m_cfb_8_aes_192  ); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ iv_len = mk_lib_crypto_mode_cfb_8_aes_256_iv_len_v   ; mk_lib_crypto_mode_cfb_8_aes_256_init  (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_8_aes_256  , &iv.m_data.m_cfb_8_aes_256  ); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ iv_len = mk_lib_crypto_mode_ctr_be_aes_128_iv_len_v  ; mk_lib_crypto_mode_ctr_be_aes_128_init (&g_mk_lib_crypto_app.m_mode.m_data.m_ctr_be_aes_128 , &iv.m_data.m_ctr_be_aes_128 ); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ iv_len = mk_lib_crypto_mode_ctr_be_aes_192_iv_len_v  ; mk_lib_crypto_mode_ctr_be_aes_192_init (&g_mk_lib_crypto_app.m_mode.m_data.m_ctr_be_aes_192 , &iv.m_data.m_ctr_be_aes_192 ); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ iv_len = mk_lib_crypto_mode_ctr_be_aes_256_iv_len_v  ; mk_lib_crypto_mode_ctr_be_aes_256_init (&g_mk_lib_crypto_app.m_mode.m_data.m_ctr_be_aes_256 , &iv.m_data.m_ctr_be_aes_256 ); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ iv_len = mk_lib_crypto_mode_ofb_aes_128_iv_len_v     ; mk_lib_crypto_mode_ofb_aes_128_init    (&g_mk_lib_crypto_app.m_mode.m_data.m_ofb_aes_128    , &iv.m_data.m_ofb_aes_128    ); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ iv_len = mk_lib_crypto_mode_ofb_aes_192_iv_len_v     ; mk_lib_crypto_mode_ofb_aes_192_init    (&g_mk_lib_crypto_app.m_mode.m_data.m_ofb_aes_192    , &iv.m_data.m_ofb_aes_192    ); }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ iv_len = mk_lib_crypto_mode_ofb_aes_256_iv_len_v     ; mk_lib_crypto_mode_ofb_aes_256_init    (&g_mk_lib_crypto_app.m_mode.m_data.m_ofb_aes_256    , &iv.m_data.m_ofb_aes_256    ); }

	else{ mk_lang_assert(0); }

	switch(alg_id)
	{
		case mk_lib_crypto_app_id_alg_e_aes_128: key_len = mk_lib_crypto_alg_aes_128_key_len_v; break;
		case mk_lib_crypto_app_id_alg_e_aes_192: key_len = mk_lib_crypto_alg_aes_192_key_len_v; break;
		case mk_lib_crypto_app_id_alg_e_aes_256: key_len = mk_lib_crypto_alg_aes_256_key_len_v; break;
		default: mk_lang_assert(0); break;
	}

	if(0){}
	else if(kdf_id == mk_lib_crypto_app_id_kdf_e_pbkdf1_md2  && key_len > mk_lib_crypto_hash_block_md2_digest_len  ) return -1;
	else if(kdf_id == mk_lib_crypto_app_id_kdf_e_pbkdf1_md5  && key_len > mk_lib_crypto_hash_block_md5_digest_len  ) return -1;
	else if(kdf_id == mk_lib_crypto_app_id_kdf_e_pbkdf1_sha1 && key_len > mk_lib_crypto_hash_block_sha1_digest_len ) return -1;

	switch(kdf_id)
	{
		case mk_lib_crypto_app_id_kdf_e_pbkdf1_md2         : mk_lib_crypto_kdf_pbkdf1_md2_u8 (pwd_buf, pwd_len, slt8, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf1_md5         : mk_lib_crypto_kdf_pbkdf1_md5_u8 (pwd_buf, pwd_len, slt8, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf1_sha1        : mk_lib_crypto_kdf_pbkdf1_sha1_u8(pwd_buf, pwd_len, slt8, cost_ul, key_len, &key_data[0]); break;

		case mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_256 : mk_lib_crypto_kdf_pbkdf2_blake2b_256_u8 (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_384 : mk_lib_crypto_kdf_pbkdf2_blake2b_384_u8 (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2b_512 : mk_lib_crypto_kdf_pbkdf2_blake2b_512_u8 (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_128 : mk_lib_crypto_kdf_pbkdf2_blake2s_128_u8 (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_160 : mk_lib_crypto_kdf_pbkdf2_blake2s_160_u8 (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_224 : mk_lib_crypto_kdf_pbkdf2_blake2s_224_u8 (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_blake2s_256 : mk_lib_crypto_kdf_pbkdf2_blake2s_256_u8 (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_blake3      : mk_lib_crypto_kdf_pbkdf2_blake3_u8      (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_md2         : mk_lib_crypto_kdf_pbkdf2_md2_u8         (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_md4         : mk_lib_crypto_kdf_pbkdf2_md4_u8         (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_md5         : mk_lib_crypto_kdf_pbkdf2_md5_u8         (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha0        : mk_lib_crypto_kdf_pbkdf2_sha0_u8        (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha1        : mk_lib_crypto_kdf_pbkdf2_sha1_u8        (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_224    : mk_lib_crypto_kdf_pbkdf2_sha2_224_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_256    : mk_lib_crypto_kdf_pbkdf2_sha2_256_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_384    : mk_lib_crypto_kdf_pbkdf2_sha2_384_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512    : mk_lib_crypto_kdf_pbkdf2_sha2_512_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512_224: mk_lib_crypto_kdf_pbkdf2_sha2_512_224_u8(pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha2_512_256: mk_lib_crypto_kdf_pbkdf2_sha2_512_256_u8(pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_224    : mk_lib_crypto_kdf_pbkdf2_sha3_224_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_256    : mk_lib_crypto_kdf_pbkdf2_sha3_256_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_384    : mk_lib_crypto_kdf_pbkdf2_sha3_384_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_sha3_512    : mk_lib_crypto_kdf_pbkdf2_sha3_512_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_128  : mk_lib_crypto_kdf_pbkdf2_tiger2_128_u8  (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_160  : mk_lib_crypto_kdf_pbkdf2_tiger2_160_u8  (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger2_192  : mk_lib_crypto_kdf_pbkdf2_tiger2_192_u8  (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_128   : mk_lib_crypto_kdf_pbkdf2_tiger_128_u8   (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_160   : mk_lib_crypto_kdf_pbkdf2_tiger_160_u8   (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_id_kdf_e_pbkdf2_tiger_192   : mk_lib_crypto_kdf_pbkdf2_tiger_192_u8   (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;

		default: mk_lang_assert(0); break;
	}

	if(0){}

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ecb){ for(i = 0; i != mk_lib_crypto_alg_aes_128_key_len_v; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_aes_128.m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ecb){ for(i = 0; i != mk_lib_crypto_alg_aes_192_key_len_v; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_aes_192.m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ecb){ for(i = 0; i != mk_lib_crypto_alg_aes_256_key_len_v; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_aes_256.m_data.m_uint8s[i] = key_data[i]; } }

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cbc    ){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_key_len_v    ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_cbc_aes_128    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cbc    ){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_key_len_v    ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_cbc_aes_192    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cbc    ){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_key_len_v    ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_cbc_aes_256    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_key_len_v; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_cfb_128_aes_128.m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_key_len_v; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_cfb_128_aes_192.m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_key_len_v; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_cfb_128_aes_256.m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8  ){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_key_len_v  ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_cfb_8_aes_128  .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8  ){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_key_len_v  ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_cfb_8_aes_192  .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8  ){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_key_len_v  ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_cfb_8_aes_256  .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be ){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_key_len_v ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_ctr_be_aes_128 .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be ){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_key_len_v ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_ctr_be_aes_192 .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be ){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_key_len_v ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_ctr_be_aes_256 .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ofb    ){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_key_len_v    ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_ofb_aes_128    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ofb    ){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_key_len_v    ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_ofb_aes_192    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ofb    ){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_key_len_v    ; ++i){ g_mk_lib_crypto_app.m_key.m_data.m_ofb_aes_256    .m_data.m_uint8s[i] = key_data[i]; } }

	else{ mk_lang_assert(0); }

	return iv_len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline int mk_lib_crypto_app_get_msg_len(mk_lib_crypto_app_id_alg_t const alg_id, mk_lib_crypto_app_id_mode_t const mode_id) mk_lang_noexcept
{
	int len mk_lang_constexpr_init;

	if(0){}

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ecb ){ len = mk_lib_crypto_alg_aes_128_msg_len_v; }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ecb ){ len = mk_lib_crypto_alg_aes_192_msg_len_v; }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ecb ){ len = mk_lib_crypto_alg_aes_256_msg_len_v; }

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ len = mk_lib_crypto_mode_cbc_aes_128_msg_len_v;     }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ len = mk_lib_crypto_mode_cbc_aes_192_msg_len_v;     }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ len = mk_lib_crypto_mode_cbc_aes_256_msg_len_v;     }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ len = mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v; }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ len = mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ len = mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v; }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ len = mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v;   }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ len = mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v;   }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ len = mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v;   }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ len = mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v;  }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ len = mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v;  }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ len = mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v;  }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ len = mk_lib_crypto_mode_ofb_aes_128_msg_len_v;     }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ len = mk_lib_crypto_mode_ofb_aes_192_msg_len_v;     }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ len = mk_lib_crypto_mode_ofb_aes_256_msg_len_v;     }

	else{ mk_lang_assert(0); }

	return len;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_app_encrypt_mode(mk_lib_crypto_app_id_alg_t const alg_id, mk_lib_crypto_app_id_mode_t const mode_id, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_app_get_data_size_impl());

	if(0){}

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ecb ){ mk_lib_crypto_alg_aes_128_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_alg_aes_128_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_alg_aes_128_encrypt(&g_mk_lib_crypto_app.m_key.m_data.m_aes_128, &msg, &msg); for(i = 0; i != mk_lib_crypto_alg_aes_128_msg_len_v; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ecb ){ mk_lib_crypto_alg_aes_192_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_alg_aes_192_encrypt(&g_mk_lib_crypto_app.m_key.m_data.m_aes_192, &msg, &msg); for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ecb ){ mk_lib_crypto_alg_aes_256_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_alg_aes_256_encrypt(&g_mk_lib_crypto_app.m_key.m_data.m_aes_256, &msg, &msg); for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ mk_lib_crypto_mode_cbc_aes_128_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_128_encrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_cbc_aes_128     , &g_mk_lib_crypto_app.m_key.m_data.m_cbc_aes_128     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ mk_lib_crypto_mode_cbc_aes_192_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_192_encrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_cbc_aes_192     , &g_mk_lib_crypto_app.m_key.m_data.m_cbc_aes_192     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ mk_lib_crypto_mode_cbc_aes_256_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_256_encrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_cbc_aes_256     , &g_mk_lib_crypto_app.m_key.m_data.m_cbc_aes_256     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ mk_lib_crypto_mode_cfb_128_aes_128_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_128_encrypt (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_128_aes_128 , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_128_aes_128 , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ mk_lib_crypto_mode_cfb_128_aes_192_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_192_encrypt (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_128_aes_192 , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_128_aes_192 , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ mk_lib_crypto_mode_cfb_128_aes_256_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_256_encrypt (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_128_aes_256 , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_128_aes_256 , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ mk_lib_crypto_mode_cfb_8_aes_128_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_128_encrypt   (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_8_aes_128   , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_8_aes_128   , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v   ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ mk_lib_crypto_mode_cfb_8_aes_192_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_192_encrypt   (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_8_aes_192   , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_8_aes_192   , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v   ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ mk_lib_crypto_mode_cfb_8_aes_256_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_256_encrypt   (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_8_aes_256   , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_8_aes_256   , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v   ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ mk_lib_crypto_mode_ctr_be_aes_128_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_128_encrypt  (&g_mk_lib_crypto_app.m_mode.m_data.m_ctr_be_aes_128  , &g_mk_lib_crypto_app.m_key.m_data.m_ctr_be_aes_128  , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v  ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ mk_lib_crypto_mode_ctr_be_aes_192_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_192_encrypt  (&g_mk_lib_crypto_app.m_mode.m_data.m_ctr_be_aes_192  , &g_mk_lib_crypto_app.m_key.m_data.m_ctr_be_aes_192  , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v  ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ mk_lib_crypto_mode_ctr_be_aes_256_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_256_encrypt  (&g_mk_lib_crypto_app.m_mode.m_data.m_ctr_be_aes_256  , &g_mk_lib_crypto_app.m_key.m_data.m_ctr_be_aes_256  , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v  ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ mk_lib_crypto_mode_ofb_aes_128_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_128_encrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_ofb_aes_128     , &g_mk_lib_crypto_app.m_key.m_data.m_ofb_aes_128     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ mk_lib_crypto_mode_ofb_aes_192_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_192_encrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_ofb_aes_192     , &g_mk_lib_crypto_app.m_key.m_data.m_ofb_aes_192     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ mk_lib_crypto_mode_ofb_aes_256_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_256_encrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_ofb_aes_256     , &g_mk_lib_crypto_app.m_key.m_data.m_ofb_aes_256     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }

	else{ mk_lang_assert(0); }
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_app_decrypt_mode(mk_lib_crypto_app_id_alg_t const alg_id, mk_lib_crypto_app_id_mode_t const mode_id, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_app_get_data_size_impl());

	if(0){}

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ecb ){ mk_lib_crypto_alg_aes_128_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_alg_aes_128_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_alg_aes_128_decrypt(&g_mk_lib_crypto_app.m_key.m_data.m_aes_128, &msg, &msg); for(i = 0; i != mk_lib_crypto_alg_aes_128_msg_len_v; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ecb ){ mk_lib_crypto_alg_aes_192_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_alg_aes_192_decrypt(&g_mk_lib_crypto_app.m_key.m_data.m_aes_192, &msg, &msg); for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ecb ){ mk_lib_crypto_alg_aes_256_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_alg_aes_256_decrypt(&g_mk_lib_crypto_app.m_key.m_data.m_aes_256, &msg, &msg); for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }

	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ mk_lib_crypto_mode_cbc_aes_128_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_128_decrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_cbc_aes_128     , &g_mk_lib_crypto_app.m_key.m_data.m_cbc_aes_128     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ mk_lib_crypto_mode_cbc_aes_192_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_192_decrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_cbc_aes_192     , &g_mk_lib_crypto_app.m_key.m_data.m_cbc_aes_192     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cbc     ){ mk_lib_crypto_mode_cbc_aes_256_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_256_decrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_cbc_aes_256     , &g_mk_lib_crypto_app.m_key.m_data.m_cbc_aes_256     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ mk_lib_crypto_mode_cfb_128_aes_128_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_128_decrypt (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_128_aes_128 , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_128_aes_128 , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ mk_lib_crypto_mode_cfb_128_aes_192_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_192_decrypt (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_128_aes_192 , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_128_aes_192 , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_128 ){ mk_lib_crypto_mode_cfb_128_aes_256_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_256_decrypt (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_128_aes_256 , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_128_aes_256 , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ mk_lib_crypto_mode_cfb_8_aes_128_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_128_decrypt   (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_8_aes_128   , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_8_aes_128   , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v   ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ mk_lib_crypto_mode_cfb_8_aes_192_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_192_decrypt   (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_8_aes_192   , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_8_aes_192   , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v   ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_cfb_8   ){ mk_lib_crypto_mode_cfb_8_aes_256_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_256_decrypt   (&g_mk_lib_crypto_app.m_mode.m_data.m_cfb_8_aes_256   , &g_mk_lib_crypto_app.m_key.m_data.m_cfb_8_aes_256   , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v   ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ mk_lib_crypto_mode_ctr_be_aes_128_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_128_decrypt  (&g_mk_lib_crypto_app.m_mode.m_data.m_ctr_be_aes_128  , &g_mk_lib_crypto_app.m_key.m_data.m_ctr_be_aes_128  , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v  ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ mk_lib_crypto_mode_ctr_be_aes_192_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_192_decrypt  (&g_mk_lib_crypto_app.m_mode.m_data.m_ctr_be_aes_192  , &g_mk_lib_crypto_app.m_key.m_data.m_ctr_be_aes_192  , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v  ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ctr_be  ){ mk_lib_crypto_mode_ctr_be_aes_256_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_256_decrypt  (&g_mk_lib_crypto_app.m_mode.m_data.m_ctr_be_aes_256  , &g_mk_lib_crypto_app.m_key.m_data.m_ctr_be_aes_256  , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v  ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_128 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ mk_lib_crypto_mode_ofb_aes_128_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_128_decrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_ofb_aes_128     , &g_mk_lib_crypto_app.m_key.m_data.m_ofb_aes_128     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_192 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ mk_lib_crypto_mode_ofb_aes_192_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_192_decrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_ofb_aes_192     , &g_mk_lib_crypto_app.m_key.m_data.m_ofb_aes_192     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }
	else if(alg_id == mk_lib_crypto_app_id_alg_e_aes_256 && mode_id == mk_lib_crypto_app_id_mode_e_ofb     ){ mk_lib_crypto_mode_ofb_aes_256_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_256_decrypt     (&g_mk_lib_crypto_app.m_mode.m_data.m_ofb_aes_256     , &g_mk_lib_crypto_app.m_key.m_data.m_ofb_aes_256     , &msg, &msg); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v     ; ++i){ g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } }

	else{ mk_lang_assert(0); }
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_encrypt_append_impl(mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_lang_types_usize_t msg_len mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	if(!(len >= 0 && len <= mk_lib_crypto_app_get_data_size_impl())) return -1;
	msg_len = mk_lib_crypto_app_get_msg_len(g_mk_lib_crypto_app.m_id_alg, g_mk_lib_crypto_app.m_id_mode);
	if(!(len % msg_len == 0)) return -1;
	n = len / msg_len;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_app_encrypt_mode(g_mk_lib_crypto_app.m_id_alg, g_mk_lib_crypto_app.m_id_mode, i * msg_len);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_encrypt_finish_impl(mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_lang_types_usize_t msg_len mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t q mk_lang_constexpr_init;
	mk_lang_types_usize_t m mk_lang_constexpr_init;
	mk_lang_types_ssize_t r mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	if(!(len >= 0 && len <= mk_lib_crypto_app_get_data_size_impl())) return -1;
	msg_len = mk_lib_crypto_app_get_msg_len(g_mk_lib_crypto_app.m_id_alg, g_mk_lib_crypto_app.m_id_mode);
	n = len / msg_len;
	q = len % msg_len;
	m = msg_len - q;
	r = mk_lib_crypto_app_encrypt_append_impl(n * msg_len); if(r != 0) return -1;
	for(i = 0; i != m; ++i){ mk_sl_cui_uint8_from_bi_size(&g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[n * msg_len + q + i], &m); }
	mk_lib_crypto_app_encrypt_mode(g_mk_lib_crypto_app.m_id_alg, g_mk_lib_crypto_app.m_id_mode, n * msg_len);
	return m;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_decrypt_append_impl(mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_lang_types_usize_t msg_len mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	if(!(len >= 0 && len <= mk_lib_crypto_app_get_data_size_impl())) return -1;
	msg_len = mk_lib_crypto_app_get_msg_len(g_mk_lib_crypto_app.m_id_alg, g_mk_lib_crypto_app.m_id_mode);
	if(!(len % msg_len == 0)) return -1;
	n = len / msg_len;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_app_decrypt_mode(g_mk_lib_crypto_app.m_id_alg, g_mk_lib_crypto_app.m_id_mode, i * msg_len);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_decrypt_finish_impl(mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_lang_types_ssize_t r mk_lang_constexpr_init;
	int msg_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	int n mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	if(!(len >= 1)) return -1;
	r = mk_lib_crypto_app_decrypt_append_impl(len); if(r != 0) return -1;
	msg_len = mk_lib_crypto_app_get_msg_len(g_mk_lib_crypto_app.m_id_alg, g_mk_lib_crypto_app.m_id_mode);
	ptr = &g_mk_lib_crypto_app.m_buffer.m_data.m_uint8s[len - 1];
	mk_sl_cui_uint8_to_bi_sint(ptr, &n);
	if(!(n >= 1 && n <= msg_len)) return -1;
	for(i = 1; i != n; ++i)
	{
		if(!(mk_sl_cui_uint8_eq(&ptr[0 - i], &ptr[0]))) return -1;
	}
	return n;
}


mk_lang_nodiscard mk_lang_jumbo mk_sl_cui_uint8_pt    mk_lib_crypto_app_get_data_addr_u8 (void)                            mk_lang_noexcept { return mk_lib_crypto_app_get_data_addr_u8_impl ();    }
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_lib_crypto_app_get_data_addr_us (void)                            mk_lang_noexcept { return mk_lib_crypto_app_get_data_addr_us_impl ();    }
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_lib_crypto_app_get_data_size    (void)                            mk_lang_noexcept { return mk_lib_crypto_app_get_data_size_impl    ();    }
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_get_names        (void)                            mk_lang_noexcept { return mk_lib_crypto_app_get_names_impl        ();    }
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_get_iv_size_max  (void)                            mk_lang_noexcept { return mk_lib_crypto_app_get_iv_size_max_impl  ();    }
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_init             (void)                            mk_lang_noexcept { return mk_lib_crypto_app_init_impl             ();    }
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_encrypt_append   (mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_encrypt_append_impl   (len); }
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_encrypt_finish   (mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_encrypt_finish_impl   (len); }
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_decrypt_append   (mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_decrypt_append_impl   (len); }
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_decrypt_finish   (mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_decrypt_finish_impl   (len); }
