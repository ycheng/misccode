#include <stdio.h>
#include "log2file.h"

void
log2file(char *filename, char *fmt, ...) {
	va_list ap;
	FILE * fp = fopen(filename, "a+");
	if (fp != NULL) {
		va_start (ap, fmt);
		vfprintf(fp, fmt, ap);
		va_end (ap);
	}
	fclose(fp);
}

