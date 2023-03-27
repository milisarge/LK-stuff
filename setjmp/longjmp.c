#include <lib/setjmp.h>

__attribute__((naked,noreturn))
void longjmp(jmp_buf buf, int ret)
{
    (void)buf;
    (void)ret;
    __asm(
        "ld s0,    0(a0)\n"
        "ld s1,    8(a0)\n"
        "ld s2,    16(a0)\n"
        "ld s3,    24(a0)\n"
        "ld s4,    32(a0)\n"
        "ld s5,    40(a0)\n"
        "ld s6,    48(a0)\n"
        "ld s7,    56(a0)\n"
        "ld s8,    64(a0)\n"
        "ld s9,    72(a0)\n"
        "ld s10,   80(a0)\n"
        "ld s11,   88(a0)\n"
        "ld sp,    96(a0)\n"
        "ld ra,    104(a0)\n"
        "seqz a0, a1\n"
        "add a0, a0, a1\n"
        "ret\n"
    );
}
