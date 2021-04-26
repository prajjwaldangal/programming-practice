SECTION .data
SECTION .text
	global main
main:
	pushq %rbp
	movq %rbp, %rsp
	movq -4(%rbp), %eax
	int 21h
	pop %rbp
	ret
