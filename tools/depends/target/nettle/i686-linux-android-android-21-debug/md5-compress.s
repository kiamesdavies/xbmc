
































	






	.file "md5-compress.asm"

	
	
	.text
	.align 16

.globl _nettle_md5_compress
.type _nettle_md5_compress,%function
_nettle_md5_compress:
	

				
				
				
	pushl	%ebx		
	pushl	%ebp		
	pushl	%esi		
	pushl	%edi		

	
	movl	20(%esp),%ebp
	movl	(%ebp),   %eax
	movl	4(%ebp),  %ebx
	movl	8(%ebp),  %ecx
	movl	12(%ebp), %edx

	
	
	movl	24(%esp), %esi

	
	addl	$0xd76aa478, %eax
	
	movl	%edx, %ebp
	xorl	%ecx, %ebp
	andl	%ebx, %ebp
	xorl	%edx, %ebp
	addl	(%esi), %eax
	addl	%ebp, %eax
	roll	$7, %eax
	addl	%ebx, %eax
	
	addl	$0xe8c7b756, %edx
	
	movl	%ecx, %ebp
	xorl	%ebx, %ebp
	andl	%eax, %ebp
	xorl	%ecx, %ebp
	addl	4(%esi), %edx
	addl	%ebp, %edx
	roll	$12, %edx
	addl	%eax, %edx
	
	addl	$0x242070db, %ecx
	
	movl	%ebx, %ebp
	xorl	%eax, %ebp
	andl	%edx, %ebp
	xorl	%ebx, %ebp
	addl	8(%esi), %ecx
	addl	%ebp, %ecx
	roll	$17, %ecx
	addl	%edx, %ecx
	
	addl	$0xc1bdceee, %ebx
	
	movl	%eax, %ebp
	xorl	%edx, %ebp
	andl	%ecx, %ebp
	xorl	%eax, %ebp
	addl	12(%esi), %ebx
	addl	%ebp, %ebx
	roll	$22, %ebx
	addl	%ecx, %ebx
	
	addl	$0xf57c0faf, %eax
	
	movl	%edx, %ebp
	xorl	%ecx, %ebp
	andl	%ebx, %ebp
	xorl	%edx, %ebp
	addl	16(%esi), %eax
	addl	%ebp, %eax
	roll	$7, %eax
	addl	%ebx, %eax
	
	addl	$0x4787c62a, %edx
	
	movl	%ecx, %ebp
	xorl	%ebx, %ebp
	andl	%eax, %ebp
	xorl	%ecx, %ebp
	addl	20(%esi), %edx
	addl	%ebp, %edx
	roll	$12, %edx
	addl	%eax, %edx
	
	addl	$0xa8304613, %ecx
	
	movl	%ebx, %ebp
	xorl	%eax, %ebp
	andl	%edx, %ebp
	xorl	%ebx, %ebp
	addl	24(%esi), %ecx
	addl	%ebp, %ecx
	roll	$17, %ecx
	addl	%edx, %ecx
	
	addl	$0xfd469501, %ebx
	
	movl	%eax, %ebp
	xorl	%edx, %ebp
	andl	%ecx, %ebp
	xorl	%eax, %ebp
	addl	28(%esi), %ebx
	addl	%ebp, %ebx
	roll	$22, %ebx
	addl	%ecx, %ebx
	
	addl	$0x698098d8, %eax
	
	movl	%edx, %ebp
	xorl	%ecx, %ebp
	andl	%ebx, %ebp
	xorl	%edx, %ebp
	addl	32(%esi), %eax
	addl	%ebp, %eax
	roll	$7, %eax
	addl	%ebx, %eax
	
	addl	$0x8b44f7af, %edx
	
	movl	%ecx, %ebp
	xorl	%ebx, %ebp
	andl	%eax, %ebp
	xorl	%ecx, %ebp
	addl	36(%esi), %edx
	addl	%ebp, %edx
	roll	$12, %edx
	addl	%eax, %edx
	
	addl	$0xffff5bb1, %ecx
	
	movl	%ebx, %ebp
	xorl	%eax, %ebp
	andl	%edx, %ebp
	xorl	%ebx, %ebp
	addl	40(%esi), %ecx
	addl	%ebp, %ecx
	roll	$17, %ecx
	addl	%edx, %ecx
	
	addl	$0x895cd7be, %ebx
	
	movl	%eax, %ebp
	xorl	%edx, %ebp
	andl	%ecx, %ebp
	xorl	%eax, %ebp
	addl	44(%esi), %ebx
	addl	%ebp, %ebx
	roll	$22, %ebx
	addl	%ecx, %ebx
	
	addl	$0x6b901122, %eax
	
	movl	%edx, %ebp
	xorl	%ecx, %ebp
	andl	%ebx, %ebp
	xorl	%edx, %ebp
	addl	48(%esi), %eax
	addl	%ebp, %eax
	roll	$7, %eax
	addl	%ebx, %eax
	
	addl	$0xfd987193, %edx
	
	movl	%ecx, %ebp
	xorl	%ebx, %ebp
	andl	%eax, %ebp
	xorl	%ecx, %ebp
	addl	52(%esi), %edx
	addl	%ebp, %edx
	roll	$12, %edx
	addl	%eax, %edx
	
	addl	$0xa679438e, %ecx
	
	movl	%ebx, %ebp
	xorl	%eax, %ebp
	andl	%edx, %ebp
	xorl	%ebx, %ebp
	addl	56(%esi), %ecx
	addl	%ebp, %ecx
	roll	$17, %ecx
	addl	%edx, %ecx
	
	addl	$0x49b40821, %ebx
	
	movl	%eax, %ebp
	xorl	%edx, %ebp
	andl	%ecx, %ebp
	xorl	%eax, %ebp
	addl	60(%esi), %ebx
	addl	%ebp, %ebx
	roll	$22, %ebx
	addl	%ecx, %ebx
	
        
	addl	$0xf61e2562, %eax
	
	movl	%ecx, %ebp
	xorl	%ebx, %ebp
	andl	%edx, %ebp
	xorl	%ecx, %ebp
	addl	4(%esi), %eax
	addl	%ebp, %eax
	roll	$5, %eax
	addl	%ebx, %eax
        
	addl	$0xc040b340, %edx
	
	movl	%ebx, %ebp
	xorl	%eax, %ebp
	andl	%ecx, %ebp
	xorl	%ebx, %ebp
	addl	24(%esi), %edx
	addl	%ebp, %edx
	roll	$9, %edx
	addl	%eax, %edx
        
	addl	$0x265e5a51, %ecx
	
	movl	%eax, %ebp
	xorl	%edx, %ebp
	andl	%ebx, %ebp
	xorl	%eax, %ebp
	addl	44(%esi), %ecx
	addl	%ebp, %ecx
	roll	$14, %ecx
	addl	%edx, %ecx
        
	addl	$0xe9b6c7aa, %ebx
	
	movl	%edx, %ebp
	xorl	%ecx, %ebp
	andl	%eax, %ebp
	xorl	%edx, %ebp
	addl	(%esi), %ebx
	addl	%ebp, %ebx
	roll	$20, %ebx
	addl	%ecx, %ebx
        
	addl	$0xd62f105d, %eax
	
	movl	%ecx, %ebp
	xorl	%ebx, %ebp
	andl	%edx, %ebp
	xorl	%ecx, %ebp
	addl	20(%esi), %eax
	addl	%ebp, %eax
	roll	$5, %eax
	addl	%ebx, %eax
        
	addl	$0x02441453, %edx
	
	movl	%ebx, %ebp
	xorl	%eax, %ebp
	andl	%ecx, %ebp
	xorl	%ebx, %ebp
	addl	40(%esi), %edx
	addl	%ebp, %edx
	roll	$9, %edx
	addl	%eax, %edx
        
	addl	$0xd8a1e681, %ecx
	
	movl	%eax, %ebp
	xorl	%edx, %ebp
	andl	%ebx, %ebp
	xorl	%eax, %ebp
	addl	60(%esi), %ecx
	addl	%ebp, %ecx
	roll	$14, %ecx
	addl	%edx, %ecx
        
	addl	$0xe7d3fbc8, %ebx
	
	movl	%edx, %ebp
	xorl	%ecx, %ebp
	andl	%eax, %ebp
	xorl	%edx, %ebp
	addl	16(%esi), %ebx
	addl	%ebp, %ebx
	roll	$20, %ebx
	addl	%ecx, %ebx
        
	addl	$0x21e1cde6, %eax
	
	movl	%ecx, %ebp
	xorl	%ebx, %ebp
	andl	%edx, %ebp
	xorl	%ecx, %ebp
	addl	36(%esi), %eax
	addl	%ebp, %eax
	roll	$5, %eax
	addl	%ebx, %eax
        
	addl	$0xc33707d6, %edx
	
	movl	%ebx, %ebp
	xorl	%eax, %ebp
	andl	%ecx, %ebp
	xorl	%ebx, %ebp
	addl	56(%esi), %edx
	addl	%ebp, %edx
	roll	$9, %edx
	addl	%eax, %edx
        
	addl	$0xf4d50d87, %ecx
	
	movl	%eax, %ebp
	xorl	%edx, %ebp
	andl	%ebx, %ebp
	xorl	%eax, %ebp
	addl	12(%esi), %ecx
	addl	%ebp, %ecx
	roll	$14, %ecx
	addl	%edx, %ecx
        
	addl	$0x455a14ed, %ebx
	
	movl	%edx, %ebp
	xorl	%ecx, %ebp
	andl	%eax, %ebp
	xorl	%edx, %ebp
	addl	32(%esi), %ebx
	addl	%ebp, %ebx
	roll	$20, %ebx
	addl	%ecx, %ebx
        
	addl	$0xa9e3e905, %eax
	
	movl	%ecx, %ebp
	xorl	%ebx, %ebp
	andl	%edx, %ebp
	xorl	%ecx, %ebp
	addl	52(%esi), %eax
	addl	%ebp, %eax
	roll	$5, %eax
	addl	%ebx, %eax
        
	addl	$0xfcefa3f8, %edx
	
	movl	%ebx, %ebp
	xorl	%eax, %ebp
	andl	%ecx, %ebp
	xorl	%ebx, %ebp
	addl	8(%esi), %edx
	addl	%ebp, %edx
	roll	$9, %edx
	addl	%eax, %edx
        
	addl	$0x676f02d9, %ecx
	
	movl	%eax, %ebp
	xorl	%edx, %ebp
	andl	%ebx, %ebp
	xorl	%eax, %ebp
	addl	28(%esi), %ecx
	addl	%ebp, %ecx
	roll	$14, %ecx
	addl	%edx, %ecx
        
	addl	$0x8d2a4c8a, %ebx
	
	movl	%edx, %ebp
	xorl	%ecx, %ebp
	andl	%eax, %ebp
	xorl	%edx, %ebp
	addl	48(%esi), %ebx
	addl	%ebp, %ebx
	roll	$20, %ebx
	addl	%ecx, %ebx        

        
	addl	$0xfffa3942, %eax
	
	movl	%ebx, %ebp
	xorl	%ecx, %ebp
	xorl	%edx, %ebp
	addl	20(%esi), %eax
	addl	%ebp, %eax
	roll	$4, %eax
	addl	%ebx, %eax
        
	addl	$0x8771f681, %edx
	
	movl	%eax, %ebp
	xorl	%ebx, %ebp
	xorl	%ecx, %ebp
	addl	32(%esi), %edx
	addl	%ebp, %edx
	roll	$11, %edx
	addl	%eax, %edx
        
	addl	$0x6d9d6122, %ecx
	
	movl	%edx, %ebp
	xorl	%eax, %ebp
	xorl	%ebx, %ebp
	addl	44(%esi), %ecx
	addl	%ebp, %ecx
	roll	$16, %ecx
	addl	%edx, %ecx
        
	addl	$0xfde5380c, %ebx
	
	movl	%ecx, %ebp
	xorl	%edx, %ebp
	xorl	%eax, %ebp
	addl	56(%esi), %ebx
	addl	%ebp, %ebx
	roll	$23, %ebx
	addl	%ecx, %ebx
        
	addl	$0xa4beea44, %eax
	
	movl	%ebx, %ebp
	xorl	%ecx, %ebp
	xorl	%edx, %ebp
	addl	4(%esi), %eax
	addl	%ebp, %eax
	roll	$4, %eax
	addl	%ebx, %eax
        
	addl	$0x4bdecfa9, %edx
	
	movl	%eax, %ebp
	xorl	%ebx, %ebp
	xorl	%ecx, %ebp
	addl	16(%esi), %edx
	addl	%ebp, %edx
	roll	$11, %edx
	addl	%eax, %edx
        
	addl	$0xf6bb4b60, %ecx
	
	movl	%edx, %ebp
	xorl	%eax, %ebp
	xorl	%ebx, %ebp
	addl	28(%esi), %ecx
	addl	%ebp, %ecx
	roll	$16, %ecx
	addl	%edx, %ecx
        
	addl	$0xbebfbc70, %ebx
	
	movl	%ecx, %ebp
	xorl	%edx, %ebp
	xorl	%eax, %ebp
	addl	40(%esi), %ebx
	addl	%ebp, %ebx
	roll	$23, %ebx
	addl	%ecx, %ebx
        
	addl	$0x289b7ec6, %eax
	
	movl	%ebx, %ebp
	xorl	%ecx, %ebp
	xorl	%edx, %ebp
	addl	52(%esi), %eax
	addl	%ebp, %eax
	roll	$4, %eax
	addl	%ebx, %eax
        
	addl	$0xeaa127fa, %edx
	
	movl	%eax, %ebp
	xorl	%ebx, %ebp
	xorl	%ecx, %ebp
	addl	(%esi), %edx
	addl	%ebp, %edx
	roll	$11, %edx
	addl	%eax, %edx
        
	addl	$0xd4ef3085, %ecx
	
	movl	%edx, %ebp
	xorl	%eax, %ebp
	xorl	%ebx, %ebp
	addl	12(%esi), %ecx
	addl	%ebp, %ecx
	roll	$16, %ecx
	addl	%edx, %ecx
        
	addl	$0x04881d05, %ebx
	
	movl	%ecx, %ebp
	xorl	%edx, %ebp
	xorl	%eax, %ebp
	addl	24(%esi), %ebx
	addl	%ebp, %ebx
	roll	$23, %ebx
	addl	%ecx, %ebx
        
	addl	$0xd9d4d039, %eax
	
	movl	%ebx, %ebp
	xorl	%ecx, %ebp
	xorl	%edx, %ebp
	addl	36(%esi), %eax
	addl	%ebp, %eax
	roll	$4, %eax
	addl	%ebx, %eax
        
	addl	$0xe6db99e5, %edx
	
	movl	%eax, %ebp
	xorl	%ebx, %ebp
	xorl	%ecx, %ebp
	addl	48(%esi), %edx
	addl	%ebp, %edx
	roll	$11, %edx
	addl	%eax, %edx
        
	addl	$0x1fa27cf8, %ecx
	
	movl	%edx, %ebp
	xorl	%eax, %ebp
	xorl	%ebx, %ebp
	addl	60(%esi), %ecx
	addl	%ebp, %ecx
	roll	$16, %ecx
	addl	%edx, %ecx
        
	addl	$0xc4ac5665, %ebx
	
	movl	%ecx, %ebp
	xorl	%edx, %ebp
	xorl	%eax, %ebp
	addl	8(%esi), %ebx
	addl	%ebp, %ebx
	roll	$23, %ebx
	addl	%ecx, %ebx        

        
	addl	$0xf4292244, %eax
	
	movl	%edx, %ebp
	notl	%ebp
	orl	%ebx, %ebp
	xorl	%ecx, %ebp
	addl	(%esi), %eax
	addl	%ebp, %eax
	roll	$6, %eax
	addl	%ebx, %eax
        
	addl	$0x432aff97, %edx
	
	movl	%ecx, %ebp
	notl	%ebp
	orl	%eax, %ebp
	xorl	%ebx, %ebp
	addl	28(%esi), %edx
	addl	%ebp, %edx
	roll	$10, %edx
	addl	%eax, %edx
        
	addl	$0xab9423a7, %ecx
	
	movl	%ebx, %ebp
	notl	%ebp
	orl	%edx, %ebp
	xorl	%eax, %ebp
	addl	56(%esi), %ecx
	addl	%ebp, %ecx
	roll	$15, %ecx
	addl	%edx, %ecx
        
	addl	$0xfc93a039, %ebx
	
	movl	%eax, %ebp
	notl	%ebp
	orl	%ecx, %ebp
	xorl	%edx, %ebp
	addl	20(%esi), %ebx
	addl	%ebp, %ebx
	roll	$21, %ebx
	addl	%ecx, %ebx
        
	addl	$0x655b59c3, %eax
	
	movl	%edx, %ebp
	notl	%ebp
	orl	%ebx, %ebp
	xorl	%ecx, %ebp
	addl	48(%esi), %eax
	addl	%ebp, %eax
	roll	$6, %eax
	addl	%ebx, %eax
        
	addl	$0x8f0ccc92, %edx
	
	movl	%ecx, %ebp
	notl	%ebp
	orl	%eax, %ebp
	xorl	%ebx, %ebp
	addl	12(%esi), %edx
	addl	%ebp, %edx
	roll	$10, %edx
	addl	%eax, %edx
        
	addl	$0xffeff47d, %ecx
	
	movl	%ebx, %ebp
	notl	%ebp
	orl	%edx, %ebp
	xorl	%eax, %ebp
	addl	40(%esi), %ecx
	addl	%ebp, %ecx
	roll	$15, %ecx
	addl	%edx, %ecx
        
	addl	$0x85845dd1, %ebx
	
	movl	%eax, %ebp
	notl	%ebp
	orl	%ecx, %ebp
	xorl	%edx, %ebp
	addl	4(%esi), %ebx
	addl	%ebp, %ebx
	roll	$21, %ebx
	addl	%ecx, %ebx
        
	addl	$0x6fa87e4f, %eax
	
	movl	%edx, %ebp
	notl	%ebp
	orl	%ebx, %ebp
	xorl	%ecx, %ebp
	addl	32(%esi), %eax
	addl	%ebp, %eax
	roll	$6, %eax
	addl	%ebx, %eax
        
	addl	$0xfe2ce6e0, %edx
	
	movl	%ecx, %ebp
	notl	%ebp
	orl	%eax, %ebp
	xorl	%ebx, %ebp
	addl	60(%esi), %edx
	addl	%ebp, %edx
	roll	$10, %edx
	addl	%eax, %edx
        
	addl	$0xa3014314, %ecx
	
	movl	%ebx, %ebp
	notl	%ebp
	orl	%edx, %ebp
	xorl	%eax, %ebp
	addl	24(%esi), %ecx
	addl	%ebp, %ecx
	roll	$15, %ecx
	addl	%edx, %ecx
        
	addl	$0x4e0811a1, %ebx
	
	movl	%eax, %ebp
	notl	%ebp
	orl	%ecx, %ebp
	xorl	%edx, %ebp
	addl	52(%esi), %ebx
	addl	%ebp, %ebx
	roll	$21, %ebx
	addl	%ecx, %ebx
        
	addl	$0xf7537e82, %eax
	
	movl	%edx, %ebp
	notl	%ebp
	orl	%ebx, %ebp
	xorl	%ecx, %ebp
	addl	16(%esi), %eax
	addl	%ebp, %eax
	roll	$6, %eax
	addl	%ebx, %eax
        
	addl	$0xbd3af235, %edx
	
	movl	%ecx, %ebp
	notl	%ebp
	orl	%eax, %ebp
	xorl	%ebx, %ebp
	addl	44(%esi), %edx
	addl	%ebp, %edx
	roll	$10, %edx
	addl	%eax, %edx
        
	addl	$0x2ad7d2bb, %ecx
	
	movl	%ebx, %ebp
	notl	%ebp
	orl	%edx, %ebp
	xorl	%eax, %ebp
	addl	8(%esi), %ecx
	addl	%ebp, %ecx
	roll	$15, %ecx
	addl	%edx, %ecx
        
	addl	$0xeb86d391, %ebx
	
	movl	%eax, %ebp
	notl	%ebp
	orl	%ecx, %ebp
	xorl	%edx, %ebp
	addl	36(%esi), %ebx
	addl	%ebp, %ebx
	roll	$21, %ebx
	addl	%ecx, %ebx
	
	
	movl	20(%esp),%ebp
	addl	%eax, (%ebp) 
	addl	%ebx, 4(%ebp) 
	addl	%ecx, 8(%ebp) 
	addl	%edx, 12(%ebp) 

	popl	%edi
	popl	%esi
	popl	%ebp
	popl	%ebx
	ret
.size _nettle_md5_compress, . - _nettle_md5_compress

.section .note.GNU-stack,"",%progbits
