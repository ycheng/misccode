#! /bin/bash
set -x

GTK=gtk+-3.0
# GTK=gtk4
ATK=atk

gcc \
	$( pkg-config --cflags $GTK )  \
	$( pkg-config --cflags $ATK )  \
	-o ex-3 ex-3.c \
	$( pkg-config --libs $GTK ) \
	$( pkg-config --libs $ATK )

exit

gcc $( pkg-config --cflags gtk+-3.0 ) -o ex-1-3 ex-1.c $( pkg-config --libs gtk+-3.0 )
gcc $( pkg-config --cflags gtk4 ) -o ex-1-4 ex-1.c $( pkg-config --libs gtk4 )

# gcc $( pkg-config --cflags gtk+-3.0 ) -o ex-3-3 ex-3.c $( pkg-config --libs gtk+-3.0 )
# gcc $( pkg-config --cflags gtk4 )     -o ex-3-4 ex-3.c $( pkg-config --libs gtk4 )
