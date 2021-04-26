	.file	"optimize.c"
	.text
	.globl	getbuf
	.type	getbuf, @function
getbuf:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$4, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	gets@PLT
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	getbuf, .-getbuf
	.globl	pass2
	.type	pass2, @function
pass2:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movl	%edx, %eax
	movq	%rcx, -24(%rbp)
	movl	%r8d, -16(%rbp)
	movl	%r9d, %edi
	movl	16(%rbp), %edx
	movl	%esi, %ecx
	movb	%cl, -8(%rbp)
	movw	%ax, -12(%rbp)
	movl	%edi, %eax
	movb	%al, -28(%rbp)
	movl	%edx, %eax
	movw	%ax, -32(%rbp)
	movl	$0, %eax
	call	getbuf
	movsbl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	addl	%eax, %edx
	movswl	-12(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	addl	%eax, %edx
	movl	-16(%rbp), %eax
	addl	%eax, %edx
	movsbl	-28(%rbp), %eax
	addl	%eax, %edx
	movswl	-32(%rbp), %eax
	addl	%eax, %edx
	movq	24(%rbp), %rax
	addl	%eax, %edx
	movq	32(%rbp), %rax
	addl	%eax, %edx
	movq	40(%rbp), %rax
	addl	%eax, %edx
	movq	48(%rbp), %rax
	addl	%edx, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	pass2, .-pass2
	.globl	pass
	.type	pass, @function
pass:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movl	%edx, %eax
	movq	%rcx, -24(%rbp)
	movl	%r8d, -16(%rbp)
	movl	%r9d, %edi
	movl	16(%rbp), %edx
	movl	%esi, %ecx
	movb	%cl, -8(%rbp)
	movw	%ax, -12(%rbp)
	movl	%edi, %eax
	movb	%al, -28(%rbp)
	movl	%edx, %eax
	movw	%ax, -32(%rbp)
	movswl	-32(%rbp), %edi
	movsbl	-28(%rbp), %r9d
	movswl	-12(%rbp), %edx
	movsbl	-8(%rbp), %esi
	movl	-16(%rbp), %r8d
	movq	-24(%rbp), %rcx
	movl	-4(%rbp), %eax
	subq	$8, %rsp
	pushq	48(%rbp)
	pushq	40(%rbp)
	pushq	32(%rbp)
	pushq	24(%rbp)
	pushq	%rdi
	movl	%eax, %edi
	call	pass2
	addq	$48, %rsp
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	pass, .-pass
	.globl	main
	.type	main, @function
main:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$8, %rsp
	pushq	$11
	pushq	$10
	pushq	$9
	pushq	$8
	pushq	$7
	movl	$97, %r9d
	movl	$5, %r8d
	movl	$4, %ecx
	movl	$3, %edx
	movl	$98, %esi
	movl	$1, %edi
	call	pass
	addq	$48, %rsp
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
