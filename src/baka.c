/*
 *  baka.c
 *
 *  Copyright (c) 2011 Allan McRae <allan@archlinux.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "baka.h"
#include "interface.h"

static void activate(GtkApplication *app, Baka *baka)
{
	GList *list;

	list = gtk_application_get_windows(baka->application);

	if(list != NULL) {
		gtk_window_present(GTK_WINDOW(list->data));
	} else {
		baka->window = baka_load_interface(baka);
		gtk_window_set_application(GTK_WINDOW(baka->window), app);
		gtk_widget_show_all(baka->window);
	}
}


int main(int argc, char **argv)
{
	Baka *baka;
	gint status;

	baka = g_slice_new(Baka);

	g_set_application_name(_("Baka Package Manager"));

	baka->application = gtk_application_new("am.i.baka", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(baka->application, "activate", G_CALLBACK(activate), baka);

	status = g_application_run(G_APPLICATION(baka->application), argc, argv);
	g_object_unref(baka->application);

	g_slice_free(Baka, baka);

	return status;
}
