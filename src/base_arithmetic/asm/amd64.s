.globl complbit, addbit, mulbit

.text
complbit:
    XORQ $0xffffffffffffffff, (%rdi)
    ADDQ %rsi, (%rdi)
    pushf
    pop %rax
    ANDQ $0x01, %rax
    
    ret



addbit:
    ADDQ %rdi, (%rsi)       #Add carry
    JC carry
    push %r15
    MOVQ (%rsi), %r15
    ADDQ %r15, (%rdx)
    pop %r15
    JC carry
    XORQ %rax, %rax
    ret
carry: 
    MOVQ $0x01, %rax
    ret


mulbit:
    MOVQ  (%rsi), %rax
    MULQ  (%rdx)
    ADDQ   %rax, (%rcx)
    JNC nocarry1
    ADDQ $0x01, %rdx
nocarry1:
    ADDQ   %rdi, (%rcx)
    JNC nocarry
    ADDQ $0x01, %rdx
nocarry:
    MOV %rdx, %rax

    ret
