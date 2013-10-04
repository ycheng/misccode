#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE (10 * 1024 * 1024)

int
main(int argc, char *argv[]) {
	int *p;
	int i;
	int size = 0;

	if (argc >= 2) {
		size = atoi(argv[1]);
	}
	if (size <= 0) {
		size = SIZE;
	} else {
		size = size / sizeof(int);
	}
	printf("Allocate %i bytes\n", size * 4);

	p = malloc(size * sizeof(int));
	for (i = 0; i < size; i++) {
		*(p + i) = i;
	}
	while(-1) {
		sleep(1);
	}
	return 0;
} 
