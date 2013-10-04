
#include <stdio.h>
#include <string.h>
#include <libudev.h>

int
main(int argc, char *argv[]) {
    struct udev *udev;
    struct udev_enumerate *enumerate;
    struct udev_list_entry *devices, *device;

    udev = udev_new();
    if (!udev) {
        printf("udev_new failed\n");
        return 0;
    }

    enumerate = udev_enumerate_new(udev);
    if (!enumerate)
        return 0;
    udev_enumerate_add_match_subsystem(enumerate, "input");
    udev_enumerate_scan_devices(enumerate);
    devices = udev_enumerate_get_list_entry(enumerate);

    udev_list_entry_foreach(device, devices) {
        const char *syspath = udev_list_entry_get_name(device);
	struct udev_device *udev_device = udev_device_new_from_syspath(udev, syspath);
	if (udev_device == NULL) continue;

        const char *path = udev_device_get_devnode(udev_device);
        syspath = udev_device_get_syspath(udev_device);
	const char *id_input;
    	// syspath = udev_device_get_syspath(udev_device);

    	if (!syspath || !path)
        	continue;

	printf("got device path :%s: syspath :%s:\n", path, syspath);

	id_input = udev_device_get_property_value(udev_device, "ID_INPUT");

	if (id_input) {
		printf("it's ID_INPUT is :%s:\n", id_input);
	} else {
		printf("it's ID_INPUT is null\n");
	}

        // device_added(udev_device);
        udev_device_unref(udev_device);
    }
    udev_enumerate_unref(enumerate);


    return 0;
}
