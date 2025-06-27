#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


#include "mk_sl_list_dbl_inl_defd.h"


mk_lang_forward(mk_sl_list_dbl_inl_defd_node);


typedef mk_sl_list_dbl_inl_defd_element_type mk_sl_list_dbl_inl_defd_element_t;
mk_lang_typedef(mk_sl_list_dbl_inl_defd_element);

struct mk_sl_list_dbl_inl_defd_s
{
	mk_sl_list_dbl_inl_defd_node_pt m_front;
	mk_sl_list_dbl_inl_defd_node_pt m_back;
};
typedef struct mk_sl_list_dbl_inl_defd_s mk_sl_list_dbl_inl_defd_t;
mk_lang_typedef(mk_sl_list_dbl_inl_defd);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_construct(mk_sl_list_dbl_inl_defd_pt const list) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_destroy(mk_sl_list_dbl_inl_defd_pt const list) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_list_dbl_inl_defd_rw_is_empty(mk_sl_list_dbl_inl_defd_pt const list) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_push_back_copy(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pct const element) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_push_back_move(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pt const element) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_pop_front_copy(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pt const element) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_pop_front_move(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pt const element) mk_lang_noexcept;


#include "mk_sl_list_dbl_inl_defu.h"
