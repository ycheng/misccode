#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s number_of_pixel\n", argv[0]);
		return 1 ;
	}

	int len = atoi(argv[1]);
	printf("len %i\n", len);
	while (1) {
		unsigned int sum = 0;
		int i;
		for (i = 0; i < len; i++) {
			unsigned int value;
			int ret = read(0, &value, 4);
			if (ret == 0) {
				printf("last %i bytes sum 0x%x\n", i, sum);
				return 0;
			}
			sum = sum ^ value;
		}
		printf("sum 0x%x\n", sum);
	}
	return 0;
}

