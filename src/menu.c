/*
 *  menu.c
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

#include "menu.h"
#include "credits.h"

void file_quit_action_callback(GtkAction *action, Baka *baka)
{
	gtk_widget_destroy(baka->window);
}

void help_about_action_callback(GtkAction *action, Baka *baka)
{
	char *license = g_strjoin("\n\n", _(gpl2[0]), _(gpl2[1]), _(gpl2[2]), NULL);

	gtk_show_about_dialog(GTK_WINDOW(baka->window),
	                      "version", VERSION,
	                      "comments", _("GTK+3 GUI for the pacman package manager"),
	                      "copyright", _("Copyright (c) 2011 Allan McRae <allan@archlinux.org>"),
	                      "license", license,
	                      "wrap-license", TRUE,
	                      "website", PACKAGE_URL,
//	                      "authors", authors,
//	                      "artists", artists,
//	                      "translator-credits", _("translator-credits"),
	                      NULL);

	g_free(license);
}
