//========================================================================
/**@file	pan/pan/gui/gtk-compat.h
 * @author imhotep
 * @author	kid
 * @date
 * 	Created:	Mon 09 May 2011 04:42:46 PM MDT \n
 * 	Last Update:	Sun 08 Jan 2012 11:56:00 PM GMT
 */
/*------------------------------------------------------------------------
 * Description:	GTK Compatibility layer for GTK2/3+ migration
 *
 *========================================================================
 */

#ifndef PAN_GTK_COMPAT_H
#define PAN_GTK_COMPAT_H

#include <gtk/gtk.h>
#include <gdk/gdk.h>

#ifdef __cplusplus
namespace
{
#endif
#if !GTK_CHECK_VERSION(2,18,0)
  static inline void gtk_widget_get_allocation( GtkWidget *w, GtkAllocation *a)
  {
    *a = w->allocation;
  }
  static inline bool gtk_widget_has_focus( GtkWidget *w)
  {
    return GTK_WIDGET_HAS_FOCUS(w);
  }
  static inline bool gtk_widget_get_sensitive( GtkWidget *w)
  {
    return GTK_WIDGET_SENSITIVE(w);
  }
  static inline bool gtk_widget_get_visible(GtkWidget *w)
  {
    return GTK_WIDGET_VISIBLE(w);
  }
  static inline bool gtk_widget_is_toplevel(GtkWidget *w)
  {
    return GTK_WIDGET_TOPLEVEL(w);
  }
#endif

#if !GTK_CHECK_VERSION(2,20,0)
  static inline gboolean gtk_widget_get_realized(GtkWidget *w)
  {
    return GTK_WIDGET_REALIZED(w);
  }
#endif

#if defined(GTK_DISABLE_DEPRECATED) || GTK_CHECK_VERSION(3,0,0)
#if GTK_CHECK_VERSION(2,22,0)
#define GtkNotebookPage void
#endif
#endif

#if !GTK_CHECK_VERSION(2,24,0)
#define GTK_COMBO_BOX_TEXT(cb) GTK_COMBO_BOX(cb)
  typedef GtkComboBox GtkComboBoxText;
  static inline GtkWidget* gtk_combo_box_text_new()
  {
    return gtk_combo_box_new_text();
  }
  static inline GtkWidget* gtk_combo_box_text_new_with_entry()
  {
    return gtk_combo_box_entry_new_text();
  }
  static inline void gtk_combo_box_text_append_text(GtkComboBoxText *cb, const gchar *t)
  {
    gtk_combo_box_append_text(cb,t);
  }
  static inline gchar *gtk_combo_box_text_get_active_text(GtkComboBoxText *cb)
  {
    return gtk_combo_box_get_active_text(cb);
  }
  static inline void gtk_combo_box_text_remove(GtkComboBoxText *cb, int p)
  {
    gtk_combo_box_remove_text(cb, p);
  }
#endif

#if !GTK_CHECK_VERSION(3, 0, 0)
  #include <gdk/gdkkeysyms.h>
#endif

//#if !GTK_CHECK_VERSION(3,0,0)
//#ifndef GDK_KEY_Up
//  #define GDK_KEY_Up GDK_Up
//#define GDK_KEY_KP_Up GDK_KP_Up
//#ifndef GDK_KEY_Down
//  #define GDK_KEY_Down GDK_Down
//#define GDK_KEY_KP_Down GDK_KP_Down
//#endif

#if !GTK_CHECK_VERSION(2, 22, 0)
// Define any keys not defined by older GDK versions
  #define GDK_KEY_Delete GDK_Delete
  #define GDK_KEY_Return GDK_Return
  #define GDK_KEY_Down GDK_Down
  #define GDK_KEY_Up GDK_Up
  #define GDK_KEY_KP_Up GDK_KP_Up
  #define GDK_KEY_KP_Down GDK_KP_Down
#endif

#if !GTK_CHECK_VERSION(3,0,0)

  typedef GtkStyle GtkStyleContext;
  static inline GtkStyleContext* gtk_widget_get_style_context(GtkWidget *w)
  {
    return gtk_widget_get_style(w);
  }
  static inline GtkIconSet* gtk_style_context_lookup_icon_set(GtkStyleContext *s,
      const char *id)
  {

    return gtk_style_lookup_icon_set(s,id);
  }
  static inline void gtk_widget_override_font(GtkWidget *w, PangoFontDescription *f)
  {
    gtk_widget_modify_font(w,f);
  }
#endif
#if GTK_CHECK_VERSION(3,0,0)

// include this for conversion of old key names to new
#include <gdk/gdkkeysyms-compat.h>

#define GTK_OBJECT(w) w
  typedef GtkWidget GtkObject;
#ifdef GTK_DISABLE_DEPRECATED
  static inline void gdk_cursor_unref(GdkCursor *p)
  {
    g_object_unref(p);
  }
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
