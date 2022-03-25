#! /bin/bash
set -x

GTK3=gtk+-3.0
GTK4=gtk4
ATK=atk

gcc \
	$( pkg-config --cflags $GTK4 )  \
	$( pkg-config --cflags $ATK )  \
	-o ex-3-gtk4 ex-3-gtk4.c \
	$( pkg-config --libs $GTK4 ) \
	$( pkg-config --libs $ATK )

exit

gcc \
	$( pkg-config --cflags $GTK3 )  \
	$( pkg-config --cflags $ATK )  \
	-o ex-3 ex-3.c \
	$( pkg-config --libs $GTK3 ) \
	$( pkg-config --libs $ATK )

exit

gcc $( pkg-config --cflags gtk+-3.0 ) -o ex-1-3 ex-1.c $( pkg-config --libs gtk+-3.0 )
gcc $( pkg-config --cflags gtk4 ) -o ex-1-4 ex-1.c $( pkg-config --libs gtk4 )

# gcc $( pkg-config --cflags gtk+-3.0 ) -o ex-3-3 ex-3.c $( pkg-config --libs gtk+-3.0 )
# gcc $( pkg-config --cflags gtk4 )     -o ex-3-4 ex-3.c $( pkg-config --libs gtk4 )
