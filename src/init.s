.globl init, addr, len

.data
addr:
    .long 0x0
len:
    .long 0x0

.text
init:
    push %r15
    push %r14

    mov $addr, %r15         #address of the addr global variable
    mov $addr, %r14         #address of the len global variable

    call allocate_safemem
    call test_null

    pop %r14
    pop %r15
    ret

allocate_safemem:
    push %rsi
    MOV %rdi, %rsi      #size of the to-be-allocated memory
    push %rdi
    XOR %rdi, %rdi      #address of the to-be-allocated memory, NULL (no preference)
    push %rdx
    MOV $0x2, %rdx      #0babc -> a: EXEC, b: WRITE, c: READ (prot), here we only want to be able to write into memory
    push %r10
    MOV $0x22,%r10      #flags, here private (0x02) and anonymus (0x20), so that it doesn't get swapped to unsafe diskspace 
    push %r8
    MOV $1,   %r8       #filedescriptor of output, 1 is the standard output
    push %r9
    xor %r9,  %r9       #null the offset, we want the entire space
    push %rax
    MOV $9,   %rax      #sys_mmap is the 9th system call in the linux x64 kernel
    syscall 

    MOV %rax, (%r15)    #update addr
    MOV %rdi, (%r14)    #update len
    
    pop %rax
    pop %r9
    pop %r8
    pop %r10
    pop %rdx
    pop %rdi
    pop %rsi