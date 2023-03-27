#ifndef SETJMP_H
#define SETJMP_H

typedef void *jmp_buf[26];

int setjmp(jmp_buf);
_Noreturn void longjmp(jmp_buf, int);

#endif /* _SETJMP_H_ */
