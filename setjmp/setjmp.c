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
