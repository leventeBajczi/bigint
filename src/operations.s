.globl complbit

.text
complbit:
    XORQ $0xffffffffffffffff, (%rdi)
    ADDQ %rsi, (%rdi)
    pushf
    pop %rax
    ANDQ $0x01, %rax
    
    ret
