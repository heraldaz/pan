/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * Pan - A Newsreader for Gtk+
 * Copyright (C) 2002-2007  Charles Kerr <charles@rebelbase.com>
 *
 * This file
 * Copyright (C) 2007 Calin Culianu <calin@ajvar.org>
 *
 * This file is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.  *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef _Mutex_h_
#define _Mutex_h_

#include <glib.h>

namespace pan
{
  /***
   * A C++ wrapper for GMutex.
   *
   * @author Calin Culianu <calin@ajvar.org>
   * @ingroup general
   * (changed for glib >= 3.32)
   */
  class Mutex
  {
    private:
      static GMutex mutex;
      GMutex * m;

    public:

      /** Create a new mutex */
      Mutex()
      {
#if !GLIB_CHECK_VERSION(3,32,0)
        m = g_mutex_new();
#else
        g_mutex_init(&mutex);
        m = &mutex;
#endif
      }

      /** Destroy the mutex */
      ~Mutex()
      {
#if !GLIB_CHECK_VERSION(3,32,0)
        g_mutex_free(m);
#endif
      }

      /** Block until a lock is acquired */
      void lock()   { g_mutex_lock(m); }

      /** Unlock the mutex - may wake another thread waiting on it */
      void unlock() { g_mutex_unlock(m); }
  };
}

#endif
