.globl add

#Adds two 2*keylen+2 length numbers (at ptr and ptr+2*keylen+2) and stores it in the former

.text
add:
    push %r15   #counter
    push %r14   #current content
    push %r13   #current content 2
    push %r12   #starting address, addr+ptr
    push %r11   #starting address 2, addr+ptr+keylen+8
    push %r10   #to get the carry flag

    MOV addr, %r12
    ADD ptr , %r12

    MOV %r12, %r11
    ADD keylen, %r11
    ADD $0x08, %r11
    ADD keylen, %r11
    ADD $0x08, %r11

    MOV keylen, %r15
    ADD keylen, %r15
    ADD $0x08, %r15

    MOV $0x0, %r10                  #start with no carry
    push %r10
loop:
    MOV (%r12,%r15,1), %r14         #Read 8 bytes into register r14 
    MOV (%r11,%r15,1), %r13         #Read 8 bytes into register r13
    
    pop %r10
    AND $0x1, %r10                  #Carry flag

    ADD %r10, %r13                  #Adding the carry bit to the number
    JC join                         #if we jump here, then r13 must be 0, so r14 can be left as-is to be passed along
nocarry:                            
    ADD %r13, %r14                  #summing the two numbers 
join:
    pushf

    MOV %r14, (%r12,%r15,1)         #Write the two number's sum back into memory                

    SUB $8, %r15
    CMP $0x0, %r15
    JGE loop

endloop:
    popf

    pop %r10
    pop %r11 
    pop %r12
    pop %r13
    pop %r14
    pop %r15
    ret
