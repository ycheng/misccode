
#include <stdio.h>
#include "log2file.h"

int
main(int argc, char **argv) {
	log2file("/tmp/log2file.out.txt", "hello world %i\n", 10);
	return 0;
}

