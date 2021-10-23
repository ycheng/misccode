

#include <fcntl.h>
#include <stdio.h>
#include <sys/epoll.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <unistd.h>

#define MAX_EVENTS 10
#define READ_SIZE 100

int main() {
	int tty_active_fd = -1;


	tty_active_fd = open("/sys/class/tty/tty0/active", O_RDONLY|O_NOCTTY|O_CLOEXEC);
	printf("tty_active_fd %i\n", tty_active_fd);

	int epoll_fd = epoll_create1(EPOLL_CLOEXEC);
	if (epoll_fd == -1) {
	    fprintf(stderr, "Failed to create epoll file descriptor\n");
		return 1;
	}

	struct epoll_event ev = {
		.events = 0,
		.data.fd = tty_active_fd,
	};

	int ret = epoll_ctl(epoll_fd,
                      EPOLL_CTL_ADD,
                      tty_active_fd, &ev);

	if (ret != 0) {
		printf("epoll_ctl add reurn non-zero, failed.\n");
		return 1;
	}

	struct epoll_event events[MAX_EVENTS];

	int event_count;
	while (1 == 1) {
		event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, 30000);
		printf("%d ready events\n", event_count);
		for(int i = 0; i < event_count; i++) {
			size_t bytes_read;
			char read_buffer[READ_SIZE + 1];
			printf("Reading file descriptor '%d' -- ", events[i].data.fd);
			lseek(events[i].data.fd, 0, SEEK_SET);
			bytes_read = read(events[i].data.fd, read_buffer, READ_SIZE);
			printf("%zd bytes read.\n", bytes_read);
			read_buffer[bytes_read] = '\0';
			printf("Read '%s'\n", read_buffer);
		}
	}

	if(close(epoll_fd)) {
		fprintf(stderr, "Failed to close epoll file descriptor\n");
		return 1;
	}

	return 0;
}
