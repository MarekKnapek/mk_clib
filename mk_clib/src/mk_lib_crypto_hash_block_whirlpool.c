#include "mk_lib_crypto_hash_block_whirlpool.h"

/* http://www.larc.usp.br/~pbarreto/WhirlpoolPage.html */
/* http://www.larc.usp.br/~pbarreto/whirlpool.zip */

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#define mk_sl_cui_t_name mk_lib_crypto_hash_block_whirlpool_uint256
#define mk_sl_cui_t_base mk_sl_cui_uint64
#define mk_sl_cui_t_count 4
#include "mk_sl_cui_inl_filec.h"


#define mk_sl_cui_uint64_cc(a, b) mk_sl_cui_uint64_c \
( \
	( \
		((((b) >> (0 * 8)) & 0xfful) << (3 * 8)) | \
		((((b) >> (1 * 8)) & 0xfful) << (2 * 8)) | \
		((((b) >> (2 * 8)) & 0xfful) << (1 * 8)) | \
		((((b) >> (3 * 8)) & 0xfful) << (0 * 8)) \
	), \
	( \
		((((a) >> (0 * 8)) & 0xfful) << (3 * 8)) | \
		((((a) >> (1 * 8)) & 0xfful) << (2 * 8)) | \
		((((a) >> (2 * 8)) & 0xfful) << (1 * 8)) | \
		((((a) >> (3 * 8)) & 0xfful) << (0 * 8)) \
	) \
)


struct mk_lib_crypto_hash_block_whirlpool_table_data_s
{
	mk_sl_cui_uint64_t m_uint64s[0xff + 0x01];
};
typedef struct mk_lib_crypto_hash_block_whirlpool_table_data_s mk_lib_crypto_hash_block_whirlpool_table_data_t;

struct mk_lib_crypto_hash_block_whirlpool_table_s
{
	mk_lang_alignas(64) mk_lib_crypto_hash_block_whirlpool_table_data_t m_data;
};
typedef struct mk_lib_crypto_hash_block_whirlpool_table_s mk_lib_crypto_hash_block_whirlpool_table_t;

struct mk_lib_crypto_hash_block_whirlpool_tables_s
{
	mk_lib_crypto_hash_block_whirlpool_table_t m_data[8];
};
typedef struct mk_lib_crypto_hash_block_whirlpool_tables_s mk_lib_crypto_hash_block_whirlpool_tables_t;


#define s_mk_lib_crypto_hash_block_whirlpool_nrounds 10

mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_whirlpool_tables_t const s_mk_lib_crypto_hash_block_whirlpool_tables =
{{
	{{{
		mk_sl_cui_uint64_cc(0x18186018ul, 0xc07830d8ul), mk_sl_cui_uint64_cc(0x23238c23ul, 0x05af4626ul), mk_sl_cui_uint64_cc(0xc6c63fc6ul, 0x7ef991b8ul), mk_sl_cui_uint64_cc(0xe8e887e8ul, 0x136fcdfbul),
		mk_sl_cui_uint64_cc(0x87872687ul, 0x4ca113cbul), mk_sl_cui_uint64_cc(0xb8b8dab8ul, 0xa9626d11ul), mk_sl_cui_uint64_cc(0x01010401ul, 0x08050209ul), mk_sl_cui_uint64_cc(0x4f4f214ful, 0x426e9e0dul),
		mk_sl_cui_uint64_cc(0x3636d836ul, 0xadee6c9bul), mk_sl_cui_uint64_cc(0xa6a6a2a6ul, 0x590451fful), mk_sl_cui_uint64_cc(0xd2d26fd2ul, 0xdebdb90cul), mk_sl_cui_uint64_cc(0xf5f5f3f5ul, 0xfb06f70eul),
		mk_sl_cui_uint64_cc(0x7979f979ul, 0xef80f296ul), mk_sl_cui_uint64_cc(0x6f6fa16ful, 0x5fcede30ul), mk_sl_cui_uint64_cc(0x91917e91ul, 0xfcef3f6dul), mk_sl_cui_uint64_cc(0x52525552ul, 0xaa07a4f8ul),
		mk_sl_cui_uint64_cc(0x60609d60ul, 0x27fdc047ul), mk_sl_cui_uint64_cc(0xbcbccabcul, 0x89766535ul), mk_sl_cui_uint64_cc(0x9b9b569bul, 0xaccd2b37ul), mk_sl_cui_uint64_cc(0x8e8e028eul, 0x048c018aul),
		mk_sl_cui_uint64_cc(0xa3a3b6a3ul, 0x71155bd2ul), mk_sl_cui_uint64_cc(0x0c0c300cul, 0x603c186cul), mk_sl_cui_uint64_cc(0x7b7bf17bul, 0xff8af684ul), mk_sl_cui_uint64_cc(0x3535d435ul, 0xb5e16a80ul),
		mk_sl_cui_uint64_cc(0x1d1d741dul, 0xe8693af5ul), mk_sl_cui_uint64_cc(0xe0e0a7e0ul, 0x5347ddb3ul), mk_sl_cui_uint64_cc(0xd7d77bd7ul, 0xf6acb321ul), mk_sl_cui_uint64_cc(0xc2c22fc2ul, 0x5eed999cul),
		mk_sl_cui_uint64_cc(0x2e2eb82eul, 0x6d965c43ul), mk_sl_cui_uint64_cc(0x4b4b314bul, 0x627a9629ul), mk_sl_cui_uint64_cc(0xfefedffeul, 0xa321e15dul), mk_sl_cui_uint64_cc(0x57574157ul, 0x8216aed5ul),
		mk_sl_cui_uint64_cc(0x15155415ul, 0xa8412abdul), mk_sl_cui_uint64_cc(0x7777c177ul, 0x9fb6eee8ul), mk_sl_cui_uint64_cc(0x3737dc37ul, 0xa5eb6e92ul), mk_sl_cui_uint64_cc(0xe5e5b3e5ul, 0x7b56d79eul),
		mk_sl_cui_uint64_cc(0x9f9f469ful, 0x8cd92313ul), mk_sl_cui_uint64_cc(0xf0f0e7f0ul, 0xd317fd23ul), mk_sl_cui_uint64_cc(0x4a4a354aul, 0x6a7f9420ul), mk_sl_cui_uint64_cc(0xdada4fdaul, 0x9e95a944ul),
		mk_sl_cui_uint64_cc(0x58587d58ul, 0xfa25b0a2ul), mk_sl_cui_uint64_cc(0xc9c903c9ul, 0x06ca8fcful), mk_sl_cui_uint64_cc(0x2929a429ul, 0x558d527cul), mk_sl_cui_uint64_cc(0x0a0a280aul, 0x5022145aul),
		mk_sl_cui_uint64_cc(0xb1b1feb1ul, 0xe14f7f50ul), mk_sl_cui_uint64_cc(0xa0a0baa0ul, 0x691a5dc9ul), mk_sl_cui_uint64_cc(0x6b6bb16bul, 0x7fdad614ul), mk_sl_cui_uint64_cc(0x85852e85ul, 0x5cab17d9ul),
		mk_sl_cui_uint64_cc(0xbdbdcebdul, 0x8173673cul), mk_sl_cui_uint64_cc(0x5d5d695dul, 0xd234ba8ful), mk_sl_cui_uint64_cc(0x10104010ul, 0x80502090ul), mk_sl_cui_uint64_cc(0xf4f4f7f4ul, 0xf303f507ul),
		mk_sl_cui_uint64_cc(0xcbcb0bcbul, 0x16c08bddul), mk_sl_cui_uint64_cc(0x3e3ef83eul, 0xedc67cd3ul), mk_sl_cui_uint64_cc(0x05051405ul, 0x28110a2dul), mk_sl_cui_uint64_cc(0x67678167ul, 0x1fe6ce78ul),
		mk_sl_cui_uint64_cc(0xe4e4b7e4ul, 0x7353d597ul), mk_sl_cui_uint64_cc(0x27279c27ul, 0x25bb4e02ul), mk_sl_cui_uint64_cc(0x41411941ul, 0x32588273ul), mk_sl_cui_uint64_cc(0x8b8b168bul, 0x2c9d0ba7ul),
		mk_sl_cui_uint64_cc(0xa7a7a6a7ul, 0x510153f6ul), mk_sl_cui_uint64_cc(0x7d7de97dul, 0xcf94fab2ul), mk_sl_cui_uint64_cc(0x95956e95ul, 0xdcfb3749ul), mk_sl_cui_uint64_cc(0xd8d847d8ul, 0x8e9fad56ul),
		mk_sl_cui_uint64_cc(0xfbfbcbfbul, 0x8b30eb70ul), mk_sl_cui_uint64_cc(0xeeee9feeul, 0x2371c1cdul), mk_sl_cui_uint64_cc(0x7c7ced7cul, 0xc791f8bbul), mk_sl_cui_uint64_cc(0x66668566ul, 0x17e3cc71ul),
		mk_sl_cui_uint64_cc(0xdddd53ddul, 0xa68ea77bul), mk_sl_cui_uint64_cc(0x17175c17ul, 0xb84b2eaful), mk_sl_cui_uint64_cc(0x47470147ul, 0x02468e45ul), mk_sl_cui_uint64_cc(0x9e9e429eul, 0x84dc211aul),
		mk_sl_cui_uint64_cc(0xcaca0fcaul, 0x1ec589d4ul), mk_sl_cui_uint64_cc(0x2d2db42dul, 0x75995a58ul), mk_sl_cui_uint64_cc(0xbfbfc6bful, 0x9179632eul), mk_sl_cui_uint64_cc(0x07071c07ul, 0x381b0e3ful),
		mk_sl_cui_uint64_cc(0xadad8eadul, 0x012347acul), mk_sl_cui_uint64_cc(0x5a5a755aul, 0xea2fb4b0ul), mk_sl_cui_uint64_cc(0x83833683ul, 0x6cb51beful), mk_sl_cui_uint64_cc(0x3333cc33ul, 0x85ff66b6ul),
		mk_sl_cui_uint64_cc(0x63639163ul, 0x3ff2c65cul), mk_sl_cui_uint64_cc(0x02020802ul, 0x100a0412ul), mk_sl_cui_uint64_cc(0xaaaa92aaul, 0x39384993ul), mk_sl_cui_uint64_cc(0x7171d971ul, 0xafa8e2deul),
		mk_sl_cui_uint64_cc(0xc8c807c8ul, 0x0ecf8dc6ul), mk_sl_cui_uint64_cc(0x19196419ul, 0xc87d32d1ul), mk_sl_cui_uint64_cc(0x49493949ul, 0x7270923bul), mk_sl_cui_uint64_cc(0xd9d943d9ul, 0x869aaf5ful),
		mk_sl_cui_uint64_cc(0xf2f2eff2ul, 0xc31df931ul), mk_sl_cui_uint64_cc(0xe3e3abe3ul, 0x4b48dba8ul), mk_sl_cui_uint64_cc(0x5b5b715bul, 0xe22ab6b9ul), mk_sl_cui_uint64_cc(0x88881a88ul, 0x34920dbcul),
		mk_sl_cui_uint64_cc(0x9a9a529aul, 0xa4c8293eul), mk_sl_cui_uint64_cc(0x26269826ul, 0x2dbe4c0bul), mk_sl_cui_uint64_cc(0x3232c832ul, 0x8dfa64bful), mk_sl_cui_uint64_cc(0xb0b0fab0ul, 0xe94a7d59ul),
		mk_sl_cui_uint64_cc(0xe9e983e9ul, 0x1b6acff2ul), mk_sl_cui_uint64_cc(0x0f0f3c0ful, 0x78331e77ul), mk_sl_cui_uint64_cc(0xd5d573d5ul, 0xe6a6b733ul), mk_sl_cui_uint64_cc(0x80803a80ul, 0x74ba1df4ul),
		mk_sl_cui_uint64_cc(0xbebec2beul, 0x997c6127ul), mk_sl_cui_uint64_cc(0xcdcd13cdul, 0x26de87ebul), mk_sl_cui_uint64_cc(0x3434d034ul, 0xbde46889ul), mk_sl_cui_uint64_cc(0x48483d48ul, 0x7a759032ul),
		mk_sl_cui_uint64_cc(0xffffdbfful, 0xab24e354ul), mk_sl_cui_uint64_cc(0x7a7af57aul, 0xf78ff48dul), mk_sl_cui_uint64_cc(0x90907a90ul, 0xf4ea3d64ul), mk_sl_cui_uint64_cc(0x5f5f615ful, 0xc23ebe9dul),
		mk_sl_cui_uint64_cc(0x20208020ul, 0x1da0403dul), mk_sl_cui_uint64_cc(0x6868bd68ul, 0x67d5d00ful), mk_sl_cui_uint64_cc(0x1a1a681aul, 0xd07234caul), mk_sl_cui_uint64_cc(0xaeae82aeul, 0x192c41b7ul),
		mk_sl_cui_uint64_cc(0xb4b4eab4ul, 0xc95e757dul), mk_sl_cui_uint64_cc(0x54544d54ul, 0x9a19a8ceul), mk_sl_cui_uint64_cc(0x93937693ul, 0xece53b7ful), mk_sl_cui_uint64_cc(0x22228822ul, 0x0daa442ful),
		mk_sl_cui_uint64_cc(0x64648d64ul, 0x07e9c863ul), mk_sl_cui_uint64_cc(0xf1f1e3f1ul, 0xdb12ff2aul), mk_sl_cui_uint64_cc(0x7373d173ul, 0xbfa2e6ccul), mk_sl_cui_uint64_cc(0x12124812ul, 0x905a2482ul),
		mk_sl_cui_uint64_cc(0x40401d40ul, 0x3a5d807aul), mk_sl_cui_uint64_cc(0x08082008ul, 0x40281048ul), mk_sl_cui_uint64_cc(0xc3c32bc3ul, 0x56e89b95ul), mk_sl_cui_uint64_cc(0xecec97ecul, 0x337bc5dful),
		mk_sl_cui_uint64_cc(0xdbdb4bdbul, 0x9690ab4dul), mk_sl_cui_uint64_cc(0xa1a1bea1ul, 0x611f5fc0ul), mk_sl_cui_uint64_cc(0x8d8d0e8dul, 0x1c830791ul), mk_sl_cui_uint64_cc(0x3d3df43dul, 0xf5c97ac8ul),
		mk_sl_cui_uint64_cc(0x97976697ul, 0xccf1335bul), mk_sl_cui_uint64_cc(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_cc(0xcfcf1bcful, 0x36d483f9ul), mk_sl_cui_uint64_cc(0x2b2bac2bul, 0x4587566eul),
		mk_sl_cui_uint64_cc(0x7676c576ul, 0x97b3ece1ul), mk_sl_cui_uint64_cc(0x82823282ul, 0x64b019e6ul), mk_sl_cui_uint64_cc(0xd6d67fd6ul, 0xfea9b128ul), mk_sl_cui_uint64_cc(0x1b1b6c1bul, 0xd87736c3ul),
		mk_sl_cui_uint64_cc(0xb5b5eeb5ul, 0xc15b7774ul), mk_sl_cui_uint64_cc(0xafaf86aful, 0x112943beul), mk_sl_cui_uint64_cc(0x6a6ab56aul, 0x77dfd41dul), mk_sl_cui_uint64_cc(0x50505d50ul, 0xba0da0eaul),
		mk_sl_cui_uint64_cc(0x45450945ul, 0x124c8a57ul), mk_sl_cui_uint64_cc(0xf3f3ebf3ul, 0xcb18fb38ul), mk_sl_cui_uint64_cc(0x3030c030ul, 0x9df060adul), mk_sl_cui_uint64_cc(0xefef9beful, 0x2b74c3c4ul),
		mk_sl_cui_uint64_cc(0x3f3ffc3ful, 0xe5c37edaul), mk_sl_cui_uint64_cc(0x55554955ul, 0x921caac7ul), mk_sl_cui_uint64_cc(0xa2a2b2a2ul, 0x791059dbul), mk_sl_cui_uint64_cc(0xeaea8feaul, 0x0365c9e9ul),
		mk_sl_cui_uint64_cc(0x65658965ul, 0x0fecca6aul), mk_sl_cui_uint64_cc(0xbabad2baul, 0xb9686903ul), mk_sl_cui_uint64_cc(0x2f2fbc2ful, 0x65935e4aul), mk_sl_cui_uint64_cc(0xc0c027c0ul, 0x4ee79d8eul),
		mk_sl_cui_uint64_cc(0xdede5fdeul, 0xbe81a160ul), mk_sl_cui_uint64_cc(0x1c1c701cul, 0xe06c38fcul), mk_sl_cui_uint64_cc(0xfdfdd3fdul, 0xbb2ee746ul), mk_sl_cui_uint64_cc(0x4d4d294dul, 0x52649a1ful),
		mk_sl_cui_uint64_cc(0x92927292ul, 0xe4e03976ul), mk_sl_cui_uint64_cc(0x7575c975ul, 0x8fbceafaul), mk_sl_cui_uint64_cc(0x06061806ul, 0x301e0c36ul), mk_sl_cui_uint64_cc(0x8a8a128aul, 0x249809aeul),
		mk_sl_cui_uint64_cc(0xb2b2f2b2ul, 0xf940794bul), mk_sl_cui_uint64_cc(0xe6e6bfe6ul, 0x6359d185ul), mk_sl_cui_uint64_cc(0x0e0e380eul, 0x70361c7eul), mk_sl_cui_uint64_cc(0x1f1f7c1ful, 0xf8633ee7ul),
		mk_sl_cui_uint64_cc(0x62629562ul, 0x37f7c455ul), mk_sl_cui_uint64_cc(0xd4d477d4ul, 0xeea3b53aul), mk_sl_cui_uint64_cc(0xa8a89aa8ul, 0x29324d81ul), mk_sl_cui_uint64_cc(0x96966296ul, 0xc4f43152ul),
		mk_sl_cui_uint64_cc(0xf9f9c3f9ul, 0x9b3aef62ul), mk_sl_cui_uint64_cc(0xc5c533c5ul, 0x66f697a3ul), mk_sl_cui_uint64_cc(0x25259425ul, 0x35b14a10ul), mk_sl_cui_uint64_cc(0x59597959ul, 0xf220b2abul),
		mk_sl_cui_uint64_cc(0x84842a84ul, 0x54ae15d0ul), mk_sl_cui_uint64_cc(0x7272d572ul, 0xb7a7e4c5ul), mk_sl_cui_uint64_cc(0x3939e439ul, 0xd5dd72ecul), mk_sl_cui_uint64_cc(0x4c4c2d4cul, 0x5a619816ul),
		mk_sl_cui_uint64_cc(0x5e5e655eul, 0xca3bbc94ul), mk_sl_cui_uint64_cc(0x7878fd78ul, 0xe785f09ful), mk_sl_cui_uint64_cc(0x3838e038ul, 0xddd870e5ul), mk_sl_cui_uint64_cc(0x8c8c0a8cul, 0x14860598ul),
		mk_sl_cui_uint64_cc(0xd1d163d1ul, 0xc6b2bf17ul), mk_sl_cui_uint64_cc(0xa5a5aea5ul, 0x410b57e4ul), mk_sl_cui_uint64_cc(0xe2e2afe2ul, 0x434dd9a1ul), mk_sl_cui_uint64_cc(0x61619961ul, 0x2ff8c24eul),
		mk_sl_cui_uint64_cc(0xb3b3f6b3ul, 0xf1457b42ul), mk_sl_cui_uint64_cc(0x21218421ul, 0x15a54234ul), mk_sl_cui_uint64_cc(0x9c9c4a9cul, 0x94d62508ul), mk_sl_cui_uint64_cc(0x1e1e781eul, 0xf0663ceeul),
		mk_sl_cui_uint64_cc(0x43431143ul, 0x22528661ul), mk_sl_cui_uint64_cc(0xc7c73bc7ul, 0x76fc93b1ul), mk_sl_cui_uint64_cc(0xfcfcd7fcul, 0xb32be54ful), mk_sl_cui_uint64_cc(0x04041004ul, 0x20140824ul),
		mk_sl_cui_uint64_cc(0x51515951ul, 0xb208a2e3ul), mk_sl_cui_uint64_cc(0x99995e99ul, 0xbcc72f25ul), mk_sl_cui_uint64_cc(0x6d6da96dul, 0x4fc4da22ul), mk_sl_cui_uint64_cc(0x0d0d340dul, 0x68391a65ul),
		mk_sl_cui_uint64_cc(0xfafacffaul, 0x8335e979ul), mk_sl_cui_uint64_cc(0xdfdf5bdful, 0xb684a369ul), mk_sl_cui_uint64_cc(0x7e7ee57eul, 0xd79bfca9ul), mk_sl_cui_uint64_cc(0x24249024ul, 0x3db44819ul),
		mk_sl_cui_uint64_cc(0x3b3bec3bul, 0xc5d776feul), mk_sl_cui_uint64_cc(0xabab96abul, 0x313d4b9aul), mk_sl_cui_uint64_cc(0xcece1fceul, 0x3ed181f0ul), mk_sl_cui_uint64_cc(0x11114411ul, 0x88552299ul),
		mk_sl_cui_uint64_cc(0x8f8f068ful, 0x0c890383ul), mk_sl_cui_uint64_cc(0x4e4e254eul, 0x4a6b9c04ul), mk_sl_cui_uint64_cc(0xb7b7e6b7ul, 0xd1517366ul), mk_sl_cui_uint64_cc(0xebeb8bebul, 0x0b60cbe0ul),
		mk_sl_cui_uint64_cc(0x3c3cf03cul, 0xfdcc78c1ul), mk_sl_cui_uint64_cc(0x81813e81ul, 0x7cbf1ffdul), mk_sl_cui_uint64_cc(0x94946a94ul, 0xd4fe3540ul), mk_sl_cui_uint64_cc(0xf7f7fbf7ul, 0xeb0cf31cul),
		mk_sl_cui_uint64_cc(0xb9b9deb9ul, 0xa1676f18ul), mk_sl_cui_uint64_cc(0x13134c13ul, 0x985f268bul), mk_sl_cui_uint64_cc(0x2c2cb02cul, 0x7d9c5851ul), mk_sl_cui_uint64_cc(0xd3d36bd3ul, 0xd6b8bb05ul),
		mk_sl_cui_uint64_cc(0xe7e7bbe7ul, 0x6b5cd38cul), mk_sl_cui_uint64_cc(0x6e6ea56eul, 0x57cbdc39ul), mk_sl_cui_uint64_cc(0xc4c437c4ul, 0x6ef395aaul), mk_sl_cui_uint64_cc(0x03030c03ul, 0x180f061bul),
		mk_sl_cui_uint64_cc(0x56564556ul, 0x8a13acdcul), mk_sl_cui_uint64_cc(0x44440d44ul, 0x1a49885eul), mk_sl_cui_uint64_cc(0x7f7fe17ful, 0xdf9efea0ul), mk_sl_cui_uint64_cc(0xa9a99ea9ul, 0x21374f88ul),
		mk_sl_cui_uint64_cc(0x2a2aa82aul, 0x4d825467ul), mk_sl_cui_uint64_cc(0xbbbbd6bbul, 0xb16d6b0aul), mk_sl_cui_uint64_cc(0xc1c123c1ul, 0x46e29f87ul), mk_sl_cui_uint64_cc(0x53535153ul, 0xa202a6f1ul),
		mk_sl_cui_uint64_cc(0xdcdc57dcul, 0xae8ba572ul), mk_sl_cui_uint64_cc(0x0b0b2c0bul, 0x58271653ul), mk_sl_cui_uint64_cc(0x9d9d4e9dul, 0x9cd32701ul), mk_sl_cui_uint64_cc(0x6c6cad6cul, 0x47c1d82bul),
		mk_sl_cui_uint64_cc(0x3131c431ul, 0x95f562a4ul), mk_sl_cui_uint64_cc(0x7474cd74ul, 0x87b9e8f3ul), mk_sl_cui_uint64_cc(0xf6f6fff6ul, 0xe309f115ul), mk_sl_cui_uint64_cc(0x46460546ul, 0x0a438c4cul),
		mk_sl_cui_uint64_cc(0xacac8aacul, 0x092645a5ul), mk_sl_cui_uint64_cc(0x89891e89ul, 0x3c970fb5ul), mk_sl_cui_uint64_cc(0x14145014ul, 0xa04428b4ul), mk_sl_cui_uint64_cc(0xe1e1a3e1ul, 0x5b42dfbaul),
		mk_sl_cui_uint64_cc(0x16165816ul, 0xb04e2ca6ul), mk_sl_cui_uint64_cc(0x3a3ae83aul, 0xcdd274f7ul), mk_sl_cui_uint64_cc(0x6969b969ul, 0x6fd0d206ul), mk_sl_cui_uint64_cc(0x09092409ul, 0x482d1241ul),
		mk_sl_cui_uint64_cc(0x7070dd70ul, 0xa7ade0d7ul), mk_sl_cui_uint64_cc(0xb6b6e2b6ul, 0xd954716ful), mk_sl_cui_uint64_cc(0xd0d067d0ul, 0xceb7bd1eul), mk_sl_cui_uint64_cc(0xeded93edul, 0x3b7ec7d6ul),
		mk_sl_cui_uint64_cc(0xcccc17ccul, 0x2edb85e2ul), mk_sl_cui_uint64_cc(0x42421542ul, 0x2a578468ul), mk_sl_cui_uint64_cc(0x98985a98ul, 0xb4c22d2cul), mk_sl_cui_uint64_cc(0xa4a4aaa4ul, 0x490e55edul),
		mk_sl_cui_uint64_cc(0x2828a028ul, 0x5d885075ul), mk_sl_cui_uint64_cc(0x5c5c6d5cul, 0xda31b886ul), mk_sl_cui_uint64_cc(0xf8f8c7f8ul, 0x933fed6bul), mk_sl_cui_uint64_cc(0x86862286ul, 0x44a411c2ul),
	}}},
	{{{
		mk_sl_cui_uint64_cc(0xd8181860ul, 0x18c07830ul), mk_sl_cui_uint64_cc(0x2623238cul, 0x2305af46ul), mk_sl_cui_uint64_cc(0xb8c6c63ful, 0xc67ef991ul), mk_sl_cui_uint64_cc(0xfbe8e887ul, 0xe8136fcdul),
		mk_sl_cui_uint64_cc(0xcb878726ul, 0x874ca113ul), mk_sl_cui_uint64_cc(0x11b8b8daul, 0xb8a9626dul), mk_sl_cui_uint64_cc(0x09010104ul, 0x01080502ul), mk_sl_cui_uint64_cc(0x0d4f4f21ul, 0x4f426e9eul),
		mk_sl_cui_uint64_cc(0x9b3636d8ul, 0x36adee6cul), mk_sl_cui_uint64_cc(0xffa6a6a2ul, 0xa6590451ul), mk_sl_cui_uint64_cc(0x0cd2d26ful, 0xd2debdb9ul), mk_sl_cui_uint64_cc(0x0ef5f5f3ul, 0xf5fb06f7ul),
		mk_sl_cui_uint64_cc(0x967979f9ul, 0x79ef80f2ul), mk_sl_cui_uint64_cc(0x306f6fa1ul, 0x6f5fcedeul), mk_sl_cui_uint64_cc(0x6d91917eul, 0x91fcef3ful), mk_sl_cui_uint64_cc(0xf8525255ul, 0x52aa07a4ul),
		mk_sl_cui_uint64_cc(0x4760609dul, 0x6027fdc0ul), mk_sl_cui_uint64_cc(0x35bcbccaul, 0xbc897665ul), mk_sl_cui_uint64_cc(0x379b9b56ul, 0x9baccd2bul), mk_sl_cui_uint64_cc(0x8a8e8e02ul, 0x8e048c01ul),
		mk_sl_cui_uint64_cc(0xd2a3a3b6ul, 0xa371155bul), mk_sl_cui_uint64_cc(0x6c0c0c30ul, 0x0c603c18ul), mk_sl_cui_uint64_cc(0x847b7bf1ul, 0x7bff8af6ul), mk_sl_cui_uint64_cc(0x803535d4ul, 0x35b5e16aul),
		mk_sl_cui_uint64_cc(0xf51d1d74ul, 0x1de8693aul), mk_sl_cui_uint64_cc(0xb3e0e0a7ul, 0xe05347ddul), mk_sl_cui_uint64_cc(0x21d7d77bul, 0xd7f6acb3ul), mk_sl_cui_uint64_cc(0x9cc2c22ful, 0xc25eed99ul),
		mk_sl_cui_uint64_cc(0x432e2eb8ul, 0x2e6d965cul), mk_sl_cui_uint64_cc(0x294b4b31ul, 0x4b627a96ul), mk_sl_cui_uint64_cc(0x5dfefedful, 0xfea321e1ul), mk_sl_cui_uint64_cc(0xd5575741ul, 0x578216aeul),
		mk_sl_cui_uint64_cc(0xbd151554ul, 0x15a8412aul), mk_sl_cui_uint64_cc(0xe87777c1ul, 0x779fb6eeul), mk_sl_cui_uint64_cc(0x923737dcul, 0x37a5eb6eul), mk_sl_cui_uint64_cc(0x9ee5e5b3ul, 0xe57b56d7ul),
		mk_sl_cui_uint64_cc(0x139f9f46ul, 0x9f8cd923ul), mk_sl_cui_uint64_cc(0x23f0f0e7ul, 0xf0d317fdul), mk_sl_cui_uint64_cc(0x204a4a35ul, 0x4a6a7f94ul), mk_sl_cui_uint64_cc(0x44dada4ful, 0xda9e95a9ul),
		mk_sl_cui_uint64_cc(0xa258587dul, 0x58fa25b0ul), mk_sl_cui_uint64_cc(0xcfc9c903ul, 0xc906ca8ful), mk_sl_cui_uint64_cc(0x7c2929a4ul, 0x29558d52ul), mk_sl_cui_uint64_cc(0x5a0a0a28ul, 0x0a502214ul),
		mk_sl_cui_uint64_cc(0x50b1b1feul, 0xb1e14f7ful), mk_sl_cui_uint64_cc(0xc9a0a0baul, 0xa0691a5dul), mk_sl_cui_uint64_cc(0x146b6bb1ul, 0x6b7fdad6ul), mk_sl_cui_uint64_cc(0xd985852eul, 0x855cab17ul),
		mk_sl_cui_uint64_cc(0x3cbdbdceul, 0xbd817367ul), mk_sl_cui_uint64_cc(0x8f5d5d69ul, 0x5dd234baul), mk_sl_cui_uint64_cc(0x90101040ul, 0x10805020ul), mk_sl_cui_uint64_cc(0x07f4f4f7ul, 0xf4f303f5ul),
		mk_sl_cui_uint64_cc(0xddcbcb0bul, 0xcb16c08bul), mk_sl_cui_uint64_cc(0xd33e3ef8ul, 0x3eedc67cul), mk_sl_cui_uint64_cc(0x2d050514ul, 0x0528110aul), mk_sl_cui_uint64_cc(0x78676781ul, 0x671fe6ceul),
		mk_sl_cui_uint64_cc(0x97e4e4b7ul, 0xe47353d5ul), mk_sl_cui_uint64_cc(0x0227279cul, 0x2725bb4eul), mk_sl_cui_uint64_cc(0x73414119ul, 0x41325882ul), mk_sl_cui_uint64_cc(0xa78b8b16ul, 0x8b2c9d0bul),
		mk_sl_cui_uint64_cc(0xf6a7a7a6ul, 0xa7510153ul), mk_sl_cui_uint64_cc(0xb27d7de9ul, 0x7dcf94faul), mk_sl_cui_uint64_cc(0x4995956eul, 0x95dcfb37ul), mk_sl_cui_uint64_cc(0x56d8d847ul, 0xd88e9fadul),
		mk_sl_cui_uint64_cc(0x70fbfbcbul, 0xfb8b30ebul), mk_sl_cui_uint64_cc(0xcdeeee9ful, 0xee2371c1ul), mk_sl_cui_uint64_cc(0xbb7c7cedul, 0x7cc791f8ul), mk_sl_cui_uint64_cc(0x71666685ul, 0x6617e3ccul),
		mk_sl_cui_uint64_cc(0x7bdddd53ul, 0xdda68ea7ul), mk_sl_cui_uint64_cc(0xaf17175cul, 0x17b84b2eul), mk_sl_cui_uint64_cc(0x45474701ul, 0x4702468eul), mk_sl_cui_uint64_cc(0x1a9e9e42ul, 0x9e84dc21ul),
		mk_sl_cui_uint64_cc(0xd4caca0ful, 0xca1ec589ul), mk_sl_cui_uint64_cc(0x582d2db4ul, 0x2d75995aul), mk_sl_cui_uint64_cc(0x2ebfbfc6ul, 0xbf917963ul), mk_sl_cui_uint64_cc(0x3f07071cul, 0x07381b0eul),
		mk_sl_cui_uint64_cc(0xacadad8eul, 0xad012347ul), mk_sl_cui_uint64_cc(0xb05a5a75ul, 0x5aea2fb4ul), mk_sl_cui_uint64_cc(0xef838336ul, 0x836cb51bul), mk_sl_cui_uint64_cc(0xb63333ccul, 0x3385ff66ul),
		mk_sl_cui_uint64_cc(0x5c636391ul, 0x633ff2c6ul), mk_sl_cui_uint64_cc(0x12020208ul, 0x02100a04ul), mk_sl_cui_uint64_cc(0x93aaaa92ul, 0xaa393849ul), mk_sl_cui_uint64_cc(0xde7171d9ul, 0x71afa8e2ul),
		mk_sl_cui_uint64_cc(0xc6c8c807ul, 0xc80ecf8dul), mk_sl_cui_uint64_cc(0xd1191964ul, 0x19c87d32ul), mk_sl_cui_uint64_cc(0x3b494939ul, 0x49727092ul), mk_sl_cui_uint64_cc(0x5fd9d943ul, 0xd9869aaful),
		mk_sl_cui_uint64_cc(0x31f2f2eful, 0xf2c31df9ul), mk_sl_cui_uint64_cc(0xa8e3e3abul, 0xe34b48dbul), mk_sl_cui_uint64_cc(0xb95b5b71ul, 0x5be22ab6ul), mk_sl_cui_uint64_cc(0xbc88881aul, 0x8834920dul),
		mk_sl_cui_uint64_cc(0x3e9a9a52ul, 0x9aa4c829ul), mk_sl_cui_uint64_cc(0x0b262698ul, 0x262dbe4cul), mk_sl_cui_uint64_cc(0xbf3232c8ul, 0x328dfa64ul), mk_sl_cui_uint64_cc(0x59b0b0faul, 0xb0e94a7dul),
		mk_sl_cui_uint64_cc(0xf2e9e983ul, 0xe91b6acful), mk_sl_cui_uint64_cc(0x770f0f3cul, 0x0f78331eul), mk_sl_cui_uint64_cc(0x33d5d573ul, 0xd5e6a6b7ul), mk_sl_cui_uint64_cc(0xf480803aul, 0x8074ba1dul),
		mk_sl_cui_uint64_cc(0x27bebec2ul, 0xbe997c61ul), mk_sl_cui_uint64_cc(0xebcdcd13ul, 0xcd26de87ul), mk_sl_cui_uint64_cc(0x893434d0ul, 0x34bde468ul), mk_sl_cui_uint64_cc(0x3248483dul, 0x487a7590ul),
		mk_sl_cui_uint64_cc(0x54ffffdbul, 0xffab24e3ul), mk_sl_cui_uint64_cc(0x8d7a7af5ul, 0x7af78ff4ul), mk_sl_cui_uint64_cc(0x6490907aul, 0x90f4ea3dul), mk_sl_cui_uint64_cc(0x9d5f5f61ul, 0x5fc23ebeul),
		mk_sl_cui_uint64_cc(0x3d202080ul, 0x201da040ul), mk_sl_cui_uint64_cc(0x0f6868bdul, 0x6867d5d0ul), mk_sl_cui_uint64_cc(0xca1a1a68ul, 0x1ad07234ul), mk_sl_cui_uint64_cc(0xb7aeae82ul, 0xae192c41ul),
		mk_sl_cui_uint64_cc(0x7db4b4eaul, 0xb4c95e75ul), mk_sl_cui_uint64_cc(0xce54544dul, 0x549a19a8ul), mk_sl_cui_uint64_cc(0x7f939376ul, 0x93ece53bul), mk_sl_cui_uint64_cc(0x2f222288ul, 0x220daa44ul),
		mk_sl_cui_uint64_cc(0x6364648dul, 0x6407e9c8ul), mk_sl_cui_uint64_cc(0x2af1f1e3ul, 0xf1db12fful), mk_sl_cui_uint64_cc(0xcc7373d1ul, 0x73bfa2e6ul), mk_sl_cui_uint64_cc(0x82121248ul, 0x12905a24ul),
		mk_sl_cui_uint64_cc(0x7a40401dul, 0x403a5d80ul), mk_sl_cui_uint64_cc(0x48080820ul, 0x08402810ul), mk_sl_cui_uint64_cc(0x95c3c32bul, 0xc356e89bul), mk_sl_cui_uint64_cc(0xdfecec97ul, 0xec337bc5ul),
		mk_sl_cui_uint64_cc(0x4ddbdb4bul, 0xdb9690abul), mk_sl_cui_uint64_cc(0xc0a1a1beul, 0xa1611f5ful), mk_sl_cui_uint64_cc(0x918d8d0eul, 0x8d1c8307ul), mk_sl_cui_uint64_cc(0xc83d3df4ul, 0x3df5c97aul),
		mk_sl_cui_uint64_cc(0x5b979766ul, 0x97ccf133ul), mk_sl_cui_uint64_cc(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_cc(0xf9cfcf1bul, 0xcf36d483ul), mk_sl_cui_uint64_cc(0x6e2b2bacul, 0x2b458756ul),
		mk_sl_cui_uint64_cc(0xe17676c5ul, 0x7697b3ecul), mk_sl_cui_uint64_cc(0xe6828232ul, 0x8264b019ul), mk_sl_cui_uint64_cc(0x28d6d67ful, 0xd6fea9b1ul), mk_sl_cui_uint64_cc(0xc31b1b6cul, 0x1bd87736ul),
		mk_sl_cui_uint64_cc(0x74b5b5eeul, 0xb5c15b77ul), mk_sl_cui_uint64_cc(0xbeafaf86ul, 0xaf112943ul), mk_sl_cui_uint64_cc(0x1d6a6ab5ul, 0x6a77dfd4ul), mk_sl_cui_uint64_cc(0xea50505dul, 0x50ba0da0ul),
		mk_sl_cui_uint64_cc(0x57454509ul, 0x45124c8aul), mk_sl_cui_uint64_cc(0x38f3f3ebul, 0xf3cb18fbul), mk_sl_cui_uint64_cc(0xad3030c0ul, 0x309df060ul), mk_sl_cui_uint64_cc(0xc4efef9bul, 0xef2b74c3ul),
		mk_sl_cui_uint64_cc(0xda3f3ffcul, 0x3fe5c37eul), mk_sl_cui_uint64_cc(0xc7555549ul, 0x55921caaul), mk_sl_cui_uint64_cc(0xdba2a2b2ul, 0xa2791059ul), mk_sl_cui_uint64_cc(0xe9eaea8ful, 0xea0365c9ul),
		mk_sl_cui_uint64_cc(0x6a656589ul, 0x650feccaul), mk_sl_cui_uint64_cc(0x03babad2ul, 0xbab96869ul), mk_sl_cui_uint64_cc(0x4a2f2fbcul, 0x2f65935eul), mk_sl_cui_uint64_cc(0x8ec0c027ul, 0xc04ee79dul),
		mk_sl_cui_uint64_cc(0x60dede5ful, 0xdebe81a1ul), mk_sl_cui_uint64_cc(0xfc1c1c70ul, 0x1ce06c38ul), mk_sl_cui_uint64_cc(0x46fdfdd3ul, 0xfdbb2ee7ul), mk_sl_cui_uint64_cc(0x1f4d4d29ul, 0x4d52649aul),
		mk_sl_cui_uint64_cc(0x76929272ul, 0x92e4e039ul), mk_sl_cui_uint64_cc(0xfa7575c9ul, 0x758fbceaul), mk_sl_cui_uint64_cc(0x36060618ul, 0x06301e0cul), mk_sl_cui_uint64_cc(0xae8a8a12ul, 0x8a249809ul),
		mk_sl_cui_uint64_cc(0x4bb2b2f2ul, 0xb2f94079ul), mk_sl_cui_uint64_cc(0x85e6e6bful, 0xe66359d1ul), mk_sl_cui_uint64_cc(0x7e0e0e38ul, 0x0e70361cul), mk_sl_cui_uint64_cc(0xe71f1f7cul, 0x1ff8633eul),
		mk_sl_cui_uint64_cc(0x55626295ul, 0x6237f7c4ul), mk_sl_cui_uint64_cc(0x3ad4d477ul, 0xd4eea3b5ul), mk_sl_cui_uint64_cc(0x81a8a89aul, 0xa829324dul), mk_sl_cui_uint64_cc(0x52969662ul, 0x96c4f431ul),
		mk_sl_cui_uint64_cc(0x62f9f9c3ul, 0xf99b3aeful), mk_sl_cui_uint64_cc(0xa3c5c533ul, 0xc566f697ul), mk_sl_cui_uint64_cc(0x10252594ul, 0x2535b14aul), mk_sl_cui_uint64_cc(0xab595979ul, 0x59f220b2ul),
		mk_sl_cui_uint64_cc(0xd084842aul, 0x8454ae15ul), mk_sl_cui_uint64_cc(0xc57272d5ul, 0x72b7a7e4ul), mk_sl_cui_uint64_cc(0xec3939e4ul, 0x39d5dd72ul), mk_sl_cui_uint64_cc(0x164c4c2dul, 0x4c5a6198ul),
		mk_sl_cui_uint64_cc(0x945e5e65ul, 0x5eca3bbcul), mk_sl_cui_uint64_cc(0x9f7878fdul, 0x78e785f0ul), mk_sl_cui_uint64_cc(0xe53838e0ul, 0x38ddd870ul), mk_sl_cui_uint64_cc(0x988c8c0aul, 0x8c148605ul),
		mk_sl_cui_uint64_cc(0x17d1d163ul, 0xd1c6b2bful), mk_sl_cui_uint64_cc(0xe4a5a5aeul, 0xa5410b57ul), mk_sl_cui_uint64_cc(0xa1e2e2aful, 0xe2434dd9ul), mk_sl_cui_uint64_cc(0x4e616199ul, 0x612ff8c2ul),
		mk_sl_cui_uint64_cc(0x42b3b3f6ul, 0xb3f1457bul), mk_sl_cui_uint64_cc(0x34212184ul, 0x2115a542ul), mk_sl_cui_uint64_cc(0x089c9c4aul, 0x9c94d625ul), mk_sl_cui_uint64_cc(0xee1e1e78ul, 0x1ef0663cul),
		mk_sl_cui_uint64_cc(0x61434311ul, 0x43225286ul), mk_sl_cui_uint64_cc(0xb1c7c73bul, 0xc776fc93ul), mk_sl_cui_uint64_cc(0x4ffcfcd7ul, 0xfcb32be5ul), mk_sl_cui_uint64_cc(0x24040410ul, 0x04201408ul),
		mk_sl_cui_uint64_cc(0xe3515159ul, 0x51b208a2ul), mk_sl_cui_uint64_cc(0x2599995eul, 0x99bcc72ful), mk_sl_cui_uint64_cc(0x226d6da9ul, 0x6d4fc4daul), mk_sl_cui_uint64_cc(0x650d0d34ul, 0x0d68391aul),
		mk_sl_cui_uint64_cc(0x79fafacful, 0xfa8335e9ul), mk_sl_cui_uint64_cc(0x69dfdf5bul, 0xdfb684a3ul), mk_sl_cui_uint64_cc(0xa97e7ee5ul, 0x7ed79bfcul), mk_sl_cui_uint64_cc(0x19242490ul, 0x243db448ul),
		mk_sl_cui_uint64_cc(0xfe3b3becul, 0x3bc5d776ul), mk_sl_cui_uint64_cc(0x9aabab96ul, 0xab313d4bul), mk_sl_cui_uint64_cc(0xf0cece1ful, 0xce3ed181ul), mk_sl_cui_uint64_cc(0x99111144ul, 0x11885522ul),
		mk_sl_cui_uint64_cc(0x838f8f06ul, 0x8f0c8903ul), mk_sl_cui_uint64_cc(0x044e4e25ul, 0x4e4a6b9cul), mk_sl_cui_uint64_cc(0x66b7b7e6ul, 0xb7d15173ul), mk_sl_cui_uint64_cc(0xe0ebeb8bul, 0xeb0b60cbul),
		mk_sl_cui_uint64_cc(0xc13c3cf0ul, 0x3cfdcc78ul), mk_sl_cui_uint64_cc(0xfd81813eul, 0x817cbf1ful), mk_sl_cui_uint64_cc(0x4094946aul, 0x94d4fe35ul), mk_sl_cui_uint64_cc(0x1cf7f7fbul, 0xf7eb0cf3ul),
		mk_sl_cui_uint64_cc(0x18b9b9deul, 0xb9a1676ful), mk_sl_cui_uint64_cc(0x8b13134cul, 0x13985f26ul), mk_sl_cui_uint64_cc(0x512c2cb0ul, 0x2c7d9c58ul), mk_sl_cui_uint64_cc(0x05d3d36bul, 0xd3d6b8bbul),
		mk_sl_cui_uint64_cc(0x8ce7e7bbul, 0xe76b5cd3ul), mk_sl_cui_uint64_cc(0x396e6ea5ul, 0x6e57cbdcul), mk_sl_cui_uint64_cc(0xaac4c437ul, 0xc46ef395ul), mk_sl_cui_uint64_cc(0x1b03030cul, 0x03180f06ul),
		mk_sl_cui_uint64_cc(0xdc565645ul, 0x568a13acul), mk_sl_cui_uint64_cc(0x5e44440dul, 0x441a4988ul), mk_sl_cui_uint64_cc(0xa07f7fe1ul, 0x7fdf9efeul), mk_sl_cui_uint64_cc(0x88a9a99eul, 0xa921374ful),
		mk_sl_cui_uint64_cc(0x672a2aa8ul, 0x2a4d8254ul), mk_sl_cui_uint64_cc(0x0abbbbd6ul, 0xbbb16d6bul), mk_sl_cui_uint64_cc(0x87c1c123ul, 0xc146e29ful), mk_sl_cui_uint64_cc(0xf1535351ul, 0x53a202a6ul),
		mk_sl_cui_uint64_cc(0x72dcdc57ul, 0xdcae8ba5ul), mk_sl_cui_uint64_cc(0x530b0b2cul, 0x0b582716ul), mk_sl_cui_uint64_cc(0x019d9d4eul, 0x9d9cd327ul), mk_sl_cui_uint64_cc(0x2b6c6cadul, 0x6c47c1d8ul),
		mk_sl_cui_uint64_cc(0xa43131c4ul, 0x3195f562ul), mk_sl_cui_uint64_cc(0xf37474cdul, 0x7487b9e8ul), mk_sl_cui_uint64_cc(0x15f6f6fful, 0xf6e309f1ul), mk_sl_cui_uint64_cc(0x4c464605ul, 0x460a438cul),
		mk_sl_cui_uint64_cc(0xa5acac8aul, 0xac092645ul), mk_sl_cui_uint64_cc(0xb589891eul, 0x893c970ful), mk_sl_cui_uint64_cc(0xb4141450ul, 0x14a04428ul), mk_sl_cui_uint64_cc(0xbae1e1a3ul, 0xe15b42dful),
		mk_sl_cui_uint64_cc(0xa6161658ul, 0x16b04e2cul), mk_sl_cui_uint64_cc(0xf73a3ae8ul, 0x3acdd274ul), mk_sl_cui_uint64_cc(0x066969b9ul, 0x696fd0d2ul), mk_sl_cui_uint64_cc(0x41090924ul, 0x09482d12ul),
		mk_sl_cui_uint64_cc(0xd77070ddul, 0x70a7ade0ul), mk_sl_cui_uint64_cc(0x6fb6b6e2ul, 0xb6d95471ul), mk_sl_cui_uint64_cc(0x1ed0d067ul, 0xd0ceb7bdul), mk_sl_cui_uint64_cc(0xd6eded93ul, 0xed3b7ec7ul),
		mk_sl_cui_uint64_cc(0xe2cccc17ul, 0xcc2edb85ul), mk_sl_cui_uint64_cc(0x68424215ul, 0x422a5784ul), mk_sl_cui_uint64_cc(0x2c98985aul, 0x98b4c22dul), mk_sl_cui_uint64_cc(0xeda4a4aaul, 0xa4490e55ul),
		mk_sl_cui_uint64_cc(0x752828a0ul, 0x285d8850ul), mk_sl_cui_uint64_cc(0x865c5c6dul, 0x5cda31b8ul), mk_sl_cui_uint64_cc(0x6bf8f8c7ul, 0xf8933fedul), mk_sl_cui_uint64_cc(0xc2868622ul, 0x8644a411ul),
	}}},
	{{{
		mk_sl_cui_uint64_cc(0x30d81818ul, 0x6018c078ul), mk_sl_cui_uint64_cc(0x46262323ul, 0x8c2305aful), mk_sl_cui_uint64_cc(0x91b8c6c6ul, 0x3fc67ef9ul), mk_sl_cui_uint64_cc(0xcdfbe8e8ul, 0x87e8136ful),
		mk_sl_cui_uint64_cc(0x13cb8787ul, 0x26874ca1ul), mk_sl_cui_uint64_cc(0x6d11b8b8ul, 0xdab8a962ul), mk_sl_cui_uint64_cc(0x02090101ul, 0x04010805ul), mk_sl_cui_uint64_cc(0x9e0d4f4ful, 0x214f426eul),
		mk_sl_cui_uint64_cc(0x6c9b3636ul, 0xd836adeeul), mk_sl_cui_uint64_cc(0x51ffa6a6ul, 0xa2a65904ul), mk_sl_cui_uint64_cc(0xb90cd2d2ul, 0x6fd2debdul), mk_sl_cui_uint64_cc(0xf70ef5f5ul, 0xf3f5fb06ul),
		mk_sl_cui_uint64_cc(0xf2967979ul, 0xf979ef80ul), mk_sl_cui_uint64_cc(0xde306f6ful, 0xa16f5fceul), mk_sl_cui_uint64_cc(0x3f6d9191ul, 0x7e91fceful), mk_sl_cui_uint64_cc(0xa4f85252ul, 0x5552aa07ul),
		mk_sl_cui_uint64_cc(0xc0476060ul, 0x9d6027fdul), mk_sl_cui_uint64_cc(0x6535bcbcul, 0xcabc8976ul), mk_sl_cui_uint64_cc(0x2b379b9bul, 0x569baccdul), mk_sl_cui_uint64_cc(0x018a8e8eul, 0x028e048cul),
		mk_sl_cui_uint64_cc(0x5bd2a3a3ul, 0xb6a37115ul), mk_sl_cui_uint64_cc(0x186c0c0cul, 0x300c603cul), mk_sl_cui_uint64_cc(0xf6847b7bul, 0xf17bff8aul), mk_sl_cui_uint64_cc(0x6a803535ul, 0xd435b5e1ul),
		mk_sl_cui_uint64_cc(0x3af51d1dul, 0x741de869ul), mk_sl_cui_uint64_cc(0xddb3e0e0ul, 0xa7e05347ul), mk_sl_cui_uint64_cc(0xb321d7d7ul, 0x7bd7f6acul), mk_sl_cui_uint64_cc(0x999cc2c2ul, 0x2fc25eedul),
		mk_sl_cui_uint64_cc(0x5c432e2eul, 0xb82e6d96ul), mk_sl_cui_uint64_cc(0x96294b4bul, 0x314b627aul), mk_sl_cui_uint64_cc(0xe15dfefeul, 0xdffea321ul), mk_sl_cui_uint64_cc(0xaed55757ul, 0x41578216ul),
		mk_sl_cui_uint64_cc(0x2abd1515ul, 0x5415a841ul), mk_sl_cui_uint64_cc(0xeee87777ul, 0xc1779fb6ul), mk_sl_cui_uint64_cc(0x6e923737ul, 0xdc37a5ebul), mk_sl_cui_uint64_cc(0xd79ee5e5ul, 0xb3e57b56ul),
		mk_sl_cui_uint64_cc(0x23139f9ful, 0x469f8cd9ul), mk_sl_cui_uint64_cc(0xfd23f0f0ul, 0xe7f0d317ul), mk_sl_cui_uint64_cc(0x94204a4aul, 0x354a6a7ful), mk_sl_cui_uint64_cc(0xa944dadaul, 0x4fda9e95ul),
		mk_sl_cui_uint64_cc(0xb0a25858ul, 0x7d58fa25ul), mk_sl_cui_uint64_cc(0x8fcfc9c9ul, 0x03c906caul), mk_sl_cui_uint64_cc(0x527c2929ul, 0xa429558dul), mk_sl_cui_uint64_cc(0x145a0a0aul, 0x280a5022ul),
		mk_sl_cui_uint64_cc(0x7f50b1b1ul, 0xfeb1e14ful), mk_sl_cui_uint64_cc(0x5dc9a0a0ul, 0xbaa0691aul), mk_sl_cui_uint64_cc(0xd6146b6bul, 0xb16b7fdaul), mk_sl_cui_uint64_cc(0x17d98585ul, 0x2e855cabul),
		mk_sl_cui_uint64_cc(0x673cbdbdul, 0xcebd8173ul), mk_sl_cui_uint64_cc(0xba8f5d5dul, 0x695dd234ul), mk_sl_cui_uint64_cc(0x20901010ul, 0x40108050ul), mk_sl_cui_uint64_cc(0xf507f4f4ul, 0xf7f4f303ul),
		mk_sl_cui_uint64_cc(0x8bddcbcbul, 0x0bcb16c0ul), mk_sl_cui_uint64_cc(0x7cd33e3eul, 0xf83eedc6ul), mk_sl_cui_uint64_cc(0x0a2d0505ul, 0x14052811ul), mk_sl_cui_uint64_cc(0xce786767ul, 0x81671fe6ul),
		mk_sl_cui_uint64_cc(0xd597e4e4ul, 0xb7e47353ul), mk_sl_cui_uint64_cc(0x4e022727ul, 0x9c2725bbul), mk_sl_cui_uint64_cc(0x82734141ul, 0x19413258ul), mk_sl_cui_uint64_cc(0x0ba78b8bul, 0x168b2c9dul),
		mk_sl_cui_uint64_cc(0x53f6a7a7ul, 0xa6a75101ul), mk_sl_cui_uint64_cc(0xfab27d7dul, 0xe97dcf94ul), mk_sl_cui_uint64_cc(0x37499595ul, 0x6e95dcfbul), mk_sl_cui_uint64_cc(0xad56d8d8ul, 0x47d88e9ful),
		mk_sl_cui_uint64_cc(0xeb70fbfbul, 0xcbfb8b30ul), mk_sl_cui_uint64_cc(0xc1cdeeeeul, 0x9fee2371ul), mk_sl_cui_uint64_cc(0xf8bb7c7cul, 0xed7cc791ul), mk_sl_cui_uint64_cc(0xcc716666ul, 0x856617e3ul),
		mk_sl_cui_uint64_cc(0xa77bddddul, 0x53dda68eul), mk_sl_cui_uint64_cc(0x2eaf1717ul, 0x5c17b84bul), mk_sl_cui_uint64_cc(0x8e454747ul, 0x01470246ul), mk_sl_cui_uint64_cc(0x211a9e9eul, 0x429e84dcul),
		mk_sl_cui_uint64_cc(0x89d4cacaul, 0x0fca1ec5ul), mk_sl_cui_uint64_cc(0x5a582d2dul, 0xb42d7599ul), mk_sl_cui_uint64_cc(0x632ebfbful, 0xc6bf9179ul), mk_sl_cui_uint64_cc(0x0e3f0707ul, 0x1c07381bul),
		mk_sl_cui_uint64_cc(0x47acadadul, 0x8ead0123ul), mk_sl_cui_uint64_cc(0xb4b05a5aul, 0x755aea2ful), mk_sl_cui_uint64_cc(0x1bef8383ul, 0x36836cb5ul), mk_sl_cui_uint64_cc(0x66b63333ul, 0xcc3385fful),
		mk_sl_cui_uint64_cc(0xc65c6363ul, 0x91633ff2ul), mk_sl_cui_uint64_cc(0x04120202ul, 0x0802100aul), mk_sl_cui_uint64_cc(0x4993aaaaul, 0x92aa3938ul), mk_sl_cui_uint64_cc(0xe2de7171ul, 0xd971afa8ul),
		mk_sl_cui_uint64_cc(0x8dc6c8c8ul, 0x07c80ecful), mk_sl_cui_uint64_cc(0x32d11919ul, 0x6419c87dul), mk_sl_cui_uint64_cc(0x923b4949ul, 0x39497270ul), mk_sl_cui_uint64_cc(0xaf5fd9d9ul, 0x43d9869aul),
		mk_sl_cui_uint64_cc(0xf931f2f2ul, 0xeff2c31dul), mk_sl_cui_uint64_cc(0xdba8e3e3ul, 0xabe34b48ul), mk_sl_cui_uint64_cc(0xb6b95b5bul, 0x715be22aul), mk_sl_cui_uint64_cc(0x0dbc8888ul, 0x1a883492ul),
		mk_sl_cui_uint64_cc(0x293e9a9aul, 0x529aa4c8ul), mk_sl_cui_uint64_cc(0x4c0b2626ul, 0x98262dbeul), mk_sl_cui_uint64_cc(0x64bf3232ul, 0xc8328dfaul), mk_sl_cui_uint64_cc(0x7d59b0b0ul, 0xfab0e94aul),
		mk_sl_cui_uint64_cc(0xcff2e9e9ul, 0x83e91b6aul), mk_sl_cui_uint64_cc(0x1e770f0ful, 0x3c0f7833ul), mk_sl_cui_uint64_cc(0xb733d5d5ul, 0x73d5e6a6ul), mk_sl_cui_uint64_cc(0x1df48080ul, 0x3a8074baul),
		mk_sl_cui_uint64_cc(0x6127bebeul, 0xc2be997cul), mk_sl_cui_uint64_cc(0x87ebcdcdul, 0x13cd26deul), mk_sl_cui_uint64_cc(0x68893434ul, 0xd034bde4ul), mk_sl_cui_uint64_cc(0x90324848ul, 0x3d487a75ul),
		mk_sl_cui_uint64_cc(0xe354fffful, 0xdbffab24ul), mk_sl_cui_uint64_cc(0xf48d7a7aul, 0xf57af78ful), mk_sl_cui_uint64_cc(0x3d649090ul, 0x7a90f4eaul), mk_sl_cui_uint64_cc(0xbe9d5f5ful, 0x615fc23eul),
		mk_sl_cui_uint64_cc(0x403d2020ul, 0x80201da0ul), mk_sl_cui_uint64_cc(0xd00f6868ul, 0xbd6867d5ul), mk_sl_cui_uint64_cc(0x34ca1a1aul, 0x681ad072ul), mk_sl_cui_uint64_cc(0x41b7aeaeul, 0x82ae192cul),
		mk_sl_cui_uint64_cc(0x757db4b4ul, 0xeab4c95eul), mk_sl_cui_uint64_cc(0xa8ce5454ul, 0x4d549a19ul), mk_sl_cui_uint64_cc(0x3b7f9393ul, 0x7693ece5ul), mk_sl_cui_uint64_cc(0x442f2222ul, 0x88220daaul),
		mk_sl_cui_uint64_cc(0xc8636464ul, 0x8d6407e9ul), mk_sl_cui_uint64_cc(0xff2af1f1ul, 0xe3f1db12ul), mk_sl_cui_uint64_cc(0xe6cc7373ul, 0xd173bfa2ul), mk_sl_cui_uint64_cc(0x24821212ul, 0x4812905aul),
		mk_sl_cui_uint64_cc(0x807a4040ul, 0x1d403a5dul), mk_sl_cui_uint64_cc(0x10480808ul, 0x20084028ul), mk_sl_cui_uint64_cc(0x9b95c3c3ul, 0x2bc356e8ul), mk_sl_cui_uint64_cc(0xc5dfececul, 0x97ec337bul),
		mk_sl_cui_uint64_cc(0xab4ddbdbul, 0x4bdb9690ul), mk_sl_cui_uint64_cc(0x5fc0a1a1ul, 0xbea1611ful), mk_sl_cui_uint64_cc(0x07918d8dul, 0x0e8d1c83ul), mk_sl_cui_uint64_cc(0x7ac83d3dul, 0xf43df5c9ul),
		mk_sl_cui_uint64_cc(0x335b9797ul, 0x6697ccf1ul), mk_sl_cui_uint64_cc(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_cc(0x83f9cfcful, 0x1bcf36d4ul), mk_sl_cui_uint64_cc(0x566e2b2bul, 0xac2b4587ul),
		mk_sl_cui_uint64_cc(0xece17676ul, 0xc57697b3ul), mk_sl_cui_uint64_cc(0x19e68282ul, 0x328264b0ul), mk_sl_cui_uint64_cc(0xb128d6d6ul, 0x7fd6fea9ul), mk_sl_cui_uint64_cc(0x36c31b1bul, 0x6c1bd877ul),
		mk_sl_cui_uint64_cc(0x7774b5b5ul, 0xeeb5c15bul), mk_sl_cui_uint64_cc(0x43beafaful, 0x86af1129ul), mk_sl_cui_uint64_cc(0xd41d6a6aul, 0xb56a77dful), mk_sl_cui_uint64_cc(0xa0ea5050ul, 0x5d50ba0dul),
		mk_sl_cui_uint64_cc(0x8a574545ul, 0x0945124cul), mk_sl_cui_uint64_cc(0xfb38f3f3ul, 0xebf3cb18ul), mk_sl_cui_uint64_cc(0x60ad3030ul, 0xc0309df0ul), mk_sl_cui_uint64_cc(0xc3c4efeful, 0x9bef2b74ul),
		mk_sl_cui_uint64_cc(0x7eda3f3ful, 0xfc3fe5c3ul), mk_sl_cui_uint64_cc(0xaac75555ul, 0x4955921cul), mk_sl_cui_uint64_cc(0x59dba2a2ul, 0xb2a27910ul), mk_sl_cui_uint64_cc(0xc9e9eaeaul, 0x8fea0365ul),
		mk_sl_cui_uint64_cc(0xca6a6565ul, 0x89650fecul), mk_sl_cui_uint64_cc(0x6903babaul, 0xd2bab968ul), mk_sl_cui_uint64_cc(0x5e4a2f2ful, 0xbc2f6593ul), mk_sl_cui_uint64_cc(0x9d8ec0c0ul, 0x27c04ee7ul),
		mk_sl_cui_uint64_cc(0xa160dedeul, 0x5fdebe81ul), mk_sl_cui_uint64_cc(0x38fc1c1cul, 0x701ce06cul), mk_sl_cui_uint64_cc(0xe746fdfdul, 0xd3fdbb2eul), mk_sl_cui_uint64_cc(0x9a1f4d4dul, 0x294d5264ul),
		mk_sl_cui_uint64_cc(0x39769292ul, 0x7292e4e0ul), mk_sl_cui_uint64_cc(0xeafa7575ul, 0xc9758fbcul), mk_sl_cui_uint64_cc(0x0c360606ul, 0x1806301eul), mk_sl_cui_uint64_cc(0x09ae8a8aul, 0x128a2498ul),
		mk_sl_cui_uint64_cc(0x794bb2b2ul, 0xf2b2f940ul), mk_sl_cui_uint64_cc(0xd185e6e6ul, 0xbfe66359ul), mk_sl_cui_uint64_cc(0x1c7e0e0eul, 0x380e7036ul), mk_sl_cui_uint64_cc(0x3ee71f1ful, 0x7c1ff863ul),
		mk_sl_cui_uint64_cc(0xc4556262ul, 0x956237f7ul), mk_sl_cui_uint64_cc(0xb53ad4d4ul, 0x77d4eea3ul), mk_sl_cui_uint64_cc(0x4d81a8a8ul, 0x9aa82932ul), mk_sl_cui_uint64_cc(0x31529696ul, 0x6296c4f4ul),
		mk_sl_cui_uint64_cc(0xef62f9f9ul, 0xc3f99b3aul), mk_sl_cui_uint64_cc(0x97a3c5c5ul, 0x33c566f6ul), mk_sl_cui_uint64_cc(0x4a102525ul, 0x942535b1ul), mk_sl_cui_uint64_cc(0xb2ab5959ul, 0x7959f220ul),
		mk_sl_cui_uint64_cc(0x15d08484ul, 0x2a8454aeul), mk_sl_cui_uint64_cc(0xe4c57272ul, 0xd572b7a7ul), mk_sl_cui_uint64_cc(0x72ec3939ul, 0xe439d5ddul), mk_sl_cui_uint64_cc(0x98164c4cul, 0x2d4c5a61ul),
		mk_sl_cui_uint64_cc(0xbc945e5eul, 0x655eca3bul), mk_sl_cui_uint64_cc(0xf09f7878ul, 0xfd78e785ul), mk_sl_cui_uint64_cc(0x70e53838ul, 0xe038ddd8ul), mk_sl_cui_uint64_cc(0x05988c8cul, 0x0a8c1486ul),
		mk_sl_cui_uint64_cc(0xbf17d1d1ul, 0x63d1c6b2ul), mk_sl_cui_uint64_cc(0x57e4a5a5ul, 0xaea5410bul), mk_sl_cui_uint64_cc(0xd9a1e2e2ul, 0xafe2434dul), mk_sl_cui_uint64_cc(0xc24e6161ul, 0x99612ff8ul),
		mk_sl_cui_uint64_cc(0x7b42b3b3ul, 0xf6b3f145ul), mk_sl_cui_uint64_cc(0x42342121ul, 0x842115a5ul), mk_sl_cui_uint64_cc(0x25089c9cul, 0x4a9c94d6ul), mk_sl_cui_uint64_cc(0x3cee1e1eul, 0x781ef066ul),
		mk_sl_cui_uint64_cc(0x86614343ul, 0x11432252ul), mk_sl_cui_uint64_cc(0x93b1c7c7ul, 0x3bc776fcul), mk_sl_cui_uint64_cc(0xe54ffcfcul, 0xd7fcb32bul), mk_sl_cui_uint64_cc(0x08240404ul, 0x10042014ul),
		mk_sl_cui_uint64_cc(0xa2e35151ul, 0x5951b208ul), mk_sl_cui_uint64_cc(0x2f259999ul, 0x5e99bcc7ul), mk_sl_cui_uint64_cc(0xda226d6dul, 0xa96d4fc4ul), mk_sl_cui_uint64_cc(0x1a650d0dul, 0x340d6839ul),
		mk_sl_cui_uint64_cc(0xe979fafaul, 0xcffa8335ul), mk_sl_cui_uint64_cc(0xa369dfdful, 0x5bdfb684ul), mk_sl_cui_uint64_cc(0xfca97e7eul, 0xe57ed79bul), mk_sl_cui_uint64_cc(0x48192424ul, 0x90243db4ul),
		mk_sl_cui_uint64_cc(0x76fe3b3bul, 0xec3bc5d7ul), mk_sl_cui_uint64_cc(0x4b9aababul, 0x96ab313dul), mk_sl_cui_uint64_cc(0x81f0ceceul, 0x1fce3ed1ul), mk_sl_cui_uint64_cc(0x22991111ul, 0x44118855ul),
		mk_sl_cui_uint64_cc(0x03838f8ful, 0x068f0c89ul), mk_sl_cui_uint64_cc(0x9c044e4eul, 0x254e4a6bul), mk_sl_cui_uint64_cc(0x7366b7b7ul, 0xe6b7d151ul), mk_sl_cui_uint64_cc(0xcbe0ebebul, 0x8beb0b60ul),
		mk_sl_cui_uint64_cc(0x78c13c3cul, 0xf03cfdccul), mk_sl_cui_uint64_cc(0x1ffd8181ul, 0x3e817cbful), mk_sl_cui_uint64_cc(0x35409494ul, 0x6a94d4feul), mk_sl_cui_uint64_cc(0xf31cf7f7ul, 0xfbf7eb0cul),
		mk_sl_cui_uint64_cc(0x6f18b9b9ul, 0xdeb9a167ul), mk_sl_cui_uint64_cc(0x268b1313ul, 0x4c13985ful), mk_sl_cui_uint64_cc(0x58512c2cul, 0xb02c7d9cul), mk_sl_cui_uint64_cc(0xbb05d3d3ul, 0x6bd3d6b8ul),
		mk_sl_cui_uint64_cc(0xd38ce7e7ul, 0xbbe76b5cul), mk_sl_cui_uint64_cc(0xdc396e6eul, 0xa56e57cbul), mk_sl_cui_uint64_cc(0x95aac4c4ul, 0x37c46ef3ul), mk_sl_cui_uint64_cc(0x061b0303ul, 0x0c03180ful),
		mk_sl_cui_uint64_cc(0xacdc5656ul, 0x45568a13ul), mk_sl_cui_uint64_cc(0x885e4444ul, 0x0d441a49ul), mk_sl_cui_uint64_cc(0xfea07f7ful, 0xe17fdf9eul), mk_sl_cui_uint64_cc(0x4f88a9a9ul, 0x9ea92137ul),
		mk_sl_cui_uint64_cc(0x54672a2aul, 0xa82a4d82ul), mk_sl_cui_uint64_cc(0x6b0abbbbul, 0xd6bbb16dul), mk_sl_cui_uint64_cc(0x9f87c1c1ul, 0x23c146e2ul), mk_sl_cui_uint64_cc(0xa6f15353ul, 0x5153a202ul),
		mk_sl_cui_uint64_cc(0xa572dcdcul, 0x57dcae8bul), mk_sl_cui_uint64_cc(0x16530b0bul, 0x2c0b5827ul), mk_sl_cui_uint64_cc(0x27019d9dul, 0x4e9d9cd3ul), mk_sl_cui_uint64_cc(0xd82b6c6cul, 0xad6c47c1ul),
		mk_sl_cui_uint64_cc(0x62a43131ul, 0xc43195f5ul), mk_sl_cui_uint64_cc(0xe8f37474ul, 0xcd7487b9ul), mk_sl_cui_uint64_cc(0xf115f6f6ul, 0xfff6e309ul), mk_sl_cui_uint64_cc(0x8c4c4646ul, 0x05460a43ul),
		mk_sl_cui_uint64_cc(0x45a5acacul, 0x8aac0926ul), mk_sl_cui_uint64_cc(0x0fb58989ul, 0x1e893c97ul), mk_sl_cui_uint64_cc(0x28b41414ul, 0x5014a044ul), mk_sl_cui_uint64_cc(0xdfbae1e1ul, 0xa3e15b42ul),
		mk_sl_cui_uint64_cc(0x2ca61616ul, 0x5816b04eul), mk_sl_cui_uint64_cc(0x74f73a3aul, 0xe83acdd2ul), mk_sl_cui_uint64_cc(0xd2066969ul, 0xb9696fd0ul), mk_sl_cui_uint64_cc(0x12410909ul, 0x2409482dul),
		mk_sl_cui_uint64_cc(0xe0d77070ul, 0xdd70a7adul), mk_sl_cui_uint64_cc(0x716fb6b6ul, 0xe2b6d954ul), mk_sl_cui_uint64_cc(0xbd1ed0d0ul, 0x67d0ceb7ul), mk_sl_cui_uint64_cc(0xc7d6ededul, 0x93ed3b7eul),
		mk_sl_cui_uint64_cc(0x85e2ccccul, 0x17cc2edbul), mk_sl_cui_uint64_cc(0x84684242ul, 0x15422a57ul), mk_sl_cui_uint64_cc(0x2d2c9898ul, 0x5a98b4c2ul), mk_sl_cui_uint64_cc(0x55eda4a4ul, 0xaaa4490eul),
		mk_sl_cui_uint64_cc(0x50752828ul, 0xa0285d88ul), mk_sl_cui_uint64_cc(0xb8865c5cul, 0x6d5cda31ul), mk_sl_cui_uint64_cc(0xed6bf8f8ul, 0xc7f8933ful), mk_sl_cui_uint64_cc(0x11c28686ul, 0x228644a4ul),
	}}},
	{{{
		mk_sl_cui_uint64_cc(0x7830d818ul, 0x186018c0ul), mk_sl_cui_uint64_cc(0xaf462623ul, 0x238c2305ul), mk_sl_cui_uint64_cc(0xf991b8c6ul, 0xc63fc67eul), mk_sl_cui_uint64_cc(0x6fcdfbe8ul, 0xe887e813ul),
		mk_sl_cui_uint64_cc(0xa113cb87ul, 0x8726874cul), mk_sl_cui_uint64_cc(0x626d11b8ul, 0xb8dab8a9ul), mk_sl_cui_uint64_cc(0x05020901ul, 0x01040108ul), mk_sl_cui_uint64_cc(0x6e9e0d4ful, 0x4f214f42ul),
		mk_sl_cui_uint64_cc(0xee6c9b36ul, 0x36d836adul), mk_sl_cui_uint64_cc(0x0451ffa6ul, 0xa6a2a659ul), mk_sl_cui_uint64_cc(0xbdb90cd2ul, 0xd26fd2deul), mk_sl_cui_uint64_cc(0x06f70ef5ul, 0xf5f3f5fbul),
		mk_sl_cui_uint64_cc(0x80f29679ul, 0x79f979eful), mk_sl_cui_uint64_cc(0xcede306ful, 0x6fa16f5ful), mk_sl_cui_uint64_cc(0xef3f6d91ul, 0x917e91fcul), mk_sl_cui_uint64_cc(0x07a4f852ul, 0x525552aaul),
		mk_sl_cui_uint64_cc(0xfdc04760ul, 0x609d6027ul), mk_sl_cui_uint64_cc(0x766535bcul, 0xbccabc89ul), mk_sl_cui_uint64_cc(0xcd2b379bul, 0x9b569bacul), mk_sl_cui_uint64_cc(0x8c018a8eul, 0x8e028e04ul),
		mk_sl_cui_uint64_cc(0x155bd2a3ul, 0xa3b6a371ul), mk_sl_cui_uint64_cc(0x3c186c0cul, 0x0c300c60ul), mk_sl_cui_uint64_cc(0x8af6847bul, 0x7bf17bfful), mk_sl_cui_uint64_cc(0xe16a8035ul, 0x35d435b5ul),
		mk_sl_cui_uint64_cc(0x693af51dul, 0x1d741de8ul), mk_sl_cui_uint64_cc(0x47ddb3e0ul, 0xe0a7e053ul), mk_sl_cui_uint64_cc(0xacb321d7ul, 0xd77bd7f6ul), mk_sl_cui_uint64_cc(0xed999cc2ul, 0xc22fc25eul),
		mk_sl_cui_uint64_cc(0x965c432eul, 0x2eb82e6dul), mk_sl_cui_uint64_cc(0x7a96294bul, 0x4b314b62ul), mk_sl_cui_uint64_cc(0x21e15dfeul, 0xfedffea3ul), mk_sl_cui_uint64_cc(0x16aed557ul, 0x57415782ul),
		mk_sl_cui_uint64_cc(0x412abd15ul, 0x155415a8ul), mk_sl_cui_uint64_cc(0xb6eee877ul, 0x77c1779ful), mk_sl_cui_uint64_cc(0xeb6e9237ul, 0x37dc37a5ul), mk_sl_cui_uint64_cc(0x56d79ee5ul, 0xe5b3e57bul),
		mk_sl_cui_uint64_cc(0xd923139ful, 0x9f469f8cul), mk_sl_cui_uint64_cc(0x17fd23f0ul, 0xf0e7f0d3ul), mk_sl_cui_uint64_cc(0x7f94204aul, 0x4a354a6aul), mk_sl_cui_uint64_cc(0x95a944daul, 0xda4fda9eul),
		mk_sl_cui_uint64_cc(0x25b0a258ul, 0x587d58faul), mk_sl_cui_uint64_cc(0xca8fcfc9ul, 0xc903c906ul), mk_sl_cui_uint64_cc(0x8d527c29ul, 0x29a42955ul), mk_sl_cui_uint64_cc(0x22145a0aul, 0x0a280a50ul),
		mk_sl_cui_uint64_cc(0x4f7f50b1ul, 0xb1feb1e1ul), mk_sl_cui_uint64_cc(0x1a5dc9a0ul, 0xa0baa069ul), mk_sl_cui_uint64_cc(0xdad6146bul, 0x6bb16b7ful), mk_sl_cui_uint64_cc(0xab17d985ul, 0x852e855cul),
		mk_sl_cui_uint64_cc(0x73673cbdul, 0xbdcebd81ul), mk_sl_cui_uint64_cc(0x34ba8f5dul, 0x5d695dd2ul), mk_sl_cui_uint64_cc(0x50209010ul, 0x10401080ul), mk_sl_cui_uint64_cc(0x03f507f4ul, 0xf4f7f4f3ul),
		mk_sl_cui_uint64_cc(0xc08bddcbul, 0xcb0bcb16ul), mk_sl_cui_uint64_cc(0xc67cd33eul, 0x3ef83eedul), mk_sl_cui_uint64_cc(0x110a2d05ul, 0x05140528ul), mk_sl_cui_uint64_cc(0xe6ce7867ul, 0x6781671ful),
		mk_sl_cui_uint64_cc(0x53d597e4ul, 0xe4b7e473ul), mk_sl_cui_uint64_cc(0xbb4e0227ul, 0x279c2725ul), mk_sl_cui_uint64_cc(0x58827341ul, 0x41194132ul), mk_sl_cui_uint64_cc(0x9d0ba78bul, 0x8b168b2cul),
		mk_sl_cui_uint64_cc(0x0153f6a7ul, 0xa7a6a751ul), mk_sl_cui_uint64_cc(0x94fab27dul, 0x7de97dcful), mk_sl_cui_uint64_cc(0xfb374995ul, 0x956e95dcul), mk_sl_cui_uint64_cc(0x9fad56d8ul, 0xd847d88eul),
		mk_sl_cui_uint64_cc(0x30eb70fbul, 0xfbcbfb8bul), mk_sl_cui_uint64_cc(0x71c1cdeeul, 0xee9fee23ul), mk_sl_cui_uint64_cc(0x91f8bb7cul, 0x7ced7cc7ul), mk_sl_cui_uint64_cc(0xe3cc7166ul, 0x66856617ul),
		mk_sl_cui_uint64_cc(0x8ea77bddul, 0xdd53dda6ul), mk_sl_cui_uint64_cc(0x4b2eaf17ul, 0x175c17b8ul), mk_sl_cui_uint64_cc(0x468e4547ul, 0x47014702ul), mk_sl_cui_uint64_cc(0xdc211a9eul, 0x9e429e84ul),
		mk_sl_cui_uint64_cc(0xc589d4caul, 0xca0fca1eul), mk_sl_cui_uint64_cc(0x995a582dul, 0x2db42d75ul), mk_sl_cui_uint64_cc(0x79632ebful, 0xbfc6bf91ul), mk_sl_cui_uint64_cc(0x1b0e3f07ul, 0x071c0738ul),
		mk_sl_cui_uint64_cc(0x2347acadul, 0xad8ead01ul), mk_sl_cui_uint64_cc(0x2fb4b05aul, 0x5a755aeaul), mk_sl_cui_uint64_cc(0xb51bef83ul, 0x8336836cul), mk_sl_cui_uint64_cc(0xff66b633ul, 0x33cc3385ul),
		mk_sl_cui_uint64_cc(0xf2c65c63ul, 0x6391633ful), mk_sl_cui_uint64_cc(0x0a041202ul, 0x02080210ul), mk_sl_cui_uint64_cc(0x384993aaul, 0xaa92aa39ul), mk_sl_cui_uint64_cc(0xa8e2de71ul, 0x71d971aful),
		mk_sl_cui_uint64_cc(0xcf8dc6c8ul, 0xc807c80eul), mk_sl_cui_uint64_cc(0x7d32d119ul, 0x196419c8ul), mk_sl_cui_uint64_cc(0x70923b49ul, 0x49394972ul), mk_sl_cui_uint64_cc(0x9aaf5fd9ul, 0xd943d986ul),
		mk_sl_cui_uint64_cc(0x1df931f2ul, 0xf2eff2c3ul), mk_sl_cui_uint64_cc(0x48dba8e3ul, 0xe3abe34bul), mk_sl_cui_uint64_cc(0x2ab6b95bul, 0x5b715be2ul), mk_sl_cui_uint64_cc(0x920dbc88ul, 0x881a8834ul),
		mk_sl_cui_uint64_cc(0xc8293e9aul, 0x9a529aa4ul), mk_sl_cui_uint64_cc(0xbe4c0b26ul, 0x2698262dul), mk_sl_cui_uint64_cc(0xfa64bf32ul, 0x32c8328dul), mk_sl_cui_uint64_cc(0x4a7d59b0ul, 0xb0fab0e9ul),
		mk_sl_cui_uint64_cc(0x6acff2e9ul, 0xe983e91bul), mk_sl_cui_uint64_cc(0x331e770ful, 0x0f3c0f78ul), mk_sl_cui_uint64_cc(0xa6b733d5ul, 0xd573d5e6ul), mk_sl_cui_uint64_cc(0xba1df480ul, 0x803a8074ul),
		mk_sl_cui_uint64_cc(0x7c6127beul, 0xbec2be99ul), mk_sl_cui_uint64_cc(0xde87ebcdul, 0xcd13cd26ul), mk_sl_cui_uint64_cc(0xe4688934ul, 0x34d034bdul), mk_sl_cui_uint64_cc(0x75903248ul, 0x483d487aul),
		mk_sl_cui_uint64_cc(0x24e354fful, 0xffdbffabul), mk_sl_cui_uint64_cc(0x8ff48d7aul, 0x7af57af7ul), mk_sl_cui_uint64_cc(0xea3d6490ul, 0x907a90f4ul), mk_sl_cui_uint64_cc(0x3ebe9d5ful, 0x5f615fc2ul),
		mk_sl_cui_uint64_cc(0xa0403d20ul, 0x2080201dul), mk_sl_cui_uint64_cc(0xd5d00f68ul, 0x68bd6867ul), mk_sl_cui_uint64_cc(0x7234ca1aul, 0x1a681ad0ul), mk_sl_cui_uint64_cc(0x2c41b7aeul, 0xae82ae19ul),
		mk_sl_cui_uint64_cc(0x5e757db4ul, 0xb4eab4c9ul), mk_sl_cui_uint64_cc(0x19a8ce54ul, 0x544d549aul), mk_sl_cui_uint64_cc(0xe53b7f93ul, 0x937693ecul), mk_sl_cui_uint64_cc(0xaa442f22ul, 0x2288220dul),
		mk_sl_cui_uint64_cc(0xe9c86364ul, 0x648d6407ul), mk_sl_cui_uint64_cc(0x12ff2af1ul, 0xf1e3f1dbul), mk_sl_cui_uint64_cc(0xa2e6cc73ul, 0x73d173bful), mk_sl_cui_uint64_cc(0x5a248212ul, 0x12481290ul),
		mk_sl_cui_uint64_cc(0x5d807a40ul, 0x401d403aul), mk_sl_cui_uint64_cc(0x28104808ul, 0x08200840ul), mk_sl_cui_uint64_cc(0xe89b95c3ul, 0xc32bc356ul), mk_sl_cui_uint64_cc(0x7bc5dfecul, 0xec97ec33ul),
		mk_sl_cui_uint64_cc(0x90ab4ddbul, 0xdb4bdb96ul), mk_sl_cui_uint64_cc(0x1f5fc0a1ul, 0xa1bea161ul), mk_sl_cui_uint64_cc(0x8307918dul, 0x8d0e8d1cul), mk_sl_cui_uint64_cc(0xc97ac83dul, 0x3df43df5ul),
		mk_sl_cui_uint64_cc(0xf1335b97ul, 0x976697ccul), mk_sl_cui_uint64_cc(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_cc(0xd483f9cful, 0xcf1bcf36ul), mk_sl_cui_uint64_cc(0x87566e2bul, 0x2bac2b45ul),
		mk_sl_cui_uint64_cc(0xb3ece176ul, 0x76c57697ul), mk_sl_cui_uint64_cc(0xb019e682ul, 0x82328264ul), mk_sl_cui_uint64_cc(0xa9b128d6ul, 0xd67fd6feul), mk_sl_cui_uint64_cc(0x7736c31bul, 0x1b6c1bd8ul),
		mk_sl_cui_uint64_cc(0x5b7774b5ul, 0xb5eeb5c1ul), mk_sl_cui_uint64_cc(0x2943beaful, 0xaf86af11ul), mk_sl_cui_uint64_cc(0xdfd41d6aul, 0x6ab56a77ul), mk_sl_cui_uint64_cc(0x0da0ea50ul, 0x505d50baul),
		mk_sl_cui_uint64_cc(0x4c8a5745ul, 0x45094512ul), mk_sl_cui_uint64_cc(0x18fb38f3ul, 0xf3ebf3cbul), mk_sl_cui_uint64_cc(0xf060ad30ul, 0x30c0309dul), mk_sl_cui_uint64_cc(0x74c3c4eful, 0xef9bef2bul),
		mk_sl_cui_uint64_cc(0xc37eda3ful, 0x3ffc3fe5ul), mk_sl_cui_uint64_cc(0x1caac755ul, 0x55495592ul), mk_sl_cui_uint64_cc(0x1059dba2ul, 0xa2b2a279ul), mk_sl_cui_uint64_cc(0x65c9e9eaul, 0xea8fea03ul),
		mk_sl_cui_uint64_cc(0xecca6a65ul, 0x6589650ful), mk_sl_cui_uint64_cc(0x686903baul, 0xbad2bab9ul), mk_sl_cui_uint64_cc(0x935e4a2ful, 0x2fbc2f65ul), mk_sl_cui_uint64_cc(0xe79d8ec0ul, 0xc027c04eul),
		mk_sl_cui_uint64_cc(0x81a160deul, 0xde5fdebeul), mk_sl_cui_uint64_cc(0x6c38fc1cul, 0x1c701ce0ul), mk_sl_cui_uint64_cc(0x2ee746fdul, 0xfdd3fdbbul), mk_sl_cui_uint64_cc(0x649a1f4dul, 0x4d294d52ul),
		mk_sl_cui_uint64_cc(0xe0397692ul, 0x927292e4ul), mk_sl_cui_uint64_cc(0xbceafa75ul, 0x75c9758ful), mk_sl_cui_uint64_cc(0x1e0c3606ul, 0x06180630ul), mk_sl_cui_uint64_cc(0x9809ae8aul, 0x8a128a24ul),
		mk_sl_cui_uint64_cc(0x40794bb2ul, 0xb2f2b2f9ul), mk_sl_cui_uint64_cc(0x59d185e6ul, 0xe6bfe663ul), mk_sl_cui_uint64_cc(0x361c7e0eul, 0x0e380e70ul), mk_sl_cui_uint64_cc(0x633ee71ful, 0x1f7c1ff8ul),
		mk_sl_cui_uint64_cc(0xf7c45562ul, 0x62956237ul), mk_sl_cui_uint64_cc(0xa3b53ad4ul, 0xd477d4eeul), mk_sl_cui_uint64_cc(0x324d81a8ul, 0xa89aa829ul), mk_sl_cui_uint64_cc(0xf4315296ul, 0x966296c4ul),
		mk_sl_cui_uint64_cc(0x3aef62f9ul, 0xf9c3f99bul), mk_sl_cui_uint64_cc(0xf697a3c5ul, 0xc533c566ul), mk_sl_cui_uint64_cc(0xb14a1025ul, 0x25942535ul), mk_sl_cui_uint64_cc(0x20b2ab59ul, 0x597959f2ul),
		mk_sl_cui_uint64_cc(0xae15d084ul, 0x842a8454ul), mk_sl_cui_uint64_cc(0xa7e4c572ul, 0x72d572b7ul), mk_sl_cui_uint64_cc(0xdd72ec39ul, 0x39e439d5ul), mk_sl_cui_uint64_cc(0x6198164cul, 0x4c2d4c5aul),
		mk_sl_cui_uint64_cc(0x3bbc945eul, 0x5e655ecaul), mk_sl_cui_uint64_cc(0x85f09f78ul, 0x78fd78e7ul), mk_sl_cui_uint64_cc(0xd870e538ul, 0x38e038ddul), mk_sl_cui_uint64_cc(0x8605988cul, 0x8c0a8c14ul),
		mk_sl_cui_uint64_cc(0xb2bf17d1ul, 0xd163d1c6ul), mk_sl_cui_uint64_cc(0x0b57e4a5ul, 0xa5aea541ul), mk_sl_cui_uint64_cc(0x4dd9a1e2ul, 0xe2afe243ul), mk_sl_cui_uint64_cc(0xf8c24e61ul, 0x6199612ful),
		mk_sl_cui_uint64_cc(0x457b42b3ul, 0xb3f6b3f1ul), mk_sl_cui_uint64_cc(0xa5423421ul, 0x21842115ul), mk_sl_cui_uint64_cc(0xd625089cul, 0x9c4a9c94ul), mk_sl_cui_uint64_cc(0x663cee1eul, 0x1e781ef0ul),
		mk_sl_cui_uint64_cc(0x52866143ul, 0x43114322ul), mk_sl_cui_uint64_cc(0xfc93b1c7ul, 0xc73bc776ul), mk_sl_cui_uint64_cc(0x2be54ffcul, 0xfcd7fcb3ul), mk_sl_cui_uint64_cc(0x14082404ul, 0x04100420ul),
		mk_sl_cui_uint64_cc(0x08a2e351ul, 0x515951b2ul), mk_sl_cui_uint64_cc(0xc72f2599ul, 0x995e99bcul), mk_sl_cui_uint64_cc(0xc4da226dul, 0x6da96d4ful), mk_sl_cui_uint64_cc(0x391a650dul, 0x0d340d68ul),
		mk_sl_cui_uint64_cc(0x35e979faul, 0xfacffa83ul), mk_sl_cui_uint64_cc(0x84a369dful, 0xdf5bdfb6ul), mk_sl_cui_uint64_cc(0x9bfca97eul, 0x7ee57ed7ul), mk_sl_cui_uint64_cc(0xb4481924ul, 0x2490243dul),
		mk_sl_cui_uint64_cc(0xd776fe3bul, 0x3bec3bc5ul), mk_sl_cui_uint64_cc(0x3d4b9aabul, 0xab96ab31ul), mk_sl_cui_uint64_cc(0xd181f0ceul, 0xce1fce3eul), mk_sl_cui_uint64_cc(0x55229911ul, 0x11441188ul),
		mk_sl_cui_uint64_cc(0x8903838ful, 0x8f068f0cul), mk_sl_cui_uint64_cc(0x6b9c044eul, 0x4e254e4aul), mk_sl_cui_uint64_cc(0x517366b7ul, 0xb7e6b7d1ul), mk_sl_cui_uint64_cc(0x60cbe0ebul, 0xeb8beb0bul),
		mk_sl_cui_uint64_cc(0xcc78c13cul, 0x3cf03cfdul), mk_sl_cui_uint64_cc(0xbf1ffd81ul, 0x813e817cul), mk_sl_cui_uint64_cc(0xfe354094ul, 0x946a94d4ul), mk_sl_cui_uint64_cc(0x0cf31cf7ul, 0xf7fbf7ebul),
		mk_sl_cui_uint64_cc(0x676f18b9ul, 0xb9deb9a1ul), mk_sl_cui_uint64_cc(0x5f268b13ul, 0x134c1398ul), mk_sl_cui_uint64_cc(0x9c58512cul, 0x2cb02c7dul), mk_sl_cui_uint64_cc(0xb8bb05d3ul, 0xd36bd3d6ul),
		mk_sl_cui_uint64_cc(0x5cd38ce7ul, 0xe7bbe76bul), mk_sl_cui_uint64_cc(0xcbdc396eul, 0x6ea56e57ul), mk_sl_cui_uint64_cc(0xf395aac4ul, 0xc437c46eul), mk_sl_cui_uint64_cc(0x0f061b03ul, 0x030c0318ul),
		mk_sl_cui_uint64_cc(0x13acdc56ul, 0x5645568aul), mk_sl_cui_uint64_cc(0x49885e44ul, 0x440d441aul), mk_sl_cui_uint64_cc(0x9efea07ful, 0x7fe17fdful), mk_sl_cui_uint64_cc(0x374f88a9ul, 0xa99ea921ul),
		mk_sl_cui_uint64_cc(0x8254672aul, 0x2aa82a4dul), mk_sl_cui_uint64_cc(0x6d6b0abbul, 0xbbd6bbb1ul), mk_sl_cui_uint64_cc(0xe29f87c1ul, 0xc123c146ul), mk_sl_cui_uint64_cc(0x02a6f153ul, 0x535153a2ul),
		mk_sl_cui_uint64_cc(0x8ba572dcul, 0xdc57dcaeul), mk_sl_cui_uint64_cc(0x2716530bul, 0x0b2c0b58ul), mk_sl_cui_uint64_cc(0xd327019dul, 0x9d4e9d9cul), mk_sl_cui_uint64_cc(0xc1d82b6cul, 0x6cad6c47ul),
		mk_sl_cui_uint64_cc(0xf562a431ul, 0x31c43195ul), mk_sl_cui_uint64_cc(0xb9e8f374ul, 0x74cd7487ul), mk_sl_cui_uint64_cc(0x09f115f6ul, 0xf6fff6e3ul), mk_sl_cui_uint64_cc(0x438c4c46ul, 0x4605460aul),
		mk_sl_cui_uint64_cc(0x2645a5acul, 0xac8aac09ul), mk_sl_cui_uint64_cc(0x970fb589ul, 0x891e893cul), mk_sl_cui_uint64_cc(0x4428b414ul, 0x145014a0ul), mk_sl_cui_uint64_cc(0x42dfbae1ul, 0xe1a3e15bul),
		mk_sl_cui_uint64_cc(0x4e2ca616ul, 0x165816b0ul), mk_sl_cui_uint64_cc(0xd274f73aul, 0x3ae83acdul), mk_sl_cui_uint64_cc(0xd0d20669ul, 0x69b9696ful), mk_sl_cui_uint64_cc(0x2d124109ul, 0x09240948ul),
		mk_sl_cui_uint64_cc(0xade0d770ul, 0x70dd70a7ul), mk_sl_cui_uint64_cc(0x54716fb6ul, 0xb6e2b6d9ul), mk_sl_cui_uint64_cc(0xb7bd1ed0ul, 0xd067d0ceul), mk_sl_cui_uint64_cc(0x7ec7d6edul, 0xed93ed3bul),
		mk_sl_cui_uint64_cc(0xdb85e2ccul, 0xcc17cc2eul), mk_sl_cui_uint64_cc(0x57846842ul, 0x4215422aul), mk_sl_cui_uint64_cc(0xc22d2c98ul, 0x985a98b4ul), mk_sl_cui_uint64_cc(0x0e55eda4ul, 0xa4aaa449ul),
		mk_sl_cui_uint64_cc(0x88507528ul, 0x28a0285dul), mk_sl_cui_uint64_cc(0x31b8865cul, 0x5c6d5cdaul), mk_sl_cui_uint64_cc(0x3fed6bf8ul, 0xf8c7f893ul), mk_sl_cui_uint64_cc(0xa411c286ul, 0x86228644ul),
	}}},
	{{{
		mk_sl_cui_uint64_cc(0xc07830d8ul, 0x18186018ul), mk_sl_cui_uint64_cc(0x05af4626ul, 0x23238c23ul), mk_sl_cui_uint64_cc(0x7ef991b8ul, 0xc6c63fc6ul), mk_sl_cui_uint64_cc(0x136fcdfbul, 0xe8e887e8ul),
		mk_sl_cui_uint64_cc(0x4ca113cbul, 0x87872687ul), mk_sl_cui_uint64_cc(0xa9626d11ul, 0xb8b8dab8ul), mk_sl_cui_uint64_cc(0x08050209ul, 0x01010401ul), mk_sl_cui_uint64_cc(0x426e9e0dul, 0x4f4f214ful),
		mk_sl_cui_uint64_cc(0xadee6c9bul, 0x3636d836ul), mk_sl_cui_uint64_cc(0x590451fful, 0xa6a6a2a6ul), mk_sl_cui_uint64_cc(0xdebdb90cul, 0xd2d26fd2ul), mk_sl_cui_uint64_cc(0xfb06f70eul, 0xf5f5f3f5ul),
		mk_sl_cui_uint64_cc(0xef80f296ul, 0x7979f979ul), mk_sl_cui_uint64_cc(0x5fcede30ul, 0x6f6fa16ful), mk_sl_cui_uint64_cc(0xfcef3f6dul, 0x91917e91ul), mk_sl_cui_uint64_cc(0xaa07a4f8ul, 0x52525552ul),
		mk_sl_cui_uint64_cc(0x27fdc047ul, 0x60609d60ul), mk_sl_cui_uint64_cc(0x89766535ul, 0xbcbccabcul), mk_sl_cui_uint64_cc(0xaccd2b37ul, 0x9b9b569bul), mk_sl_cui_uint64_cc(0x048c018aul, 0x8e8e028eul),
		mk_sl_cui_uint64_cc(0x71155bd2ul, 0xa3a3b6a3ul), mk_sl_cui_uint64_cc(0x603c186cul, 0x0c0c300cul), mk_sl_cui_uint64_cc(0xff8af684ul, 0x7b7bf17bul), mk_sl_cui_uint64_cc(0xb5e16a80ul, 0x3535d435ul),
		mk_sl_cui_uint64_cc(0xe8693af5ul, 0x1d1d741dul), mk_sl_cui_uint64_cc(0x5347ddb3ul, 0xe0e0a7e0ul), mk_sl_cui_uint64_cc(0xf6acb321ul, 0xd7d77bd7ul), mk_sl_cui_uint64_cc(0x5eed999cul, 0xc2c22fc2ul),
		mk_sl_cui_uint64_cc(0x6d965c43ul, 0x2e2eb82eul), mk_sl_cui_uint64_cc(0x627a9629ul, 0x4b4b314bul), mk_sl_cui_uint64_cc(0xa321e15dul, 0xfefedffeul), mk_sl_cui_uint64_cc(0x8216aed5ul, 0x57574157ul),
		mk_sl_cui_uint64_cc(0xa8412abdul, 0x15155415ul), mk_sl_cui_uint64_cc(0x9fb6eee8ul, 0x7777c177ul), mk_sl_cui_uint64_cc(0xa5eb6e92ul, 0x3737dc37ul), mk_sl_cui_uint64_cc(0x7b56d79eul, 0xe5e5b3e5ul),
		mk_sl_cui_uint64_cc(0x8cd92313ul, 0x9f9f469ful), mk_sl_cui_uint64_cc(0xd317fd23ul, 0xf0f0e7f0ul), mk_sl_cui_uint64_cc(0x6a7f9420ul, 0x4a4a354aul), mk_sl_cui_uint64_cc(0x9e95a944ul, 0xdada4fdaul),
		mk_sl_cui_uint64_cc(0xfa25b0a2ul, 0x58587d58ul), mk_sl_cui_uint64_cc(0x06ca8fcful, 0xc9c903c9ul), mk_sl_cui_uint64_cc(0x558d527cul, 0x2929a429ul), mk_sl_cui_uint64_cc(0x5022145aul, 0x0a0a280aul),
		mk_sl_cui_uint64_cc(0xe14f7f50ul, 0xb1b1feb1ul), mk_sl_cui_uint64_cc(0x691a5dc9ul, 0xa0a0baa0ul), mk_sl_cui_uint64_cc(0x7fdad614ul, 0x6b6bb16bul), mk_sl_cui_uint64_cc(0x5cab17d9ul, 0x85852e85ul),
		mk_sl_cui_uint64_cc(0x8173673cul, 0xbdbdcebdul), mk_sl_cui_uint64_cc(0xd234ba8ful, 0x5d5d695dul), mk_sl_cui_uint64_cc(0x80502090ul, 0x10104010ul), mk_sl_cui_uint64_cc(0xf303f507ul, 0xf4f4f7f4ul),
		mk_sl_cui_uint64_cc(0x16c08bddul, 0xcbcb0bcbul), mk_sl_cui_uint64_cc(0xedc67cd3ul, 0x3e3ef83eul), mk_sl_cui_uint64_cc(0x28110a2dul, 0x05051405ul), mk_sl_cui_uint64_cc(0x1fe6ce78ul, 0x67678167ul),
		mk_sl_cui_uint64_cc(0x7353d597ul, 0xe4e4b7e4ul), mk_sl_cui_uint64_cc(0x25bb4e02ul, 0x27279c27ul), mk_sl_cui_uint64_cc(0x32588273ul, 0x41411941ul), mk_sl_cui_uint64_cc(0x2c9d0ba7ul, 0x8b8b168bul),
		mk_sl_cui_uint64_cc(0x510153f6ul, 0xa7a7a6a7ul), mk_sl_cui_uint64_cc(0xcf94fab2ul, 0x7d7de97dul), mk_sl_cui_uint64_cc(0xdcfb3749ul, 0x95956e95ul), mk_sl_cui_uint64_cc(0x8e9fad56ul, 0xd8d847d8ul),
		mk_sl_cui_uint64_cc(0x8b30eb70ul, 0xfbfbcbfbul), mk_sl_cui_uint64_cc(0x2371c1cdul, 0xeeee9feeul), mk_sl_cui_uint64_cc(0xc791f8bbul, 0x7c7ced7cul), mk_sl_cui_uint64_cc(0x17e3cc71ul, 0x66668566ul),
		mk_sl_cui_uint64_cc(0xa68ea77bul, 0xdddd53ddul), mk_sl_cui_uint64_cc(0xb84b2eaful, 0x17175c17ul), mk_sl_cui_uint64_cc(0x02468e45ul, 0x47470147ul), mk_sl_cui_uint64_cc(0x84dc211aul, 0x9e9e429eul),
		mk_sl_cui_uint64_cc(0x1ec589d4ul, 0xcaca0fcaul), mk_sl_cui_uint64_cc(0x75995a58ul, 0x2d2db42dul), mk_sl_cui_uint64_cc(0x9179632eul, 0xbfbfc6bful), mk_sl_cui_uint64_cc(0x381b0e3ful, 0x07071c07ul),
		mk_sl_cui_uint64_cc(0x012347acul, 0xadad8eadul), mk_sl_cui_uint64_cc(0xea2fb4b0ul, 0x5a5a755aul), mk_sl_cui_uint64_cc(0x6cb51beful, 0x83833683ul), mk_sl_cui_uint64_cc(0x85ff66b6ul, 0x3333cc33ul),
		mk_sl_cui_uint64_cc(0x3ff2c65cul, 0x63639163ul), mk_sl_cui_uint64_cc(0x100a0412ul, 0x02020802ul), mk_sl_cui_uint64_cc(0x39384993ul, 0xaaaa92aaul), mk_sl_cui_uint64_cc(0xafa8e2deul, 0x7171d971ul),
		mk_sl_cui_uint64_cc(0x0ecf8dc6ul, 0xc8c807c8ul), mk_sl_cui_uint64_cc(0xc87d32d1ul, 0x19196419ul), mk_sl_cui_uint64_cc(0x7270923bul, 0x49493949ul), mk_sl_cui_uint64_cc(0x869aaf5ful, 0xd9d943d9ul),
		mk_sl_cui_uint64_cc(0xc31df931ul, 0xf2f2eff2ul), mk_sl_cui_uint64_cc(0x4b48dba8ul, 0xe3e3abe3ul), mk_sl_cui_uint64_cc(0xe22ab6b9ul, 0x5b5b715bul), mk_sl_cui_uint64_cc(0x34920dbcul, 0x88881a88ul),
		mk_sl_cui_uint64_cc(0xa4c8293eul, 0x9a9a529aul), mk_sl_cui_uint64_cc(0x2dbe4c0bul, 0x26269826ul), mk_sl_cui_uint64_cc(0x8dfa64bful, 0x3232c832ul), mk_sl_cui_uint64_cc(0xe94a7d59ul, 0xb0b0fab0ul),
		mk_sl_cui_uint64_cc(0x1b6acff2ul, 0xe9e983e9ul), mk_sl_cui_uint64_cc(0x78331e77ul, 0x0f0f3c0ful), mk_sl_cui_uint64_cc(0xe6a6b733ul, 0xd5d573d5ul), mk_sl_cui_uint64_cc(0x74ba1df4ul, 0x80803a80ul),
		mk_sl_cui_uint64_cc(0x997c6127ul, 0xbebec2beul), mk_sl_cui_uint64_cc(0x26de87ebul, 0xcdcd13cdul), mk_sl_cui_uint64_cc(0xbde46889ul, 0x3434d034ul), mk_sl_cui_uint64_cc(0x7a759032ul, 0x48483d48ul),
		mk_sl_cui_uint64_cc(0xab24e354ul, 0xffffdbfful), mk_sl_cui_uint64_cc(0xf78ff48dul, 0x7a7af57aul), mk_sl_cui_uint64_cc(0xf4ea3d64ul, 0x90907a90ul), mk_sl_cui_uint64_cc(0xc23ebe9dul, 0x5f5f615ful),
		mk_sl_cui_uint64_cc(0x1da0403dul, 0x20208020ul), mk_sl_cui_uint64_cc(0x67d5d00ful, 0x6868bd68ul), mk_sl_cui_uint64_cc(0xd07234caul, 0x1a1a681aul), mk_sl_cui_uint64_cc(0x192c41b7ul, 0xaeae82aeul),
		mk_sl_cui_uint64_cc(0xc95e757dul, 0xb4b4eab4ul), mk_sl_cui_uint64_cc(0x9a19a8ceul, 0x54544d54ul), mk_sl_cui_uint64_cc(0xece53b7ful, 0x93937693ul), mk_sl_cui_uint64_cc(0x0daa442ful, 0x22228822ul),
		mk_sl_cui_uint64_cc(0x07e9c863ul, 0x64648d64ul), mk_sl_cui_uint64_cc(0xdb12ff2aul, 0xf1f1e3f1ul), mk_sl_cui_uint64_cc(0xbfa2e6ccul, 0x7373d173ul), mk_sl_cui_uint64_cc(0x905a2482ul, 0x12124812ul),
		mk_sl_cui_uint64_cc(0x3a5d807aul, 0x40401d40ul), mk_sl_cui_uint64_cc(0x40281048ul, 0x08082008ul), mk_sl_cui_uint64_cc(0x56e89b95ul, 0xc3c32bc3ul), mk_sl_cui_uint64_cc(0x337bc5dful, 0xecec97ecul),
		mk_sl_cui_uint64_cc(0x9690ab4dul, 0xdbdb4bdbul), mk_sl_cui_uint64_cc(0x611f5fc0ul, 0xa1a1bea1ul), mk_sl_cui_uint64_cc(0x1c830791ul, 0x8d8d0e8dul), mk_sl_cui_uint64_cc(0xf5c97ac8ul, 0x3d3df43dul),
		mk_sl_cui_uint64_cc(0xccf1335bul, 0x97976697ul), mk_sl_cui_uint64_cc(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_cc(0x36d483f9ul, 0xcfcf1bcful), mk_sl_cui_uint64_cc(0x4587566eul, 0x2b2bac2bul),
		mk_sl_cui_uint64_cc(0x97b3ece1ul, 0x7676c576ul), mk_sl_cui_uint64_cc(0x64b019e6ul, 0x82823282ul), mk_sl_cui_uint64_cc(0xfea9b128ul, 0xd6d67fd6ul), mk_sl_cui_uint64_cc(0xd87736c3ul, 0x1b1b6c1bul),
		mk_sl_cui_uint64_cc(0xc15b7774ul, 0xb5b5eeb5ul), mk_sl_cui_uint64_cc(0x112943beul, 0xafaf86aful), mk_sl_cui_uint64_cc(0x77dfd41dul, 0x6a6ab56aul), mk_sl_cui_uint64_cc(0xba0da0eaul, 0x50505d50ul),
		mk_sl_cui_uint64_cc(0x124c8a57ul, 0x45450945ul), mk_sl_cui_uint64_cc(0xcb18fb38ul, 0xf3f3ebf3ul), mk_sl_cui_uint64_cc(0x9df060adul, 0x3030c030ul), mk_sl_cui_uint64_cc(0x2b74c3c4ul, 0xefef9beful),
		mk_sl_cui_uint64_cc(0xe5c37edaul, 0x3f3ffc3ful), mk_sl_cui_uint64_cc(0x921caac7ul, 0x55554955ul), mk_sl_cui_uint64_cc(0x791059dbul, 0xa2a2b2a2ul), mk_sl_cui_uint64_cc(0x0365c9e9ul, 0xeaea8feaul),
		mk_sl_cui_uint64_cc(0x0fecca6aul, 0x65658965ul), mk_sl_cui_uint64_cc(0xb9686903ul, 0xbabad2baul), mk_sl_cui_uint64_cc(0x65935e4aul, 0x2f2fbc2ful), mk_sl_cui_uint64_cc(0x4ee79d8eul, 0xc0c027c0ul),
		mk_sl_cui_uint64_cc(0xbe81a160ul, 0xdede5fdeul), mk_sl_cui_uint64_cc(0xe06c38fcul, 0x1c1c701cul), mk_sl_cui_uint64_cc(0xbb2ee746ul, 0xfdfdd3fdul), mk_sl_cui_uint64_cc(0x52649a1ful, 0x4d4d294dul),
		mk_sl_cui_uint64_cc(0xe4e03976ul, 0x92927292ul), mk_sl_cui_uint64_cc(0x8fbceafaul, 0x7575c975ul), mk_sl_cui_uint64_cc(0x301e0c36ul, 0x06061806ul), mk_sl_cui_uint64_cc(0x249809aeul, 0x8a8a128aul),
		mk_sl_cui_uint64_cc(0xf940794bul, 0xb2b2f2b2ul), mk_sl_cui_uint64_cc(0x6359d185ul, 0xe6e6bfe6ul), mk_sl_cui_uint64_cc(0x70361c7eul, 0x0e0e380eul), mk_sl_cui_uint64_cc(0xf8633ee7ul, 0x1f1f7c1ful),
		mk_sl_cui_uint64_cc(0x37f7c455ul, 0x62629562ul), mk_sl_cui_uint64_cc(0xeea3b53aul, 0xd4d477d4ul), mk_sl_cui_uint64_cc(0x29324d81ul, 0xa8a89aa8ul), mk_sl_cui_uint64_cc(0xc4f43152ul, 0x96966296ul),
		mk_sl_cui_uint64_cc(0x9b3aef62ul, 0xf9f9c3f9ul), mk_sl_cui_uint64_cc(0x66f697a3ul, 0xc5c533c5ul), mk_sl_cui_uint64_cc(0x35b14a10ul, 0x25259425ul), mk_sl_cui_uint64_cc(0xf220b2abul, 0x59597959ul),
		mk_sl_cui_uint64_cc(0x54ae15d0ul, 0x84842a84ul), mk_sl_cui_uint64_cc(0xb7a7e4c5ul, 0x7272d572ul), mk_sl_cui_uint64_cc(0xd5dd72ecul, 0x3939e439ul), mk_sl_cui_uint64_cc(0x5a619816ul, 0x4c4c2d4cul),
		mk_sl_cui_uint64_cc(0xca3bbc94ul, 0x5e5e655eul), mk_sl_cui_uint64_cc(0xe785f09ful, 0x7878fd78ul), mk_sl_cui_uint64_cc(0xddd870e5ul, 0x3838e038ul), mk_sl_cui_uint64_cc(0x14860598ul, 0x8c8c0a8cul),
		mk_sl_cui_uint64_cc(0xc6b2bf17ul, 0xd1d163d1ul), mk_sl_cui_uint64_cc(0x410b57e4ul, 0xa5a5aea5ul), mk_sl_cui_uint64_cc(0x434dd9a1ul, 0xe2e2afe2ul), mk_sl_cui_uint64_cc(0x2ff8c24eul, 0x61619961ul),
		mk_sl_cui_uint64_cc(0xf1457b42ul, 0xb3b3f6b3ul), mk_sl_cui_uint64_cc(0x15a54234ul, 0x21218421ul), mk_sl_cui_uint64_cc(0x94d62508ul, 0x9c9c4a9cul), mk_sl_cui_uint64_cc(0xf0663ceeul, 0x1e1e781eul),
		mk_sl_cui_uint64_cc(0x22528661ul, 0x43431143ul), mk_sl_cui_uint64_cc(0x76fc93b1ul, 0xc7c73bc7ul), mk_sl_cui_uint64_cc(0xb32be54ful, 0xfcfcd7fcul), mk_sl_cui_uint64_cc(0x20140824ul, 0x04041004ul),
		mk_sl_cui_uint64_cc(0xb208a2e3ul, 0x51515951ul), mk_sl_cui_uint64_cc(0xbcc72f25ul, 0x99995e99ul), mk_sl_cui_uint64_cc(0x4fc4da22ul, 0x6d6da96dul), mk_sl_cui_uint64_cc(0x68391a65ul, 0x0d0d340dul),
		mk_sl_cui_uint64_cc(0x8335e979ul, 0xfafacffaul), mk_sl_cui_uint64_cc(0xb684a369ul, 0xdfdf5bdful), mk_sl_cui_uint64_cc(0xd79bfca9ul, 0x7e7ee57eul), mk_sl_cui_uint64_cc(0x3db44819ul, 0x24249024ul),
		mk_sl_cui_uint64_cc(0xc5d776feul, 0x3b3bec3bul), mk_sl_cui_uint64_cc(0x313d4b9aul, 0xabab96abul), mk_sl_cui_uint64_cc(0x3ed181f0ul, 0xcece1fceul), mk_sl_cui_uint64_cc(0x88552299ul, 0x11114411ul),
		mk_sl_cui_uint64_cc(0x0c890383ul, 0x8f8f068ful), mk_sl_cui_uint64_cc(0x4a6b9c04ul, 0x4e4e254eul), mk_sl_cui_uint64_cc(0xd1517366ul, 0xb7b7e6b7ul), mk_sl_cui_uint64_cc(0x0b60cbe0ul, 0xebeb8bebul),
		mk_sl_cui_uint64_cc(0xfdcc78c1ul, 0x3c3cf03cul), mk_sl_cui_uint64_cc(0x7cbf1ffdul, 0x81813e81ul), mk_sl_cui_uint64_cc(0xd4fe3540ul, 0x94946a94ul), mk_sl_cui_uint64_cc(0xeb0cf31cul, 0xf7f7fbf7ul),
		mk_sl_cui_uint64_cc(0xa1676f18ul, 0xb9b9deb9ul), mk_sl_cui_uint64_cc(0x985f268bul, 0x13134c13ul), mk_sl_cui_uint64_cc(0x7d9c5851ul, 0x2c2cb02cul), mk_sl_cui_uint64_cc(0xd6b8bb05ul, 0xd3d36bd3ul),
		mk_sl_cui_uint64_cc(0x6b5cd38cul, 0xe7e7bbe7ul), mk_sl_cui_uint64_cc(0x57cbdc39ul, 0x6e6ea56eul), mk_sl_cui_uint64_cc(0x6ef395aaul, 0xc4c437c4ul), mk_sl_cui_uint64_cc(0x180f061bul, 0x03030c03ul),
		mk_sl_cui_uint64_cc(0x8a13acdcul, 0x56564556ul), mk_sl_cui_uint64_cc(0x1a49885eul, 0x44440d44ul), mk_sl_cui_uint64_cc(0xdf9efea0ul, 0x7f7fe17ful), mk_sl_cui_uint64_cc(0x21374f88ul, 0xa9a99ea9ul),
		mk_sl_cui_uint64_cc(0x4d825467ul, 0x2a2aa82aul), mk_sl_cui_uint64_cc(0xb16d6b0aul, 0xbbbbd6bbul), mk_sl_cui_uint64_cc(0x46e29f87ul, 0xc1c123c1ul), mk_sl_cui_uint64_cc(0xa202a6f1ul, 0x53535153ul),
		mk_sl_cui_uint64_cc(0xae8ba572ul, 0xdcdc57dcul), mk_sl_cui_uint64_cc(0x58271653ul, 0x0b0b2c0bul), mk_sl_cui_uint64_cc(0x9cd32701ul, 0x9d9d4e9dul), mk_sl_cui_uint64_cc(0x47c1d82bul, 0x6c6cad6cul),
		mk_sl_cui_uint64_cc(0x95f562a4ul, 0x3131c431ul), mk_sl_cui_uint64_cc(0x87b9e8f3ul, 0x7474cd74ul), mk_sl_cui_uint64_cc(0xe309f115ul, 0xf6f6fff6ul), mk_sl_cui_uint64_cc(0x0a438c4cul, 0x46460546ul),
		mk_sl_cui_uint64_cc(0x092645a5ul, 0xacac8aacul), mk_sl_cui_uint64_cc(0x3c970fb5ul, 0x89891e89ul), mk_sl_cui_uint64_cc(0xa04428b4ul, 0x14145014ul), mk_sl_cui_uint64_cc(0x5b42dfbaul, 0xe1e1a3e1ul),
		mk_sl_cui_uint64_cc(0xb04e2ca6ul, 0x16165816ul), mk_sl_cui_uint64_cc(0xcdd274f7ul, 0x3a3ae83aul), mk_sl_cui_uint64_cc(0x6fd0d206ul, 0x6969b969ul), mk_sl_cui_uint64_cc(0x482d1241ul, 0x09092409ul),
		mk_sl_cui_uint64_cc(0xa7ade0d7ul, 0x7070dd70ul), mk_sl_cui_uint64_cc(0xd954716ful, 0xb6b6e2b6ul), mk_sl_cui_uint64_cc(0xceb7bd1eul, 0xd0d067d0ul), mk_sl_cui_uint64_cc(0x3b7ec7d6ul, 0xeded93edul),
		mk_sl_cui_uint64_cc(0x2edb85e2ul, 0xcccc17ccul), mk_sl_cui_uint64_cc(0x2a578468ul, 0x42421542ul), mk_sl_cui_uint64_cc(0xb4c22d2cul, 0x98985a98ul), mk_sl_cui_uint64_cc(0x490e55edul, 0xa4a4aaa4ul),
		mk_sl_cui_uint64_cc(0x5d885075ul, 0x2828a028ul), mk_sl_cui_uint64_cc(0xda31b886ul, 0x5c5c6d5cul), mk_sl_cui_uint64_cc(0x933fed6bul, 0xf8f8c7f8ul), mk_sl_cui_uint64_cc(0x44a411c2ul, 0x86862286ul),
	}}},
	{{{
		mk_sl_cui_uint64_cc(0x18c07830ul, 0xd8181860ul), mk_sl_cui_uint64_cc(0x2305af46ul, 0x2623238cul), mk_sl_cui_uint64_cc(0xc67ef991ul, 0xb8c6c63ful), mk_sl_cui_uint64_cc(0xe8136fcdul, 0xfbe8e887ul),
		mk_sl_cui_uint64_cc(0x874ca113ul, 0xcb878726ul), mk_sl_cui_uint64_cc(0xb8a9626dul, 0x11b8b8daul), mk_sl_cui_uint64_cc(0x01080502ul, 0x09010104ul), mk_sl_cui_uint64_cc(0x4f426e9eul, 0x0d4f4f21ul),
		mk_sl_cui_uint64_cc(0x36adee6cul, 0x9b3636d8ul), mk_sl_cui_uint64_cc(0xa6590451ul, 0xffa6a6a2ul), mk_sl_cui_uint64_cc(0xd2debdb9ul, 0x0cd2d26ful), mk_sl_cui_uint64_cc(0xf5fb06f7ul, 0x0ef5f5f3ul),
		mk_sl_cui_uint64_cc(0x79ef80f2ul, 0x967979f9ul), mk_sl_cui_uint64_cc(0x6f5fcedeul, 0x306f6fa1ul), mk_sl_cui_uint64_cc(0x91fcef3ful, 0x6d91917eul), mk_sl_cui_uint64_cc(0x52aa07a4ul, 0xf8525255ul),
		mk_sl_cui_uint64_cc(0x6027fdc0ul, 0x4760609dul), mk_sl_cui_uint64_cc(0xbc897665ul, 0x35bcbccaul), mk_sl_cui_uint64_cc(0x9baccd2bul, 0x379b9b56ul), mk_sl_cui_uint64_cc(0x8e048c01ul, 0x8a8e8e02ul),
		mk_sl_cui_uint64_cc(0xa371155bul, 0xd2a3a3b6ul), mk_sl_cui_uint64_cc(0x0c603c18ul, 0x6c0c0c30ul), mk_sl_cui_uint64_cc(0x7bff8af6ul, 0x847b7bf1ul), mk_sl_cui_uint64_cc(0x35b5e16aul, 0x803535d4ul),
		mk_sl_cui_uint64_cc(0x1de8693aul, 0xf51d1d74ul), mk_sl_cui_uint64_cc(0xe05347ddul, 0xb3e0e0a7ul), mk_sl_cui_uint64_cc(0xd7f6acb3ul, 0x21d7d77bul), mk_sl_cui_uint64_cc(0xc25eed99ul, 0x9cc2c22ful),
		mk_sl_cui_uint64_cc(0x2e6d965cul, 0x432e2eb8ul), mk_sl_cui_uint64_cc(0x4b627a96ul, 0x294b4b31ul), mk_sl_cui_uint64_cc(0xfea321e1ul, 0x5dfefedful), mk_sl_cui_uint64_cc(0x578216aeul, 0xd5575741ul),
		mk_sl_cui_uint64_cc(0x15a8412aul, 0xbd151554ul), mk_sl_cui_uint64_cc(0x779fb6eeul, 0xe87777c1ul), mk_sl_cui_uint64_cc(0x37a5eb6eul, 0x923737dcul), mk_sl_cui_uint64_cc(0xe57b56d7ul, 0x9ee5e5b3ul),
		mk_sl_cui_uint64_cc(0x9f8cd923ul, 0x139f9f46ul), mk_sl_cui_uint64_cc(0xf0d317fdul, 0x23f0f0e7ul), mk_sl_cui_uint64_cc(0x4a6a7f94ul, 0x204a4a35ul), mk_sl_cui_uint64_cc(0xda9e95a9ul, 0x44dada4ful),
		mk_sl_cui_uint64_cc(0x58fa25b0ul, 0xa258587dul), mk_sl_cui_uint64_cc(0xc906ca8ful, 0xcfc9c903ul), mk_sl_cui_uint64_cc(0x29558d52ul, 0x7c2929a4ul), mk_sl_cui_uint64_cc(0x0a502214ul, 0x5a0a0a28ul),
		mk_sl_cui_uint64_cc(0xb1e14f7ful, 0x50b1b1feul), mk_sl_cui_uint64_cc(0xa0691a5dul, 0xc9a0a0baul), mk_sl_cui_uint64_cc(0x6b7fdad6ul, 0x146b6bb1ul), mk_sl_cui_uint64_cc(0x855cab17ul, 0xd985852eul),
		mk_sl_cui_uint64_cc(0xbd817367ul, 0x3cbdbdceul), mk_sl_cui_uint64_cc(0x5dd234baul, 0x8f5d5d69ul), mk_sl_cui_uint64_cc(0x10805020ul, 0x90101040ul), mk_sl_cui_uint64_cc(0xf4f303f5ul, 0x07f4f4f7ul),
		mk_sl_cui_uint64_cc(0xcb16c08bul, 0xddcbcb0bul), mk_sl_cui_uint64_cc(0x3eedc67cul, 0xd33e3ef8ul), mk_sl_cui_uint64_cc(0x0528110aul, 0x2d050514ul), mk_sl_cui_uint64_cc(0x671fe6ceul, 0x78676781ul),
		mk_sl_cui_uint64_cc(0xe47353d5ul, 0x97e4e4b7ul), mk_sl_cui_uint64_cc(0x2725bb4eul, 0x0227279cul), mk_sl_cui_uint64_cc(0x41325882ul, 0x73414119ul), mk_sl_cui_uint64_cc(0x8b2c9d0bul, 0xa78b8b16ul),
		mk_sl_cui_uint64_cc(0xa7510153ul, 0xf6a7a7a6ul), mk_sl_cui_uint64_cc(0x7dcf94faul, 0xb27d7de9ul), mk_sl_cui_uint64_cc(0x95dcfb37ul, 0x4995956eul), mk_sl_cui_uint64_cc(0xd88e9fadul, 0x56d8d847ul),
		mk_sl_cui_uint64_cc(0xfb8b30ebul, 0x70fbfbcbul), mk_sl_cui_uint64_cc(0xee2371c1ul, 0xcdeeee9ful), mk_sl_cui_uint64_cc(0x7cc791f8ul, 0xbb7c7cedul), mk_sl_cui_uint64_cc(0x6617e3ccul, 0x71666685ul),
		mk_sl_cui_uint64_cc(0xdda68ea7ul, 0x7bdddd53ul), mk_sl_cui_uint64_cc(0x17b84b2eul, 0xaf17175cul), mk_sl_cui_uint64_cc(0x4702468eul, 0x45474701ul), mk_sl_cui_uint64_cc(0x9e84dc21ul, 0x1a9e9e42ul),
		mk_sl_cui_uint64_cc(0xca1ec589ul, 0xd4caca0ful), mk_sl_cui_uint64_cc(0x2d75995aul, 0x582d2db4ul), mk_sl_cui_uint64_cc(0xbf917963ul, 0x2ebfbfc6ul), mk_sl_cui_uint64_cc(0x07381b0eul, 0x3f07071cul),
		mk_sl_cui_uint64_cc(0xad012347ul, 0xacadad8eul), mk_sl_cui_uint64_cc(0x5aea2fb4ul, 0xb05a5a75ul), mk_sl_cui_uint64_cc(0x836cb51bul, 0xef838336ul), mk_sl_cui_uint64_cc(0x3385ff66ul, 0xb63333ccul),
		mk_sl_cui_uint64_cc(0x633ff2c6ul, 0x5c636391ul), mk_sl_cui_uint64_cc(0x02100a04ul, 0x12020208ul), mk_sl_cui_uint64_cc(0xaa393849ul, 0x93aaaa92ul), mk_sl_cui_uint64_cc(0x71afa8e2ul, 0xde7171d9ul),
		mk_sl_cui_uint64_cc(0xc80ecf8dul, 0xc6c8c807ul), mk_sl_cui_uint64_cc(0x19c87d32ul, 0xd1191964ul), mk_sl_cui_uint64_cc(0x49727092ul, 0x3b494939ul), mk_sl_cui_uint64_cc(0xd9869aaful, 0x5fd9d943ul),
		mk_sl_cui_uint64_cc(0xf2c31df9ul, 0x31f2f2eful), mk_sl_cui_uint64_cc(0xe34b48dbul, 0xa8e3e3abul), mk_sl_cui_uint64_cc(0x5be22ab6ul, 0xb95b5b71ul), mk_sl_cui_uint64_cc(0x8834920dul, 0xbc88881aul),
		mk_sl_cui_uint64_cc(0x9aa4c829ul, 0x3e9a9a52ul), mk_sl_cui_uint64_cc(0x262dbe4cul, 0x0b262698ul), mk_sl_cui_uint64_cc(0x328dfa64ul, 0xbf3232c8ul), mk_sl_cui_uint64_cc(0xb0e94a7dul, 0x59b0b0faul),
		mk_sl_cui_uint64_cc(0xe91b6acful, 0xf2e9e983ul), mk_sl_cui_uint64_cc(0x0f78331eul, 0x770f0f3cul), mk_sl_cui_uint64_cc(0xd5e6a6b7ul, 0x33d5d573ul), mk_sl_cui_uint64_cc(0x8074ba1dul, 0xf480803aul),
		mk_sl_cui_uint64_cc(0xbe997c61ul, 0x27bebec2ul), mk_sl_cui_uint64_cc(0xcd26de87ul, 0xebcdcd13ul), mk_sl_cui_uint64_cc(0x34bde468ul, 0x893434d0ul), mk_sl_cui_uint64_cc(0x487a7590ul, 0x3248483dul),
		mk_sl_cui_uint64_cc(0xffab24e3ul, 0x54ffffdbul), mk_sl_cui_uint64_cc(0x7af78ff4ul, 0x8d7a7af5ul), mk_sl_cui_uint64_cc(0x90f4ea3dul, 0x6490907aul), mk_sl_cui_uint64_cc(0x5fc23ebeul, 0x9d5f5f61ul),
		mk_sl_cui_uint64_cc(0x201da040ul, 0x3d202080ul), mk_sl_cui_uint64_cc(0x6867d5d0ul, 0x0f6868bdul), mk_sl_cui_uint64_cc(0x1ad07234ul, 0xca1a1a68ul), mk_sl_cui_uint64_cc(0xae192c41ul, 0xb7aeae82ul),
		mk_sl_cui_uint64_cc(0xb4c95e75ul, 0x7db4b4eaul), mk_sl_cui_uint64_cc(0x549a19a8ul, 0xce54544dul), mk_sl_cui_uint64_cc(0x93ece53bul, 0x7f939376ul), mk_sl_cui_uint64_cc(0x220daa44ul, 0x2f222288ul),
		mk_sl_cui_uint64_cc(0x6407e9c8ul, 0x6364648dul), mk_sl_cui_uint64_cc(0xf1db12fful, 0x2af1f1e3ul), mk_sl_cui_uint64_cc(0x73bfa2e6ul, 0xcc7373d1ul), mk_sl_cui_uint64_cc(0x12905a24ul, 0x82121248ul),
		mk_sl_cui_uint64_cc(0x403a5d80ul, 0x7a40401dul), mk_sl_cui_uint64_cc(0x08402810ul, 0x48080820ul), mk_sl_cui_uint64_cc(0xc356e89bul, 0x95c3c32bul), mk_sl_cui_uint64_cc(0xec337bc5ul, 0xdfecec97ul),
		mk_sl_cui_uint64_cc(0xdb9690abul, 0x4ddbdb4bul), mk_sl_cui_uint64_cc(0xa1611f5ful, 0xc0a1a1beul), mk_sl_cui_uint64_cc(0x8d1c8307ul, 0x918d8d0eul), mk_sl_cui_uint64_cc(0x3df5c97aul, 0xc83d3df4ul),
		mk_sl_cui_uint64_cc(0x97ccf133ul, 0x5b979766ul), mk_sl_cui_uint64_cc(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_cc(0xcf36d483ul, 0xf9cfcf1bul), mk_sl_cui_uint64_cc(0x2b458756ul, 0x6e2b2bacul),
		mk_sl_cui_uint64_cc(0x7697b3ecul, 0xe17676c5ul), mk_sl_cui_uint64_cc(0x8264b019ul, 0xe6828232ul), mk_sl_cui_uint64_cc(0xd6fea9b1ul, 0x28d6d67ful), mk_sl_cui_uint64_cc(0x1bd87736ul, 0xc31b1b6cul),
		mk_sl_cui_uint64_cc(0xb5c15b77ul, 0x74b5b5eeul), mk_sl_cui_uint64_cc(0xaf112943ul, 0xbeafaf86ul), mk_sl_cui_uint64_cc(0x6a77dfd4ul, 0x1d6a6ab5ul), mk_sl_cui_uint64_cc(0x50ba0da0ul, 0xea50505dul),
		mk_sl_cui_uint64_cc(0x45124c8aul, 0x57454509ul), mk_sl_cui_uint64_cc(0xf3cb18fbul, 0x38f3f3ebul), mk_sl_cui_uint64_cc(0x309df060ul, 0xad3030c0ul), mk_sl_cui_uint64_cc(0xef2b74c3ul, 0xc4efef9bul),
		mk_sl_cui_uint64_cc(0x3fe5c37eul, 0xda3f3ffcul), mk_sl_cui_uint64_cc(0x55921caaul, 0xc7555549ul), mk_sl_cui_uint64_cc(0xa2791059ul, 0xdba2a2b2ul), mk_sl_cui_uint64_cc(0xea0365c9ul, 0xe9eaea8ful),
		mk_sl_cui_uint64_cc(0x650feccaul, 0x6a656589ul), mk_sl_cui_uint64_cc(0xbab96869ul, 0x03babad2ul), mk_sl_cui_uint64_cc(0x2f65935eul, 0x4a2f2fbcul), mk_sl_cui_uint64_cc(0xc04ee79dul, 0x8ec0c027ul),
		mk_sl_cui_uint64_cc(0xdebe81a1ul, 0x60dede5ful), mk_sl_cui_uint64_cc(0x1ce06c38ul, 0xfc1c1c70ul), mk_sl_cui_uint64_cc(0xfdbb2ee7ul, 0x46fdfdd3ul), mk_sl_cui_uint64_cc(0x4d52649aul, 0x1f4d4d29ul),
		mk_sl_cui_uint64_cc(0x92e4e039ul, 0x76929272ul), mk_sl_cui_uint64_cc(0x758fbceaul, 0xfa7575c9ul), mk_sl_cui_uint64_cc(0x06301e0cul, 0x36060618ul), mk_sl_cui_uint64_cc(0x8a249809ul, 0xae8a8a12ul),
		mk_sl_cui_uint64_cc(0xb2f94079ul, 0x4bb2b2f2ul), mk_sl_cui_uint64_cc(0xe66359d1ul, 0x85e6e6bful), mk_sl_cui_uint64_cc(0x0e70361cul, 0x7e0e0e38ul), mk_sl_cui_uint64_cc(0x1ff8633eul, 0xe71f1f7cul),
		mk_sl_cui_uint64_cc(0x6237f7c4ul, 0x55626295ul), mk_sl_cui_uint64_cc(0xd4eea3b5ul, 0x3ad4d477ul), mk_sl_cui_uint64_cc(0xa829324dul, 0x81a8a89aul), mk_sl_cui_uint64_cc(0x96c4f431ul, 0x52969662ul),
		mk_sl_cui_uint64_cc(0xf99b3aeful, 0x62f9f9c3ul), mk_sl_cui_uint64_cc(0xc566f697ul, 0xa3c5c533ul), mk_sl_cui_uint64_cc(0x2535b14aul, 0x10252594ul), mk_sl_cui_uint64_cc(0x59f220b2ul, 0xab595979ul),
		mk_sl_cui_uint64_cc(0x8454ae15ul, 0xd084842aul), mk_sl_cui_uint64_cc(0x72b7a7e4ul, 0xc57272d5ul), mk_sl_cui_uint64_cc(0x39d5dd72ul, 0xec3939e4ul), mk_sl_cui_uint64_cc(0x4c5a6198ul, 0x164c4c2dul),
		mk_sl_cui_uint64_cc(0x5eca3bbcul, 0x945e5e65ul), mk_sl_cui_uint64_cc(0x78e785f0ul, 0x9f7878fdul), mk_sl_cui_uint64_cc(0x38ddd870ul, 0xe53838e0ul), mk_sl_cui_uint64_cc(0x8c148605ul, 0x988c8c0aul),
		mk_sl_cui_uint64_cc(0xd1c6b2bful, 0x17d1d163ul), mk_sl_cui_uint64_cc(0xa5410b57ul, 0xe4a5a5aeul), mk_sl_cui_uint64_cc(0xe2434dd9ul, 0xa1e2e2aful), mk_sl_cui_uint64_cc(0x612ff8c2ul, 0x4e616199ul),
		mk_sl_cui_uint64_cc(0xb3f1457bul, 0x42b3b3f6ul), mk_sl_cui_uint64_cc(0x2115a542ul, 0x34212184ul), mk_sl_cui_uint64_cc(0x9c94d625ul, 0x089c9c4aul), mk_sl_cui_uint64_cc(0x1ef0663cul, 0xee1e1e78ul),
		mk_sl_cui_uint64_cc(0x43225286ul, 0x61434311ul), mk_sl_cui_uint64_cc(0xc776fc93ul, 0xb1c7c73bul), mk_sl_cui_uint64_cc(0xfcb32be5ul, 0x4ffcfcd7ul), mk_sl_cui_uint64_cc(0x04201408ul, 0x24040410ul),
		mk_sl_cui_uint64_cc(0x51b208a2ul, 0xe3515159ul), mk_sl_cui_uint64_cc(0x99bcc72ful, 0x2599995eul), mk_sl_cui_uint64_cc(0x6d4fc4daul, 0x226d6da9ul), mk_sl_cui_uint64_cc(0x0d68391aul, 0x650d0d34ul),
		mk_sl_cui_uint64_cc(0xfa8335e9ul, 0x79fafacful), mk_sl_cui_uint64_cc(0xdfb684a3ul, 0x69dfdf5bul), mk_sl_cui_uint64_cc(0x7ed79bfcul, 0xa97e7ee5ul), mk_sl_cui_uint64_cc(0x243db448ul, 0x19242490ul),
		mk_sl_cui_uint64_cc(0x3bc5d776ul, 0xfe3b3becul), mk_sl_cui_uint64_cc(0xab313d4bul, 0x9aabab96ul), mk_sl_cui_uint64_cc(0xce3ed181ul, 0xf0cece1ful), mk_sl_cui_uint64_cc(0x11885522ul, 0x99111144ul),
		mk_sl_cui_uint64_cc(0x8f0c8903ul, 0x838f8f06ul), mk_sl_cui_uint64_cc(0x4e4a6b9cul, 0x044e4e25ul), mk_sl_cui_uint64_cc(0xb7d15173ul, 0x66b7b7e6ul), mk_sl_cui_uint64_cc(0xeb0b60cbul, 0xe0ebeb8bul),
		mk_sl_cui_uint64_cc(0x3cfdcc78ul, 0xc13c3cf0ul), mk_sl_cui_uint64_cc(0x817cbf1ful, 0xfd81813eul), mk_sl_cui_uint64_cc(0x94d4fe35ul, 0x4094946aul), mk_sl_cui_uint64_cc(0xf7eb0cf3ul, 0x1cf7f7fbul),
		mk_sl_cui_uint64_cc(0xb9a1676ful, 0x18b9b9deul), mk_sl_cui_uint64_cc(0x13985f26ul, 0x8b13134cul), mk_sl_cui_uint64_cc(0x2c7d9c58ul, 0x512c2cb0ul), mk_sl_cui_uint64_cc(0xd3d6b8bbul, 0x05d3d36bul),
		mk_sl_cui_uint64_cc(0xe76b5cd3ul, 0x8ce7e7bbul), mk_sl_cui_uint64_cc(0x6e57cbdcul, 0x396e6ea5ul), mk_sl_cui_uint64_cc(0xc46ef395ul, 0xaac4c437ul), mk_sl_cui_uint64_cc(0x03180f06ul, 0x1b03030cul),
		mk_sl_cui_uint64_cc(0x568a13acul, 0xdc565645ul), mk_sl_cui_uint64_cc(0x441a4988ul, 0x5e44440dul), mk_sl_cui_uint64_cc(0x7fdf9efeul, 0xa07f7fe1ul), mk_sl_cui_uint64_cc(0xa921374ful, 0x88a9a99eul),
		mk_sl_cui_uint64_cc(0x2a4d8254ul, 0x672a2aa8ul), mk_sl_cui_uint64_cc(0xbbb16d6bul, 0x0abbbbd6ul), mk_sl_cui_uint64_cc(0xc146e29ful, 0x87c1c123ul), mk_sl_cui_uint64_cc(0x53a202a6ul, 0xf1535351ul),
		mk_sl_cui_uint64_cc(0xdcae8ba5ul, 0x72dcdc57ul), mk_sl_cui_uint64_cc(0x0b582716ul, 0x530b0b2cul), mk_sl_cui_uint64_cc(0x9d9cd327ul, 0x019d9d4eul), mk_sl_cui_uint64_cc(0x6c47c1d8ul, 0x2b6c6cadul),
		mk_sl_cui_uint64_cc(0x3195f562ul, 0xa43131c4ul), mk_sl_cui_uint64_cc(0x7487b9e8ul, 0xf37474cdul), mk_sl_cui_uint64_cc(0xf6e309f1ul, 0x15f6f6fful), mk_sl_cui_uint64_cc(0x460a438cul, 0x4c464605ul),
		mk_sl_cui_uint64_cc(0xac092645ul, 0xa5acac8aul), mk_sl_cui_uint64_cc(0x893c970ful, 0xb589891eul), mk_sl_cui_uint64_cc(0x14a04428ul, 0xb4141450ul), mk_sl_cui_uint64_cc(0xe15b42dful, 0xbae1e1a3ul),
		mk_sl_cui_uint64_cc(0x16b04e2cul, 0xa6161658ul), mk_sl_cui_uint64_cc(0x3acdd274ul, 0xf73a3ae8ul), mk_sl_cui_uint64_cc(0x696fd0d2ul, 0x066969b9ul), mk_sl_cui_uint64_cc(0x09482d12ul, 0x41090924ul),
		mk_sl_cui_uint64_cc(0x70a7ade0ul, 0xd77070ddul), mk_sl_cui_uint64_cc(0xb6d95471ul, 0x6fb6b6e2ul), mk_sl_cui_uint64_cc(0xd0ceb7bdul, 0x1ed0d067ul), mk_sl_cui_uint64_cc(0xed3b7ec7ul, 0xd6eded93ul),
		mk_sl_cui_uint64_cc(0xcc2edb85ul, 0xe2cccc17ul), mk_sl_cui_uint64_cc(0x422a5784ul, 0x68424215ul), mk_sl_cui_uint64_cc(0x98b4c22dul, 0x2c98985aul), mk_sl_cui_uint64_cc(0xa4490e55ul, 0xeda4a4aaul),
		mk_sl_cui_uint64_cc(0x285d8850ul, 0x752828a0ul), mk_sl_cui_uint64_cc(0x5cda31b8ul, 0x865c5c6dul), mk_sl_cui_uint64_cc(0xf8933fedul, 0x6bf8f8c7ul), mk_sl_cui_uint64_cc(0x8644a411ul, 0xc2868622ul),
	}}},
	{{{
		mk_sl_cui_uint64_cc(0x6018c078ul, 0x30d81818ul), mk_sl_cui_uint64_cc(0x8c2305aful, 0x46262323ul), mk_sl_cui_uint64_cc(0x3fc67ef9ul, 0x91b8c6c6ul), mk_sl_cui_uint64_cc(0x87e8136ful, 0xcdfbe8e8ul),
		mk_sl_cui_uint64_cc(0x26874ca1ul, 0x13cb8787ul), mk_sl_cui_uint64_cc(0xdab8a962ul, 0x6d11b8b8ul), mk_sl_cui_uint64_cc(0x04010805ul, 0x02090101ul), mk_sl_cui_uint64_cc(0x214f426eul, 0x9e0d4f4ful),
		mk_sl_cui_uint64_cc(0xd836adeeul, 0x6c9b3636ul), mk_sl_cui_uint64_cc(0xa2a65904ul, 0x51ffa6a6ul), mk_sl_cui_uint64_cc(0x6fd2debdul, 0xb90cd2d2ul), mk_sl_cui_uint64_cc(0xf3f5fb06ul, 0xf70ef5f5ul),
		mk_sl_cui_uint64_cc(0xf979ef80ul, 0xf2967979ul), mk_sl_cui_uint64_cc(0xa16f5fceul, 0xde306f6ful), mk_sl_cui_uint64_cc(0x7e91fceful, 0x3f6d9191ul), mk_sl_cui_uint64_cc(0x5552aa07ul, 0xa4f85252ul),
		mk_sl_cui_uint64_cc(0x9d6027fdul, 0xc0476060ul), mk_sl_cui_uint64_cc(0xcabc8976ul, 0x6535bcbcul), mk_sl_cui_uint64_cc(0x569baccdul, 0x2b379b9bul), mk_sl_cui_uint64_cc(0x028e048cul, 0x018a8e8eul),
		mk_sl_cui_uint64_cc(0xb6a37115ul, 0x5bd2a3a3ul), mk_sl_cui_uint64_cc(0x300c603cul, 0x186c0c0cul), mk_sl_cui_uint64_cc(0xf17bff8aul, 0xf6847b7bul), mk_sl_cui_uint64_cc(0xd435b5e1ul, 0x6a803535ul),
		mk_sl_cui_uint64_cc(0x741de869ul, 0x3af51d1dul), mk_sl_cui_uint64_cc(0xa7e05347ul, 0xddb3e0e0ul), mk_sl_cui_uint64_cc(0x7bd7f6acul, 0xb321d7d7ul), mk_sl_cui_uint64_cc(0x2fc25eedul, 0x999cc2c2ul),
		mk_sl_cui_uint64_cc(0xb82e6d96ul, 0x5c432e2eul), mk_sl_cui_uint64_cc(0x314b627aul, 0x96294b4bul), mk_sl_cui_uint64_cc(0xdffea321ul, 0xe15dfefeul), mk_sl_cui_uint64_cc(0x41578216ul, 0xaed55757ul),
		mk_sl_cui_uint64_cc(0x5415a841ul, 0x2abd1515ul), mk_sl_cui_uint64_cc(0xc1779fb6ul, 0xeee87777ul), mk_sl_cui_uint64_cc(0xdc37a5ebul, 0x6e923737ul), mk_sl_cui_uint64_cc(0xb3e57b56ul, 0xd79ee5e5ul),
		mk_sl_cui_uint64_cc(0x469f8cd9ul, 0x23139f9ful), mk_sl_cui_uint64_cc(0xe7f0d317ul, 0xfd23f0f0ul), mk_sl_cui_uint64_cc(0x354a6a7ful, 0x94204a4aul), mk_sl_cui_uint64_cc(0x4fda9e95ul, 0xa944dadaul),
		mk_sl_cui_uint64_cc(0x7d58fa25ul, 0xb0a25858ul), mk_sl_cui_uint64_cc(0x03c906caul, 0x8fcfc9c9ul), mk_sl_cui_uint64_cc(0xa429558dul, 0x527c2929ul), mk_sl_cui_uint64_cc(0x280a5022ul, 0x145a0a0aul),
		mk_sl_cui_uint64_cc(0xfeb1e14ful, 0x7f50b1b1ul), mk_sl_cui_uint64_cc(0xbaa0691aul, 0x5dc9a0a0ul), mk_sl_cui_uint64_cc(0xb16b7fdaul, 0xd6146b6bul), mk_sl_cui_uint64_cc(0x2e855cabul, 0x17d98585ul),
		mk_sl_cui_uint64_cc(0xcebd8173ul, 0x673cbdbdul), mk_sl_cui_uint64_cc(0x695dd234ul, 0xba8f5d5dul), mk_sl_cui_uint64_cc(0x40108050ul, 0x20901010ul), mk_sl_cui_uint64_cc(0xf7f4f303ul, 0xf507f4f4ul),
		mk_sl_cui_uint64_cc(0x0bcb16c0ul, 0x8bddcbcbul), mk_sl_cui_uint64_cc(0xf83eedc6ul, 0x7cd33e3eul), mk_sl_cui_uint64_cc(0x14052811ul, 0x0a2d0505ul), mk_sl_cui_uint64_cc(0x81671fe6ul, 0xce786767ul),
		mk_sl_cui_uint64_cc(0xb7e47353ul, 0xd597e4e4ul), mk_sl_cui_uint64_cc(0x9c2725bbul, 0x4e022727ul), mk_sl_cui_uint64_cc(0x19413258ul, 0x82734141ul), mk_sl_cui_uint64_cc(0x168b2c9dul, 0x0ba78b8bul),
		mk_sl_cui_uint64_cc(0xa6a75101ul, 0x53f6a7a7ul), mk_sl_cui_uint64_cc(0xe97dcf94ul, 0xfab27d7dul), mk_sl_cui_uint64_cc(0x6e95dcfbul, 0x37499595ul), mk_sl_cui_uint64_cc(0x47d88e9ful, 0xad56d8d8ul),
		mk_sl_cui_uint64_cc(0xcbfb8b30ul, 0xeb70fbfbul), mk_sl_cui_uint64_cc(0x9fee2371ul, 0xc1cdeeeeul), mk_sl_cui_uint64_cc(0xed7cc791ul, 0xf8bb7c7cul), mk_sl_cui_uint64_cc(0x856617e3ul, 0xcc716666ul),
		mk_sl_cui_uint64_cc(0x53dda68eul, 0xa77bddddul), mk_sl_cui_uint64_cc(0x5c17b84bul, 0x2eaf1717ul), mk_sl_cui_uint64_cc(0x01470246ul, 0x8e454747ul), mk_sl_cui_uint64_cc(0x429e84dcul, 0x211a9e9eul),
		mk_sl_cui_uint64_cc(0x0fca1ec5ul, 0x89d4cacaul), mk_sl_cui_uint64_cc(0xb42d7599ul, 0x5a582d2dul), mk_sl_cui_uint64_cc(0xc6bf9179ul, 0x632ebfbful), mk_sl_cui_uint64_cc(0x1c07381bul, 0x0e3f0707ul),
		mk_sl_cui_uint64_cc(0x8ead0123ul, 0x47acadadul), mk_sl_cui_uint64_cc(0x755aea2ful, 0xb4b05a5aul), mk_sl_cui_uint64_cc(0x36836cb5ul, 0x1bef8383ul), mk_sl_cui_uint64_cc(0xcc3385fful, 0x66b63333ul),
		mk_sl_cui_uint64_cc(0x91633ff2ul, 0xc65c6363ul), mk_sl_cui_uint64_cc(0x0802100aul, 0x04120202ul), mk_sl_cui_uint64_cc(0x92aa3938ul, 0x4993aaaaul), mk_sl_cui_uint64_cc(0xd971afa8ul, 0xe2de7171ul),
		mk_sl_cui_uint64_cc(0x07c80ecful, 0x8dc6c8c8ul), mk_sl_cui_uint64_cc(0x6419c87dul, 0x32d11919ul), mk_sl_cui_uint64_cc(0x39497270ul, 0x923b4949ul), mk_sl_cui_uint64_cc(0x43d9869aul, 0xaf5fd9d9ul),
		mk_sl_cui_uint64_cc(0xeff2c31dul, 0xf931f2f2ul), mk_sl_cui_uint64_cc(0xabe34b48ul, 0xdba8e3e3ul), mk_sl_cui_uint64_cc(0x715be22aul, 0xb6b95b5bul), mk_sl_cui_uint64_cc(0x1a883492ul, 0x0dbc8888ul),
		mk_sl_cui_uint64_cc(0x529aa4c8ul, 0x293e9a9aul), mk_sl_cui_uint64_cc(0x98262dbeul, 0x4c0b2626ul), mk_sl_cui_uint64_cc(0xc8328dfaul, 0x64bf3232ul), mk_sl_cui_uint64_cc(0xfab0e94aul, 0x7d59b0b0ul),
		mk_sl_cui_uint64_cc(0x83e91b6aul, 0xcff2e9e9ul), mk_sl_cui_uint64_cc(0x3c0f7833ul, 0x1e770f0ful), mk_sl_cui_uint64_cc(0x73d5e6a6ul, 0xb733d5d5ul), mk_sl_cui_uint64_cc(0x3a8074baul, 0x1df48080ul),
		mk_sl_cui_uint64_cc(0xc2be997cul, 0x6127bebeul), mk_sl_cui_uint64_cc(0x13cd26deul, 0x87ebcdcdul), mk_sl_cui_uint64_cc(0xd034bde4ul, 0x68893434ul), mk_sl_cui_uint64_cc(0x3d487a75ul, 0x90324848ul),
		mk_sl_cui_uint64_cc(0xdbffab24ul, 0xe354fffful), mk_sl_cui_uint64_cc(0xf57af78ful, 0xf48d7a7aul), mk_sl_cui_uint64_cc(0x7a90f4eaul, 0x3d649090ul), mk_sl_cui_uint64_cc(0x615fc23eul, 0xbe9d5f5ful),
		mk_sl_cui_uint64_cc(0x80201da0ul, 0x403d2020ul), mk_sl_cui_uint64_cc(0xbd6867d5ul, 0xd00f6868ul), mk_sl_cui_uint64_cc(0x681ad072ul, 0x34ca1a1aul), mk_sl_cui_uint64_cc(0x82ae192cul, 0x41b7aeaeul),
		mk_sl_cui_uint64_cc(0xeab4c95eul, 0x757db4b4ul), mk_sl_cui_uint64_cc(0x4d549a19ul, 0xa8ce5454ul), mk_sl_cui_uint64_cc(0x7693ece5ul, 0x3b7f9393ul), mk_sl_cui_uint64_cc(0x88220daaul, 0x442f2222ul),
		mk_sl_cui_uint64_cc(0x8d6407e9ul, 0xc8636464ul), mk_sl_cui_uint64_cc(0xe3f1db12ul, 0xff2af1f1ul), mk_sl_cui_uint64_cc(0xd173bfa2ul, 0xe6cc7373ul), mk_sl_cui_uint64_cc(0x4812905aul, 0x24821212ul),
		mk_sl_cui_uint64_cc(0x1d403a5dul, 0x807a4040ul), mk_sl_cui_uint64_cc(0x20084028ul, 0x10480808ul), mk_sl_cui_uint64_cc(0x2bc356e8ul, 0x9b95c3c3ul), mk_sl_cui_uint64_cc(0x97ec337bul, 0xc5dfececul),
		mk_sl_cui_uint64_cc(0x4bdb9690ul, 0xab4ddbdbul), mk_sl_cui_uint64_cc(0xbea1611ful, 0x5fc0a1a1ul), mk_sl_cui_uint64_cc(0x0e8d1c83ul, 0x07918d8dul), mk_sl_cui_uint64_cc(0xf43df5c9ul, 0x7ac83d3dul),
		mk_sl_cui_uint64_cc(0x6697ccf1ul, 0x335b9797ul), mk_sl_cui_uint64_cc(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_cc(0x1bcf36d4ul, 0x83f9cfcful), mk_sl_cui_uint64_cc(0xac2b4587ul, 0x566e2b2bul),
		mk_sl_cui_uint64_cc(0xc57697b3ul, 0xece17676ul), mk_sl_cui_uint64_cc(0x328264b0ul, 0x19e68282ul), mk_sl_cui_uint64_cc(0x7fd6fea9ul, 0xb128d6d6ul), mk_sl_cui_uint64_cc(0x6c1bd877ul, 0x36c31b1bul),
		mk_sl_cui_uint64_cc(0xeeb5c15bul, 0x7774b5b5ul), mk_sl_cui_uint64_cc(0x86af1129ul, 0x43beafaful), mk_sl_cui_uint64_cc(0xb56a77dful, 0xd41d6a6aul), mk_sl_cui_uint64_cc(0x5d50ba0dul, 0xa0ea5050ul),
		mk_sl_cui_uint64_cc(0x0945124cul, 0x8a574545ul), mk_sl_cui_uint64_cc(0xebf3cb18ul, 0xfb38f3f3ul), mk_sl_cui_uint64_cc(0xc0309df0ul, 0x60ad3030ul), mk_sl_cui_uint64_cc(0x9bef2b74ul, 0xc3c4efeful),
		mk_sl_cui_uint64_cc(0xfc3fe5c3ul, 0x7eda3f3ful), mk_sl_cui_uint64_cc(0x4955921cul, 0xaac75555ul), mk_sl_cui_uint64_cc(0xb2a27910ul, 0x59dba2a2ul), mk_sl_cui_uint64_cc(0x8fea0365ul, 0xc9e9eaeaul),
		mk_sl_cui_uint64_cc(0x89650fecul, 0xca6a6565ul), mk_sl_cui_uint64_cc(0xd2bab968ul, 0x6903babaul), mk_sl_cui_uint64_cc(0xbc2f6593ul, 0x5e4a2f2ful), mk_sl_cui_uint64_cc(0x27c04ee7ul, 0x9d8ec0c0ul),
		mk_sl_cui_uint64_cc(0x5fdebe81ul, 0xa160dedeul), mk_sl_cui_uint64_cc(0x701ce06cul, 0x38fc1c1cul), mk_sl_cui_uint64_cc(0xd3fdbb2eul, 0xe746fdfdul), mk_sl_cui_uint64_cc(0x294d5264ul, 0x9a1f4d4dul),
		mk_sl_cui_uint64_cc(0x7292e4e0ul, 0x39769292ul), mk_sl_cui_uint64_cc(0xc9758fbcul, 0xeafa7575ul), mk_sl_cui_uint64_cc(0x1806301eul, 0x0c360606ul), mk_sl_cui_uint64_cc(0x128a2498ul, 0x09ae8a8aul),
		mk_sl_cui_uint64_cc(0xf2b2f940ul, 0x794bb2b2ul), mk_sl_cui_uint64_cc(0xbfe66359ul, 0xd185e6e6ul), mk_sl_cui_uint64_cc(0x380e7036ul, 0x1c7e0e0eul), mk_sl_cui_uint64_cc(0x7c1ff863ul, 0x3ee71f1ful),
		mk_sl_cui_uint64_cc(0x956237f7ul, 0xc4556262ul), mk_sl_cui_uint64_cc(0x77d4eea3ul, 0xb53ad4d4ul), mk_sl_cui_uint64_cc(0x9aa82932ul, 0x4d81a8a8ul), mk_sl_cui_uint64_cc(0x6296c4f4ul, 0x31529696ul),
		mk_sl_cui_uint64_cc(0xc3f99b3aul, 0xef62f9f9ul), mk_sl_cui_uint64_cc(0x33c566f6ul, 0x97a3c5c5ul), mk_sl_cui_uint64_cc(0x942535b1ul, 0x4a102525ul), mk_sl_cui_uint64_cc(0x7959f220ul, 0xb2ab5959ul),
		mk_sl_cui_uint64_cc(0x2a8454aeul, 0x15d08484ul), mk_sl_cui_uint64_cc(0xd572b7a7ul, 0xe4c57272ul), mk_sl_cui_uint64_cc(0xe439d5ddul, 0x72ec3939ul), mk_sl_cui_uint64_cc(0x2d4c5a61ul, 0x98164c4cul),
		mk_sl_cui_uint64_cc(0x655eca3bul, 0xbc945e5eul), mk_sl_cui_uint64_cc(0xfd78e785ul, 0xf09f7878ul), mk_sl_cui_uint64_cc(0xe038ddd8ul, 0x70e53838ul), mk_sl_cui_uint64_cc(0x0a8c1486ul, 0x05988c8cul),
		mk_sl_cui_uint64_cc(0x63d1c6b2ul, 0xbf17d1d1ul), mk_sl_cui_uint64_cc(0xaea5410bul, 0x57e4a5a5ul), mk_sl_cui_uint64_cc(0xafe2434dul, 0xd9a1e2e2ul), mk_sl_cui_uint64_cc(0x99612ff8ul, 0xc24e6161ul),
		mk_sl_cui_uint64_cc(0xf6b3f145ul, 0x7b42b3b3ul), mk_sl_cui_uint64_cc(0x842115a5ul, 0x42342121ul), mk_sl_cui_uint64_cc(0x4a9c94d6ul, 0x25089c9cul), mk_sl_cui_uint64_cc(0x781ef066ul, 0x3cee1e1eul),
		mk_sl_cui_uint64_cc(0x11432252ul, 0x86614343ul), mk_sl_cui_uint64_cc(0x3bc776fcul, 0x93b1c7c7ul), mk_sl_cui_uint64_cc(0xd7fcb32bul, 0xe54ffcfcul), mk_sl_cui_uint64_cc(0x10042014ul, 0x08240404ul),
		mk_sl_cui_uint64_cc(0x5951b208ul, 0xa2e35151ul), mk_sl_cui_uint64_cc(0x5e99bcc7ul, 0x2f259999ul), mk_sl_cui_uint64_cc(0xa96d4fc4ul, 0xda226d6dul), mk_sl_cui_uint64_cc(0x340d6839ul, 0x1a650d0dul),
		mk_sl_cui_uint64_cc(0xcffa8335ul, 0xe979fafaul), mk_sl_cui_uint64_cc(0x5bdfb684ul, 0xa369dfdful), mk_sl_cui_uint64_cc(0xe57ed79bul, 0xfca97e7eul), mk_sl_cui_uint64_cc(0x90243db4ul, 0x48192424ul),
		mk_sl_cui_uint64_cc(0xec3bc5d7ul, 0x76fe3b3bul), mk_sl_cui_uint64_cc(0x96ab313dul, 0x4b9aababul), mk_sl_cui_uint64_cc(0x1fce3ed1ul, 0x81f0ceceul), mk_sl_cui_uint64_cc(0x44118855ul, 0x22991111ul),
		mk_sl_cui_uint64_cc(0x068f0c89ul, 0x03838f8ful), mk_sl_cui_uint64_cc(0x254e4a6bul, 0x9c044e4eul), mk_sl_cui_uint64_cc(0xe6b7d151ul, 0x7366b7b7ul), mk_sl_cui_uint64_cc(0x8beb0b60ul, 0xcbe0ebebul),
		mk_sl_cui_uint64_cc(0xf03cfdccul, 0x78c13c3cul), mk_sl_cui_uint64_cc(0x3e817cbful, 0x1ffd8181ul), mk_sl_cui_uint64_cc(0x6a94d4feul, 0x35409494ul), mk_sl_cui_uint64_cc(0xfbf7eb0cul, 0xf31cf7f7ul),
		mk_sl_cui_uint64_cc(0xdeb9a167ul, 0x6f18b9b9ul), mk_sl_cui_uint64_cc(0x4c13985ful, 0x268b1313ul), mk_sl_cui_uint64_cc(0xb02c7d9cul, 0x58512c2cul), mk_sl_cui_uint64_cc(0x6bd3d6b8ul, 0xbb05d3d3ul),
		mk_sl_cui_uint64_cc(0xbbe76b5cul, 0xd38ce7e7ul), mk_sl_cui_uint64_cc(0xa56e57cbul, 0xdc396e6eul), mk_sl_cui_uint64_cc(0x37c46ef3ul, 0x95aac4c4ul), mk_sl_cui_uint64_cc(0x0c03180ful, 0x061b0303ul),
		mk_sl_cui_uint64_cc(0x45568a13ul, 0xacdc5656ul), mk_sl_cui_uint64_cc(0x0d441a49ul, 0x885e4444ul), mk_sl_cui_uint64_cc(0xe17fdf9eul, 0xfea07f7ful), mk_sl_cui_uint64_cc(0x9ea92137ul, 0x4f88a9a9ul),
		mk_sl_cui_uint64_cc(0xa82a4d82ul, 0x54672a2aul), mk_sl_cui_uint64_cc(0xd6bbb16dul, 0x6b0abbbbul), mk_sl_cui_uint64_cc(0x23c146e2ul, 0x9f87c1c1ul), mk_sl_cui_uint64_cc(0x5153a202ul, 0xa6f15353ul),
		mk_sl_cui_uint64_cc(0x57dcae8bul, 0xa572dcdcul), mk_sl_cui_uint64_cc(0x2c0b5827ul, 0x16530b0bul), mk_sl_cui_uint64_cc(0x4e9d9cd3ul, 0x27019d9dul), mk_sl_cui_uint64_cc(0xad6c47c1ul, 0xd82b6c6cul),
		mk_sl_cui_uint64_cc(0xc43195f5ul, 0x62a43131ul), mk_sl_cui_uint64_cc(0xcd7487b9ul, 0xe8f37474ul), mk_sl_cui_uint64_cc(0xfff6e309ul, 0xf115f6f6ul), mk_sl_cui_uint64_cc(0x05460a43ul, 0x8c4c4646ul),
		mk_sl_cui_uint64_cc(0x8aac0926ul, 0x45a5acacul), mk_sl_cui_uint64_cc(0x1e893c97ul, 0x0fb58989ul), mk_sl_cui_uint64_cc(0x5014a044ul, 0x28b41414ul), mk_sl_cui_uint64_cc(0xa3e15b42ul, 0xdfbae1e1ul),
		mk_sl_cui_uint64_cc(0x5816b04eul, 0x2ca61616ul), mk_sl_cui_uint64_cc(0xe83acdd2ul, 0x74f73a3aul), mk_sl_cui_uint64_cc(0xb9696fd0ul, 0xd2066969ul), mk_sl_cui_uint64_cc(0x2409482dul, 0x12410909ul),
		mk_sl_cui_uint64_cc(0xdd70a7adul, 0xe0d77070ul), mk_sl_cui_uint64_cc(0xe2b6d954ul, 0x716fb6b6ul), mk_sl_cui_uint64_cc(0x67d0ceb7ul, 0xbd1ed0d0ul), mk_sl_cui_uint64_cc(0x93ed3b7eul, 0xc7d6ededul),
		mk_sl_cui_uint64_cc(0x17cc2edbul, 0x85e2ccccul), mk_sl_cui_uint64_cc(0x15422a57ul, 0x84684242ul), mk_sl_cui_uint64_cc(0x5a98b4c2ul, 0x2d2c9898ul), mk_sl_cui_uint64_cc(0xaaa4490eul, 0x55eda4a4ul),
		mk_sl_cui_uint64_cc(0xa0285d88ul, 0x50752828ul), mk_sl_cui_uint64_cc(0x6d5cda31ul, 0xb8865c5cul), mk_sl_cui_uint64_cc(0xc7f8933ful, 0xed6bf8f8ul), mk_sl_cui_uint64_cc(0x228644a4ul, 0x11c28686ul),
	}}},
	{{{
		mk_sl_cui_uint64_cc(0x186018c0ul, 0x7830d818ul), mk_sl_cui_uint64_cc(0x238c2305ul, 0xaf462623ul), mk_sl_cui_uint64_cc(0xc63fc67eul, 0xf991b8c6ul), mk_sl_cui_uint64_cc(0xe887e813ul, 0x6fcdfbe8ul),
		mk_sl_cui_uint64_cc(0x8726874cul, 0xa113cb87ul), mk_sl_cui_uint64_cc(0xb8dab8a9ul, 0x626d11b8ul), mk_sl_cui_uint64_cc(0x01040108ul, 0x05020901ul), mk_sl_cui_uint64_cc(0x4f214f42ul, 0x6e9e0d4ful),
		mk_sl_cui_uint64_cc(0x36d836adul, 0xee6c9b36ul), mk_sl_cui_uint64_cc(0xa6a2a659ul, 0x0451ffa6ul), mk_sl_cui_uint64_cc(0xd26fd2deul, 0xbdb90cd2ul), mk_sl_cui_uint64_cc(0xf5f3f5fbul, 0x06f70ef5ul),
		mk_sl_cui_uint64_cc(0x79f979eful, 0x80f29679ul), mk_sl_cui_uint64_cc(0x6fa16f5ful, 0xcede306ful), mk_sl_cui_uint64_cc(0x917e91fcul, 0xef3f6d91ul), mk_sl_cui_uint64_cc(0x525552aaul, 0x07a4f852ul),
		mk_sl_cui_uint64_cc(0x609d6027ul, 0xfdc04760ul), mk_sl_cui_uint64_cc(0xbccabc89ul, 0x766535bcul), mk_sl_cui_uint64_cc(0x9b569bacul, 0xcd2b379bul), mk_sl_cui_uint64_cc(0x8e028e04ul, 0x8c018a8eul),
		mk_sl_cui_uint64_cc(0xa3b6a371ul, 0x155bd2a3ul), mk_sl_cui_uint64_cc(0x0c300c60ul, 0x3c186c0cul), mk_sl_cui_uint64_cc(0x7bf17bfful, 0x8af6847bul), mk_sl_cui_uint64_cc(0x35d435b5ul, 0xe16a8035ul),
		mk_sl_cui_uint64_cc(0x1d741de8ul, 0x693af51dul), mk_sl_cui_uint64_cc(0xe0a7e053ul, 0x47ddb3e0ul), mk_sl_cui_uint64_cc(0xd77bd7f6ul, 0xacb321d7ul), mk_sl_cui_uint64_cc(0xc22fc25eul, 0xed999cc2ul),
		mk_sl_cui_uint64_cc(0x2eb82e6dul, 0x965c432eul), mk_sl_cui_uint64_cc(0x4b314b62ul, 0x7a96294bul), mk_sl_cui_uint64_cc(0xfedffea3ul, 0x21e15dfeul), mk_sl_cui_uint64_cc(0x57415782ul, 0x16aed557ul),
		mk_sl_cui_uint64_cc(0x155415a8ul, 0x412abd15ul), mk_sl_cui_uint64_cc(0x77c1779ful, 0xb6eee877ul), mk_sl_cui_uint64_cc(0x37dc37a5ul, 0xeb6e9237ul), mk_sl_cui_uint64_cc(0xe5b3e57bul, 0x56d79ee5ul),
		mk_sl_cui_uint64_cc(0x9f469f8cul, 0xd923139ful), mk_sl_cui_uint64_cc(0xf0e7f0d3ul, 0x17fd23f0ul), mk_sl_cui_uint64_cc(0x4a354a6aul, 0x7f94204aul), mk_sl_cui_uint64_cc(0xda4fda9eul, 0x95a944daul),
		mk_sl_cui_uint64_cc(0x587d58faul, 0x25b0a258ul), mk_sl_cui_uint64_cc(0xc903c906ul, 0xca8fcfc9ul), mk_sl_cui_uint64_cc(0x29a42955ul, 0x8d527c29ul), mk_sl_cui_uint64_cc(0x0a280a50ul, 0x22145a0aul),
		mk_sl_cui_uint64_cc(0xb1feb1e1ul, 0x4f7f50b1ul), mk_sl_cui_uint64_cc(0xa0baa069ul, 0x1a5dc9a0ul), mk_sl_cui_uint64_cc(0x6bb16b7ful, 0xdad6146bul), mk_sl_cui_uint64_cc(0x852e855cul, 0xab17d985ul),
		mk_sl_cui_uint64_cc(0xbdcebd81ul, 0x73673cbdul), mk_sl_cui_uint64_cc(0x5d695dd2ul, 0x34ba8f5dul), mk_sl_cui_uint64_cc(0x10401080ul, 0x50209010ul), mk_sl_cui_uint64_cc(0xf4f7f4f3ul, 0x03f507f4ul),
		mk_sl_cui_uint64_cc(0xcb0bcb16ul, 0xc08bddcbul), mk_sl_cui_uint64_cc(0x3ef83eedul, 0xc67cd33eul), mk_sl_cui_uint64_cc(0x05140528ul, 0x110a2d05ul), mk_sl_cui_uint64_cc(0x6781671ful, 0xe6ce7867ul),
		mk_sl_cui_uint64_cc(0xe4b7e473ul, 0x53d597e4ul), mk_sl_cui_uint64_cc(0x279c2725ul, 0xbb4e0227ul), mk_sl_cui_uint64_cc(0x41194132ul, 0x58827341ul), mk_sl_cui_uint64_cc(0x8b168b2cul, 0x9d0ba78bul),
		mk_sl_cui_uint64_cc(0xa7a6a751ul, 0x0153f6a7ul), mk_sl_cui_uint64_cc(0x7de97dcful, 0x94fab27dul), mk_sl_cui_uint64_cc(0x956e95dcul, 0xfb374995ul), mk_sl_cui_uint64_cc(0xd847d88eul, 0x9fad56d8ul),
		mk_sl_cui_uint64_cc(0xfbcbfb8bul, 0x30eb70fbul), mk_sl_cui_uint64_cc(0xee9fee23ul, 0x71c1cdeeul), mk_sl_cui_uint64_cc(0x7ced7cc7ul, 0x91f8bb7cul), mk_sl_cui_uint64_cc(0x66856617ul, 0xe3cc7166ul),
		mk_sl_cui_uint64_cc(0xdd53dda6ul, 0x8ea77bddul), mk_sl_cui_uint64_cc(0x175c17b8ul, 0x4b2eaf17ul), mk_sl_cui_uint64_cc(0x47014702ul, 0x468e4547ul), mk_sl_cui_uint64_cc(0x9e429e84ul, 0xdc211a9eul),
		mk_sl_cui_uint64_cc(0xca0fca1eul, 0xc589d4caul), mk_sl_cui_uint64_cc(0x2db42d75ul, 0x995a582dul), mk_sl_cui_uint64_cc(0xbfc6bf91ul, 0x79632ebful), mk_sl_cui_uint64_cc(0x071c0738ul, 0x1b0e3f07ul),
		mk_sl_cui_uint64_cc(0xad8ead01ul, 0x2347acadul), mk_sl_cui_uint64_cc(0x5a755aeaul, 0x2fb4b05aul), mk_sl_cui_uint64_cc(0x8336836cul, 0xb51bef83ul), mk_sl_cui_uint64_cc(0x33cc3385ul, 0xff66b633ul),
		mk_sl_cui_uint64_cc(0x6391633ful, 0xf2c65c63ul), mk_sl_cui_uint64_cc(0x02080210ul, 0x0a041202ul), mk_sl_cui_uint64_cc(0xaa92aa39ul, 0x384993aaul), mk_sl_cui_uint64_cc(0x71d971aful, 0xa8e2de71ul),
		mk_sl_cui_uint64_cc(0xc807c80eul, 0xcf8dc6c8ul), mk_sl_cui_uint64_cc(0x196419c8ul, 0x7d32d119ul), mk_sl_cui_uint64_cc(0x49394972ul, 0x70923b49ul), mk_sl_cui_uint64_cc(0xd943d986ul, 0x9aaf5fd9ul),
		mk_sl_cui_uint64_cc(0xf2eff2c3ul, 0x1df931f2ul), mk_sl_cui_uint64_cc(0xe3abe34bul, 0x48dba8e3ul), mk_sl_cui_uint64_cc(0x5b715be2ul, 0x2ab6b95bul), mk_sl_cui_uint64_cc(0x881a8834ul, 0x920dbc88ul),
		mk_sl_cui_uint64_cc(0x9a529aa4ul, 0xc8293e9aul), mk_sl_cui_uint64_cc(0x2698262dul, 0xbe4c0b26ul), mk_sl_cui_uint64_cc(0x32c8328dul, 0xfa64bf32ul), mk_sl_cui_uint64_cc(0xb0fab0e9ul, 0x4a7d59b0ul),
		mk_sl_cui_uint64_cc(0xe983e91bul, 0x6acff2e9ul), mk_sl_cui_uint64_cc(0x0f3c0f78ul, 0x331e770ful), mk_sl_cui_uint64_cc(0xd573d5e6ul, 0xa6b733d5ul), mk_sl_cui_uint64_cc(0x803a8074ul, 0xba1df480ul),
		mk_sl_cui_uint64_cc(0xbec2be99ul, 0x7c6127beul), mk_sl_cui_uint64_cc(0xcd13cd26ul, 0xde87ebcdul), mk_sl_cui_uint64_cc(0x34d034bdul, 0xe4688934ul), mk_sl_cui_uint64_cc(0x483d487aul, 0x75903248ul),
		mk_sl_cui_uint64_cc(0xffdbffabul, 0x24e354fful), mk_sl_cui_uint64_cc(0x7af57af7ul, 0x8ff48d7aul), mk_sl_cui_uint64_cc(0x907a90f4ul, 0xea3d6490ul), mk_sl_cui_uint64_cc(0x5f615fc2ul, 0x3ebe9d5ful),
		mk_sl_cui_uint64_cc(0x2080201dul, 0xa0403d20ul), mk_sl_cui_uint64_cc(0x68bd6867ul, 0xd5d00f68ul), mk_sl_cui_uint64_cc(0x1a681ad0ul, 0x7234ca1aul), mk_sl_cui_uint64_cc(0xae82ae19ul, 0x2c41b7aeul),
		mk_sl_cui_uint64_cc(0xb4eab4c9ul, 0x5e757db4ul), mk_sl_cui_uint64_cc(0x544d549aul, 0x19a8ce54ul), mk_sl_cui_uint64_cc(0x937693ecul, 0xe53b7f93ul), mk_sl_cui_uint64_cc(0x2288220dul, 0xaa442f22ul),
		mk_sl_cui_uint64_cc(0x648d6407ul, 0xe9c86364ul), mk_sl_cui_uint64_cc(0xf1e3f1dbul, 0x12ff2af1ul), mk_sl_cui_uint64_cc(0x73d173bful, 0xa2e6cc73ul), mk_sl_cui_uint64_cc(0x12481290ul, 0x5a248212ul),
		mk_sl_cui_uint64_cc(0x401d403aul, 0x5d807a40ul), mk_sl_cui_uint64_cc(0x08200840ul, 0x28104808ul), mk_sl_cui_uint64_cc(0xc32bc356ul, 0xe89b95c3ul), mk_sl_cui_uint64_cc(0xec97ec33ul, 0x7bc5dfecul),
		mk_sl_cui_uint64_cc(0xdb4bdb96ul, 0x90ab4ddbul), mk_sl_cui_uint64_cc(0xa1bea161ul, 0x1f5fc0a1ul), mk_sl_cui_uint64_cc(0x8d0e8d1cul, 0x8307918dul), mk_sl_cui_uint64_cc(0x3df43df5ul, 0xc97ac83dul),
		mk_sl_cui_uint64_cc(0x976697ccul, 0xf1335b97ul), mk_sl_cui_uint64_cc(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_cc(0xcf1bcf36ul, 0xd483f9cful), mk_sl_cui_uint64_cc(0x2bac2b45ul, 0x87566e2bul),
		mk_sl_cui_uint64_cc(0x76c57697ul, 0xb3ece176ul), mk_sl_cui_uint64_cc(0x82328264ul, 0xb019e682ul), mk_sl_cui_uint64_cc(0xd67fd6feul, 0xa9b128d6ul), mk_sl_cui_uint64_cc(0x1b6c1bd8ul, 0x7736c31bul),
		mk_sl_cui_uint64_cc(0xb5eeb5c1ul, 0x5b7774b5ul), mk_sl_cui_uint64_cc(0xaf86af11ul, 0x2943beaful), mk_sl_cui_uint64_cc(0x6ab56a77ul, 0xdfd41d6aul), mk_sl_cui_uint64_cc(0x505d50baul, 0x0da0ea50ul),
		mk_sl_cui_uint64_cc(0x45094512ul, 0x4c8a5745ul), mk_sl_cui_uint64_cc(0xf3ebf3cbul, 0x18fb38f3ul), mk_sl_cui_uint64_cc(0x30c0309dul, 0xf060ad30ul), mk_sl_cui_uint64_cc(0xef9bef2bul, 0x74c3c4eful),
		mk_sl_cui_uint64_cc(0x3ffc3fe5ul, 0xc37eda3ful), mk_sl_cui_uint64_cc(0x55495592ul, 0x1caac755ul), mk_sl_cui_uint64_cc(0xa2b2a279ul, 0x1059dba2ul), mk_sl_cui_uint64_cc(0xea8fea03ul, 0x65c9e9eaul),
		mk_sl_cui_uint64_cc(0x6589650ful, 0xecca6a65ul), mk_sl_cui_uint64_cc(0xbad2bab9ul, 0x686903baul), mk_sl_cui_uint64_cc(0x2fbc2f65ul, 0x935e4a2ful), mk_sl_cui_uint64_cc(0xc027c04eul, 0xe79d8ec0ul),
		mk_sl_cui_uint64_cc(0xde5fdebeul, 0x81a160deul), mk_sl_cui_uint64_cc(0x1c701ce0ul, 0x6c38fc1cul), mk_sl_cui_uint64_cc(0xfdd3fdbbul, 0x2ee746fdul), mk_sl_cui_uint64_cc(0x4d294d52ul, 0x649a1f4dul),
		mk_sl_cui_uint64_cc(0x927292e4ul, 0xe0397692ul), mk_sl_cui_uint64_cc(0x75c9758ful, 0xbceafa75ul), mk_sl_cui_uint64_cc(0x06180630ul, 0x1e0c3606ul), mk_sl_cui_uint64_cc(0x8a128a24ul, 0x9809ae8aul),
		mk_sl_cui_uint64_cc(0xb2f2b2f9ul, 0x40794bb2ul), mk_sl_cui_uint64_cc(0xe6bfe663ul, 0x59d185e6ul), mk_sl_cui_uint64_cc(0x0e380e70ul, 0x361c7e0eul), mk_sl_cui_uint64_cc(0x1f7c1ff8ul, 0x633ee71ful),
		mk_sl_cui_uint64_cc(0x62956237ul, 0xf7c45562ul), mk_sl_cui_uint64_cc(0xd477d4eeul, 0xa3b53ad4ul), mk_sl_cui_uint64_cc(0xa89aa829ul, 0x324d81a8ul), mk_sl_cui_uint64_cc(0x966296c4ul, 0xf4315296ul),
		mk_sl_cui_uint64_cc(0xf9c3f99bul, 0x3aef62f9ul), mk_sl_cui_uint64_cc(0xc533c566ul, 0xf697a3c5ul), mk_sl_cui_uint64_cc(0x25942535ul, 0xb14a1025ul), mk_sl_cui_uint64_cc(0x597959f2ul, 0x20b2ab59ul),
		mk_sl_cui_uint64_cc(0x842a8454ul, 0xae15d084ul), mk_sl_cui_uint64_cc(0x72d572b7ul, 0xa7e4c572ul), mk_sl_cui_uint64_cc(0x39e439d5ul, 0xdd72ec39ul), mk_sl_cui_uint64_cc(0x4c2d4c5aul, 0x6198164cul),
		mk_sl_cui_uint64_cc(0x5e655ecaul, 0x3bbc945eul), mk_sl_cui_uint64_cc(0x78fd78e7ul, 0x85f09f78ul), mk_sl_cui_uint64_cc(0x38e038ddul, 0xd870e538ul), mk_sl_cui_uint64_cc(0x8c0a8c14ul, 0x8605988cul),
		mk_sl_cui_uint64_cc(0xd163d1c6ul, 0xb2bf17d1ul), mk_sl_cui_uint64_cc(0xa5aea541ul, 0x0b57e4a5ul), mk_sl_cui_uint64_cc(0xe2afe243ul, 0x4dd9a1e2ul), mk_sl_cui_uint64_cc(0x6199612ful, 0xf8c24e61ul),
		mk_sl_cui_uint64_cc(0xb3f6b3f1ul, 0x457b42b3ul), mk_sl_cui_uint64_cc(0x21842115ul, 0xa5423421ul), mk_sl_cui_uint64_cc(0x9c4a9c94ul, 0xd625089cul), mk_sl_cui_uint64_cc(0x1e781ef0ul, 0x663cee1eul),
		mk_sl_cui_uint64_cc(0x43114322ul, 0x52866143ul), mk_sl_cui_uint64_cc(0xc73bc776ul, 0xfc93b1c7ul), mk_sl_cui_uint64_cc(0xfcd7fcb3ul, 0x2be54ffcul), mk_sl_cui_uint64_cc(0x04100420ul, 0x14082404ul),
		mk_sl_cui_uint64_cc(0x515951b2ul, 0x08a2e351ul), mk_sl_cui_uint64_cc(0x995e99bcul, 0xc72f2599ul), mk_sl_cui_uint64_cc(0x6da96d4ful, 0xc4da226dul), mk_sl_cui_uint64_cc(0x0d340d68ul, 0x391a650dul),
		mk_sl_cui_uint64_cc(0xfacffa83ul, 0x35e979faul), mk_sl_cui_uint64_cc(0xdf5bdfb6ul, 0x84a369dful), mk_sl_cui_uint64_cc(0x7ee57ed7ul, 0x9bfca97eul), mk_sl_cui_uint64_cc(0x2490243dul, 0xb4481924ul),
		mk_sl_cui_uint64_cc(0x3bec3bc5ul, 0xd776fe3bul), mk_sl_cui_uint64_cc(0xab96ab31ul, 0x3d4b9aabul), mk_sl_cui_uint64_cc(0xce1fce3eul, 0xd181f0ceul), mk_sl_cui_uint64_cc(0x11441188ul, 0x55229911ul),
		mk_sl_cui_uint64_cc(0x8f068f0cul, 0x8903838ful), mk_sl_cui_uint64_cc(0x4e254e4aul, 0x6b9c044eul), mk_sl_cui_uint64_cc(0xb7e6b7d1ul, 0x517366b7ul), mk_sl_cui_uint64_cc(0xeb8beb0bul, 0x60cbe0ebul),
		mk_sl_cui_uint64_cc(0x3cf03cfdul, 0xcc78c13cul), mk_sl_cui_uint64_cc(0x813e817cul, 0xbf1ffd81ul), mk_sl_cui_uint64_cc(0x946a94d4ul, 0xfe354094ul), mk_sl_cui_uint64_cc(0xf7fbf7ebul, 0x0cf31cf7ul),
		mk_sl_cui_uint64_cc(0xb9deb9a1ul, 0x676f18b9ul), mk_sl_cui_uint64_cc(0x134c1398ul, 0x5f268b13ul), mk_sl_cui_uint64_cc(0x2cb02c7dul, 0x9c58512cul), mk_sl_cui_uint64_cc(0xd36bd3d6ul, 0xb8bb05d3ul),
		mk_sl_cui_uint64_cc(0xe7bbe76bul, 0x5cd38ce7ul), mk_sl_cui_uint64_cc(0x6ea56e57ul, 0xcbdc396eul), mk_sl_cui_uint64_cc(0xc437c46eul, 0xf395aac4ul), mk_sl_cui_uint64_cc(0x030c0318ul, 0x0f061b03ul),
		mk_sl_cui_uint64_cc(0x5645568aul, 0x13acdc56ul), mk_sl_cui_uint64_cc(0x440d441aul, 0x49885e44ul), mk_sl_cui_uint64_cc(0x7fe17fdful, 0x9efea07ful), mk_sl_cui_uint64_cc(0xa99ea921ul, 0x374f88a9ul),
		mk_sl_cui_uint64_cc(0x2aa82a4dul, 0x8254672aul), mk_sl_cui_uint64_cc(0xbbd6bbb1ul, 0x6d6b0abbul), mk_sl_cui_uint64_cc(0xc123c146ul, 0xe29f87c1ul), mk_sl_cui_uint64_cc(0x535153a2ul, 0x02a6f153ul),
		mk_sl_cui_uint64_cc(0xdc57dcaeul, 0x8ba572dcul), mk_sl_cui_uint64_cc(0x0b2c0b58ul, 0x2716530bul), mk_sl_cui_uint64_cc(0x9d4e9d9cul, 0xd327019dul), mk_sl_cui_uint64_cc(0x6cad6c47ul, 0xc1d82b6cul),
		mk_sl_cui_uint64_cc(0x31c43195ul, 0xf562a431ul), mk_sl_cui_uint64_cc(0x74cd7487ul, 0xb9e8f374ul), mk_sl_cui_uint64_cc(0xf6fff6e3ul, 0x09f115f6ul), mk_sl_cui_uint64_cc(0x4605460aul, 0x438c4c46ul),
		mk_sl_cui_uint64_cc(0xac8aac09ul, 0x2645a5acul), mk_sl_cui_uint64_cc(0x891e893cul, 0x970fb589ul), mk_sl_cui_uint64_cc(0x145014a0ul, 0x4428b414ul), mk_sl_cui_uint64_cc(0xe1a3e15bul, 0x42dfbae1ul),
		mk_sl_cui_uint64_cc(0x165816b0ul, 0x4e2ca616ul), mk_sl_cui_uint64_cc(0x3ae83acdul, 0xd274f73aul), mk_sl_cui_uint64_cc(0x69b9696ful, 0xd0d20669ul), mk_sl_cui_uint64_cc(0x09240948ul, 0x2d124109ul),
		mk_sl_cui_uint64_cc(0x70dd70a7ul, 0xade0d770ul), mk_sl_cui_uint64_cc(0xb6e2b6d9ul, 0x54716fb6ul), mk_sl_cui_uint64_cc(0xd067d0ceul, 0xb7bd1ed0ul), mk_sl_cui_uint64_cc(0xed93ed3bul, 0x7ec7d6edul),
		mk_sl_cui_uint64_cc(0xcc17cc2eul, 0xdb85e2ccul), mk_sl_cui_uint64_cc(0x4215422aul, 0x57846842ul), mk_sl_cui_uint64_cc(0x985a98b4ul, 0xc22d2c98ul), mk_sl_cui_uint64_cc(0xa4aaa449ul, 0x0e55eda4ul),
		mk_sl_cui_uint64_cc(0x28a0285dul, 0x88507528ul), mk_sl_cui_uint64_cc(0x5c6d5cdaul, 0x31b8865cul), mk_sl_cui_uint64_cc(0xf8c7f893ul, 0x3fed6bf8ul), mk_sl_cui_uint64_cc(0x86228644ul, 0xa411c286ul),
	}}},
}};

mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const s_mk_lib_crypto_hash_block_whirlpool_rc[s_mk_lib_crypto_hash_block_whirlpool_nrounds] =
{
	mk_sl_cui_uint64_cc(0x1823c6e8ul, 0x87b8014ful),
	mk_sl_cui_uint64_cc(0x36a6d2f5ul, 0x796f9152ul),
	mk_sl_cui_uint64_cc(0x60bc9b8eul, 0xa30c7b35ul),
	mk_sl_cui_uint64_cc(0x1de0d7c2ul, 0x2e4bfe57ul),
	mk_sl_cui_uint64_cc(0x157737e5ul, 0x9ff04adaul),
	mk_sl_cui_uint64_cc(0x58c9290aul, 0xb1a06b85ul),
	mk_sl_cui_uint64_cc(0xbd5d10f4ul, 0xcb3e0567ul),
	mk_sl_cui_uint64_cc(0xe427418bul, 0xa77d95d8ul),
	mk_sl_cui_uint64_cc(0xfbee7c66ul, 0xdd17479eul),
	mk_sl_cui_uint64_cc(0xca2dbf07ul, 0xad5a8333ul),
};


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_whirlpool_init(mk_lib_crypto_hash_block_whirlpool_pt const whirlpool) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_whirlpool_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_whirlpool_digest_t) == 64);

	mk_lang_assert(whirlpool);

	for(i = 0; i != 8; ++i)
	{
		mk_sl_cui_uint64_set_zero(&whirlpool->m_state.m_uint64s[i]);
	}
	mk_lib_crypto_hash_block_whirlpool_uint256_set_zero(&whirlpool->m_len);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_whirlpool_append_blocks(mk_lib_crypto_hash_block_whirlpool_pt const whirlpool, mk_lib_crypto_hash_block_whirlpool_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_whirlpool_uint256_t tsize mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_whirlpool_block_pt pfree[3] mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_whirlpool_block_t storages[3] mk_lang_constexpr_init;
	mk_lang_types_sint_t nfree mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_whirlpool_block_pt ptr1 mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_whirlpool_block_pt ptr2 mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t ir mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_whirlpool_block_pt ptr3 mk_lang_constexpr_init;
	mk_lang_types_uchar_t idxs[8] mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint64_t td mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_whirlpool_block_pt ptr4 mk_lang_constexpr_init;

	mk_lang_assert(whirlpool);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_whirlpool_block_len);

	mk_lib_crypto_hash_block_whirlpool_uint256_from_bi_usize(&tsize, &nblocks);
	mk_lang_assert(!mk_lib_crypto_hash_block_whirlpool_uint256_would_overflow_add_cc(&whirlpool->m_len, &tsize));
	mk_lib_crypto_hash_block_whirlpool_uint256_add2_wrap_cid_cod(&whirlpool->m_len, &tsize);
	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		pfree[0] = &storages[0];
		pfree[1] = &storages[1];
		pfree[2] = &storages[2];
		nfree = 3;
		ptr1 = &whirlpool->m_state;
		ptr2 = pfree[--nfree];
		for(i = 0; i != 8; ++i)
		{
			mk_sl_uint_64_from_8_le(&ta, &pblocks[iblock].m_uint8s[i * 8]);
			mk_sl_cui_uint64_xor3(&whirlpool->m_state.m_uint64s[i], &ta, &ptr2->m_uint64s[i]);
		}
		for(ir = 0; ir != s_mk_lib_crypto_hash_block_whirlpool_nrounds; ++ir)
		{
			ptr3 = pfree[--nfree];
			for(i = 0; i != 8; ++i)
			{
				mk_sl_cui_uint64_shr3(&ptr1->m_uint64s[(0 + i) % 8], 0 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[0]);
				mk_sl_cui_uint64_shr3(&ptr1->m_uint64s[(7 + i) % 8], 1 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[1]);
				mk_sl_cui_uint64_shr3(&ptr1->m_uint64s[(6 + i) % 8], 2 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[2]);
				mk_sl_cui_uint64_shr3(&ptr1->m_uint64s[(5 + i) % 8], 3 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[3]);
				mk_sl_cui_uint64_shr3(&ptr1->m_uint64s[(4 + i) % 8], 4 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[4]);
				mk_sl_cui_uint64_shr3(&ptr1->m_uint64s[(3 + i) % 8], 5 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[5]);
				mk_sl_cui_uint64_shr3(&ptr1->m_uint64s[(2 + i) % 8], 6 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[6]);
				mk_sl_cui_uint64_shr3(&ptr1->m_uint64s[(1 + i) % 8], 7 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[7]);
				mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[0].m_data.m_uint64s[idxs[0]], &s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[1].m_data.m_uint64s[idxs[1]], &ta);
				mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[2].m_data.m_uint64s[idxs[2]], &s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[3].m_data.m_uint64s[idxs[3]], &tb);
				mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[4].m_data.m_uint64s[idxs[4]], &s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[5].m_data.m_uint64s[idxs[5]], &tc);
				mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[6].m_data.m_uint64s[idxs[6]], &s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[7].m_data.m_uint64s[idxs[7]], &td);
				mk_sl_cui_uint64_xor2(&ta, &tb);
				mk_sl_cui_uint64_xor2(&tc, &td);
				mk_sl_cui_uint64_xor3(&ta, &tc, &ptr3->m_uint64s[i]);
			}
			mk_sl_cui_uint64_xor2(&ptr3->m_uint64s[0], &s_mk_lib_crypto_hash_block_whirlpool_rc[ir]);
			if(ir != 0){ pfree[nfree++] = ptr1; }
			ptr4 = pfree[--nfree];
			for(i = 0; i != 8; ++i)
			{
				mk_sl_cui_uint64_shr3(&ptr2->m_uint64s[(0 + i) % 8], 0 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[0]);
				mk_sl_cui_uint64_shr3(&ptr2->m_uint64s[(7 + i) % 8], 1 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[1]);
				mk_sl_cui_uint64_shr3(&ptr2->m_uint64s[(6 + i) % 8], 2 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[2]);
				mk_sl_cui_uint64_shr3(&ptr2->m_uint64s[(5 + i) % 8], 3 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[3]);
				mk_sl_cui_uint64_shr3(&ptr2->m_uint64s[(4 + i) % 8], 4 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[4]);
				mk_sl_cui_uint64_shr3(&ptr2->m_uint64s[(3 + i) % 8], 5 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[5]);
				mk_sl_cui_uint64_shr3(&ptr2->m_uint64s[(2 + i) % 8], 6 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[6]);
				mk_sl_cui_uint64_shr3(&ptr2->m_uint64s[(1 + i) % 8], 7 * 8, &ta); mk_sl_cui_uint64_to_bi_uchar(&ta, &idxs[7]);
				mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[0].m_data.m_uint64s[idxs[0]], &s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[1].m_data.m_uint64s[idxs[1]], &ta);
				mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[2].m_data.m_uint64s[idxs[2]], &s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[3].m_data.m_uint64s[idxs[3]], &tb);
				mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[4].m_data.m_uint64s[idxs[4]], &s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[5].m_data.m_uint64s[idxs[5]], &tc);
				mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[6].m_data.m_uint64s[idxs[6]], &s_mk_lib_crypto_hash_block_whirlpool_tables.m_data[7].m_data.m_uint64s[idxs[7]], &td);
				mk_sl_cui_uint64_xor2(&ta, &tb);
				mk_sl_cui_uint64_xor2(&tc, &td);
				mk_sl_cui_uint64_xor2(&ta, &tc);
				mk_sl_cui_uint64_xor3(&ta, &ptr3->m_uint64s[i], &ptr4->m_uint64s[i]);
			}
			pfree[nfree++] = ptr2;
			ptr1 = ptr3;
			ptr2 = ptr4;
		}
		for(i = 0; i != 8; ++i)
		{
			mk_sl_uint_64_from_8_le(&ta, &pblocks[iblock].m_uint8s[i * 8]);
			mk_sl_cui_uint64_xor2(&ta, &ptr2->m_uint64s[i]);
			mk_sl_cui_uint64_xor2(&whirlpool->m_state.m_uint64s[i], &ta);
		}
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_whirlpool_finish(mk_lib_crypto_hash_block_whirlpool_pt const whirlpool, mk_lib_crypto_hash_block_whirlpool_block_pt const block, mk_lang_types_sint_t const idx, mk_lib_crypto_hash_block_whirlpool_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_types_uint_t tui mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_whirlpool_uint256_t ta mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_whirlpool_uint256_t tb mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[32] mk_lang_constexpr_init;

	mk_lang_assert(whirlpool);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_whirlpool_block_len);
	mk_lang_assert(digest);

	tui = mk_lib_crypto_hash_block_whirlpool_block_len;
	mk_lib_crypto_hash_block_whirlpool_uint256_from_bi_uint(&ta, &tui);
	mk_lang_assert(!mk_lib_crypto_hash_block_whirlpool_uint256_would_overflow_mul(&whirlpool->m_len, &ta));
	mk_lib_crypto_hash_block_whirlpool_uint256_shl3(&whirlpool->m_len, 6, &ta);
	mk_lib_crypto_hash_block_whirlpool_uint256_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_lib_crypto_hash_block_whirlpool_uint256_would_overflow_add_cc(&ta, &tb));
	mk_lib_crypto_hash_block_whirlpool_uint256_add2_wrap_cid_cod(&ta, &tb);
	tui = 8;
	mk_lib_crypto_hash_block_whirlpool_uint256_from_bi_uint(&tb, &tui);
	mk_lang_assert(!mk_lib_crypto_hash_block_whirlpool_uint256_would_overflow_mul(&ta, &tb));
	mk_lib_crypto_hash_block_whirlpool_uint256_shl2(&ta, 3);
	tui = 0x80;
	mk_sl_cui_uint8_from_bi_uint(&block->m_uint8s[idx], &tui);
	rest = mk_lib_crypto_hash_block_whirlpool_block_len - idx - 1;
	if(rest >= 32)
	{
		for(i = 0; i != rest - 32; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[idx + 1 + i]);
		}
	}
	else
	{
		for(i = 0; i != rest; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[idx + 1 + i]);
		}
		mk_lib_crypto_hash_block_whirlpool_append_blocks(whirlpool, block, 1);
		for(i = 0; i != mk_lib_crypto_hash_block_whirlpool_block_len - 32; ++i)
		{
			mk_sl_cui_uint8_set_zero(&block->m_uint8s[i]);
		}
	}
	mk_lib_crypto_hash_block_whirlpool_uint256_to_buis_uchar_be(&ta, &uchars[0]);
	for(i = 0; i != 32; ++i)
	{
		mk_sl_cui_uint8_from_bi_uchar(&block->m_uint8s[mk_lib_crypto_hash_block_whirlpool_block_len - 32 + i], &uchars[i]);
	}
	mk_lib_crypto_hash_block_whirlpool_append_blocks(whirlpool, block, 1);
	for(i = 0; i != 8; ++i)
	{
		mk_sl_uint_64_to_8_le(&whirlpool->m_state.m_uint64s[i], &digest->m_uint8s[i * 8]);
	}
}
