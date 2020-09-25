
bomb:     file format elf64-x86-64


Disassembly of section .init:

0000000000000ca8 <_init>:
 ca8:	48 83 ec 08          	sub    $0x8,%rsp
 cac:	48 8b 05 35 33 20 00 	mov    0x203335(%rip),%rax        # 203fe8 <__gmon_start__>
 cb3:	48 85 c0             	test   %rax,%rax
 cb6:	74 02                	je     cba <_init+0x12>
 cb8:	ff d0                	callq  *%rax
 cba:	48 83 c4 08          	add    $0x8,%rsp
 cbe:	c3                   	retq   

Disassembly of section .plt:

0000000000000cc0 <.plt>:
 cc0:	ff 35 22 32 20 00    	pushq  0x203222(%rip)        # 203ee8 <_GLOBAL_OFFSET_TABLE_+0x8>
 cc6:	ff 25 24 32 20 00    	jmpq   *0x203224(%rip)        # 203ef0 <_GLOBAL_OFFSET_TABLE_+0x10>
 ccc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000cd0 <getenv@plt>:
 cd0:	ff 25 22 32 20 00    	jmpq   *0x203222(%rip)        # 203ef8 <getenv@GLIBC_2.2.5>
 cd6:	68 00 00 00 00       	pushq  $0x0
 cdb:	e9 e0 ff ff ff       	jmpq   cc0 <.plt>

0000000000000ce0 <strcasecmp@plt>:
 ce0:	ff 25 1a 32 20 00    	jmpq   *0x20321a(%rip)        # 203f00 <strcasecmp@GLIBC_2.2.5>
 ce6:	68 01 00 00 00       	pushq  $0x1
 ceb:	e9 d0 ff ff ff       	jmpq   cc0 <.plt>

0000000000000cf0 <__errno_location@plt>:
 cf0:	ff 25 12 32 20 00    	jmpq   *0x203212(%rip)        # 203f08 <__errno_location@GLIBC_2.2.5>
 cf6:	68 02 00 00 00       	pushq  $0x2
 cfb:	e9 c0 ff ff ff       	jmpq   cc0 <.plt>

0000000000000d00 <strcpy@plt>:
 d00:	ff 25 0a 32 20 00    	jmpq   *0x20320a(%rip)        # 203f10 <strcpy@GLIBC_2.2.5>
 d06:	68 03 00 00 00       	pushq  $0x3
 d0b:	e9 b0 ff ff ff       	jmpq   cc0 <.plt>

0000000000000d10 <puts@plt>:
 d10:	ff 25 02 32 20 00    	jmpq   *0x203202(%rip)        # 203f18 <puts@GLIBC_2.2.5>
 d16:	68 04 00 00 00       	pushq  $0x4
 d1b:	e9 a0 ff ff ff       	jmpq   cc0 <.plt>

0000000000000d20 <write@plt>:
 d20:	ff 25 fa 31 20 00    	jmpq   *0x2031fa(%rip)        # 203f20 <write@GLIBC_2.2.5>
 d26:	68 05 00 00 00       	pushq  $0x5
 d2b:	e9 90 ff ff ff       	jmpq   cc0 <.plt>

0000000000000d30 <inet_ntoa@plt>:
 d30:	ff 25 f2 31 20 00    	jmpq   *0x2031f2(%rip)        # 203f28 <inet_ntoa@GLIBC_2.2.5>
 d36:	68 06 00 00 00       	pushq  $0x6
 d3b:	e9 80 ff ff ff       	jmpq   cc0 <.plt>

0000000000000d40 <__stack_chk_fail@plt>:
 d40:	ff 25 ea 31 20 00    	jmpq   *0x2031ea(%rip)        # 203f30 <__stack_chk_fail@GLIBC_2.4>
 d46:	68 07 00 00 00       	pushq  $0x7
 d4b:	e9 70 ff ff ff       	jmpq   cc0 <.plt>

0000000000000d50 <alarm@plt>:
 d50:	ff 25 e2 31 20 00    	jmpq   *0x2031e2(%rip)        # 203f38 <alarm@GLIBC_2.2.5>
 d56:	68 08 00 00 00       	pushq  $0x8
 d5b:	e9 60 ff ff ff       	jmpq   cc0 <.plt>

0000000000000d60 <close@plt>:
 d60:	ff 25 da 31 20 00    	jmpq   *0x2031da(%rip)        # 203f40 <close@GLIBC_2.2.5>
 d66:	68 09 00 00 00       	pushq  $0x9
 d6b:	e9 50 ff ff ff       	jmpq   cc0 <.plt>

0000000000000d70 <read@plt>:
 d70:	ff 25 d2 31 20 00    	jmpq   *0x2031d2(%rip)        # 203f48 <read@GLIBC_2.2.5>
 d76:	68 0a 00 00 00       	pushq  $0xa
 d7b:	e9 40 ff ff ff       	jmpq   cc0 <.plt>

0000000000000d80 <fgets@plt>:
 d80:	ff 25 ca 31 20 00    	jmpq   *0x2031ca(%rip)        # 203f50 <fgets@GLIBC_2.2.5>
 d86:	68 0b 00 00 00       	pushq  $0xb
 d8b:	e9 30 ff ff ff       	jmpq   cc0 <.plt>

0000000000000d90 <signal@plt>:
 d90:	ff 25 c2 31 20 00    	jmpq   *0x2031c2(%rip)        # 203f58 <signal@GLIBC_2.2.5>
 d96:	68 0c 00 00 00       	pushq  $0xc
 d9b:	e9 20 ff ff ff       	jmpq   cc0 <.plt>

0000000000000da0 <gethostbyname@plt>:
 da0:	ff 25 ba 31 20 00    	jmpq   *0x2031ba(%rip)        # 203f60 <gethostbyname@GLIBC_2.2.5>
 da6:	68 0d 00 00 00       	pushq  $0xd
 dab:	e9 10 ff ff ff       	jmpq   cc0 <.plt>

0000000000000db0 <__memmove_chk@plt>:
 db0:	ff 25 b2 31 20 00    	jmpq   *0x2031b2(%rip)        # 203f68 <__memmove_chk@GLIBC_2.3.4>
 db6:	68 0e 00 00 00       	pushq  $0xe
 dbb:	e9 00 ff ff ff       	jmpq   cc0 <.plt>

0000000000000dc0 <strncasecmp@plt>:
 dc0:	ff 25 aa 31 20 00    	jmpq   *0x2031aa(%rip)        # 203f70 <strncasecmp@GLIBC_2.2.5>
 dc6:	68 0f 00 00 00       	pushq  $0xf
 dcb:	e9 f0 fe ff ff       	jmpq   cc0 <.plt>

0000000000000dd0 <fflush@plt>:
 dd0:	ff 25 a2 31 20 00    	jmpq   *0x2031a2(%rip)        # 203f78 <fflush@GLIBC_2.2.5>
 dd6:	68 10 00 00 00       	pushq  $0x10
 ddb:	e9 e0 fe ff ff       	jmpq   cc0 <.plt>

0000000000000de0 <__isoc99_sscanf@plt>:
 de0:	ff 25 9a 31 20 00    	jmpq   *0x20319a(%rip)        # 203f80 <__isoc99_sscanf@GLIBC_2.7>
 de6:	68 11 00 00 00       	pushq  $0x11
 deb:	e9 d0 fe ff ff       	jmpq   cc0 <.plt>

0000000000000df0 <__printf_chk@plt>:
 df0:	ff 25 92 31 20 00    	jmpq   *0x203192(%rip)        # 203f88 <__printf_chk@GLIBC_2.3.4>
 df6:	68 12 00 00 00       	pushq  $0x12
 dfb:	e9 c0 fe ff ff       	jmpq   cc0 <.plt>

0000000000000e00 <fopen@plt>:
 e00:	ff 25 8a 31 20 00    	jmpq   *0x20318a(%rip)        # 203f90 <fopen@GLIBC_2.2.5>
 e06:	68 13 00 00 00       	pushq  $0x13
 e0b:	e9 b0 fe ff ff       	jmpq   cc0 <.plt>

0000000000000e10 <gethostname@plt>:
 e10:	ff 25 82 31 20 00    	jmpq   *0x203182(%rip)        # 203f98 <gethostname@GLIBC_2.2.5>
 e16:	68 14 00 00 00       	pushq  $0x14
 e1b:	e9 a0 fe ff ff       	jmpq   cc0 <.plt>

0000000000000e20 <exit@plt>:
 e20:	ff 25 7a 31 20 00    	jmpq   *0x20317a(%rip)        # 203fa0 <exit@GLIBC_2.2.5>
 e26:	68 15 00 00 00       	pushq  $0x15
 e2b:	e9 90 fe ff ff       	jmpq   cc0 <.plt>

0000000000000e30 <connect@plt>:
 e30:	ff 25 72 31 20 00    	jmpq   *0x203172(%rip)        # 203fa8 <connect@GLIBC_2.2.5>
 e36:	68 16 00 00 00       	pushq  $0x16
 e3b:	e9 80 fe ff ff       	jmpq   cc0 <.plt>

0000000000000e40 <__fprintf_chk@plt>:
 e40:	ff 25 6a 31 20 00    	jmpq   *0x20316a(%rip)        # 203fb0 <__fprintf_chk@GLIBC_2.3.4>
 e46:	68 17 00 00 00       	pushq  $0x17
 e4b:	e9 70 fe ff ff       	jmpq   cc0 <.plt>

0000000000000e50 <sleep@plt>:
 e50:	ff 25 62 31 20 00    	jmpq   *0x203162(%rip)        # 203fb8 <sleep@GLIBC_2.2.5>
 e56:	68 18 00 00 00       	pushq  $0x18
 e5b:	e9 60 fe ff ff       	jmpq   cc0 <.plt>

0000000000000e60 <__ctype_b_loc@plt>:
 e60:	ff 25 5a 31 20 00    	jmpq   *0x20315a(%rip)        # 203fc0 <__ctype_b_loc@GLIBC_2.3>
 e66:	68 19 00 00 00       	pushq  $0x19
 e6b:	e9 50 fe ff ff       	jmpq   cc0 <.plt>

0000000000000e70 <__sprintf_chk@plt>:
 e70:	ff 25 52 31 20 00    	jmpq   *0x203152(%rip)        # 203fc8 <__sprintf_chk@GLIBC_2.3.4>
 e76:	68 1a 00 00 00       	pushq  $0x1a
 e7b:	e9 40 fe ff ff       	jmpq   cc0 <.plt>

0000000000000e80 <socket@plt>:
 e80:	ff 25 4a 31 20 00    	jmpq   *0x20314a(%rip)        # 203fd0 <socket@GLIBC_2.2.5>
 e86:	68 1b 00 00 00       	pushq  $0x1b
 e8b:	e9 30 fe ff ff       	jmpq   cc0 <.plt>

Disassembly of section .plt.got:

0000000000000e90 <__cxa_finalize@plt>:
 e90:	ff 25 62 31 20 00    	jmpq   *0x203162(%rip)        # 203ff8 <__cxa_finalize@GLIBC_2.2.5>
 e96:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000000ea0 <_start>:
     ea0:	31 ed                	xor    %ebp,%ebp
     ea2:	49 89 d1             	mov    %rdx,%r9
     ea5:	5e                   	pop    %rsi
     ea6:	48 89 e2             	mov    %rsp,%rdx
     ea9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
     ead:	50                   	push   %rax
     eae:	54                   	push   %rsp
     eaf:	4c 8d 05 5a 17 00 00 	lea    0x175a(%rip),%r8        # 2610 <__libc_csu_fini>
     eb6:	48 8d 0d e3 16 00 00 	lea    0x16e3(%rip),%rcx        # 25a0 <__libc_csu_init>
     ebd:	48 8d 3d e6 00 00 00 	lea    0xe6(%rip),%rdi        # faa <main>
     ec4:	ff 15 16 31 20 00    	callq  *0x203116(%rip)        # 203fe0 <__libc_start_main@GLIBC_2.2.5>
     eca:	f4                   	hlt    
     ecb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000000ed0 <deregister_tm_clones>:
     ed0:	48 8d 3d 69 35 20 00 	lea    0x203569(%rip),%rdi        # 204440 <stdout@@GLIBC_2.2.5>
     ed7:	55                   	push   %rbp
     ed8:	48 8d 05 61 35 20 00 	lea    0x203561(%rip),%rax        # 204440 <stdout@@GLIBC_2.2.5>
     edf:	48 39 f8             	cmp    %rdi,%rax
     ee2:	48 89 e5             	mov    %rsp,%rbp
     ee5:	74 19                	je     f00 <deregister_tm_clones+0x30>
     ee7:	48 8b 05 ea 30 20 00 	mov    0x2030ea(%rip),%rax        # 203fd8 <_ITM_deregisterTMCloneTable>
     eee:	48 85 c0             	test   %rax,%rax
     ef1:	74 0d                	je     f00 <deregister_tm_clones+0x30>
     ef3:	5d                   	pop    %rbp
     ef4:	ff e0                	jmpq   *%rax
     ef6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
     efd:	00 00 00 
     f00:	5d                   	pop    %rbp
     f01:	c3                   	retq   
     f02:	0f 1f 40 00          	nopl   0x0(%rax)
     f06:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
     f0d:	00 00 00 

0000000000000f10 <register_tm_clones>:
     f10:	48 8d 3d 29 35 20 00 	lea    0x203529(%rip),%rdi        # 204440 <stdout@@GLIBC_2.2.5>
     f17:	48 8d 35 22 35 20 00 	lea    0x203522(%rip),%rsi        # 204440 <stdout@@GLIBC_2.2.5>
     f1e:	55                   	push   %rbp
     f1f:	48 29 fe             	sub    %rdi,%rsi
     f22:	48 89 e5             	mov    %rsp,%rbp
     f25:	48 c1 fe 03          	sar    $0x3,%rsi
     f29:	48 89 f0             	mov    %rsi,%rax
     f2c:	48 c1 e8 3f          	shr    $0x3f,%rax
     f30:	48 01 c6             	add    %rax,%rsi
     f33:	48 d1 fe             	sar    %rsi
     f36:	74 18                	je     f50 <register_tm_clones+0x40>
     f38:	48 8b 05 b1 30 20 00 	mov    0x2030b1(%rip),%rax        # 203ff0 <_ITM_registerTMCloneTable>
     f3f:	48 85 c0             	test   %rax,%rax
     f42:	74 0c                	je     f50 <register_tm_clones+0x40>
     f44:	5d                   	pop    %rbp
     f45:	ff e0                	jmpq   *%rax
     f47:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
     f4e:	00 00 
     f50:	5d                   	pop    %rbp
     f51:	c3                   	retq   
     f52:	0f 1f 40 00          	nopl   0x0(%rax)
     f56:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
     f5d:	00 00 00 

0000000000000f60 <__do_global_dtors_aux>:
     f60:	80 3d 01 35 20 00 00 	cmpb   $0x0,0x203501(%rip)        # 204468 <completed.7698>
     f67:	75 2f                	jne    f98 <__do_global_dtors_aux+0x38>
     f69:	48 83 3d 87 30 20 00 	cmpq   $0x0,0x203087(%rip)        # 203ff8 <__cxa_finalize@GLIBC_2.2.5>
     f70:	00 
     f71:	55                   	push   %rbp
     f72:	48 89 e5             	mov    %rsp,%rbp
     f75:	74 0c                	je     f83 <__do_global_dtors_aux+0x23>
     f77:	48 8b 3d 8a 30 20 00 	mov    0x20308a(%rip),%rdi        # 204008 <__dso_handle>
     f7e:	e8 0d ff ff ff       	callq  e90 <__cxa_finalize@plt>
     f83:	e8 48 ff ff ff       	callq  ed0 <deregister_tm_clones>
     f88:	c6 05 d9 34 20 00 01 	movb   $0x1,0x2034d9(%rip)        # 204468 <completed.7698>
     f8f:	5d                   	pop    %rbp
     f90:	c3                   	retq   
     f91:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
     f98:	f3 c3                	repz retq 
     f9a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000000fa0 <frame_dummy>:
     fa0:	55                   	push   %rbp
     fa1:	48 89 e5             	mov    %rsp,%rbp
     fa4:	5d                   	pop    %rbp
     fa5:	e9 66 ff ff ff       	jmpq   f10 <register_tm_clones>

0000000000000faa <main>:
     faa:	53                   	push   %rbx
     fab:	83 ff 01             	cmp    $0x1,%edi
     fae:	0f 84 e6 00 00 00    	je     109a <main+0xf0>
     fb4:	48 89 f3             	mov    %rsi,%rbx
     fb7:	83 ff 02             	cmp    $0x2,%edi
     fba:	0f 85 0f 01 00 00    	jne    10cf <main+0x125>
     fc0:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
     fc4:	48 8d 35 59 16 00 00 	lea    0x1659(%rip),%rsi        # 2624 <_IO_stdin_used+0x4>
     fcb:	e8 30 fe ff ff       	callq  e00 <fopen@plt>
     fd0:	48 89 05 99 34 20 00 	mov    %rax,0x203499(%rip)        # 204470 <infile>
     fd7:	48 85 c0             	test   %rax,%rax
     fda:	0f 84 cd 00 00 00    	je     10ad <main+0x103>
     fe0:	e8 3c 05 00 00       	callq  1521 <initialize_bomb>
     fe5:	48 8d 3d ac 16 00 00 	lea    0x16ac(%rip),%rdi        # 2698 <_IO_stdin_used+0x78>
     fec:	e8 1f fd ff ff       	callq  d10 <puts@plt>
     ff1:	48 8d 3d e0 16 00 00 	lea    0x16e0(%rip),%rdi        # 26d8 <_IO_stdin_used+0xb8>
     ff8:	e8 13 fd ff ff       	callq  d10 <puts@plt>
     ffd:	e8 45 08 00 00       	callq  1847 <read_line>
    1002:	48 89 c7             	mov    %rax,%rdi
    1005:	e8 e8 00 00 00       	callq  10f2 <phase_1>
    100a:	e8 7c 09 00 00       	callq  198b <phase_defused>
    100f:	48 8d 3d f2 16 00 00 	lea    0x16f2(%rip),%rdi        # 2708 <_IO_stdin_used+0xe8>
    1016:	e8 f5 fc ff ff       	callq  d10 <puts@plt>
    101b:	e8 27 08 00 00       	callq  1847 <read_line>
    1020:	48 89 c7             	mov    %rax,%rdi
    1023:	e8 ea 00 00 00       	callq  1112 <phase_2>
    1028:	e8 5e 09 00 00       	callq  198b <phase_defused>
    102d:	48 8d 3d 29 16 00 00 	lea    0x1629(%rip),%rdi        # 265d <_IO_stdin_used+0x3d>
    1034:	e8 d7 fc ff ff       	callq  d10 <puts@plt>
    1039:	e8 09 08 00 00       	callq  1847 <read_line>
    103e:	48 89 c7             	mov    %rax,%rdi
    1041:	e8 3a 01 00 00       	callq  1180 <phase_3>
    1046:	e8 40 09 00 00       	callq  198b <phase_defused>
    104b:	48 8d 3d 29 16 00 00 	lea    0x1629(%rip),%rdi        # 267b <_IO_stdin_used+0x5b>
    1052:	e8 b9 fc ff ff       	callq  d10 <puts@plt>
    1057:	e8 eb 07 00 00       	callq  1847 <read_line>
    105c:	48 89 c7             	mov    %rax,%rdi
    105f:	e8 09 02 00 00       	callq  126d <phase_4>
    1064:	e8 22 09 00 00       	callq  198b <phase_defused>
    1069:	48 8d 3d c8 16 00 00 	lea    0x16c8(%rip),%rdi        # 2738 <_IO_stdin_used+0x118>
    1070:	e8 9b fc ff ff       	callq  d10 <puts@plt>
    1075:	e8 cd 07 00 00       	callq  1847 <read_line>
    107a:	48 89 c7             	mov    %rax,%rdi
    107d:	e8 5a 02 00 00       	callq  12dc <phase_5>
    1082:	e8 04 09 00 00       	callq  198b <phase_defused>
    1087:	48 8d 3d d2 16 00 00 	lea    0x16d2(%rip),%rdi        # 2760 <_IO_stdin_used+0x140>
    108e:	e8 7d fc ff ff       	callq  d10 <puts@plt>
    1093:	b8 00 00 00 00       	mov    $0x0,%eax
    1098:	5b                   	pop    %rbx
    1099:	c3                   	retq   
    109a:	48 8b 05 af 33 20 00 	mov    0x2033af(%rip),%rax        # 204450 <stdin@@GLIBC_2.2.5>
    10a1:	48 89 05 c8 33 20 00 	mov    %rax,0x2033c8(%rip)        # 204470 <infile>
    10a8:	e9 33 ff ff ff       	jmpq   fe0 <main+0x36>
    10ad:	48 8b 4b 08          	mov    0x8(%rbx),%rcx
    10b1:	48 8b 13             	mov    (%rbx),%rdx
    10b4:	48 8d 35 6b 15 00 00 	lea    0x156b(%rip),%rsi        # 2626 <_IO_stdin_used+0x6>
    10bb:	bf 01 00 00 00       	mov    $0x1,%edi
    10c0:	e8 2b fd ff ff       	callq  df0 <__printf_chk@plt>
    10c5:	bf 08 00 00 00       	mov    $0x8,%edi
    10ca:	e8 51 fd ff ff       	callq  e20 <exit@plt>
    10cf:	48 8b 16             	mov    (%rsi),%rdx
    10d2:	48 8d 35 6a 15 00 00 	lea    0x156a(%rip),%rsi        # 2643 <_IO_stdin_used+0x23>
    10d9:	bf 01 00 00 00       	mov    $0x1,%edi
    10de:	b8 00 00 00 00       	mov    $0x0,%eax
    10e3:	e8 08 fd ff ff       	callq  df0 <__printf_chk@plt>
    10e8:	bf 08 00 00 00       	mov    $0x8,%edi
    10ed:	e8 2e fd ff ff       	callq  e20 <exit@plt>

00000000000010f2 <phase_1>:
    10f2:	48 83 ec 08          	sub    $0x8,%rsp
    10f6:	48 8d 35 8b 16 00 00 	lea    0x168b(%rip),%rsi        # 2788 <_IO_stdin_used+0x168>
    10fd:	e8 c0 02 00 00       	callq  13c2 <strings_not_equal>
    1102:	85 c0                	test   %eax,%eax
    1104:	75 05                	jne    110b <phase_1+0x19>
    1106:	48 83 c4 08          	add    $0x8,%rsp
    110a:	c3                   	retq   
    110b:	e8 ba 06 00 00       	callq  17ca <explode_bomb>
    1110:	eb f4                	jmp    1106 <phase_1+0x14>

0000000000001112 <phase_2>:
    1112:	55                   	push   %rbp
    1113:	53                   	push   %rbx
    1114:	48 83 ec 28          	sub    $0x28,%rsp
    1118:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    111f:	00 00 
    1121:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    1126:	31 c0                	xor    %eax,%eax
    1128:	48 89 e6             	mov    %rsp,%rsi
    112b:	e8 d6 06 00 00       	callq  1806 <read_six_numbers>
    1130:	83 3c 24 00          	cmpl   $0x0,(%rsp)
    1134:	78 0a                	js     1140 <phase_2+0x2e>
    1136:	bb 01 00 00 00       	mov    $0x1,%ebx
    113b:	48 89 e5             	mov    %rsp,%rbp
    113e:	eb 11                	jmp    1151 <phase_2+0x3f>
    1140:	e8 85 06 00 00       	callq  17ca <explode_bomb>
    1145:	eb ef                	jmp    1136 <phase_2+0x24>
    1147:	48 83 c3 01          	add    $0x1,%rbx
    114b:	48 83 fb 06          	cmp    $0x6,%rbx
    114f:	74 13                	je     1164 <phase_2+0x52>
    1151:	89 d8                	mov    %ebx,%eax
    1153:	03 44 9d fc          	add    -0x4(%rbp,%rbx,4),%eax
    1157:	39 44 9d 00          	cmp    %eax,0x0(%rbp,%rbx,4)
    115b:	74 ea                	je     1147 <phase_2+0x35>
    115d:	e8 68 06 00 00       	callq  17ca <explode_bomb>
    1162:	eb e3                	jmp    1147 <phase_2+0x35>
    1164:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
    1169:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1170:	00 00 
    1172:	75 07                	jne    117b <phase_2+0x69>
    1174:	48 83 c4 28          	add    $0x28,%rsp
    1178:	5b                   	pop    %rbx
    1179:	5d                   	pop    %rbp
    117a:	c3                   	retq   
    117b:	e8 c0 fb ff ff       	callq  d40 <__stack_chk_fail@plt>

0000000000001180 <phase_3>:
    1180:	48 83 ec 18          	sub    $0x18,%rsp
    1184:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    118b:	00 00 
    118d:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    1192:	31 c0                	xor    %eax,%eax
    1194:	48 8d 4c 24 04       	lea    0x4(%rsp),%rcx
    1199:	48 89 e2             	mov    %rsp,%rdx
    119c:	48 8d 35 ad 18 00 00 	lea    0x18ad(%rip),%rsi        # 2a50 <array.3415+0x270>
    11a3:	e8 38 fc ff ff       	callq  de0 <__isoc99_sscanf@plt>
    11a8:	83 f8 01             	cmp    $0x1,%eax
    11ab:	7e 19                	jle    11c6 <phase_3+0x46>
    11ad:	83 3c 24 07          	cmpl   $0x7,(%rsp)
    11b1:	77 4b                	ja     11fe <phase_3+0x7e>
    11b3:	8b 04 24             	mov    (%rsp),%eax
    11b6:	48 8d 15 03 16 00 00 	lea    0x1603(%rip),%rdx        # 27c0 <_IO_stdin_used+0x1a0>
    11bd:	48 63 04 82          	movslq (%rdx,%rax,4),%rax
    11c1:	48 01 d0             	add    %rdx,%rax
    11c4:	ff e0                	jmpq   *%rax
    11c6:	e8 ff 05 00 00       	callq  17ca <explode_bomb>
    11cb:	eb e0                	jmp    11ad <phase_3+0x2d>
    11cd:	b8 e4 01 00 00       	mov    $0x1e4,%eax
    11d2:	eb 3b                	jmp    120f <phase_3+0x8f>
    11d4:	b8 ab 03 00 00       	mov    $0x3ab,%eax
    11d9:	eb 34                	jmp    120f <phase_3+0x8f>
    11db:	b8 95 02 00 00       	mov    $0x295,%eax
    11e0:	eb 2d                	jmp    120f <phase_3+0x8f>
    11e2:	b8 94 01 00 00       	mov    $0x194,%eax
    11e7:	eb 26                	jmp    120f <phase_3+0x8f>
    11e9:	b8 da 02 00 00       	mov    $0x2da,%eax
    11ee:	eb 1f                	jmp    120f <phase_3+0x8f>
    11f0:	b8 c5 00 00 00       	mov    $0xc5,%eax
    11f5:	eb 18                	jmp    120f <phase_3+0x8f>
    11f7:	b8 c8 00 00 00       	mov    $0xc8,%eax
    11fc:	eb 11                	jmp    120f <phase_3+0x8f>
    11fe:	e8 c7 05 00 00       	callq  17ca <explode_bomb>
    1203:	b8 00 00 00 00       	mov    $0x0,%eax
    1208:	eb 05                	jmp    120f <phase_3+0x8f>
    120a:	b8 ad 03 00 00       	mov    $0x3ad,%eax
    120f:	39 44 24 04          	cmp    %eax,0x4(%rsp)
    1213:	74 05                	je     121a <phase_3+0x9a>
    1215:	e8 b0 05 00 00       	callq  17ca <explode_bomb>
    121a:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    121f:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1226:	00 00 
    1228:	75 05                	jne    122f <phase_3+0xaf>
    122a:	48 83 c4 18          	add    $0x18,%rsp
    122e:	c3                   	retq   
    122f:	e8 0c fb ff ff       	callq  d40 <__stack_chk_fail@plt>

0000000000001234 <func4>:
    1234:	b8 00 00 00 00       	mov    $0x0,%eax
    1239:	85 ff                	test   %edi,%edi
    123b:	7e 07                	jle    1244 <func4+0x10>
    123d:	89 f0                	mov    %esi,%eax
    123f:	83 ff 01             	cmp    $0x1,%edi
    1242:	75 02                	jne    1246 <func4+0x12>
    1244:	f3 c3                	repz retq 
    1246:	41 54                	push   %r12
    1248:	55                   	push   %rbp
    1249:	53                   	push   %rbx
    124a:	41 89 f4             	mov    %esi,%r12d
    124d:	89 fb                	mov    %edi,%ebx
    124f:	8d 7f ff             	lea    -0x1(%rdi),%edi
    1252:	e8 dd ff ff ff       	callq  1234 <func4>
    1257:	42 8d 2c 20          	lea    (%rax,%r12,1),%ebp
    125b:	8d 7b fe             	lea    -0x2(%rbx),%edi
    125e:	44 89 e6             	mov    %r12d,%esi
    1261:	e8 ce ff ff ff       	callq  1234 <func4>
    1266:	01 e8                	add    %ebp,%eax
    1268:	5b                   	pop    %rbx
    1269:	5d                   	pop    %rbp
    126a:	41 5c                	pop    %r12
    126c:	c3                   	retq   

000000000000126d <phase_4>:
    126d:	48 83 ec 18          	sub    $0x18,%rsp
    1271:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1278:	00 00 
    127a:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    127f:	31 c0                	xor    %eax,%eax
    1281:	48 89 e1             	mov    %rsp,%rcx
    1284:	48 8d 54 24 04       	lea    0x4(%rsp),%rdx
    1289:	48 8d 35 c0 17 00 00 	lea    0x17c0(%rip),%rsi        # 2a50 <array.3415+0x270>
    1290:	e8 4b fb ff ff       	callq  de0 <__isoc99_sscanf@plt>
    1295:	83 f8 02             	cmp    $0x2,%eax
    1298:	75 0b                	jne    12a5 <phase_4+0x38>
    129a:	8b 04 24             	mov    (%rsp),%eax
    129d:	83 e8 02             	sub    $0x2,%eax
    12a0:	83 f8 02             	cmp    $0x2,%eax
    12a3:	76 05                	jbe    12aa <phase_4+0x3d>
    12a5:	e8 20 05 00 00       	callq  17ca <explode_bomb>
    12aa:	8b 34 24             	mov    (%rsp),%esi
    12ad:	bf 08 00 00 00       	mov    $0x8,%edi
    12b2:	e8 7d ff ff ff       	callq  1234 <func4>
    12b7:	39 44 24 04          	cmp    %eax,0x4(%rsp)
    12bb:	74 05                	je     12c2 <phase_4+0x55>
    12bd:	e8 08 05 00 00       	callq  17ca <explode_bomb>
    12c2:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    12c7:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    12ce:	00 00 
    12d0:	75 05                	jne    12d7 <phase_4+0x6a>
    12d2:	48 83 c4 18          	add    $0x18,%rsp
    12d6:	c3                   	retq   
    12d7:	e8 64 fa ff ff       	callq  d40 <__stack_chk_fail@plt>

00000000000012dc <phase_5>:
    12dc:	53                   	push   %rbx
    12dd:	48 89 fb             	mov    %rdi,%rbx
    12e0:	e8 c0 00 00 00       	callq  13a5 <string_length>
    12e5:	83 f8 06             	cmp    $0x6,%eax
    12e8:	75 31                	jne    131b <phase_5+0x3f>
    12ea:	48 89 d8             	mov    %rbx,%rax
    12ed:	48 8d 7b 06          	lea    0x6(%rbx),%rdi
    12f1:	b9 00 00 00 00       	mov    $0x0,%ecx
    12f6:	48 8d 35 e3 14 00 00 	lea    0x14e3(%rip),%rsi        # 27e0 <array.3415>
    12fd:	0f b6 10             	movzbl (%rax),%edx
    1300:	83 e2 0f             	and    $0xf,%edx
    1303:	03 0c 96             	add    (%rsi,%rdx,4),%ecx
    1306:	48 83 c0 01          	add    $0x1,%rax
    130a:	48 39 f8             	cmp    %rdi,%rax
    130d:	75 ee                	jne    12fd <phase_5+0x21>
    130f:	83 f9 3b             	cmp    $0x3b,%ecx
    1312:	74 05                	je     1319 <phase_5+0x3d>
    1314:	e8 b1 04 00 00       	callq  17ca <explode_bomb>
    1319:	5b                   	pop    %rbx
    131a:	c3                   	retq   
    131b:	e8 aa 04 00 00       	callq  17ca <explode_bomb>
    1320:	eb c8                	jmp    12ea <phase_5+0xe>

0000000000001322 <sig_handler>:
    1322:	48 83 ec 08          	sub    $0x8,%rsp
    1326:	48 8d 3d f3 14 00 00 	lea    0x14f3(%rip),%rdi        # 2820 <array.3415+0x40>
    132d:	e8 de f9 ff ff       	callq  d10 <puts@plt>
    1332:	bf 03 00 00 00       	mov    $0x3,%edi
    1337:	e8 14 fb ff ff       	callq  e50 <sleep@plt>
    133c:	48 8d 35 7e 16 00 00 	lea    0x167e(%rip),%rsi        # 29c1 <array.3415+0x1e1>
    1343:	bf 01 00 00 00       	mov    $0x1,%edi
    1348:	b8 00 00 00 00       	mov    $0x0,%eax
    134d:	e8 9e fa ff ff       	callq  df0 <__printf_chk@plt>
    1352:	48 8b 3d e7 30 20 00 	mov    0x2030e7(%rip),%rdi        # 204440 <stdout@@GLIBC_2.2.5>
    1359:	e8 72 fa ff ff       	callq  dd0 <fflush@plt>
    135e:	bf 01 00 00 00       	mov    $0x1,%edi
    1363:	e8 e8 fa ff ff       	callq  e50 <sleep@plt>
    1368:	48 8d 3d 5a 16 00 00 	lea    0x165a(%rip),%rdi        # 29c9 <array.3415+0x1e9>
    136f:	e8 9c f9 ff ff       	callq  d10 <puts@plt>
    1374:	bf 10 00 00 00       	mov    $0x10,%edi
    1379:	e8 a2 fa ff ff       	callq  e20 <exit@plt>

000000000000137e <invalid_phase>:
    137e:	48 83 ec 08          	sub    $0x8,%rsp
    1382:	48 89 fa             	mov    %rdi,%rdx
    1385:	48 8d 35 45 16 00 00 	lea    0x1645(%rip),%rsi        # 29d1 <array.3415+0x1f1>
    138c:	bf 01 00 00 00       	mov    $0x1,%edi
    1391:	b8 00 00 00 00       	mov    $0x0,%eax
    1396:	e8 55 fa ff ff       	callq  df0 <__printf_chk@plt>
    139b:	bf 08 00 00 00       	mov    $0x8,%edi
    13a0:	e8 7b fa ff ff       	callq  e20 <exit@plt>

00000000000013a5 <string_length>:
    13a5:	80 3f 00             	cmpb   $0x0,(%rdi)
    13a8:	74 12                	je     13bc <string_length+0x17>
    13aa:	48 89 fa             	mov    %rdi,%rdx
    13ad:	48 83 c2 01          	add    $0x1,%rdx
    13b1:	89 d0                	mov    %edx,%eax
    13b3:	29 f8                	sub    %edi,%eax
    13b5:	80 3a 00             	cmpb   $0x0,(%rdx)
    13b8:	75 f3                	jne    13ad <string_length+0x8>
    13ba:	f3 c3                	repz retq 
    13bc:	b8 00 00 00 00       	mov    $0x0,%eax
    13c1:	c3                   	retq   

00000000000013c2 <strings_not_equal>:
    13c2:	41 54                	push   %r12
    13c4:	55                   	push   %rbp
    13c5:	53                   	push   %rbx
    13c6:	48 89 fb             	mov    %rdi,%rbx
    13c9:	48 89 f5             	mov    %rsi,%rbp
    13cc:	e8 d4 ff ff ff       	callq  13a5 <string_length>
    13d1:	41 89 c4             	mov    %eax,%r12d
    13d4:	48 89 ef             	mov    %rbp,%rdi
    13d7:	e8 c9 ff ff ff       	callq  13a5 <string_length>
    13dc:	ba 01 00 00 00       	mov    $0x1,%edx
    13e1:	41 39 c4             	cmp    %eax,%r12d
    13e4:	74 07                	je     13ed <strings_not_equal+0x2b>
    13e6:	89 d0                	mov    %edx,%eax
    13e8:	5b                   	pop    %rbx
    13e9:	5d                   	pop    %rbp
    13ea:	41 5c                	pop    %r12
    13ec:	c3                   	retq   
    13ed:	0f b6 03             	movzbl (%rbx),%eax
    13f0:	84 c0                	test   %al,%al
    13f2:	74 27                	je     141b <strings_not_equal+0x59>
    13f4:	3a 45 00             	cmp    0x0(%rbp),%al
    13f7:	75 29                	jne    1422 <strings_not_equal+0x60>
    13f9:	48 83 c3 01          	add    $0x1,%rbx
    13fd:	48 83 c5 01          	add    $0x1,%rbp
    1401:	0f b6 03             	movzbl (%rbx),%eax
    1404:	84 c0                	test   %al,%al
    1406:	74 0c                	je     1414 <strings_not_equal+0x52>
    1408:	38 45 00             	cmp    %al,0x0(%rbp)
    140b:	74 ec                	je     13f9 <strings_not_equal+0x37>
    140d:	ba 01 00 00 00       	mov    $0x1,%edx
    1412:	eb d2                	jmp    13e6 <strings_not_equal+0x24>
    1414:	ba 00 00 00 00       	mov    $0x0,%edx
    1419:	eb cb                	jmp    13e6 <strings_not_equal+0x24>
    141b:	ba 00 00 00 00       	mov    $0x0,%edx
    1420:	eb c4                	jmp    13e6 <strings_not_equal+0x24>
    1422:	ba 01 00 00 00       	mov    $0x1,%edx
    1427:	eb bd                	jmp    13e6 <strings_not_equal+0x24>

0000000000001429 <hostname_to_ip>:
    1429:	53                   	push   %rbx
    142a:	48 89 f3             	mov    %rsi,%rbx
    142d:	e8 6e f9 ff ff       	callq  da0 <gethostbyname@plt>
    1432:	ba 01 00 00 00       	mov    $0x1,%edx
    1437:	48 85 c0             	test   %rax,%rax
    143a:	74 23                	je     145f <hostname_to_ip+0x36>
    143c:	48 8b 40 18          	mov    0x18(%rax),%rax
    1440:	48 8b 00             	mov    (%rax),%rax
    1443:	48 85 c0             	test   %rax,%rax
    1446:	74 17                	je     145f <hostname_to_ip+0x36>
    1448:	8b 38                	mov    (%rax),%edi
    144a:	e8 e1 f8 ff ff       	callq  d30 <inet_ntoa@plt>
    144f:	48 89 c6             	mov    %rax,%rsi
    1452:	48 89 df             	mov    %rbx,%rdi
    1455:	e8 a6 f8 ff ff       	callq  d00 <strcpy@plt>
    145a:	ba 00 00 00 00       	mov    $0x0,%edx
    145f:	89 d0                	mov    %edx,%eax
    1461:	5b                   	pop    %rbx
    1462:	c3                   	retq   

0000000000001463 <hostname_to_netid>:
    1463:	55                   	push   %rbp
    1464:	53                   	push   %rbx
    1465:	48 83 ec 08          	sub    $0x8,%rsp
    1469:	48 89 f5             	mov    %rsi,%rbp
    146c:	89 d3                	mov    %edx,%ebx
    146e:	e8 2d f9 ff ff       	callq  da0 <gethostbyname@plt>
    1473:	ba 01 00 00 00       	mov    $0x1,%edx
    1478:	48 85 c0             	test   %rax,%rax
    147b:	74 2a                	je     14a7 <hostname_to_netid+0x44>
    147d:	48 8b 48 18          	mov    0x18(%rax),%rcx
    1481:	48 8b 01             	mov    (%rcx),%rax
    1484:	48 85 c0             	test   %rax,%rax
    1487:	74 1e                	je     14a7 <hostname_to_netid+0x44>
    1489:	0f cb                	bswap  %ebx
    148b:	21 18                	and    %ebx,(%rax)
    148d:	48 8b 01             	mov    (%rcx),%rax
    1490:	8b 38                	mov    (%rax),%edi
    1492:	e8 99 f8 ff ff       	callq  d30 <inet_ntoa@plt>
    1497:	48 89 c6             	mov    %rax,%rsi
    149a:	48 89 ef             	mov    %rbp,%rdi
    149d:	e8 5e f8 ff ff       	callq  d00 <strcpy@plt>
    14a2:	ba 00 00 00 00       	mov    $0x0,%edx
    14a7:	89 d0                	mov    %edx,%eax
    14a9:	48 83 c4 08          	add    $0x8,%rsp
    14ad:	5b                   	pop    %rbx
    14ae:	5d                   	pop    %rbp
    14af:	c3                   	retq   

00000000000014b0 <valid_host_netid>:
    14b0:	48 83 ec 58          	sub    $0x58,%rsp
    14b4:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    14bb:	00 00 
    14bd:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
    14c2:	31 c0                	xor    %eax,%eax
    14c4:	48 89 e6             	mov    %rsp,%rsi
    14c7:	ba 00 f0 ff ff       	mov    $0xfffff000,%edx
    14cc:	e8 92 ff ff ff       	callq  1463 <hostname_to_netid>
    14d1:	85 c0                	test   %eax,%eax
    14d3:	75 31                	jne    1506 <valid_host_netid+0x56>
    14d5:	48 89 e7             	mov    %rsp,%rdi
    14d8:	ba 0a 00 00 00       	mov    $0xa,%edx
    14dd:	48 8d 35 fe 14 00 00 	lea    0x14fe(%rip),%rsi        # 29e2 <array.3415+0x202>
    14e4:	e8 d7 f8 ff ff       	callq  dc0 <strncasecmp@plt>
    14e9:	85 c0                	test   %eax,%eax
    14eb:	0f 94 c0             	sete   %al
    14ee:	0f b6 c0             	movzbl %al,%eax
    14f1:	48 8b 4c 24 48       	mov    0x48(%rsp),%rcx
    14f6:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    14fd:	00 00 
    14ff:	75 1b                	jne    151c <valid_host_netid+0x6c>
    1501:	48 83 c4 58          	add    $0x58,%rsp
    1505:	c3                   	retq   
    1506:	48 8d 3d 4b 13 00 00 	lea    0x134b(%rip),%rdi        # 2858 <array.3415+0x78>
    150d:	e8 fe f7 ff ff       	callq  d10 <puts@plt>
    1512:	bf 08 00 00 00       	mov    $0x8,%edi
    1517:	e8 04 f9 ff ff       	callq  e20 <exit@plt>
    151c:	e8 1f f8 ff ff       	callq  d40 <__stack_chk_fail@plt>

0000000000001521 <initialize_bomb>:
    1521:	55                   	push   %rbp
    1522:	53                   	push   %rbx
    1523:	48 81 ec 58 20 00 00 	sub    $0x2058,%rsp
    152a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1531:	00 00 
    1533:	48 89 84 24 48 20 00 	mov    %rax,0x2048(%rsp)
    153a:	00 
    153b:	31 c0                	xor    %eax,%eax
    153d:	48 8d 35 de fd ff ff 	lea    -0x222(%rip),%rsi        # 1322 <sig_handler>
    1544:	bf 02 00 00 00       	mov    $0x2,%edi
    1549:	e8 42 f8 ff ff       	callq  d90 <signal@plt>
    154e:	48 89 e7             	mov    %rsp,%rdi
    1551:	be 40 00 00 00       	mov    $0x40,%esi
    1556:	e8 b5 f8 ff ff       	callq  e10 <gethostname@plt>
    155b:	85 c0                	test   %eax,%eax
    155d:	75 66                	jne    15c5 <initialize_bomb+0xa4>
    155f:	48 8b 3d da 2a 20 00 	mov    0x202ada(%rip),%rdi        # 204040 <host_table>
    1566:	48 8d 1d db 2a 20 00 	lea    0x202adb(%rip),%rbx        # 204048 <host_table+0x8>
    156d:	48 89 e5             	mov    %rsp,%rbp
    1570:	48 85 ff             	test   %rdi,%rdi
    1573:	74 19                	je     158e <initialize_bomb+0x6d>
    1575:	48 89 ee             	mov    %rbp,%rsi
    1578:	e8 63 f7 ff ff       	callq  ce0 <strcasecmp@plt>
    157d:	85 c0                	test   %eax,%eax
    157f:	74 19                	je     159a <initialize_bomb+0x79>
    1581:	48 83 c3 08          	add    $0x8,%rbx
    1585:	48 8b 7b f8          	mov    -0x8(%rbx),%rdi
    1589:	48 85 ff             	test   %rdi,%rdi
    158c:	75 e7                	jne    1575 <initialize_bomb+0x54>
    158e:	48 89 e7             	mov    %rsp,%rdi
    1591:	e8 1a ff ff ff       	callq  14b0 <valid_host_netid>
    1596:	85 c0                	test   %eax,%eax
    1598:	74 41                	je     15db <initialize_bomb+0xba>
    159a:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
    159f:	e8 75 0d 00 00       	callq  2319 <init_driver>
    15a4:	85 c0                	test   %eax,%eax
    15a6:	78 49                	js     15f1 <initialize_bomb+0xd0>
    15a8:	48 8b 84 24 48 20 00 	mov    0x2048(%rsp),%rax
    15af:	00 
    15b0:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    15b7:	00 00 
    15b9:	75 5b                	jne    1616 <initialize_bomb+0xf5>
    15bb:	48 81 c4 58 20 00 00 	add    $0x2058,%rsp
    15c2:	5b                   	pop    %rbx
    15c3:	5d                   	pop    %rbp
    15c4:	c3                   	retq   
    15c5:	48 8d 3d c4 12 00 00 	lea    0x12c4(%rip),%rdi        # 2890 <array.3415+0xb0>
    15cc:	e8 3f f7 ff ff       	callq  d10 <puts@plt>
    15d1:	bf 08 00 00 00       	mov    $0x8,%edi
    15d6:	e8 45 f8 ff ff       	callq  e20 <exit@plt>
    15db:	48 8d 3d e6 12 00 00 	lea    0x12e6(%rip),%rdi        # 28c8 <array.3415+0xe8>
    15e2:	e8 29 f7 ff ff       	callq  d10 <puts@plt>
    15e7:	bf 08 00 00 00       	mov    $0x8,%edi
    15ec:	e8 2f f8 ff ff       	callq  e20 <exit@plt>
    15f1:	48 8d 54 24 40       	lea    0x40(%rsp),%rdx
    15f6:	48 8d 35 f0 13 00 00 	lea    0x13f0(%rip),%rsi        # 29ed <array.3415+0x20d>
    15fd:	bf 01 00 00 00       	mov    $0x1,%edi
    1602:	b8 00 00 00 00       	mov    $0x0,%eax
    1607:	e8 e4 f7 ff ff       	callq  df0 <__printf_chk@plt>
    160c:	bf 08 00 00 00       	mov    $0x8,%edi
    1611:	e8 0a f8 ff ff       	callq  e20 <exit@plt>
    1616:	e8 25 f7 ff ff       	callq  d40 <__stack_chk_fail@plt>

000000000000161b <initialize_bomb_solve>:
    161b:	f3 c3                	repz retq 

000000000000161d <blank_line>:
    161d:	55                   	push   %rbp
    161e:	53                   	push   %rbx
    161f:	48 83 ec 08          	sub    $0x8,%rsp
    1623:	48 89 fd             	mov    %rdi,%rbp
    1626:	0f b6 5d 00          	movzbl 0x0(%rbp),%ebx
    162a:	84 db                	test   %bl,%bl
    162c:	74 1e                	je     164c <blank_line+0x2f>
    162e:	e8 2d f8 ff ff       	callq  e60 <__ctype_b_loc@plt>
    1633:	48 83 c5 01          	add    $0x1,%rbp
    1637:	48 0f be db          	movsbq %bl,%rbx
    163b:	48 8b 00             	mov    (%rax),%rax
    163e:	f6 44 58 01 20       	testb  $0x20,0x1(%rax,%rbx,2)
    1643:	75 e1                	jne    1626 <blank_line+0x9>
    1645:	b8 00 00 00 00       	mov    $0x0,%eax
    164a:	eb 05                	jmp    1651 <blank_line+0x34>
    164c:	b8 01 00 00 00       	mov    $0x1,%eax
    1651:	48 83 c4 08          	add    $0x8,%rsp
    1655:	5b                   	pop    %rbx
    1656:	5d                   	pop    %rbp
    1657:	c3                   	retq   

0000000000001658 <skip>:
    1658:	55                   	push   %rbp
    1659:	53                   	push   %rbx
    165a:	48 83 ec 08          	sub    $0x8,%rsp
    165e:	48 8d 2d 1b 2e 20 00 	lea    0x202e1b(%rip),%rbp        # 204480 <input_strings>
    1665:	48 63 05 00 2e 20 00 	movslq 0x202e00(%rip),%rax        # 20446c <num_input_strings>
    166c:	48 8d 3c 80          	lea    (%rax,%rax,4),%rdi
    1670:	48 c1 e7 04          	shl    $0x4,%rdi
    1674:	48 01 ef             	add    %rbp,%rdi
    1677:	48 8b 15 f2 2d 20 00 	mov    0x202df2(%rip),%rdx        # 204470 <infile>
    167e:	be 50 00 00 00       	mov    $0x50,%esi
    1683:	e8 f8 f6 ff ff       	callq  d80 <fgets@plt>
    1688:	48 89 c3             	mov    %rax,%rbx
    168b:	48 85 c0             	test   %rax,%rax
    168e:	74 0c                	je     169c <skip+0x44>
    1690:	48 89 c7             	mov    %rax,%rdi
    1693:	e8 85 ff ff ff       	callq  161d <blank_line>
    1698:	85 c0                	test   %eax,%eax
    169a:	75 c9                	jne    1665 <skip+0xd>
    169c:	48 89 d8             	mov    %rbx,%rax
    169f:	48 83 c4 08          	add    $0x8,%rsp
    16a3:	5b                   	pop    %rbx
    16a4:	5d                   	pop    %rbp
    16a5:	c3                   	retq   

00000000000016a6 <send_msg>:
    16a6:	53                   	push   %rbx
    16a7:	48 81 ec 10 40 00 00 	sub    $0x4010,%rsp
    16ae:	41 89 f8             	mov    %edi,%r8d
    16b1:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    16b8:	00 00 
    16ba:	48 89 84 24 08 40 00 	mov    %rax,0x4008(%rsp)
    16c1:	00 
    16c2:	31 c0                	xor    %eax,%eax
    16c4:	8b 35 a2 2d 20 00    	mov    0x202da2(%rip),%esi        # 20446c <num_input_strings>
    16ca:	8d 46 ff             	lea    -0x1(%rsi),%eax
    16cd:	48 98                	cltq   
    16cf:	48 8d 14 80          	lea    (%rax,%rax,4),%rdx
    16d3:	48 c1 e2 04          	shl    $0x4,%rdx
    16d7:	48 8d 05 a2 2d 20 00 	lea    0x202da2(%rip),%rax        # 204480 <input_strings>
    16de:	48 01 c2             	add    %rax,%rdx
    16e1:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
    16e8:	b8 00 00 00 00       	mov    $0x0,%eax
    16ed:	48 89 d7             	mov    %rdx,%rdi
    16f0:	f2 ae                	repnz scas %es:(%rdi),%al
    16f2:	48 89 c8             	mov    %rcx,%rax
    16f5:	48 f7 d0             	not    %rax
    16f8:	48 83 c0 63          	add    $0x63,%rax
    16fc:	48 3d 00 20 00 00    	cmp    $0x2000,%rax
    1702:	0f 87 86 00 00 00    	ja     178e <send_msg+0xe8>
    1708:	45 85 c0             	test   %r8d,%r8d
    170b:	4c 8d 0d f5 12 00 00 	lea    0x12f5(%rip),%r9        # 2a07 <array.3415+0x227>
    1712:	48 8d 05 f6 12 00 00 	lea    0x12f6(%rip),%rax        # 2a0f <array.3415+0x22f>
    1719:	4c 0f 44 c8          	cmove  %rax,%r9
    171d:	48 89 e3             	mov    %rsp,%rbx
    1720:	52                   	push   %rdx
    1721:	56                   	push   %rsi
    1722:	44 8b 05 07 29 20 00 	mov    0x202907(%rip),%r8d        # 204030 <bomb_id>
    1729:	48 8d 0d e8 12 00 00 	lea    0x12e8(%rip),%rcx        # 2a18 <array.3415+0x238>
    1730:	ba 00 20 00 00       	mov    $0x2000,%edx
    1735:	be 01 00 00 00       	mov    $0x1,%esi
    173a:	48 89 df             	mov    %rbx,%rdi
    173d:	b8 00 00 00 00       	mov    $0x0,%eax
    1742:	e8 29 f7 ff ff       	callq  e70 <__sprintf_chk@plt>
    1747:	4c 8d 84 24 10 20 00 	lea    0x2010(%rsp),%r8
    174e:	00 
    174f:	b9 00 00 00 00       	mov    $0x0,%ecx
    1754:	48 89 da             	mov    %rbx,%rdx
    1757:	48 8d 35 b2 28 20 00 	lea    0x2028b2(%rip),%rsi        # 204010 <user_password>
    175e:	48 8d 3d c3 28 20 00 	lea    0x2028c3(%rip),%rdi        # 204028 <userid>
    1765:	e8 b8 0d 00 00       	callq  2522 <driver_post>
    176a:	48 83 c4 10          	add    $0x10,%rsp
    176e:	85 c0                	test   %eax,%eax
    1770:	78 3c                	js     17ae <send_msg+0x108>
    1772:	48 8b 84 24 08 40 00 	mov    0x4008(%rsp),%rax
    1779:	00 
    177a:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1781:	00 00 
    1783:	75 40                	jne    17c5 <send_msg+0x11f>
    1785:	48 81 c4 10 40 00 00 	add    $0x4010,%rsp
    178c:	5b                   	pop    %rbx
    178d:	c3                   	retq   
    178e:	48 8d 35 6b 11 00 00 	lea    0x116b(%rip),%rsi        # 2900 <array.3415+0x120>
    1795:	bf 01 00 00 00       	mov    $0x1,%edi
    179a:	b8 00 00 00 00       	mov    $0x0,%eax
    179f:	e8 4c f6 ff ff       	callq  df0 <__printf_chk@plt>
    17a4:	bf 08 00 00 00       	mov    $0x8,%edi
    17a9:	e8 72 f6 ff ff       	callq  e20 <exit@plt>
    17ae:	48 8d bc 24 00 20 00 	lea    0x2000(%rsp),%rdi
    17b5:	00 
    17b6:	e8 55 f5 ff ff       	callq  d10 <puts@plt>
    17bb:	bf 00 00 00 00       	mov    $0x0,%edi
    17c0:	e8 5b f6 ff ff       	callq  e20 <exit@plt>
    17c5:	e8 76 f5 ff ff       	callq  d40 <__stack_chk_fail@plt>

00000000000017ca <explode_bomb>:
    17ca:	48 83 ec 08          	sub    $0x8,%rsp
    17ce:	48 8d 3d 4f 12 00 00 	lea    0x124f(%rip),%rdi        # 2a24 <array.3415+0x244>
    17d5:	e8 36 f5 ff ff       	callq  d10 <puts@plt>
    17da:	48 8d 3d 4c 12 00 00 	lea    0x124c(%rip),%rdi        # 2a2d <array.3415+0x24d>
    17e1:	e8 2a f5 ff ff       	callq  d10 <puts@plt>
    17e6:	bf 00 00 00 00       	mov    $0x0,%edi
    17eb:	e8 b6 fe ff ff       	callq  16a6 <send_msg>
    17f0:	48 8d 3d 31 11 00 00 	lea    0x1131(%rip),%rdi        # 2928 <array.3415+0x148>
    17f7:	e8 14 f5 ff ff       	callq  d10 <puts@plt>
    17fc:	bf 08 00 00 00       	mov    $0x8,%edi
    1801:	e8 1a f6 ff ff       	callq  e20 <exit@plt>

0000000000001806 <read_six_numbers>:
    1806:	48 83 ec 08          	sub    $0x8,%rsp
    180a:	48 89 f2             	mov    %rsi,%rdx
    180d:	48 8d 4e 04          	lea    0x4(%rsi),%rcx
    1811:	48 8d 46 14          	lea    0x14(%rsi),%rax
    1815:	50                   	push   %rax
    1816:	48 8d 46 10          	lea    0x10(%rsi),%rax
    181a:	50                   	push   %rax
    181b:	4c 8d 4e 0c          	lea    0xc(%rsi),%r9
    181f:	4c 8d 46 08          	lea    0x8(%rsi),%r8
    1823:	48 8d 35 1a 12 00 00 	lea    0x121a(%rip),%rsi        # 2a44 <array.3415+0x264>
    182a:	b8 00 00 00 00       	mov    $0x0,%eax
    182f:	e8 ac f5 ff ff       	callq  de0 <__isoc99_sscanf@plt>
    1834:	48 83 c4 10          	add    $0x10,%rsp
    1838:	83 f8 05             	cmp    $0x5,%eax
    183b:	7e 05                	jle    1842 <read_six_numbers+0x3c>
    183d:	48 83 c4 08          	add    $0x8,%rsp
    1841:	c3                   	retq   
    1842:	e8 83 ff ff ff       	callq  17ca <explode_bomb>

0000000000001847 <read_line>:
    1847:	48 83 ec 08          	sub    $0x8,%rsp
    184b:	b8 00 00 00 00       	mov    $0x0,%eax
    1850:	e8 03 fe ff ff       	callq  1658 <skip>
    1855:	48 85 c0             	test   %rax,%rax
    1858:	74 6f                	je     18c9 <read_line+0x82>
    185a:	8b 35 0c 2c 20 00    	mov    0x202c0c(%rip),%esi        # 20446c <num_input_strings>
    1860:	48 63 c6             	movslq %esi,%rax
    1863:	48 8d 14 80          	lea    (%rax,%rax,4),%rdx
    1867:	48 c1 e2 04          	shl    $0x4,%rdx
    186b:	48 8d 05 0e 2c 20 00 	lea    0x202c0e(%rip),%rax        # 204480 <input_strings>
    1872:	48 01 c2             	add    %rax,%rdx
    1875:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
    187c:	b8 00 00 00 00       	mov    $0x0,%eax
    1881:	48 89 d7             	mov    %rdx,%rdi
    1884:	f2 ae                	repnz scas %es:(%rdi),%al
    1886:	48 f7 d1             	not    %rcx
    1889:	48 83 e9 01          	sub    $0x1,%rcx
    188d:	83 f9 4e             	cmp    $0x4e,%ecx
    1890:	0f 8f ab 00 00 00    	jg     1941 <read_line+0xfa>
    1896:	83 e9 01             	sub    $0x1,%ecx
    1899:	48 63 c9             	movslq %ecx,%rcx
    189c:	48 63 c6             	movslq %esi,%rax
    189f:	48 8d 04 80          	lea    (%rax,%rax,4),%rax
    18a3:	48 c1 e0 04          	shl    $0x4,%rax
    18a7:	48 89 c7             	mov    %rax,%rdi
    18aa:	48 8d 05 cf 2b 20 00 	lea    0x202bcf(%rip),%rax        # 204480 <input_strings>
    18b1:	48 01 f8             	add    %rdi,%rax
    18b4:	c6 04 08 00          	movb   $0x0,(%rax,%rcx,1)
    18b8:	83 c6 01             	add    $0x1,%esi
    18bb:	89 35 ab 2b 20 00    	mov    %esi,0x202bab(%rip)        # 20446c <num_input_strings>
    18c1:	48 89 d0             	mov    %rdx,%rax
    18c4:	48 83 c4 08          	add    $0x8,%rsp
    18c8:	c3                   	retq   
    18c9:	48 8b 05 80 2b 20 00 	mov    0x202b80(%rip),%rax        # 204450 <stdin@@GLIBC_2.2.5>
    18d0:	48 39 05 99 2b 20 00 	cmp    %rax,0x202b99(%rip)        # 204470 <infile>
    18d7:	74 1b                	je     18f4 <read_line+0xad>
    18d9:	48 8d 3d 94 11 00 00 	lea    0x1194(%rip),%rdi        # 2a74 <array.3415+0x294>
    18e0:	e8 eb f3 ff ff       	callq  cd0 <getenv@plt>
    18e5:	48 85 c0             	test   %rax,%rax
    18e8:	74 20                	je     190a <read_line+0xc3>
    18ea:	bf 00 00 00 00       	mov    $0x0,%edi
    18ef:	e8 2c f5 ff ff       	callq  e20 <exit@plt>
    18f4:	48 8d 3d 5b 11 00 00 	lea    0x115b(%rip),%rdi        # 2a56 <array.3415+0x276>
    18fb:	e8 10 f4 ff ff       	callq  d10 <puts@plt>
    1900:	bf 08 00 00 00       	mov    $0x8,%edi
    1905:	e8 16 f5 ff ff       	callq  e20 <exit@plt>
    190a:	48 8b 05 3f 2b 20 00 	mov    0x202b3f(%rip),%rax        # 204450 <stdin@@GLIBC_2.2.5>
    1911:	48 89 05 58 2b 20 00 	mov    %rax,0x202b58(%rip)        # 204470 <infile>
    1918:	b8 00 00 00 00       	mov    $0x0,%eax
    191d:	e8 36 fd ff ff       	callq  1658 <skip>
    1922:	48 85 c0             	test   %rax,%rax
    1925:	0f 85 2f ff ff ff    	jne    185a <read_line+0x13>
    192b:	48 8d 3d 24 11 00 00 	lea    0x1124(%rip),%rdi        # 2a56 <array.3415+0x276>
    1932:	e8 d9 f3 ff ff       	callq  d10 <puts@plt>
    1937:	bf 00 00 00 00       	mov    $0x0,%edi
    193c:	e8 df f4 ff ff       	callq  e20 <exit@plt>
    1941:	48 8d 3d 37 11 00 00 	lea    0x1137(%rip),%rdi        # 2a7f <array.3415+0x29f>
    1948:	e8 c3 f3 ff ff       	callq  d10 <puts@plt>
    194d:	8b 05 19 2b 20 00    	mov    0x202b19(%rip),%eax        # 20446c <num_input_strings>
    1953:	8d 50 01             	lea    0x1(%rax),%edx
    1956:	89 15 10 2b 20 00    	mov    %edx,0x202b10(%rip)        # 20446c <num_input_strings>
    195c:	48 98                	cltq   
    195e:	48 6b c0 50          	imul   $0x50,%rax,%rax
    1962:	48 8d 15 17 2b 20 00 	lea    0x202b17(%rip),%rdx        # 204480 <input_strings>
    1969:	48 be 2a 2a 2a 74 72 	movabs $0x636e7572742a2a2a,%rsi
    1970:	75 6e 63 
    1973:	48 bf 61 74 65 64 2a 	movabs $0x2a2a2a64657461,%rdi
    197a:	2a 2a 00 
    197d:	48 89 34 02          	mov    %rsi,(%rdx,%rax,1)
    1981:	48 89 7c 02 08       	mov    %rdi,0x8(%rdx,%rax,1)
    1986:	e8 3f fe ff ff       	callq  17ca <explode_bomb>

000000000000198b <phase_defused>:
    198b:	48 83 ec 08          	sub    $0x8,%rsp
    198f:	bf 01 00 00 00       	mov    $0x1,%edi
    1994:	e8 0d fd ff ff       	callq  16a6 <send_msg>
    1999:	83 3d cc 2a 20 00 05 	cmpl   $0x5,0x202acc(%rip)        # 20446c <num_input_strings>
    19a0:	74 05                	je     19a7 <phase_defused+0x1c>
    19a2:	48 83 c4 08          	add    $0x8,%rsp
    19a6:	c3                   	retq   
    19a7:	48 8d 3d a2 0f 00 00 	lea    0xfa2(%rip),%rdi        # 2950 <array.3415+0x170>
    19ae:	e8 5d f3 ff ff       	callq  d10 <puts@plt>
    19b3:	48 8d 3d c6 0f 00 00 	lea    0xfc6(%rip),%rdi        # 2980 <array.3415+0x1a0>
    19ba:	e8 51 f3 ff ff       	callq  d10 <puts@plt>
    19bf:	eb e1                	jmp    19a2 <phase_defused+0x17>

00000000000019c1 <sigalrm_handler>:
    19c1:	48 83 ec 08          	sub    $0x8,%rsp
    19c5:	b9 00 00 00 00       	mov    $0x0,%ecx
    19ca:	48 8d 15 d7 10 00 00 	lea    0x10d7(%rip),%rdx        # 2aa8 <array.3415+0x2c8>
    19d1:	be 01 00 00 00       	mov    $0x1,%esi
    19d6:	48 8b 3d 83 2a 20 00 	mov    0x202a83(%rip),%rdi        # 204460 <stderr@@GLIBC_2.2.5>
    19dd:	b8 00 00 00 00       	mov    $0x0,%eax
    19e2:	e8 59 f4 ff ff       	callq  e40 <__fprintf_chk@plt>
    19e7:	bf 01 00 00 00       	mov    $0x1,%edi
    19ec:	e8 2f f4 ff ff       	callq  e20 <exit@plt>

00000000000019f1 <rio_readlineb>:
    19f1:	41 56                	push   %r14
    19f3:	41 55                	push   %r13
    19f5:	41 54                	push   %r12
    19f7:	55                   	push   %rbp
    19f8:	53                   	push   %rbx
    19f9:	48 89 fb             	mov    %rdi,%rbx
    19fc:	49 89 f4             	mov    %rsi,%r12
    19ff:	49 89 d6             	mov    %rdx,%r14
    1a02:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    1a08:	48 8d 6f 10          	lea    0x10(%rdi),%rbp
    1a0c:	48 83 fa 01          	cmp    $0x1,%rdx
    1a10:	77 0c                	ja     1a1e <rio_readlineb+0x2d>
    1a12:	eb 60                	jmp    1a74 <rio_readlineb+0x83>
    1a14:	e8 d7 f2 ff ff       	callq  cf0 <__errno_location@plt>
    1a19:	83 38 04             	cmpl   $0x4,(%rax)
    1a1c:	75 67                	jne    1a85 <rio_readlineb+0x94>
    1a1e:	8b 43 04             	mov    0x4(%rbx),%eax
    1a21:	85 c0                	test   %eax,%eax
    1a23:	7f 20                	jg     1a45 <rio_readlineb+0x54>
    1a25:	ba 00 20 00 00       	mov    $0x2000,%edx
    1a2a:	48 89 ee             	mov    %rbp,%rsi
    1a2d:	8b 3b                	mov    (%rbx),%edi
    1a2f:	e8 3c f3 ff ff       	callq  d70 <read@plt>
    1a34:	89 43 04             	mov    %eax,0x4(%rbx)
    1a37:	85 c0                	test   %eax,%eax
    1a39:	78 d9                	js     1a14 <rio_readlineb+0x23>
    1a3b:	85 c0                	test   %eax,%eax
    1a3d:	74 4f                	je     1a8e <rio_readlineb+0x9d>
    1a3f:	48 89 6b 08          	mov    %rbp,0x8(%rbx)
    1a43:	eb d9                	jmp    1a1e <rio_readlineb+0x2d>
    1a45:	48 8b 53 08          	mov    0x8(%rbx),%rdx
    1a49:	0f b6 0a             	movzbl (%rdx),%ecx
    1a4c:	48 83 c2 01          	add    $0x1,%rdx
    1a50:	48 89 53 08          	mov    %rdx,0x8(%rbx)
    1a54:	83 e8 01             	sub    $0x1,%eax
    1a57:	89 43 04             	mov    %eax,0x4(%rbx)
    1a5a:	49 83 c4 01          	add    $0x1,%r12
    1a5e:	41 88 4c 24 ff       	mov    %cl,-0x1(%r12)
    1a63:	80 f9 0a             	cmp    $0xa,%cl
    1a66:	74 0c                	je     1a74 <rio_readlineb+0x83>
    1a68:	41 83 c5 01          	add    $0x1,%r13d
    1a6c:	49 63 c5             	movslq %r13d,%rax
    1a6f:	4c 39 f0             	cmp    %r14,%rax
    1a72:	72 aa                	jb     1a1e <rio_readlineb+0x2d>
    1a74:	41 c6 04 24 00       	movb   $0x0,(%r12)
    1a79:	49 63 c5             	movslq %r13d,%rax
    1a7c:	5b                   	pop    %rbx
    1a7d:	5d                   	pop    %rbp
    1a7e:	41 5c                	pop    %r12
    1a80:	41 5d                	pop    %r13
    1a82:	41 5e                	pop    %r14
    1a84:	c3                   	retq   
    1a85:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    1a8c:	eb 05                	jmp    1a93 <rio_readlineb+0xa2>
    1a8e:	b8 00 00 00 00       	mov    $0x0,%eax
    1a93:	85 c0                	test   %eax,%eax
    1a95:	75 0d                	jne    1aa4 <rio_readlineb+0xb3>
    1a97:	b8 00 00 00 00       	mov    $0x0,%eax
    1a9c:	41 83 fd 01          	cmp    $0x1,%r13d
    1aa0:	75 d2                	jne    1a74 <rio_readlineb+0x83>
    1aa2:	eb d8                	jmp    1a7c <rio_readlineb+0x8b>
    1aa4:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    1aab:	eb cf                	jmp    1a7c <rio_readlineb+0x8b>

0000000000001aad <submitr>:
    1aad:	41 57                	push   %r15
    1aaf:	41 56                	push   %r14
    1ab1:	41 55                	push   %r13
    1ab3:	41 54                	push   %r12
    1ab5:	55                   	push   %rbp
    1ab6:	53                   	push   %rbx
    1ab7:	48 81 ec 78 a0 00 00 	sub    $0xa078,%rsp
    1abe:	49 89 fd             	mov    %rdi,%r13
    1ac1:	89 f5                	mov    %esi,%ebp
    1ac3:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
    1ac8:	48 89 4c 24 10       	mov    %rcx,0x10(%rsp)
    1acd:	4c 89 44 24 20       	mov    %r8,0x20(%rsp)
    1ad2:	4c 89 4c 24 18       	mov    %r9,0x18(%rsp)
    1ad7:	48 8b 9c 24 b0 a0 00 	mov    0xa0b0(%rsp),%rbx
    1ade:	00 
    1adf:	4c 8b bc 24 b8 a0 00 	mov    0xa0b8(%rsp),%r15
    1ae6:	00 
    1ae7:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1aee:	00 00 
    1af0:	48 89 84 24 68 a0 00 	mov    %rax,0xa068(%rsp)
    1af7:	00 
    1af8:	31 c0                	xor    %eax,%eax
    1afa:	c7 44 24 3c 00 00 00 	movl   $0x0,0x3c(%rsp)
    1b01:	00 
    1b02:	ba 00 00 00 00       	mov    $0x0,%edx
    1b07:	be 01 00 00 00       	mov    $0x1,%esi
    1b0c:	bf 02 00 00 00       	mov    $0x2,%edi
    1b11:	e8 6a f3 ff ff       	callq  e80 <socket@plt>
    1b16:	85 c0                	test   %eax,%eax
    1b18:	0f 88 35 01 00 00    	js     1c53 <submitr+0x1a6>
    1b1e:	41 89 c4             	mov    %eax,%r12d
    1b21:	4c 89 ef             	mov    %r13,%rdi
    1b24:	e8 77 f2 ff ff       	callq  da0 <gethostbyname@plt>
    1b29:	48 85 c0             	test   %rax,%rax
    1b2c:	0f 84 71 01 00 00    	je     1ca3 <submitr+0x1f6>
    1b32:	4c 8d 6c 24 40       	lea    0x40(%rsp),%r13
    1b37:	48 c7 44 24 42 00 00 	movq   $0x0,0x42(%rsp)
    1b3e:	00 00 
    1b40:	c7 44 24 4a 00 00 00 	movl   $0x0,0x4a(%rsp)
    1b47:	00 
    1b48:	66 c7 44 24 4e 00 00 	movw   $0x0,0x4e(%rsp)
    1b4f:	66 c7 44 24 40 02 00 	movw   $0x2,0x40(%rsp)
    1b56:	48 63 50 14          	movslq 0x14(%rax),%rdx
    1b5a:	48 8b 40 18          	mov    0x18(%rax),%rax
    1b5e:	48 8d 7c 24 44       	lea    0x44(%rsp),%rdi
    1b63:	b9 0c 00 00 00       	mov    $0xc,%ecx
    1b68:	48 8b 30             	mov    (%rax),%rsi
    1b6b:	e8 40 f2 ff ff       	callq  db0 <__memmove_chk@plt>
    1b70:	66 c1 cd 08          	ror    $0x8,%bp
    1b74:	66 89 6c 24 42       	mov    %bp,0x42(%rsp)
    1b79:	ba 10 00 00 00       	mov    $0x10,%edx
    1b7e:	4c 89 ee             	mov    %r13,%rsi
    1b81:	44 89 e7             	mov    %r12d,%edi
    1b84:	e8 a7 f2 ff ff       	callq  e30 <connect@plt>
    1b89:	85 c0                	test   %eax,%eax
    1b8b:	0f 88 7d 01 00 00    	js     1d0e <submitr+0x261>
    1b91:	49 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%r9
    1b98:	b8 00 00 00 00       	mov    $0x0,%eax
    1b9d:	4c 89 c9             	mov    %r9,%rcx
    1ba0:	48 89 df             	mov    %rbx,%rdi
    1ba3:	f2 ae                	repnz scas %es:(%rdi),%al
    1ba5:	48 89 ce             	mov    %rcx,%rsi
    1ba8:	48 f7 d6             	not    %rsi
    1bab:	4c 89 c9             	mov    %r9,%rcx
    1bae:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
    1bb3:	f2 ae                	repnz scas %es:(%rdi),%al
    1bb5:	49 89 c8             	mov    %rcx,%r8
    1bb8:	4c 89 c9             	mov    %r9,%rcx
    1bbb:	48 8b 7c 24 10       	mov    0x10(%rsp),%rdi
    1bc0:	f2 ae                	repnz scas %es:(%rdi),%al
    1bc2:	48 89 ca             	mov    %rcx,%rdx
    1bc5:	48 f7 d2             	not    %rdx
    1bc8:	4c 89 c9             	mov    %r9,%rcx
    1bcb:	48 8b 7c 24 18       	mov    0x18(%rsp),%rdi
    1bd0:	f2 ae                	repnz scas %es:(%rdi),%al
    1bd2:	4c 29 c2             	sub    %r8,%rdx
    1bd5:	48 29 ca             	sub    %rcx,%rdx
    1bd8:	48 8d 44 76 fd       	lea    -0x3(%rsi,%rsi,2),%rax
    1bdd:	48 8d 44 02 7b       	lea    0x7b(%rdx,%rax,1),%rax
    1be2:	48 3d 00 20 00 00    	cmp    $0x2000,%rax
    1be8:	0f 87 7d 01 00 00    	ja     1d6b <submitr+0x2be>
    1bee:	48 8d 94 24 60 40 00 	lea    0x4060(%rsp),%rdx
    1bf5:	00 
    1bf6:	b9 00 04 00 00       	mov    $0x400,%ecx
    1bfb:	b8 00 00 00 00       	mov    $0x0,%eax
    1c00:	48 89 d7             	mov    %rdx,%rdi
    1c03:	f3 48 ab             	rep stos %rax,%es:(%rdi)
    1c06:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
    1c0d:	48 89 df             	mov    %rbx,%rdi
    1c10:	f2 ae                	repnz scas %es:(%rdi),%al
    1c12:	48 89 ca             	mov    %rcx,%rdx
    1c15:	48 f7 d2             	not    %rdx
    1c18:	48 89 d1             	mov    %rdx,%rcx
    1c1b:	48 83 e9 01          	sub    $0x1,%rcx
    1c1f:	85 c9                	test   %ecx,%ecx
    1c21:	0f 84 3f 06 00 00    	je     2266 <submitr+0x7b9>
    1c27:	8d 41 ff             	lea    -0x1(%rcx),%eax
    1c2a:	4c 8d 74 03 01       	lea    0x1(%rbx,%rax,1),%r14
    1c2f:	48 8d ac 24 60 40 00 	lea    0x4060(%rsp),%rbp
    1c36:	00 
    1c37:	48 8d 84 24 60 80 00 	lea    0x8060(%rsp),%rax
    1c3e:	00 
    1c3f:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
    1c44:	49 bd d9 ff 00 00 00 	movabs $0x2000000000ffd9,%r13
    1c4b:	00 20 00 
    1c4e:	e9 a6 01 00 00       	jmpq   1df9 <submitr+0x34c>
    1c53:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    1c5a:	3a 20 43 
    1c5d:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    1c64:	20 75 6e 
    1c67:	49 89 07             	mov    %rax,(%r15)
    1c6a:	49 89 57 08          	mov    %rdx,0x8(%r15)
    1c6e:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    1c75:	74 6f 20 
    1c78:	48 ba 63 72 65 61 74 	movabs $0x7320657461657263,%rdx
    1c7f:	65 20 73 
    1c82:	49 89 47 10          	mov    %rax,0x10(%r15)
    1c86:	49 89 57 18          	mov    %rdx,0x18(%r15)
    1c8a:	41 c7 47 20 6f 63 6b 	movl   $0x656b636f,0x20(%r15)
    1c91:	65 
    1c92:	66 41 c7 47 24 74 00 	movw   $0x74,0x24(%r15)
    1c99:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1c9e:	e9 9a 04 00 00       	jmpq   213d <submitr+0x690>
    1ca3:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
    1caa:	3a 20 44 
    1cad:	48 ba 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rdx
    1cb4:	20 75 6e 
    1cb7:	49 89 07             	mov    %rax,(%r15)
    1cba:	49 89 57 08          	mov    %rdx,0x8(%r15)
    1cbe:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    1cc5:	74 6f 20 
    1cc8:	48 ba 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rdx
    1ccf:	76 65 20 
    1cd2:	49 89 47 10          	mov    %rax,0x10(%r15)
    1cd6:	49 89 57 18          	mov    %rdx,0x18(%r15)
    1cda:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
    1ce1:	72 20 61 
    1ce4:	49 89 47 20          	mov    %rax,0x20(%r15)
    1ce8:	41 c7 47 28 64 64 72 	movl   $0x65726464,0x28(%r15)
    1cef:	65 
    1cf0:	66 41 c7 47 2c 73 73 	movw   $0x7373,0x2c(%r15)
    1cf7:	41 c6 47 2e 00       	movb   $0x0,0x2e(%r15)
    1cfc:	44 89 e7             	mov    %r12d,%edi
    1cff:	e8 5c f0 ff ff       	callq  d60 <close@plt>
    1d04:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1d09:	e9 2f 04 00 00       	jmpq   213d <submitr+0x690>
    1d0e:	48 b8 45 72 72 6f 72 	movabs $0x55203a726f727245,%rax
    1d15:	3a 20 55 
    1d18:	48 ba 6e 61 62 6c 65 	movabs $0x6f7420656c62616e,%rdx
    1d1f:	20 74 6f 
    1d22:	49 89 07             	mov    %rax,(%r15)
    1d25:	49 89 57 08          	mov    %rdx,0x8(%r15)
    1d29:	48 b8 20 63 6f 6e 6e 	movabs $0x7463656e6e6f6320,%rax
    1d30:	65 63 74 
    1d33:	48 ba 20 74 6f 20 74 	movabs $0x20656874206f7420,%rdx
    1d3a:	68 65 20 
    1d3d:	49 89 47 10          	mov    %rax,0x10(%r15)
    1d41:	49 89 57 18          	mov    %rdx,0x18(%r15)
    1d45:	41 c7 47 20 73 65 72 	movl   $0x76726573,0x20(%r15)
    1d4c:	76 
    1d4d:	66 41 c7 47 24 65 72 	movw   $0x7265,0x24(%r15)
    1d54:	41 c6 47 26 00       	movb   $0x0,0x26(%r15)
    1d59:	44 89 e7             	mov    %r12d,%edi
    1d5c:	e8 ff ef ff ff       	callq  d60 <close@plt>
    1d61:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1d66:	e9 d2 03 00 00       	jmpq   213d <submitr+0x690>
    1d6b:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
    1d72:	3a 20 52 
    1d75:	48 ba 65 73 75 6c 74 	movabs $0x747320746c757365,%rdx
    1d7c:	20 73 74 
    1d7f:	49 89 07             	mov    %rax,(%r15)
    1d82:	49 89 57 08          	mov    %rdx,0x8(%r15)
    1d86:	48 b8 72 69 6e 67 20 	movabs $0x6f6f7420676e6972,%rax
    1d8d:	74 6f 6f 
    1d90:	48 ba 20 6c 61 72 67 	movabs $0x202e656772616c20,%rdx
    1d97:	65 2e 20 
    1d9a:	49 89 47 10          	mov    %rax,0x10(%r15)
    1d9e:	49 89 57 18          	mov    %rdx,0x18(%r15)
    1da2:	48 b8 49 6e 63 72 65 	movabs $0x6573616572636e49,%rax
    1da9:	61 73 65 
    1dac:	48 ba 20 53 55 42 4d 	movabs $0x5254494d42555320,%rdx
    1db3:	49 54 52 
    1db6:	49 89 47 20          	mov    %rax,0x20(%r15)
    1dba:	49 89 57 28          	mov    %rdx,0x28(%r15)
    1dbe:	48 b8 5f 4d 41 58 42 	movabs $0x46554258414d5f,%rax
    1dc5:	55 46 00 
    1dc8:	49 89 47 30          	mov    %rax,0x30(%r15)
    1dcc:	44 89 e7             	mov    %r12d,%edi
    1dcf:	e8 8c ef ff ff       	callq  d60 <close@plt>
    1dd4:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1dd9:	e9 5f 03 00 00       	jmpq   213d <submitr+0x690>
    1dde:	49 0f a3 c5          	bt     %rax,%r13
    1de2:	73 21                	jae    1e05 <submitr+0x358>
    1de4:	44 88 45 00          	mov    %r8b,0x0(%rbp)
    1de8:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
    1dec:	48 83 c3 01          	add    $0x1,%rbx
    1df0:	4c 39 f3             	cmp    %r14,%rbx
    1df3:	0f 84 6d 04 00 00    	je     2266 <submitr+0x7b9>
    1df9:	44 0f b6 03          	movzbl (%rbx),%r8d
    1dfd:	41 8d 40 d6          	lea    -0x2a(%r8),%eax
    1e01:	3c 35                	cmp    $0x35,%al
    1e03:	76 d9                	jbe    1dde <submitr+0x331>
    1e05:	44 89 c0             	mov    %r8d,%eax
    1e08:	83 e0 df             	and    $0xffffffdf,%eax
    1e0b:	83 e8 41             	sub    $0x41,%eax
    1e0e:	3c 19                	cmp    $0x19,%al
    1e10:	76 d2                	jbe    1de4 <submitr+0x337>
    1e12:	41 80 f8 20          	cmp    $0x20,%r8b
    1e16:	74 60                	je     1e78 <submitr+0x3cb>
    1e18:	41 8d 40 e0          	lea    -0x20(%r8),%eax
    1e1c:	3c 5f                	cmp    $0x5f,%al
    1e1e:	76 0a                	jbe    1e2a <submitr+0x37d>
    1e20:	41 80 f8 09          	cmp    $0x9,%r8b
    1e24:	0f 85 af 03 00 00    	jne    21d9 <submitr+0x72c>
    1e2a:	45 0f b6 c0          	movzbl %r8b,%r8d
    1e2e:	48 8d 0d 4b 0d 00 00 	lea    0xd4b(%rip),%rcx        # 2b80 <array.3415+0x3a0>
    1e35:	ba 08 00 00 00       	mov    $0x8,%edx
    1e3a:	be 01 00 00 00       	mov    $0x1,%esi
    1e3f:	48 8b 7c 24 28       	mov    0x28(%rsp),%rdi
    1e44:	b8 00 00 00 00       	mov    $0x0,%eax
    1e49:	e8 22 f0 ff ff       	callq  e70 <__sprintf_chk@plt>
    1e4e:	0f b6 84 24 60 80 00 	movzbl 0x8060(%rsp),%eax
    1e55:	00 
    1e56:	88 45 00             	mov    %al,0x0(%rbp)
    1e59:	0f b6 84 24 61 80 00 	movzbl 0x8061(%rsp),%eax
    1e60:	00 
    1e61:	88 45 01             	mov    %al,0x1(%rbp)
    1e64:	0f b6 84 24 62 80 00 	movzbl 0x8062(%rsp),%eax
    1e6b:	00 
    1e6c:	88 45 02             	mov    %al,0x2(%rbp)
    1e6f:	48 8d 6d 03          	lea    0x3(%rbp),%rbp
    1e73:	e9 74 ff ff ff       	jmpq   1dec <submitr+0x33f>
    1e78:	c6 45 00 2b          	movb   $0x2b,0x0(%rbp)
    1e7c:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
    1e80:	e9 67 ff ff ff       	jmpq   1dec <submitr+0x33f>
    1e85:	49 01 c5             	add    %rax,%r13
    1e88:	48 29 c5             	sub    %rax,%rbp
    1e8b:	74 26                	je     1eb3 <submitr+0x406>
    1e8d:	48 89 ea             	mov    %rbp,%rdx
    1e90:	4c 89 ee             	mov    %r13,%rsi
    1e93:	44 89 e7             	mov    %r12d,%edi
    1e96:	e8 85 ee ff ff       	callq  d20 <write@plt>
    1e9b:	48 85 c0             	test   %rax,%rax
    1e9e:	7f e5                	jg     1e85 <submitr+0x3d8>
    1ea0:	e8 4b ee ff ff       	callq  cf0 <__errno_location@plt>
    1ea5:	83 38 04             	cmpl   $0x4,(%rax)
    1ea8:	0f 85 31 01 00 00    	jne    1fdf <submitr+0x532>
    1eae:	4c 89 f0             	mov    %r14,%rax
    1eb1:	eb d2                	jmp    1e85 <submitr+0x3d8>
    1eb3:	48 85 db             	test   %rbx,%rbx
    1eb6:	0f 88 23 01 00 00    	js     1fdf <submitr+0x532>
    1ebc:	44 89 64 24 50       	mov    %r12d,0x50(%rsp)
    1ec1:	c7 44 24 54 00 00 00 	movl   $0x0,0x54(%rsp)
    1ec8:	00 
    1ec9:	48 8d 7c 24 50       	lea    0x50(%rsp),%rdi
    1ece:	48 8d 47 10          	lea    0x10(%rdi),%rax
    1ed2:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
    1ed7:	48 8d b4 24 60 20 00 	lea    0x2060(%rsp),%rsi
    1ede:	00 
    1edf:	ba 00 20 00 00       	mov    $0x2000,%edx
    1ee4:	e8 08 fb ff ff       	callq  19f1 <rio_readlineb>
    1ee9:	48 85 c0             	test   %rax,%rax
    1eec:	0f 8e 4c 01 00 00    	jle    203e <submitr+0x591>
    1ef2:	48 8d 4c 24 3c       	lea    0x3c(%rsp),%rcx
    1ef7:	48 8d 94 24 60 60 00 	lea    0x6060(%rsp),%rdx
    1efe:	00 
    1eff:	48 8d bc 24 60 20 00 	lea    0x2060(%rsp),%rdi
    1f06:	00 
    1f07:	4c 8d 84 24 60 80 00 	lea    0x8060(%rsp),%r8
    1f0e:	00 
    1f0f:	48 8d 35 71 0c 00 00 	lea    0xc71(%rip),%rsi        # 2b87 <array.3415+0x3a7>
    1f16:	b8 00 00 00 00       	mov    $0x0,%eax
    1f1b:	e8 c0 ee ff ff       	callq  de0 <__isoc99_sscanf@plt>
    1f20:	44 8b 44 24 3c       	mov    0x3c(%rsp),%r8d
    1f25:	41 81 f8 c8 00 00 00 	cmp    $0xc8,%r8d
    1f2c:	0f 85 80 01 00 00    	jne    20b2 <submitr+0x605>
    1f32:	48 8d 9c 24 60 20 00 	lea    0x2060(%rsp),%rbx
    1f39:	00 
    1f3a:	48 8d 2d 57 0c 00 00 	lea    0xc57(%rip),%rbp        # 2b98 <array.3415+0x3b8>
    1f41:	4c 8d 6c 24 50       	lea    0x50(%rsp),%r13
    1f46:	b9 03 00 00 00       	mov    $0x3,%ecx
    1f4b:	48 89 de             	mov    %rbx,%rsi
    1f4e:	48 89 ef             	mov    %rbp,%rdi
    1f51:	f3 a6                	repz cmpsb %es:(%rdi),%ds:(%rsi)
    1f53:	0f 97 c0             	seta   %al
    1f56:	1c 00                	sbb    $0x0,%al
    1f58:	84 c0                	test   %al,%al
    1f5a:	0f 84 89 01 00 00    	je     20e9 <submitr+0x63c>
    1f60:	ba 00 20 00 00       	mov    $0x2000,%edx
    1f65:	48 89 de             	mov    %rbx,%rsi
    1f68:	4c 89 ef             	mov    %r13,%rdi
    1f6b:	e8 81 fa ff ff       	callq  19f1 <rio_readlineb>
    1f70:	48 85 c0             	test   %rax,%rax
    1f73:	7f d1                	jg     1f46 <submitr+0x499>
    1f75:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    1f7c:	3a 20 43 
    1f7f:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    1f86:	20 75 6e 
    1f89:	49 89 07             	mov    %rax,(%r15)
    1f8c:	49 89 57 08          	mov    %rdx,0x8(%r15)
    1f90:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    1f97:	74 6f 20 
    1f9a:	48 ba 72 65 61 64 20 	movabs $0x6165682064616572,%rdx
    1fa1:	68 65 61 
    1fa4:	49 89 47 10          	mov    %rax,0x10(%r15)
    1fa8:	49 89 57 18          	mov    %rdx,0x18(%r15)
    1fac:	48 b8 64 65 72 73 20 	movabs $0x6f72662073726564,%rax
    1fb3:	66 72 6f 
    1fb6:	48 ba 6d 20 73 65 72 	movabs $0x726576726573206d,%rdx
    1fbd:	76 65 72 
    1fc0:	49 89 47 20          	mov    %rax,0x20(%r15)
    1fc4:	49 89 57 28          	mov    %rdx,0x28(%r15)
    1fc8:	41 c6 47 30 00       	movb   $0x0,0x30(%r15)
    1fcd:	44 89 e7             	mov    %r12d,%edi
    1fd0:	e8 8b ed ff ff       	callq  d60 <close@plt>
    1fd5:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1fda:	e9 5e 01 00 00       	jmpq   213d <submitr+0x690>
    1fdf:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    1fe6:	3a 20 43 
    1fe9:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    1ff0:	20 75 6e 
    1ff3:	49 89 07             	mov    %rax,(%r15)
    1ff6:	49 89 57 08          	mov    %rdx,0x8(%r15)
    1ffa:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2001:	74 6f 20 
    2004:	48 ba 77 72 69 74 65 	movabs $0x6f74206574697277,%rdx
    200b:	20 74 6f 
    200e:	49 89 47 10          	mov    %rax,0x10(%r15)
    2012:	49 89 57 18          	mov    %rdx,0x18(%r15)
    2016:	48 b8 20 74 68 65 20 	movabs $0x7265732065687420,%rax
    201d:	73 65 72 
    2020:	49 89 47 20          	mov    %rax,0x20(%r15)
    2024:	41 c7 47 28 76 65 72 	movl   $0x726576,0x28(%r15)
    202b:	00 
    202c:	44 89 e7             	mov    %r12d,%edi
    202f:	e8 2c ed ff ff       	callq  d60 <close@plt>
    2034:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2039:	e9 ff 00 00 00       	jmpq   213d <submitr+0x690>
    203e:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    2045:	3a 20 43 
    2048:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    204f:	20 75 6e 
    2052:	49 89 07             	mov    %rax,(%r15)
    2055:	49 89 57 08          	mov    %rdx,0x8(%r15)
    2059:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2060:	74 6f 20 
    2063:	48 ba 72 65 61 64 20 	movabs $0x7269662064616572,%rdx
    206a:	66 69 72 
    206d:	49 89 47 10          	mov    %rax,0x10(%r15)
    2071:	49 89 57 18          	mov    %rdx,0x18(%r15)
    2075:	48 b8 73 74 20 68 65 	movabs $0x6564616568207473,%rax
    207c:	61 64 65 
    207f:	48 ba 72 20 66 72 6f 	movabs $0x73206d6f72662072,%rdx
    2086:	6d 20 73 
    2089:	49 89 47 20          	mov    %rax,0x20(%r15)
    208d:	49 89 57 28          	mov    %rdx,0x28(%r15)
    2091:	41 c7 47 30 65 72 76 	movl   $0x65767265,0x30(%r15)
    2098:	65 
    2099:	66 41 c7 47 34 72 00 	movw   $0x72,0x34(%r15)
    20a0:	44 89 e7             	mov    %r12d,%edi
    20a3:	e8 b8 ec ff ff       	callq  d60 <close@plt>
    20a8:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    20ad:	e9 8b 00 00 00       	jmpq   213d <submitr+0x690>
    20b2:	4c 8d 8c 24 60 80 00 	lea    0x8060(%rsp),%r9
    20b9:	00 
    20ba:	48 8d 0d 0f 0a 00 00 	lea    0xa0f(%rip),%rcx        # 2ad0 <array.3415+0x2f0>
    20c1:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    20c8:	be 01 00 00 00       	mov    $0x1,%esi
    20cd:	4c 89 ff             	mov    %r15,%rdi
    20d0:	b8 00 00 00 00       	mov    $0x0,%eax
    20d5:	e8 96 ed ff ff       	callq  e70 <__sprintf_chk@plt>
    20da:	44 89 e7             	mov    %r12d,%edi
    20dd:	e8 7e ec ff ff       	callq  d60 <close@plt>
    20e2:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    20e7:	eb 54                	jmp    213d <submitr+0x690>
    20e9:	48 8d b4 24 60 20 00 	lea    0x2060(%rsp),%rsi
    20f0:	00 
    20f1:	48 8d 7c 24 50       	lea    0x50(%rsp),%rdi
    20f6:	ba 00 20 00 00       	mov    $0x2000,%edx
    20fb:	e8 f1 f8 ff ff       	callq  19f1 <rio_readlineb>
    2100:	48 85 c0             	test   %rax,%rax
    2103:	7e 61                	jle    2166 <submitr+0x6b9>
    2105:	48 8d b4 24 60 20 00 	lea    0x2060(%rsp),%rsi
    210c:	00 
    210d:	4c 89 ff             	mov    %r15,%rdi
    2110:	e8 eb eb ff ff       	callq  d00 <strcpy@plt>
    2115:	44 89 e7             	mov    %r12d,%edi
    2118:	e8 43 ec ff ff       	callq  d60 <close@plt>
    211d:	b9 03 00 00 00       	mov    $0x3,%ecx
    2122:	48 8d 3d 72 0a 00 00 	lea    0xa72(%rip),%rdi        # 2b9b <array.3415+0x3bb>
    2129:	4c 89 fe             	mov    %r15,%rsi
    212c:	f3 a6                	repz cmpsb %es:(%rdi),%ds:(%rsi)
    212e:	0f 97 c0             	seta   %al
    2131:	1c 00                	sbb    $0x0,%al
    2133:	84 c0                	test   %al,%al
    2135:	0f 95 c0             	setne  %al
    2138:	0f b6 c0             	movzbl %al,%eax
    213b:	f7 d8                	neg    %eax
    213d:	48 8b 94 24 68 a0 00 	mov    0xa068(%rsp),%rdx
    2144:	00 
    2145:	64 48 33 14 25 28 00 	xor    %fs:0x28,%rdx
    214c:	00 00 
    214e:	0f 85 95 01 00 00    	jne    22e9 <submitr+0x83c>
    2154:	48 81 c4 78 a0 00 00 	add    $0xa078,%rsp
    215b:	5b                   	pop    %rbx
    215c:	5d                   	pop    %rbp
    215d:	41 5c                	pop    %r12
    215f:	41 5d                	pop    %r13
    2161:	41 5e                	pop    %r14
    2163:	41 5f                	pop    %r15
    2165:	c3                   	retq   
    2166:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    216d:	3a 20 43 
    2170:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    2177:	20 75 6e 
    217a:	49 89 07             	mov    %rax,(%r15)
    217d:	49 89 57 08          	mov    %rdx,0x8(%r15)
    2181:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2188:	74 6f 20 
    218b:	48 ba 72 65 61 64 20 	movabs $0x6174732064616572,%rdx
    2192:	73 74 61 
    2195:	49 89 47 10          	mov    %rax,0x10(%r15)
    2199:	49 89 57 18          	mov    %rdx,0x18(%r15)
    219d:	48 b8 74 75 73 20 6d 	movabs $0x7373656d20737574,%rax
    21a4:	65 73 73 
    21a7:	48 ba 61 67 65 20 66 	movabs $0x6d6f726620656761,%rdx
    21ae:	72 6f 6d 
    21b1:	49 89 47 20          	mov    %rax,0x20(%r15)
    21b5:	49 89 57 28          	mov    %rdx,0x28(%r15)
    21b9:	48 b8 20 73 65 72 76 	movabs $0x72657672657320,%rax
    21c0:	65 72 00 
    21c3:	49 89 47 30          	mov    %rax,0x30(%r15)
    21c7:	44 89 e7             	mov    %r12d,%edi
    21ca:	e8 91 eb ff ff       	callq  d60 <close@plt>
    21cf:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    21d4:	e9 64 ff ff ff       	jmpq   213d <submitr+0x690>
    21d9:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
    21e0:	3a 20 52 
    21e3:	48 ba 65 73 75 6c 74 	movabs $0x747320746c757365,%rdx
    21ea:	20 73 74 
    21ed:	49 89 07             	mov    %rax,(%r15)
    21f0:	49 89 57 08          	mov    %rdx,0x8(%r15)
    21f4:	48 b8 72 69 6e 67 20 	movabs $0x6e6f6320676e6972,%rax
    21fb:	63 6f 6e 
    21fe:	48 ba 74 61 69 6e 73 	movabs $0x6e6120736e696174,%rdx
    2205:	20 61 6e 
    2208:	49 89 47 10          	mov    %rax,0x10(%r15)
    220c:	49 89 57 18          	mov    %rdx,0x18(%r15)
    2210:	48 b8 20 69 6c 6c 65 	movabs $0x6c6167656c6c6920,%rax
    2217:	67 61 6c 
    221a:	48 ba 20 6f 72 20 75 	movabs $0x72706e7520726f20,%rdx
    2221:	6e 70 72 
    2224:	49 89 47 20          	mov    %rax,0x20(%r15)
    2228:	49 89 57 28          	mov    %rdx,0x28(%r15)
    222c:	48 b8 69 6e 74 61 62 	movabs $0x20656c6261746e69,%rax
    2233:	6c 65 20 
    2236:	48 ba 63 68 61 72 61 	movabs $0x6574636172616863,%rdx
    223d:	63 74 65 
    2240:	49 89 47 30          	mov    %rax,0x30(%r15)
    2244:	49 89 57 38          	mov    %rdx,0x38(%r15)
    2248:	66 41 c7 47 40 72 2e 	movw   $0x2e72,0x40(%r15)
    224f:	41 c6 47 42 00       	movb   $0x0,0x42(%r15)
    2254:	44 89 e7             	mov    %r12d,%edi
    2257:	e8 04 eb ff ff       	callq  d60 <close@plt>
    225c:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2261:	e9 d7 fe ff ff       	jmpq   213d <submitr+0x690>
    2266:	48 8d 9c 24 60 20 00 	lea    0x2060(%rsp),%rbx
    226d:	00 
    226e:	48 83 ec 08          	sub    $0x8,%rsp
    2272:	48 8d 84 24 68 40 00 	lea    0x4068(%rsp),%rax
    2279:	00 
    227a:	50                   	push   %rax
    227b:	ff 74 24 28          	pushq  0x28(%rsp)
    227f:	ff 74 24 38          	pushq  0x38(%rsp)
    2283:	4c 8b 4c 24 30       	mov    0x30(%rsp),%r9
    2288:	4c 8b 44 24 28       	mov    0x28(%rsp),%r8
    228d:	48 8d 0d 6c 08 00 00 	lea    0x86c(%rip),%rcx        # 2b00 <array.3415+0x320>
    2294:	ba 00 20 00 00       	mov    $0x2000,%edx
    2299:	be 01 00 00 00       	mov    $0x1,%esi
    229e:	48 89 df             	mov    %rbx,%rdi
    22a1:	b8 00 00 00 00       	mov    $0x0,%eax
    22a6:	e8 c5 eb ff ff       	callq  e70 <__sprintf_chk@plt>
    22ab:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
    22b2:	b8 00 00 00 00       	mov    $0x0,%eax
    22b7:	48 89 df             	mov    %rbx,%rdi
    22ba:	f2 ae                	repnz scas %es:(%rdi),%al
    22bc:	48 f7 d1             	not    %rcx
    22bf:	48 89 cb             	mov    %rcx,%rbx
    22c2:	48 83 eb 01          	sub    $0x1,%rbx
    22c6:	48 83 c4 20          	add    $0x20,%rsp
    22ca:	48 89 dd             	mov    %rbx,%rbp
    22cd:	4c 8d ac 24 60 20 00 	lea    0x2060(%rsp),%r13
    22d4:	00 
    22d5:	41 be 00 00 00 00    	mov    $0x0,%r14d
    22db:	48 85 db             	test   %rbx,%rbx
    22de:	0f 85 a9 fb ff ff    	jne    1e8d <submitr+0x3e0>
    22e4:	e9 d3 fb ff ff       	jmpq   1ebc <submitr+0x40f>
    22e9:	e8 52 ea ff ff       	callq  d40 <__stack_chk_fail@plt>

00000000000022ee <init_timeout>:
    22ee:	85 ff                	test   %edi,%edi
    22f0:	74 25                	je     2317 <init_timeout+0x29>
    22f2:	53                   	push   %rbx
    22f3:	89 fb                	mov    %edi,%ebx
    22f5:	48 8d 35 c5 f6 ff ff 	lea    -0x93b(%rip),%rsi        # 19c1 <sigalrm_handler>
    22fc:	bf 0e 00 00 00       	mov    $0xe,%edi
    2301:	e8 8a ea ff ff       	callq  d90 <signal@plt>
    2306:	85 db                	test   %ebx,%ebx
    2308:	bf 00 00 00 00       	mov    $0x0,%edi
    230d:	0f 49 fb             	cmovns %ebx,%edi
    2310:	e8 3b ea ff ff       	callq  d50 <alarm@plt>
    2315:	5b                   	pop    %rbx
    2316:	c3                   	retq   
    2317:	f3 c3                	repz retq 

0000000000002319 <init_driver>:
    2319:	41 54                	push   %r12
    231b:	55                   	push   %rbp
    231c:	53                   	push   %rbx
    231d:	48 83 ec 20          	sub    $0x20,%rsp
    2321:	49 89 fc             	mov    %rdi,%r12
    2324:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    232b:	00 00 
    232d:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    2332:	31 c0                	xor    %eax,%eax
    2334:	be 01 00 00 00       	mov    $0x1,%esi
    2339:	bf 0d 00 00 00       	mov    $0xd,%edi
    233e:	e8 4d ea ff ff       	callq  d90 <signal@plt>
    2343:	be 01 00 00 00       	mov    $0x1,%esi
    2348:	bf 1d 00 00 00       	mov    $0x1d,%edi
    234d:	e8 3e ea ff ff       	callq  d90 <signal@plt>
    2352:	be 01 00 00 00       	mov    $0x1,%esi
    2357:	bf 1d 00 00 00       	mov    $0x1d,%edi
    235c:	e8 2f ea ff ff       	callq  d90 <signal@plt>
    2361:	ba 00 00 00 00       	mov    $0x0,%edx
    2366:	be 01 00 00 00       	mov    $0x1,%esi
    236b:	bf 02 00 00 00       	mov    $0x2,%edi
    2370:	e8 0b eb ff ff       	callq  e80 <socket@plt>
    2375:	85 c0                	test   %eax,%eax
    2377:	0f 88 a3 00 00 00    	js     2420 <init_driver+0x107>
    237d:	89 c3                	mov    %eax,%ebx
    237f:	48 8d 3d 18 08 00 00 	lea    0x818(%rip),%rdi        # 2b9e <array.3415+0x3be>
    2386:	e8 15 ea ff ff       	callq  da0 <gethostbyname@plt>
    238b:	48 85 c0             	test   %rax,%rax
    238e:	0f 84 df 00 00 00    	je     2473 <init_driver+0x15a>
    2394:	48 89 e5             	mov    %rsp,%rbp
    2397:	48 c7 44 24 02 00 00 	movq   $0x0,0x2(%rsp)
    239e:	00 00 
    23a0:	c7 45 0a 00 00 00 00 	movl   $0x0,0xa(%rbp)
    23a7:	66 c7 45 0e 00 00    	movw   $0x0,0xe(%rbp)
    23ad:	66 c7 04 24 02 00    	movw   $0x2,(%rsp)
    23b3:	48 63 50 14          	movslq 0x14(%rax),%rdx
    23b7:	48 8b 40 18          	mov    0x18(%rax),%rax
    23bb:	48 8d 7d 04          	lea    0x4(%rbp),%rdi
    23bf:	b9 0c 00 00 00       	mov    $0xc,%ecx
    23c4:	48 8b 30             	mov    (%rax),%rsi
    23c7:	e8 e4 e9 ff ff       	callq  db0 <__memmove_chk@plt>
    23cc:	66 c7 44 24 02 9e 3b 	movw   $0x3b9e,0x2(%rsp)
    23d3:	ba 10 00 00 00       	mov    $0x10,%edx
    23d8:	48 89 ee             	mov    %rbp,%rsi
    23db:	89 df                	mov    %ebx,%edi
    23dd:	e8 4e ea ff ff       	callq  e30 <connect@plt>
    23e2:	85 c0                	test   %eax,%eax
    23e4:	0f 88 fb 00 00 00    	js     24e5 <init_driver+0x1cc>
    23ea:	89 df                	mov    %ebx,%edi
    23ec:	e8 6f e9 ff ff       	callq  d60 <close@plt>
    23f1:	66 41 c7 04 24 4f 4b 	movw   $0x4b4f,(%r12)
    23f8:	41 c6 44 24 02 00    	movb   $0x0,0x2(%r12)
    23fe:	b8 00 00 00 00       	mov    $0x0,%eax
    2403:	48 8b 4c 24 18       	mov    0x18(%rsp),%rcx
    2408:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    240f:	00 00 
    2411:	0f 85 06 01 00 00    	jne    251d <init_driver+0x204>
    2417:	48 83 c4 20          	add    $0x20,%rsp
    241b:	5b                   	pop    %rbx
    241c:	5d                   	pop    %rbp
    241d:	41 5c                	pop    %r12
    241f:	c3                   	retq   
    2420:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    2427:	3a 20 43 
    242a:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    2431:	20 75 6e 
    2434:	49 89 04 24          	mov    %rax,(%r12)
    2438:	49 89 54 24 08       	mov    %rdx,0x8(%r12)
    243d:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2444:	74 6f 20 
    2447:	48 ba 63 72 65 61 74 	movabs $0x7320657461657263,%rdx
    244e:	65 20 73 
    2451:	49 89 44 24 10       	mov    %rax,0x10(%r12)
    2456:	49 89 54 24 18       	mov    %rdx,0x18(%r12)
    245b:	41 c7 44 24 20 6f 63 	movl   $0x656b636f,0x20(%r12)
    2462:	6b 65 
    2464:	66 41 c7 44 24 24 74 	movw   $0x74,0x24(%r12)
    246b:	00 
    246c:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2471:	eb 90                	jmp    2403 <init_driver+0xea>
    2473:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
    247a:	3a 20 44 
    247d:	48 ba 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rdx
    2484:	20 75 6e 
    2487:	49 89 04 24          	mov    %rax,(%r12)
    248b:	49 89 54 24 08       	mov    %rdx,0x8(%r12)
    2490:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2497:	74 6f 20 
    249a:	48 ba 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rdx
    24a1:	76 65 20 
    24a4:	49 89 44 24 10       	mov    %rax,0x10(%r12)
    24a9:	49 89 54 24 18       	mov    %rdx,0x18(%r12)
    24ae:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
    24b5:	72 20 61 
    24b8:	49 89 44 24 20       	mov    %rax,0x20(%r12)
    24bd:	41 c7 44 24 28 64 64 	movl   $0x65726464,0x28(%r12)
    24c4:	72 65 
    24c6:	66 41 c7 44 24 2c 73 	movw   $0x7373,0x2c(%r12)
    24cd:	73 
    24ce:	41 c6 44 24 2e 00    	movb   $0x0,0x2e(%r12)
    24d4:	89 df                	mov    %ebx,%edi
    24d6:	e8 85 e8 ff ff       	callq  d60 <close@plt>
    24db:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    24e0:	e9 1e ff ff ff       	jmpq   2403 <init_driver+0xea>
    24e5:	4c 8d 05 b2 06 00 00 	lea    0x6b2(%rip),%r8        # 2b9e <array.3415+0x3be>
    24ec:	48 8d 0d 65 06 00 00 	lea    0x665(%rip),%rcx        # 2b58 <array.3415+0x378>
    24f3:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    24fa:	be 01 00 00 00       	mov    $0x1,%esi
    24ff:	4c 89 e7             	mov    %r12,%rdi
    2502:	b8 00 00 00 00       	mov    $0x0,%eax
    2507:	e8 64 e9 ff ff       	callq  e70 <__sprintf_chk@plt>
    250c:	89 df                	mov    %ebx,%edi
    250e:	e8 4d e8 ff ff       	callq  d60 <close@plt>
    2513:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2518:	e9 e6 fe ff ff       	jmpq   2403 <init_driver+0xea>
    251d:	e8 1e e8 ff ff       	callq  d40 <__stack_chk_fail@plt>

0000000000002522 <driver_post>:
    2522:	53                   	push   %rbx
    2523:	4c 89 c3             	mov    %r8,%rbx
    2526:	85 c9                	test   %ecx,%ecx
    2528:	75 17                	jne    2541 <driver_post+0x1f>
    252a:	48 85 ff             	test   %rdi,%rdi
    252d:	74 05                	je     2534 <driver_post+0x12>
    252f:	80 3f 00             	cmpb   $0x0,(%rdi)
    2532:	75 33                	jne    2567 <driver_post+0x45>
    2534:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
    2539:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
    253d:	89 c8                	mov    %ecx,%eax
    253f:	5b                   	pop    %rbx
    2540:	c3                   	retq   
    2541:	48 8d 35 6b 06 00 00 	lea    0x66b(%rip),%rsi        # 2bb3 <array.3415+0x3d3>
    2548:	bf 01 00 00 00       	mov    $0x1,%edi
    254d:	b8 00 00 00 00       	mov    $0x0,%eax
    2552:	e8 99 e8 ff ff       	callq  df0 <__printf_chk@plt>
    2557:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
    255c:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
    2560:	b8 00 00 00 00       	mov    $0x0,%eax
    2565:	eb d8                	jmp    253f <driver_post+0x1d>
    2567:	41 50                	push   %r8
    2569:	52                   	push   %rdx
    256a:	4c 8d 0d 59 06 00 00 	lea    0x659(%rip),%r9        # 2bca <array.3415+0x3ea>
    2571:	49 89 f0             	mov    %rsi,%r8
    2574:	48 89 f9             	mov    %rdi,%rcx
    2577:	48 8d 15 52 06 00 00 	lea    0x652(%rip),%rdx        # 2bd0 <array.3415+0x3f0>
    257e:	be 3b 9e 00 00       	mov    $0x9e3b,%esi
    2583:	48 8d 3d 14 06 00 00 	lea    0x614(%rip),%rdi        # 2b9e <array.3415+0x3be>
    258a:	e8 1e f5 ff ff       	callq  1aad <submitr>
    258f:	48 83 c4 10          	add    $0x10,%rsp
    2593:	eb aa                	jmp    253f <driver_post+0x1d>
    2595:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    259c:	00 00 00 
    259f:	90                   	nop

00000000000025a0 <__libc_csu_init>:
    25a0:	41 57                	push   %r15
    25a2:	41 56                	push   %r14
    25a4:	49 89 d7             	mov    %rdx,%r15
    25a7:	41 55                	push   %r13
    25a9:	41 54                	push   %r12
    25ab:	4c 8d 25 2e 17 20 00 	lea    0x20172e(%rip),%r12        # 203ce0 <__frame_dummy_init_array_entry>
    25b2:	55                   	push   %rbp
    25b3:	48 8d 2d 2e 17 20 00 	lea    0x20172e(%rip),%rbp        # 203ce8 <__init_array_end>
    25ba:	53                   	push   %rbx
    25bb:	41 89 fd             	mov    %edi,%r13d
    25be:	49 89 f6             	mov    %rsi,%r14
    25c1:	4c 29 e5             	sub    %r12,%rbp
    25c4:	48 83 ec 08          	sub    $0x8,%rsp
    25c8:	48 c1 fd 03          	sar    $0x3,%rbp
    25cc:	e8 d7 e6 ff ff       	callq  ca8 <_init>
    25d1:	48 85 ed             	test   %rbp,%rbp
    25d4:	74 20                	je     25f6 <__libc_csu_init+0x56>
    25d6:	31 db                	xor    %ebx,%ebx
    25d8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    25df:	00 
    25e0:	4c 89 fa             	mov    %r15,%rdx
    25e3:	4c 89 f6             	mov    %r14,%rsi
    25e6:	44 89 ef             	mov    %r13d,%edi
    25e9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
    25ed:	48 83 c3 01          	add    $0x1,%rbx
    25f1:	48 39 dd             	cmp    %rbx,%rbp
    25f4:	75 ea                	jne    25e0 <__libc_csu_init+0x40>
    25f6:	48 83 c4 08          	add    $0x8,%rsp
    25fa:	5b                   	pop    %rbx
    25fb:	5d                   	pop    %rbp
    25fc:	41 5c                	pop    %r12
    25fe:	41 5d                	pop    %r13
    2600:	41 5e                	pop    %r14
    2602:	41 5f                	pop    %r15
    2604:	c3                   	retq   
    2605:	90                   	nop
    2606:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    260d:	00 00 00 

0000000000002610 <__libc_csu_fini>:
    2610:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000002614 <_fini>:
    2614:	48 83 ec 08          	sub    $0x8,%rsp
    2618:	48 83 c4 08          	add    $0x8,%rsp
    261c:	c3                   	retq   
