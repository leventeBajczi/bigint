.globl mul

#multiplies two keylen+1 length numbers (at ptr and ptr+keylen+1) and stores it in the space after these two (2*(keylen+1)-sized)

.text
mul:
    push %r15   #counter
    push %r14   #current content
    push %r13   #inner counter
    push %r12   #starting address, addr+ptr
    push %r11   #starting address 2, addr+ptr+keylen+8
    push %r10   #starting address of the result, addr+ptr+2*keylen+16
    push  %r9   #for calculations
    push  %r8   #for carry

    MOV addr, %r12
    ADD ptr , %r12

    MOV %r12, %r11
    ADD keylen, %r11
    ADD $0x08, %r11

    MOV %r11, %r10
    ADD keylen, %r10
    ADD $0x08, %r11

    MOV keylen, %r15
    ADD $0x08, %r15

    MOV keylen, %r9
    ADD $0x08, %r9
    push %r9
outer_loop:
    CMP $0x0, %r15
    JL endloop
    MOV (%r11,%r15,1), %rax         #Read 8 bytes into register rax
    MOV keylen, %r13
    INC %r13
    push %r9

inner_loop:
    CMP $0x0, %r13
    JL endinner
    MOV (%r12,%r13,1), %r14         #Read 8 bytes into register r14
    MUL %r14
    pop %r9
    ADD %rax, (%r10, %r9, 1)
    JNC nocarry
    push %r9
handlecarry:
    DEC %r9
    ADD $0x01, (%r10, %r9, 1)
    JC handlecarry
    pop %r9
nocarry:
    DEC %r9
    ADD %rdx, (%r10, %r9, 1)
    JNC nocarry2
    push %r9
handlecarry2:
    DEC %r9
    ADD $0x01, (%r10, %r9, 1)
    JC handlecarry2
    pop %r9
nocarry2:
    push %r9
    DEC %r13
    JMP inner_loop
endinner:
    pop %r9
    pop %r9
    INC %r9
    DEC %r15
    push %r9
    JMP outer_loop

endloop:
    pop %r9
    pop %r8
    pop %r9
    pop %r10
    pop %r11
    pop %r12
    pop %r13
    pop %r14
    pop %r15

    ret
