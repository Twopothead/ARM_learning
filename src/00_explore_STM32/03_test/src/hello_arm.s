@https://community.arm.com/processors/b/blog/posts/hello-world-in-assembly
    .syntax unified

    @ --------------------------------
.global main
main:
    @ Stack the return address (lr) in addition to a dummy register (ip) to
    @ keep the stack 8-byte aligned.
    push    {ip, lr}

   .rept 120
    ldr     r0, =message
    bl      printf
    .endr
    @ Exit from 'main'. This is like 'return 0' in C.
    mov     r0, #0    @ Return 0.

    @ Pop the dummy ip to reverse our alignment fix, and pop the original lr
    @ value directly into pc — the Program Counter — to return.
    pop     {ip, pc}

@ count seta #1 
    mov r0,#120
 .rept 120
    sub r0,#1
 .endr

    @ --------------------------------
    @ Data for the printf calls. The GNU assembler's ".asciz" directive
    @ automatically adds a NULL character termination.
message:
    .asciz "Hello, world.\n"
