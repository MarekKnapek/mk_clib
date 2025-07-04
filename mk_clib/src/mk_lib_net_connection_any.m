define(`mk_lib_net_connection_any_mm_per_type_c', `define(`mm_x', ``$1'')mm_x(`$2', `$4')undefine(`mm_x')')dnl
define(`mk_lib_net_connection_any_mm_per_type_b', `mk_lib_net_connection_any_mm_per_type_c(`$1', `$4', `$2', eval($3 - $# + 1))ifelse(`$#', `5', `', ``$2'`'mk_lib_net_connection_any_mm_per_type_b(`$1', `$2', `$3', shift(shift(shift(shift($@)))))')')dnl
define(`mk_lib_net_connection_any_mm_per_type_a', `mk_lib_net_connection_any_mm_per_type_b(`$1', `$2', `$#', shift(shift($@)))')dnl
define(`mk_lib_net_connection_any_mm_per_type', `mk_lib_net_connection_any_mm_per_type_a(`$1', `$2',
`mk_lib_iip_cp_client_connection_task',
`')')dnl
