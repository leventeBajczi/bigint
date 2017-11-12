.globl divrest

#Calculates a ≡ x (mod m), where a is at addr+ptr and m is at addr+ptr+2*keylen+2 and stores it in the former

.text
divrest:
    push %r15   #counter
    push %r14   #current content
    push %r12   #starting address, addr+ptr
    push %r11   #starting address 2, addr+ptr+2*keylen+2

    MOV ptr , %r12

    MOV %r12, %r11
    ADD keylen, %r11
    INC %r11
    ADD keylen, %r11
    INC %r11

    MOV %r11, ptr(,1)
    call compl

    MOV %r12, ptr(,1) 
    
    ADD addr, %r12
loop:
    XOR %rax, %rax
    CMP (%r12), %rax
    JNE endloop
    call add
    JMP loop

endloop:
    pop %r11
    pop %r12
    pop %r14
    pop %r15

    ret
