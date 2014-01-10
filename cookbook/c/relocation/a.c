// http://www.technovelty.org/linux/plt-and-got-the-key-to-code-sharing-and-dynamic-libraries.html

extern int foo;

int function(void) {
    return foo;
}

/*
$ pcc -c a.c
$ readelf --relocs ./a.o

Relocation section '.rela.text' at offset 0x3b0 contains 1 entries:
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
00000000000a  000600000002 R_X86_64_PC32     0000000000000000 foo + fffffffffffffffc
$ gcc -c a.c            
$ readelf --relocs ./a.o

Relocation section '.rela.text' at offset 0x448 contains 1 entries:
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
000000000007  000800000009 R_X86_64_GOTPCREL 0000000000000000 foo + fffffffffffffffc

Relocation section '.rela.eh_frame' at offset 0x460 contains 1 entries:
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
000000000020  000200000002 R_X86_64_PC32     0000000000000000 .text + 0
$
*/

/*
$ gcc -c a.c            
$ objdump --disassemble ./a.o

./a.o:     file format elf64-x86-64

Disassembly of section .text:

0000000000000000 <function>:
   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   48 8b 05 00 00 00 00    mov    0(%rip),%rax        # b <function+0xb>
   b:   8b 00                   mov    (%rax),%eax
   d:   c9                      leaveq 
   e:   c3                      retq   
$ pcc -c a.c
$ objdump --disassemble ./a.o

./a.o:     file format elf64-x86-64

Disassembly of section .text:

0000000000000000 <function>:
   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   48 83 ec 10             sub    $0x10,%rsp
   8:   8b 05 00 00 00 00       mov    0(%rip),%eax        # e <function+0xe>
   e:   89 45 fc                mov    %eax,0xfffffffffffffffc(%rbp)
  11:   eb 00                   jmp    13 <function+0x13>
  13:   8b 45 fc                mov    0xfffffffffffffffc(%rbp),%eax
  16:   c9                      leaveq 
  17:   c3                      retq   
$
*/
