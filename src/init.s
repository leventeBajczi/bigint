.globl init, addr, len, ptr, del

.data
addr:                   #address of the VM allocated
    .quad 0x0
len:                    #length of the VM allocated
    .quad 0x0
ptr:                    #pointer to the unused part of the VM (relative to addr)
    .quad 0x0


.text

del:                    #Test_null writes some testdata to the VM, therefore deletes all the stored data
    jmp test_null

init:                   #Allocate memory
    JMP allocate_safemem

allocate_safemem:

    MOV %rdi, len(,1)   #update len

    push %r10
    push %r8
    push %r9

    MOV %rdi, %rsi      #size of the to-be-allocated memory
    XOR %rdi, %rdi      #address of the to-be-allocated memory, NULL (no preference)
    MOV $0x2, %rdx      #0babc -> a: EXEC, b: WRITE, c: READ (prot), here we only want to be able to write into memory
    MOV $0x22,%r10      #flags, here private (0x02) and anonymus (0x20), so that it doesn't get swapped to unsafe diskspace 
    MOV $1,   %r8       #filedescriptor of output, 1 is the standard output
    xor %r9,  %r9       #null the offset, we want the entire space
    MOV $9,   %rax      #sys_mmap is the 9th system call in the linux x64 kernel
    syscall 

    MOV %rax, addr(,1)  #update addr
    
    pop %r10
    pop %r8
    pop %r9

    jmp test_null
test_null:

    push %r15
    push %r14
    push %r13
    push %r12

    MOV addr, %r15

    CMP $0x0, %r15              #if the address is still 0x00000000, there is a good reason to believe it didn't work
    JE  test_bad

    MOV len, %r14
    MOV $0xffffffff, %r13       #store testdata in r13
    XOR %r12, %r12

iteration:
    ADD $8, %r12
    CMP %r12, %r14              #all good
    JLE test_good
    MOV %r13, -8(%r15,%r12,1)   #Write the testdata to the last available address

    MOV -8(%r15,%r12,1), %r11   #Reading back the data, checking for integrity
    CMP %r11, %r13
    JNE test_bad

    JMP iteration
test_bad:                       #Arrive here if something bad happened
    pop %r15
    pop %r14
    pop %r13
    pop %r12

    MOV $0, %rax
    sti
    ret
test_good:                      #Arrive here if we have $len allocated bytes starting at $addr
    pop %r15
    pop %r14
    pop %r13
    pop %r12

    MOV $1, %rax 
    ret
