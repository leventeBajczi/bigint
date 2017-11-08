.globl _start

#Integer arithmetic with very big numbers
#
#
#
#
#

.data
.text
_start:
    push %rdi
    MOV $0xf, %rdi #Size of the memory to allocate
    INC %rdi
    call init 
    #cmp $1, %rax
    #jne end              #if not 1, then something bad happened
end:
    JMP end
    mov $60, %rax
    xor %rdi, %rdi
    syscall
