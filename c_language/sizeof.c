#include <stdio.h>

int
main() {
	printf("%lu\n", sizeof(int)); // for gcc, it's 4.
	printf("%lu\n", sizeof(sizeof(int))); // for 64bit platform, it's (maybe mostly) 8.

	return 0;
}
