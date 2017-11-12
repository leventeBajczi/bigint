.globl compl

#Creates two's complement from a number, effectively negating it

#uses rwo unit of storage (2*keylen+2) after the current pos (ptr)

.text
compl:
    push %r15   #counter
    push %r14   #current content
    push %r13   #starting address, addr+ptr
    push %r12   #to get the carry flag

    MOV addr, %r13
    ADD ptr , %r13
    
    MOV keylen, %r15
    ADD keylen, %r15
    ADD $0x08,  %r15

    MOV $0x1, %r12
    push %r12
loop:
    MOV (%r13,%r15,1), %r14         #Read 8 bytes into register r14 
    XORQ $0xffffffffffffffff, %r14  #invert the digits one by one
    
    pop %r12
    AND $0x1, %r12                  #Carry flag
    ADD %r12, %r14                  #Adding the carry bit to the number

    pushf

    MOV %r14, (%r13,%r15,1)         #Write the two's complement of the number back into memory                

    SUB $8, %r15
    CMP $0x0, %r15
    JGE loop

endloop:
    popf
         
    pop %r12
    pop %r13
    pop %r14
    pop %r15
    ret
