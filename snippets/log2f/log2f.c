#include <stdio.h>
#include <stdarg.h>


void
log2file(char *filename, char *fmt, ...) {
	va_list ap;
	FILE * fp = fopen(filename, "w+");
	if (fp != NULL) {
		va_start (ap, fmt);
		vfprintf(fp, fmt, ap);
		va_end (ap);
	}
	fclose(fp);
}


int
main(int argc, char **argv) {
	log2file("/tmp/lala", "hello world %i\n", 10);
	return 0;
}

