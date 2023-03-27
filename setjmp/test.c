#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <app.h>
#include <platform.h>
#include <kernel/thread.h>
#include <lk/console_cmd.h>

#include <inttypes.h>
#include <lib/setjmp.h>

static jmp_buf buf;

void second() {
	printf("second\n");         // prints
	longjmp(buf,1);             // jumps back to where setjmp was called - making setjmp now return 1
}

void first() {
	second();
	printf("first\n");          // does not print
}
	
static int jmptest(int argc, const console_cmd_args *argv) {

	if (!setjmp(buf))
		first();                // when executed, setjmp returned 0
	else                        // when longjmp jumps back, setjmp returns 1
		printf("main\n");       // prints
	return 0;
}

STATIC_COMMAND_START
STATIC_COMMAND("jmptest", "jmptest tests", &jmptest)
STATIC_COMMAND_END(jmptest);

APP_START(jmptest)
APP_END

