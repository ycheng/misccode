#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char buf1[1024];
	char buf2[1024];
	void *p1, *p2;

	p1 = buf1;
	p2 = buf2;

	printf("before memcpy\n");
	memcpy((void*) p1, (const void *) p2, (size_t)1024);
	printf("after memcpy\n");
	return 0;
}

