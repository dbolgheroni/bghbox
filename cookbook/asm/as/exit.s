.section ".note.openbsd.ident", "a"
	.long 0x8
	.long 0x4
	.long 0x1
	.ascii "OpenBSD\0"
	.long 0x
	.p2align 2
.section .text
.globl _start
_start:
	xorl %eax, %eax
	pushl eax
	pushl eax
	movl $1, %eax
	int $0x80
	