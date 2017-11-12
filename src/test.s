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
    MOV $0x10,  %rsi #Key length in bytes, must be 8k+0
    MOV $0x01000000, %rdi #Size of the memory to allocate, 10 x (keysize+1) is a recommended minimum, 16MiB is the maximum
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

    call compl
    call add
    call mul
end:
    call del

    MOV $11,  %rax      #The 11th systemcall is sys_munmap, which deallocates the memory
    MOV addr, %rdi      #address of the allocated memory
    MOV len,  %rsi      #length of the allocated memory
    syscall

nope:
    MOV $60, %rax       #exiting...
    XOR %rdi, %rdi
    syscall


print:
    MOV $1, %rax
    MOV $1, %rdi
    syscall
    ret