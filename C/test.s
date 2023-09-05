	.text
	.file	"start"
	.globl	count_10                        # -- Begin function count_10
	.p2align	4, 0x90
	.type	count_10,@function
count_10:                               # @count_10
	.cfi_startproc
# %bb.0:                                # %entry
	movl	$0, -4(%rsp)
	cmpl	$9, -4(%rsp)
	jg	.LBB0_3
	.p2align	4, 0x90
.LBB0_2:                                # %loop
                                        # =>This Inner Loop Header: Depth=1
	incl	-4(%rsp)
	cmpl	$9, -4(%rsp)
	jle	.LBB0_2
.LBB0_3:                                # %loop_continue
	movl	-4(%rsp), %eax
	retq
.Lfunc_end0:
	.size	count_10, .Lfunc_end0-count_10
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
