#include <lib/setjmp.h>

__attribute__((naked,returns_twice))
int setjmp(jmp_buf buf)
{
    (void)buf;
    __asm(
        "sd s0,    0(a0)\n"
        "sd s1,    8(a0)\n"
        "sd s2,    16(a0)\n"
        "sd s3,    24(a0)\n"
        "sd s4,    32(a0)\n"
        "sd s5,    40(a0)\n"
        "sd s6,    48(a0)\n"
        "sd s7,    56(a0)\n"
        "sd s8,    64(a0)\n"
        "sd s9,    72(a0)\n"
        "sd s10,   80(a0)\n"
        "sd s11,   88(a0)\n"
        "sd sp,    96(a0)\n"
        "sd ra,    104(a0)\n"
        "li a0, 0\n"	
        "ret\n"
    );
}
