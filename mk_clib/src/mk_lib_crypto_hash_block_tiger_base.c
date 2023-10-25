#include "mk_lib_crypto_hash_block_tiger_base.h"

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


mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const s_mk_lib_crypto_hash_block_tiger_base_table[4 * 256] =
{
	mk_sl_cui_uint64_c(0x02aab17cul, 0xf7e90c5eul), mk_sl_cui_uint64_c(0xac424b03ul, 0xe243a8ecul), mk_sl_cui_uint64_c(0x72cd5be3ul, 0x0dd5fcd3ul), mk_sl_cui_uint64_c(0x6d019b93ul, 0xf6f97f3aul),
	mk_sl_cui_uint64_c(0xcd9978fful, 0xd21f9193ul), mk_sl_cui_uint64_c(0x7573a1c9ul, 0x708029e2ul), mk_sl_cui_uint64_c(0xb164326bul, 0x922a83c3ul), mk_sl_cui_uint64_c(0x46883eeeul, 0x04915870ul),
	mk_sl_cui_uint64_c(0xeaace305ul, 0x7103ece6ul), mk_sl_cui_uint64_c(0xc54169b8ul, 0x08a3535cul), mk_sl_cui_uint64_c(0x4ce75491ul, 0x8ddec47cul), mk_sl_cui_uint64_c(0x0aa2f4dful, 0xdc0df40cul),
	mk_sl_cui_uint64_c(0x10b76f18ul, 0xa74dbefaul), mk_sl_cui_uint64_c(0xc6ccb623ul, 0x5ad1ab6aul), mk_sl_cui_uint64_c(0x13726121ul, 0x572fe2fful), mk_sl_cui_uint64_c(0x1a488c6ful, 0x199d921eul),
	mk_sl_cui_uint64_c(0x4bc9f9f4ul, 0xda0007caul), mk_sl_cui_uint64_c(0x26f5e6f6ul, 0xe85241c7ul), mk_sl_cui_uint64_c(0x859079dbul, 0xea5947b6ul), mk_sl_cui_uint64_c(0x4f1885c5ul, 0xc99e8c92ul),
	mk_sl_cui_uint64_c(0xd78e761eul, 0xa96f864bul), mk_sl_cui_uint64_c(0x8e36428cul, 0x52b5c17dul), mk_sl_cui_uint64_c(0x69cf6827ul, 0x373063c1ul), mk_sl_cui_uint64_c(0xb607c93dul, 0x9bb4c56eul),
	mk_sl_cui_uint64_c(0x7d820e76ul, 0x0e76b5eaul), mk_sl_cui_uint64_c(0x645c9cc6ul, 0xf07fdc42ul), mk_sl_cui_uint64_c(0xbf38a078ul, 0x243342e0ul), mk_sl_cui_uint64_c(0x5f6b343cul, 0x9d2e7d04ul),
	mk_sl_cui_uint64_c(0xf2c28aebul, 0x600b0ec6ul), mk_sl_cui_uint64_c(0x6c0ed85ful, 0x7254bcacul), mk_sl_cui_uint64_c(0x71592281ul, 0xa4db4fe5ul), mk_sl_cui_uint64_c(0x1967fa69ul, 0xce0fed9ful),
	mk_sl_cui_uint64_c(0xfd5293f8ul, 0xb96545dbul), mk_sl_cui_uint64_c(0xc879e9d7ul, 0xf2a7600bul), mk_sl_cui_uint64_c(0x86024892ul, 0x0193194eul), mk_sl_cui_uint64_c(0xa4f9533bul, 0x2d9cc0b3ul),
	mk_sl_cui_uint64_c(0x9053836cul, 0x15957613ul), mk_sl_cui_uint64_c(0xdb6dcf8aul, 0xfc357bf1ul), mk_sl_cui_uint64_c(0x18beea7aul, 0x7a370f57ul), mk_sl_cui_uint64_c(0x037117caul, 0x50b99066ul),
	mk_sl_cui_uint64_c(0x6ab30a97ul, 0x74424a35ul), mk_sl_cui_uint64_c(0xf4e92f02ul, 0xe325249bul), mk_sl_cui_uint64_c(0x7739db07ul, 0x061ccae1ul), mk_sl_cui_uint64_c(0xd8f3b49cul, 0xeca42a05ul),
	mk_sl_cui_uint64_c(0xbd56be3ful, 0x51382f73ul), mk_sl_cui_uint64_c(0x45faed58ul, 0x43b0bb28ul), mk_sl_cui_uint64_c(0x1c813d5cul, 0x11bf1f83ul), mk_sl_cui_uint64_c(0x8af0e4b6ul, 0xd75fa169ul),
	mk_sl_cui_uint64_c(0x33ee18a4ul, 0x87ad9999ul), mk_sl_cui_uint64_c(0x3c26e8eaul, 0xb1c94410ul), mk_sl_cui_uint64_c(0xb510102bul, 0xc0a822f9ul), mk_sl_cui_uint64_c(0x141eef31ul, 0x0ce6123bul),
	mk_sl_cui_uint64_c(0xfc65b900ul, 0x59ddb154ul), mk_sl_cui_uint64_c(0xe0158640ul, 0xc5e0e607ul), mk_sl_cui_uint64_c(0x884e0798ul, 0x26c3a3cful), mk_sl_cui_uint64_c(0x930d0d95ul, 0x23c535fdul),
	mk_sl_cui_uint64_c(0x35638d75ul, 0x4e9a2b00ul), mk_sl_cui_uint64_c(0x4085fccful, 0x40469dd5ul), mk_sl_cui_uint64_c(0xc4b17ad2ul, 0x8be23a4cul), mk_sl_cui_uint64_c(0xcab2f0fcul, 0x6a3e6a2eul),
	mk_sl_cui_uint64_c(0x2860971aul, 0x6b943fcdul), mk_sl_cui_uint64_c(0x3dde6ee2ul, 0x12e30446ul), mk_sl_cui_uint64_c(0x6222f32aul, 0xe01765aeul), mk_sl_cui_uint64_c(0x5d550bb5ul, 0x478308feul),
	mk_sl_cui_uint64_c(0xa9efa98dul, 0xa0eda22aul), mk_sl_cui_uint64_c(0xc351a716ul, 0x86c40da7ul), mk_sl_cui_uint64_c(0x1105586dul, 0x9c867c84ul), mk_sl_cui_uint64_c(0xdcffee85ul, 0xfda22853ul),
	mk_sl_cui_uint64_c(0xccfbd026ul, 0x2c5eef76ul), mk_sl_cui_uint64_c(0xbaf294cbul, 0x8990d201ul), mk_sl_cui_uint64_c(0xe69464f5ul, 0x2afad975ul), mk_sl_cui_uint64_c(0x94b013aful, 0xdf133e14ul),
	mk_sl_cui_uint64_c(0x06a7d1a3ul, 0x2823c958ul), mk_sl_cui_uint64_c(0x6f95fe51ul, 0x30f61119ul), mk_sl_cui_uint64_c(0xd92ab34eul, 0x462c06c0ul), mk_sl_cui_uint64_c(0xed7bde33ul, 0x887c71d2ul),
	mk_sl_cui_uint64_c(0x79746d6eul, 0x6518393eul), mk_sl_cui_uint64_c(0x5ba41938ul, 0x5d713329ul), mk_sl_cui_uint64_c(0x7c1ba6b9ul, 0x48a97564ul), mk_sl_cui_uint64_c(0x31987c19ul, 0x7bfdac67ul),
	mk_sl_cui_uint64_c(0xde6c23c4ul, 0x4b053d02ul), mk_sl_cui_uint64_c(0x581c49feul, 0xd002d64dul), mk_sl_cui_uint64_c(0xdd474d63ul, 0x38261571ul), mk_sl_cui_uint64_c(0xaa4546c3ul, 0xe473d062ul),
	mk_sl_cui_uint64_c(0x928fce34ul, 0x9455f860ul), mk_sl_cui_uint64_c(0x48161bbaul, 0xcaab94d9ul), mk_sl_cui_uint64_c(0x63912430ul, 0x770e6f68ul), mk_sl_cui_uint64_c(0x6ec8a5e6ul, 0x02c6641cul),
	mk_sl_cui_uint64_c(0x87282515ul, 0x337ddd2bul), mk_sl_cui_uint64_c(0x2cda6b42ul, 0x034b701bul), mk_sl_cui_uint64_c(0xb03d37c1ul, 0x81cb096dul), mk_sl_cui_uint64_c(0xe1084382ul, 0x66c71c6ful),
	mk_sl_cui_uint64_c(0x2b3180c7ul, 0xeb51b255ul), mk_sl_cui_uint64_c(0xdf92b82ful, 0x96c08bbcul), mk_sl_cui_uint64_c(0x5c68c8c0ul, 0xa632f3baul), mk_sl_cui_uint64_c(0x5504cc86ul, 0x1c3d0556ul),
	mk_sl_cui_uint64_c(0xabbfa4e5ul, 0x5fb26b8ful), mk_sl_cui_uint64_c(0x41848b0aul, 0xb3baceb4ul), mk_sl_cui_uint64_c(0xb334a273ul, 0xaa445d32ul), mk_sl_cui_uint64_c(0xbca696f0ul, 0xa85ad881ul),
	mk_sl_cui_uint64_c(0x24f6ec65ul, 0xb528d56cul), mk_sl_cui_uint64_c(0x0ce1512eul, 0x90f4524aul), mk_sl_cui_uint64_c(0x4e9dd79dul, 0x5506d35aul), mk_sl_cui_uint64_c(0x258905faul, 0xc6ce9779ul),
	mk_sl_cui_uint64_c(0x2019295bul, 0x3e109b33ul), mk_sl_cui_uint64_c(0xf8a9478bul, 0x73a054ccul), mk_sl_cui_uint64_c(0x2924f2f9ul, 0x34417eb0ul), mk_sl_cui_uint64_c(0x3993357dul, 0x536d1bc4ul),
	mk_sl_cui_uint64_c(0x38a81ac2ul, 0x1db6ff8bul), mk_sl_cui_uint64_c(0x47c4fbf1ul, 0x7d6016bful), mk_sl_cui_uint64_c(0x1e0faaddul, 0x7667e3f5ul), mk_sl_cui_uint64_c(0x7abcff62ul, 0x938beb96ul),
	mk_sl_cui_uint64_c(0xa78dad94ul, 0x8fc179c9ul), mk_sl_cui_uint64_c(0x8f1f98b7ul, 0x2911e50dul), mk_sl_cui_uint64_c(0x61e48eaeul, 0x27121a91ul), mk_sl_cui_uint64_c(0x4d62f7adul, 0x31859808ul),
	mk_sl_cui_uint64_c(0xeceba345ul, 0xef5ceaebul), mk_sl_cui_uint64_c(0xf5ceb25eul, 0xbc9684ceul), mk_sl_cui_uint64_c(0xf633e20cul, 0xb7f76221ul), mk_sl_cui_uint64_c(0xa32cdf06ul, 0xab8293e4ul),
	mk_sl_cui_uint64_c(0x985a202cul, 0xa5ee2ca4ul), mk_sl_cui_uint64_c(0xcf0b8447ul, 0xcc8a8fb1ul), mk_sl_cui_uint64_c(0x9f765244ul, 0x979859a3ul), mk_sl_cui_uint64_c(0xa8d516b1ul, 0xa1240017ul),
	mk_sl_cui_uint64_c(0x0bd7ba3eul, 0xbb5dc726ul), mk_sl_cui_uint64_c(0xe54bca55ul, 0xb86adb39ul), mk_sl_cui_uint64_c(0x1d7a3afdul, 0x6c478063ul), mk_sl_cui_uint64_c(0x519ec608ul, 0xe7669eddul),
	mk_sl_cui_uint64_c(0x0e5715a2ul, 0xd149aa23ul), mk_sl_cui_uint64_c(0x177d4571ul, 0x848ff194ul), mk_sl_cui_uint64_c(0xeeb55f32ul, 0x41014c22ul), mk_sl_cui_uint64_c(0x0f5e5ca1ul, 0x3a6e2ec2ul),
	mk_sl_cui_uint64_c(0x8029927bul, 0x75f5c361ul), mk_sl_cui_uint64_c(0xad139fabul, 0xc3d6e436ul), mk_sl_cui_uint64_c(0x0d5df1a9ul, 0x4ccf402ful), mk_sl_cui_uint64_c(0x3e8bd948ul, 0xbea5dfc8ul),
	mk_sl_cui_uint64_c(0xa5a0d357ul, 0xbd3ff77eul), mk_sl_cui_uint64_c(0xa2d12e25ul, 0x1f74f645ul), mk_sl_cui_uint64_c(0x66fd9e52ul, 0x5e81a082ul), mk_sl_cui_uint64_c(0x2e0c90ceul, 0x7f687a49ul),
	mk_sl_cui_uint64_c(0xc2e8bcbeul, 0xba973bc5ul), mk_sl_cui_uint64_c(0x000001bcul, 0xe509745ful), mk_sl_cui_uint64_c(0x423777bbul, 0xe6dab3d6ul), mk_sl_cui_uint64_c(0xd1661c7eul, 0xaef06eb5ul),
	mk_sl_cui_uint64_c(0xa1781f35ul, 0x4daacfd8ul), mk_sl_cui_uint64_c(0x2d11284aul, 0x2b16affcul), mk_sl_cui_uint64_c(0xf1fc4f67ul, 0xfa891d1ful), mk_sl_cui_uint64_c(0x73ecc25dul, 0xcb920adaul),
	mk_sl_cui_uint64_c(0xae610c22ul, 0xc2a12651ul), mk_sl_cui_uint64_c(0x96e0a810ul, 0xd356b78aul), mk_sl_cui_uint64_c(0x5a9a381ful, 0x2fe7870ful), mk_sl_cui_uint64_c(0xd5ad62edul, 0xe94e5530ul),
	mk_sl_cui_uint64_c(0xd225e5e8ul, 0x368d1427ul), mk_sl_cui_uint64_c(0x65977b70ul, 0xc7af4631ul), mk_sl_cui_uint64_c(0x99f889b2ul, 0xde39d74ful), mk_sl_cui_uint64_c(0x233f30bful, 0x54e1d143ul),
	mk_sl_cui_uint64_c(0x9a9675d3ul, 0xd9a63c97ul), mk_sl_cui_uint64_c(0x5470554ful, 0xf334f9a8ul), mk_sl_cui_uint64_c(0x166acb74ul, 0x4a4f5688ul), mk_sl_cui_uint64_c(0x70c74caaul, 0xb2e4aeadul),
	mk_sl_cui_uint64_c(0xf0d09164ul, 0x6f294d12ul), mk_sl_cui_uint64_c(0x57b82a89ul, 0x684031d1ul), mk_sl_cui_uint64_c(0xefd95a5aul, 0x61be0b6bul), mk_sl_cui_uint64_c(0x2fbd12e9ul, 0x69f2f29aul),
	mk_sl_cui_uint64_c(0x9bd37013ul, 0xfeff9fe8ul), mk_sl_cui_uint64_c(0x3f9b0404ul, 0xd6085a06ul), mk_sl_cui_uint64_c(0x4940c1f3ul, 0x166cfe15ul), mk_sl_cui_uint64_c(0x09542c4dul, 0xcdf3defbul),
	mk_sl_cui_uint64_c(0xb4c52183ul, 0x85cd5ce3ul), mk_sl_cui_uint64_c(0xc935b7dcul, 0x4462a641ul), mk_sl_cui_uint64_c(0x3417f8a6ul, 0x8ed3b63ful), mk_sl_cui_uint64_c(0xb8095929ul, 0x5b215b40ul),
	mk_sl_cui_uint64_c(0xf99cdaeful, 0x3b8c8572ul), mk_sl_cui_uint64_c(0x018c0614ul, 0xf8fcb95dul), mk_sl_cui_uint64_c(0x1b14accdul, 0x1a3acdf3ul), mk_sl_cui_uint64_c(0x84d471f2ul, 0x00bb732dul),
	mk_sl_cui_uint64_c(0xc1a3110eul, 0x95e8da16ul), mk_sl_cui_uint64_c(0x430a7220ul, 0xbf1a82b8ul), mk_sl_cui_uint64_c(0xb77e090dul, 0x39df210eul), mk_sl_cui_uint64_c(0x5ef4bd9ful, 0x3cd05e9dul),
	mk_sl_cui_uint64_c(0x9d4ff6daul, 0x7e57a444ul), mk_sl_cui_uint64_c(0xda1d60e1ul, 0x83d4a5f8ul), mk_sl_cui_uint64_c(0xb287c384ul, 0x17998e47ul), mk_sl_cui_uint64_c(0xfe3edc12ul, 0x1bb31886ul),
	mk_sl_cui_uint64_c(0xc7fe3cccul, 0x980ccbeful), mk_sl_cui_uint64_c(0xe46fb590ul, 0x189bfd03ul), mk_sl_cui_uint64_c(0x3732fd46ul, 0x9a4c57dcul), mk_sl_cui_uint64_c(0x7ef700a0ul, 0x7cf1ad65ul),
	mk_sl_cui_uint64_c(0x59c64468ul, 0xa31d8859ul), mk_sl_cui_uint64_c(0x762fb0b4ul, 0xd45b61f6ul), mk_sl_cui_uint64_c(0x155baed0ul, 0x99047718ul), mk_sl_cui_uint64_c(0x68755e4cul, 0x3d50baa6ul),
	mk_sl_cui_uint64_c(0xe9214e7ful, 0x22d8b4dful), mk_sl_cui_uint64_c(0x2addbf53ul, 0x2eac95f4ul), mk_sl_cui_uint64_c(0x32ae3909ul, 0xb4bd0109ul), mk_sl_cui_uint64_c(0x834df537ul, 0xb08e3450ul),
	mk_sl_cui_uint64_c(0xfa209da8ul, 0x4220728dul), mk_sl_cui_uint64_c(0x9e691d9bul, 0x9efe23f7ul), mk_sl_cui_uint64_c(0x0446d288ul, 0xc4ae8d7ful), mk_sl_cui_uint64_c(0x7b4cc524ul, 0xe169785bul),
	mk_sl_cui_uint64_c(0x21d87f01ul, 0x35ca1385ul), mk_sl_cui_uint64_c(0xcebb400ful, 0x137b8aa5ul), mk_sl_cui_uint64_c(0x272e2b66ul, 0x580796beul), mk_sl_cui_uint64_c(0x36122641ul, 0x25c2b0deul),
	mk_sl_cui_uint64_c(0x057702bdul, 0xad1efbb2ul), mk_sl_cui_uint64_c(0xd4babb8eul, 0xacf84be9ul), mk_sl_cui_uint64_c(0x91583139ul, 0x641bc67bul), mk_sl_cui_uint64_c(0x8bdc2de0ul, 0x8036e024ul),
	mk_sl_cui_uint64_c(0x603c8156ul, 0xf49f68edul), mk_sl_cui_uint64_c(0xf7d236f7ul, 0xdbef5111ul), mk_sl_cui_uint64_c(0x9727c459ul, 0x8ad21e80ul), mk_sl_cui_uint64_c(0xa08a0896ul, 0x670a5fd7ul),
	mk_sl_cui_uint64_c(0xcb4a8f43ul, 0x09eba9cbul), mk_sl_cui_uint64_c(0x81af564bul, 0x0f7036a1ul), mk_sl_cui_uint64_c(0xc0b99aa7ul, 0x78199abdul), mk_sl_cui_uint64_c(0x959f1ec8ul, 0x3fc8e952ul),
	mk_sl_cui_uint64_c(0x8c505077ul, 0x794a81b9ul), mk_sl_cui_uint64_c(0x3acaaf8ful, 0x056338f0ul), mk_sl_cui_uint64_c(0x07b43f50ul, 0x627a6778ul), mk_sl_cui_uint64_c(0x4a44ab49ul, 0xf5eccc77ul),
	mk_sl_cui_uint64_c(0x3bc3d6e4ul, 0xb679ee98ul), mk_sl_cui_uint64_c(0x9cc0d4d1ul, 0xcf14108cul), mk_sl_cui_uint64_c(0x4406c00bul, 0x206bc8a0ul), mk_sl_cui_uint64_c(0x82a18854ul, 0xc8d72d89ul),
	mk_sl_cui_uint64_c(0x67e366b3ul, 0x5c3c432cul), mk_sl_cui_uint64_c(0xb923dd61ul, 0x102b37f2ul), mk_sl_cui_uint64_c(0x56ab2779ul, 0xd884271dul), mk_sl_cui_uint64_c(0xbe83e1b0ul, 0xff1525aful),
	mk_sl_cui_uint64_c(0xfb7c65d4ul, 0x217e49a9ul), mk_sl_cui_uint64_c(0x6bdbe0e7ul, 0x6d48e7d4ul), mk_sl_cui_uint64_c(0x08df8287ul, 0x45d9179eul), mk_sl_cui_uint64_c(0x22ea6a9aul, 0xdd53bd34ul),
	mk_sl_cui_uint64_c(0xe36e141cul, 0x5622200aul), mk_sl_cui_uint64_c(0x7f805d1bul, 0x8cb750eeul), mk_sl_cui_uint64_c(0xafe5c7a5ul, 0x9f58e837ul), mk_sl_cui_uint64_c(0xe27f996aul, 0x4fb1c23cul),
	mk_sl_cui_uint64_c(0xd3867dfbul, 0x0775f0d0ul), mk_sl_cui_uint64_c(0xd0e673deul, 0x6e88891aul), mk_sl_cui_uint64_c(0x123aeb9eul, 0xafb86c25ul), mk_sl_cui_uint64_c(0x30f1d5d5ul, 0xc145b895ul),
	mk_sl_cui_uint64_c(0xbb434a2dul, 0xee7269e7ul), mk_sl_cui_uint64_c(0x78cb67ecul, 0xf931fa38ul), mk_sl_cui_uint64_c(0xf33b0372ul, 0x323bbf9cul), mk_sl_cui_uint64_c(0x52d66336ul, 0xfb279c74ul),
	mk_sl_cui_uint64_c(0x505f33acul, 0x0afb4eaaul), mk_sl_cui_uint64_c(0xe8a5cd99ul, 0xa2cce187ul), mk_sl_cui_uint64_c(0x53497480ul, 0x1e2d30bbul), mk_sl_cui_uint64_c(0x8d2d5711ul, 0xd5876d90ul),
	mk_sl_cui_uint64_c(0x1f1a4128ul, 0x91bc038eul), mk_sl_cui_uint64_c(0xd6e2e71dul, 0x82e56648ul), mk_sl_cui_uint64_c(0x74036c3aul, 0x497732b7ul), mk_sl_cui_uint64_c(0x89b67ed9ul, 0x6361f5abul),
	mk_sl_cui_uint64_c(0xffed95d8ul, 0xf1ea02a2ul), mk_sl_cui_uint64_c(0xe72b3bd6ul, 0x1464d43dul), mk_sl_cui_uint64_c(0xa6300f17ul, 0x0bdc4820ul), mk_sl_cui_uint64_c(0xebc18760ul, 0xed78a77aul),
	mk_sl_cui_uint64_c(0xe6a6be5aul, 0x05a12138ul), mk_sl_cui_uint64_c(0xb5a122a5ul, 0xb4f87c98ul), mk_sl_cui_uint64_c(0x563c6089ul, 0x140b6990ul), mk_sl_cui_uint64_c(0x4c46cb2eul, 0x391f5dd5ul),
	mk_sl_cui_uint64_c(0xd932addbul, 0xc9b79434ul), mk_sl_cui_uint64_c(0x08ea70e4ul, 0x2015aff5ul), mk_sl_cui_uint64_c(0xd765a667ul, 0x3e478cf1ul), mk_sl_cui_uint64_c(0xc4fb757eul, 0xab278d99ul),
	mk_sl_cui_uint64_c(0xdf11c686ul, 0x2d6e0692ul), mk_sl_cui_uint64_c(0xddeb84f1ul, 0x0d7f3b16ul), mk_sl_cui_uint64_c(0x6f2ef604ul, 0xa665ea04ul), mk_sl_cui_uint64_c(0x4a8e0f0ful, 0xf0e0dfb3ul),
	mk_sl_cui_uint64_c(0xa5edeef8ul, 0x3dbcba51ul), mk_sl_cui_uint64_c(0xfc4f0a2aul, 0x0ea4371eul), mk_sl_cui_uint64_c(0xe83e1da8ul, 0x5cb38429ul), mk_sl_cui_uint64_c(0xdc8ff882ul, 0xba1b1ce2ul),
	mk_sl_cui_uint64_c(0xcd45505eul, 0x8353e80dul), mk_sl_cui_uint64_c(0x18d19a00ul, 0xd4db0717ul), mk_sl_cui_uint64_c(0x34a0cfedul, 0xa5f38101ul), mk_sl_cui_uint64_c(0x0be77e51ul, 0x8887caf2ul),
	mk_sl_cui_uint64_c(0x1e341438ul, 0xb3c45136ul), mk_sl_cui_uint64_c(0xe05797f4ul, 0x9089ccf9ul), mk_sl_cui_uint64_c(0xffd23f9dul, 0xf2591d14ul), mk_sl_cui_uint64_c(0x543dda22ul, 0x8595c5cdul),
	mk_sl_cui_uint64_c(0x661f81fdul, 0x99052a33ul), mk_sl_cui_uint64_c(0x8736e641ul, 0xdb0f7b76ul), mk_sl_cui_uint64_c(0x15227725ul, 0x418e5307ul), mk_sl_cui_uint64_c(0xe25f7f46ul, 0x162eb2faul),
	mk_sl_cui_uint64_c(0x48a8b212ul, 0x6c13d9feul), mk_sl_cui_uint64_c(0xafdc5417ul, 0x92e76eeaul), mk_sl_cui_uint64_c(0x03d912bful, 0xc6d1898ful), mk_sl_cui_uint64_c(0x31b1aafaul, 0x1b83f51bul),
	mk_sl_cui_uint64_c(0xf1ac2796ul, 0xe42ab7d9ul), mk_sl_cui_uint64_c(0x40a3a7d7ul, 0xfcd2ebacul), mk_sl_cui_uint64_c(0x1056136dul, 0x0afbbcc5ul), mk_sl_cui_uint64_c(0x7889e1ddul, 0x9a6d0c85ul),
	mk_sl_cui_uint64_c(0xd3352578ul, 0x2a7974aaul), mk_sl_cui_uint64_c(0xa7e25d09ul, 0x078ac09bul), mk_sl_cui_uint64_c(0xbd4138b3ul, 0xeac6edd0ul), mk_sl_cui_uint64_c(0x920abfbeul, 0x71eb9e70ul),
	mk_sl_cui_uint64_c(0xa2a5d0f5ul, 0x4fc2625cul), mk_sl_cui_uint64_c(0xc054e36bul, 0x0b1290a3ul), mk_sl_cui_uint64_c(0xf6dd59fful, 0x62fe932bul), mk_sl_cui_uint64_c(0x35373545ul, 0x11a8ac7dul),
	mk_sl_cui_uint64_c(0xca845e91ul, 0x72fadcd4ul), mk_sl_cui_uint64_c(0x84f82b60ul, 0x329d20dcul), mk_sl_cui_uint64_c(0x79c62ce1ul, 0xcd672f18ul), mk_sl_cui_uint64_c(0x8b09a2adul, 0xd124642cul),
	mk_sl_cui_uint64_c(0xd0c1e96aul, 0x19d9e726ul), mk_sl_cui_uint64_c(0x5a786a9bul, 0x4ba9500cul), mk_sl_cui_uint64_c(0x0e020336ul, 0x634c43f3ul), mk_sl_cui_uint64_c(0xc17b474aul, 0xeb66d822ul),
	mk_sl_cui_uint64_c(0x6a731ae3ul, 0xec9baac2ul), mk_sl_cui_uint64_c(0x8226667aul, 0xe0840258ul), mk_sl_cui_uint64_c(0x67d45676ul, 0x91caeca5ul), mk_sl_cui_uint64_c(0x1d94155cul, 0x4875adb5ul),
	mk_sl_cui_uint64_c(0x6d00fd98ul, 0x5b813fdful), mk_sl_cui_uint64_c(0x51286efcul, 0xb774cd06ul), mk_sl_cui_uint64_c(0x5e883447ul, 0x1fa744aful), mk_sl_cui_uint64_c(0xf72ca0aeul, 0xe761ae2eul),
	mk_sl_cui_uint64_c(0xbe40e4cdul, 0xaee8e09aul), mk_sl_cui_uint64_c(0xe9970bbbul, 0x5118f665ul), mk_sl_cui_uint64_c(0x726e4bebul, 0x33df1964ul), mk_sl_cui_uint64_c(0x703b0007ul, 0x29199762ul),
	mk_sl_cui_uint64_c(0x4631d816ul, 0xf5ef30a7ul), mk_sl_cui_uint64_c(0xb880b5b5ul, 0x1504a6beul), mk_sl_cui_uint64_c(0x641793c3ul, 0x7ed84b6cul), mk_sl_cui_uint64_c(0x7b21ed77ul, 0xf6e97d96ul),
	mk_sl_cui_uint64_c(0x77630631ul, 0x2ef96b73ul), mk_sl_cui_uint64_c(0xae528948ul, 0xe86ff3f4ul), mk_sl_cui_uint64_c(0x53dbd7f2ul, 0x86a3f8f8ul), mk_sl_cui_uint64_c(0x16cadce7ul, 0x4cfc1063ul),
	mk_sl_cui_uint64_c(0x005c19bdul, 0xfa52c6ddul), mk_sl_cui_uint64_c(0x68868f5dul, 0x64d46ad3ul), mk_sl_cui_uint64_c(0x3a9d512cul, 0xcf1e186aul), mk_sl_cui_uint64_c(0x367e62c2ul, 0x385660aeul),
	mk_sl_cui_uint64_c(0xe359e7eaul, 0x77dcb1d7ul), mk_sl_cui_uint64_c(0x526c0773ul, 0x749abe6eul), mk_sl_cui_uint64_c(0x735ae5f9ul, 0xd09f734bul), mk_sl_cui_uint64_c(0x493fc7ccul, 0x8a558ba8ul),
	mk_sl_cui_uint64_c(0xb0b9c153ul, 0x3041ab45ul), mk_sl_cui_uint64_c(0x321958baul, 0x470a59bdul), mk_sl_cui_uint64_c(0x852db00bul, 0x5f46c393ul), mk_sl_cui_uint64_c(0x91209b2bul, 0xd336b0e5ul),
	mk_sl_cui_uint64_c(0x6e604f7dul, 0x659ef19ful), mk_sl_cui_uint64_c(0xb99a8ae2ul, 0x782ccb24ul), mk_sl_cui_uint64_c(0xccf52ab6ul, 0xc814c4c7ul), mk_sl_cui_uint64_c(0x4727d9aful, 0xbe11727bul),
	mk_sl_cui_uint64_c(0x7e950d0cul, 0x0121b34dul), mk_sl_cui_uint64_c(0x756f4356ul, 0x70ad471ful), mk_sl_cui_uint64_c(0xf5add442ul, 0x615a6849ul), mk_sl_cui_uint64_c(0x4e87e099ul, 0x80b9957aul),
	mk_sl_cui_uint64_c(0x2acfa1dful, 0x50aee355ul), mk_sl_cui_uint64_c(0xd898263aul, 0xfd2fd556ul), mk_sl_cui_uint64_c(0xc8f4924dul, 0xd80c8fd6ul), mk_sl_cui_uint64_c(0xcf99ca3dul, 0x754a173aul),
	mk_sl_cui_uint64_c(0xfe477bacul, 0xaf91bf3cul), mk_sl_cui_uint64_c(0xed5371f6ul, 0xd690c12dul), mk_sl_cui_uint64_c(0x831a5c28ul, 0x5e687094ul), mk_sl_cui_uint64_c(0xc5d3c90aul, 0x3708a0a4ul),
	mk_sl_cui_uint64_c(0x0f7f9037ul, 0x17d06580ul), mk_sl_cui_uint64_c(0x19f9bb13ul, 0xb8fdf27ful), mk_sl_cui_uint64_c(0xb1bd6f1bul, 0x4d502843ul), mk_sl_cui_uint64_c(0x1c761ba3ul, 0x8fff4012ul),
	mk_sl_cui_uint64_c(0x0d1530c4ul, 0xe2e21f3bul), mk_sl_cui_uint64_c(0x8943ce69ul, 0xa7372c8aul), mk_sl_cui_uint64_c(0xe5184e11ul, 0xfeb5ce66ul), mk_sl_cui_uint64_c(0x618bdb80ul, 0xbd736621ul),
	mk_sl_cui_uint64_c(0x7d29bad6ul, 0x8b574d0bul), mk_sl_cui_uint64_c(0x81bb613eul, 0x25e6fe5bul), mk_sl_cui_uint64_c(0x071c9c10ul, 0xbc07913ful), mk_sl_cui_uint64_c(0xc7beeb79ul, 0x09ac2d97ul),
	mk_sl_cui_uint64_c(0xc3e58d35ul, 0x3bc5d757ul), mk_sl_cui_uint64_c(0xeb017892ul, 0xf38f61e8ul), mk_sl_cui_uint64_c(0xd4effb9cul, 0x9b1cc21aul), mk_sl_cui_uint64_c(0x99727d26ul, 0xf494f7abul),
	mk_sl_cui_uint64_c(0xa3e063a2ul, 0x956b3e03ul), mk_sl_cui_uint64_c(0x9d4a8b9aul, 0x4aa09c30ul), mk_sl_cui_uint64_c(0x3f6ab7d5ul, 0x00090fb4ul), mk_sl_cui_uint64_c(0x9cc0f2a0ul, 0x57268ac0ul),
	mk_sl_cui_uint64_c(0x3dee9d2dul, 0xedbf42d1ul), mk_sl_cui_uint64_c(0x330f49c8ul, 0x7960a972ul), mk_sl_cui_uint64_c(0xc6b27202ul, 0x87421b41ul), mk_sl_cui_uint64_c(0x0ac59ec0ul, 0x7c00369cul),
	mk_sl_cui_uint64_c(0xef4eac49ul, 0xcb353425ul), mk_sl_cui_uint64_c(0xf450244eul, 0xef0129d8ul), mk_sl_cui_uint64_c(0x8acc46e5ul, 0xcaf4deb6ul), mk_sl_cui_uint64_c(0x2ffeab63ul, 0x989263f7ul),
	mk_sl_cui_uint64_c(0x8f7cb9feul, 0x5d7a4578ul), mk_sl_cui_uint64_c(0x5bd8f764ul, 0x4e634635ul), mk_sl_cui_uint64_c(0x427a7315ul, 0xbf2dc900ul), mk_sl_cui_uint64_c(0x17d0c4aaul, 0x2125261cul),
	mk_sl_cui_uint64_c(0x3992486cul, 0x93518e50ul), mk_sl_cui_uint64_c(0xb4cbfee0ul, 0xa2d7d4c3ul), mk_sl_cui_uint64_c(0x7c75d620ul, 0x2c5ddd8dul), mk_sl_cui_uint64_c(0xdbc295d8ul, 0xe35b6c61ul),
	mk_sl_cui_uint64_c(0x60b369d3ul, 0x02032b19ul), mk_sl_cui_uint64_c(0xce42685ful, 0xdce44132ul), mk_sl_cui_uint64_c(0x06f3ddb9ul, 0xddf65610ul), mk_sl_cui_uint64_c(0x8ea4d21dul, 0xb5e148f0ul),
	mk_sl_cui_uint64_c(0x20b0fce6ul, 0x2fcd496ful), mk_sl_cui_uint64_c(0x2c1b9123ul, 0x58b0ee31ul), mk_sl_cui_uint64_c(0xb28317b8ul, 0x18f5a308ul), mk_sl_cui_uint64_c(0xa89c1e18ul, 0x9ca6d2cful),
	mk_sl_cui_uint64_c(0x0c6b1857ul, 0x6aaadbc8ul), mk_sl_cui_uint64_c(0xb65deaa9ul, 0x1299fae3ul), mk_sl_cui_uint64_c(0xfb2b794bul, 0x7f1027e7ul), mk_sl_cui_uint64_c(0x04e4317ful, 0x443b5bebul),
	mk_sl_cui_uint64_c(0x4b852d32ul, 0x5939d0a6ul), mk_sl_cui_uint64_c(0xd5ae6beeul, 0xfb207ffcul), mk_sl_cui_uint64_c(0x309682b2ul, 0x81c7d374ul), mk_sl_cui_uint64_c(0xbae309a1ul, 0x94c3b475ul),
	mk_sl_cui_uint64_c(0x8cc3f97bul, 0x13b49f05ul), mk_sl_cui_uint64_c(0x98a9422ful, 0xf8293967ul), mk_sl_cui_uint64_c(0x244b16b0ul, 0x1076ff7cul), mk_sl_cui_uint64_c(0xf8bf571cul, 0x663d67eeul),
	mk_sl_cui_uint64_c(0x1f0d6758ul, 0xeee30da1ul), mk_sl_cui_uint64_c(0xc9b611d9ul, 0x7adeb9b7ul), mk_sl_cui_uint64_c(0xb7afd588ul, 0x7b6c57a2ul), mk_sl_cui_uint64_c(0x6290ae84ul, 0x6b984fe1ul),
	mk_sl_cui_uint64_c(0x94df4cdeul, 0xacc1a5fdul), mk_sl_cui_uint64_c(0x058a5bd1ul, 0xc5483afful), mk_sl_cui_uint64_c(0x63166cc1ul, 0x42ba3c37ul), mk_sl_cui_uint64_c(0x8db8526eul, 0xb2f76f40ul),
	mk_sl_cui_uint64_c(0xe1088003ul, 0x6f0d6d4eul), mk_sl_cui_uint64_c(0x9e0523c9ul, 0x971d311dul), mk_sl_cui_uint64_c(0x45ec2824ul, 0xcc7cd691ul), mk_sl_cui_uint64_c(0x575b8359ul, 0xe62382c9ul),
	mk_sl_cui_uint64_c(0xfa9e400dul, 0xc4889995ul), mk_sl_cui_uint64_c(0xd1823ecbul, 0x45721568ul), mk_sl_cui_uint64_c(0xdafd983bul, 0x8206082ful), mk_sl_cui_uint64_c(0xaa7d2908ul, 0x2386a8cbul),
	mk_sl_cui_uint64_c(0x269fcd44ul, 0x03b87588ul), mk_sl_cui_uint64_c(0x1b91f5f7ul, 0x28bdd1e0ul), mk_sl_cui_uint64_c(0xe4669f39ul, 0x040201f6ul), mk_sl_cui_uint64_c(0x7a1d7c21ul, 0x8cf04adeul),
	mk_sl_cui_uint64_c(0x65623c29ul, 0xd79ce5ceul), mk_sl_cui_uint64_c(0x23684490ul, 0x96c00bb1ul), mk_sl_cui_uint64_c(0xab9bf187ul, 0x9da503baul), mk_sl_cui_uint64_c(0xbc23ecb1ul, 0xa458058eul),
	mk_sl_cui_uint64_c(0x9a58df01ul, 0xbb401eccul), mk_sl_cui_uint64_c(0xa070e868ul, 0xa85f143dul), mk_sl_cui_uint64_c(0x4ff18830ul, 0x7df2239eul), mk_sl_cui_uint64_c(0x14d565b4ul, 0x1a641183ul),
	mk_sl_cui_uint64_c(0xee133374ul, 0x52701602ul), mk_sl_cui_uint64_c(0x950e3dcful, 0x3f285e09ul), mk_sl_cui_uint64_c(0x59930254ul, 0xb9c80953ul), mk_sl_cui_uint64_c(0x3bf29940ul, 0x8930da6dul),
	mk_sl_cui_uint64_c(0xa955943ful, 0x53691387ul), mk_sl_cui_uint64_c(0xa15edecaul, 0xa9cb8784ul), mk_sl_cui_uint64_c(0x29142127ul, 0x352be9a0ul), mk_sl_cui_uint64_c(0x76f0371ful, 0xff4e7afbul),
	mk_sl_cui_uint64_c(0x0239f450ul, 0x274f2228ul), mk_sl_cui_uint64_c(0xbb073af0ul, 0x1d5e868bul), mk_sl_cui_uint64_c(0xbfc80571ul, 0xc10e96c1ul), mk_sl_cui_uint64_c(0xd2670885ul, 0x68222e23ul),
	mk_sl_cui_uint64_c(0x9671a3d4ul, 0x8e80b5b0ul), mk_sl_cui_uint64_c(0x55b5d38aul, 0xe193bb81ul), mk_sl_cui_uint64_c(0x693ae2d0ul, 0xa18b04b8ul), mk_sl_cui_uint64_c(0x5c48b4ecul, 0xadd5335ful),
	mk_sl_cui_uint64_c(0xfd743b19ul, 0x4916a1caul), mk_sl_cui_uint64_c(0x25770181ul, 0x34be98c4ul), mk_sl_cui_uint64_c(0xe77987e8ul, 0x3c54a4adul), mk_sl_cui_uint64_c(0x28e11014ul, 0xda33e1b9ul),
	mk_sl_cui_uint64_c(0x270cc59eul, 0x226aa213ul), mk_sl_cui_uint64_c(0x71495f75ul, 0x6d1a5f60ul), mk_sl_cui_uint64_c(0x9be853fbul, 0x60afef77ul), mk_sl_cui_uint64_c(0xadc786a7ul, 0xf7443dbful),
	mk_sl_cui_uint64_c(0x09044561ul, 0x73b29a82ul), mk_sl_cui_uint64_c(0x58bc7a66ul, 0xc232bd5eul), mk_sl_cui_uint64_c(0xf306558cul, 0x673ac8b2ul), mk_sl_cui_uint64_c(0x41f639c6ul, 0xb6c9772aul),
	mk_sl_cui_uint64_c(0x216defe9ul, 0x9fda35daul), mk_sl_cui_uint64_c(0x11640cc7ul, 0x1c7be615ul), mk_sl_cui_uint64_c(0x93c43694ul, 0x565c5527ul), mk_sl_cui_uint64_c(0xea038e62ul, 0x46777839ul),
	mk_sl_cui_uint64_c(0xf9abf3ceul, 0x5a3e2469ul), mk_sl_cui_uint64_c(0x741e768dul, 0x0fd312d2ul), mk_sl_cui_uint64_c(0x0144b883ul, 0xced652c6ul), mk_sl_cui_uint64_c(0xc20b5a5bul, 0xa33f8552ul),
	mk_sl_cui_uint64_c(0x1ae69633ul, 0xc3435a9dul), mk_sl_cui_uint64_c(0x97a28ca4ul, 0x088cfdecul), mk_sl_cui_uint64_c(0x8824a43cul, 0x1e96f420ul), mk_sl_cui_uint64_c(0x37612fa6ul, 0x6eeea746ul),
	mk_sl_cui_uint64_c(0x6b4cb165ul, 0xf9cf0e5aul), mk_sl_cui_uint64_c(0x43aa1c06ul, 0xa0abfb4aul), mk_sl_cui_uint64_c(0x7f4dc26ful, 0xf162796bul), mk_sl_cui_uint64_c(0x6cbacc8eul, 0x54ed9b0ful),
	mk_sl_cui_uint64_c(0xa6b7ffeful, 0xd2bb253eul), mk_sl_cui_uint64_c(0x2e25bc95ul, 0xb0a29d4ful), mk_sl_cui_uint64_c(0x86d6a58bul, 0xdef1388cul), mk_sl_cui_uint64_c(0xded74ac5ul, 0x76b6f054ul),
	mk_sl_cui_uint64_c(0x8030bdbcul, 0x2b45805dul), mk_sl_cui_uint64_c(0x3c81af70ul, 0xe94d9289ul), mk_sl_cui_uint64_c(0x3eff6ddaul, 0x9e3100dbul), mk_sl_cui_uint64_c(0xb38dc39ful, 0xdfcc8847ul),
	mk_sl_cui_uint64_c(0x12388552ul, 0x8d17b87eul), mk_sl_cui_uint64_c(0xf2da0ed2ul, 0x40b1b642ul), mk_sl_cui_uint64_c(0x44cefadcul, 0xd54bf9a9ul), mk_sl_cui_uint64_c(0x1312200eul, 0x433c7ee6ul),
	mk_sl_cui_uint64_c(0x9ffcc84ful, 0x3a78c748ul), mk_sl_cui_uint64_c(0xf0cd1f72ul, 0x248576bbul), mk_sl_cui_uint64_c(0xec697405ul, 0x3638cfe4ul), mk_sl_cui_uint64_c(0x2ba7b67cul, 0x0cec4e4cul),
	mk_sl_cui_uint64_c(0xac2f4df3ul, 0xe5ce32edul), mk_sl_cui_uint64_c(0xcb33d143ul, 0x26ea4c11ul), mk_sl_cui_uint64_c(0xa4e9044cul, 0xc77e58bcul), mk_sl_cui_uint64_c(0x5f513293ul, 0xd934fceful),
	mk_sl_cui_uint64_c(0x5dc96455ul, 0x06e55444ul), mk_sl_cui_uint64_c(0x50de418ful, 0x317de40aul), mk_sl_cui_uint64_c(0x388cb31aul, 0x69dde259ul), mk_sl_cui_uint64_c(0x2db4a834ul, 0x55820a86ul),
	mk_sl_cui_uint64_c(0x9010a91eul, 0x84711ae9ul), mk_sl_cui_uint64_c(0x4df7f0b7ul, 0xb1498371ul), mk_sl_cui_uint64_c(0xd62a2eabul, 0xc0977179ul), mk_sl_cui_uint64_c(0x22fac097ul, 0xaa8d5c0eul),
	mk_sl_cui_uint64_c(0xf49fcc2ful, 0xf1daf39bul), mk_sl_cui_uint64_c(0x487fd5c6ul, 0x6ff29281ul), mk_sl_cui_uint64_c(0xe8a30667ul, 0xfcdca83ful), mk_sl_cui_uint64_c(0x2c9b4be3ul, 0xd2fcce63ul),
	mk_sl_cui_uint64_c(0xda3ff74bul, 0x93fbbbc2ul), mk_sl_cui_uint64_c(0x2fa165d2ul, 0xfe70ba66ul), mk_sl_cui_uint64_c(0xa103e279ul, 0x970e93d4ul), mk_sl_cui_uint64_c(0xbecdec77ul, 0xb0e45e71ul),
	mk_sl_cui_uint64_c(0xcfb41e72ul, 0x3985e497ul), mk_sl_cui_uint64_c(0xb70aaa02ul, 0x5ef75017ul), mk_sl_cui_uint64_c(0xd42309f0ul, 0x3840b8e0ul), mk_sl_cui_uint64_c(0x8efc1ad0ul, 0x35898579ul),
	mk_sl_cui_uint64_c(0x96c6920bul, 0xe2b2abc5ul), mk_sl_cui_uint64_c(0x66af4163ul, 0x375a9172ul), mk_sl_cui_uint64_c(0x2174abdcul, 0xca7127fbul), mk_sl_cui_uint64_c(0xb33ccea6ul, 0x4a72ff41ul),
	mk_sl_cui_uint64_c(0xf04a4933ul, 0x083066a5ul), mk_sl_cui_uint64_c(0x8d970acdul, 0xd7289af5ul), mk_sl_cui_uint64_c(0x8f96e8e0ul, 0x31c8c25eul), mk_sl_cui_uint64_c(0xf3fec022ul, 0x76875d47ul),
	mk_sl_cui_uint64_c(0xec7bf310ul, 0x056190ddul), mk_sl_cui_uint64_c(0xf5adb0aeul, 0xbb0f1491ul), mk_sl_cui_uint64_c(0x9b50f885ul, 0x0fd58892ul), mk_sl_cui_uint64_c(0x49754883ul, 0x58b74de8ul),
	mk_sl_cui_uint64_c(0xa3354ff6ul, 0x91531c61ul), mk_sl_cui_uint64_c(0x0702bbe4ul, 0x81d2c6eeul), mk_sl_cui_uint64_c(0x89fb2405ul, 0x7deded98ul), mk_sl_cui_uint64_c(0xac307513ul, 0x8596e902ul),
	mk_sl_cui_uint64_c(0x1d2d3580ul, 0x172772edul), mk_sl_cui_uint64_c(0xeb738fc2ul, 0x8e6bc30dul), mk_sl_cui_uint64_c(0x5854ef8ful, 0x63044326ul), mk_sl_cui_uint64_c(0x9e5c5232ul, 0x5add3bbeul),
	mk_sl_cui_uint64_c(0x90aa53cful, 0x325c4623ul), mk_sl_cui_uint64_c(0xc1d24d51ul, 0x349dd067ul), mk_sl_cui_uint64_c(0x2051cfeeul, 0xa69ea624ul), mk_sl_cui_uint64_c(0x13220f0aul, 0x862e7e4ful),
	mk_sl_cui_uint64_c(0xce393994ul, 0x04e04864ul), mk_sl_cui_uint64_c(0xd9c42ca4ul, 0x7086fcb7ul), mk_sl_cui_uint64_c(0x685ad223ul, 0x8a03e7ccul), mk_sl_cui_uint64_c(0x066484b2ul, 0xab2ff1dbul),
	mk_sl_cui_uint64_c(0xfe9d5d70ul, 0xefbf79ecul), mk_sl_cui_uint64_c(0x5b13b9ddul, 0x9c481854ul), mk_sl_cui_uint64_c(0x15f0d475ul, 0xed1509adul), mk_sl_cui_uint64_c(0x0bebcd06ul, 0x0ec79851ul),
	mk_sl_cui_uint64_c(0xd58c6791ul, 0x183ab7f8ul), mk_sl_cui_uint64_c(0xd1187c50ul, 0x52f3eee4ul), mk_sl_cui_uint64_c(0xc95d1192ul, 0xe54e82fful), mk_sl_cui_uint64_c(0x86eea14cul, 0xb9ac6ca2ul),
	mk_sl_cui_uint64_c(0x3485beb1ul, 0x53677d5dul), mk_sl_cui_uint64_c(0xdd191d78ul, 0x1f8c492aul), mk_sl_cui_uint64_c(0xf60866baul, 0xa784ebf9ul), mk_sl_cui_uint64_c(0x518f643bul, 0xa2d08c74ul),
	mk_sl_cui_uint64_c(0x8852e956ul, 0xe1087c22ul), mk_sl_cui_uint64_c(0xa768cb8dul, 0xc410ae8dul), mk_sl_cui_uint64_c(0x38047726ul, 0xbfec8e1aul), mk_sl_cui_uint64_c(0xa67738b4ul, 0xcd3b45aaul),
	mk_sl_cui_uint64_c(0xad16691cul, 0xec0dde19ul), mk_sl_cui_uint64_c(0xc6d43193ul, 0x80462e07ul), mk_sl_cui_uint64_c(0xc5a5876dul, 0x0ba61938ul), mk_sl_cui_uint64_c(0x16b9fa1ful, 0xa58fd840ul),
	mk_sl_cui_uint64_c(0x188ab117ul, 0x3ca74f18ul), mk_sl_cui_uint64_c(0xabda2f98ul, 0xc99c021ful), mk_sl_cui_uint64_c(0x3e0580abul, 0x134ae816ul), mk_sl_cui_uint64_c(0x5f3b05b7ul, 0x73645abbul),
	mk_sl_cui_uint64_c(0x2501a2beul, 0x5575f2f6ul), mk_sl_cui_uint64_c(0x1b2f7400ul, 0x4e7e8ba9ul), mk_sl_cui_uint64_c(0x1cd75803ul, 0x71e8d953ul), mk_sl_cui_uint64_c(0x7f6ed895ul, 0x62764e30ul),
	mk_sl_cui_uint64_c(0xb15926fful, 0x596f003dul), mk_sl_cui_uint64_c(0x9f65293dul, 0xa8c5d6b9ul), mk_sl_cui_uint64_c(0x6ecef04dul, 0xd690f84cul), mk_sl_cui_uint64_c(0x4782275ful, 0xff33af88ul),
	mk_sl_cui_uint64_c(0xe4143308ul, 0x3f820801ul), mk_sl_cui_uint64_c(0xfd0dfe40ul, 0x9a1af9b5ul), mk_sl_cui_uint64_c(0x4325a334ul, 0x2cdb396bul), mk_sl_cui_uint64_c(0x8ae77e62ul, 0xb301b252ul),
	mk_sl_cui_uint64_c(0xc36f9e9ful, 0x6655615aul), mk_sl_cui_uint64_c(0x85455a2dul, 0x92d32c09ul), mk_sl_cui_uint64_c(0xf2c7dea9ul, 0x49477485ul), mk_sl_cui_uint64_c(0x63cfb4c1ul, 0x33a39ebaul),
	mk_sl_cui_uint64_c(0x83b040ccul, 0x6ebc5462ul), mk_sl_cui_uint64_c(0x3b9454c8ul, 0xfdb326b0ul), mk_sl_cui_uint64_c(0x56f56a9eul, 0x87ffd78cul), mk_sl_cui_uint64_c(0x2dc2940dul, 0x99f42bc6ul),
	mk_sl_cui_uint64_c(0x98f7df09ul, 0x6b096e2dul), mk_sl_cui_uint64_c(0x19a6e01eul, 0x3ad852bful), mk_sl_cui_uint64_c(0x42a99ccbul, 0xdbd4b40bul), mk_sl_cui_uint64_c(0xa59998aful, 0x45e9c559ul),
	mk_sl_cui_uint64_c(0x366295e8ul, 0x07d93186ul), mk_sl_cui_uint64_c(0x6b48181bul, 0xfaa1f773ul), mk_sl_cui_uint64_c(0x1fec57e2ul, 0x157a0a1dul), mk_sl_cui_uint64_c(0x4667446aul, 0xf6201ad5ul),
	mk_sl_cui_uint64_c(0xe615ebcaul, 0xcfb0f075ul), mk_sl_cui_uint64_c(0xb8f31f4ful, 0x68290778ul), mk_sl_cui_uint64_c(0x22713ed6ul, 0xce22d11eul), mk_sl_cui_uint64_c(0x3057c1a7ul, 0x2ec3c93bul),
	mk_sl_cui_uint64_c(0xcb46acc3ul, 0x7c3f1f2ful), mk_sl_cui_uint64_c(0xdbb893fdul, 0x02aaf50eul), mk_sl_cui_uint64_c(0x331fd92eul, 0x600b9fcful), mk_sl_cui_uint64_c(0xa498f961ul, 0x48ea3ad6ul),
	mk_sl_cui_uint64_c(0xa8d8426eul, 0x8b6a83eaul), mk_sl_cui_uint64_c(0xa089b274ul, 0xb7735cdcul), mk_sl_cui_uint64_c(0x87f6b373ul, 0x1e524a11ul), mk_sl_cui_uint64_c(0x118808e5ul, 0xcbc96749ul),
	mk_sl_cui_uint64_c(0x9906e4c7ul, 0xb19bd394ul), mk_sl_cui_uint64_c(0xafed7f7eul, 0x9b24a20cul), mk_sl_cui_uint64_c(0x6509eadeul, 0xeb3644a7ul), mk_sl_cui_uint64_c(0x6c1ef1d3ul, 0xe8ef0edeul),
	mk_sl_cui_uint64_c(0xb9c97d43ul, 0xe9798fb4ul), mk_sl_cui_uint64_c(0xa2f2d784ul, 0x740c28a3ul), mk_sl_cui_uint64_c(0x7b849647ul, 0x6197566ful), mk_sl_cui_uint64_c(0x7a5be3e6ul, 0xb65f069dul),
	mk_sl_cui_uint64_c(0xf96330edul, 0x78be6f10ul), mk_sl_cui_uint64_c(0xeee60de7ul, 0x7a076a15ul), mk_sl_cui_uint64_c(0x2b4bee4aul, 0xa08b9bd0ul), mk_sl_cui_uint64_c(0x6a56a63eul, 0xc7b8894eul),
	mk_sl_cui_uint64_c(0x02121359ul, 0xba34fef4ul), mk_sl_cui_uint64_c(0x4cbf99f8ul, 0x283703fcul), mk_sl_cui_uint64_c(0x39807135ul, 0x0caf30c8ul), mk_sl_cui_uint64_c(0xd0a77a89ul, 0xf017687aul),
	mk_sl_cui_uint64_c(0xf1c1a9ebul, 0x9e423569ul), mk_sl_cui_uint64_c(0x8c797628ul, 0x2dee8199ul), mk_sl_cui_uint64_c(0x5d1737a5ul, 0xdd1f7abdul), mk_sl_cui_uint64_c(0x4f53433cul, 0x09a9fa80ul),
	mk_sl_cui_uint64_c(0xfa8b0c53ul, 0xdf7ca1d9ul), mk_sl_cui_uint64_c(0x3fd9dcbcul, 0x886ccb77ul), mk_sl_cui_uint64_c(0xc040917cul, 0xa91b4720ul), mk_sl_cui_uint64_c(0x7dd00142ul, 0xf9d1dcdful),
	mk_sl_cui_uint64_c(0x8476fc1dul, 0x4f387b58ul), mk_sl_cui_uint64_c(0x23f8e7c5ul, 0xf3316503ul), mk_sl_cui_uint64_c(0x032a2244ul, 0xe7e37339ul), mk_sl_cui_uint64_c(0x5c87a5d7ul, 0x50f5a74bul),
	mk_sl_cui_uint64_c(0x082b4cc4ul, 0x3698992eul), mk_sl_cui_uint64_c(0xdf917becul, 0xb858f63cul), mk_sl_cui_uint64_c(0x3270b8fcul, 0x5bf86ddaul), mk_sl_cui_uint64_c(0x10ae72bbul, 0x29b5dd76ul),
	mk_sl_cui_uint64_c(0x576ac94eul, 0x7700362bul), mk_sl_cui_uint64_c(0x1ad112daul, 0xc61efb8ful), mk_sl_cui_uint64_c(0x691bc30eul, 0xc5faa427ul), mk_sl_cui_uint64_c(0xff246311ul, 0xcc327143ul),
	mk_sl_cui_uint64_c(0x3142368eul, 0x30e53206ul), mk_sl_cui_uint64_c(0x71380e31ul, 0xe02ca396ul), mk_sl_cui_uint64_c(0x958d5c96ul, 0x0aad76f1ul), mk_sl_cui_uint64_c(0xf8d6f430ul, 0xc16da536ul),
	mk_sl_cui_uint64_c(0xc8ffd13ful, 0x1be7e1d2ul), mk_sl_cui_uint64_c(0x7578ae66ul, 0x004ddbe1ul), mk_sl_cui_uint64_c(0x05833f01ul, 0x067be646ul), mk_sl_cui_uint64_c(0xbb34b5adul, 0x3bfe586dul),
	mk_sl_cui_uint64_c(0x095f34c9ul, 0xa12b97f0ul), mk_sl_cui_uint64_c(0x247ab645ul, 0x25d60ca8ul), mk_sl_cui_uint64_c(0xdcdbc6f3ul, 0x017477d1ul), mk_sl_cui_uint64_c(0x4a2e14d4ul, 0xdecad24dul),
	mk_sl_cui_uint64_c(0xbdb5e6d9ul, 0xbe0a1eebul), mk_sl_cui_uint64_c(0x2a7e70f7ul, 0x794301abul), mk_sl_cui_uint64_c(0xdef42d8aul, 0x270540fdul), mk_sl_cui_uint64_c(0x01078ec0ul, 0xa34c22c1ul),
	mk_sl_cui_uint64_c(0xe5de511aul, 0xf4c16387ul), mk_sl_cui_uint64_c(0x7ebb3a52ul, 0xbd9a330aul), mk_sl_cui_uint64_c(0x77697857ul, 0xaa7d6435ul), mk_sl_cui_uint64_c(0x004e8316ul, 0x03ae4c32ul),
	mk_sl_cui_uint64_c(0xe7a21020ul, 0xad78e312ul), mk_sl_cui_uint64_c(0x9d41a70cul, 0x6ab420f2ul), mk_sl_cui_uint64_c(0x28e06c18ul, 0xea1141e6ul), mk_sl_cui_uint64_c(0xd2b28cbdul, 0x984f6b28ul),
	mk_sl_cui_uint64_c(0x26b75f6cul, 0x446e9d83ul), mk_sl_cui_uint64_c(0xba47568cul, 0x4d418d7ful), mk_sl_cui_uint64_c(0xd80badbful, 0xe6183d8eul), mk_sl_cui_uint64_c(0x0e206d7ful, 0x5f166044ul),
	mk_sl_cui_uint64_c(0xe258a439ul, 0x11cbca3eul), mk_sl_cui_uint64_c(0x723a1746ul, 0xb21dc0bcul), mk_sl_cui_uint64_c(0xc7caa854ul, 0xf5d7cdd3ul), mk_sl_cui_uint64_c(0x7cac3288ul, 0x3d261d9cul),
	mk_sl_cui_uint64_c(0x7690c264ul, 0x23ba942cul), mk_sl_cui_uint64_c(0x17e55524ul, 0x478042b8ul), mk_sl_cui_uint64_c(0xe0be4776ul, 0x56a2389ful), mk_sl_cui_uint64_c(0x4d289b5eul, 0x67ab2da0ul),
	mk_sl_cui_uint64_c(0x44862b9cul, 0x8fbbfd31ul), mk_sl_cui_uint64_c(0xb47cc804ul, 0x9d141365ul), mk_sl_cui_uint64_c(0x822c1b36ul, 0x2b91c793ul), mk_sl_cui_uint64_c(0x4eb14655ul, 0xfb13dfd8ul),
	mk_sl_cui_uint64_c(0x1ecbba07ul, 0x14e2a97bul), mk_sl_cui_uint64_c(0x6143459dul, 0x5cde5f14ul), mk_sl_cui_uint64_c(0x53a8fbf1ul, 0xd5f0ac89ul), mk_sl_cui_uint64_c(0x97ea04d8ul, 0x1c5e5b00ul),
	mk_sl_cui_uint64_c(0x622181a8ul, 0xd4fdb3f3ul), mk_sl_cui_uint64_c(0xe9bcd341ul, 0x572a1208ul), mk_sl_cui_uint64_c(0x14112586ul, 0x43cce58aul), mk_sl_cui_uint64_c(0x9144c5feul, 0xa4c6e0a4ul),
	mk_sl_cui_uint64_c(0x0d33d065ul, 0x65cf620ful), mk_sl_cui_uint64_c(0x54a48d48ul, 0x9f219ca1ul), mk_sl_cui_uint64_c(0xc43e5eacul, 0x6d63c821ul), mk_sl_cui_uint64_c(0xa9728b3aul, 0x72770daful),
	mk_sl_cui_uint64_c(0xd7934e7bul, 0x20df87eful), mk_sl_cui_uint64_c(0xe35503b6ul, 0x1a3e86e5ul), mk_sl_cui_uint64_c(0xcae321fbul, 0xc819d504ul), mk_sl_cui_uint64_c(0x129a50b3ul, 0xac60bfa6ul),
	mk_sl_cui_uint64_c(0xcd5e68eaul, 0x7e9fb6c3ul), mk_sl_cui_uint64_c(0xb01c9019ul, 0x9483b1c7ul), mk_sl_cui_uint64_c(0x3de93cd5ul, 0xc295376cul), mk_sl_cui_uint64_c(0xaed52edful, 0x2ab9ad13ul),
	mk_sl_cui_uint64_c(0x2e60f512ul, 0xc0a07884ul), mk_sl_cui_uint64_c(0xbc3d86a3ul, 0xe36210c9ul), mk_sl_cui_uint64_c(0x35269d9bul, 0x163951ceul), mk_sl_cui_uint64_c(0x0c7d6e2aul, 0xd0cdb5faul),
	mk_sl_cui_uint64_c(0x59e86297ul, 0xd87f5733ul), mk_sl_cui_uint64_c(0x298ef221ul, 0x898db0e7ul), mk_sl_cui_uint64_c(0x55000029ul, 0xd1a5aa7eul), mk_sl_cui_uint64_c(0x8bc08ae1ul, 0xb5061b45ul),
	mk_sl_cui_uint64_c(0xc2c31c2bul, 0x6c92703aul), mk_sl_cui_uint64_c(0x94cc596bul, 0xaf25ef42ul), mk_sl_cui_uint64_c(0x0a1d73dbul, 0x22540456ul), mk_sl_cui_uint64_c(0x04b6a0f9ul, 0xd9c4179aul),
	mk_sl_cui_uint64_c(0xeffdafa2ul, 0xae3d3c60ul), mk_sl_cui_uint64_c(0xf7c8075bul, 0xb49496c4ul), mk_sl_cui_uint64_c(0x9cc5c714ul, 0x1d1cd4e3ul), mk_sl_cui_uint64_c(0x78bd1638ul, 0x218e5534ul),
	mk_sl_cui_uint64_c(0xb2f11568ul, 0xf850246aul), mk_sl_cui_uint64_c(0xedfabcfaul, 0x9502bc29ul), mk_sl_cui_uint64_c(0x796ce5f2ul, 0xda23051bul), mk_sl_cui_uint64_c(0xaae128b0ul, 0xdc93537cul),
	mk_sl_cui_uint64_c(0x3a493da0ul, 0xee4b29aeul), mk_sl_cui_uint64_c(0xb5df6b2cul, 0x416895d7ul), mk_sl_cui_uint64_c(0xfcabbd25ul, 0x122d7f37ul), mk_sl_cui_uint64_c(0x70810b58ul, 0x105dc4b1ul),
	mk_sl_cui_uint64_c(0xe10fdd37ul, 0xf7882a90ul), mk_sl_cui_uint64_c(0x524dcab5ul, 0x518a3f5cul), mk_sl_cui_uint64_c(0x3c9e8587ul, 0x8451255bul), mk_sl_cui_uint64_c(0x40298281ul, 0x19bd34e2ul),
	mk_sl_cui_uint64_c(0x74a05b6ful, 0x5d3ceccbul), mk_sl_cui_uint64_c(0xb6100215ul, 0x42e13ecaul), mk_sl_cui_uint64_c(0x0ff979d1ul, 0x2f59e2acul), mk_sl_cui_uint64_c(0x6037da27ul, 0xe4f9cc50ul),
	mk_sl_cui_uint64_c(0x5e92975aul, 0x0df1847dul), mk_sl_cui_uint64_c(0xd66de190ul, 0xd3e623feul), mk_sl_cui_uint64_c(0x5032d6b8ul, 0x7b568048ul), mk_sl_cui_uint64_c(0x9a36b7ceul, 0x8235216eul),
	mk_sl_cui_uint64_c(0x80272a7aul, 0x24f64b4aul), mk_sl_cui_uint64_c(0x93efed8bul, 0x8c6916f7ul), mk_sl_cui_uint64_c(0x37ddbff4ul, 0x4cce1555ul), mk_sl_cui_uint64_c(0x4b95db5dul, 0x4b99bd25ul),
	mk_sl_cui_uint64_c(0x92d3fda1ul, 0x69812fc0ul), mk_sl_cui_uint64_c(0xfb1a4a9aul, 0x90660bb6ul), mk_sl_cui_uint64_c(0x730c1969ul, 0x46a4b9b2ul), mk_sl_cui_uint64_c(0x81e289aaul, 0x7f49da68ul),
	mk_sl_cui_uint64_c(0x64669a0ful, 0x83b1a05ful), mk_sl_cui_uint64_c(0x27b3ff7dul, 0x9644f48bul), mk_sl_cui_uint64_c(0xcc6b615cul, 0x8db675b3ul), mk_sl_cui_uint64_c(0x674f20b9ul, 0xbcebbe95ul),
	mk_sl_cui_uint64_c(0x6f312382ul, 0x75655982ul), mk_sl_cui_uint64_c(0x5ae48871ul, 0x3e45cf05ul), mk_sl_cui_uint64_c(0xbf619f99ul, 0x54c21157ul), mk_sl_cui_uint64_c(0xeabac460ul, 0x40a8eae9ul),
	mk_sl_cui_uint64_c(0x454c6fe9ul, 0xf2c0c1cdul), mk_sl_cui_uint64_c(0x419cf649ul, 0x6412691cul), mk_sl_cui_uint64_c(0xd3dc3beful, 0x265b0f70ul), mk_sl_cui_uint64_c(0x6d0e60f5ul, 0xc3578a9eul),
	mk_sl_cui_uint64_c(0x5b0e6085ul, 0x26323c55ul), mk_sl_cui_uint64_c(0x1a46c1a9ul, 0xfa1b59f5ul), mk_sl_cui_uint64_c(0xa9e245a1ul, 0x7c4c8ffaul), mk_sl_cui_uint64_c(0x65ca5159ul, 0xdb2955d7ul),
	mk_sl_cui_uint64_c(0x05db0a76ul, 0xce35afc2ul), mk_sl_cui_uint64_c(0x81eac77eul, 0xa9113d45ul), mk_sl_cui_uint64_c(0x528ef88aul, 0xb6ac0a0dul), mk_sl_cui_uint64_c(0xa09ea253ul, 0x597be3fful),
	mk_sl_cui_uint64_c(0x430ddfb3ul, 0xac48cd56ul), mk_sl_cui_uint64_c(0xc4b3a67aul, 0xf45ce46ful), mk_sl_cui_uint64_c(0x4ececfd8ul, 0xfbe2d05eul), mk_sl_cui_uint64_c(0x3ef56f10ul, 0xb39935f0ul),
	mk_sl_cui_uint64_c(0x0b22d682ul, 0x9cd619c6ul), mk_sl_cui_uint64_c(0x17fd460aul, 0x74df2069ul), mk_sl_cui_uint64_c(0x6cf8cc8eul, 0x8510ed40ul), mk_sl_cui_uint64_c(0xd6c824bful, 0x3a6ecaa7ul),
	mk_sl_cui_uint64_c(0x61243d58ul, 0x1a817049ul), mk_sl_cui_uint64_c(0x048bacb6ul, 0xbbc163a2ul), mk_sl_cui_uint64_c(0xd9a38ac2ul, 0x7d44cc32ul), mk_sl_cui_uint64_c(0x7fddff5bul, 0xaaf410abul),
	mk_sl_cui_uint64_c(0xad6d495aul, 0xa804824bul), mk_sl_cui_uint64_c(0xe1a6a74ful, 0x2d8c9f94ul), mk_sl_cui_uint64_c(0xd4f78512ul, 0x35dee8e3ul), mk_sl_cui_uint64_c(0xfd4b7f88ul, 0x6540d893ul),
	mk_sl_cui_uint64_c(0x247c2004ul, 0x2aa4bfdaul), mk_sl_cui_uint64_c(0x096ea1c5ul, 0x17d1327cul), mk_sl_cui_uint64_c(0xd56966b4ul, 0x361a6685ul), mk_sl_cui_uint64_c(0x277da5c3ul, 0x1221057dul),
	mk_sl_cui_uint64_c(0x94d59893ul, 0xa43acff7ul), mk_sl_cui_uint64_c(0x64f0c51cul, 0xcdc02281ul), mk_sl_cui_uint64_c(0x3d33bcc4ul, 0xff6189dbul), mk_sl_cui_uint64_c(0xe005cb18ul, 0x4ce66af1ul),
	mk_sl_cui_uint64_c(0xff5ccd1dul, 0x1db99beaul), mk_sl_cui_uint64_c(0xb0b854a7ul, 0xfe42980ful), mk_sl_cui_uint64_c(0x7bd46a6aul, 0x718d4b9ful), mk_sl_cui_uint64_c(0xd10fa8ccul, 0x22a5fd8cul),
	mk_sl_cui_uint64_c(0xd3148495ul, 0x2be4bd31ul), mk_sl_cui_uint64_c(0xc7fa975ful, 0xcb243847ul), mk_sl_cui_uint64_c(0x4886ed1eul, 0x5846c407ul), mk_sl_cui_uint64_c(0x28cddb79ul, 0x1eb70b04ul),
	mk_sl_cui_uint64_c(0xc2b00be2ul, 0xf573417ful), mk_sl_cui_uint64_c(0x5c959045ul, 0x2180f877ul), mk_sl_cui_uint64_c(0x7a6bddfful, 0xf370eb00ul), mk_sl_cui_uint64_c(0xce509e38ul, 0xd6d9d6a4ul),
	mk_sl_cui_uint64_c(0xebeb0f00ul, 0x647fa702ul), mk_sl_cui_uint64_c(0x1dcc06cful, 0x76606f06ul), mk_sl_cui_uint64_c(0xe4d9f28bul, 0xa286ff0aul), mk_sl_cui_uint64_c(0xd85a305dul, 0xc918c262ul),
	mk_sl_cui_uint64_c(0x475b1d87ul, 0x32225f54ul), mk_sl_cui_uint64_c(0x2d4fb516ul, 0x68ccb5feul), mk_sl_cui_uint64_c(0xa679b9d9ul, 0xd72bba20ul), mk_sl_cui_uint64_c(0x53841c0dul, 0x912d43a5ul),
	mk_sl_cui_uint64_c(0x3b7eaa48ul, 0xbf12a4e8ul), mk_sl_cui_uint64_c(0x781e0e47ul, 0xf22f1ddful), mk_sl_cui_uint64_c(0xeff20ce6ul, 0x0ab50973ul), mk_sl_cui_uint64_c(0x20d261d1ul, 0x9dffb742ul),
	mk_sl_cui_uint64_c(0x16a12b03ul, 0x062a2e39ul), mk_sl_cui_uint64_c(0x1960eb22ul, 0x39650495ul), mk_sl_cui_uint64_c(0x251c16feul, 0xd50eb8b8ul), mk_sl_cui_uint64_c(0x9ac0c330ul, 0xf826016eul),
	mk_sl_cui_uint64_c(0xed152665ul, 0x953e7671ul), mk_sl_cui_uint64_c(0x02d63194ul, 0xa6369570ul), mk_sl_cui_uint64_c(0x5074f083ul, 0x94b1c987ul), mk_sl_cui_uint64_c(0x70ba598cul, 0x90b25ce1ul),
	mk_sl_cui_uint64_c(0x794a1581ul, 0x0b9742f6ul), mk_sl_cui_uint64_c(0x0d5925e9ul, 0xfcaf8c6cul), mk_sl_cui_uint64_c(0x3067716cul, 0xd868744eul), mk_sl_cui_uint64_c(0x910ab077ul, 0xe8d7731bul),
	mk_sl_cui_uint64_c(0x6a61bbdbul, 0x5ac42f61ul), mk_sl_cui_uint64_c(0x93513efbul, 0xf0851567ul), mk_sl_cui_uint64_c(0xf494724bul, 0x9e83e9d5ul), mk_sl_cui_uint64_c(0xe887e198ul, 0x5c09648dul),
	mk_sl_cui_uint64_c(0x34b1d3c6ul, 0x75370cfdul), mk_sl_cui_uint64_c(0xdc35e433ul, 0xbc0d255dul), mk_sl_cui_uint64_c(0xd0aab842ul, 0x34131be0ul), mk_sl_cui_uint64_c(0x08042a50ul, 0xb48b7eaful),
	mk_sl_cui_uint64_c(0x9997c4eeul, 0x44a3ab35ul), mk_sl_cui_uint64_c(0x829a7b49ul, 0x201799d0ul), mk_sl_cui_uint64_c(0x263b8307ul, 0xb7c54441ul), mk_sl_cui_uint64_c(0x752f95f4ul, 0xfd6a6ca6ul),
	mk_sl_cui_uint64_c(0x92721740ul, 0x2c08c6e5ul), mk_sl_cui_uint64_c(0x2a8ab754ul, 0xa795d9eeul), mk_sl_cui_uint64_c(0xa442f755ul, 0x2f72943dul), mk_sl_cui_uint64_c(0x2c31334eul, 0x19781208ul),
	mk_sl_cui_uint64_c(0x4fa98d7cul, 0xeaee6291ul), mk_sl_cui_uint64_c(0x55c3862ful, 0x665db309ul), mk_sl_cui_uint64_c(0xbd061017ul, 0x5d53b1f3ul), mk_sl_cui_uint64_c(0x46fe6cb8ul, 0x40413f27ul),
	mk_sl_cui_uint64_c(0x3fe03792ul, 0xdf0cfa59ul), mk_sl_cui_uint64_c(0xcfe70037ul, 0x2eb85e8ful), mk_sl_cui_uint64_c(0xa7be29e7ul, 0xadbce118ul), mk_sl_cui_uint64_c(0xe544ee5cul, 0xde8431ddul),
	mk_sl_cui_uint64_c(0x8a781b1bul, 0x41f1873eul), mk_sl_cui_uint64_c(0xa5c94c78ul, 0xa0d2f0e7ul), mk_sl_cui_uint64_c(0x39412e28ul, 0x77b60728ul), mk_sl_cui_uint64_c(0xa1265ef3ul, 0xafc9a62cul),
	mk_sl_cui_uint64_c(0xbcc2770cul, 0x6a2506c5ul), mk_sl_cui_uint64_c(0x3ab66dd5ul, 0xdce1ce12ul), mk_sl_cui_uint64_c(0xe65499d0ul, 0x4a675b37ul), mk_sl_cui_uint64_c(0x7d8f5234ul, 0x81bfd216ul),
	mk_sl_cui_uint64_c(0x0f6f64fcul, 0xec15f389ul), mk_sl_cui_uint64_c(0x74efbe61ul, 0x8b5b13c8ul), mk_sl_cui_uint64_c(0xacdc82b7ul, 0x14273e1dul), mk_sl_cui_uint64_c(0xdd40bfe0ul, 0x03199d17ul),
	mk_sl_cui_uint64_c(0x37e99257ul, 0xe7e061f8ul), mk_sl_cui_uint64_c(0xfa526269ul, 0x04775aaaul), mk_sl_cui_uint64_c(0x8bbbf63aul, 0x463d56f9ul), mk_sl_cui_uint64_c(0xf0013f15ul, 0x43a26e64ul),
	mk_sl_cui_uint64_c(0xa8307e9ful, 0x879ec898ul), mk_sl_cui_uint64_c(0xcc4c27a4ul, 0x150177ccul), mk_sl_cui_uint64_c(0x1b432f2cul, 0xca1d3348ul), mk_sl_cui_uint64_c(0xde1d1f8ful, 0x9f6fa013ul),
	mk_sl_cui_uint64_c(0x606602a0ul, 0x47a7ddd6ul), mk_sl_cui_uint64_c(0xd237ab64ul, 0xcc1cb2c7ul), mk_sl_cui_uint64_c(0x9b938e72ul, 0x25fcd1d3ul), mk_sl_cui_uint64_c(0xec4e0370ul, 0x8e0ff476ul),
	mk_sl_cui_uint64_c(0xfeb2fbdaul, 0x3d03c12dul), mk_sl_cui_uint64_c(0xae0bced2ul, 0xee43889aul), mk_sl_cui_uint64_c(0x22cb8923ul, 0xebfb4f43ul), mk_sl_cui_uint64_c(0x69360d01ul, 0x3cf7396dul),
	mk_sl_cui_uint64_c(0x855e3602ul, 0xd2d4e022ul), mk_sl_cui_uint64_c(0x073805baul, 0xd01f784cul), mk_sl_cui_uint64_c(0x33e17a13ul, 0x3852f546ul), mk_sl_cui_uint64_c(0xdf487405ul, 0x8ac7b638ul),
	mk_sl_cui_uint64_c(0xba92b29cul, 0x678aa14aul), mk_sl_cui_uint64_c(0x0ce89fc7ul, 0x6cfaadcdul), mk_sl_cui_uint64_c(0x5f9d4e09ul, 0x08339e34ul), mk_sl_cui_uint64_c(0xf1afe929ul, 0x1f5923b9ul),
	mk_sl_cui_uint64_c(0x6e3480f6ul, 0x0f4a265ful), mk_sl_cui_uint64_c(0xeebf3a2aul, 0xb29b841cul), mk_sl_cui_uint64_c(0xe21938a8ul, 0x8f91b4adul), mk_sl_cui_uint64_c(0x57dfeff8ul, 0x45c6d3c3ul),
	mk_sl_cui_uint64_c(0x2f006b0bul, 0xf62caaf2ul), mk_sl_cui_uint64_c(0x62f479eful, 0x6f75ee78ul), mk_sl_cui_uint64_c(0x11a55ad4ul, 0x1c8916a9ul), mk_sl_cui_uint64_c(0xf229d290ul, 0x84fed453ul),
	mk_sl_cui_uint64_c(0x42f1c27bul, 0x16b000e6ul), mk_sl_cui_uint64_c(0x2b1f7674ul, 0x9823c074ul), mk_sl_cui_uint64_c(0x4b76eca3ul, 0xc2745360ul), mk_sl_cui_uint64_c(0x8c98f463ul, 0xb91691bdul),
	mk_sl_cui_uint64_c(0x14bcc93cul, 0xf1ade66aul), mk_sl_cui_uint64_c(0x8885213eul, 0x6d458397ul), mk_sl_cui_uint64_c(0x8e177df0ul, 0x274d4711ul), mk_sl_cui_uint64_c(0xb49b73b5ul, 0x503f2951ul),
	mk_sl_cui_uint64_c(0x10168168ul, 0xc3f96b6bul), mk_sl_cui_uint64_c(0x0e3d963bul, 0x63cab0aeul), mk_sl_cui_uint64_c(0x8dfc4b56ul, 0x55a1db14ul), mk_sl_cui_uint64_c(0xf789f135ul, 0x6e14de5cul),
	mk_sl_cui_uint64_c(0x683e68aful, 0x4e51dac1ul), mk_sl_cui_uint64_c(0xc9a84f9dul, 0x8d4b0fd9ul), mk_sl_cui_uint64_c(0x3691e03ful, 0x52a0f9d1ul), mk_sl_cui_uint64_c(0x5ed86e46ul, 0xe1878e80ul),
	mk_sl_cui_uint64_c(0x3c711a0eul, 0x99d07150ul), mk_sl_cui_uint64_c(0x5a0865b2ul, 0x0c4e9310ul), mk_sl_cui_uint64_c(0x56fbfc1ful, 0xe4f0682eul), mk_sl_cui_uint64_c(0xea8d5de3ul, 0x105edf9bul),
	mk_sl_cui_uint64_c(0x71abfdb1ul, 0x2379187aul), mk_sl_cui_uint64_c(0x2eb99de1ul, 0xbee77b9cul), mk_sl_cui_uint64_c(0x21ecc0eaul, 0x33cf4523ul), mk_sl_cui_uint64_c(0x59a4d752ul, 0x1805c7a1ul),
	mk_sl_cui_uint64_c(0x3896f5ebul, 0x56ae7c72ul), mk_sl_cui_uint64_c(0xaa638f3dul, 0xb18f75dcul), mk_sl_cui_uint64_c(0x9f39358dul, 0xabe9808eul), mk_sl_cui_uint64_c(0xb7defa91ul, 0xc00b72acul),
	mk_sl_cui_uint64_c(0x6b5541fdul, 0x62492d92ul), mk_sl_cui_uint64_c(0x6dc6dee8ul, 0xf92e4d5bul), mk_sl_cui_uint64_c(0x353f57abul, 0xc4beea7eul), mk_sl_cui_uint64_c(0x735769d6ul, 0xda5690ceul),
	mk_sl_cui_uint64_c(0x0a234aa6ul, 0x42391484ul), mk_sl_cui_uint64_c(0xf6f95080ul, 0x28f80d9dul), mk_sl_cui_uint64_c(0xb8e319a2ul, 0x7ab3f215ul), mk_sl_cui_uint64_c(0x31ad9c11ul, 0x51341a4dul),
	mk_sl_cui_uint64_c(0x773c22a5ul, 0x7bef5805ul), mk_sl_cui_uint64_c(0x45c7561aul, 0x07968633ul), mk_sl_cui_uint64_c(0xf913da9eul, 0x249dbe36ul), mk_sl_cui_uint64_c(0xda652d9bul, 0x78a64c68ul),
	mk_sl_cui_uint64_c(0x4c27a97ful, 0x3bc334eful), mk_sl_cui_uint64_c(0x76621220ul, 0xe66b17f4ul), mk_sl_cui_uint64_c(0x96774389ul, 0x9acd7d0bul), mk_sl_cui_uint64_c(0xf3ee5bcaul, 0xe0ed6782ul),
	mk_sl_cui_uint64_c(0x409f7536ul, 0x00c879fcul), mk_sl_cui_uint64_c(0x06d09a39ul, 0xb5926db6ul), mk_sl_cui_uint64_c(0x6f83aeb0ul, 0x317ac588ul), mk_sl_cui_uint64_c(0x01e6ca4aul, 0x86381f21ul),
	mk_sl_cui_uint64_c(0x66ff3462ul, 0xd19f3025ul), mk_sl_cui_uint64_c(0x72207c24ul, 0xddfd3bfbul), mk_sl_cui_uint64_c(0x4af6b6d3ul, 0xe2ece2ebul), mk_sl_cui_uint64_c(0x9c994dbeul, 0xc7ea08deul),
	mk_sl_cui_uint64_c(0x49ace597ul, 0xb09a8bc4ul), mk_sl_cui_uint64_c(0xb38c4766ul, 0xcf0797baul), mk_sl_cui_uint64_c(0x131b9373ul, 0xc57c2a75ul), mk_sl_cui_uint64_c(0xb1822cceul, 0x61931e58ul),
	mk_sl_cui_uint64_c(0x9d7555b9ul, 0x09ba1c0cul), mk_sl_cui_uint64_c(0x127fafddul, 0x937d11d2ul), mk_sl_cui_uint64_c(0x29da3badul, 0xc66d92e4ul), mk_sl_cui_uint64_c(0xa2c1d571ul, 0x54c2ecbcul),
	mk_sl_cui_uint64_c(0x58c5134dul, 0x82f6fe24ul), mk_sl_cui_uint64_c(0x1c3ae351ul, 0x5b62274ful), mk_sl_cui_uint64_c(0xe907c82eul, 0x01cb8126ul), mk_sl_cui_uint64_c(0xf8ed0919ul, 0x13e37fcbul),
	mk_sl_cui_uint64_c(0x3249d8f9ul, 0xc80046c9ul), mk_sl_cui_uint64_c(0x80cf9bedul, 0xe388fb63ul), mk_sl_cui_uint64_c(0x1881539aul, 0x116cf19eul), mk_sl_cui_uint64_c(0x5103f3f7ul, 0x6bd52457ul),
	mk_sl_cui_uint64_c(0x15b7e6f5ul, 0xae47f7a8ul), mk_sl_cui_uint64_c(0xdbd7c6deul, 0xd47e9ccful), mk_sl_cui_uint64_c(0x44e55c41ul, 0x0228bb1aul), mk_sl_cui_uint64_c(0xb647d425ul, 0x5edb4e99ul),
	mk_sl_cui_uint64_c(0x5d11882bul, 0xb8aafc30ul), mk_sl_cui_uint64_c(0xf5098bbbul, 0x29d3212aul), mk_sl_cui_uint64_c(0x8fb5ea14ul, 0xe90296b3ul), mk_sl_cui_uint64_c(0x677b9421ul, 0x57dd025aul),
	mk_sl_cui_uint64_c(0xfb58e7c0ul, 0xa390acb5ul), mk_sl_cui_uint64_c(0x89d3674cul, 0x83bd4a01ul), mk_sl_cui_uint64_c(0x9e2da4dful, 0x4bf3b93bul), mk_sl_cui_uint64_c(0xfcc41e32ul, 0x8cab4829ul),
	mk_sl_cui_uint64_c(0x03f38c96ul, 0xba582c52ul), mk_sl_cui_uint64_c(0xcad1bdbdul, 0x7fd85db2ul), mk_sl_cui_uint64_c(0xbbb442c1ul, 0x6082ae83ul), mk_sl_cui_uint64_c(0xb95fe86bul, 0xa5da9ab0ul),
	mk_sl_cui_uint64_c(0xb22e0467ul, 0x3771a93ful), mk_sl_cui_uint64_c(0x845358c9ul, 0x493152d8ul), mk_sl_cui_uint64_c(0xbe2a4886ul, 0x97b4541eul), mk_sl_cui_uint64_c(0x95a2dc2dul, 0xd38e6966ul),
	mk_sl_cui_uint64_c(0xc02c11acul, 0x923c852bul), mk_sl_cui_uint64_c(0x2388b199ul, 0x0df2a87bul), mk_sl_cui_uint64_c(0x7c8008faul, 0x1b4f37beul), mk_sl_cui_uint64_c(0x1f70d0c8ul, 0x4d54e503ul),
	mk_sl_cui_uint64_c(0x5490adecul, 0x7ece57d4ul), mk_sl_cui_uint64_c(0x002b3c27ul, 0xd9063a3aul), mk_sl_cui_uint64_c(0x7eaea384ul, 0x8030a2bful), mk_sl_cui_uint64_c(0xc602326dul, 0xed2003c0ul),
	mk_sl_cui_uint64_c(0x83a7287dul, 0x69a94086ul), mk_sl_cui_uint64_c(0xc57a5fcbul, 0x30f57a8aul), mk_sl_cui_uint64_c(0xb56844e4ul, 0x79ebe779ul), mk_sl_cui_uint64_c(0xa373b40ful, 0x05dcbce9ul),
	mk_sl_cui_uint64_c(0xd71a786eul, 0x88570ee2ul), mk_sl_cui_uint64_c(0x879cbacdul, 0xbde8f6a0ul), mk_sl_cui_uint64_c(0x976ad1bcul, 0xc164a32ful), mk_sl_cui_uint64_c(0xab21e25eul, 0x9666d78bul),
	mk_sl_cui_uint64_c(0x901063aaul, 0xe5e5c33cul), mk_sl_cui_uint64_c(0x9818b344ul, 0x48698d90ul), mk_sl_cui_uint64_c(0xe36487aeul, 0x3e1e8abbul), mk_sl_cui_uint64_c(0xafbdf931ul, 0x893bdcb4ul),
	mk_sl_cui_uint64_c(0x6345a0dcul, 0x5fbbd519ul), mk_sl_cui_uint64_c(0x8628fe26ul, 0x9b9465caul), mk_sl_cui_uint64_c(0x1e5d0160ul, 0x3f9c51ecul), mk_sl_cui_uint64_c(0x4de44006ul, 0xa15049b7ul),
	mk_sl_cui_uint64_c(0xbf6c70e5ul, 0xf776cbb1ul), mk_sl_cui_uint64_c(0x411218f2ul, 0xef552bedul), mk_sl_cui_uint64_c(0xcb0c0708ul, 0x705a36a3ul), mk_sl_cui_uint64_c(0xe74d1475ul, 0x4f986044ul),
	mk_sl_cui_uint64_c(0xcd56d943ul, 0x0ea8280eul), mk_sl_cui_uint64_c(0xc12591d7ul, 0x535f5065ul), mk_sl_cui_uint64_c(0xc83223f1ul, 0x720aef96ul), mk_sl_cui_uint64_c(0xc3a0396ful, 0x7363a51ful),
};


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_tiger_base_key_schedule(mk_lib_crypto_hash_block_tiger_base_block_pt const block) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint64_t const s_key_schedule_constant_a = mk_sl_cui_uint64_c(0xa5a5a5a5ul, 0xa5a5a5a5ul);
	mk_lang_constexpr_static mk_sl_cui_uint64_t const s_key_schedule_constant_b = mk_sl_cui_uint64_c(0x01234567ul, 0x89abcdeful);

	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	mk_lang_assert(block);

	mk_sl_cui_uint64_xor3(&block->m_uint64s[7], &s_key_schedule_constant_a, &ta);
	mk_sl_cui_uint64_sub2_wrap_cid_cod(&block->m_uint64s[0], &ta);
	mk_sl_cui_uint64_xor2(&block->m_uint64s[1], &block->m_uint64s[0]);
	mk_sl_cui_uint64_add2_wrap_cid_cod(&block->m_uint64s[2], &block->m_uint64s[1]);
	mk_sl_cui_uint64_not2(&block->m_uint64s[1], &ta);
	mk_sl_cui_uint64_shl2(&ta, 19);
	mk_sl_cui_uint64_xor2(&ta, &block->m_uint64s[2]);
	mk_sl_cui_uint64_sub2_wrap_cid_cod(&block->m_uint64s[3], &ta);
	mk_sl_cui_uint64_xor2(&block->m_uint64s[4], &block->m_uint64s[3]);
	mk_sl_cui_uint64_add2_wrap_cid_cod(&block->m_uint64s[5], &block->m_uint64s[4]);
	mk_sl_cui_uint64_not2(&block->m_uint64s[4], &ta);
	mk_sl_cui_uint64_shr2(&ta, 23);
	mk_sl_cui_uint64_xor2(&ta, &block->m_uint64s[5]);
	mk_sl_cui_uint64_sub2_wrap_cid_cod(&block->m_uint64s[6], &ta);
	mk_sl_cui_uint64_xor2(&block->m_uint64s[7], &block->m_uint64s[6]);
	mk_sl_cui_uint64_add2_wrap_cid_cod(&block->m_uint64s[0], &block->m_uint64s[7]);
	mk_sl_cui_uint64_not2(&block->m_uint64s[7], &ta);
	mk_sl_cui_uint64_shl2(&ta, 19);
	mk_sl_cui_uint64_xor2(&ta, &block->m_uint64s[0]);
	mk_sl_cui_uint64_sub2_wrap_cid_cod(&block->m_uint64s[1], &ta);
	mk_sl_cui_uint64_xor2(&block->m_uint64s[2], &block->m_uint64s[1]);
	mk_sl_cui_uint64_add2_wrap_cid_cod(&block->m_uint64s[3], &block->m_uint64s[2]);
	mk_sl_cui_uint64_not2(&block->m_uint64s[2], &ta);
	mk_sl_cui_uint64_shr2(&ta, 23);
	mk_sl_cui_uint64_xor2(&ta, &block->m_uint64s[3]);
	mk_sl_cui_uint64_sub2_wrap_cid_cod(&block->m_uint64s[4], &ta);
	mk_sl_cui_uint64_xor2(&block->m_uint64s[5], &block->m_uint64s[4]);
	mk_sl_cui_uint64_add2_wrap_cid_cod(&block->m_uint64s[6], &block->m_uint64s[5]);
	mk_sl_cui_uint64_xor3(&block->m_uint64s[6], &s_key_schedule_constant_b, &ta);
	mk_sl_cui_uint64_sub2_wrap_cid_cod(&block->m_uint64s[7], &ta);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_tiger_base_round(mk_sl_cui_uint64_prt const a, mk_sl_cui_uint64_prt const b, mk_sl_cui_uint64_prt const c, mk_sl_cui_uint64_prct const x, int const mul) mk_lang_noexcept
{
	mk_lang_types_uchar_t cc[8] mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint64_base_t mull mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(x);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(a != x);
	mk_lang_assert(b != c);
	mk_lang_assert(b != x);
	mk_lang_assert(c != x);

	mk_sl_cui_uint64_xor2(c, x);
	mk_sl_cui_uint64_to_buis_uchar_le(c, cc);
	mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_tiger_base_table[0 * 256 + cc[0]], &s_mk_lib_crypto_hash_block_tiger_base_table[1 * 256 + cc[2]], &ta);
	mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_tiger_base_table[2 * 256 + cc[4]], &s_mk_lib_crypto_hash_block_tiger_base_table[3 * 256 + cc[6]], &tb);
	mk_sl_cui_uint64_xor2(&ta, &tb);
	mk_sl_cui_uint64_sub2_wrap_cid_cod(a, &ta);
	mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_tiger_base_table[3 * 256 + cc[1]], &s_mk_lib_crypto_hash_block_tiger_base_table[2 * 256 + cc[3]], &ta);
	mk_sl_cui_uint64_xor3(&s_mk_lib_crypto_hash_block_tiger_base_table[1 * 256 + cc[5]], &s_mk_lib_crypto_hash_block_tiger_base_table[0 * 256 + cc[7]], &tb);
	mk_sl_cui_uint64_xor2(&ta, &tb);
	mk_sl_cui_uint64_add2_wrap_cid_cod(b, &ta);
	mull = mul;
	mk_sl_cui_uint64_mul3_wrap_lo_smol(b, &mull, b);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_hash_block_tiger_base_pass(mk_sl_cui_uint64_prt const a, mk_sl_cui_uint64_prt const b, mk_sl_cui_uint64_prt const c, mk_lib_crypto_hash_block_tiger_base_block_pct const block, int const mul) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);
	mk_lang_assert(block);

	mk_lib_crypto_hash_block_tiger_base_round(a, b, c, &block->m_uint64s[0], mul);
	mk_lib_crypto_hash_block_tiger_base_round(b, c, a, &block->m_uint64s[1], mul);
	mk_lib_crypto_hash_block_tiger_base_round(c, a, b, &block->m_uint64s[2], mul);
	mk_lib_crypto_hash_block_tiger_base_round(a, b, c, &block->m_uint64s[3], mul);
	mk_lib_crypto_hash_block_tiger_base_round(b, c, a, &block->m_uint64s[4], mul);
	mk_lib_crypto_hash_block_tiger_base_round(c, a, b, &block->m_uint64s[5], mul);
	mk_lib_crypto_hash_block_tiger_base_round(a, b, c, &block->m_uint64s[6], mul);
	mk_lib_crypto_hash_block_tiger_base_round(b, c, a, &block->m_uint64s[7], mul);
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger_base_init(mk_lib_crypto_hash_block_tiger_base_pt const tiger_base) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint64_t const s_init_a = mk_sl_cui_uint64_c(0x01234567ul, 0x89abcdeful);
	mk_lang_constexpr_static mk_sl_cui_uint64_t const s_init_b = mk_sl_cui_uint64_c(0xfedcba98ul, 0x76543210ul);
	mk_lang_constexpr_static mk_sl_cui_uint64_t const s_init_c = mk_sl_cui_uint64_c(0xf096a5b4ul, 0xc3b2e187ul);

	mk_lang_static_assert(sizeof(mk_sl_cui_uint8_t) == 1);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_tiger_base_block_t) == 64);
	mk_lang_static_assert(sizeof(mk_lib_crypto_hash_block_tiger_base_digest_t) >= 24);

	mk_lang_assert(tiger_base);

	tiger_base->m_a = s_init_a;
	tiger_base->m_b = s_init_b;
	tiger_base->m_c = s_init_c;
	mk_sl_cui_uint64_set_zero(&tiger_base->m_len);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger_base_append_blocks(mk_lib_crypto_hash_block_tiger_base_pt const tiger_base, mk_lib_crypto_hash_block_tiger_base_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t a mk_lang_constexpr_init;
	mk_sl_cui_uint64_t b mk_lang_constexpr_init;
	mk_sl_cui_uint64_t c mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_tiger_base_block_t block mk_lang_constexpr_init;
	mk_sl_cui_uint64_t aa mk_lang_constexpr_init;
	mk_sl_cui_uint64_t bb mk_lang_constexpr_init;
	mk_sl_cui_uint64_t cc mk_lang_constexpr_init;

	mk_lang_assert(tiger_base);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_tiger_base_block_len);

	mk_sl_cui_uint64_from_bi_usize(&ta, &nblocks);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&tiger_base->m_len, &ta));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&tiger_base->m_len, &ta);
	a = tiger_base->m_a;
	b = tiger_base->m_b;
	c = tiger_base->m_c;
	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		for(i = 0; i != 8; ++i){ mk_sl_uint_64_from_8_le(&block.m_uint64s[i], &pblocks[iblock].m_uint8s[i * 8]); }
		aa = a;
		bb = b;
		cc = c;
		mk_lib_crypto_hash_block_tiger_base_pass(&a, &b, &c, &block, 5);
		mk_lib_crypto_hash_block_tiger_base_key_schedule(&block);
		mk_lib_crypto_hash_block_tiger_base_pass(&c, &a, &b, &block, 7);
		mk_lib_crypto_hash_block_tiger_base_key_schedule(&block);
		mk_lib_crypto_hash_block_tiger_base_pass(&b, &c, &a, &block, 9);
		mk_sl_cui_uint64_xor2(&a, &aa);
		mk_sl_cui_uint64_sub2_wrap_cid_cod(&b, &bb);
		mk_sl_cui_uint64_add2_wrap_cid_cod(&c, &cc);
	}
	tiger_base->m_a = a;
	tiger_base->m_b = b;
	tiger_base->m_c = c;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_block_tiger_base_finish(mk_lib_crypto_hash_block_tiger_base_pt const tiger_base, mk_lang_types_bool_t const variant, mk_lib_crypto_hash_block_tiger_base_block_pt const block, int const idx, mk_lib_crypto_hash_block_tiger_base_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_tiger_base_block_t blok mk_lang_constexpr_init;
	unsigned ui mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	int rest mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(tiger_base);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_tiger_base_block_len);
	mk_lang_assert(digest);

	blok = *block;
	ui = mk_lib_crypto_hash_block_tiger_base_block_len;
	mk_sl_cui_uint64_from_bi_uint(&ta, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&tiger_base->m_len, &ta));
	mk_sl_cui_uint64_shl3(&tiger_base->m_len, 6, &ta);
	mk_sl_cui_uint64_from_bi_sint(&tb, &idx);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&ta, &tb));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&ta, &tb);
	ui = 8;
	mk_sl_cui_uint64_from_bi_uint(&tb, &ui);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_mul(&ta, &tb));
	mk_sl_cui_uint64_shl2(&ta, 3);
	ui = variant ? 0x80 : 0x01;
	mk_sl_cui_uint8_from_bi_uint(&blok.m_uint8s[idx], &ui);
	rest = mk_lib_crypto_hash_block_tiger_base_block_len - idx - 1;
	if(rest >= 8)
	{
		for(i = 0; i != rest - 8; ++i)
		{
			mk_sl_cui_uint8_set_zero(&blok.m_uint8s[idx + 1 + i]);
		}
	}
	else
	{
		for(i = 0; i != rest; ++i)
		{
			mk_sl_cui_uint8_set_zero(&blok.m_uint8s[idx + 1 + i]);
		}
		mk_lib_crypto_hash_block_tiger_base_append_blocks(tiger_base, &blok, 1);
		for(i = 0; i != mk_lib_crypto_hash_block_tiger_base_block_len - 8; ++i)
		{
			mk_sl_cui_uint8_set_zero(&blok.m_uint8s[i]);
		}
	}
	mk_sl_uint_64_to_8_le(&ta, &blok.m_uint8s[mk_lib_crypto_hash_block_tiger_base_block_len - 8]);
	mk_lib_crypto_hash_block_tiger_base_append_blocks(tiger_base, &blok, 1);
	mk_sl_uint_64_to_8_le(&tiger_base->m_a, &digest->m_uint8s[0 * 8]);
	mk_sl_uint_64_to_8_le(&tiger_base->m_b, &digest->m_uint8s[1 * 8]);
	mk_sl_uint_64_to_8_le(&tiger_base->m_c, &digest->m_uint8s[2 * 8]);
}
