bin_PROGRAMS = baka

AM_CPPFLAGS = -DDATADIR='"$(datadir)"'
AM_CFLAGS = -Wall -g -O0
AM_LDFLAGS = -g

baka_SOURCES = \
	baka.h baka.c \
	interface.h interface.c \
	menu.h menu.c

baka_CFLAGS = \
	$(GLIB_CFLAGS) \
	$(GTK_CFLAGS) \
	$(AM_CFLAGS)

baka_LDADD = \
	$(GLIB_LIBS) \
	$(GTK_LIBS)
