
#include <stdio.h>

#define A 3123

#define xstr(s) str(s)
#define str(s) #s
     
int
main() {
	const char *a = xstr(A);
	puts(a);

	return 0;
}

