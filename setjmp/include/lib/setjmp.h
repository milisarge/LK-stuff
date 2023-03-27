#ifndef SETJMP_H
#define SETJMP_H



typedef void *jmp_buf[26];

int setjmp(jmp_buf);
_Noreturn void longjmp(jmp_buf, int);

#define setjmp __builtin_setjmp
#define longjmp __builtin_longjmp

#endif /* _SETJMP_H_ */
