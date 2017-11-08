.globl _start

#Integer arithmetic with very big numbers
#
#
#
#
#

.data

error:
    .ascii "Info: Something bad happened\n"
ok:
    .ascii "Info: Everything OK\n"


.text
_start:
    push %rdi
    MOV $0xfffff, %rdi #Size of the memory to allocate
    call init 
    
    CMP $1, %rax
    JE endok              #if not 1, then something bad happened

    MOV $error, %rsi
    MOV $30, %rdx
    call print
    JMP end
endok:

    MOV $ok, %rsi
    MOV $21, %rdx
    call print
end:
    call del

    MOV $11,  %rax      #The 11th systemcall is sys_munmap, which deallocates the memory
    MOV addr, %rdi      #address of the allocated memory
    MOV len,  %rsi      #length of the allocated memory
    syscall

nope:
    JMP nope
    MOV $60, %rax       #exiting...
    XOR %rdi, %rdi
    syscall


print:
    MOV $1, %rax
    MOV $1, %rdi
    syscall
    ret