	.text
	.file	"start"
	.globl	_42                             # -- Begin function _42
	.p2align	4, 0x90
	.type	_42,@function
_42:                                    # @_42
	.cfi_startproc
# %bb.0:                                # %entry
	movl	$42, -4(%rsp)
	movl	$42, %eax
	retq
.Lfunc_end0:
	.size	_42, .Lfunc_end0-_42
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
