/* File automatically generated by genmdesc.py, don't change */

const char mono_arm64_cpu_desc [] = {
	"\x0\x0\x0\x0\x0\x0"	/* null entry */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* nop */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* relaxed_nop */
	"\x0" "ii\x0" "\x4" "\x0" ""	/* compare */
	"\x0" "i\x0" "\x0" "\x14" "\x0" ""	/* compare_imm */
	"\x0" "ff\x0" "\xc" "\x0" ""	/* fcompare */
	"\x0" "ff\x0" "\xc" "\x0" ""	/* rcompare */
	"\x0" "ii\x0" "\x4" "\x0" ""	/* lcompare */
	"\x0" "ii\x0" "\x4" "\x0" ""	/* icompare */
	"\x0" "i\x0" "\x0" "\xc" "\x0" ""	/* icompare_imm */
	"\x0" "i\x0" "\x0" "\x14" "\x0" ""	/* lcompare_imm */
	"\x0" "f\x0" "\x0" "\xc" "\x0" ""	/* setfret */
	"\x0" "ii\x0" "\xc" "\x0" ""	/* setlret */
	"ii\x0" "\x0" "\x60" "\x0" ""	/* localloc */
	"i\x0" "\x0" "\x0" "\x40" "\x0" ""	/* localloc_imm */
	"\x0" "b\x0" "\x0" "\x4" "\x0" ""	/* checkthis */
	"\x0" "\x0" "\x0" "\x0" "\x28" "c"	/* seq_point */
	"\x0" "\x0" "\x0" "\x0" "\x0" "\x0" ""	/* il_seq_point */
	"\x0" "\x0" "\x0" "\x0" "\x20" "c"	/* voidcall */
	"\x0" "i\x0" "\x0" "\x20" "c"	/* voidcall_reg */
	"\x0" "b\x0" "\x0" "\x20" "c"	/* voidcall_membase */
	"a\x0" "\x0" "\x0" "\x20" "c"	/* call */
	"ai\x0" "\x0" "\x20" "c"	/* call_reg */
	"ab\x0" "\x0" "\x20" "c"	/* call_membase */
	"f\x0" "\x0" "\x0" "\x20" "c"	/* fcall */
	"fi\x0" "\x0" "\x20" "c"	/* fcall_reg */
	"fb\x0" "\x0" "\x20" "c"	/* fcall_membase */
	"f\x0" "\x0" "\x0" "\x20" "c"	/* rcall */
	"fi\x0" "\x0" "\x20" "c"	/* rcall_reg */
	"fb\x0" "\x0" "\x20" "c"	/* rcall_membase */
	"l\x0" "\x0" "\x0" "\x20" "c"	/* lcall */
	"li\x0" "\x0" "\x20" "c"	/* lcall_reg */
	"lb\x0" "\x0" "\x20" "c"	/* lcall_membase */
	"\x0" "\x0" "\x0" "\x0" "\x20" "c"	/* vcall */
	"\x0" "i\x0" "\x0" "\x20" "c"	/* vcall_reg */
	"\x0" "b\x0" "\x0" "\x20" "c"	/* vcall_membase */
	"\x0" "\x0" "\x0" "\x0" "\x28" "c"	/* vcall2 */
	"\x0" "i\x0" "\x0" "\x28" "c"	/* vcall2_reg */
	"\x0" "b\x0" "\x0" "\x28" "c"	/* vcall2_membase */
	"\x0" "ii\x0" "\xd8" "c"	/* dyn_call */
	"i\x0" "\x0" "\x0" "\x10" "\x0" ""	/* iconst */
	"i\x0" "\x0" "\x0" "\x10" "\x0" ""	/* i8const */
	"f\x0" "\x0" "\x0" "\x18" "\x0" ""	/* r4const */
	"f\x0" "\x0" "\x0" "\x14" "\x0" ""	/* r8const */
	"i\x0" "\x0" "\x0" "\x0" "\x0" ""	/* dummy_iconst */
	"i\x0" "\x0" "\x0" "\x0" "\x0" ""	/* dummy_i8const */
	"f\x0" "\x0" "\x0" "\x0" "\x0" ""	/* dummy_r8const */
	"f\x0" "\x0" "\x0" "\x0" "\x0" ""	/* dummy_r4const */
	"\x0" "\x0" "\x0" "\x0" "\x0" "\x0" ""	/* label */
	"\x0" "i\x0" "\x0" "\xc" "\x0" ""	/* switch */
	"\x0" "i\x0" "\x0" "\x18" "\x0" ""	/* throw */
	"\x0" "i\x0" "\x0" "\x14" "\x0" ""	/* rethrow */
	"\x0" "i\x0" "\x0" "\xc" "\x0" ""	/* oparglist */
	"bi\x0" "\x0" "\x14" "\x0" ""	/* store_membase_reg */
	"bi\x0" "\x0" "\xc" "\x0" ""	/* storei1_membase_reg */
	"bi\x0" "\x0" "\xc" "\x0" ""	/* storei2_membase_reg */
	"bi\x0" "\x0" "\x14" "\x0" ""	/* storei4_membase_reg */
	"bi\x0" "\x0" "\xc" "\x0" ""	/* storei8_membase_reg */
	"bf\x0" "\x0" "\x14" "\x0" ""	/* storer4_membase_reg */
	"bf\x0" "\x0" "\x18" "\x0" ""	/* storer8_membase_reg */
	"b\x0" "\x0" "\x0" "\x14" "\x0" ""	/* store_membase_imm */
	"b\x0" "\x0" "\x0" "\x14" "\x0" ""	/* storei1_membase_imm */
	"b\x0" "\x0" "\x0" "\x14" "\x0" ""	/* storei2_membase_imm */
	"b\x0" "\x0" "\x0" "\x14" "\x0" ""	/* storei4_membase_imm */
	"b\x0" "\x0" "\x0" "\x14" "\x0" ""	/* storei8_membase_imm */
	"ib\x0" "\x0" "\x14" "\x0" ""	/* load_membase */
	"ib\x0" "\x0" "\x20" "\x0" ""	/* loadi1_membase */
	"ib\x0" "\x0" "\x20" "\x0" ""	/* loadu1_membase */
	"ib\x0" "\x0" "\x20" "\x0" ""	/* loadi2_membase */
	"ib\x0" "\x0" "\x20" "\x0" ""	/* loadu2_membase */
	"ib\x0" "\x0" "\x20" "\x0" ""	/* loadi4_membase */
	"ib\x0" "\x0" "\x20" "\x0" ""	/* loadu4_membase */
	"ib\x0" "\x0" "\xc" "\x0" ""	/* loadi8_membase */
	"fb\x0" "\x0" "\x20" "\x0" ""	/* loadr4_membase */
	"fb\x0" "\x0" "\x20" "\x0" ""	/* loadr8_membase */
	"ibi\x0" "\x4" "\x0" ""	/* load_memindex */
	"ibi\x0" "\x4" "\x0" ""	/* loadi1_memindex */
	"ibi\x0" "\x4" "\x0" ""	/* loadu1_memindex */
	"ibi\x0" "\x4" "\x0" ""	/* loadi2_memindex */
	"ibi\x0" "\x4" "\x0" ""	/* loadu2_memindex */
	"ibi\x0" "\x4" "\x0" ""	/* loadi4_memindex */
	"ibi\x0" "\x4" "\x0" ""	/* loadu4_memindex */
	"bii\x0" "\x4" "\x0" ""	/* store_memindex */
	"bii\x0" "\x4" "\x0" ""	/* storei1_memindex */
	"bii\x0" "\x4" "\x0" ""	/* storei2_memindex */
	"bii\x0" "\x4" "\x0" ""	/* storei4_memindex */
	"i\x0" "\x0" "\x0" "\x8" "\x0" ""	/* loadu4_mem */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* move */
	"ff\x0" "\x0" "\x4" "\x0" ""	/* fmove */
	"ff\x0" "\x0" "\x4" "\x0" ""	/* rmove */
	"if\x0" "\x0" "\x8" "\x0" ""	/* move_f_to_i4 */
	"fi\x0" "\x0" "\x8" "\x0" ""	/* move_i4_to_f */
	"if\x0" "\x0" "\x4" "\x0" ""	/* move_f_to_i8 */
	"fi\x0" "\x0" "\x4" "\x0" ""	/* move_i8_to_f */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* add_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* sub_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* mul_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* and_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* or_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* xor_imm */
	"ii\x0" "\x0" "\x8" "\x0" ""	/* shl_imm */
	"ii\x0" "\x0" "\x8" "\x0" ""	/* shr_imm */
	"ii\x0" "\x0" "\x8" "\x0" ""	/* shr_un_imm */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* br */
	"\x0" "\x0" "\x0" "\x0" "\xff" "c"	/* tailcall */
	"\x0" "\x0" "\x0" "\x0" "\x18" "\x0" ""	/* tailcall_parameter */
	"\x0" "b\x0" "\x0" "\xff" "c"	/* tailcall_reg */
	"\x0" "b\x0" "\x0" "\xff" "c"	/* tailcall_membase */
	"\x0" "\x0" "\x0" "\x0" "\x14" "\x0" ""	/* break */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* ceq */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* cgt */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* cgt.un */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* clt */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* clt.un */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_eq */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_ge */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_gt */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_le */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_lt */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_ne_un */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_ge_un */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_gt_un */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_le_un */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_lt_un */
	"\x0" "\x0" "\x0" "\x0" "\xc" "\x0" ""	/* cond_exc_ov */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_no */
	"\x0" "\x0" "\x0" "\x0" "\xc" "\x0" ""	/* cond_exc_c */
	"\x0" "\x0" "\x0" "\x0" "\x8" "\x0" ""	/* cond_exc_nc */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_ieq */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_ige */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_igt */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_ile */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_ilt */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_ine_un */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_ige_un */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_igt_un */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_ile_un */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_ilt_un */
	"\x0" "\x0" "\x0" "\x0" "\x14" "\x0" ""	/* cond_exc_iov */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_ino */
	"\x0" "\x0" "\x0" "\x0" "\x14" "\x0" ""	/* cond_exc_ic */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* cond_exc_inc */
	"iii\x0" "\x4" "\x0" ""	/* long_add */
	"iii\x0" "\x4" "\x0" ""	/* long_sub */
	"iii\x0" "\x4" "\x0" ""	/* long_mul */
	"iii\x0" "P\x0" ""	/* long_div */
	"iii\x0" "\x40" "\x0" ""	/* long_div_un */
	"iii\x0" "P\x0" ""	/* long_rem */
	"iii\x0" "\x40" "\x0" ""	/* long_rem_un */
	"iii\x0" "\x4" "\x0" ""	/* long_and */
	"iii\x0" "\x4" "\x0" ""	/* long_or */
	"iii\x0" "\x4" "\x0" ""	/* long_xor */
	"iii\x0" "\x4" "\x0" ""	/* long_shl */
	"iii\x0" "\x4" "\x0" ""	/* long_shr */
	"iii\x0" "\x4" "\x0" ""	/* long_shr_un */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* long_neg */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* long_not */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* long_conv_to_i1 */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* long_conv_to_i2 */
	"fi\x0" "\x0" "\xc" "\x0" ""	/* long_conv_to_r4 */
	"fi\x0" "\x0" "\x8" "\x0" ""	/* long_conv_to_r8 */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* long_conv_to_u2 */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* long_conv_to_u1 */
	"iii\x0" "\x10" "\x0" ""	/* long_add_ovf */
	"iii\x0" "\x10" "\x0" ""	/* long_add_ovf_un */
	"iii\x0" "\x10" "\x0" ""	/* long_mul_ovf */
	"iii\x0" "\x10" "\x0" ""	/* long_mul_ovf_un */
	"iii\x0" "\x10" "\x0" ""	/* long_sub_ovf */
	"iii\x0" "\x10" "\x0" ""	/* long_sub_ovf_un */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* long_ceq */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* long_cgt */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* long_cgt_un */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* long_clt */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* long_clt_un */
	"fi\x0" "\x0" "\x8" "\x0" ""	/* long_conv_to_r_un */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* long_add_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* long_sub_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* long_mul_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* long_and_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* long_or_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* long_xor_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* long_shl_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* long_shr_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* long_shr_un_imm */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* long_beq */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* long_bge */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* long_bgt */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* long_ble */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* long_blt */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* long_bne_un */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* long_bge_un */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* long_bgt_un */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* long_ble_un */
	"\x0" "\x0" "\x0" "\x0" "\x4" "\x0" ""	/* long_blt_un */
	"iii\x0" "\x24" "\x0" ""	/* long_conv_to_ovf_i4_2 */
	"iii\x0" "\x4" "\x0" ""	/* int_add */
	"iii\x0" "\x4" "\x0" ""	/* int_sub */
	"iii\x0" "\x4" "\x0" ""	/* int_mul */
	"iii\x0" "H\x0" ""	/* int_div */
	"iii\x0" "H\x0" ""	/* int_div_un */
	"iii\x0" "H\x0" ""	/* int_rem */
	"iii\x0" "H\x0" ""	/* int_rem_un */
	"iii\x0" "\x4" "\x0" ""	/* int_and */
	"iii\x0" "\x4" "\x0" ""	/* int_or */
	"iii\x0" "\x4" "\x0" ""	/* int_xor */
	"iii\x0" "\x4" "\x0" ""	/* int_shl */
	"iii\x0" "\x4" "\x0" ""	/* int_shr */
	"iii\x0" "\x4" "\x0" ""	/* int_shr_un */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* int_neg */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* int_not */
	"ii\x0" "\x0" "\x8" "\x0" ""	/* int_conv_to_i1 */
	"ii\x0" "\x0" "\x8" "\x0" ""	/* int_conv_to_i2 */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* int_conv_to_i4 */
	"fi\x0" "\x0" "\x24" "\x0" ""	/* int_conv_to_r4 */
	"fi\x0" "\x0" "\x24" "\x0" ""	/* int_conv_to_r8 */
	"ii\x0" "\x0" "\x0" "\x0" ""	/* int_conv_to_u4 */
	"fi\x0" "\x0" "8\x0" ""	/* int_conv_to_r_un */
	"ii\x0" "\x0" "\x8" "\x0" ""	/* int_conv_to_u2 */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* int_conv_to_u1 */
	"iii\x0" "\x10" "\x0" ""	/* int_add_ovf */
	"iii\x0" "\x10" "\x0" ""	/* int_add_ovf_un */
	"iii\x0" "\x10" "\x0" ""	/* int_mul_ovf */
	"iii\x0" "\x10" "\x0" ""	/* int_mul_ovf_un */
	"iii\x0" "\x10" "\x0" ""	/* int_sub_ovf */
	"iii\x0" "\x10" "\x0" ""	/* int_sub_ovf_un */
	"iii\x0" "\x4" "\x0" ""	/* int_adc */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* int_adc_imm */
	"iii\x0" "\x4" "\x0" ""	/* int_sbb */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* int_sbb_imm */
	"iii\x0" "\x4" "\x0" ""	/* int_addcc */
	"iii\x0" "\x4" "\x0" ""	/* int_subcc */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* int_add_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* int_sub_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* int_mul_imm */
	"ii\x0" "\x0" "\x14" "\x0" ""	/* int_div_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* int_div_un_imm */
	"ii\x0" "\x0" "\x1c" "\x0" ""	/* int_rem_imm */
	"ii\x0" "\x0" "\x10" "\x0" ""	/* int_rem_un_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* int_and_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* int_or_imm */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* int_xor_imm */
	"ii\x0" "\x0" "\x8" "\x0" ""	/* int_shl_imm */
	"ii\x0" "\x0" "\x8" "\x0" ""	/* int_shr_imm */
	"ii\x0" "\x0" "\x8" "\x0" ""	/* int_shr_un_imm */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* int_ceq */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* int_cgt */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* int_cgt_un */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* int_clt */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* int_clt_un */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* int_cneq */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* int_cge */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* int_cle */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* int_cge_un */
	"i\x0" "\x0" "\x0" "\xc" "\x0" ""	/* int_cle_un */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* int_beq */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* int_bge */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* int_bgt */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* int_ble */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* int_blt */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* int_bne_un */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* int_bge_un */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* int_bgt_un */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* int_ble_un */
	"\x0" "\x0" "\x0" "\x0" "\x10" "\x0" ""	/* int_blt_un */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* float_beq */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* float_bge */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* float_bgt */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* float_ble */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* float_blt */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* float_bne_un */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* float_bge_un */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* float_bgt_un */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* float_ble_un */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* float_blt_un */
	"fff\x0" "\x4" "\x0" ""	/* float_add */
	"fff\x0" "\x4" "\x0" ""	/* float_sub */
	"fff\x0" "\x4" "\x0" ""	/* float_mul */
	"fff\x0" "\x4" "\x0" ""	/* float_div */
	"fff\x0" "\x4" "\x0" ""	/* float_div_un */
	"fff\x0" "\x10" "\x0" ""	/* float_rem */
	"fff\x0" "\x10" "\x0" ""	/* float_rem_un */
	"fff\x0" "\x4" "\x0" ""	/* r4_add */
	"fff\x0" "\x4" "\x0" ""	/* r4_sub */
	"fff\x0" "\x4" "\x0" ""	/* r4_mul */
	"fff\x0" "\x4" "\x0" ""	/* r4_div */
	"fff\x0" "\x10" "\x0" ""	/* r4_rem */
	"ff\x0" "\x0" "\x4" "\x0" ""	/* float_neg */
	"ff\x0" "\x0" "\x4" "\x0" ""	/* float_not */
	"if\x0" "\x0" "\x28" "\x0" ""	/* float_conv_to_i1 */
	"if\x0" "\x0" "\x28" "\x0" ""	/* float_conv_to_i2 */
	"if\x0" "\x0" "\x28" "\x0" ""	/* float_conv_to_i4 */
	"lf\x0" "\x0" "\x28" "\x0" ""	/* float_conv_to_i8 */
	"ff\x0" "\x0" "\x8" "\x0" ""	/* float_conv_to_r4 */
	"if\x0" "\x0" "\x28" "\x0" ""	/* float_conv_to_u4 */
	"lf\x0" "\x0" "\x28" "\x0" ""	/* float_conv_to_u8 */
	"ff\x0" "\x0" "\x4" "\x0" ""	/* r4_neg */
	"if\x0" "\x0" "\x8" "\x0" ""	/* r4_conv_to_i1 */
	"if\x0" "\x0" "\x8" "\x0" ""	/* r4_conv_to_i2 */
	"if\x0" "\x0" "\x8" "\x0" ""	/* r4_conv_to_i4 */
	"lf\x0" "\x0" "\x8" "\x0" ""	/* r4_conv_to_i8 */
	"ff\x0" "\x0" "\x4" "\x0" ""	/* r4_conv_to_r4 */
	"ff\x0" "\x0" "\x4" "\x0" ""	/* r4_conv_to_r8 */
	"if\x0" "\x0" "\x8" "\x0" ""	/* r4_conv_to_u4 */
	"lf\x0" "\x0" "\x8" "\x0" ""	/* r4_conv_to_u8 */
	"if\x0" "\x0" "\x28" "\x0" ""	/* float_conv_to_u2 */
	"if\x0" "\x0" "\x28" "\x0" ""	/* float_conv_to_u1 */
	"if\x0" "\x0" "\x28" "\x0" ""	/* float_conv_to_i */
	"iff\x0" "\x10" "\x0" ""	/* float_ceq */
	"iff\x0" "\x10" "\x0" ""	/* float_cgt */
	"iff\x0" "\x14" "\x0" ""	/* float_cgt_un */
	"iff\x0" "\x10" "\x0" ""	/* float_clt */
	"iff\x0" "\x14" "\x0" ""	/* float_clt_un */
	"iff\x0" "\x14" "\x0" ""	/* float_cneq */
	"iff\x0" "\x14" "\x0" ""	/* float_cge */
	"iff\x0" "\x14" "\x0" ""	/* float_cle */
	"if\x0" "\x0" "\x24" "\x0" ""	/* float_conv_to_u */
	"ff\x0" "\x0" "\x40" "\x0" ""	/* ckfinite */
	"if\x0" "\x0" "\x8" "\x0" ""	/* r4_conv_to_u2 */
	"if\x0" "\x0" "\x8" "\x0" ""	/* r4_conv_to_u1 */
	"iff\x0" "\x10" "\x0" ""	/* r4_ceq */
	"iff\x0" "\x10" "\x0" ""	/* r4_cgt */
	"iff\x0" "\x14" "\x0" ""	/* r4_cgt_un */
	"iff\x0" "\x10" "\x0" ""	/* r4_clt */
	"iff\x0" "\x14" "\x0" ""	/* r4_clt_un */
	"iff\x0" "\x14" "\x0" ""	/* r4_cneq */
	"iff\x0" "\x14" "\x0" ""	/* r4_cge */
	"iff\x0" "\x14" "\x0" ""	/* r4_cle */
	"i\x0" "\x0" "\x0" "\x10" "\x0" ""	/* jump_table */
	"i\x0" "\x0" "\x0" "\x10" "\x0" ""	/* aot_const */
	"\x0" "\x0" "\x0" "\x0" "\x10" "c"	/* call_handler */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* start_handler */
	"\x0" "i\x0" "\x0" "\x20" "\x0" ""	/* endfilter */
	"\x0" "\x0" "\x0" "\x0" "\x20" "\x0" ""	/* endfinally */
	"i\x0" "\x0" "\x0" "\x10" "\x0" ""	/* get_ex_obj */
	"lii\x0" "\x8" "\x0" ""	/* bigmul */
	"lii\x0" "\x8" "\x0" ""	/* bigmul_un */
	"iii\x0" "\x4" "\x0" ""	/* adc */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* adc_imm */
	"iii\x0" "\x4" "\x0" ""	/* sbb */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* sbb_imm */
	"iii\x0" "\x4" "\x0" ""	/* addcc */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* addcc_imm */
	"iii\x0" "\x4" "\x0" ""	/* subcc */
	"ii\x0" "\x0" "\xc" "\x0" ""	/* subcc_imm */
	"\x0" "i\x0" "\x0" "\x8" "\x0" ""	/* br_reg */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* sext_i4 */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* zext_i4 */
	"iii\x0" "\x10" "\x0" ""	/* add_ovf_carry */
	"iii\x0" "\x10" "\x0" ""	/* sub_ovf_carry */
	"iii\x0" "\x10" "\x0" ""	/* add_ovf_un_carry */
	"iii\x0" "\x10" "\x0" ""	/* sub_ovf_un_carry */
	"ff\x0" "\x0" "\x4" "\x0" ""	/* sqrt */
	"i\x0" "\x0" "\x0" "\x20" "\x0" ""	/* tls_get */
	"\x0" "i\x0" "\x0" "\x20" "\x0" ""	/* tls_set */
	"\x0" "i\x0" "\x0" "\x0" "\x0" ""	/* dummy_use */
	"\x0" "\x0" "\x0" "\x0" "\x0" "\x0" ""	/* not_reached */
	"\x0" "i\x0" "\x0" "\x0" "\x0" ""	/* not_null */
	"\x0" "\x0" "\x0" "\x0" "\x8" "a"	/* memory_barrier */
	"ib\x0" "\x0" "\x18" "\x0" ""	/* atomic_load_i1 */
	"ib\x0" "\x0" "\x18" "\x0" ""	/* atomic_load_i2 */
	"ib\x0" "\x0" "\x18" "\x0" ""	/* atomic_load_i4 */
	"ib\x0" "\x0" "\x14" "\x0" ""	/* atomic_load_i8 */
	"ib\x0" "\x0" "\x18" "\x0" ""	/* atomic_load_u1 */
	"ib\x0" "\x0" "\x18" "\x0" ""	/* atomic_load_u2 */
	"ib\x0" "\x0" "\x18" "\x0" ""	/* atomic_load_u4 */
	"ib\x0" "\x0" "\x14" "\x0" ""	/* atomic_load_u8 */
	"fb\x0" "\x0" "\x1c" "\x0" ""	/* atomic_load_r4 */
	"fb\x0" "\x0" "\x18" "\x0" ""	/* atomic_load_r8 */
	"bi\x0" "\x0" "\x14" "\x0" ""	/* atomic_store_i1 */
	"bi\x0" "\x0" "\x14" "\x0" ""	/* atomic_store_i2 */
	"bi\x0" "\x0" "\x14" "\x0" ""	/* atomic_store_i4 */
	"bi\x0" "\x0" "\x14" "\x0" ""	/* atomic_store_i8 */
	"bi\x0" "\x0" "\x14" "\x0" ""	/* atomic_store_u1 */
	"bi\x0" "\x0" "\x14" "\x0" ""	/* atomic_store_u2 */
	"bi\x0" "\x0" "\x14" "\x0" ""	/* atomic_store_u4 */
	"bi\x0" "\x0" "\x14" "\x0" ""	/* atomic_store_u8 */
	"bf\x0" "\x0" "\x1c" "\x0" ""	/* atomic_store_r4 */
	"bf\x0" "\x0" "\x18" "\x0" ""	/* atomic_store_r8 */
	"iii\x0" "\x20" "\x0" ""	/* atomic_add_i4 */
	"iii\x0" "\x20" "\x0" ""	/* atomic_add_i8 */
	"iii\x0" "\x20" "\x0" ""	/* atomic_exchange_i4 */
	"iii\x0" "\x20" "\x0" ""	/* atomic_exchange_i8 */
	"iiii\x20" "\x0" ""	/* atomic_cas_i4 */
	"iiii\x20" "\x0" ""	/* atomic_cas_i8 */
	"\x0" "\x0" "\x0" "\x0" "\x0" "\x0" ""	/* liverange_start */
	"\x0" "\x0" "\x0" "\x0" "\x0" "\x0" ""	/* liverange_end */
	"\x0" "\x0" "\x0" "\x0" "\x0" "\x0" ""	/* gc_liveness_def */
	"\x0" "\x0" "\x0" "\x0" "\x0" "\x0" ""	/* gc_liveness_use */
	"\x0" "\x0" "\x0" "\x0" "\x0" "\x0" ""	/* gc_spill_slot_liveness_def */
	"\x0" "\x0" "\x0" "\x0" "\x0" "\x0" ""	/* gc_param_slot_liveness_def */
	"\x0" "i\x0" "\x0" "\xc" "c"	/* gc_safe_point */
	"\x0" "a\x0" "\x0" "\x2c" "c"	/* generic_class_init */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* arm_rsbs_imm */
	"ii\x0" "\x0" "\x4" "\x0" ""	/* arm_rsc_imm */
	"ff\x0" "\x0" "\x8" "\x0" ""	/* arm_setfreg_r4 */
	"\x0" "i\x0" "\x0" "\x10" "\x0" ""	/* arm64_cbzw */
	"\x0" "i\x0" "\x0" "\x10" "\x0" ""	/* arm64_cbzx */
	"\x0" "i\x0" "\x0" "\x10" "\x0" ""	/* arm64_cbnzw */
	"\x0" "i\x0" "\x0" "\x10" "\x0" ""	/* arm64_cbnzx */
	"i\x0" "\x0" "\x0" "\x20" "\x0" ""	/* objc_get_selector */
	"\x0" "i\x0" "\x0" "\x80" "\x0" ""	/* fill_prof_call_ctx */
};
const guint16 mono_arm64_cpu_desc_idx [] = {
	0,	/* load */
	0,	/* ldaddr */
	0,	/* store */
	6,	/* nop */
	0,	/* hard_nop */
	12,	/* relaxed_nop */
	0,	/* phi */
	0,	/* fphi */
	0,	/* vphi */
	18,	/* compare */
	24,	/* compare_imm */
	30,	/* fcompare */
	36,	/* rcompare */
	42,	/* lcompare */
	48,	/* icompare */
	54,	/* icompare_imm */
	60,	/* lcompare_imm */
	0,	/* local */
	0,	/* arg */
	0,	/* gsharedvt_local */
	0,	/* gsharedvt_arg_regoffset */
	0,	/* outarg_vt */
	0,	/* outarg_vtretaddr */
	0,	/* setret */
	66,	/* setfret */
	72,	/* setlret */
	78,	/* localloc */
	84,	/* localloc_imm */
	90,	/* checkthis */
	96,	/* seq_point */
	102,	/* il_seq_point */
	0,	/* implicit_exception */
	0,	/* box */
	0,	/* box_iconst */
	0,	/* typed_objref */
	108,	/* voidcall */
	114,	/* voidcall_reg */
	120,	/* voidcall_membase */
	126,	/* call */
	132,	/* call_reg */
	138,	/* call_membase */
	144,	/* fcall */
	150,	/* fcall_reg */
	156,	/* fcall_membase */
	162,	/* rcall */
	168,	/* rcall_reg */
	174,	/* rcall_membase */
	180,	/* lcall */
	186,	/* lcall_reg */
	192,	/* lcall_membase */
	198,	/* vcall */
	204,	/* vcall_reg */
	210,	/* vcall_membase */
	216,	/* vcall2 */
	222,	/* vcall2_reg */
	228,	/* vcall2_membase */
	234,	/* dyn_call */
	240,	/* iconst */
	246,	/* i8const */
	252,	/* r4const */
	258,	/* r8const */
	264,	/* dummy_iconst */
	270,	/* dummy_i8const */
	276,	/* dummy_r8const */
	282,	/* dummy_r4const */
	0,	/* dummy_vzero */
	0,	/* regvar */
	0,	/* regoffset */
	0,	/* vtarg_addr */
	288,	/* label */
	294,	/* switch */
	300,	/* throw */
	306,	/* rethrow */
	312,	/* oparglist */
	318,	/* store_membase_reg */
	324,	/* storei1_membase_reg */
	330,	/* storei2_membase_reg */
	336,	/* storei4_membase_reg */
	342,	/* storei8_membase_reg */
	348,	/* storer4_membase_reg */
	354,	/* storer8_membase_reg */
	360,	/* store_membase_imm */
	366,	/* storei1_membase_imm */
	372,	/* storei2_membase_imm */
	378,	/* storei4_membase_imm */
	384,	/* storei8_membase_imm */
	0,	/* storex_membase */
	0,	/* storev_membase */
	390,	/* load_membase */
	396,	/* loadi1_membase */
	402,	/* loadu1_membase */
	408,	/* loadi2_membase */
	414,	/* loadu2_membase */
	420,	/* loadi4_membase */
	426,	/* loadu4_membase */
	432,	/* loadi8_membase */
	438,	/* loadr4_membase */
	444,	/* loadr8_membase */
	0,	/* loadx_membase */
	0,	/* loadv_membase */
	450,	/* load_memindex */
	456,	/* loadi1_memindex */
	462,	/* loadu1_memindex */
	468,	/* loadi2_memindex */
	474,	/* loadu2_memindex */
	480,	/* loadi4_memindex */
	486,	/* loadu4_memindex */
	0,	/* loadi8_memindex */
	0,	/* loadr4_memindex */
	0,	/* loadr8_memindex */
	492,	/* store_memindex */
	498,	/* storei1_memindex */
	504,	/* storei2_memindex */
	510,	/* storei4_memindex */
	0,	/* storei8_memindex */
	0,	/* storer4_memindex */
	0,	/* storer8_memindex */
	0,	/* load_mem */
	0,	/* loadu1_mem */
	0,	/* loadu2_mem */
	0,	/* loadi4_mem */
	516,	/* loadu4_mem */
	0,	/* loadi8_mem */
	0,	/* store_mem_imm */
	522,	/* move */
	0,	/* lmove */
	528,	/* fmove */
	0,	/* vmove */
	534,	/* rmove */
	540,	/* move_f_to_i4 */
	546,	/* move_i4_to_f */
	552,	/* move_f_to_i8 */
	558,	/* move_i8_to_f */
	0,	/* vzero */
	564,	/* add_imm */
	570,	/* sub_imm */
	576,	/* mul_imm */
	0,	/* div_imm */
	0,	/* div_un_imm */
	0,	/* rem_imm */
	0,	/* rem_un_imm */
	582,	/* and_imm */
	588,	/* or_imm */
	594,	/* xor_imm */
	600,	/* shl_imm */
	606,	/* shr_imm */
	612,	/* shr_un_imm */
	618,	/* br */
	624,	/* tailcall */
	630,	/* tailcall_parameter */
	636,	/* tailcall_reg */
	642,	/* tailcall_membase */
	648,	/* break */
	654,	/* ceq */
	660,	/* cgt */
	666,	/* cgt.un */
	672,	/* clt */
	678,	/* clt.un */
	684,	/* cond_exc_eq */
	690,	/* cond_exc_ge */
	696,	/* cond_exc_gt */
	702,	/* cond_exc_le */
	708,	/* cond_exc_lt */
	714,	/* cond_exc_ne_un */
	720,	/* cond_exc_ge_un */
	726,	/* cond_exc_gt_un */
	732,	/* cond_exc_le_un */
	738,	/* cond_exc_lt_un */
	744,	/* cond_exc_ov */
	750,	/* cond_exc_no */
	756,	/* cond_exc_c */
	762,	/* cond_exc_nc */
	768,	/* cond_exc_ieq */
	774,	/* cond_exc_ige */
	780,	/* cond_exc_igt */
	786,	/* cond_exc_ile */
	792,	/* cond_exc_ilt */
	798,	/* cond_exc_ine_un */
	804,	/* cond_exc_ige_un */
	810,	/* cond_exc_igt_un */
	816,	/* cond_exc_ile_un */
	822,	/* cond_exc_ilt_un */
	828,	/* cond_exc_iov */
	834,	/* cond_exc_ino */
	840,	/* cond_exc_ic */
	846,	/* cond_exc_inc */
	852,	/* long_add */
	858,	/* long_sub */
	864,	/* long_mul */
	870,	/* long_div */
	876,	/* long_div_un */
	882,	/* long_rem */
	888,	/* long_rem_un */
	894,	/* long_and */
	900,	/* long_or */
	906,	/* long_xor */
	912,	/* long_shl */
	918,	/* long_shr */
	924,	/* long_shr_un */
	930,	/* long_neg */
	936,	/* long_not */
	942,	/* long_conv_to_i1 */
	948,	/* long_conv_to_i2 */
	0,	/* long_conv_to_i4 */
	0,	/* long_conv_to_i8 */
	954,	/* long_conv_to_r4 */
	960,	/* long_conv_to_r8 */
	0,	/* long_conv_to_u4 */
	0,	/* long_conv_to_u8 */
	966,	/* long_conv_to_u2 */
	972,	/* long_conv_to_u1 */
	0,	/* long_conv_to_i */
	0,	/* long_conv_to_ovf_i */
	0,	/* long_conv_to_ovf_u */
	978,	/* long_add_ovf */
	984,	/* long_add_ovf_un */
	990,	/* long_mul_ovf */
	996,	/* long_mul_ovf_un */
	1002,	/* long_sub_ovf */
	1008,	/* long_sub_ovf_un */
	0,	/* long_conv_to_ovf_i1_un */
	0,	/* long_conv_to_ovf_i2_un */
	0,	/* long_conv_to_ovf_i4_un */
	0,	/* long_conv_to_ovf_i8_un */
	0,	/* long_conv_to_ovf_u1_un */
	0,	/* long_conv_to_ovf_u2_un */
	0,	/* long_conv_to_ovf_u4_un */
	0,	/* long_conv_to_ovf_u8_un */
	0,	/* long_conv_to_ovf_i_un */
	0,	/* long_conv_to_ovf_u_un */
	0,	/* long_conv_to_ovf_i1 */
	0,	/* long_conv_to_ovf_u1 */
	0,	/* long_conv_to_ovf_i2 */
	0,	/* long_conv_to_ovf_u2 */
	0,	/* long_conv_to_ovf_i4 */
	0,	/* long_conv_to_ovf_u4 */
	0,	/* long_conv_to_ovf_i8 */
	0,	/* long_conv_to_ovf_u8 */
	1014,	/* long_ceq */
	1020,	/* long_cgt */
	1026,	/* long_cgt_un */
	1032,	/* long_clt */
	1038,	/* long_clt_un */
	1044,	/* long_conv_to_r_un */
	0,	/* long_conv_to_u */
	1050,	/* long_add_imm */
	1056,	/* long_sub_imm */
	1062,	/* long_mul_imm */
	1068,	/* long_and_imm */
	1074,	/* long_or_imm */
	1080,	/* long_xor_imm */
	1086,	/* long_shl_imm */
	1092,	/* long_shr_imm */
	1098,	/* long_shr_un_imm */
	0,	/* long_div_imm */
	0,	/* long_div_un_imm */
	0,	/* long_rem_imm */
	0,	/* long_rem_un_imm */
	1104,	/* long_beq */
	1110,	/* long_bge */
	1116,	/* long_bgt */
	1122,	/* long_ble */
	1128,	/* long_blt */
	1134,	/* long_bne_un */
	1140,	/* long_bge_un */
	1146,	/* long_bgt_un */
	1152,	/* long_ble_un */
	1158,	/* long_blt_un */
	0,	/* long_conv_to_r8_2 */
	0,	/* long_conv_to_r4_2 */
	0,	/* long_conv_to_r_un_2 */
	1164,	/* long_conv_to_ovf_i4_2 */
	1170,	/* int_add */
	1176,	/* int_sub */
	1182,	/* int_mul */
	1188,	/* int_div */
	1194,	/* int_div_un */
	1200,	/* int_rem */
	1206,	/* int_rem_un */
	1212,	/* int_and */
	1218,	/* int_or */
	1224,	/* int_xor */
	1230,	/* int_shl */
	1236,	/* int_shr */
	1242,	/* int_shr_un */
	1248,	/* int_neg */
	1254,	/* int_not */
	1260,	/* int_conv_to_i1 */
	1266,	/* int_conv_to_i2 */
	1272,	/* int_conv_to_i4 */
	0,	/* int_conv_to_i8 */
	1278,	/* int_conv_to_r4 */
	1284,	/* int_conv_to_r8 */
	1290,	/* int_conv_to_u4 */
	0,	/* int_conv_to_u8 */
	1296,	/* int_conv_to_r_un */
	0,	/* int_conv_to_u */
	1302,	/* int_conv_to_u2 */
	1308,	/* int_conv_to_u1 */
	0,	/* int_conv_to_i */
	0,	/* int_conv_to_ovf_i */
	0,	/* int_conv_to_ovf_u */
	1314,	/* int_add_ovf */
	1320,	/* int_add_ovf_un */
	1326,	/* int_mul_ovf */
	1332,	/* int_mul_ovf_un */
	1338,	/* int_sub_ovf */
	1344,	/* int_sub_ovf_un */
	0,	/* int_conv_to_ovf_i1_un */
	0,	/* int_conv_to_ovf_i2_un */
	0,	/* int_conv_to_ovf_i4_un */
	0,	/* int_conv_to_ovf_i8_un */
	0,	/* int_conv_to_ovf_u1_un */
	0,	/* int_conv_to_ovf_u2_un */
	0,	/* int_conv_to_ovf_u4_un */
	0,	/* int_conv_to_ovf_u8_un */
	0,	/* int_conv_to_ovf_i_un */
	0,	/* int_conv_to_ovf_u_un */
	0,	/* int_conv_to_ovf_i1 */
	0,	/* int_conv_to_ovf_u1 */
	0,	/* int_conv_to_ovf_i2 */
	0,	/* int_conv_to_ovf_u2 */
	0,	/* int_conv_to_ovf_i4 */
	0,	/* int_conv_to_ovf_u4 */
	0,	/* int_conv_to_ovf_i8 */
	0,	/* int_conv_to_ovf_u8 */
	1350,	/* int_adc */
	1356,	/* int_adc_imm */
	1362,	/* int_sbb */
	1368,	/* int_sbb_imm */
	1374,	/* int_addcc */
	1380,	/* int_subcc */
	1386,	/* int_add_imm */
	1392,	/* int_sub_imm */
	1398,	/* int_mul_imm */
	1404,	/* int_div_imm */
	1410,	/* int_div_un_imm */
	1416,	/* int_rem_imm */
	1422,	/* int_rem_un_imm */
	1428,	/* int_and_imm */
	1434,	/* int_or_imm */
	1440,	/* int_xor_imm */
	1446,	/* int_shl_imm */
	1452,	/* int_shr_imm */
	1458,	/* int_shr_un_imm */
	1464,	/* int_ceq */
	1470,	/* int_cgt */
	1476,	/* int_cgt_un */
	1482,	/* int_clt */
	1488,	/* int_clt_un */
	1494,	/* int_cneq */
	1500,	/* int_cge */
	1506,	/* int_cle */
	1512,	/* int_cge_un */
	1518,	/* int_cle_un */
	1524,	/* int_beq */
	1530,	/* int_bge */
	1536,	/* int_bgt */
	1542,	/* int_ble */
	1548,	/* int_blt */
	1554,	/* int_bne_un */
	1560,	/* int_bge_un */
	1566,	/* int_bgt_un */
	1572,	/* int_ble_un */
	1578,	/* int_blt_un */
	1584,	/* float_beq */
	1590,	/* float_bge */
	1596,	/* float_bgt */
	1602,	/* float_ble */
	1608,	/* float_blt */
	1614,	/* float_bne_un */
	1620,	/* float_bge_un */
	1626,	/* float_bgt_un */
	1632,	/* float_ble_un */
	1638,	/* float_blt_un */
	0,	/* r4_beq */
	0,	/* r4_bge */
	0,	/* r4_bgt */
	0,	/* r4_ble */
	0,	/* r4_blt */
	0,	/* r4_bne_un */
	0,	/* r4_bge_un */
	0,	/* r4_bgt_un */
	0,	/* r4_ble_un */
	0,	/* r4_blt_un */
	1644,	/* float_add */
	1650,	/* float_sub */
	1656,	/* float_mul */
	1662,	/* float_div */
	1668,	/* float_div_un */
	1674,	/* float_rem */
	1680,	/* float_rem_un */
	1686,	/* r4_add */
	1692,	/* r4_sub */
	1698,	/* r4_mul */
	1704,	/* r4_div */
	0,	/* r4_div_un */
	1710,	/* r4_rem */
	0,	/* r4_rem_un */
	1716,	/* float_neg */
	1722,	/* float_not */
	1728,	/* float_conv_to_i1 */
	1734,	/* float_conv_to_i2 */
	1740,	/* float_conv_to_i4 */
	1746,	/* float_conv_to_i8 */
	1752,	/* float_conv_to_r4 */
	0,	/* float_conv_to_r8 */
	1758,	/* float_conv_to_u4 */
	1764,	/* float_conv_to_u8 */
	1770,	/* r4_neg */
	0,	/* r4_not */
	1776,	/* r4_conv_to_i1 */
	1782,	/* r4_conv_to_i2 */
	1788,	/* r4_conv_to_i4 */
	1794,	/* r4_conv_to_i8 */
	1800,	/* r4_conv_to_r4 */
	1806,	/* r4_conv_to_r8 */
	1812,	/* r4_conv_to_u4 */
	1818,	/* r4_conv_to_u8 */
	1824,	/* float_conv_to_u2 */
	1830,	/* float_conv_to_u1 */
	1836,	/* float_conv_to_i */
	0,	/* float_conv_to_ovf_i */
	0,	/* float_conv_to_ovd_u */
	0,	/* float_add_ovf */
	0,	/* float_add_ovf_un */
	0,	/* float_mul_ovf */
	0,	/* float_mul_ovf_un */
	0,	/* float_sub_ovf */
	0,	/* float_sub_ovf_un */
	0,	/* float_conv_to_ovf_i1_un */
	0,	/* float_conv_to_ovf_i2_un */
	0,	/* float_conv_to_ovf_i4_un */
	0,	/* float_conv_to_ovf_i8_un */
	0,	/* float_conv_to_ovf_u1_un */
	0,	/* float_conv_to_ovf_u2_un */
	0,	/* float_conv_to_ovf_u4_un */
	0,	/* float_conv_to_ovf_u8_un */
	0,	/* float_conv_to_ovf_i_un */
	0,	/* float_conv_to_ovf_u_un */
	0,	/* float_conv_to_ovf_i1 */
	0,	/* float_conv_to_ovf_u1 */
	0,	/* float_conv_to_ovf_i2 */
	0,	/* float_conv_to_ovf_u2 */
	0,	/* float_conv_to_ovf_i4 */
	0,	/* float_conv_to_ovf_u4 */
	0,	/* float_conv_to_ovf_i8 */
	0,	/* float_conv_to_ovf_u8 */
	1842,	/* float_ceq */
	1848,	/* float_cgt */
	1854,	/* float_cgt_un */
	1860,	/* float_clt */
	1866,	/* float_clt_un */
	1872,	/* float_cneq */
	1878,	/* float_cge */
	1884,	/* float_cle */
	0,	/* float_ceq_membase */
	0,	/* float_cgt_membase */
	0,	/* float_cgt_un_membase */
	0,	/* float_clt_membase */
	0,	/* float_clt_un_membase */
	1890,	/* float_conv_to_u */
	1896,	/* ckfinite */
	1902,	/* r4_conv_to_u2 */
	1908,	/* r4_conv_to_u1 */
	0,	/* r4_conv_to_i */
	0,	/* r4_conv_to_ovf_i */
	0,	/* r4_conv_to_ovd_u */
	0,	/* r4_add_ovf */
	0,	/* r4_add_ovf_un */
	0,	/* r4_mul_ovf */
	0,	/* r4_mul_ovf_un */
	0,	/* r4_sub_ovf */
	0,	/* r4_sub_ovf_un */
	0,	/* r4_conv_to_ovf_i1_un */
	0,	/* r4_conv_to_ovf_i2_un */
	0,	/* r4_conv_to_ovf_i4_un */
	0,	/* r4_conv_to_ovf_i8_un */
	0,	/* r4_conv_to_ovf_u1_un */
	0,	/* r4_conv_to_ovf_u2_un */
	0,	/* r4_conv_to_ovf_u4_un */
	0,	/* r4_conv_to_ovf_u8_un */
	0,	/* r4_conv_to_ovf_i_un */
	0,	/* r4_conv_to_ovf_u_un */
	0,	/* r4_conv_to_ovf_i1 */
	0,	/* r4_conv_to_ovf_u1 */
	0,	/* r4_conv_to_ovf_i2 */
	0,	/* r4_conv_to_ovf_u2 */
	0,	/* r4_conv_to_ovf_i4 */
	0,	/* r4_conv_to_ovf_u4 */
	0,	/* r4_conv_to_ovf_i8 */
	0,	/* r4_conv_to_ovf_u8 */
	1914,	/* r4_ceq */
	1920,	/* r4_cgt */
	1926,	/* r4_cgt_un */
	1932,	/* r4_clt */
	1938,	/* r4_clt_un */
	1944,	/* r4_cneq */
	1950,	/* r4_cge */
	1956,	/* r4_cle */
	0,	/* float_getlow32 */
	0,	/* float_gethigh32 */
	1962,	/* jump_table */
	1968,	/* aot_const */
	0,	/* patch_info */
	0,	/* got_entry */
	1974,	/* call_handler */
	1980,	/* start_handler */
	1986,	/* endfilter */
	1992,	/* endfinally */
	1998,	/* get_ex_obj */
	2004,	/* bigmul */
	2010,	/* bigmul_un */
	0,	/* int_min_un */
	0,	/* int_max_un */
	0,	/* long_min_un */
	0,	/* long_max_un */
	0,	/* min */
	0,	/* max */
	0,	/* int_min */
	0,	/* int_max */
	0,	/* long_min */
	0,	/* long_max */
	0,	/* rmax */
	0,	/* rpow */
	2016,	/* adc */
	2022,	/* adc_imm */
	2028,	/* sbb */
	2034,	/* sbb_imm */
	2040,	/* addcc */
	2046,	/* addcc_imm */
	2052,	/* subcc */
	2058,	/* subcc_imm */
	2064,	/* br_reg */
	0,	/* sext_i1 */
	0,	/* sext_i2 */
	2070,	/* sext_i4 */
	0,	/* zext_i1 */
	0,	/* zext_i2 */
	2076,	/* zext_i4 */
	0,	/* cne */
	0,	/* trunc_i4 */
	2082,	/* add_ovf_carry */
	2088,	/* sub_ovf_carry */
	2094,	/* add_ovf_un_carry */
	2100,	/* sub_ovf_un_carry */
	0,	/* laddcc */
	0,	/* lsubcc */
	0,	/* sin */
	0,	/* cos */
	0,	/* abs */
	0,	/* tan */
	0,	/* atan */
	2106,	/* sqrt */
	0,	/* round */
	0,	/* sinf */
	0,	/* cosf */
	0,	/* absf */
	0,	/* sqrtf */
	0,	/* strlen */
	0,	/* newarr */
	0,	/* ldlen */
	0,	/* bounds_check */
	0,	/* isinst */
	0,	/* castclass */
	0,	/* getldelema2 */
	0,	/* memcpy */
	0,	/* memset */
	0,	/* save_lmf */
	0,	/* restore_lmf */
	0,	/* card_table_wbarrier */
	2112,	/* tls_get */
	0,	/* tls_get_reg */
	2118,	/* tls_set */
	0,	/* tls_set_reg */
	0,	/* load_gotaddr */
	2124,	/* dummy_use */
	2130,	/* not_reached */
	2136,	/* not_null */
	0,	/* xmove */
	0,	/* xzero */
	0,	/* xones */
	0,	/* xphi */
	2142,	/* memory_barrier */
	2148,	/* atomic_load_i1 */
	2154,	/* atomic_load_i2 */
	2160,	/* atomic_load_i4 */
	2166,	/* atomic_load_i8 */
	2172,	/* atomic_load_u1 */
	2178,	/* atomic_load_u2 */
	2184,	/* atomic_load_u4 */
	2190,	/* atomic_load_u8 */
	2196,	/* atomic_load_r4 */
	2202,	/* atomic_load_r8 */
	2208,	/* atomic_store_i1 */
	2214,	/* atomic_store_i2 */
	2220,	/* atomic_store_i4 */
	2226,	/* atomic_store_i8 */
	2232,	/* atomic_store_u1 */
	2238,	/* atomic_store_u2 */
	2244,	/* atomic_store_u4 */
	2250,	/* atomic_store_u8 */
	2256,	/* atomic_store_r4 */
	2262,	/* atomic_store_r8 */
	2268,	/* atomic_add_i4 */
	2274,	/* atomic_add_i8 */
	2280,	/* atomic_exchange_i4 */
	2286,	/* atomic_exchange_i8 */
	2292,	/* atomic_cas_i4 */
	2298,	/* atomic_cas_i8 */
	0,	/* cmov_ieq */
	0,	/* cmov_ige */
	0,	/* cmov_igt */
	0,	/* cmov_ile */
	0,	/* cmov_ilt */
	0,	/* cmov_ine_un */
	0,	/* cmov_ige_un */
	0,	/* cmov_igt_un */
	0,	/* cmov_ile_un */
	0,	/* cmov_ilt_un */
	0,	/* cmov_leq */
	0,	/* cmov_lge */
	0,	/* cmov_lgt */
	0,	/* cmov_lle */
	0,	/* cmov_llt */
	0,	/* cmov_lne_un */
	0,	/* cmov_lge_un */
	0,	/* cmov_lgt_un */
	0,	/* cmov_lle_un */
	0,	/* cmov_llt_un */
	2304,	/* liverange_start */
	2310,	/* liverange_end */
	2316,	/* gc_liveness_def */
	2322,	/* gc_liveness_use */
	2328,	/* gc_spill_slot_liveness_def */
	2334,	/* gc_param_slot_liveness_def */
	2340,	/* gc_safe_point */
	2346,	/* generic_class_init */
	2352,	/* arm_rsbs_imm */
	2358,	/* arm_rsc_imm */
	2364,	/* arm_setfreg_r4 */
	2370,	/* arm64_cbzw */
	2376,	/* arm64_cbzx */
	2382,	/* arm64_cbnzw */
	2388,	/* arm64_cbnzx */
	0,	/* llvm_outarg_vt */
	2394,	/* objc_get_selector */
	0,	/* get_sp */
	0,	/* set_sp */
	0,	/* get_last_error */
	2400,	/* fill_prof_call_ctx */
};

