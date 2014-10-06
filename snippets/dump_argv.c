
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define FILENAME "/tmp/dump_argv_XXXXXX"

void
dump_args(int argc, char *argv[], int verbose) {
    char filename[] = FILENAME;
    int fd = mkostemp(filename, O_APPEND);
    FILE *fh;
    int i;

    if (fd < 0) {
        printf("mkostemp failed\n");
        return;
    }
    fh = fdopen(fd, "w");

    for (i = 0; i < argc; i++) {
        fprintf(fh, "%s\n", argv[i]);
    }
    fclose(fh);
    if (verbose) {
        printf("dump argv to file succ\n");
    }
}

int
main(int argc, char *argv[]) {
    dump_args(argc, argv, 0);
    return 0;
}

