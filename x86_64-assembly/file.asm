.section text
	pushq %rbp
	movq %rbp, %rsp
	movq -4(%rbp), %eax
	int 21h
	pop %rbp
	ret
