.globl compl

#Creates two's complement from a number, effectively negating it

#uses one unit of storage (keylen+1) after the current pos (ptr)

.text
compl:
    push %r15   #counter
    push %r14   #current content
    push %r13   #starting address, addr+ptr
    push %r12   #to get the carry flag

    MOV addr, %r13
    ADD ptr , %r13
    
    MOV keylen, %r15

    MOV $0x1, %r12
    push %r12
loop:
    CMP $0x0, %r15
    JLE endloop

    MOV (%r13,%r15,1), %r14         #Read 8 bytes into register r14 
    XORQ $0xffffffffffffffff, %r14  #invert the digits one by one
    
    pop %r12
    AND $0x1, %r12                  #Carry flag
    ADD %r12, %r14                  #Adding the carry bit to the number

    pushf

    MOV %r14, (%r13,%r15,1)         #Write the two's complement of the number back into memory                

    SUB $8, %r15
    JMP loop

endloop:
    pop %r12
    AND $0x1, %r12
    MOV %r12, (%r13,%r15,1)         #Write out the carry flag on the keylen+1st byte
         
    pop %r12
    pop %r13
    pop %r14
    pop %r15
    ret
