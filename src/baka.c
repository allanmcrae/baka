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

#include <gtk/gtk.h>

static void activate(GtkApplication *app)
{
	GList *list;
	GtkWidget *window;

	list = gtk_application_get_windows(app);

	if(list != NULL) {
		gtk_window_present(GTK_WINDOW(list->data));
	} else {
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_application(GTK_WINDOW(window), app);
		gtk_widget_show_all(window);
	}
}


int main(int argc, char **argv)
{
	GtkApplication *app;
	gint status;

	app = gtk_application_new("am.i.baka", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}
