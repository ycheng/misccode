
package main

import (
	"fmt"
	"github.com/godbus/dbus"
	"os"
)

func main() {
	conn, err := dbus.SessionBus()
	if err != nil {
		fmt.Fprintln(os.Stderr, "Failed to open session bus", err)
		os.Exit(1)
	}
	var s[]string
	err = conn.BusObject().Call("org.freedesktop.DBus.ListNames", 0).Store(&s)
	// YC: destination name is ignored, which is "org.freedesktop.DBus" in this case.
	// YC: OBJECT_PATH is ignored, which is "/org/freedesktop/DBus" in this case.
	if err != nil {
		fmt.Fprintln(os.Stderr, "Failed to get list of owned names:", err)
		os.Exit(1)
	}
	fmt.Println("Currently owned names on the session bus:")
	for _, v := range s {
		fmt.Println(v)
	}

	// fmt.Println("Hello, 世界")
	// fmt.Println("Hello, 世界2")
}
