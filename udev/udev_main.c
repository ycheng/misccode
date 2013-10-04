
#include <stdio.h>
#include <string.h>
#include <libudev.h>

static struct udev_monitor *udev_monitor;


void
select_for_read(int fd) {
	fd_set rfds;
	struct timeval tv;
	int retval;

	while (1==1) {

        /* Watch stdin (fd 0) to see when it has input. */
        FD_ZERO(&rfds);
        FD_SET(fd, &rfds);

	/* Wait up to five seconds. */
	tv.tv_sec = 5;
	tv.tv_usec = 0;

	retval = select(fd + 1, &rfds, NULL, NULL, &tv);
        /* Don't rely on the value of tv now! */

        if (retval == -1)
               perror("select()");
        else if (retval) {
            printf("Data is available now.\n");
	    break;
            /* FD_ISSET(fd, &rfds) will be true. */
	}
        else {
               printf("No data within five seconds.\n");
	}

	}
}

int
main(int argc, char *argv[]) {
    struct udev *udev;
    // struct udev_enumerate *enumerate;
//    struct udev_list_entry *devices, *device;
    udev_monitor = NULL;

    struct udev_device *udev_device;
    const char *action;


    udev = udev_new();
    if (!udev) {
        printf("udev_new failed\n");
        return 0;
    }
    udev_monitor = udev_monitor_new_from_netlink(udev, "udev");
    if (!udev_monitor) {
        printf("udev_monitor_new_from_netlink failed\n");
        return 0;
    }

    udev_monitor_filter_add_match_subsystem_devtype(udev_monitor, "input", NULL);

    if (udev_monitor_enable_receiving(udev_monitor)) {
        printf("config/udev: failed to bind the udev monitor\n");
        return 0;
    }


    int udev_fd = udev_monitor_get_fd(udev_monitor);

    select_for_read(udev_fd);

    udev_device = udev_monitor_receive_device(udev_monitor);
    if (!udev_device) {
        printf("udev_monitor_receive_device failed\n");
        return 0;
    }
    action = udev_device_get_action(udev_device);
    printf("udev action %s\n", action);
    if (action) {
        if (!strcmp(action, "add") || !strcmp(action, "change")) {
            printf("device_removed(udev_device); device_added(udev_device);\n");
        }
        else if (!strcmp(action, "remove")) {
            printf("device_removed(udev_device);\n");
	}
    }
    udev_device_unref(udev_device);

    return 0;
}
