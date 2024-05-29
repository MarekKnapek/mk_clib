#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lib_crypto_alg_twofish_base_t_name) && \
	(defined mk_lib_crypto_alg_twofish_base_t_keylen && ((mk_lib_crypto_alg_twofish_base_t_keylen) == 128 || (mk_lib_crypto_alg_twofish_base_t_keylen) == 192 || (mk_lib_crypto_alg_twofish_base_t_keylen) == 256)) && \
	1 \
))
#error xxxxxxxxxx
#endif

#define mk_lib_crypto_alg_twofish_base_inl_defd_name mk_lib_crypto_alg_twofish_base_t_name
#define mk_lib_crypto_alg_twofish_base_inl_defd_keylen (mk_lib_crypto_alg_twofish_base_t_keylen)


#define mk_lib_crypto_alg_twofish_base_inl_defd_key_len_m          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _key_len_m         )
#define mk_lib_crypto_alg_twofish_base_inl_defd_key_len_e          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _key_len_e         )
#define mk_lib_crypto_alg_twofish_base_inl_defd_key_len_v          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _key_len_v         )

#define mk_lib_crypto_alg_twofish_base_inl_defd_msg_len_m          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _msg_len_m         )
#define mk_lib_crypto_alg_twofish_base_inl_defd_msg_len_e          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _msg_len_e         )
#define mk_lib_crypto_alg_twofish_base_inl_defd_msg_len_v          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _msg_len_v         )

#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_len_m     mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_len_m    )
#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_len_e     mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_len_e    )
#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_len_v     mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_len_v    )

#define mk_lib_crypto_alg_twofish_base_inl_defd_nr                 mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _nr                )
#define mk_lib_crypto_alg_twofish_base_inl_defd_rks_s              mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _rks_s             )
#define mk_lib_crypto_alg_twofish_base_inl_defd_rks_t              mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _rks_t             )
#define mk_lib_crypto_alg_twofish_base_inl_defd_sbox_s             mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _sbox_s            )
#define mk_lib_crypto_alg_twofish_base_inl_defd_sbox_t             mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _sbox_t            )
#define mk_lib_crypto_alg_twofish_base_inl_defd_sboxs_s            mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _sboxs_s           )
#define mk_lib_crypto_alg_twofish_base_inl_defd_sboxs_t            mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _sboxs_t           )
#define mk_lib_crypto_alg_twofish_base_inl_defd_rks_sboxs_s        mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _rks_sboxs_s       )
#define mk_lib_crypto_alg_twofish_base_inl_defd_rks_sboxs_t        mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _rks_sboxs_t       )

#define mk_lib_crypto_alg_twofish_base_inl_defd_key_data_u         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _key_data_u        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_key_data_t         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _key_data_t        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_key_s              mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _key_s             )
#define mk_lib_crypto_alg_twofish_base_inl_defd_key_t              mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _key_t             )
#define mk_lib_crypto_alg_twofish_base_inl_defd_key_ct             mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _key_ct            )
#define mk_lib_crypto_alg_twofish_base_inl_defd_key_pt             mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _key_pt            )
#define mk_lib_crypto_alg_twofish_base_inl_defd_key_pct            mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _key_pct           )

#define mk_lib_crypto_alg_twofish_base_inl_defd_msg_data_u         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _msg_data_u        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_msg_data_t         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _msg_data_t        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_msg_s              mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _msg_s             )
#define mk_lib_crypto_alg_twofish_base_inl_defd_msg_t              mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _msg_t             )
#define mk_lib_crypto_alg_twofish_base_inl_defd_msg_ct             mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _msg_ct            )
#define mk_lib_crypto_alg_twofish_base_inl_defd_msg_pt             mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _msg_pt            )
#define mk_lib_crypto_alg_twofish_base_inl_defd_msg_pct            mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _msg_pct           )

#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_data_u    mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_data_u   )
#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_data_t    mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_data_t   )
#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_s         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_s        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_t         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_t        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_ct        mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_ct       )
#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pt        mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_pt       )
#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pct       mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_pct      )

#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_encrypt   mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_encrypt  )
#define mk_lib_crypto_alg_twofish_base_inl_defd_schedule_decrypt   mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _schedule_decrypt  )
#define mk_lib_crypto_alg_twofish_base_inl_defd_expand_enc         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _expand_enc        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_expand_dec         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _expand_dec        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_encrypt            mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _encrypt           )
#define mk_lib_crypto_alg_twofish_base_inl_defd_decrypt            mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _decrypt           )

#define mk_lib_crypto_alg_twofish_base_inl_defd_uint328_data_u     mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _uint328_data_u    )
#define mk_lib_crypto_alg_twofish_base_inl_defd_uint328_data_t     mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _uint328_data_t    )
#define mk_lib_crypto_alg_twofish_base_inl_defd_uint328_s          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _uint328_s         )
#define mk_lib_crypto_alg_twofish_base_inl_defd_uint328_t          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _uint328_t         )

#define mk_lib_crypto_alg_twofish_base_inl_defd_table_q_data_u     mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_q_data_u    )
#define mk_lib_crypto_alg_twofish_base_inl_defd_table_q_data_t     mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_q_data_t    )
#define mk_lib_crypto_alg_twofish_base_inl_defd_table_q_s          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_q_s         )
#define mk_lib_crypto_alg_twofish_base_inl_defd_table_q_t          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_q_t         )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_data_s    mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_q_data_s   )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_data_t    mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_q_data_t   )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_s         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_q_s        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_t         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_q_t        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_q           mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_q          )

#define mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_data_u  mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_mdsq_data_u )
#define mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_data_t  mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_mdsq_data_t )
#define mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_s       mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_mdsq_s      )
#define mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_t       mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_mdsq_t      )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_data_s mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_mdsq_data_s)
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_data_t mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_mdsq_data_t)
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_s      mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_mdsq_s     )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_t      mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_mdsq_t     )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq        mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_mdsq       )

#define mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_data_u    mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_rs_data_u   )
#define mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_data_t    mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_rs_data_t   )
#define mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_s         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_rs_s        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_t         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _table_rs_t        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_data_s   mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_rs_data_s  )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_data_t   mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_rs_data_t  )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_s        mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_rs_s       )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_t        mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_rs_t       )
#define mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _tables_rs         )

#define mk_lib_crypto_alg_twofish_base_inl_defd_rnd_t              mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _rnd_t             )
#define mk_lib_crypto_alg_twofish_base_inl_defd_rnd_enc_a          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _rnd_enc_a         )
#define mk_lib_crypto_alg_twofish_base_inl_defd_rnd_enc_b          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _rnd_enc_b         )
#define mk_lib_crypto_alg_twofish_base_inl_defd_rnd_dec_a          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _rnd_dec_a         )
#define mk_lib_crypto_alg_twofish_base_inl_defd_rnd_dec_b          mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _rnd_dec_b         )
#define mk_lib_crypto_alg_twofish_base_inl_defd_one_enc            mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _one_enc           )
#define mk_lib_crypto_alg_twofish_base_inl_defd_one_dec            mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _one_dec           )
#define mk_lib_crypto_alg_twofish_base_inl_defd_expand_128         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _expand_128        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_expand_192         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _expand_192        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_expand_256         mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _expand_256        )
#define mk_lib_crypto_alg_twofish_base_inl_defd_expand             mk_lang_concat(mk_lib_crypto_alg_twofish_base_inl_defd_name, _expand            )
