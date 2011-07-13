/*
 *  interface.c
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

#include "interface.h"

GtkWidget *baka_load_interface(Baka *baka)
{
	GError *error = NULL;

	/* TODO - this only runs from within the src/ directory */
	char *uifile = "../data/baka.ui";

	baka->builder = gtk_builder_new();

	/* TODO - gtk_builder_set_translation_domain */

	gtk_builder_add_from_file(baka->builder, uifile, &error);
	/* TODO - check error */

	gtk_builder_connect_signals(baka->builder, baka);

	baka->window = GTK_WIDGET(gtk_builder_get_object(baka->builder, "baka_main_window"));

	return baka->window;
}
