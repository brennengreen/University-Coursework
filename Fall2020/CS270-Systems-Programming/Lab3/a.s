
a.out:     file format elf64-x86-64


Disassembly of section .init:

00000000000006d8 <_init>:
 6d8:	48 83 ec 08          	sub    $0x8,%rsp
 6dc:	48 8b 05 05 19 20 00 	mov    0x201905(%rip),%rax        # 201fe8 <__gmon_start__>
 6e3:	48 85 c0             	test   %rax,%rax
 6e6:	74 02                	je     6ea <_init+0x12>
 6e8:	ff d0                	callq  *%rax
 6ea:	48 83 c4 08          	add    $0x8,%rsp
 6ee:	c3                   	retq   

Disassembly of section .plt:

00000000000006f0 <.plt>:
 6f0:	ff 35 92 18 20 00    	pushq  0x201892(%rip)        # 201f88 <_GLOBAL_OFFSET_TABLE_+0x8>
 6f6:	ff 25 94 18 20 00    	jmpq   *0x201894(%rip)        # 201f90 <_GLOBAL_OFFSET_TABLE_+0x10>
 6fc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000700 <puts@plt>:
 700:	ff 25 92 18 20 00    	jmpq   *0x201892(%rip)        # 201f98 <puts@GLIBC_2.2.5>
 706:	68 00 00 00 00       	pushq  $0x0
 70b:	e9 e0 ff ff ff       	jmpq   6f0 <.plt>

0000000000000710 <strlen@plt>:
 710:	ff 25 8a 18 20 00    	jmpq   *0x20188a(%rip)        # 201fa0 <strlen@GLIBC_2.2.5>
 716:	68 01 00 00 00       	pushq  $0x1
 71b:	e9 d0 ff ff ff       	jmpq   6f0 <.plt>

0000000000000720 <printf@plt>:
 720:	ff 25 82 18 20 00    	jmpq   *0x201882(%rip)        # 201fa8 <printf@GLIBC_2.2.5>
 726:	68 02 00 00 00       	pushq  $0x2
 72b:	e9 c0 ff ff ff       	jmpq   6f0 <.plt>

0000000000000730 <fgets@plt>:
 730:	ff 25 7a 18 20 00    	jmpq   *0x20187a(%rip)        # 201fb0 <fgets@GLIBC_2.2.5>
 736:	68 03 00 00 00       	pushq  $0x3
 73b:	e9 b0 ff ff ff       	jmpq   6f0 <.plt>

0000000000000740 <strcmp@plt>:
 740:	ff 25 72 18 20 00    	jmpq   *0x201872(%rip)        # 201fb8 <strcmp@GLIBC_2.2.5>
 746:	68 04 00 00 00       	pushq  $0x4
 74b:	e9 a0 ff ff ff       	jmpq   6f0 <.plt>

0000000000000750 <fopen@plt>:
 750:	ff 25 6a 18 20 00    	jmpq   *0x20186a(%rip)        # 201fc0 <fopen@GLIBC_2.2.5>
 756:	68 05 00 00 00       	pushq  $0x5
 75b:	e9 90 ff ff ff       	jmpq   6f0 <.plt>

0000000000000760 <exit@plt>:
 760:	ff 25 62 18 20 00    	jmpq   *0x201862(%rip)        # 201fc8 <exit@GLIBC_2.2.5>
 766:	68 06 00 00 00       	pushq  $0x6
 76b:	e9 80 ff ff ff       	jmpq   6f0 <.plt>

0000000000000770 <__ctype_b_loc@plt>:
 770:	ff 25 5a 18 20 00    	jmpq   *0x20185a(%rip)        # 201fd0 <__ctype_b_loc@GLIBC_2.3>
 776:	68 07 00 00 00       	pushq  $0x7
 77b:	e9 70 ff ff ff       	jmpq   6f0 <.plt>

Disassembly of section .plt.got:

0000000000000780 <__cxa_finalize@plt>:
 780:	ff 25 72 18 20 00    	jmpq   *0x201872(%rip)        # 201ff8 <__cxa_finalize@GLIBC_2.2.5>
 786:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000000790 <_start>:
 790:	31 ed                	xor    %ebp,%ebp
 792:	49 89 d1             	mov    %rdx,%r9
 795:	5e                   	pop    %rsi
 796:	48 89 e2             	mov    %rsp,%rdx
 799:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
 79d:	50                   	push   %rax
 79e:	54                   	push   %rsp
 79f:	4c 8d 05 6a 03 00 00 	lea    0x36a(%rip),%r8        # b10 <__libc_csu_fini>
 7a6:	48 8d 0d f3 02 00 00 	lea    0x2f3(%rip),%rcx        # aa0 <__libc_csu_init>
 7ad:	48 8d 3d 02 02 00 00 	lea    0x202(%rip),%rdi        # 9b6 <main>
 7b4:	ff 15 26 18 20 00    	callq  *0x201826(%rip)        # 201fe0 <__libc_start_main@GLIBC_2.2.5>
 7ba:	f4                   	hlt    
 7bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000007c0 <deregister_tm_clones>:
 7c0:	48 8d 3d 49 18 20 00 	lea    0x201849(%rip),%rdi        # 202010 <__TMC_END__>
 7c7:	55                   	push   %rbp
 7c8:	48 8d 05 41 18 20 00 	lea    0x201841(%rip),%rax        # 202010 <__TMC_END__>
 7cf:	48 39 f8             	cmp    %rdi,%rax
 7d2:	48 89 e5             	mov    %rsp,%rbp
 7d5:	74 19                	je     7f0 <deregister_tm_clones+0x30>
 7d7:	48 8b 05 fa 17 20 00 	mov    0x2017fa(%rip),%rax        # 201fd8 <_ITM_deregisterTMCloneTable>
 7de:	48 85 c0             	test   %rax,%rax
 7e1:	74 0d                	je     7f0 <deregister_tm_clones+0x30>
 7e3:	5d                   	pop    %rbp
 7e4:	ff e0                	jmpq   *%rax
 7e6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 7ed:	00 00 00 
 7f0:	5d                   	pop    %rbp
 7f1:	c3                   	retq   
 7f2:	0f 1f 40 00          	nopl   0x0(%rax)
 7f6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 7fd:	00 00 00 

0000000000000800 <register_tm_clones>:
 800:	48 8d 3d 09 18 20 00 	lea    0x201809(%rip),%rdi        # 202010 <__TMC_END__>
 807:	48 8d 35 02 18 20 00 	lea    0x201802(%rip),%rsi        # 202010 <__TMC_END__>
 80e:	55                   	push   %rbp
 80f:	48 29 fe             	sub    %rdi,%rsi
 812:	48 89 e5             	mov    %rsp,%rbp
 815:	48 c1 fe 03          	sar    $0x3,%rsi
 819:	48 89 f0             	mov    %rsi,%rax
 81c:	48 c1 e8 3f          	shr    $0x3f,%rax
 820:	48 01 c6             	add    %rax,%rsi
 823:	48 d1 fe             	sar    %rsi
 826:	74 18                	je     840 <register_tm_clones+0x40>
 828:	48 8b 05 c1 17 20 00 	mov    0x2017c1(%rip),%rax        # 201ff0 <_ITM_registerTMCloneTable>
 82f:	48 85 c0             	test   %rax,%rax
 832:	74 0c                	je     840 <register_tm_clones+0x40>
 834:	5d                   	pop    %rbp
 835:	ff e0                	jmpq   *%rax
 837:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 83e:	00 00 
 840:	5d                   	pop    %rbp
 841:	c3                   	retq   
 842:	0f 1f 40 00          	nopl   0x0(%rax)
 846:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 84d:	00 00 00 

0000000000000850 <__do_global_dtors_aux>:
 850:	80 3d d1 17 20 00 00 	cmpb   $0x0,0x2017d1(%rip)        # 202028 <completed.7698>
 857:	75 2f                	jne    888 <__do_global_dtors_aux+0x38>
 859:	48 83 3d 97 17 20 00 	cmpq   $0x0,0x201797(%rip)        # 201ff8 <__cxa_finalize@GLIBC_2.2.5>
 860:	00 
 861:	55                   	push   %rbp
 862:	48 89 e5             	mov    %rsp,%rbp
 865:	74 0c                	je     873 <__do_global_dtors_aux+0x23>
 867:	48 8b 3d 9a 17 20 00 	mov    0x20179a(%rip),%rdi        # 202008 <__dso_handle>
 86e:	e8 0d ff ff ff       	callq  780 <__cxa_finalize@plt>
 873:	e8 48 ff ff ff       	callq  7c0 <deregister_tm_clones>
 878:	c6 05 a9 17 20 00 01 	movb   $0x1,0x2017a9(%rip)        # 202028 <completed.7698>
 87f:	5d                   	pop    %rbp
 880:	c3                   	retq   
 881:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 888:	f3 c3                	repz retq 
 88a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000000890 <frame_dummy>:
 890:	55                   	push   %rbp
 891:	48 89 e5             	mov    %rsp,%rbp
 894:	5d                   	pop    %rbp
 895:	e9 66 ff ff ff       	jmpq   800 <register_tm_clones>

000000000000089a <blank_line>:
 89a:	55                   	push   %rbp
 89b:	48 89 e5             	mov    %rsp,%rbp
 89e:	48 83 ec 10          	sub    $0x10,%rsp
 8a2:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
 8a6:	eb 37                	jmp    8df <blank_line+0x45>
 8a8:	e8 c3 fe ff ff       	callq  770 <__ctype_b_loc@plt>
 8ad:	48 8b 08             	mov    (%rax),%rcx
 8b0:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 8b4:	48 8d 50 01          	lea    0x1(%rax),%rdx
 8b8:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
 8bc:	0f b6 00             	movzbl (%rax),%eax
 8bf:	48 0f be c0          	movsbq %al,%rax
 8c3:	48 01 c0             	add    %rax,%rax
 8c6:	48 01 c8             	add    %rcx,%rax
 8c9:	0f b7 00             	movzwl (%rax),%eax
 8cc:	0f b7 c0             	movzwl %ax,%eax
 8cf:	25 00 20 00 00       	and    $0x2000,%eax
 8d4:	85 c0                	test   %eax,%eax
 8d6:	75 07                	jne    8df <blank_line+0x45>
 8d8:	b8 00 00 00 00       	mov    $0x0,%eax
 8dd:	eb 10                	jmp    8ef <blank_line+0x55>
 8df:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 8e3:	0f b6 00             	movzbl (%rax),%eax
 8e6:	84 c0                	test   %al,%al
 8e8:	75 be                	jne    8a8 <blank_line+0xe>
 8ea:	b8 01 00 00 00       	mov    $0x1,%eax
 8ef:	c9                   	leaveq 
 8f0:	c3                   	retq   

00000000000008f1 <read_line>:
 8f1:	55                   	push   %rbp
 8f2:	48 89 e5             	mov    %rsp,%rbp
 8f5:	48 83 ec 10          	sub    $0x10,%rsp
 8f9:	48 8b 05 c8 17 20 00 	mov    0x2017c8(%rip),%rax        # 2020c8 <infile>
 900:	48 89 c2             	mov    %rax,%rdx
 903:	be 84 00 00 00       	mov    $0x84,%esi
 908:	48 8d 3d 31 17 20 00 	lea    0x201731(%rip),%rdi        # 202040 <input_string>
 90f:	e8 1c fe ff ff       	callq  730 <fgets@plt>
 914:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
 918:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
 91d:	74 12                	je     931 <read_line+0x40>
 91f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 923:	48 89 c7             	mov    %rax,%rdi
 926:	e8 6f ff ff ff       	callq  89a <blank_line>
 92b:	85 c0                	test   %eax,%eax
 92d:	74 02                	je     931 <read_line+0x40>
 92f:	eb c8                	jmp    8f9 <read_line+0x8>
 931:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
 936:	75 16                	jne    94e <read_line+0x5d>
 938:	48 8d 3d e9 01 00 00 	lea    0x1e9(%rip),%rdi        # b28 <_IO_stdin_used+0x8>
 93f:	e8 bc fd ff ff       	callq  700 <puts@plt>
 944:	bf 08 00 00 00       	mov    $0x8,%edi
 949:	e8 12 fe ff ff       	callq  760 <exit@plt>
 94e:	48 8d 3d eb 16 20 00 	lea    0x2016eb(%rip),%rdi        # 202040 <input_string>
 955:	e8 b6 fd ff ff       	callq  710 <strlen@plt>
 95a:	89 45 f4             	mov    %eax,-0xc(%rbp)
 95d:	8b 45 f4             	mov    -0xc(%rbp),%eax
 960:	83 e8 01             	sub    $0x1,%eax
 963:	48 63 d0             	movslq %eax,%rdx
 966:	48 8d 05 d3 16 20 00 	lea    0x2016d3(%rip),%rax        # 202040 <input_string>
 96d:	c6 04 02 00          	movb   $0x0,(%rdx,%rax,1)
 971:	48 8d 05 c8 16 20 00 	lea    0x2016c8(%rip),%rax        # 202040 <input_string>
 978:	c9                   	leaveq 
 979:	c3                   	retq   

000000000000097a <test_pass_phrase>:
 97a:	55                   	push   %rbp
 97b:	48 89 e5             	mov    %rsp,%rbp
 97e:	48 83 ec 10          	sub    $0x10,%rsp
 982:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
 986:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 98a:	48 8d 35 ae 01 00 00 	lea    0x1ae(%rip),%rsi        # b3f <_IO_stdin_used+0x1f>
 991:	48 89 c7             	mov    %rax,%rdi
 994:	e8 a7 fd ff ff       	callq  740 <strcmp@plt>
 999:	85 c0                	test   %eax,%eax
 99b:	74 16                	je     9b3 <test_pass_phrase+0x39>
 99d:	48 8d 3d bc 01 00 00 	lea    0x1bc(%rip),%rdi        # b60 <_IO_stdin_used+0x40>
 9a4:	e8 57 fd ff ff       	callq  700 <puts@plt>
 9a9:	bf 04 00 00 00       	mov    $0x4,%edi
 9ae:	e8 ad fd ff ff       	callq  760 <exit@plt>
 9b3:	90                   	nop
 9b4:	c9                   	leaveq 
 9b5:	c3                   	retq   

00000000000009b6 <main>:
 9b6:	55                   	push   %rbp
 9b7:	48 89 e5             	mov    %rsp,%rbp
 9ba:	48 83 ec 20          	sub    $0x20,%rsp
 9be:	89 7d ec             	mov    %edi,-0x14(%rbp)
 9c1:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
 9c5:	83 7d ec 01          	cmpl   $0x1,-0x14(%rbp)
 9c9:	75 13                	jne    9de <main+0x28>
 9cb:	48 8b 05 4e 16 20 00 	mov    0x20164e(%rip),%rax        # 202020 <stdin@@GLIBC_2.2.5>
 9d2:	48 89 05 ef 16 20 00 	mov    %rax,0x2016ef(%rip)        # 2020c8 <infile>
 9d9:	e9 88 00 00 00       	jmpq   a66 <main+0xb0>
 9de:	83 7d ec 02          	cmpl   $0x2,-0x14(%rbp)
 9e2:	75 5d                	jne    a41 <main+0x8b>
 9e4:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 9e8:	48 83 c0 08          	add    $0x8,%rax
 9ec:	48 8b 00             	mov    (%rax),%rax
 9ef:	48 8d 35 90 01 00 00 	lea    0x190(%rip),%rsi        # b86 <_IO_stdin_used+0x66>
 9f6:	48 89 c7             	mov    %rax,%rdi
 9f9:	e8 52 fd ff ff       	callq  750 <fopen@plt>
 9fe:	48 89 05 c3 16 20 00 	mov    %rax,0x2016c3(%rip)        # 2020c8 <infile>
 a05:	48 8b 05 bc 16 20 00 	mov    0x2016bc(%rip),%rax        # 2020c8 <infile>
 a0c:	48 85 c0             	test   %rax,%rax
 a0f:	75 55                	jne    a66 <main+0xb0>
 a11:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 a15:	48 83 c0 08          	add    $0x8,%rax
 a19:	48 8b 10             	mov    (%rax),%rdx
 a1c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 a20:	48 8b 00             	mov    (%rax),%rax
 a23:	48 89 c6             	mov    %rax,%rsi
 a26:	48 8d 3d 5b 01 00 00 	lea    0x15b(%rip),%rdi        # b88 <_IO_stdin_used+0x68>
 a2d:	b8 00 00 00 00       	mov    $0x0,%eax
 a32:	e8 e9 fc ff ff       	callq  720 <printf@plt>
 a37:	bf 08 00 00 00       	mov    $0x8,%edi
 a3c:	e8 1f fd ff ff       	callq  760 <exit@plt>
 a41:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 a45:	48 8b 00             	mov    (%rax),%rax
 a48:	48 89 c6             	mov    %rax,%rsi
 a4b:	48 8d 3d 53 01 00 00 	lea    0x153(%rip),%rdi        # ba5 <_IO_stdin_used+0x85>
 a52:	b8 00 00 00 00       	mov    $0x0,%eax
 a57:	e8 c4 fc ff ff       	callq  720 <printf@plt>
 a5c:	bf 08 00 00 00       	mov    $0x8,%edi
 a61:	e8 fa fc ff ff       	callq  760 <exit@plt>
 a66:	48 8d 3d 53 01 00 00 	lea    0x153(%rip),%rdi        # bc0 <_IO_stdin_used+0xa0>
 a6d:	b8 00 00 00 00       	mov    $0x0,%eax
 a72:	e8 a9 fc ff ff       	callq  720 <printf@plt>
 a77:	e8 75 fe ff ff       	callq  8f1 <read_line>
 a7c:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
 a80:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 a84:	48 89 c7             	mov    %rax,%rdi
 a87:	e8 ee fe ff ff       	callq  97a <test_pass_phrase>
 a8c:	48 8d 3d 55 01 00 00 	lea    0x155(%rip),%rdi        # be8 <_IO_stdin_used+0xc8>
 a93:	e8 68 fc ff ff       	callq  700 <puts@plt>
 a98:	b8 00 00 00 00       	mov    $0x0,%eax
 a9d:	c9                   	leaveq 
 a9e:	c3                   	retq   
 a9f:	90                   	nop

0000000000000aa0 <__libc_csu_init>:
 aa0:	41 57                	push   %r15
 aa2:	41 56                	push   %r14
 aa4:	49 89 d7             	mov    %rdx,%r15
 aa7:	41 55                	push   %r13
 aa9:	41 54                	push   %r12
 aab:	4c 8d 25 ce 12 20 00 	lea    0x2012ce(%rip),%r12        # 201d80 <__frame_dummy_init_array_entry>
 ab2:	55                   	push   %rbp
 ab3:	48 8d 2d ce 12 20 00 	lea    0x2012ce(%rip),%rbp        # 201d88 <__init_array_end>
 aba:	53                   	push   %rbx
 abb:	41 89 fd             	mov    %edi,%r13d
 abe:	49 89 f6             	mov    %rsi,%r14
 ac1:	4c 29 e5             	sub    %r12,%rbp
 ac4:	48 83 ec 08          	sub    $0x8,%rsp
 ac8:	48 c1 fd 03          	sar    $0x3,%rbp
 acc:	e8 07 fc ff ff       	callq  6d8 <_init>
 ad1:	48 85 ed             	test   %rbp,%rbp
 ad4:	74 20                	je     af6 <__libc_csu_init+0x56>
 ad6:	31 db                	xor    %ebx,%ebx
 ad8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 adf:	00 
 ae0:	4c 89 fa             	mov    %r15,%rdx
 ae3:	4c 89 f6             	mov    %r14,%rsi
 ae6:	44 89 ef             	mov    %r13d,%edi
 ae9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
 aed:	48 83 c3 01          	add    $0x1,%rbx
 af1:	48 39 dd             	cmp    %rbx,%rbp
 af4:	75 ea                	jne    ae0 <__libc_csu_init+0x40>
 af6:	48 83 c4 08          	add    $0x8,%rsp
 afa:	5b                   	pop    %rbx
 afb:	5d                   	pop    %rbp
 afc:	41 5c                	pop    %r12
 afe:	41 5d                	pop    %r13
 b00:	41 5e                	pop    %r14
 b02:	41 5f                	pop    %r15
 b04:	c3                   	retq   
 b05:	90                   	nop
 b06:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 b0d:	00 00 00 

0000000000000b10 <__libc_csu_fini>:
 b10:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000000b14 <_fini>:
 b14:	48 83 ec 08          	sub    $0x8,%rsp
 b18:	48 83 c4 08          	add    $0x8,%rsp
 b1c:	c3                   	retq   
