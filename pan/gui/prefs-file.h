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

#ifndef _PrefsFile_h_
#define _PrefsFile_h_

#include "prefs.h"

namespace pan
{
  class PrefsFile: public Prefs
  {
    public:
      PrefsFile (const StringView& filename);
      ~PrefsFile ();
      virtual void save () const;

    private:
      std::string _filename;

    private:
      void set_from_file (const StringView& filename);
      void set_from_xml (const StringView& xml_string);
  };
}

#endif
