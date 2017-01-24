
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int
main() {

  int ret;
    struct stat statBuf;

    ret = stat("/etc/passwd", &statBuf);

    printf("ret = %i.\n", ret);
    return 0;
}
