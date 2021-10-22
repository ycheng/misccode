

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/epoll.h>

#include <stdio.h>

int main() {
	int tty_active_fd = -1;


	tty_active_fd = open("/sys/class/tty/tty0/active", O_RDONLY|O_NOCTTY|O_CLOEXEC);

	int epoll_fd = epoll_create1(EPOLL_CLOEXEC);

	struct epoll_event ev = {
                .events = 0,
        };

	int ret = epoll_ctl(epoll_fd,
                      EPOLL_CTL_ADD,
                      tty_active_fd, &ev);

	printf("ret = %i\n", ret);

	return 0;
}
