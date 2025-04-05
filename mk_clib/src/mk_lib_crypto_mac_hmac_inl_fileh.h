#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


/* RFC 2104 */
/* FIPS PUB 198 */
/* FIPS PUB 198-1 */


#include "mk_lib_crypto_mac_hmac_inl_defd.h"


enum mk_lib_crypto_mac_hmac_inl_defd_digest_len_e{ mk_lib_crypto_mac_hmac_inl_defd_digest_len_v = mk_lib_crypto_mac_hmac_inl_defd_base_digest_len_v }; typedef enum mk_lib_crypto_mac_hmac_inl_defd_digest_len_e mk_lib_crypto_mac_hmac_inl_defd_digest_len_t;

typedef mk_lib_crypto_mac_hmac_inl_defd_base_digest_t mk_lib_crypto_mac_hmac_inl_defd_digest_t; mk_lang_typedef(mk_lib_crypto_mac_hmac_inl_defd_digest);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_crypto_mac_hmac_inl_defd_s
{
	mk_lib_crypto_mac_hmac_inl_defd_base_t m_base;
	mk_lib_crypto_mac_hmac_inl_defd_base_block_t m_opad;
};
typedef struct mk_lib_crypto_mac_hmac_inl_defd_s mk_lib_crypto_mac_hmac_inl_defd_t;
mk_lang_typedef(mk_lib_crypto_mac_hmac_inl_defd);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_inl_defd_init(mk_lib_crypto_mac_hmac_inl_defd_pt const hmac, mk_sl_cui_uint8_pct const key_buf, mk_lang_types_sint_t const key_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_inl_defd_append(mk_lib_crypto_mac_hmac_inl_defd_pt const hmac, mk_sl_cui_uint8_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_inl_defd_finish(mk_lib_crypto_mac_hmac_inl_defd_pt const hmac, mk_lib_crypto_mac_hmac_inl_defd_base_digest_pt const digest) mk_lang_noexcept;


#include "mk_lib_crypto_mac_hmac_inl_defu.h"
