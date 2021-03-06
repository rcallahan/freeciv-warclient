/********************************************************************** 
 Freeciv - Copyright (C) 1996 - A Kjeldberg, L Gregersen, P Unold
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
***********************************************************************/
#ifndef FC__GUI_MAIN_H
#define FC__GUI_MAIN_H

#include <gtk/gtk.h>

#include "gtkpixcomm.h"
#include "gui_main_g.h"

enum canvas_type {
  CANVAS_PIXMAP,
  CANVAS_PIXCOMM,
  CANVAS_PIXBUF
};

struct canvas
{
  enum canvas_type type;

  union {
    GdkPixmap *pixmap;
    GtkPixcomm *pixcomm;
    GdkPixbuf *pixbuf;
  } v;
};

struct voteinfo_bar {
  GtkWidget *box;
  GtkWidget *next_button;
  GtkWidget *label;
  GtkWidget *yes_button;
  GtkWidget *no_button;
  GtkWidget *abstain_button;
  GtkWidget *yes_count_label;
  GtkWidget *no_count_label;
  GtkWidget *abstain_count_label;
  GtkWidget *voter_count_label;
};

extern struct voteinfo_bar *ingame_votebar;
extern struct voteinfo_bar *pregame_votebar;

struct voteinfo_bar *create_voteinfo_bar(void);

/* network string charset conversion */
gchar *ntoh_str(const gchar *netstr);

extern PangoFontDescription *        main_font;
extern PangoFontDescription *        city_productions_font;

extern bool allied_chat_only;

void init_chat_buttons(void);

extern GdkGC *          civ_gc;
extern GdkGC *          mask_fg_gc;
extern GdkGC *          mask_bg_gc;
extern GdkGC *          fill_bg_gc;
extern GdkGC *          fill_tile_gc;
extern GdkGC *          thin_line_gc;
extern GdkGC *          thick_line_gc;
extern GdkGC *          border_line_gc;
extern GdkPixmap *      gray50;
extern GdkPixmap *      gray25;
extern GdkPixmap *      black50;
extern GdkPixmap *      mask_bitmap;
#define single_tile_pixmap (mapview_canvas.single_tile->pixmap)
extern GtkTextView *	main_message_area;
extern GtkWidget *      text_scrollbar;
extern GtkWidget *      toplevel;
extern GtkWidget *      top_vbox;
extern GtkWidget *      main_frame_civ_name;
extern GtkWidget *      main_label_info;
extern GtkWidget *      econ_label[10];
extern GtkWidget *      bulb_label;
extern GtkWidget *      sun_label;
extern GtkWidget *      flake_label;
extern GtkWidget *      government_label;
extern GtkTooltips *	main_tips;
extern GtkWidget *	econ_ebox;
extern GtkWidget *	bulb_ebox;
extern GtkWidget *	sun_ebox;
extern GtkWidget *	flake_ebox;
extern GtkWidget *	government_ebox;
extern GtkWidget *      go_sun_label;
extern GtkWidget *      go_flake_label;
extern GtkWidget *      go_timeout_label;
extern GtkWidget *      go_sun_ebox;
extern GtkWidget *      go_flake_ebox;
extern GtkWidget *      map_canvas;             /* GtkDrawingArea */
extern GtkWidget *      overview_canvas;        /* GtkDrawingArea */
extern GtkWidget *      player_colors_mode_label;
extern GtkWidget *      timeout_label;
extern GtkWidget *      turn_done_button;
extern GtkWidget *      unit_info_label;
extern GtkWidget *      unit_info_frame;
extern GtkWidget *      map_horizontal_scrollbar;
extern GtkWidget *      map_vertical_scrollbar;
extern GdkWindow *      root_window;

extern GtkWidget *	toplevel_tabs;
extern GtkWidget *	top_notebook;
extern GtkWidget *	bottom_notebook;
extern GtkTextBuffer *	message_buffer;
extern GtkTextBuffer *	network_message_buffer;
extern GtkWidget *      inputline;

void enable_menus(bool enable);

gboolean inputline_handler(GtkWidget *w, GdkEventKey *ev);
gboolean show_conn_popup(GtkWidget *view, GdkEventButton *ev, gpointer data);

void reset_unit_table(void);
void popup_quit_dialog(void);

void queue_chatline_scroll_to_bottom(void);

#endif  /* FC__GUI_MAIN_H */
