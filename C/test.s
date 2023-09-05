	.text
	.file	"start"
	.globl	is_major                        # -- Begin function is_major
	.p2align	4, 0x90
	.type	is_major,@function
is_major:                               # @is_major
	.cfi_startproc
# %bb.0:                                # %entry
	movl	%edi, -4(%rsp)
	testl	%edi, %edi
	js	.LBB0_4
# %bb.1:                                # %else
	cmpl	$17, -4(%rsp)
	jg	.LBB0_2
# %bb.5:                                # %then2
	movl	$1, %eax
	retq
.LBB0_4:                                # %then
	xorl	%eax, %eax
	retq
.LBB0_2:                                # %else4
	cmpl	$99, -4(%rsp)
	jg	.LBB0_3
# %bb.6:                                # %then6
	movl	$2, %eax
	retq
.LBB0_3:                                # %continue7
	movl	$3, %eax
	retq
.Lfunc_end0:
	.size	is_major, .Lfunc_end0-is_major
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
