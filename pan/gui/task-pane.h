/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * Pan - A Newsreader for Gtk+
 * Copyright (C) 2002-2006  Charles Kerr <charles@rebelbase.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "gtk-compat.h"
#include <vector>
#include <pan/tasks/task.h>
#include <pan/tasks/queue.h>
#include "prefs.h"

typedef Queue::tasks_t tasks_t;

namespace pan
{
  /**
   * Dialog for showing and manipulating Tasks in a Queue.
   * @ingroup GUI
   */
  class TaskPane: private Queue::Listener
  {
    public:
      TaskPane (Queue&, Prefs&);
      virtual ~TaskPane ();
      GtkWidget * root() { return _root; }
      //void rebuild ();

    private: // inherited from Queue::Listener
      virtual void on_queue_task_active_changed (Queue&, Task&, bool active);
      virtual void on_queue_tasks_added (Queue&, int index, int count);
      virtual void on_queue_task_removed (Queue&, Task&, int index);
      virtual void on_queue_task_moved (Queue&, Task&, int new_index, int old_index);
      virtual void on_queue_connection_count_changed (Queue&, int count);
      virtual void on_queue_size_changed (Queue&, int active, int total);
      virtual void on_queue_online_changed (Queue&, bool online);
      virtual void on_queue_error (Queue&, const StringView&) { }

    private:
      static gboolean on_tooltip_query(GtkWidget  *widget,
                                       gint        x,
                                       gint        y,
                                       gboolean    keyboard_tip,
                                       GtkTooltip *tooltip,
                                       gpointer    data);

    private:
      Queue& _queue;
      GtkWidget * _root;
      GtkWidget * _view;
      GtkWidget * _online_image;
      GtkWidget * _online_toggle;
      GtkWidget * _status_label;
      GtkListStore * _store;
      gulong _online_toggle_handler;
      guint _update_timeout_tag;
      bool _dampen_move_feedback_loop;
      GtkUIManager * _uim;
      GtkActionGroup * _pgroup;
    private:
      std::string prompt_user_for_new_dest (GtkWindow * parent, const Quark& current_path);

    private:
      void update_status (const Queue::task_states_t&);
      static gboolean periodic_refresh_foreach (GtkTreeModel*, GtkTreePath*, GtkTreeIter*, gpointer);
      static gboolean periodic_refresh (gpointer);
      static void root_destroyed_cb (GtkWidget, gpointer);

    public:
      static void do_popup_menu (GtkWidget*, GdkEventButton *event, gpointer pane_g);
      static gboolean on_button_pressed (GtkWidget * treeview, GdkEventButton *event, gpointer userdata);
      void add_actions (GtkWidget * box);
      void change_destination (const tasks_t& tasks);

    private:
      typedef std::vector<Task*> task_list;
      task_list get_selected_tasks () const;
      static void get_selected_tasks_foreach (GtkTreeModel*, GtkTreePath*, GtkTreeIter*, gpointer);
      static void online_toggled_cb  (GtkToggleButton*, Queue*);

    public:   /// FIXME, privatize this again...
      static void up_clicked_cb      (GtkButton*, TaskPane*);
      static void down_clicked_cb    (GtkButton*, TaskPane*);
      static void top_clicked_cb     (GtkButton*, TaskPane*);
      static void bottom_clicked_cb  (GtkButton*, TaskPane*);
      static void stop_clicked_cb    (GtkButton*, TaskPane*);
      static void delete_clicked_cb  (GtkButton*, TaskPane*);
      static void restart_clicked_cb (GtkButton*, TaskPane*);
      static void change_dest_clicked_cb (GtkButton*, TaskPane*);
  };
}

#endif
