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
    call powmod 

loop:
    NOP
    
    JMP loop

end:
    mov $60, %rax
    xor %rdi, %rdi
    syscall
