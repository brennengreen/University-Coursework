
bufdemo:     file format elf64-x86-64


Disassembly of section .init:

0000000000000528 <_init>:
 528:	48 83 ec 08          	sub    $0x8,%rsp
 52c:	48 8b 05 b5 0a 20 00 	mov    0x200ab5(%rip),%rax        # 200fe8 <__gmon_start__>
 533:	48 85 c0             	test   %rax,%rax
 536:	74 02                	je     53a <_init+0x12>
 538:	ff d0                	callq  *%rax
 53a:	48 83 c4 08          	add    $0x8,%rsp
 53e:	c3                   	retq   

Disassembly of section .plt:

0000000000000540 <.plt>:
 540:	ff 35 72 0a 20 00    	pushq  0x200a72(%rip)        # 200fb8 <_GLOBAL_OFFSET_TABLE_+0x8>
 546:	ff 25 74 0a 20 00    	jmpq   *0x200a74(%rip)        # 200fc0 <_GLOBAL_OFFSET_TABLE_+0x10>
 54c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000550 <printf@plt>:
 550:	ff 25 72 0a 20 00    	jmpq   *0x200a72(%rip)        # 200fc8 <printf@GLIBC_2.2.5>
 556:	68 00 00 00 00       	pushq  $0x0
 55b:	e9 e0 ff ff ff       	jmpq   540 <.plt>

0000000000000560 <gets@plt>:
 560:	ff 25 6a 0a 20 00    	jmpq   *0x200a6a(%rip)        # 200fd0 <gets@GLIBC_2.2.5>
 566:	68 01 00 00 00       	pushq  $0x1
 56b:	e9 d0 ff ff ff       	jmpq   540 <.plt>

Disassembly of section .plt.got:

0000000000000570 <__cxa_finalize@plt>:
 570:	ff 25 82 0a 20 00    	jmpq   *0x200a82(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 576:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000000580 <_start>:
 580:	31 ed                	xor    %ebp,%ebp
 582:	49 89 d1             	mov    %rdx,%r9
 585:	5e                   	pop    %rsi
 586:	48 89 e2             	mov    %rsp,%rdx
 589:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
 58d:	50                   	push   %rax
 58e:	54                   	push   %rsp
 58f:	4c 8d 05 ca 01 00 00 	lea    0x1ca(%rip),%r8        # 760 <__libc_csu_fini>
 596:	48 8d 0d 53 01 00 00 	lea    0x153(%rip),%rcx        # 6f0 <__libc_csu_init>
 59d:	48 8d 3d 22 01 00 00 	lea    0x122(%rip),%rdi        # 6c6 <main>
 5a4:	ff 15 36 0a 20 00    	callq  *0x200a36(%rip)        # 200fe0 <__libc_start_main@GLIBC_2.2.5>
 5aa:	f4                   	hlt    
 5ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000005b0 <deregister_tm_clones>:
 5b0:	48 8d 3d 59 0a 20 00 	lea    0x200a59(%rip),%rdi        # 201010 <__TMC_END__>
 5b7:	55                   	push   %rbp
 5b8:	48 8d 05 51 0a 20 00 	lea    0x200a51(%rip),%rax        # 201010 <__TMC_END__>
 5bf:	48 39 f8             	cmp    %rdi,%rax
 5c2:	48 89 e5             	mov    %rsp,%rbp
 5c5:	74 19                	je     5e0 <deregister_tm_clones+0x30>
 5c7:	48 8b 05 0a 0a 20 00 	mov    0x200a0a(%rip),%rax        # 200fd8 <_ITM_deregisterTMCloneTable>
 5ce:	48 85 c0             	test   %rax,%rax
 5d1:	74 0d                	je     5e0 <deregister_tm_clones+0x30>
 5d3:	5d                   	pop    %rbp
 5d4:	ff e0                	jmpq   *%rax
 5d6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 5dd:	00 00 00 
 5e0:	5d                   	pop    %rbp
 5e1:	c3                   	retq   
 5e2:	0f 1f 40 00          	nopl   0x0(%rax)
 5e6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 5ed:	00 00 00 

00000000000005f0 <register_tm_clones>:
 5f0:	48 8d 3d 19 0a 20 00 	lea    0x200a19(%rip),%rdi        # 201010 <__TMC_END__>
 5f7:	48 8d 35 12 0a 20 00 	lea    0x200a12(%rip),%rsi        # 201010 <__TMC_END__>
 5fe:	55                   	push   %rbp
 5ff:	48 29 fe             	sub    %rdi,%rsi
 602:	48 89 e5             	mov    %rsp,%rbp
 605:	48 c1 fe 03          	sar    $0x3,%rsi
 609:	48 89 f0             	mov    %rsi,%rax
 60c:	48 c1 e8 3f          	shr    $0x3f,%rax
 610:	48 01 c6             	add    %rax,%rsi
 613:	48 d1 fe             	sar    %rsi
 616:	74 18                	je     630 <register_tm_clones+0x40>
 618:	48 8b 05 d1 09 20 00 	mov    0x2009d1(%rip),%rax        # 200ff0 <_ITM_registerTMCloneTable>
 61f:	48 85 c0             	test   %rax,%rax
 622:	74 0c                	je     630 <register_tm_clones+0x40>
 624:	5d                   	pop    %rbp
 625:	ff e0                	jmpq   *%rax
 627:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 62e:	00 00 
 630:	5d                   	pop    %rbp
 631:	c3                   	retq   
 632:	0f 1f 40 00          	nopl   0x0(%rax)
 636:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 63d:	00 00 00 

0000000000000640 <__do_global_dtors_aux>:
 640:	80 3d c9 09 20 00 00 	cmpb   $0x0,0x2009c9(%rip)        # 201010 <__TMC_END__>
 647:	75 2f                	jne    678 <__do_global_dtors_aux+0x38>
 649:	48 83 3d a7 09 20 00 	cmpq   $0x0,0x2009a7(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 650:	00 
 651:	55                   	push   %rbp
 652:	48 89 e5             	mov    %rsp,%rbp
 655:	74 0c                	je     663 <__do_global_dtors_aux+0x23>
 657:	48 8b 3d aa 09 20 00 	mov    0x2009aa(%rip),%rdi        # 201008 <__dso_handle>
 65e:	e8 0d ff ff ff       	callq  570 <__cxa_finalize@plt>
 663:	e8 48 ff ff ff       	callq  5b0 <deregister_tm_clones>
 668:	c6 05 a1 09 20 00 01 	movb   $0x1,0x2009a1(%rip)        # 201010 <__TMC_END__>
 66f:	5d                   	pop    %rbp
 670:	c3                   	retq   
 671:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 678:	f3 c3                	repz retq 
 67a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000000680 <frame_dummy>:
 680:	55                   	push   %rbp
 681:	48 89 e5             	mov    %rsp,%rbp
 684:	5d                   	pop    %rbp
 685:	e9 66 ff ff ff       	jmpq   5f0 <register_tm_clones>

000000000000068a <echo>:
 68a:	55                   	push   %rbp
 68b:	48 89 e5             	mov    %rsp,%rbp
 68e:	48 83 ec 10          	sub    $0x10,%rsp
 692:	c6 45 fc 00          	movb   $0x0,-0x4(%rbp)
 696:	48 8d 45 f8          	lea    -0x8(%rbp),%rax
 69a:	48 89 c7             	mov    %rax,%rdi
 69d:	b8 00 00 00 00       	mov    $0x0,%eax
 6a2:	e8 b9 fe ff ff       	callq  560 <gets@plt>
 6a7:	48 8d 55 f8          	lea    -0x8(%rbp),%rdx
 6ab:	48 8d 45 fc          	lea    -0x4(%rbp),%rax
 6af:	48 89 c6             	mov    %rax,%rsi
 6b2:	48 8d 3d bb 00 00 00 	lea    0xbb(%rip),%rdi        # 774 <_IO_stdin_used+0x4>
 6b9:	b8 00 00 00 00       	mov    $0x0,%eax
 6be:	e8 8d fe ff ff       	callq  550 <printf@plt>
 6c3:	90                   	nop
 6c4:	c9                   	leaveq 
 6c5:	c3                   	retq   

00000000000006c6 <main>:
 6c6:	55                   	push   %rbp
 6c7:	48 89 e5             	mov    %rsp,%rbp
 6ca:	48 8d 3d be 00 00 00 	lea    0xbe(%rip),%rdi        # 78f <_IO_stdin_used+0x1f>
 6d1:	b8 00 00 00 00       	mov    $0x0,%eax
 6d6:	e8 75 fe ff ff       	callq  550 <printf@plt>
 6db:	b8 00 00 00 00       	mov    $0x0,%eax
 6e0:	e8 a5 ff ff ff       	callq  68a <echo>
 6e5:	b8 00 00 00 00       	mov    $0x0,%eax
 6ea:	5d                   	pop    %rbp
 6eb:	c3                   	retq   
 6ec:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000006f0 <__libc_csu_init>:
 6f0:	41 57                	push   %r15
 6f2:	41 56                	push   %r14
 6f4:	49 89 d7             	mov    %rdx,%r15
 6f7:	41 55                	push   %r13
 6f9:	41 54                	push   %r12
 6fb:	4c 8d 25 ae 06 20 00 	lea    0x2006ae(%rip),%r12        # 200db0 <__frame_dummy_init_array_entry>
 702:	55                   	push   %rbp
 703:	48 8d 2d ae 06 20 00 	lea    0x2006ae(%rip),%rbp        # 200db8 <__init_array_end>
 70a:	53                   	push   %rbx
 70b:	41 89 fd             	mov    %edi,%r13d
 70e:	49 89 f6             	mov    %rsi,%r14
 711:	4c 29 e5             	sub    %r12,%rbp
 714:	48 83 ec 08          	sub    $0x8,%rsp
 718:	48 c1 fd 03          	sar    $0x3,%rbp
 71c:	e8 07 fe ff ff       	callq  528 <_init>
 721:	48 85 ed             	test   %rbp,%rbp
 724:	74 20                	je     746 <__libc_csu_init+0x56>
 726:	31 db                	xor    %ebx,%ebx
 728:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 72f:	00 
 730:	4c 89 fa             	mov    %r15,%rdx
 733:	4c 89 f6             	mov    %r14,%rsi
 736:	44 89 ef             	mov    %r13d,%edi
 739:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
 73d:	48 83 c3 01          	add    $0x1,%rbx
 741:	48 39 dd             	cmp    %rbx,%rbp
 744:	75 ea                	jne    730 <__libc_csu_init+0x40>
 746:	48 83 c4 08          	add    $0x8,%rsp
 74a:	5b                   	pop    %rbx
 74b:	5d                   	pop    %rbp
 74c:	41 5c                	pop    %r12
 74e:	41 5d                	pop    %r13
 750:	41 5e                	pop    %r14
 752:	41 5f                	pop    %r15
 754:	c3                   	retq   
 755:	90                   	nop
 756:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 75d:	00 00 00 

0000000000000760 <__libc_csu_fini>:
 760:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000000764 <_fini>:
 764:	48 83 ec 08          	sub    $0x8,%rsp
 768:	48 83 c4 08          	add    $0x8,%rsp
 76c:	c3                   	retq   
