#include "mk_lib_crypto_app.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpp.h"
#include "mk_lang_emscripten.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
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
#include "mk_lib_crypto_kdf_pbkdf2_streebog_256.h"
#include "mk_lib_crypto_kdf_pbkdf2_streebog_512.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger2_128.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger2_160.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger2_192.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger_128.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger_160.h"
#include "mk_lib_crypto_kdf_pbkdf2_tiger_192.h"
#include "mk_lib_crypto_kdf_pbkdf2_whirlpool.h"
#include "mk_lib_crypto_mode_cbc_aes_128.h"
#include "mk_lib_crypto_mode_cbc_aes_192.h"
#include "mk_lib_crypto_mode_cbc_aes_256.h"
#include "mk_lib_crypto_mode_cbc_des.h"
#include "mk_lib_crypto_mode_cbc_serpent.h"
#include "mk_lib_crypto_mode_cbc_tdes2.h"
#include "mk_lib_crypto_mode_cbc_tdes3.h"
#include "mk_lib_crypto_mode_cfb_128_aes_128.h"
#include "mk_lib_crypto_mode_cfb_128_aes_192.h"
#include "mk_lib_crypto_mode_cfb_128_aes_256.h"
#include "mk_lib_crypto_mode_cfb_128_serpent.h"
#include "mk_lib_crypto_mode_cfb_64_des.h"
#include "mk_lib_crypto_mode_cfb_64_tdes2.h"
#include "mk_lib_crypto_mode_cfb_64_tdes3.h"
#include "mk_lib_crypto_mode_cfb_8_aes_128.h"
#include "mk_lib_crypto_mode_cfb_8_aes_192.h"
#include "mk_lib_crypto_mode_cfb_8_aes_256.h"
#include "mk_lib_crypto_mode_cfb_8_des.h"
#include "mk_lib_crypto_mode_cfb_8_serpent.h"
#include "mk_lib_crypto_mode_cfb_8_tdes2.h"
#include "mk_lib_crypto_mode_cfb_8_tdes3.h"
#include "mk_lib_crypto_mode_ctr_be_aes_128.h"
#include "mk_lib_crypto_mode_ctr_be_aes_192.h"
#include "mk_lib_crypto_mode_ctr_be_aes_256.h"
#include "mk_lib_crypto_mode_ctr_be_des.h"
#include "mk_lib_crypto_mode_ctr_be_serpent.h"
#include "mk_lib_crypto_mode_ctr_be_tdes2.h"
#include "mk_lib_crypto_mode_ctr_be_tdes3.h"
#include "mk_lib_crypto_mode_ecb_aes_128.h"
#include "mk_lib_crypto_mode_ecb_aes_192.h"
#include "mk_lib_crypto_mode_ecb_aes_256.h"
#include "mk_lib_crypto_mode_ecb_des.h"
#include "mk_lib_crypto_mode_ecb_serpent.h"
#include "mk_lib_crypto_mode_ecb_tdes2.h"
#include "mk_lib_crypto_mode_ecb_tdes3.h"
#include "mk_lib_crypto_mode_ofb_aes_128.h"
#include "mk_lib_crypto_mode_ofb_aes_192.h"
#include "mk_lib_crypto_mode_ofb_aes_256.h"
#include "mk_lib_crypto_mode_ofb_des.h"
#include "mk_lib_crypto_mode_ofb_serpent.h"
#include "mk_lib_crypto_mode_ofb_tdes2.h"
#include "mk_lib_crypto_mode_ofb_tdes3.h"
#include "mk_lib_crypto_padding_iso9797pm2.h"
#include "mk_lib_crypto_padding_pkcs7.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_app_name_code_alg_aes_128 "aes_128"
#define mk_lib_crypto_app_name_code_alg_aes_192 "aes_192"
#define mk_lib_crypto_app_name_code_alg_aes_256 "aes_256"
#define mk_lib_crypto_app_name_code_alg_des     "des"
#define mk_lib_crypto_app_name_code_alg_serpent "serpent"
#define mk_lib_crypto_app_name_code_alg_tdes2   "tdes2"
#define mk_lib_crypto_app_name_code_alg_tdes3   "tdes3"

#define mk_lib_crypto_app_name_code_padding_pkcs7      "pkcs7"
#define mk_lib_crypto_app_name_code_padding_iso9797pm2 "iso9797pm2"

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
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_streebog_256 "pbkdf2_streebog_256"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_streebog_512 "pbkdf2_streebog_512"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_128   "pbkdf2_tiger2_128"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_160   "pbkdf2_tiger2_160"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_192   "pbkdf2_tiger2_192"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_128    "pbkdf2_tiger_128"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_160    "pbkdf2_tiger_160"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_192    "pbkdf2_tiger_192"
#define mk_lib_crypto_app_name_code_kdf_pbkdf2_whirlpool    "pbkdf2_whirlpool"


#define mk_lib_crypto_app_name_pretty_alg_aes_128 "AES-128"
#define mk_lib_crypto_app_name_pretty_alg_aes_192 "AES-192"
#define mk_lib_crypto_app_name_pretty_alg_aes_256 "AES-256"
#define mk_lib_crypto_app_name_pretty_alg_des     "DES"
#define mk_lib_crypto_app_name_pretty_alg_serpent "Serpent"
#define mk_lib_crypto_app_name_pretty_alg_tdes2   "Tripple DES Keying Option 2"
#define mk_lib_crypto_app_name_pretty_alg_tdes3   "Tripple DES Keying Option 1"

#define mk_lib_crypto_app_name_pretty_padding_pkcs7      "PKCS #7"
#define mk_lib_crypto_app_name_pretty_padding_iso9797pm2 "ISO 9797 Padding Method 2"

#define mk_lib_crypto_app_name_pretty_mode_cbc     "CBC"
#define mk_lib_crypto_app_name_pretty_mode_cfb_128 "CFB-128 (or CFB-64)"
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
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_streebog_256 "PBKDF2-Streebog-256"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_streebog_512 "PBKDF2-Streebog-512"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_128   "PBKDF2-Tiger2/128"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_160   "PBKDF2-Tiger2/160"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_192   "PBKDF2-Tiger2/192"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_128    "PBKDF2-Tiger/128"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_160    "PBKDF2-Tiger/160"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_192    "PBKDF2-Tiger/192"
#define mk_lib_crypto_app_name_pretty_kdf_pbkdf2_whirlpool    "PBKDF2-Whirlpool"


#define mk_lib_crypto_app_namelen_code_alg_aes_128 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_alg_aes_128 ) / sizeof(mk_lib_crypto_app_name_code_alg_aes_128 [0]) - 1))
#define mk_lib_crypto_app_namelen_code_alg_aes_192 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_alg_aes_192 ) / sizeof(mk_lib_crypto_app_name_code_alg_aes_192 [0]) - 1))
#define mk_lib_crypto_app_namelen_code_alg_aes_256 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_alg_aes_256 ) / sizeof(mk_lib_crypto_app_name_code_alg_aes_256 [0]) - 1))
#define mk_lib_crypto_app_namelen_code_alg_des     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_alg_des     ) / sizeof(mk_lib_crypto_app_name_code_alg_des     [0]) - 1))
#define mk_lib_crypto_app_namelen_code_alg_serpent ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_alg_serpent ) / sizeof(mk_lib_crypto_app_name_code_alg_serpent [0]) - 1))
#define mk_lib_crypto_app_namelen_code_alg_tdes2   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_alg_tdes2   ) / sizeof(mk_lib_crypto_app_name_code_alg_tdes2   [0]) - 1))
#define mk_lib_crypto_app_namelen_code_alg_tdes3   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_alg_tdes3   ) / sizeof(mk_lib_crypto_app_name_code_alg_tdes3   [0]) - 1))

#define mk_lib_crypto_app_namelen_code_padding_pkcs7      ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_padding_pkcs7      ) / sizeof(mk_lib_crypto_app_name_code_padding_pkcs7      [0]) - 1))
#define mk_lib_crypto_app_namelen_code_padding_iso9797pm2 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_padding_iso9797pm2 ) / sizeof(mk_lib_crypto_app_name_code_padding_iso9797pm2 [0]) - 1))

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
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_streebog_256 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_streebog_256 ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_streebog_256 [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_streebog_512 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_streebog_512 ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_streebog_512 [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_128   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_128   ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_128   [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_160   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_160   ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_160   [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_192   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_192   ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_192   [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_128    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_128    ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_128    [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_160    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_160    ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_160    [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_192    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_192    ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_192    [0]) - 1))
#define mk_lib_crypto_app_namelen_code_kdf_pbkdf2_whirlpool    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_whirlpool    ) / sizeof(mk_lib_crypto_app_name_code_kdf_pbkdf2_whirlpool    [0]) - 1))


#define mk_lib_crypto_app_namelen_pretty_alg_aes_128 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_alg_aes_128 ) / sizeof(mk_lib_crypto_app_name_pretty_alg_aes_128 [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_alg_aes_192 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_alg_aes_192 ) / sizeof(mk_lib_crypto_app_name_pretty_alg_aes_192 [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_alg_aes_256 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_alg_aes_256 ) / sizeof(mk_lib_crypto_app_name_pretty_alg_aes_256 [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_alg_des     ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_alg_des     ) / sizeof(mk_lib_crypto_app_name_pretty_alg_des     [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_alg_serpent ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_alg_serpent ) / sizeof(mk_lib_crypto_app_name_pretty_alg_serpent [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_alg_tdes2   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_alg_tdes2   ) / sizeof(mk_lib_crypto_app_name_pretty_alg_tdes2   [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_alg_tdes3   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_alg_tdes3   ) / sizeof(mk_lib_crypto_app_name_pretty_alg_tdes3   [0]) - 1))

#define mk_lib_crypto_app_namelen_pretty_padding_pkcs7      ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_padding_pkcs7      ) / sizeof(mk_lib_crypto_app_name_pretty_padding_pkcs7      [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_padding_iso9797pm2 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_padding_iso9797pm2 ) / sizeof(mk_lib_crypto_app_name_pretty_padding_iso9797pm2 [0]) - 1))

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
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_streebog_256 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_streebog_256 ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_streebog_256 [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_streebog_512 ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_streebog_512 ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_streebog_512 [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_128   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_128   ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_128   [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_160   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_160   ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_160   [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_192   ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_192   ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_192   [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_128    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_128    ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_128    [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_160    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_160    ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_160    [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_192    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_192    ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_192    [0]) - 1))
#define mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_whirlpool    ((mk_lang_types_uchar_t)(sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_whirlpool    ) / sizeof(mk_lib_crypto_app_name_pretty_kdf_pbkdf2_whirlpool    [0]) - 1))


#define mk_lib_crypto_app_name_code_algs \
	mk_lib_crypto_app_name_code_alg_aes_128 \
	mk_lib_crypto_app_name_code_alg_aes_192 \
	mk_lib_crypto_app_name_code_alg_aes_256 \
	mk_lib_crypto_app_name_code_alg_des     \
	mk_lib_crypto_app_name_code_alg_serpent \
	mk_lib_crypto_app_name_code_alg_tdes2   \
	mk_lib_crypto_app_name_code_alg_tdes3   \
	""

#define mk_lib_crypto_app_name_code_paddings \
	mk_lib_crypto_app_name_code_padding_pkcs7      \
	mk_lib_crypto_app_name_code_padding_iso9797pm2 \
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
	mk_lib_crypto_app_name_code_kdf_pbkdf2_streebog_256 \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_streebog_512 \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_128   \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_160   \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger2_192   \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_128    \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_160    \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_tiger_192    \
	mk_lib_crypto_app_name_code_kdf_pbkdf2_whirlpool    \
	""

#define mk_lib_crypto_app_name_pretty_algs \
	mk_lib_crypto_app_name_pretty_alg_aes_128 \
	mk_lib_crypto_app_name_pretty_alg_aes_192 \
	mk_lib_crypto_app_name_pretty_alg_aes_256 \
	mk_lib_crypto_app_name_pretty_alg_des     \
	mk_lib_crypto_app_name_pretty_alg_serpent \
	mk_lib_crypto_app_name_pretty_alg_tdes2   \
	mk_lib_crypto_app_name_pretty_alg_tdes3   \
	""

#define mk_lib_crypto_app_name_pretty_paddings \
	mk_lib_crypto_app_name_pretty_padding_pkcs7      \
	mk_lib_crypto_app_name_pretty_padding_iso9797pm2 \
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
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_streebog_256 \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_streebog_512 \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_128   \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_160   \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger2_192   \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_128    \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_160    \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_tiger_192    \
	mk_lib_crypto_app_name_pretty_kdf_pbkdf2_whirlpool    \
	""

#define mk_lib_crypto_app_namelen_code_algs \
	mk_lib_crypto_app_namelen_code_alg_aes_128, \
	mk_lib_crypto_app_namelen_code_alg_aes_192, \
	mk_lib_crypto_app_namelen_code_alg_aes_256, \
	mk_lib_crypto_app_namelen_code_alg_des,     \
	mk_lib_crypto_app_namelen_code_alg_serpent, \
	mk_lib_crypto_app_namelen_code_alg_tdes2,   \
	mk_lib_crypto_app_namelen_code_alg_tdes3,   \

#define mk_lib_crypto_app_namelen_code_paddings \
	mk_lib_crypto_app_namelen_code_padding_pkcs7,      \
	mk_lib_crypto_app_namelen_code_padding_iso9797pm2, \

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
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_streebog_256, \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_streebog_512, \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_128,   \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_160,   \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger2_192,   \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_128,    \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_160,    \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_tiger_192,    \
	mk_lib_crypto_app_namelen_code_kdf_pbkdf2_whirlpool,    \

#define mk_lib_crypto_app_namelen_pretty_algs \
	mk_lib_crypto_app_namelen_pretty_alg_aes_128, \
	mk_lib_crypto_app_namelen_pretty_alg_aes_192, \
	mk_lib_crypto_app_namelen_pretty_alg_aes_256, \
	mk_lib_crypto_app_namelen_pretty_alg_des,     \
	mk_lib_crypto_app_namelen_pretty_alg_serpent, \
	mk_lib_crypto_app_namelen_pretty_alg_tdes2,   \
	mk_lib_crypto_app_namelen_pretty_alg_tdes3,   \

#define mk_lib_crypto_app_namelen_pretty_paddings \
	mk_lib_crypto_app_namelen_pretty_padding_pkcs7,      \
	mk_lib_crypto_app_namelen_pretty_padding_iso9797pm2, \

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
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_streebog_256, \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_streebog_512, \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_128,   \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_160,   \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger2_192,   \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_128,    \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_160,    \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_tiger_192,    \
	mk_lib_crypto_app_namelen_pretty_kdf_pbkdf2_whirlpool,    \


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


union mk_lib_crypto_app_aligned_iv_u
{
	mk_lib_crypto_mode_cbc_aes_128_iv_t     m_cbc_aes_128     ;
	mk_lib_crypto_mode_cbc_aes_192_iv_t     m_cbc_aes_192     ;
	mk_lib_crypto_mode_cbc_aes_256_iv_t     m_cbc_aes_256     ;
	mk_lib_crypto_mode_cbc_des_iv_t         m_cbc_des         ;
	mk_lib_crypto_mode_cbc_serpent_iv_t     m_cbc_serpent     ;
	mk_lib_crypto_mode_cbc_tdes2_iv_t       m_cbc_tdes2       ;
	mk_lib_crypto_mode_cbc_tdes3_iv_t       m_cbc_tdes3       ;
	mk_lib_crypto_mode_cfb_128_aes_128_iv_t m_cfb_128_aes_128 ;
	mk_lib_crypto_mode_cfb_128_aes_192_iv_t m_cfb_128_aes_192 ;
	mk_lib_crypto_mode_cfb_128_aes_256_iv_t m_cfb_128_aes_256 ;
	mk_lib_crypto_mode_cfb_128_serpent_iv_t m_cfb_128_serpent ;
	mk_lib_crypto_mode_cfb_64_des_iv_t      m_cfb_64_des      ;
	mk_lib_crypto_mode_cfb_64_tdes2_iv_t    m_cfb_64_tdes2    ;
	mk_lib_crypto_mode_cfb_64_tdes3_iv_t    m_cfb_64_tdes3    ;
	mk_lib_crypto_mode_cfb_8_aes_128_iv_t   m_cfb_8_aes_128   ;
	mk_lib_crypto_mode_cfb_8_aes_192_iv_t   m_cfb_8_aes_192   ;
	mk_lib_crypto_mode_cfb_8_aes_256_iv_t   m_cfb_8_aes_256   ;
	mk_lib_crypto_mode_cfb_8_des_iv_t       m_cfb_8_des       ;
	mk_lib_crypto_mode_cfb_8_serpent_iv_t   m_cfb_8_serpent   ;
	mk_lib_crypto_mode_cfb_8_tdes2_iv_t     m_cfb_8_tdes2     ;
	mk_lib_crypto_mode_cfb_8_tdes3_iv_t     m_cfb_8_tdes3     ;
	mk_lib_crypto_mode_ctr_be_aes_128_iv_t  m_ctr_be_aes_128  ;
	mk_lib_crypto_mode_ctr_be_aes_192_iv_t  m_ctr_be_aes_192  ;
	mk_lib_crypto_mode_ctr_be_aes_256_iv_t  m_ctr_be_aes_256  ;
	mk_lib_crypto_mode_ctr_be_des_iv_t      m_ctr_be_des      ;
	mk_lib_crypto_mode_ctr_be_serpent_iv_t  m_ctr_be_serpent  ;
	mk_lib_crypto_mode_ctr_be_tdes2_iv_t    m_ctr_be_tdes2    ;
	mk_lib_crypto_mode_ctr_be_tdes3_iv_t    m_ctr_be_tdes3    ;
	mk_lib_crypto_mode_ofb_aes_128_iv_t     m_ofb_aes_128     ;
	mk_lib_crypto_mode_ofb_aes_192_iv_t     m_ofb_aes_192     ;
	mk_lib_crypto_mode_ofb_aes_256_iv_t     m_ofb_aes_256     ;
	mk_lib_crypto_mode_ofb_des_iv_t         m_ofb_des         ;
	mk_lib_crypto_mode_ofb_serpent_iv_t     m_ofb_serpent     ;
	mk_lib_crypto_mode_ofb_tdes2_iv_t       m_ofb_tdes2       ;
	mk_lib_crypto_mode_ofb_tdes3_iv_t       m_ofb_tdes3       ;
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union mk_lib_crypto_app_aligned_iv_u mk_lib_crypto_app_aligned_iv_t;

struct mk_lib_crypto_app_iv_s
{
	mk_lib_crypto_app_aligned_iv_t m_data;
};
typedef struct mk_lib_crypto_app_iv_s mk_lib_crypto_app_iv_t;
typedef mk_lib_crypto_app_iv_t const mk_lib_crypto_app_iv_ct;
typedef mk_lib_crypto_app_iv_t* mk_lib_crypto_app_iv_pt;
typedef mk_lib_crypto_app_iv_t const* mk_lib_crypto_app_iv_pct;


mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_order_algs[] =
{
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_alg_id_e_aes_128)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_alg_id_e_aes_192)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_alg_id_e_aes_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_alg_id_e_serpent)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_alg_id_e_des)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_alg_id_e_tdes2)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_alg_id_e_tdes3)),
};

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_order_paddings[] =
{
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_padding_id_e_pkcs7)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_padding_id_e_iso9797pm2)),
};

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_order_modes[] =
{
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_mode_id_e_ecb)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_mode_id_e_cbc)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_mode_id_e_cfb_8)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_mode_id_e_cfb_128)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_mode_id_e_ctr_be)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_mode_id_e_ofb)),
};

mk_lang_constexpr_static_inline mk_lang_types_uchar_t const s_mk_lib_crypto_app_order_kdfs[] =
{
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf1_md2)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf1_md5)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf1_sha1)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_md2)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_md4)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_md5)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha0)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha1)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_224)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_512_224)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_512_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_384)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_512)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha3_224)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha3_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha3_384)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_sha3_512)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger_128)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger_160)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger_192)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger2_128)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger2_160)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger2_192)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2s_128)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2s_160)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2s_224)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2s_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2b_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2b_384)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2b_512)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_blake3)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_whirlpool)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_streebog_256)),
	((mk_lang_types_uchar_t)(mk_lib_crypto_app_kdf_id_e_pbkdf2_streebog_512)),
};

enum mk_lib_crypto_app_mode_alg_id_e
{
	mk_lib_crypto_app_mode_alg_id_e_cbc_aes_128,
	mk_lib_crypto_app_mode_alg_id_e_cbc_aes_192,
	mk_lib_crypto_app_mode_alg_id_e_cbc_aes_256,
	mk_lib_crypto_app_mode_alg_id_e_cbc_des,
	mk_lib_crypto_app_mode_alg_id_e_cbc_serpent,
	mk_lib_crypto_app_mode_alg_id_e_cbc_tdes2,
	mk_lib_crypto_app_mode_alg_id_e_cbc_tdes3,
	mk_lib_crypto_app_mode_alg_id_e_cfb_128_aes_128,
	mk_lib_crypto_app_mode_alg_id_e_cfb_128_aes_192,
	mk_lib_crypto_app_mode_alg_id_e_cfb_128_aes_256,
	mk_lib_crypto_app_mode_alg_id_e_cfb_128_serpent,
	mk_lib_crypto_app_mode_alg_id_e_cfb_64_des,
	mk_lib_crypto_app_mode_alg_id_e_cfb_64_tdes2,
	mk_lib_crypto_app_mode_alg_id_e_cfb_64_tdes3,
	mk_lib_crypto_app_mode_alg_id_e_cfb_8_aes_128,
	mk_lib_crypto_app_mode_alg_id_e_cfb_8_aes_192,
	mk_lib_crypto_app_mode_alg_id_e_cfb_8_aes_256,
	mk_lib_crypto_app_mode_alg_id_e_cfb_8_des,
	mk_lib_crypto_app_mode_alg_id_e_cfb_8_serpent,
	mk_lib_crypto_app_mode_alg_id_e_cfb_8_tdes2,
	mk_lib_crypto_app_mode_alg_id_e_cfb_8_tdes3,
	mk_lib_crypto_app_mode_alg_id_e_ctr_be_aes_128,
	mk_lib_crypto_app_mode_alg_id_e_ctr_be_aes_192,
	mk_lib_crypto_app_mode_alg_id_e_ctr_be_aes_256,
	mk_lib_crypto_app_mode_alg_id_e_ctr_be_des,
	mk_lib_crypto_app_mode_alg_id_e_ctr_be_serpent,
	mk_lib_crypto_app_mode_alg_id_e_ctr_be_tdes2,
	mk_lib_crypto_app_mode_alg_id_e_ctr_be_tdes3,
	mk_lib_crypto_app_mode_alg_id_e_ecb_aes_128,
	mk_lib_crypto_app_mode_alg_id_e_ecb_aes_192,
	mk_lib_crypto_app_mode_alg_id_e_ecb_aes_256,
	mk_lib_crypto_app_mode_alg_id_e_ecb_des,
	mk_lib_crypto_app_mode_alg_id_e_ecb_serpent,
	mk_lib_crypto_app_mode_alg_id_e_ecb_tdes2,
	mk_lib_crypto_app_mode_alg_id_e_ecb_tdes3,
	mk_lib_crypto_app_mode_alg_id_e_ofb_aes_128,
	mk_lib_crypto_app_mode_alg_id_e_ofb_aes_192,
	mk_lib_crypto_app_mode_alg_id_e_ofb_aes_256,
	mk_lib_crypto_app_mode_alg_id_e_ofb_des,
	mk_lib_crypto_app_mode_alg_id_e_ofb_serpent,
	mk_lib_crypto_app_mode_alg_id_e_ofb_tdes2,
	mk_lib_crypto_app_mode_alg_id_e_ofb_tdes3,
	mk_lib_crypto_app_mode_alg_id_e_dummy_end
};
typedef enum mk_lib_crypto_app_mode_alg_id_e mk_lib_crypto_app_mode_alg_id_t;


#define mk_lib_crypto_app_check(x) if(!(x)) return -1; ((void)(0))


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline int mk_lib_crypto_app_get_key_size_max_f(void) mk_lang_noexcept
{
	int s mk_lang_constexpr_init;

	s = 0x00;
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_256_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_des_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_serpent_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_tdes2_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_tdes3_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_256_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_serpent_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_64_des_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_64_tdes2_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_64_tdes3_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_256_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_des_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_serpent_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_tdes2_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_tdes3_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_256_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_des_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_serpent_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_tdes2_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_tdes3_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_aes_256_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_des_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_serpent_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_tdes2_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_tdes3_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_128_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_192_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_256_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_des_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_serpent_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_tdes2_key_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_tdes3_key_len_v);
	mk_lang_assert(s == mk_lib_crypto_app_get_key_size_max_m);
	return s;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline int mk_lib_crypto_app_get_msg_size_max_f(void) mk_lang_noexcept
{
	int s mk_lang_constexpr_init;

	s = 0x00;
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_256_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_des_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_serpent_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_tdes2_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_tdes3_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_serpent_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_64_des_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_des_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_serpent_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_des_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_serpent_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_aes_256_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_des_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_serpent_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_tdes2_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_tdes3_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_128_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_192_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_256_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_des_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_serpent_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_tdes2_msg_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_tdes3_msg_len_v);
	mk_lang_assert(s == mk_lib_crypto_app_get_msg_size_max_m);
	return s;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline int mk_lib_crypto_app_get_iv_size_max_f(void) mk_lang_noexcept
{
	int s mk_lang_constexpr_init;

	s = 0x00;
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_128_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_192_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_aes_256_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_des_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_serpent_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_tdes2_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cbc_tdes3_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_128_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_192_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_aes_256_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_128_serpent_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_64_des_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_64_tdes2_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_64_tdes3_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_128_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_192_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_aes_256_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_des_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_serpent_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_tdes2_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_cfb_8_tdes3_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_128_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_192_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_aes_256_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_des_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_serpent_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_tdes2_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ctr_be_tdes3_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_aes_128_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_aes_192_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_aes_256_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_des_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_serpent_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_tdes2_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ecb_tdes3_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_128_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_192_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_aes_256_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_des_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_serpent_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_tdes2_iv_len_v);
	s = mk_lang_max(s, mk_lib_crypto_mode_ofb_tdes3_iv_len_v);
	mk_lang_assert(s == mk_lib_crypto_app_get_iv_size_max_m);
	return s;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pt mk_lib_crypto_app_impl_get_data_addr(mk_lib_crypto_app_pt const app) mk_lang_noexcept
{
	mk_lang_assert(app);

	return &app->m_buffer.m_data.m_uint8s[0];
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_lib_crypto_app_impl_get_data_size(mk_lib_crypto_app_pt const app) mk_lang_noexcept
{
	mk_lang_assert(app);
	mk_lang_assert(mk_lib_crypto_app_get_msg_size_max_m == mk_lib_crypto_app_get_msg_size_max_f());

	return ((mk_lang_types_usize_t)(sizeof(app->m_buffer.m_data.m_uint8s) / sizeof(app->m_buffer.m_data.m_uint8s[0]) - mk_lib_crypto_app_get_msg_size_max_m));
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

	mk_lang_static_assert(s_mk_lib_crypto_app_namelen_code_algs_len     == s_mk_lib_crypto_app_namelen_pretty_algs_len     );
	mk_lang_static_assert(s_mk_lib_crypto_app_namelen_code_paddings_len == s_mk_lib_crypto_app_namelen_pretty_paddings_len );
	mk_lang_static_assert(s_mk_lib_crypto_app_namelen_code_modes_len    == s_mk_lib_crypto_app_namelen_pretty_modes_len    );
	mk_lang_static_assert(s_mk_lib_crypto_app_namelen_code_kdfs_len     == s_mk_lib_crypto_app_namelen_pretty_kdfs_len     );

	p = ptr;
	p = mk_lib_crypto_app_get_names_impl_one(p, s_mk_lib_crypto_app_namelen_code_algs_len     , s_mk_lib_crypto_app_order_algs     , s_mk_lib_crypto_app_namelen_code_algs     , s_mk_lib_crypto_app_name_code_algs     , s_mk_lib_crypto_app_namelen_pretty_algs     , s_mk_lib_crypto_app_name_pretty_algs     );
	p = mk_lib_crypto_app_get_names_impl_one(p, s_mk_lib_crypto_app_namelen_code_paddings_len , s_mk_lib_crypto_app_order_paddings , s_mk_lib_crypto_app_namelen_code_paddings , s_mk_lib_crypto_app_name_code_paddings , s_mk_lib_crypto_app_namelen_pretty_paddings , s_mk_lib_crypto_app_name_pretty_paddings );
	p = mk_lib_crypto_app_get_names_impl_one(p, s_mk_lib_crypto_app_namelen_code_modes_len    , s_mk_lib_crypto_app_order_modes    , s_mk_lib_crypto_app_namelen_code_modes    , s_mk_lib_crypto_app_name_code_modes    , s_mk_lib_crypto_app_namelen_pretty_modes    , s_mk_lib_crypto_app_name_pretty_modes    );
	p = mk_lib_crypto_app_get_names_impl_one(p, s_mk_lib_crypto_app_namelen_code_kdfs_len     , s_mk_lib_crypto_app_order_kdfs     , s_mk_lib_crypto_app_namelen_code_kdfs     , s_mk_lib_crypto_app_name_code_kdfs     , s_mk_lib_crypto_app_namelen_pretty_kdfs     , s_mk_lib_crypto_app_name_pretty_kdfs     );
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

mk_lang_constexpr_static_inline auto const s_mk_lib_crypto_app_get_names_str = mk_lib_crypto_app_get_names_impl_2();

#endif

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_impl_get_names(mk_lib_crypto_app_pt const app) mk_lang_noexcept
{
	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	int i mk_lang_constexpr_init;

	mk_lang_assert(app);

	for(i = 0; i != s_mk_lib_crypto_app_get_names_str.s_size; ++i){ app->m_buffer.m_data.m_uint8s[i] = s_mk_lib_crypto_app_get_names_str.m_data[i]; }
	return s_mk_lib_crypto_app_get_names_str.s_size;

	#else

	mk_lang_assert(app);

	return mk_lib_crypto_app_get_names_impl_4(&app->m_buffer.m_data.m_uint8s[0]);

	#endif
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

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_alg_id(mk_sl_cui_uint8_pct const ptr, mk_lib_crypto_app_alg_id_pt const alg_id) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(alg_id);

	p = ptr;
	p = mk_lib_crypto_app_init_any_id(p, &uc, s_mk_lib_crypto_app_namelen_code_algs_len, s_mk_lib_crypto_app_namelen_code_algs, s_mk_lib_crypto_app_name_code_algs); if(!p) return mk_lang_null;
	mk_lang_assert(uc >= 0 && uc < mk_lib_crypto_app_alg_id_e_dummy_end);
	*alg_id = ((mk_lib_crypto_app_alg_id_t)(uc));
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_padding_id(mk_sl_cui_uint8_pct const ptr, mk_lib_crypto_app_padding_id_pt const padding_id) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(padding_id);

	p = ptr;
	p = mk_lib_crypto_app_init_any_id(p, &uc, s_mk_lib_crypto_app_namelen_code_paddings_len, s_mk_lib_crypto_app_namelen_code_paddings, s_mk_lib_crypto_app_name_code_paddings); if(!p) return mk_lang_null;
	mk_lang_assert(uc >= 0 && uc < mk_lib_crypto_app_padding_id_e_dummy_end);
	*padding_id = ((mk_lib_crypto_app_padding_id_t)(uc));
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_mode_id(mk_sl_cui_uint8_pct const ptr, mk_lib_crypto_app_mode_id_pt const mode_id) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(mode_id);

	p = ptr;
	p = mk_lib_crypto_app_init_any_id(p, &uc, s_mk_lib_crypto_app_namelen_code_modes_len, s_mk_lib_crypto_app_namelen_code_modes, s_mk_lib_crypto_app_name_code_modes); if(!p) return mk_lang_null;
	mk_lang_assert(uc >= 0 && uc < mk_lib_crypto_app_mode_id_e_dummy_end);
	*mode_id = ((mk_lib_crypto_app_mode_id_t)(uc));
	return p;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_kdf_id(mk_sl_cui_uint8_pct const ptr, mk_lib_crypto_app_kdf_id_pt const kdf_id) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(kdf_id);

	p = ptr;
	p = mk_lib_crypto_app_init_any_id(p, &uc, s_mk_lib_crypto_app_namelen_code_kdfs_len, s_mk_lib_crypto_app_namelen_code_kdfs, s_mk_lib_crypto_app_name_code_kdfs); if(!p) return mk_lang_null;
	mk_lang_assert(uc >= 0 && uc < mk_lib_crypto_app_kdf_id_e_dummy_end);
	*kdf_id = ((mk_lib_crypto_app_kdf_id_t)(uc));
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

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_cui_uint8_pct mk_lib_crypto_app_init_iv(mk_sl_cui_uint8_pct const ptr, mk_lib_crypto_app_alg_id_t const alg_id, mk_lib_crypto_app_mode_id_t const mode_id, mk_lib_crypto_app_iv_pt const iv) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct p mk_lang_constexpr_init;
	int id mk_lang_constexpr_init;

	mk_lang_assert(ptr);
	mk_lang_assert(iv);

	p = ptr;
	if(mode_id != mk_lib_crypto_app_mode_id_e_ecb)
	{
		id = ((int)(((int)(mode_id)) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(alg_id))));
		switch(id)
		{
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cbc    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_128)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cbc_aes_128_iv_len_v    , &iv->m_data.m_cbc_aes_128    .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cbc    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_192)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cbc_aes_192_iv_len_v    , &iv->m_data.m_cbc_aes_192    .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cbc    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_256)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cbc_aes_256_iv_len_v    , &iv->m_data.m_cbc_aes_256    .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cbc    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_des    )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cbc_des_iv_len_v        , &iv->m_data.m_cbc_des        .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cbc    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_serpent)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cbc_serpent_iv_len_v    , &iv->m_data.m_cbc_serpent    .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cbc    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_tdes2  )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cbc_tdes2_iv_len_v      , &iv->m_data.m_cbc_tdes2      .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cbc    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_tdes3  )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cbc_tdes3_iv_len_v      , &iv->m_data.m_cbc_tdes3      .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_128)) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_128)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_128_aes_128_iv_len_v, &iv->m_data.m_cfb_128_aes_128.m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_128)) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_192)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_128_aes_192_iv_len_v, &iv->m_data.m_cfb_128_aes_192.m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_128)) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_256)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_128_aes_256_iv_len_v, &iv->m_data.m_cfb_128_aes_256.m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_128)) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_des    )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_64_des_iv_len_v     , &iv->m_data.m_cfb_64_des     .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_128)) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_serpent)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_128_serpent_iv_len_v, &iv->m_data.m_cfb_128_serpent.m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_128)) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_tdes2  )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_64_tdes2_iv_len_v   , &iv->m_data.m_cfb_64_tdes2   .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_128)) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_tdes3  )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_64_tdes3_iv_len_v   , &iv->m_data.m_cfb_64_tdes3   .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_128)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_8_aes_128_iv_len_v  , &iv->m_data.m_cfb_8_aes_128  .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_192)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_8_aes_192_iv_len_v  , &iv->m_data.m_cfb_8_aes_192  .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_256)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_8_aes_256_iv_len_v  , &iv->m_data.m_cfb_8_aes_256  .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_des    )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_8_des_iv_len_v      , &iv->m_data.m_cfb_8_des      .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_serpent)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_8_serpent_iv_len_v  , &iv->m_data.m_cfb_8_serpent  .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_tdes2  )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_8_tdes2_iv_len_v    , &iv->m_data.m_cfb_8_tdes2    .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_tdes3  )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_cfb_8_tdes3_iv_len_v    , &iv->m_data.m_cfb_8_tdes3    .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ctr_be )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_128)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ctr_be_aes_128_iv_len_v , &iv->m_data.m_ctr_be_aes_128 .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ctr_be )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_192)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ctr_be_aes_192_iv_len_v , &iv->m_data.m_ctr_be_aes_192 .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ctr_be )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_256)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ctr_be_aes_256_iv_len_v , &iv->m_data.m_ctr_be_aes_256 .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ctr_be )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_des    )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ctr_be_des_iv_len_v     , &iv->m_data.m_ctr_be_des     .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ctr_be )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_serpent)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ctr_be_serpent_iv_len_v , &iv->m_data.m_ctr_be_serpent .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ctr_be )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_tdes2  )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ctr_be_tdes2_iv_len_v   , &iv->m_data.m_ctr_be_tdes2   .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ctr_be )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_tdes3  )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ctr_be_tdes3_iv_len_v   , &iv->m_data.m_ctr_be_tdes3   .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ofb    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_128)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ofb_aes_128_iv_len_v    , &iv->m_data.m_ofb_aes_128    .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ofb    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_192)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ofb_aes_192_iv_len_v    , &iv->m_data.m_ofb_aes_192    .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ofb    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_aes_256)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ofb_aes_256_iv_len_v    , &iv->m_data.m_ofb_aes_256    .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ofb    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_des    )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ofb_des_iv_len_v        , &iv->m_data.m_ofb_des        .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ofb    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_serpent)))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ofb_serpent_iv_len_v    , &iv->m_data.m_ofb_serpent    .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ofb    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_tdes2  )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ofb_tdes2_iv_len_v      , &iv->m_data.m_ofb_tdes2      .m_data.m_uint8s[0]))); break;
			case ((int)(((int)(mk_lib_crypto_app_mode_id_e_ofb    )) * ((int)(mk_lib_crypto_app_alg_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_alg_id_e_tdes3  )))): ((void)(mk_lib_crypto_app_init_buff(p, mk_lib_crypto_mode_ofb_tdes3_iv_len_v      , &iv->m_data.m_ofb_tdes3      .m_data.m_uint8s[0]))); break;
			default: mk_lang_assert(0); break;
		}
	}
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

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_impl_init(mk_lib_crypto_app_pt const app) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lib_crypto_app_alg_id_t alg_id mk_lang_constexpr_init;
	mk_lib_crypto_app_padding_id_t padding_id mk_lang_constexpr_init;
	mk_lib_crypto_app_mode_id_t mode_id mk_lang_constexpr_init;
	mk_lib_crypto_app_kdf_id_t kdf_id mk_lang_constexpr_init;
	mk_lib_crypto_app_iv_t iv mk_lang_constexpr_init;
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

	mk_lang_assert(app);
	mk_lang_assert(mk_lib_crypto_app_get_key_size_max_m == mk_lib_crypto_app_get_key_size_max_f());

	ptr = &app->m_buffer.m_data.m_uint8s[0];
	ptr = mk_lib_crypto_app_init_alg_id    (ptr, &alg_id             ); mk_lib_crypto_app_check(ptr);
	ptr = mk_lib_crypto_app_init_padding_id(ptr, &padding_id         ); mk_lib_crypto_app_check(ptr);
	ptr = mk_lib_crypto_app_init_mode_id   (ptr, &mode_id            ); mk_lib_crypto_app_check(ptr);
	ptr = mk_lib_crypto_app_init_kdf_id    (ptr, &kdf_id             ); mk_lib_crypto_app_check(ptr);
	ptr = mk_lib_crypto_app_init_iv        (ptr, alg_id, mode_id, &iv); mk_lib_crypto_app_check(ptr);
	ptr = mk_lib_crypto_app_init_num       (ptr, &cost               ); mk_lib_crypto_app_check(ptr);
	ptr = mk_lib_crypto_app_init_str       (ptr, &pwd_len, &pwd_buf  ); mk_lib_crypto_app_check(ptr);
	ptr = mk_lib_crypto_app_init_str       (ptr, &slt_len, &slt_buf  ); mk_lib_crypto_app_check(ptr);
	app->m_alg_id = alg_id;
	app->m_padding_id = padding_id;
	app->m_mode_id = mode_id;
	app->m_expanded = 0;
	mk_sl_cui_uint32_to_bi_ulong(&cost, &cost_ul);
	for(i = 0; i != mk_lang_min(8, slt_len); ++i){ slt8[i] = slt_buf[i]; }
	for(i = mk_lang_min(8, slt_len); i != 8; ++i){ mk_sl_cui_uint8_set_zero(&slt8[i]); }
	if(0){}
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_ecb     ){ iv_len = mk_lib_crypto_mode_ecb_aes_128_iv_len_v; }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_ecb     ){ iv_len = mk_lib_crypto_mode_ecb_aes_192_iv_len_v; }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_ecb     ){ iv_len = mk_lib_crypto_mode_ecb_aes_256_iv_len_v; }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_ecb     ){ iv_len = mk_lib_crypto_mode_ecb_des_iv_len_v    ; }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_ecb     ){ iv_len = mk_lib_crypto_mode_ecb_tdes2_iv_len_v  ; }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_ecb     ){ iv_len = mk_lib_crypto_mode_ecb_tdes3_iv_len_v  ; }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_ecb     ){ iv_len = mk_lib_crypto_mode_ecb_serpent_iv_len_v; }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_cbc     ){ iv_len = mk_lib_crypto_mode_cbc_aes_128_iv_len_v     ; mk_lib_crypto_mode_cbc_aes_128_init    (&app->m_mode.m_data.m_cbc_aes_128    , &iv.m_data.m_cbc_aes_128    ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128 ){ iv_len = mk_lib_crypto_mode_cfb_128_aes_128_iv_len_v ; mk_lib_crypto_mode_cfb_128_aes_128_init(&app->m_mode.m_data.m_cfb_128_aes_128, &iv.m_data.m_cfb_128_aes_128); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8   ){ iv_len = mk_lib_crypto_mode_cfb_8_aes_128_iv_len_v   ; mk_lib_crypto_mode_cfb_8_aes_128_init  (&app->m_mode.m_data.m_cfb_8_aes_128  , &iv.m_data.m_cfb_8_aes_128  ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be  ){ iv_len = mk_lib_crypto_mode_ctr_be_aes_128_iv_len_v  ; mk_lib_crypto_mode_ctr_be_aes_128_init (&app->m_mode.m_data.m_ctr_be_aes_128 , &iv.m_data.m_ctr_be_aes_128 ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_ofb     ){ iv_len = mk_lib_crypto_mode_ofb_aes_128_iv_len_v     ; mk_lib_crypto_mode_ofb_aes_128_init    (&app->m_mode.m_data.m_ofb_aes_128    , &iv.m_data.m_ofb_aes_128    ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_cbc     ){ iv_len = mk_lib_crypto_mode_cbc_aes_192_iv_len_v     ; mk_lib_crypto_mode_cbc_aes_192_init    (&app->m_mode.m_data.m_cbc_aes_192    , &iv.m_data.m_cbc_aes_192    ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128 ){ iv_len = mk_lib_crypto_mode_cfb_128_aes_192_iv_len_v ; mk_lib_crypto_mode_cfb_128_aes_192_init(&app->m_mode.m_data.m_cfb_128_aes_192, &iv.m_data.m_cfb_128_aes_192); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8   ){ iv_len = mk_lib_crypto_mode_cfb_8_aes_192_iv_len_v   ; mk_lib_crypto_mode_cfb_8_aes_192_init  (&app->m_mode.m_data.m_cfb_8_aes_192  , &iv.m_data.m_cfb_8_aes_192  ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be  ){ iv_len = mk_lib_crypto_mode_ctr_be_aes_192_iv_len_v  ; mk_lib_crypto_mode_ctr_be_aes_192_init (&app->m_mode.m_data.m_ctr_be_aes_192 , &iv.m_data.m_ctr_be_aes_192 ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_ofb     ){ iv_len = mk_lib_crypto_mode_ofb_aes_192_iv_len_v     ; mk_lib_crypto_mode_ofb_aes_192_init    (&app->m_mode.m_data.m_ofb_aes_192    , &iv.m_data.m_ofb_aes_192    ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_cbc     ){ iv_len = mk_lib_crypto_mode_cbc_aes_256_iv_len_v     ; mk_lib_crypto_mode_cbc_aes_256_init    (&app->m_mode.m_data.m_cbc_aes_256    , &iv.m_data.m_cbc_aes_256    ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128 ){ iv_len = mk_lib_crypto_mode_cfb_128_aes_256_iv_len_v ; mk_lib_crypto_mode_cfb_128_aes_256_init(&app->m_mode.m_data.m_cfb_128_aes_256, &iv.m_data.m_cfb_128_aes_256); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8   ){ iv_len = mk_lib_crypto_mode_cfb_8_aes_256_iv_len_v   ; mk_lib_crypto_mode_cfb_8_aes_256_init  (&app->m_mode.m_data.m_cfb_8_aes_256  , &iv.m_data.m_cfb_8_aes_256  ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be  ){ iv_len = mk_lib_crypto_mode_ctr_be_aes_256_iv_len_v  ; mk_lib_crypto_mode_ctr_be_aes_256_init (&app->m_mode.m_data.m_ctr_be_aes_256 , &iv.m_data.m_ctr_be_aes_256 ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_ofb     ){ iv_len = mk_lib_crypto_mode_ofb_aes_256_iv_len_v     ; mk_lib_crypto_mode_ofb_aes_256_init    (&app->m_mode.m_data.m_ofb_aes_256    , &iv.m_data.m_ofb_aes_256    ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_cbc     ){ iv_len = mk_lib_crypto_mode_cbc_des_iv_len_v         ; mk_lib_crypto_mode_cbc_des_init        (&app->m_mode.m_data.m_cbc_des        , &iv.m_data.m_cbc_des        ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128 ){ iv_len = mk_lib_crypto_mode_cfb_64_des_iv_len_v      ; mk_lib_crypto_mode_cfb_64_des_init     (&app->m_mode.m_data.m_cfb_64_des     , &iv.m_data.m_cfb_64_des     ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8   ){ iv_len = mk_lib_crypto_mode_cfb_8_des_iv_len_v       ; mk_lib_crypto_mode_cfb_8_des_init      (&app->m_mode.m_data.m_cfb_8_des      , &iv.m_data.m_cfb_8_des      ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be  ){ iv_len = mk_lib_crypto_mode_ctr_be_des_iv_len_v      ; mk_lib_crypto_mode_ctr_be_des_init     (&app->m_mode.m_data.m_ctr_be_des     , &iv.m_data.m_ctr_be_des     ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_ofb     ){ iv_len = mk_lib_crypto_mode_ofb_des_iv_len_v         ; mk_lib_crypto_mode_ofb_des_init        (&app->m_mode.m_data.m_ofb_des        , &iv.m_data.m_ofb_des        ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_cbc     ){ iv_len = mk_lib_crypto_mode_cbc_serpent_iv_len_v     ; mk_lib_crypto_mode_cbc_serpent_init    (&app->m_mode.m_data.m_cbc_serpent    , &iv.m_data.m_cbc_serpent    ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128 ){ iv_len = mk_lib_crypto_mode_cfb_128_serpent_iv_len_v ; mk_lib_crypto_mode_cfb_128_serpent_init(&app->m_mode.m_data.m_cfb_128_serpent, &iv.m_data.m_cfb_128_serpent); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8   ){ iv_len = mk_lib_crypto_mode_cfb_8_serpent_iv_len_v   ; mk_lib_crypto_mode_cfb_8_serpent_init  (&app->m_mode.m_data.m_cfb_8_serpent  , &iv.m_data.m_cfb_8_serpent  ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be  ){ iv_len = mk_lib_crypto_mode_ctr_be_serpent_iv_len_v  ; mk_lib_crypto_mode_ctr_be_serpent_init (&app->m_mode.m_data.m_ctr_be_serpent , &iv.m_data.m_ctr_be_serpent ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_ofb     ){ iv_len = mk_lib_crypto_mode_ofb_serpent_iv_len_v     ; mk_lib_crypto_mode_ofb_serpent_init    (&app->m_mode.m_data.m_ofb_serpent    , &iv.m_data.m_ofb_serpent    ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_cbc     ){ iv_len = mk_lib_crypto_mode_cbc_tdes2_iv_len_v       ; mk_lib_crypto_mode_cbc_tdes2_init      (&app->m_mode.m_data.m_cbc_tdes2      , &iv.m_data.m_cbc_tdes2      ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128 ){ iv_len = mk_lib_crypto_mode_cfb_64_tdes2_iv_len_v    ; mk_lib_crypto_mode_cfb_64_tdes2_init   (&app->m_mode.m_data.m_cfb_64_tdes2   , &iv.m_data.m_cfb_64_tdes2   ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8   ){ iv_len = mk_lib_crypto_mode_cfb_8_tdes2_iv_len_v     ; mk_lib_crypto_mode_cfb_8_tdes2_init    (&app->m_mode.m_data.m_cfb_8_tdes2    , &iv.m_data.m_cfb_8_tdes2    ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be  ){ iv_len = mk_lib_crypto_mode_ctr_be_tdes2_iv_len_v    ; mk_lib_crypto_mode_ctr_be_tdes2_init   (&app->m_mode.m_data.m_ctr_be_tdes2   , &iv.m_data.m_ctr_be_tdes2   ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_ofb     ){ iv_len = mk_lib_crypto_mode_ofb_tdes2_iv_len_v       ; mk_lib_crypto_mode_ofb_tdes2_init      (&app->m_mode.m_data.m_ofb_tdes2      , &iv.m_data.m_ofb_tdes2      ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_cbc     ){ iv_len = mk_lib_crypto_mode_cbc_tdes3_iv_len_v       ; mk_lib_crypto_mode_cbc_tdes3_init      (&app->m_mode.m_data.m_cbc_tdes3      , &iv.m_data.m_cbc_tdes3      ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128 ){ iv_len = mk_lib_crypto_mode_cfb_64_tdes3_iv_len_v    ; mk_lib_crypto_mode_cfb_64_tdes3_init   (&app->m_mode.m_data.m_cfb_64_tdes3   , &iv.m_data.m_cfb_64_tdes3   ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8   ){ iv_len = mk_lib_crypto_mode_cfb_8_tdes3_iv_len_v     ; mk_lib_crypto_mode_cfb_8_tdes3_init    (&app->m_mode.m_data.m_cfb_8_tdes3    , &iv.m_data.m_cfb_8_tdes3    ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be  ){ iv_len = mk_lib_crypto_mode_ctr_be_tdes3_iv_len_v    ; mk_lib_crypto_mode_ctr_be_tdes3_init   (&app->m_mode.m_data.m_ctr_be_tdes3   , &iv.m_data.m_ctr_be_tdes3   ); }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_ofb     ){ iv_len = mk_lib_crypto_mode_ofb_tdes3_iv_len_v       ; mk_lib_crypto_mode_ofb_tdes3_init      (&app->m_mode.m_data.m_ofb_tdes3      , &iv.m_data.m_ofb_tdes3      ); }
	else{ mk_lang_assert(0); }
	switch(alg_id)
	{
		case mk_lib_crypto_app_alg_id_e_aes_128: key_len = mk_lib_crypto_alg_aes_128_key_len_v; break;
		case mk_lib_crypto_app_alg_id_e_aes_192: key_len = mk_lib_crypto_alg_aes_192_key_len_v; break;
		case mk_lib_crypto_app_alg_id_e_aes_256: key_len = mk_lib_crypto_alg_aes_256_key_len_v; break;
		case mk_lib_crypto_app_alg_id_e_des    : key_len = mk_lib_crypto_alg_des_key_len_v    ; break;
		case mk_lib_crypto_app_alg_id_e_serpent: key_len = mk_lib_crypto_alg_serpent_key_len_v; break;
		case mk_lib_crypto_app_alg_id_e_tdes2  : key_len = mk_lib_crypto_alg_tdes2_key_len_v  ; break;
		case mk_lib_crypto_app_alg_id_e_tdes3  : key_len = mk_lib_crypto_alg_tdes3_key_len_v  ; break;
		default: mk_lang_assert(0); break;
	}
	if(0){}
	else if(kdf_id == mk_lib_crypto_app_kdf_id_e_pbkdf1_md2  ){ mk_lib_crypto_app_check(key_len <= mk_lib_crypto_hash_block_md2_digest_len  ); }
	else if(kdf_id == mk_lib_crypto_app_kdf_id_e_pbkdf1_md5  ){ mk_lib_crypto_app_check(key_len <= mk_lib_crypto_hash_block_md5_digest_len  ); }
	else if(kdf_id == mk_lib_crypto_app_kdf_id_e_pbkdf1_sha1 ){ mk_lib_crypto_app_check(key_len <= mk_lib_crypto_hash_block_sha1_digest_len ); }
	switch(kdf_id)
	{
		case mk_lib_crypto_app_kdf_id_e_pbkdf1_md2         : mk_lib_crypto_kdf_pbkdf1_md2_u8  (pwd_buf, pwd_len, slt8, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf1_md5         : mk_lib_crypto_kdf_pbkdf1_md5_u8  (pwd_buf, pwd_len, slt8, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf1_sha1        : mk_lib_crypto_kdf_pbkdf1_sha1_u8 (pwd_buf, pwd_len, slt8, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2b_256 : mk_lib_crypto_kdf_pbkdf2_blake2b_256_u8  (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2b_384 : mk_lib_crypto_kdf_pbkdf2_blake2b_384_u8  (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2b_512 : mk_lib_crypto_kdf_pbkdf2_blake2b_512_u8  (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2s_128 : mk_lib_crypto_kdf_pbkdf2_blake2s_128_u8  (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2s_160 : mk_lib_crypto_kdf_pbkdf2_blake2s_160_u8  (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2s_224 : mk_lib_crypto_kdf_pbkdf2_blake2s_224_u8  (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_blake2s_256 : mk_lib_crypto_kdf_pbkdf2_blake2s_256_u8  (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_blake3      : mk_lib_crypto_kdf_pbkdf2_blake3_u8       (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_md2         : mk_lib_crypto_kdf_pbkdf2_md2_u8          (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_md4         : mk_lib_crypto_kdf_pbkdf2_md4_u8          (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_md5         : mk_lib_crypto_kdf_pbkdf2_md5_u8          (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha0        : mk_lib_crypto_kdf_pbkdf2_sha0_u8         (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha1        : mk_lib_crypto_kdf_pbkdf2_sha1_u8         (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_224    : mk_lib_crypto_kdf_pbkdf2_sha2_224_u8     (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_256    : mk_lib_crypto_kdf_pbkdf2_sha2_256_u8     (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_384    : mk_lib_crypto_kdf_pbkdf2_sha2_384_u8     (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_512    : mk_lib_crypto_kdf_pbkdf2_sha2_512_u8     (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_512_224: mk_lib_crypto_kdf_pbkdf2_sha2_512_224_u8 (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha2_512_256: mk_lib_crypto_kdf_pbkdf2_sha2_512_256_u8 (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha3_224    : mk_lib_crypto_kdf_pbkdf2_sha3_224_u8     (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha3_256    : mk_lib_crypto_kdf_pbkdf2_sha3_256_u8     (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha3_384    : mk_lib_crypto_kdf_pbkdf2_sha3_384_u8     (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_sha3_512    : mk_lib_crypto_kdf_pbkdf2_sha3_512_u8     (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_streebog_256: mk_lib_crypto_kdf_pbkdf2_streebog_256_u8 (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_streebog_512: mk_lib_crypto_kdf_pbkdf2_streebog_512_u8 (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger2_128  : mk_lib_crypto_kdf_pbkdf2_tiger2_128_u8   (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger2_160  : mk_lib_crypto_kdf_pbkdf2_tiger2_160_u8   (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger2_192  : mk_lib_crypto_kdf_pbkdf2_tiger2_192_u8   (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger_128   : mk_lib_crypto_kdf_pbkdf2_tiger_128_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger_160   : mk_lib_crypto_kdf_pbkdf2_tiger_160_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_tiger_192   : mk_lib_crypto_kdf_pbkdf2_tiger_192_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		case mk_lib_crypto_app_kdf_id_e_pbkdf2_whirlpool   : mk_lib_crypto_kdf_pbkdf2_whirlpool_u8    (pwd_buf, pwd_len, slt_buf, slt_len, cost_ul, key_len, &key_data[0]); break;
		default: mk_lang_assert(0); break;
	}
	if(0){}
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_cbc    ){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_key_len_v    ; ++i){ app->m_key.m_data.m_cbc_aes_128    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_key_len_v; ++i){ app->m_key.m_data.m_cfb_128_aes_128.m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8  ){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_key_len_v  ; ++i){ app->m_key.m_data.m_cfb_8_aes_128  .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be ){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_key_len_v ; ++i){ app->m_key.m_data.m_ctr_be_aes_128 .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_ecb    ){ for(i = 0; i != mk_lib_crypto_alg_aes_128_key_len_v         ; ++i){ app->m_key.m_data.m_ecb_aes_128    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_128 && mode_id == mk_lib_crypto_app_mode_id_e_ofb    ){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_key_len_v    ; ++i){ app->m_key.m_data.m_ofb_aes_128    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_cbc    ){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_key_len_v    ; ++i){ app->m_key.m_data.m_cbc_aes_192    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_key_len_v; ++i){ app->m_key.m_data.m_cfb_128_aes_192.m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8  ){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_key_len_v  ; ++i){ app->m_key.m_data.m_cfb_8_aes_192  .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be ){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_key_len_v ; ++i){ app->m_key.m_data.m_ctr_be_aes_192 .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_ecb    ){ for(i = 0; i != mk_lib_crypto_alg_aes_192_key_len_v         ; ++i){ app->m_key.m_data.m_ecb_aes_192    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_192 && mode_id == mk_lib_crypto_app_mode_id_e_ofb    ){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_key_len_v    ; ++i){ app->m_key.m_data.m_ofb_aes_192    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_cbc    ){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_key_len_v    ; ++i){ app->m_key.m_data.m_cbc_aes_256    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_key_len_v; ++i){ app->m_key.m_data.m_cfb_128_aes_256.m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8  ){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_key_len_v  ; ++i){ app->m_key.m_data.m_cfb_8_aes_256  .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be ){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_key_len_v ; ++i){ app->m_key.m_data.m_ctr_be_aes_256 .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_ecb    ){ for(i = 0; i != mk_lib_crypto_alg_aes_256_key_len_v         ; ++i){ app->m_key.m_data.m_cbc_aes_256    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_aes_256 && mode_id == mk_lib_crypto_app_mode_id_e_ofb    ){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_key_len_v    ; ++i){ app->m_key.m_data.m_ofb_aes_256    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_cbc    ){ for(i = 0; i != mk_lib_crypto_mode_cbc_des_key_len_v        ; ++i){ app->m_key.m_data.m_cbc_des        .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_des_key_len_v     ; ++i){ app->m_key.m_data.m_cfb_64_des     .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8  ){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_des_key_len_v      ; ++i){ app->m_key.m_data.m_cfb_8_des      .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be ){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_des_key_len_v     ; ++i){ app->m_key.m_data.m_ctr_be_des     .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_ecb    ){ for(i = 0; i != mk_lib_crypto_alg_des_key_len_v             ; ++i){ app->m_key.m_data.m_cbc_des        .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_des     && mode_id == mk_lib_crypto_app_mode_id_e_ofb    ){ for(i = 0; i != mk_lib_crypto_mode_ofb_des_key_len_v        ; ++i){ app->m_key.m_data.m_ofb_des        .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_cbc    ){ for(i = 0; i != mk_lib_crypto_mode_cbc_serpent_key_len_v    ; ++i){ app->m_key.m_data.m_cbc_serpent    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_serpent_key_len_v; ++i){ app->m_key.m_data.m_cfb_128_serpent.m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8  ){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_serpent_key_len_v  ; ++i){ app->m_key.m_data.m_cfb_8_serpent  .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be ){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_serpent_key_len_v ; ++i){ app->m_key.m_data.m_ctr_be_serpent .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_ecb    ){ for(i = 0; i != mk_lib_crypto_alg_serpent_key_len_v         ; ++i){ app->m_key.m_data.m_cbc_serpent    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_serpent && mode_id == mk_lib_crypto_app_mode_id_e_ofb    ){ for(i = 0; i != mk_lib_crypto_mode_ofb_serpent_key_len_v    ; ++i){ app->m_key.m_data.m_ofb_serpent    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_cbc    ){ for(i = 0; i != mk_lib_crypto_mode_cbc_tdes2_key_len_v      ; ++i){ app->m_key.m_data.m_cbc_tdes2      .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes2_key_len_v   ; ++i){ app->m_key.m_data.m_cfb_64_tdes2   .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8  ){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes2_key_len_v    ; ++i){ app->m_key.m_data.m_cfb_8_tdes2    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be ){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes2_key_len_v   ; ++i){ app->m_key.m_data.m_ctr_be_tdes2   .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_ecb    ){ for(i = 0; i != mk_lib_crypto_alg_tdes2_key_len_v           ; ++i){ app->m_key.m_data.m_cbc_tdes2      .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes2   && mode_id == mk_lib_crypto_app_mode_id_e_ofb    ){ for(i = 0; i != mk_lib_crypto_mode_ofb_tdes2_key_len_v      ; ++i){ app->m_key.m_data.m_ofb_tdes2      .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_cbc    ){ for(i = 0; i != mk_lib_crypto_mode_cbc_tdes3_key_len_v      ; ++i){ app->m_key.m_data.m_cbc_tdes3      .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_cfb_128){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes3_key_len_v   ; ++i){ app->m_key.m_data.m_cfb_64_tdes3   .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_cfb_8  ){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes3_key_len_v    ; ++i){ app->m_key.m_data.m_cfb_8_tdes3    .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_ctr_be ){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes3_key_len_v   ; ++i){ app->m_key.m_data.m_ctr_be_tdes3   .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_ecb    ){ for(i = 0; i != mk_lib_crypto_alg_tdes3_key_len_v           ; ++i){ app->m_key.m_data.m_cbc_tdes3      .m_data.m_uint8s[i] = key_data[i]; } }
	else if(alg_id == mk_lib_crypto_app_alg_id_e_tdes3   && mode_id == mk_lib_crypto_app_mode_id_e_ofb    ){ for(i = 0; i != mk_lib_crypto_mode_ofb_tdes3_key_len_v      ; ++i){ app->m_key.m_data.m_ofb_tdes3      .m_data.m_uint8s[i] = key_data[i]; } }
	else{ mk_lang_assert(0); }
	return iv_len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline int mk_lib_crypto_app_get_msg_len(mk_lib_crypto_app_alg_id_t const alg_id, mk_lib_crypto_app_mode_id_t const mode_id) mk_lang_noexcept
{
	int id mk_lang_constexpr_init;
	int len mk_lang_constexpr_init;

	id = ((int)(((int)(alg_id)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mode_id))));
	switch(id)
	{
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): len = mk_lib_crypto_mode_cbc_aes_128_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): len = mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): len = mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v  ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): len = mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): len = mk_lib_crypto_mode_ecb_aes_128_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): len = mk_lib_crypto_mode_ofb_aes_128_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): len = mk_lib_crypto_mode_cbc_aes_192_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): len = mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): len = mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v  ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): len = mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): len = mk_lib_crypto_mode_ecb_aes_192_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): len = mk_lib_crypto_mode_ofb_aes_192_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): len = mk_lib_crypto_mode_cbc_aes_256_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): len = mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): len = mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v  ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): len = mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): len = mk_lib_crypto_mode_ecb_aes_256_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): len = mk_lib_crypto_mode_ofb_aes_256_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): len = mk_lib_crypto_mode_cbc_des_msg_len_v        ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): len = mk_lib_crypto_mode_cfb_64_des_msg_len_v     ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): len = mk_lib_crypto_mode_cfb_8_des_msg_len_v      ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): len = mk_lib_crypto_mode_ctr_be_des_msg_len_v     ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): len = mk_lib_crypto_mode_ecb_des_msg_len_v        ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): len = mk_lib_crypto_mode_ofb_des_msg_len_v        ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): len = mk_lib_crypto_mode_cbc_serpent_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): len = mk_lib_crypto_mode_cfb_128_serpent_msg_len_v; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): len = mk_lib_crypto_mode_cfb_8_serpent_msg_len_v  ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): len = mk_lib_crypto_mode_ctr_be_serpent_msg_len_v ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): len = mk_lib_crypto_mode_ecb_serpent_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): len = mk_lib_crypto_mode_ofb_serpent_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): len = mk_lib_crypto_mode_cbc_tdes2_msg_len_v      ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): len = mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v   ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): len = mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): len = mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v   ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): len = mk_lib_crypto_mode_ecb_tdes2_msg_len_v      ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): len = mk_lib_crypto_mode_ofb_tdes2_msg_len_v      ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): len = mk_lib_crypto_mode_cbc_tdes3_msg_len_v      ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): len = mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v   ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): len = mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v    ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): len = mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v   ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): len = mk_lib_crypto_mode_ecb_tdes3_msg_len_v      ; break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): len = mk_lib_crypto_mode_ofb_tdes3_msg_len_v      ; break;
		default: mk_lang_assert(0); break;
	}
	return len;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_app_encrypt_mode(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	int id mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(app);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_app_impl_get_data_size(app));

	id = ((int)(((int)(app->m_alg_id)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(app->m_mode_id))));
	switch(id)
	{
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_aes_128_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_128_schedule_encrypt    (&app->m_mode.m_data.m_cbc_aes_128    , &app->m_schedule.m_data.m_cbc_aes_128    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_128_aes_128_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_128_schedule_encrypt(&app->m_mode.m_data.m_cfb_128_aes_128, &app->m_schedule.m_data.m_cfb_128_aes_128, &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_aes_128_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_128_schedule_encrypt  (&app->m_mode.m_data.m_cfb_8_aes_128  , &app->m_schedule.m_data.m_cfb_8_aes_128  , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_aes_128_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_128_schedule_encrypt (&app->m_mode.m_data.m_ctr_be_aes_128 , &app->m_schedule.m_data.m_ctr_be_aes_128 , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_aes_128_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_aes_128_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_aes_128_schedule_encrypt    (&app->m_mode.m_data.m_ecb_aes_128    , &app->m_schedule.m_data.m_ecb_aes_128    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_aes_128_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_128_schedule_encrypt    (&app->m_mode.m_data.m_ofb_aes_128    , &app->m_schedule.m_data.m_ofb_aes_128    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_aes_192_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_192_schedule_encrypt    (&app->m_mode.m_data.m_cbc_aes_192    , &app->m_schedule.m_data.m_cbc_aes_192    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_128_aes_192_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_192_schedule_encrypt(&app->m_mode.m_data.m_cfb_128_aes_192, &app->m_schedule.m_data.m_cfb_128_aes_192, &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_aes_192_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_192_schedule_encrypt  (&app->m_mode.m_data.m_cfb_8_aes_192  , &app->m_schedule.m_data.m_cfb_8_aes_192  , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_aes_192_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_192_schedule_encrypt (&app->m_mode.m_data.m_ctr_be_aes_192 , &app->m_schedule.m_data.m_ctr_be_aes_192 , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_aes_192_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_aes_192_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_aes_192_schedule_encrypt    (&app->m_mode.m_data.m_ecb_aes_192    , &app->m_schedule.m_data.m_ecb_aes_192    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_aes_192_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_192_schedule_encrypt    (&app->m_mode.m_data.m_ofb_aes_192    , &app->m_schedule.m_data.m_ofb_aes_192    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_aes_256_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_256_schedule_encrypt    (&app->m_mode.m_data.m_cbc_aes_256    , &app->m_schedule.m_data.m_cbc_aes_256    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_128_aes_256_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_256_schedule_encrypt(&app->m_mode.m_data.m_cfb_128_aes_256, &app->m_schedule.m_data.m_cfb_128_aes_256, &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_aes_256_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_256_schedule_encrypt  (&app->m_mode.m_data.m_cfb_8_aes_256  , &app->m_schedule.m_data.m_cfb_8_aes_256  , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_aes_256_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_256_schedule_encrypt (&app->m_mode.m_data.m_ctr_be_aes_256 , &app->m_schedule.m_data.m_ctr_be_aes_256 , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_aes_256_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_aes_256_schedule_encrypt    (&app->m_mode.m_data.m_ecb_aes_256    , &app->m_schedule.m_data.m_ecb_aes_256    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_aes_256_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_256_schedule_encrypt    (&app->m_mode.m_data.m_ofb_aes_256    , &app->m_schedule.m_data.m_ofb_aes_256    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_des_msg_t         msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_des_msg_len_v        ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_des_schedule_encrypt        (&app->m_mode.m_data.m_cbc_des        , &app->m_schedule.m_data.m_cbc_des        , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_des_msg_len_v        ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_64_des_msg_t      msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_64_des_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_64_des_schedule_encrypt     (&app->m_mode.m_data.m_cfb_64_des     , &app->m_schedule.m_data.m_cfb_64_des     , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_64_des_msg_len_v     ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_des_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_des_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_des_schedule_encrypt      (&app->m_mode.m_data.m_cfb_8_des      , &app->m_schedule.m_data.m_cfb_8_des      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_des_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_des_msg_t      msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_des_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_des_schedule_encrypt     (&app->m_mode.m_data.m_ctr_be_des     , &app->m_schedule.m_data.m_ctr_be_des     , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_des_msg_len_v     ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_des_msg_t         msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_des_msg_len_v        ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_des_schedule_encrypt        (&app->m_mode.m_data.m_ecb_des        , &app->m_schedule.m_data.m_ecb_des        , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_des_msg_len_v        ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_des_msg_t         msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_des_msg_len_v        ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_des_schedule_encrypt        (&app->m_mode.m_data.m_ofb_des        , &app->m_schedule.m_data.m_ofb_des        , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_des_msg_len_v        ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_serpent_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_serpent_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_serpent_schedule_encrypt    (&app->m_mode.m_data.m_cbc_serpent    , &app->m_schedule.m_data.m_cbc_serpent    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_128_serpent_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_serpent_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_serpent_schedule_encrypt(&app->m_mode.m_data.m_cfb_128_serpent, &app->m_schedule.m_data.m_cfb_128_serpent, &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_128_serpent_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_serpent_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_serpent_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_serpent_schedule_encrypt  (&app->m_mode.m_data.m_cfb_8_serpent  , &app->m_schedule.m_data.m_cfb_8_serpent  , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_serpent_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_serpent_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_serpent_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_serpent_schedule_encrypt (&app->m_mode.m_data.m_ctr_be_serpent , &app->m_schedule.m_data.m_ctr_be_serpent , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_serpent_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_serpent_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_serpent_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_serpent_schedule_encrypt    (&app->m_mode.m_data.m_ecb_serpent    , &app->m_schedule.m_data.m_ecb_serpent    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_serpent_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_serpent_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_serpent_schedule_encrypt    (&app->m_mode.m_data.m_ofb_serpent    , &app->m_schedule.m_data.m_ofb_serpent    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_tdes2_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_tdes2_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_tdes2_schedule_encrypt      (&app->m_mode.m_data.m_cbc_tdes2      , &app->m_schedule.m_data.m_cbc_tdes2      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_tdes2_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_64_tdes2_msg_t    msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_64_tdes2_schedule_encrypt   (&app->m_mode.m_data.m_cfb_64_tdes2   , &app->m_schedule.m_data.m_cfb_64_tdes2   , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_tdes2_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_tdes2_schedule_encrypt    (&app->m_mode.m_data.m_cfb_8_tdes2    , &app->m_schedule.m_data.m_cfb_8_tdes2    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_tdes2_msg_t    msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_tdes2_schedule_encrypt   (&app->m_mode.m_data.m_ctr_be_tdes2   , &app->m_schedule.m_data.m_ctr_be_tdes2   , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_tdes2_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_tdes2_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_tdes2_schedule_encrypt      (&app->m_mode.m_data.m_ecb_tdes2      , &app->m_schedule.m_data.m_ecb_tdes2      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_tdes2_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_tdes2_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_tdes2_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_tdes2_schedule_encrypt      (&app->m_mode.m_data.m_ofb_tdes2      , &app->m_schedule.m_data.m_ofb_tdes2      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_tdes2_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_tdes3_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_tdes3_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_tdes3_schedule_encrypt      (&app->m_mode.m_data.m_cbc_tdes3      , &app->m_schedule.m_data.m_cbc_tdes3      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_tdes3_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_64_tdes3_msg_t    msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_64_tdes3_schedule_encrypt   (&app->m_mode.m_data.m_cfb_64_tdes3   , &app->m_schedule.m_data.m_cfb_64_tdes3   , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_tdes3_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_tdes3_schedule_encrypt    (&app->m_mode.m_data.m_cfb_8_tdes3    , &app->m_schedule.m_data.m_cfb_8_tdes3    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_tdes3_msg_t    msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_tdes3_schedule_encrypt   (&app->m_mode.m_data.m_ctr_be_tdes3   , &app->m_schedule.m_data.m_ctr_be_tdes3   , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_tdes3_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_tdes3_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_tdes3_schedule_encrypt      (&app->m_mode.m_data.m_ecb_tdes3      , &app->m_schedule.m_data.m_ecb_tdes3      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_tdes3_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_tdes3_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_tdes3_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_tdes3_schedule_encrypt      (&app->m_mode.m_data.m_ofb_tdes3      , &app->m_schedule.m_data.m_ofb_tdes3      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_tdes3_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_app_encrypt_mode_16(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	int id mk_lang_constexpr_init;
	int iblock mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(app);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_app_impl_get_data_size(app));

	id = ((int)(((int)(app->m_alg_id)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(app->m_mode_id))));
	switch(id)
	{
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_aes_128_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_128_msg_len_v     + + i]; } } mk_lib_crypto_mode_cbc_aes_128_schedule_encrypt    (&app->m_mode.m_data.m_cbc_aes_128    , &app->m_schedule.m_data.m_cbc_aes_128    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_128_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_128_aes_128_msg_t msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v + + i]; } } mk_lib_crypto_mode_cfb_128_aes_128_schedule_encrypt(&app->m_mode.m_data.m_cfb_128_aes_128, &app->m_schedule.m_data.m_cfb_128_aes_128, &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_aes_128_msg_t   msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v  ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v   + + i]; } } mk_lib_crypto_mode_cfb_8_aes_128_schedule_encrypt  (&app->m_mode.m_data.m_cfb_8_aes_128  , &app->m_schedule.m_data.m_cfb_8_aes_128  , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v   + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_aes_128_msg_t  msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v  + + i]; } } mk_lib_crypto_mode_ctr_be_aes_128_schedule_encrypt (&app->m_mode.m_data.m_ctr_be_aes_128 , &app->m_schedule.m_data.m_ctr_be_aes_128 , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v  + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_aes_128_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_128_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_128_msg_len_v     + + i]; } } mk_lib_crypto_mode_ecb_aes_128_schedule_encrypt    (&app->m_mode.m_data.m_ecb_aes_128    , &app->m_schedule.m_data.m_ecb_aes_128    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_128_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ofb_aes_128_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_128_msg_len_v     + + i]; } } mk_lib_crypto_mode_ofb_aes_128_schedule_encrypt    (&app->m_mode.m_data.m_ofb_aes_128    , &app->m_schedule.m_data.m_ofb_aes_128    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_128_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_aes_192_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_192_msg_len_v     + + i]; } } mk_lib_crypto_mode_cbc_aes_192_schedule_encrypt    (&app->m_mode.m_data.m_cbc_aes_192    , &app->m_schedule.m_data.m_cbc_aes_192    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_192_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_128_aes_192_msg_t msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + + i]; } } mk_lib_crypto_mode_cfb_128_aes_192_schedule_encrypt(&app->m_mode.m_data.m_cfb_128_aes_192, &app->m_schedule.m_data.m_cfb_128_aes_192, &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_aes_192_msg_t   msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v  ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v   + + i]; } } mk_lib_crypto_mode_cfb_8_aes_192_schedule_encrypt  (&app->m_mode.m_data.m_cfb_8_aes_192  , &app->m_schedule.m_data.m_cfb_8_aes_192  , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v   + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_aes_192_msg_t  msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v  + + i]; } } mk_lib_crypto_mode_ctr_be_aes_192_schedule_encrypt (&app->m_mode.m_data.m_ctr_be_aes_192 , &app->m_schedule.m_data.m_ctr_be_aes_192 , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v  + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_aes_192_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_192_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_192_msg_len_v     + + i]; } } mk_lib_crypto_mode_ecb_aes_192_schedule_encrypt    (&app->m_mode.m_data.m_ecb_aes_192    , &app->m_schedule.m_data.m_ecb_aes_192    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_192_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ofb_aes_192_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_192_msg_len_v     + + i]; } } mk_lib_crypto_mode_ofb_aes_192_schedule_encrypt    (&app->m_mode.m_data.m_ofb_aes_192    , &app->m_schedule.m_data.m_ofb_aes_192    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_192_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_aes_256_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_256_msg_len_v     + + i]; } } mk_lib_crypto_mode_cbc_aes_256_schedule_encrypt    (&app->m_mode.m_data.m_cbc_aes_256    , &app->m_schedule.m_data.m_cbc_aes_256    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_256_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_128_aes_256_msg_t msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v + + i]; } } mk_lib_crypto_mode_cfb_128_aes_256_schedule_encrypt(&app->m_mode.m_data.m_cfb_128_aes_256, &app->m_schedule.m_data.m_cfb_128_aes_256, &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_aes_256_msg_t   msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v  ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v   + + i]; } } mk_lib_crypto_mode_cfb_8_aes_256_schedule_encrypt  (&app->m_mode.m_data.m_cfb_8_aes_256  , &app->m_schedule.m_data.m_cfb_8_aes_256  , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v   + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_aes_256_msg_t  msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v  + + i]; } } mk_lib_crypto_mode_ctr_be_aes_256_schedule_encrypt (&app->m_mode.m_data.m_ctr_be_aes_256 , &app->m_schedule.m_data.m_ctr_be_aes_256 , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v  + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_aes_256_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_256_msg_len_v     + + i]; } } mk_lib_crypto_mode_ecb_aes_256_schedule_encrypt    (&app->m_mode.m_data.m_ecb_aes_256    , &app->m_schedule.m_data.m_ecb_aes_256    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_256_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ofb_aes_256_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_256_msg_len_v     + + i]; } } mk_lib_crypto_mode_ofb_aes_256_schedule_encrypt    (&app->m_mode.m_data.m_ofb_aes_256    , &app->m_schedule.m_data.m_ofb_aes_256    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_256_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_des_msg_t         msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_des_msg_len_v        ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_des_msg_len_v         + + i]; } } mk_lib_crypto_mode_cbc_des_schedule_encrypt        (&app->m_mode.m_data.m_cbc_des        , &app->m_schedule.m_data.m_cbc_des        , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_des_msg_len_v        ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_des_msg_len_v         + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_64_des_msg_t      msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_des_msg_len_v     ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_des_msg_len_v      + + i]; } } mk_lib_crypto_mode_cfb_64_des_schedule_encrypt     (&app->m_mode.m_data.m_cfb_64_des     , &app->m_schedule.m_data.m_cfb_64_des     , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_des_msg_len_v     ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_des_msg_len_v      + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_des_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_des_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_des_msg_len_v       + + i]; } } mk_lib_crypto_mode_cfb_8_des_schedule_encrypt      (&app->m_mode.m_data.m_cfb_8_des      , &app->m_schedule.m_data.m_cfb_8_des      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_des_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_des_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_des_msg_t      msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_des_msg_len_v     ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_des_msg_len_v      + + i]; } } mk_lib_crypto_mode_ctr_be_des_schedule_encrypt     (&app->m_mode.m_data.m_ctr_be_des     , &app->m_schedule.m_data.m_ctr_be_des     , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_des_msg_len_v     ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_des_msg_len_v      + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_des_msg_t         msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_des_msg_len_v        ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_des_msg_len_v         + + i]; } } mk_lib_crypto_mode_ecb_des_schedule_encrypt        (&app->m_mode.m_data.m_ecb_des        , &app->m_schedule.m_data.m_ecb_des        , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_des_msg_len_v        ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_des_msg_len_v         + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_serpent_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_serpent_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_serpent_msg_len_v     + + i]; } } mk_lib_crypto_mode_cbc_serpent_schedule_encrypt    (&app->m_mode.m_data.m_cbc_serpent    , &app->m_schedule.m_data.m_cbc_serpent    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_serpent_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_128_serpent_msg_t msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_serpent_msg_len_v; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_serpent_msg_len_v + + i]; } } mk_lib_crypto_mode_cfb_128_serpent_schedule_encrypt(&app->m_mode.m_data.m_cfb_128_serpent, &app->m_schedule.m_data.m_cfb_128_serpent, &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_serpent_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_serpent_msg_len_v + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_serpent_msg_t   msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_serpent_msg_len_v  ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_serpent_msg_len_v   + + i]; } } mk_lib_crypto_mode_cfb_8_serpent_schedule_encrypt  (&app->m_mode.m_data.m_cfb_8_serpent  , &app->m_schedule.m_data.m_cfb_8_serpent  , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_serpent_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_serpent_msg_len_v   + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_serpent_msg_t  msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_serpent_msg_len_v ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_serpent_msg_len_v  + + i]; } } mk_lib_crypto_mode_ctr_be_serpent_schedule_encrypt (&app->m_mode.m_data.m_ctr_be_serpent , &app->m_schedule.m_data.m_ctr_be_serpent , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_serpent_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_serpent_msg_len_v  + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_serpent_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_serpent_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_serpent_msg_len_v     + + i]; } } mk_lib_crypto_mode_ecb_serpent_schedule_encrypt    (&app->m_mode.m_data.m_ecb_serpent    , &app->m_schedule.m_data.m_ecb_serpent    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_serpent_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ofb_serpent_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_serpent_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_serpent_msg_len_v     + + i]; } } mk_lib_crypto_mode_ofb_serpent_schedule_encrypt    (&app->m_mode.m_data.m_ofb_serpent    , &app->m_schedule.m_data.m_ofb_serpent    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_serpent_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_tdes2_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_tdes2_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_tdes2_msg_len_v       + + i]; } } mk_lib_crypto_mode_cbc_tdes2_schedule_encrypt      (&app->m_mode.m_data.m_cbc_tdes2      , &app->m_schedule.m_data.m_cbc_tdes2      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_tdes2_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_tdes2_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_64_tdes2_msg_t    msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v   ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v    + + i]; } } mk_lib_crypto_mode_cfb_64_tdes2_schedule_encrypt   (&app->m_mode.m_data.m_cfb_64_tdes2   , &app->m_schedule.m_data.m_cfb_64_tdes2   , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v    + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_tdes2_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v     + + i]; } } mk_lib_crypto_mode_cfb_8_tdes2_schedule_encrypt    (&app->m_mode.m_data.m_cfb_8_tdes2    , &app->m_schedule.m_data.m_cfb_8_tdes2    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_tdes2_msg_t    msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v   ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v    + + i]; } } mk_lib_crypto_mode_ctr_be_tdes2_schedule_encrypt   (&app->m_mode.m_data.m_ctr_be_tdes2   , &app->m_schedule.m_data.m_ctr_be_tdes2   , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v    + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_tdes2_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_tdes2_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_tdes2_msg_len_v       + + i]; } } mk_lib_crypto_mode_ecb_tdes2_schedule_encrypt      (&app->m_mode.m_data.m_ecb_tdes2      , &app->m_schedule.m_data.m_ecb_tdes2      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_tdes2_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_tdes2_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_tdes3_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_tdes3_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_tdes3_msg_len_v       + + i]; } } mk_lib_crypto_mode_cbc_tdes3_schedule_encrypt      (&app->m_mode.m_data.m_cbc_tdes3      , &app->m_schedule.m_data.m_cbc_tdes3      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_tdes3_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_tdes3_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_64_tdes3_msg_t    msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v   ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v    + + i]; } } mk_lib_crypto_mode_cfb_64_tdes3_schedule_encrypt   (&app->m_mode.m_data.m_cfb_64_tdes3   , &app->m_schedule.m_data.m_cfb_64_tdes3   , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v    + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_tdes3_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v     + + i]; } } mk_lib_crypto_mode_cfb_8_tdes3_schedule_encrypt    (&app->m_mode.m_data.m_cfb_8_tdes3    , &app->m_schedule.m_data.m_cfb_8_tdes3    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_tdes3_msg_t    msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v   ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v    + + i]; } } mk_lib_crypto_mode_ctr_be_tdes3_schedule_encrypt   (&app->m_mode.m_data.m_ctr_be_tdes3   , &app->m_schedule.m_data.m_ctr_be_tdes3   , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v    + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_tdes3_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_tdes3_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_tdes3_msg_len_v       + + i]; } } mk_lib_crypto_mode_ecb_tdes3_schedule_encrypt      (&app->m_mode.m_data.m_ecb_tdes3      , &app->m_schedule.m_data.m_ecb_tdes3      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_tdes3_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_tdes3_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_app_decrypt_mode(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	int id mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(app);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_app_impl_get_data_size(app));

	id = ((int)(((int)(app->m_alg_id)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(app->m_mode_id))));
	switch(id)
	{
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_aes_128_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_128_schedule_decrypt    (&app->m_mode.m_data.m_cbc_aes_128    , &app->m_schedule.m_data.m_cbc_aes_128    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_128_aes_128_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_128_schedule_decrypt(&app->m_mode.m_data.m_cfb_128_aes_128, &app->m_schedule.m_data.m_cfb_128_aes_128, &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_aes_128_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_128_schedule_decrypt  (&app->m_mode.m_data.m_cfb_8_aes_128  , &app->m_schedule.m_data.m_cfb_8_aes_128  , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_aes_128_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_128_schedule_decrypt (&app->m_mode.m_data.m_ctr_be_aes_128 , &app->m_schedule.m_data.m_ctr_be_aes_128 , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_aes_128_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_aes_128_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_aes_128_schedule_decrypt    (&app->m_mode.m_data.m_ecb_aes_128    , &app->m_schedule.m_data.m_ecb_aes_128    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_aes_128_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_128_schedule_decrypt    (&app->m_mode.m_data.m_ofb_aes_128    , &app->m_schedule.m_data.m_ofb_aes_128    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_aes_192_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_192_schedule_decrypt    (&app->m_mode.m_data.m_cbc_aes_192    , &app->m_schedule.m_data.m_cbc_aes_192    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_128_aes_192_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_192_schedule_decrypt(&app->m_mode.m_data.m_cfb_128_aes_192, &app->m_schedule.m_data.m_cfb_128_aes_192, &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_aes_192_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_192_schedule_decrypt  (&app->m_mode.m_data.m_cfb_8_aes_192  , &app->m_schedule.m_data.m_cfb_8_aes_192  , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_aes_192_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_192_schedule_decrypt (&app->m_mode.m_data.m_ctr_be_aes_192 , &app->m_schedule.m_data.m_ctr_be_aes_192 , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_aes_192_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_aes_192_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_aes_192_schedule_decrypt    (&app->m_mode.m_data.m_ecb_aes_192    , &app->m_schedule.m_data.m_ecb_aes_192    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_aes_192_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_192_schedule_decrypt    (&app->m_mode.m_data.m_ofb_aes_192    , &app->m_schedule.m_data.m_ofb_aes_192    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_aes_256_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_aes_256_schedule_decrypt    (&app->m_mode.m_data.m_cbc_aes_256    , &app->m_schedule.m_data.m_cbc_aes_256    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_128_aes_256_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_aes_256_schedule_decrypt(&app->m_mode.m_data.m_cfb_128_aes_256, &app->m_schedule.m_data.m_cfb_128_aes_256, &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_aes_256_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_aes_256_schedule_decrypt  (&app->m_mode.m_data.m_cfb_8_aes_256  , &app->m_schedule.m_data.m_cfb_8_aes_256  , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_aes_256_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_aes_256_schedule_decrypt (&app->m_mode.m_data.m_ctr_be_aes_256 , &app->m_schedule.m_data.m_ctr_be_aes_256 , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_aes_256_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_aes_256_schedule_decrypt    (&app->m_mode.m_data.m_ecb_aes_256    , &app->m_schedule.m_data.m_ecb_aes_256    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_aes_256_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_aes_256_schedule_decrypt    (&app->m_mode.m_data.m_ofb_aes_256    , &app->m_schedule.m_data.m_ofb_aes_256    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_des_msg_t         msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_des_msg_len_v        ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_des_schedule_decrypt        (&app->m_mode.m_data.m_cbc_des        , &app->m_schedule.m_data.m_cbc_des        , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_des_msg_len_v        ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_64_des_msg_t      msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_64_des_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_64_des_schedule_decrypt     (&app->m_mode.m_data.m_cfb_64_des     , &app->m_schedule.m_data.m_cfb_64_des     , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_64_des_msg_len_v     ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_des_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_des_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_des_schedule_decrypt      (&app->m_mode.m_data.m_cfb_8_des      , &app->m_schedule.m_data.m_cfb_8_des      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_des_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_des_msg_t      msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_des_msg_len_v     ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_des_schedule_decrypt     (&app->m_mode.m_data.m_ctr_be_des     , &app->m_schedule.m_data.m_ctr_be_des     , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_des_msg_len_v     ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_des_msg_t         msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_des_msg_len_v        ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_des_schedule_decrypt        (&app->m_mode.m_data.m_ecb_des        , &app->m_schedule.m_data.m_ecb_des        , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_des_msg_len_v        ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_des_msg_t         msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_des_msg_len_v        ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_des_schedule_decrypt        (&app->m_mode.m_data.m_ofb_des        , &app->m_schedule.m_data.m_ofb_des        , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_des_msg_len_v        ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_serpent_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_serpent_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_serpent_schedule_decrypt    (&app->m_mode.m_data.m_cbc_serpent    , &app->m_schedule.m_data.m_cbc_serpent    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_128_serpent_msg_t msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_128_serpent_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_128_serpent_schedule_decrypt(&app->m_mode.m_data.m_cfb_128_serpent, &app->m_schedule.m_data.m_cfb_128_serpent, &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_128_serpent_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_serpent_msg_t   msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_serpent_msg_len_v  ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_serpent_schedule_decrypt  (&app->m_mode.m_data.m_cfb_8_serpent  , &app->m_schedule.m_data.m_cfb_8_serpent  , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_serpent_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_serpent_msg_t  msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_serpent_msg_len_v ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_serpent_schedule_decrypt (&app->m_mode.m_data.m_ctr_be_serpent , &app->m_schedule.m_data.m_ctr_be_serpent , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_serpent_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_serpent_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_serpent_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_serpent_schedule_decrypt    (&app->m_mode.m_data.m_ecb_serpent    , &app->m_schedule.m_data.m_ecb_serpent    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_serpent_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_serpent_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_serpent_schedule_decrypt    (&app->m_mode.m_data.m_ofb_serpent    , &app->m_schedule.m_data.m_ofb_serpent    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_tdes2_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_tdes2_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_tdes2_schedule_decrypt      (&app->m_mode.m_data.m_cbc_tdes2      , &app->m_schedule.m_data.m_cbc_tdes2      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_tdes2_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_64_tdes2_msg_t    msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_64_tdes2_schedule_decrypt   (&app->m_mode.m_data.m_cfb_64_tdes2   , &app->m_schedule.m_data.m_cfb_64_tdes2   , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_tdes2_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_tdes2_schedule_decrypt    (&app->m_mode.m_data.m_cfb_8_tdes2    , &app->m_schedule.m_data.m_cfb_8_tdes2    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_tdes2_msg_t    msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_tdes2_schedule_decrypt   (&app->m_mode.m_data.m_ctr_be_tdes2   , &app->m_schedule.m_data.m_ctr_be_tdes2   , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_tdes2_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_tdes2_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_tdes2_schedule_decrypt      (&app->m_mode.m_data.m_ecb_tdes2      , &app->m_schedule.m_data.m_ecb_tdes2      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_tdes2_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_tdes2_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_tdes2_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_tdes2_schedule_decrypt      (&app->m_mode.m_data.m_ofb_tdes2      , &app->m_schedule.m_data.m_ofb_tdes2      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_tdes2_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lib_crypto_mode_cbc_tdes3_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cbc_tdes3_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cbc_tdes3_schedule_decrypt      (&app->m_mode.m_data.m_cbc_tdes3      , &app->m_schedule.m_data.m_cbc_tdes3      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cbc_tdes3_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lib_crypto_mode_cfb_64_tdes3_msg_t    msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_64_tdes3_schedule_decrypt   (&app->m_mode.m_data.m_cfb_64_tdes3   , &app->m_schedule.m_data.m_cfb_64_tdes3   , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lib_crypto_mode_cfb_8_tdes3_msg_t     msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v    ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_cfb_8_tdes3_schedule_decrypt    (&app->m_mode.m_data.m_cfb_8_tdes3    , &app->m_schedule.m_data.m_cfb_8_tdes3    , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lib_crypto_mode_ctr_be_tdes3_msg_t    msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v   ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ctr_be_tdes3_schedule_decrypt   (&app->m_mode.m_data.m_ctr_be_tdes3   , &app->m_schedule.m_data.m_ctr_be_tdes3   , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lib_crypto_mode_ecb_tdes3_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ecb_tdes3_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ecb_tdes3_schedule_decrypt      (&app->m_mode.m_data.m_ecb_tdes3      , &app->m_schedule.m_data.m_ecb_tdes3      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ecb_tdes3_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lib_crypto_mode_ofb_tdes3_msg_t       msg mk_lang_constexpr_init; for(i = 0; i != mk_lib_crypto_mode_ofb_tdes3_msg_len_v      ; ++i){ msg.m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + i]; } mk_lib_crypto_mode_ofb_tdes3_schedule_decrypt      (&app->m_mode.m_data.m_ofb_tdes3      , &app->m_schedule.m_data.m_ofb_tdes3      , &msg, &msg, 1); for(i = 0; i != mk_lib_crypto_mode_ofb_tdes3_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + i] = msg.m_data.m_uint8s[i]; } } break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_app_decrypt_mode_16(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	int id mk_lang_constexpr_init;
	int iblock mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(app);
	mk_lang_assert(idx >= 0 && idx <= mk_lib_crypto_app_impl_get_data_size(app));

	id = ((int)(((int)(app->m_alg_id)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(app->m_mode_id))));
	switch(id)
	{
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_aes_128_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_128_msg_len_v     + i]; } } mk_lib_crypto_mode_cbc_aes_128_schedule_decrypt    (&app->m_mode.m_data.m_cbc_aes_128    , &app->m_schedule.m_data.m_cbc_aes_128    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_128_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_128_aes_128_msg_t msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v + i]; } } mk_lib_crypto_mode_cfb_128_aes_128_schedule_decrypt(&app->m_mode.m_data.m_cfb_128_aes_128, &app->m_schedule.m_data.m_cfb_128_aes_128, &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_128_msg_len_v + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_aes_128_msg_t   msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v  ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v   + i]; } } mk_lib_crypto_mode_cfb_8_aes_128_schedule_decrypt  (&app->m_mode.m_data.m_cfb_8_aes_128  , &app->m_schedule.m_data.m_cfb_8_aes_128  , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_128_msg_len_v   + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_aes_128_msg_t  msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v  + i]; } } mk_lib_crypto_mode_ctr_be_aes_128_schedule_decrypt (&app->m_mode.m_data.m_ctr_be_aes_128 , &app->m_schedule.m_data.m_ctr_be_aes_128 , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_128_msg_len_v  + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_aes_128_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_128_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_128_msg_len_v     + i]; } } mk_lib_crypto_mode_ecb_aes_128_schedule_decrypt    (&app->m_mode.m_data.m_ecb_aes_128    , &app->m_schedule.m_data.m_ecb_aes_128    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_128_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ofb_aes_128_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_128_msg_len_v     + i]; } } mk_lib_crypto_mode_ofb_aes_128_schedule_decrypt    (&app->m_mode.m_data.m_ofb_aes_128    , &app->m_schedule.m_data.m_ofb_aes_128    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_128_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_128_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_aes_192_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_192_msg_len_v     + i]; } } mk_lib_crypto_mode_cbc_aes_192_schedule_decrypt    (&app->m_mode.m_data.m_cbc_aes_192    , &app->m_schedule.m_data.m_cbc_aes_192    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_192_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_128_aes_192_msg_t msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + i]; } } mk_lib_crypto_mode_cfb_128_aes_192_schedule_decrypt(&app->m_mode.m_data.m_cfb_128_aes_192, &app->m_schedule.m_data.m_cfb_128_aes_192, &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_aes_192_msg_t   msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v  ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v   + i]; } } mk_lib_crypto_mode_cfb_8_aes_192_schedule_decrypt  (&app->m_mode.m_data.m_cfb_8_aes_192  , &app->m_schedule.m_data.m_cfb_8_aes_192  , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_192_msg_len_v   + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_aes_192_msg_t  msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v  + i]; } } mk_lib_crypto_mode_ctr_be_aes_192_schedule_decrypt (&app->m_mode.m_data.m_ctr_be_aes_192 , &app->m_schedule.m_data.m_ctr_be_aes_192 , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_192_msg_len_v  + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_aes_192_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_192_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_192_msg_len_v     + i]; } } mk_lib_crypto_mode_ecb_aes_192_schedule_decrypt    (&app->m_mode.m_data.m_ecb_aes_192    , &app->m_schedule.m_data.m_ecb_aes_192    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_192_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ofb_aes_192_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_192_msg_len_v     + i]; } } mk_lib_crypto_mode_ofb_aes_192_schedule_decrypt    (&app->m_mode.m_data.m_ofb_aes_192    , &app->m_schedule.m_data.m_ofb_aes_192    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_192_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_192_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_aes_256_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_256_msg_len_v     + i]; } } mk_lib_crypto_mode_cbc_aes_256_schedule_decrypt    (&app->m_mode.m_data.m_cbc_aes_256    , &app->m_schedule.m_data.m_cbc_aes_256    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_aes_256_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_128_aes_256_msg_t msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v + i]; } } mk_lib_crypto_mode_cfb_128_aes_256_schedule_decrypt(&app->m_mode.m_data.m_cfb_128_aes_256, &app->m_schedule.m_data.m_cfb_128_aes_256, &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_aes_256_msg_len_v + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_aes_256_msg_t   msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v  ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v   + i]; } } mk_lib_crypto_mode_cfb_8_aes_256_schedule_decrypt  (&app->m_mode.m_data.m_cfb_8_aes_256  , &app->m_schedule.m_data.m_cfb_8_aes_256  , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_aes_256_msg_len_v   + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_aes_256_msg_t  msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v  + i]; } } mk_lib_crypto_mode_ctr_be_aes_256_schedule_decrypt (&app->m_mode.m_data.m_ctr_be_aes_256 , &app->m_schedule.m_data.m_ctr_be_aes_256 , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_aes_256_msg_len_v  + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_aes_256_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_256_msg_len_v     + i]; } } mk_lib_crypto_mode_ecb_aes_256_schedule_decrypt    (&app->m_mode.m_data.m_ecb_aes_256    , &app->m_schedule.m_data.m_ecb_aes_256    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_aes_256_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ofb_aes_256_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_256_msg_len_v     + i]; } } mk_lib_crypto_mode_ofb_aes_256_schedule_decrypt    (&app->m_mode.m_data.m_ofb_aes_256    , &app->m_schedule.m_data.m_ofb_aes_256    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_aes_256_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_aes_256_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_des_msg_t         msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_des_msg_len_v        ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_des_msg_len_v         + i]; } } mk_lib_crypto_mode_cbc_des_schedule_decrypt        (&app->m_mode.m_data.m_cbc_des        , &app->m_schedule.m_data.m_cbc_des        , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_des_msg_len_v        ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_des_msg_len_v         + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_64_des_msg_t      msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_des_msg_len_v     ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_des_msg_len_v      + i]; } } mk_lib_crypto_mode_cfb_64_des_schedule_decrypt     (&app->m_mode.m_data.m_cfb_64_des     , &app->m_schedule.m_data.m_cfb_64_des     , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_des_msg_len_v     ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_des_msg_len_v      + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_des_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_des_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_des_msg_len_v       + i]; } } mk_lib_crypto_mode_cfb_8_des_schedule_decrypt      (&app->m_mode.m_data.m_cfb_8_des      , &app->m_schedule.m_data.m_cfb_8_des      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_des_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_des_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_des_msg_t      msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_des_msg_len_v     ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_des_msg_len_v      + i]; } } mk_lib_crypto_mode_ctr_be_des_schedule_decrypt     (&app->m_mode.m_data.m_ctr_be_des     , &app->m_schedule.m_data.m_ctr_be_des     , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_des_msg_len_v     ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_des_msg_len_v      + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_des_msg_t         msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_des_msg_len_v        ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_des_msg_len_v         + i]; } } mk_lib_crypto_mode_ecb_des_schedule_decrypt        (&app->m_mode.m_data.m_ecb_des        , &app->m_schedule.m_data.m_ecb_des        , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_des_msg_len_v        ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_des_msg_len_v         + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ofb_des_msg_t         msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_des_msg_len_v        ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_des_msg_len_v         + i]; } } mk_lib_crypto_mode_ofb_des_schedule_decrypt        (&app->m_mode.m_data.m_ofb_des        , &app->m_schedule.m_data.m_ofb_des        , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_des_msg_len_v        ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_des_msg_len_v         + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_serpent_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_serpent_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_serpent_msg_len_v     + i]; } } mk_lib_crypto_mode_cbc_serpent_schedule_decrypt    (&app->m_mode.m_data.m_cbc_serpent    , &app->m_schedule.m_data.m_cbc_serpent    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_serpent_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_128_serpent_msg_t msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_serpent_msg_len_v; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_serpent_msg_len_v + i]; } } mk_lib_crypto_mode_cfb_128_serpent_schedule_decrypt(&app->m_mode.m_data.m_cfb_128_serpent, &app->m_schedule.m_data.m_cfb_128_serpent, &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_128_serpent_msg_len_v; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_128_serpent_msg_len_v + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_serpent_msg_t   msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_serpent_msg_len_v  ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_serpent_msg_len_v   + i]; } } mk_lib_crypto_mode_cfb_8_serpent_schedule_decrypt  (&app->m_mode.m_data.m_cfb_8_serpent  , &app->m_schedule.m_data.m_cfb_8_serpent  , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_serpent_msg_len_v  ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_serpent_msg_len_v   + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_serpent_msg_t  msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_serpent_msg_len_v ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_serpent_msg_len_v  + i]; } } mk_lib_crypto_mode_ctr_be_serpent_schedule_decrypt (&app->m_mode.m_data.m_ctr_be_serpent , &app->m_schedule.m_data.m_ctr_be_serpent , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_serpent_msg_len_v ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_serpent_msg_len_v  + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_serpent_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_serpent_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_serpent_msg_len_v     + i]; } } mk_lib_crypto_mode_ecb_serpent_schedule_decrypt    (&app->m_mode.m_data.m_ecb_serpent    , &app->m_schedule.m_data.m_ecb_serpent    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_serpent_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ofb_serpent_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_serpent_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_serpent_msg_len_v     + i]; } } mk_lib_crypto_mode_ofb_serpent_schedule_decrypt    (&app->m_mode.m_data.m_ofb_serpent    , &app->m_schedule.m_data.m_ofb_serpent    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_serpent_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_serpent_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_tdes2_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_tdes2_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_tdes2_msg_len_v       + i]; } } mk_lib_crypto_mode_cbc_tdes2_schedule_decrypt      (&app->m_mode.m_data.m_cbc_tdes2      , &app->m_schedule.m_data.m_cbc_tdes2      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_tdes2_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_tdes2_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_64_tdes2_msg_t    msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v   ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v    + i]; } } mk_lib_crypto_mode_cfb_64_tdes2_schedule_decrypt   (&app->m_mode.m_data.m_cfb_64_tdes2   , &app->m_schedule.m_data.m_cfb_64_tdes2   , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_tdes2_msg_len_v    + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_tdes2_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v     + i]; } } mk_lib_crypto_mode_cfb_8_tdes2_schedule_decrypt    (&app->m_mode.m_data.m_cfb_8_tdes2    , &app->m_schedule.m_data.m_cfb_8_tdes2    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_tdes2_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_tdes2_msg_t    msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v   ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v    + i]; } } mk_lib_crypto_mode_ctr_be_tdes2_schedule_decrypt   (&app->m_mode.m_data.m_ctr_be_tdes2   , &app->m_schedule.m_data.m_ctr_be_tdes2   , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_tdes2_msg_len_v    + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_tdes2_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_tdes2_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_tdes2_msg_len_v       + i]; } } mk_lib_crypto_mode_ecb_tdes2_schedule_decrypt      (&app->m_mode.m_data.m_ecb_tdes2      , &app->m_schedule.m_data.m_ecb_tdes2      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_tdes2_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_tdes2_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ofb_tdes2_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_tdes2_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_tdes2_msg_len_v       + i]; } } mk_lib_crypto_mode_ofb_tdes2_schedule_decrypt      (&app->m_mode.m_data.m_ofb_tdes2      , &app->m_schedule.m_data.m_ofb_tdes2      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_tdes2_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_tdes2_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cbc_tdes3_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_tdes3_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_tdes3_msg_len_v       + i]; } } mk_lib_crypto_mode_cbc_tdes3_schedule_decrypt      (&app->m_mode.m_data.m_cbc_tdes3      , &app->m_schedule.m_data.m_cbc_tdes3      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cbc_tdes3_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cbc_tdes3_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_64_tdes3_msg_t    msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v   ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v    + i]; } } mk_lib_crypto_mode_cfb_64_tdes3_schedule_decrypt   (&app->m_mode.m_data.m_cfb_64_tdes3   , &app->m_schedule.m_data.m_cfb_64_tdes3   , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_64_tdes3_msg_len_v    + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): { mk_lang_alignas(64) mk_lib_crypto_mode_cfb_8_tdes3_msg_t     msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v    ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v     + i]; } } mk_lib_crypto_mode_cfb_8_tdes3_schedule_decrypt    (&app->m_mode.m_data.m_cfb_8_tdes3    , &app->m_schedule.m_data.m_cfb_8_tdes3    , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v    ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_cfb_8_tdes3_msg_len_v     + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ctr_be_tdes3_msg_t    msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v   ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v    + i]; } } mk_lib_crypto_mode_ctr_be_tdes3_schedule_decrypt   (&app->m_mode.m_data.m_ctr_be_tdes3   , &app->m_schedule.m_data.m_ctr_be_tdes3   , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v   ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ctr_be_tdes3_msg_len_v    + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ecb_tdes3_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_tdes3_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_tdes3_msg_len_v       + i]; } } mk_lib_crypto_mode_ecb_tdes3_schedule_decrypt      (&app->m_mode.m_data.m_ecb_tdes3      , &app->m_schedule.m_data.m_ecb_tdes3      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ecb_tdes3_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ecb_tdes3_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): { mk_lang_alignas(64) mk_lib_crypto_mode_ofb_tdes3_msg_t       msg[16] mk_lang_constexpr_init; for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_tdes3_msg_len_v      ; ++i){ msg[iblock].m_data.m_uint8s[i] = app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_tdes3_msg_len_v       + i]; } } mk_lib_crypto_mode_ofb_tdes3_schedule_decrypt      (&app->m_mode.m_data.m_ofb_tdes3      , &app->m_schedule.m_data.m_ofb_tdes3      , &msg[0], &msg[0], 16); for(iblock = 0; iblock != 16; ++iblock){ for(i = 0; i != mk_lib_crypto_mode_ofb_tdes3_msg_len_v      ; ++i){ app->m_buffer.m_data.m_uint8s[idx + iblock * mk_lib_crypto_mode_ofb_tdes3_msg_len_v       + i] = msg[iblock].m_data.m_uint8s[i]; } } } break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_app_impl_expand_enc(mk_lib_crypto_app_pt const app) mk_lang_noexcept
{
	int id mk_lang_constexpr_init;

	mk_lang_assert(app);

	if(app->m_expanded != 1)
	{
		app->m_expanded = 1;
		id = ((int)(((int)(app->m_alg_id)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(app->m_mode_id))));
		switch(id)
		{
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_aes_128_expand_enc    (&app->m_key.m_data.m_cbc_aes_128    , &app->m_schedule.m_data.m_cbc_aes_128    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_128_aes_128_expand_enc(&app->m_key.m_data.m_cfb_128_aes_128, &app->m_schedule.m_data.m_cfb_128_aes_128); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_aes_128_expand_enc  (&app->m_key.m_data.m_cfb_8_aes_128  , &app->m_schedule.m_data.m_cfb_8_aes_128  ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_aes_128_expand_enc (&app->m_key.m_data.m_ctr_be_aes_128 , &app->m_schedule.m_data.m_ctr_be_aes_128 ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_aes_128_expand_enc    (&app->m_key.m_data.m_ecb_aes_128    , &app->m_schedule.m_data.m_ecb_aes_128    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_aes_128_expand_enc    (&app->m_key.m_data.m_ofb_aes_128    , &app->m_schedule.m_data.m_ofb_aes_128    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_aes_192_expand_enc    (&app->m_key.m_data.m_cbc_aes_192    , &app->m_schedule.m_data.m_cbc_aes_192    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_128_aes_192_expand_enc(&app->m_key.m_data.m_cfb_128_aes_192, &app->m_schedule.m_data.m_cfb_128_aes_192); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_aes_192_expand_enc  (&app->m_key.m_data.m_cfb_8_aes_192  , &app->m_schedule.m_data.m_cfb_8_aes_192  ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_aes_192_expand_enc (&app->m_key.m_data.m_ctr_be_aes_192 , &app->m_schedule.m_data.m_ctr_be_aes_192 ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_aes_192_expand_enc    (&app->m_key.m_data.m_ecb_aes_192    , &app->m_schedule.m_data.m_ecb_aes_192    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_aes_192_expand_enc    (&app->m_key.m_data.m_ofb_aes_192    , &app->m_schedule.m_data.m_ofb_aes_192    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_aes_256_expand_enc    (&app->m_key.m_data.m_cbc_aes_256    , &app->m_schedule.m_data.m_cbc_aes_256    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_128_aes_256_expand_enc(&app->m_key.m_data.m_cfb_128_aes_256, &app->m_schedule.m_data.m_cfb_128_aes_256); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_aes_256_expand_enc  (&app->m_key.m_data.m_cfb_8_aes_256  , &app->m_schedule.m_data.m_cfb_8_aes_256  ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_aes_256_expand_enc (&app->m_key.m_data.m_ctr_be_aes_256 , &app->m_schedule.m_data.m_ctr_be_aes_256 ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_aes_256_expand_enc    (&app->m_key.m_data.m_ecb_aes_256    , &app->m_schedule.m_data.m_ecb_aes_256    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_aes_256_expand_enc    (&app->m_key.m_data.m_ofb_aes_256    , &app->m_schedule.m_data.m_ofb_aes_256    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_des_expand_enc        (&app->m_key.m_data.m_cbc_des        , &app->m_schedule.m_data.m_cbc_des        ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_64_des_expand_enc     (&app->m_key.m_data.m_cfb_64_des     , &app->m_schedule.m_data.m_cfb_64_des     ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_des_expand_enc      (&app->m_key.m_data.m_cfb_8_des      , &app->m_schedule.m_data.m_cfb_8_des      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_des_expand_enc     (&app->m_key.m_data.m_ctr_be_des     , &app->m_schedule.m_data.m_ctr_be_des     ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_des_expand_enc        (&app->m_key.m_data.m_ecb_des        , &app->m_schedule.m_data.m_ecb_des        ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_des_expand_enc        (&app->m_key.m_data.m_ofb_des        , &app->m_schedule.m_data.m_ofb_des        ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_serpent_expand_enc    (&app->m_key.m_data.m_cbc_serpent    , &app->m_schedule.m_data.m_cbc_serpent    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_128_serpent_expand_enc(&app->m_key.m_data.m_cfb_128_serpent, &app->m_schedule.m_data.m_cfb_128_serpent); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_serpent_expand_enc  (&app->m_key.m_data.m_cfb_8_serpent  , &app->m_schedule.m_data.m_cfb_8_serpent  ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_serpent_expand_enc (&app->m_key.m_data.m_ctr_be_serpent , &app->m_schedule.m_data.m_ctr_be_serpent ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_serpent_expand_enc    (&app->m_key.m_data.m_ecb_serpent    , &app->m_schedule.m_data.m_ecb_serpent    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_serpent_expand_enc    (&app->m_key.m_data.m_ofb_serpent    , &app->m_schedule.m_data.m_ofb_serpent    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_tdes2_expand_enc      (&app->m_key.m_data.m_cbc_tdes2      , &app->m_schedule.m_data.m_cbc_tdes2      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_64_tdes2_expand_enc   (&app->m_key.m_data.m_cfb_64_tdes2   , &app->m_schedule.m_data.m_cfb_64_tdes2   ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_tdes2_expand_enc    (&app->m_key.m_data.m_cfb_8_tdes2    , &app->m_schedule.m_data.m_cfb_8_tdes2    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_tdes2_expand_enc   (&app->m_key.m_data.m_ctr_be_tdes2   , &app->m_schedule.m_data.m_ctr_be_tdes2   ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_tdes2_expand_enc      (&app->m_key.m_data.m_ecb_tdes2      , &app->m_schedule.m_data.m_ecb_tdes2      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_tdes2_expand_enc      (&app->m_key.m_data.m_ofb_tdes2      , &app->m_schedule.m_data.m_ofb_tdes2      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_tdes3_expand_enc      (&app->m_key.m_data.m_cbc_tdes3      , &app->m_schedule.m_data.m_cbc_tdes3      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_64_tdes3_expand_enc   (&app->m_key.m_data.m_cfb_64_tdes3   , &app->m_schedule.m_data.m_cfb_64_tdes3   ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_tdes3_expand_enc    (&app->m_key.m_data.m_cfb_8_tdes3    , &app->m_schedule.m_data.m_cfb_8_tdes3    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_tdes3_expand_enc   (&app->m_key.m_data.m_ctr_be_tdes3   , &app->m_schedule.m_data.m_ctr_be_tdes3   ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_tdes3_expand_enc      (&app->m_key.m_data.m_ecb_tdes3      , &app->m_schedule.m_data.m_ecb_tdes3      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_tdes3_expand_enc      (&app->m_key.m_data.m_ofb_tdes3      , &app->m_schedule.m_data.m_ofb_tdes3      ); break;
			default: mk_lang_assert(0); break;
		}
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_app_impl_expand_dec(mk_lib_crypto_app_pt const app) mk_lang_noexcept
{
	int id mk_lang_constexpr_init;

	mk_lang_assert(app);

	if(app->m_expanded != 2)
	{
		app->m_expanded = 2;
		id = ((int)(((int)(app->m_alg_id)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(app->m_mode_id))));
		switch(id)
		{
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_aes_128_expand_dec    (&app->m_key.m_data.m_cbc_aes_128    , &app->m_schedule.m_data.m_cbc_aes_128    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_128_aes_128_expand_dec(&app->m_key.m_data.m_cfb_128_aes_128, &app->m_schedule.m_data.m_cfb_128_aes_128); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_aes_128_expand_dec  (&app->m_key.m_data.m_cfb_8_aes_128  , &app->m_schedule.m_data.m_cfb_8_aes_128  ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_aes_128_expand_dec (&app->m_key.m_data.m_ctr_be_aes_128 , &app->m_schedule.m_data.m_ctr_be_aes_128 ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_aes_128_expand_dec    (&app->m_key.m_data.m_ecb_aes_128    , &app->m_schedule.m_data.m_ecb_aes_128    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_128)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_aes_128_expand_dec    (&app->m_key.m_data.m_ofb_aes_128    , &app->m_schedule.m_data.m_ofb_aes_128    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_aes_192_expand_dec    (&app->m_key.m_data.m_cbc_aes_192    , &app->m_schedule.m_data.m_cbc_aes_192    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_128_aes_192_expand_dec(&app->m_key.m_data.m_cfb_128_aes_192, &app->m_schedule.m_data.m_cfb_128_aes_192); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_aes_192_expand_dec  (&app->m_key.m_data.m_cfb_8_aes_192  , &app->m_schedule.m_data.m_cfb_8_aes_192  ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_aes_192_expand_dec (&app->m_key.m_data.m_ctr_be_aes_192 , &app->m_schedule.m_data.m_ctr_be_aes_192 ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_aes_192_expand_dec    (&app->m_key.m_data.m_ecb_aes_192    , &app->m_schedule.m_data.m_ecb_aes_192    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_192)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_aes_192_expand_dec    (&app->m_key.m_data.m_ofb_aes_192    , &app->m_schedule.m_data.m_ofb_aes_192    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_aes_256_expand_dec    (&app->m_key.m_data.m_cbc_aes_256    , &app->m_schedule.m_data.m_cbc_aes_256    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_128_aes_256_expand_dec(&app->m_key.m_data.m_cfb_128_aes_256, &app->m_schedule.m_data.m_cfb_128_aes_256); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_aes_256_expand_dec  (&app->m_key.m_data.m_cfb_8_aes_256  , &app->m_schedule.m_data.m_cfb_8_aes_256  ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_aes_256_expand_dec (&app->m_key.m_data.m_ctr_be_aes_256 , &app->m_schedule.m_data.m_ctr_be_aes_256 ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_aes_256_expand_dec    (&app->m_key.m_data.m_ecb_aes_256    , &app->m_schedule.m_data.m_ecb_aes_256    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_aes_256)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_aes_256_expand_dec    (&app->m_key.m_data.m_ofb_aes_256    , &app->m_schedule.m_data.m_ofb_aes_256    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_des_expand_dec        (&app->m_key.m_data.m_cbc_des        , &app->m_schedule.m_data.m_cbc_des        ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_64_des_expand_dec     (&app->m_key.m_data.m_cfb_64_des     , &app->m_schedule.m_data.m_cfb_64_des     ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_des_expand_dec      (&app->m_key.m_data.m_cfb_8_des      , &app->m_schedule.m_data.m_cfb_8_des      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_des_expand_dec     (&app->m_key.m_data.m_ctr_be_des     , &app->m_schedule.m_data.m_ctr_be_des     ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_des_expand_dec        (&app->m_key.m_data.m_ecb_des        , &app->m_schedule.m_data.m_ecb_des        ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_des    )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_des_expand_dec        (&app->m_key.m_data.m_ofb_des        , &app->m_schedule.m_data.m_ofb_des        ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_serpent_expand_dec    (&app->m_key.m_data.m_cbc_serpent    , &app->m_schedule.m_data.m_cbc_serpent    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_128_serpent_expand_dec(&app->m_key.m_data.m_cfb_128_serpent, &app->m_schedule.m_data.m_cfb_128_serpent); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_serpent_expand_dec  (&app->m_key.m_data.m_cfb_8_serpent  , &app->m_schedule.m_data.m_cfb_8_serpent  ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_serpent_expand_dec (&app->m_key.m_data.m_ctr_be_serpent , &app->m_schedule.m_data.m_ctr_be_serpent ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_serpent_expand_dec    (&app->m_key.m_data.m_ecb_serpent    , &app->m_schedule.m_data.m_ecb_serpent    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_serpent)) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_serpent_expand_dec    (&app->m_key.m_data.m_ofb_serpent    , &app->m_schedule.m_data.m_ofb_serpent    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_tdes2_expand_dec      (&app->m_key.m_data.m_cbc_tdes2      , &app->m_schedule.m_data.m_cbc_tdes2      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_64_tdes2_expand_dec   (&app->m_key.m_data.m_cfb_64_tdes2   , &app->m_schedule.m_data.m_cfb_64_tdes2   ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_tdes2_expand_dec    (&app->m_key.m_data.m_cfb_8_tdes2    , &app->m_schedule.m_data.m_cfb_8_tdes2    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_tdes2_expand_dec   (&app->m_key.m_data.m_ctr_be_tdes2   , &app->m_schedule.m_data.m_ctr_be_tdes2   ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_tdes2_expand_dec      (&app->m_key.m_data.m_ecb_tdes2      , &app->m_schedule.m_data.m_ecb_tdes2      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes2  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_tdes2_expand_dec      (&app->m_key.m_data.m_ofb_tdes2      , &app->m_schedule.m_data.m_ofb_tdes2      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cbc    )))): mk_lib_crypto_mode_cbc_tdes3_expand_dec      (&app->m_key.m_data.m_cbc_tdes3      , &app->m_schedule.m_data.m_cbc_tdes3      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_128)))): mk_lib_crypto_mode_cfb_64_tdes3_expand_dec   (&app->m_key.m_data.m_cfb_64_tdes3   , &app->m_schedule.m_data.m_cfb_64_tdes3   ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_cfb_8  )))): mk_lib_crypto_mode_cfb_8_tdes3_expand_dec    (&app->m_key.m_data.m_cfb_8_tdes3    , &app->m_schedule.m_data.m_cfb_8_tdes3    ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ctr_be )))): mk_lib_crypto_mode_ctr_be_tdes3_expand_dec   (&app->m_key.m_data.m_ctr_be_tdes3   , &app->m_schedule.m_data.m_ctr_be_tdes3   ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ecb    )))): mk_lib_crypto_mode_ecb_tdes3_expand_dec      (&app->m_key.m_data.m_ecb_tdes3      , &app->m_schedule.m_data.m_ecb_tdes3      ); break;
			case ((int)(((int)(mk_lib_crypto_app_alg_id_e_tdes3  )) * ((int)(mk_lib_crypto_app_mode_id_e_dummy_end)) + ((int)(mk_lib_crypto_app_mode_id_e_ofb    )))): mk_lib_crypto_mode_ofb_tdes3_expand_dec      (&app->m_key.m_data.m_ofb_tdes3      , &app->m_schedule.m_data.m_ofb_tdes3      ); break;
			default: mk_lang_assert(0); break;
		}
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_impl_encrypt_append(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_lang_types_usize_t msg_len mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(app);

	mk_lib_crypto_app_impl_expand_enc(app);
	msg_len = mk_lib_crypto_app_get_msg_len(app->m_alg_id, app->m_mode_id);
	mk_lib_crypto_app_check(len >= 0 && len <= mk_lib_crypto_app_impl_get_data_size(app) + mk_lib_crypto_app_get_msg_size_max_m);
	mk_lib_crypto_app_check(len % msg_len == 0);
	n = len / msg_len;
	for(i = 0; i != (n / 16) * 16; i += 16)
	{
		mk_lib_crypto_app_encrypt_mode_16(app, i * msg_len);
	}
	for(; i != n; ++i)
	{
		mk_lib_crypto_app_encrypt_mode(app, i * msg_len);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_impl_decrypt_append(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_lang_types_usize_t msg_len mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(app);

	mk_lib_crypto_app_impl_expand_dec(app);
	msg_len = mk_lib_crypto_app_get_msg_len(app->m_alg_id, app->m_mode_id);
	mk_lib_crypto_app_check(len >= 0 && len <= mk_lib_crypto_app_impl_get_data_size(app));
	mk_lib_crypto_app_check(len % msg_len == 0);
	n = len / msg_len;
	for(i = 0; i != (n / 16) * 16; i += 16)
	{
		mk_lib_crypto_app_decrypt_mode_16(app, i * msg_len);
	}
	for(; i != n; ++i)
	{
		mk_lib_crypto_app_decrypt_mode(app, i * msg_len);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_impl_encrypt_finish(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept
{
	int msg_len mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t q mk_lang_constexpr_init;
	mk_lang_types_ssize_t r mk_lang_constexpr_init;

	mk_lang_assert(app);

	mk_lib_crypto_app_check(len >= 0 && len <= mk_lib_crypto_app_impl_get_data_size(app));
	msg_len = mk_lib_crypto_app_get_msg_len(app->m_alg_id, app->m_mode_id);
	n = len / msg_len;
	q = len % msg_len;
	switch(app->m_padding_id)
	{
		case mk_lib_crypto_app_padding_id_e_pkcs7:      mk_lib_crypto_padding_pkcs7_pad      (&app->m_buffer.m_data.m_uint8s[len - q], q, msg_len); break;
		case mk_lib_crypto_app_padding_id_e_iso9797pm2: mk_lib_crypto_padding_iso9797pm2_pad (&app->m_buffer.m_data.m_uint8s[len - q], q, msg_len); break;
		default: mk_lang_assert(0); break;
	}
	r = mk_lib_crypto_app_impl_encrypt_append(app, (n + 1) * msg_len); mk_lib_crypto_app_check(r == 0);
	return msg_len - q;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_ssize_t mk_lib_crypto_app_impl_decrypt_finish(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_lang_types_ssize_t r mk_lang_constexpr_init;
	int msg_len mk_lang_constexpr_init;
	int n mk_lang_constexpr_init;

	mk_lang_assert(app);

	mk_lib_crypto_app_check(len >= 1);
	r = mk_lib_crypto_app_impl_decrypt_append(app, len); mk_lib_crypto_app_check(r == 0);
	msg_len = mk_lib_crypto_app_get_msg_len(app->m_alg_id, app->m_mode_id);
	switch(app->m_padding_id)
	{
		case mk_lib_crypto_app_padding_id_e_pkcs7:      mk_lib_crypto_padding_pkcs7_unpad      (&app->m_buffer.m_data.m_uint8s[len - msg_len], msg_len, &n); mk_lib_crypto_app_check(n != -1); break;
		case mk_lib_crypto_app_padding_id_e_iso9797pm2: mk_lib_crypto_padding_iso9797pm2_unpad (&app->m_buffer.m_data.m_uint8s[len - msg_len], msg_len, &n); mk_lib_crypto_app_check(n != -1); break;
		default: mk_lang_assert(0); break;
	}
	return msg_len - n;
}


#undef mk_lib_crypto_app_check


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_cui_uint8_pt    mk_lib_crypto_app_get_data_addr (mk_lib_crypto_app_pt const app)                                  mk_lang_noexcept { return mk_lib_crypto_app_impl_get_data_addr (app);      }
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_lib_crypto_app_get_data_size (mk_lib_crypto_app_pt const app)                                  mk_lang_noexcept { return mk_lib_crypto_app_impl_get_data_size (app);      }
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_get_names     (mk_lib_crypto_app_pt const app)                                  mk_lang_noexcept { return mk_lib_crypto_app_impl_get_names     (app);      }
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_init          (mk_lib_crypto_app_pt const app)                                  mk_lang_noexcept { return mk_lib_crypto_app_impl_init          (app);      }
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_encrypt_append(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_impl_encrypt_append(app, len); }
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_decrypt_append(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_impl_decrypt_append(app, len); }
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_encrypt_finish(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_impl_encrypt_finish(app, len); }
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_ssize_t mk_lib_crypto_app_decrypt_finish(mk_lib_crypto_app_pt const app, mk_lang_types_usize_t const len) mk_lang_noexcept { return mk_lib_crypto_app_impl_decrypt_finish(app, len); }
