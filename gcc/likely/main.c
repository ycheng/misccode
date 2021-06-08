
#include <stdio.h>

#define likely(x)   (__builtin_expect(!!(x),1))
#define unlikely(x) (__builtin_expect(!!(x),0))

int main() {
	int a = 0;

	// output false, worse performance
	if likely(a) {
		printf("true\n");
	} else {
		printf("false\n");
	}


	printf("============\n");

	// output false, better performance
	if unlikely(a) {
		printf("true\n");
	} else {
		printf("false\n");
	}
	return 0;
}

