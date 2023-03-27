/* 
this code is ported from musl codebase
https://github.com/riscvarchive/riscv-musl/blob/staging
 
musl as a whole is licensed under the following standard MIT license:

----------------------------------------------------------------------
Copyright © 2005-2014 Rich Felker, et al.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
----------------------------------------------------------------------
*/

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
