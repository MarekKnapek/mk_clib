define(`mk_lib_iip_cp_message_create_session_strings_pr_nl', `
')dnl
define(`mk_lib_iip_cp_message_create_session_strings_per_string_beg', `define(`mm_x', ``$1'')`'mm_x(`$2', `$3', `$4', `$5')`'mk_lib_iip_cp_message_create_session_strings_pr_nl`'undefine(`mm_x')')dnl
define(`mk_lib_iip_cp_message_create_session_strings_per_string_main', `define(`mm_x', ``$1'')`'mm_x(`$2', `$3', `$4', `$5', `$6', `$7')`'mk_lib_iip_cp_message_create_session_strings_pr_nl`'undefine(`mm_x')')dnl
define(`mk_lib_iip_cp_message_create_session_strings_per_string_end', `define(`mm_x', ``$1'')`'mm_x(`$2', `$3', `$4', `$5')`'mk_lib_iip_cp_message_create_session_strings_pr_nl`'undefine(`mm_x')')dnl
define(`mk_lib_iip_cp_message_create_session_strings_per_string_mid', `ifelse(eval(`$# > 3+3*2'), `1', `mk_lib_iip_cp_message_create_session_strings_per_string_main(`$2', `$6', `$7', `$4', `$5', `$8', `$9')`'$0(`$1', `$2', `$3', shift(shift(shift(shift(shift($@))))))', `mk_lib_iip_cp_message_create_session_strings_per_string_end(`$3', `$6', `$7', `$4', `$5')')')dnl
define(`mk_lib_iip_cp_message_create_session_strings_per_string_impl_main', `mk_lib_iip_cp_message_create_session_strings_per_string_beg(`$1', `$4', `$5', `$6', `$7')`'mk_lib_iip_cp_message_create_session_strings_per_string_mid($@)')dnl
define(`mk_lib_iip_cp_message_create_session_strings_per_string_impl_check_end', `ifelse(`$3', `', `mk_lib_iip_cp_message_create_session_strings_per_string_impl_main(`$1', `$2', `$2', shift(shift(shift($@))))', `mk_lib_iip_cp_message_create_session_strings_per_string_impl_main($@)')')dnl
define(`mk_lib_iip_cp_message_create_session_strings_per_string_impl_check_beg', `ifelse(`$1', `', `mk_lib_iip_cp_message_create_session_strings_per_string_impl_check_end(`$2', `$2', shift(shift($@)))', `mk_lib_iip_cp_message_create_session_strings_per_string_impl_check_end($@)')')dnl
define(`mk_lib_iip_cp_message_create_session_strings_per_string', `mk_lib_iip_cp_message_create_session_strings_per_string_impl_check_beg(`$1', `$2', `$3',
`client_message_timeout', `clientMessageTimeout',
`crypto_low_tag_threshold', `crypto.lowTagThreshold',
`crypto_ratchet_inbound_tags', `crypto.ratchet.inboundTags',
`crypto_ratchet_outbound_tags', `crypto.ratchet.outboundTags',
`crypto_tags_to_send', `crypto.tagsToSend',
`explicit_peers', `explicitPeers',
`i2cp_dont_publish_lease_set', `i2cp.dontPublishLeaseSet',
`i2cp_fast_receive', `i2cp.fastReceive',
`i2cp_lease_set_auth_type', `i2cp.leaseSetAuthType',
`i2cp_lease_set_enc_type', `i2cp.leaseSetEncType',
`i2cp_lease_set_offline_expiration', `i2cp.leaseSetOfflineExpiration',
`i2cp_lease_set_offline_signature', `i2cp.leaseSetOfflineSignature',
`i2cp_lease_set_priv_key', `i2cp.leaseSetPrivKey',
`i2cp_lease_set_secret', `i2cp.leaseSetSecret',
`i2cp_lease_set_transient_public_key', `i2cp.leaseSetTransientPublicKey',
`i2cp_lease_set_type', `i2cp.leaseSetType',
`i2cp_message_reliability', `i2cp.messageReliability',
`i2cp_password', `i2cp.password',
`i2cp_username', `i2cp.username',
`inbound_allow_zero_hop', `inbound.allowZeroHop',
`inbound_backup_quantity', `inbound.backupQuantity',
`inbound_ip_restriction', `inbound.IPRestriction',
`inbound_length', `inbound.length',
`inbound_length_variance', `inbound.lengthVariance',
`inbound_nickname', `inbound.nickname',
`inbound_quantity', `inbound.quantity',
`inbound_random_key', `inbound.randomKey',
`outbound_allow_zero_hop', `outbound.allowZeroHop',
`outbound_backup_quantity', `outbound.backupQuantity',
`outbound_ip_restriction', `outbound.IPRestriction',
`outbound_length', `outbound.length',
`outbound_length_variance', `outbound.lengthVariance',
`outbound_nickname', `outbound.nickname',
`outbound_priority', `outbound.priority',
`outbound_quantity', `outbound.quantity',
`outbound_random_key', `outbound.randomKey',
`should_bundle_reply_info', `shouldBundleReplyInfo',
dnl
`false', `false',
`true', `true',
`best_effort', `BestEffort',
`none', `None',
`', `')')dnl
