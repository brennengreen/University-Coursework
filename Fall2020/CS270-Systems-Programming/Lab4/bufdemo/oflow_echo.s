
oflow_echo:     file format elf64-x86-64


Disassembly of section .init:

0000000000000560 <_init>:
 560:	48 83 ec 08          	sub    $0x8,%rsp
 564:	48 8b 05 7d 0a 20 00 	mov    0x200a7d(%rip),%rax        # 200fe8 <__gmon_start__>
 56b:	48 85 c0             	test   %rax,%rax
 56e:	74 02                	je     572 <_init+0x12>
 570:	ff d0                	callq  *%rax
 572:	48 83 c4 08          	add    $0x8,%rsp
 576:	c3                   	retq   

Disassembly of section .plt:

0000000000000580 <.plt>:
 580:	ff 35 2a 0a 20 00    	pushq  0x200a2a(%rip)        # 200fb0 <_GLOBAL_OFFSET_TABLE_+0x8>
 586:	ff 25 2c 0a 20 00    	jmpq   *0x200a2c(%rip)        # 200fb8 <_GLOBAL_OFFSET_TABLE_+0x10>
 58c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000590 <puts@plt>:
 590:	ff 25 2a 0a 20 00    	jmpq   *0x200a2a(%rip)        # 200fc0 <puts@GLIBC_2.2.5>
 596:	68 00 00 00 00       	pushq  $0x0
 59b:	e9 e0 ff ff ff       	jmpq   580 <.plt>

00000000000005a0 <getchar@plt>:
 5a0:	ff 25 22 0a 20 00    	jmpq   *0x200a22(%rip)        # 200fc8 <getchar@GLIBC_2.2.5>
 5a6:	68 01 00 00 00       	pushq  $0x1
 5ab:	e9 d0 ff ff ff       	jmpq   580 <.plt>

00000000000005b0 <exit@plt>:
 5b0:	ff 25 1a 0a 20 00    	jmpq   *0x200a1a(%rip)        # 200fd0 <exit@GLIBC_2.2.5>
 5b6:	68 02 00 00 00       	pushq  $0x2
 5bb:	e9 c0 ff ff ff       	jmpq   580 <.plt>

Disassembly of section .plt.got:

00000000000005c0 <__cxa_finalize@plt>:
 5c0:	ff 25 32 0a 20 00    	jmpq   *0x200a32(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 5c6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000000005d0 <_start>:
 5d0:	31 ed                	xor    %ebp,%ebp
 5d2:	49 89 d1             	mov    %rdx,%r9
 5d5:	5e                   	pop    %rsi
 5d6:	48 89 e2             	mov    %rsp,%rdx
 5d9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
 5dd:	50                   	push   %rax
 5de:	54                   	push   %rsp
 5df:	4c 8d 05 1a 02 00 00 	lea    0x21a(%rip),%r8        # 800 <__libc_csu_fini>
 5e6:	48 8d 0d a3 01 00 00 	lea    0x1a3(%rip),%rcx        # 790 <__libc_csu_init>
 5ed:	48 8d 3d e6 00 00 00 	lea    0xe6(%rip),%rdi        # 6da <main>
 5f4:	ff 15 e6 09 20 00    	callq  *0x2009e6(%rip)        # 200fe0 <__libc_start_main@GLIBC_2.2.5>
 5fa:	f4                   	hlt    
 5fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000000600 <deregister_tm_clones>:
 600:	48 8d 3d 09 0a 20 00 	lea    0x200a09(%rip),%rdi        # 201010 <__TMC_END__>
 607:	55                   	push   %rbp
 608:	48 8d 05 01 0a 20 00 	lea    0x200a01(%rip),%rax        # 201010 <__TMC_END__>
 60f:	48 39 f8             	cmp    %rdi,%rax
 612:	48 89 e5             	mov    %rsp,%rbp
 615:	74 19                	je     630 <deregister_tm_clones+0x30>
 617:	48 8b 05 ba 09 20 00 	mov    0x2009ba(%rip),%rax        # 200fd8 <_ITM_deregisterTMCloneTable>
 61e:	48 85 c0             	test   %rax,%rax
 621:	74 0d                	je     630 <deregister_tm_clones+0x30>
 623:	5d                   	pop    %rbp
 624:	ff e0                	jmpq   *%rax
 626:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 62d:	00 00 00 
 630:	5d                   	pop    %rbp
 631:	c3                   	retq   
 632:	0f 1f 40 00          	nopl   0x0(%rax)
 636:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 63d:	00 00 00 

0000000000000640 <register_tm_clones>:
 640:	48 8d 3d c9 09 20 00 	lea    0x2009c9(%rip),%rdi        # 201010 <__TMC_END__>
 647:	48 8d 35 c2 09 20 00 	lea    0x2009c2(%rip),%rsi        # 201010 <__TMC_END__>
 64e:	55                   	push   %rbp
 64f:	48 29 fe             	sub    %rdi,%rsi
 652:	48 89 e5             	mov    %rsp,%rbp
 655:	48 c1 fe 03          	sar    $0x3,%rsi
 659:	48 89 f0             	mov    %rsi,%rax
 65c:	48 c1 e8 3f          	shr    $0x3f,%rax
 660:	48 01 c6             	add    %rax,%rsi
 663:	48 d1 fe             	sar    %rsi
 666:	74 18                	je     680 <register_tm_clones+0x40>
 668:	48 8b 05 81 09 20 00 	mov    0x200981(%rip),%rax        # 200ff0 <_ITM_registerTMCloneTable>
 66f:	48 85 c0             	test   %rax,%rax
 672:	74 0c                	je     680 <register_tm_clones+0x40>
 674:	5d                   	pop    %rbp
 675:	ff e0                	jmpq   *%rax
 677:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 67e:	00 00 
 680:	5d                   	pop    %rbp
 681:	c3                   	retq   
 682:	0f 1f 40 00          	nopl   0x0(%rax)
 686:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 68d:	00 00 00 

0000000000000690 <__do_global_dtors_aux>:
 690:	80 3d 79 09 20 00 00 	cmpb   $0x0,0x200979(%rip)        # 201010 <__TMC_END__>
 697:	75 2f                	jne    6c8 <__do_global_dtors_aux+0x38>
 699:	48 83 3d 57 09 20 00 	cmpq   $0x0,0x200957(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 6a0:	00 
 6a1:	55                   	push   %rbp
 6a2:	48 89 e5             	mov    %rsp,%rbp
 6a5:	74 0c                	je     6b3 <__do_global_dtors_aux+0x23>
 6a7:	48 8b 3d 5a 09 20 00 	mov    0x20095a(%rip),%rdi        # 201008 <__dso_handle>
 6ae:	e8 0d ff ff ff       	callq  5c0 <__cxa_finalize@plt>
 6b3:	e8 48 ff ff ff       	callq  600 <deregister_tm_clones>
 6b8:	c6 05 51 09 20 00 01 	movb   $0x1,0x200951(%rip)        # 201010 <__TMC_END__>
 6bf:	5d                   	pop    %rbp
 6c0:	c3                   	retq   
 6c1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 6c8:	f3 c3                	repz retq 
 6ca:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000006d0 <frame_dummy>:
 6d0:	55                   	push   %rbp
 6d1:	48 89 e5             	mov    %rsp,%rbp
 6d4:	5d                   	pop    %rbp
 6d5:	e9 66 ff ff ff       	jmpq   640 <register_tm_clones>

00000000000006da <main>:
 6da:	55                   	push   %rbp
 6db:	48 89 e5             	mov    %rsp,%rbp
 6de:	b8 00 00 00 00       	mov    $0x0,%eax
 6e3:	e8 52 00 00 00       	callq  73a <echo>
 6e8:	eb f4                	jmp    6de <main+0x4>

00000000000006ea <mygets>:
 6ea:	55                   	push   %rbp
 6eb:	48 89 e5             	mov    %rsp,%rbp
 6ee:	48 83 ec 20          	sub    $0x20,%rsp
 6f2:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
 6f6:	e8 a5 fe ff ff       	callq  5a0 <getchar@plt>
 6fb:	89 45 fc             	mov    %eax,-0x4(%rbp)
 6fe:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 702:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
 706:	eb 19                	jmp    721 <mygets+0x37>
 708:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
 70c:	48 8d 50 01          	lea    0x1(%rax),%rdx
 710:	48 89 55 f0          	mov    %rdx,-0x10(%rbp)
 714:	8b 55 fc             	mov    -0x4(%rbp),%edx
 717:	88 10                	mov    %dl,(%rax)
 719:	e8 82 fe ff ff       	callq  5a0 <getchar@plt>
 71e:	89 45 fc             	mov    %eax,-0x4(%rbp)
 721:	83 7d fc ff          	cmpl   $0xffffffff,-0x4(%rbp)
 725:	74 06                	je     72d <mygets+0x43>
 727:	83 7d fc 0a          	cmpl   $0xa,-0x4(%rbp)
 72b:	75 db                	jne    708 <mygets+0x1e>
 72d:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
 731:	c6 00 00             	movb   $0x0,(%rax)
 734:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 738:	c9                   	leaveq 
 739:	c3                   	retq   

000000000000073a <echo>:
 73a:	55                   	push   %rbp
 73b:	48 89 e5             	mov    %rsp,%rbp
 73e:	48 83 ec 10          	sub    $0x10,%rsp
 742:	48 8d 45 fc          	lea    -0x4(%rbp),%rax
 746:	48 89 c7             	mov    %rax,%rdi
 749:	e8 9c ff ff ff       	callq  6ea <mygets>
 74e:	48 8d 45 fc          	lea    -0x4(%rbp),%rax
 752:	48 89 c7             	mov    %rax,%rdi
 755:	e8 36 fe ff ff       	callq  590 <puts@plt>
 75a:	90                   	nop
 75b:	c9                   	leaveq 
 75c:	c3                   	retq   

000000000000075d <not_called>:
 75d:	55                   	push   %rbp
 75e:	48 89 e5             	mov    %rsp,%rbp
 761:	48 8d 3d b0 00 00 00 	lea    0xb0(%rip),%rdi        # 818 <_IO_stdin_used+0x8>
 768:	e8 23 fe ff ff       	callq  590 <puts@plt>
 76d:	48 8d 3d de 00 00 00 	lea    0xde(%rip),%rdi        # 852 <_IO_stdin_used+0x42>
 774:	e8 17 fe ff ff       	callq  590 <puts@plt>
 779:	bf 00 00 00 00       	mov    $0x0,%edi
 77e:	e8 2d fe ff ff       	callq  5b0 <exit@plt>
 783:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 78a:	00 00 00 
 78d:	0f 1f 00             	nopl   (%rax)

0000000000000790 <__libc_csu_init>:
 790:	41 57                	push   %r15
 792:	41 56                	push   %r14
 794:	49 89 d7             	mov    %rdx,%r15
 797:	41 55                	push   %r13
 799:	41 54                	push   %r12
 79b:	4c 8d 25 06 06 20 00 	lea    0x200606(%rip),%r12        # 200da8 <__frame_dummy_init_array_entry>
 7a2:	55                   	push   %rbp
 7a3:	48 8d 2d 06 06 20 00 	lea    0x200606(%rip),%rbp        # 200db0 <__init_array_end>
 7aa:	53                   	push   %rbx
 7ab:	41 89 fd             	mov    %edi,%r13d
 7ae:	49 89 f6             	mov    %rsi,%r14
 7b1:	4c 29 e5             	sub    %r12,%rbp
 7b4:	48 83 ec 08          	sub    $0x8,%rsp
 7b8:	48 c1 fd 03          	sar    $0x3,%rbp
 7bc:	e8 9f fd ff ff       	callq  560 <_init>
 7c1:	48 85 ed             	test   %rbp,%rbp
 7c4:	74 20                	je     7e6 <__libc_csu_init+0x56>
 7c6:	31 db                	xor    %ebx,%ebx
 7c8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 7cf:	00 
 7d0:	4c 89 fa             	mov    %r15,%rdx
 7d3:	4c 89 f6             	mov    %r14,%rsi
 7d6:	44 89 ef             	mov    %r13d,%edi
 7d9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
 7dd:	48 83 c3 01          	add    $0x1,%rbx
 7e1:	48 39 dd             	cmp    %rbx,%rbp
 7e4:	75 ea                	jne    7d0 <__libc_csu_init+0x40>
 7e6:	48 83 c4 08          	add    $0x8,%rsp
 7ea:	5b                   	pop    %rbx
 7eb:	5d                   	pop    %rbp
 7ec:	41 5c                	pop    %r12
 7ee:	41 5d                	pop    %r13
 7f0:	41 5e                	pop    %r14
 7f2:	41 5f                	pop    %r15
 7f4:	c3                   	retq   
 7f5:	90                   	nop
 7f6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 7fd:	00 00 00 

0000000000000800 <__libc_csu_fini>:
 800:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000000804 <_fini>:
 804:	48 83 ec 08          	sub    $0x8,%rsp
 808:	48 83 c4 08          	add    $0x8,%rsp
 80c:	c3                   	retq   
