	.text
	.file	"start"
	.globl	var_redef                       # -- Begin function var_redef
	.p2align	4, 0x90
	.type	var_redef,@function
var_redef:                              # @var_redef
	.cfi_startproc
# %bb.0:                                # %entry
	movl	$20, -4(%rsp)
	movl	$20, %eax
	retq
.Lfunc_end0:
	.size	var_redef, .Lfunc_end0-var_redef
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
