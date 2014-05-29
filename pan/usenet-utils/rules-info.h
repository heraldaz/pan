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

#ifndef __Rules_Info_h__
#define __Rules_Info_h__

#include <deque>
#include <pan/general/quark.h>
#include <pan/general/string-view.h>
#include <pan/general/text-match.h>

namespace pan
{
  /**
   * Interface class describing a filter that can be applied to a set of articles.
   * @ingroup usenet_utils
   */
  class RulesInfo
  {
    public:

      /** The different type of filters we support. */
      enum RulesType {
        TYPE__ERR,
        AGGREGATE__AND,
        AGGREGATE__OR,
        MARK_READ,
        AUTOCACHE,
        AUTODOWNLOAD,
        DELETE_ARTICLE
      };

      /** Defines what type of filter this is. */
      RulesType _type;

      bool empty() const { return _type == TYPE__ERR; }
      RulesInfo () { clear(); }
      virtual ~RulesInfo () { }

      /** Convenience typedef. */
      typedef std::deque<RulesInfo> aggregates_t;

      /** When `_type' is AGGREGATE_OR or AGGREGATE_AND,
          these are the filters being or'ed or and'ed together. */
      aggregates_t _aggregates;

      /** When this is true, the results of the test should be negated. */
      bool _negate;

    private:
      void set_type_is (RulesType type);
      void set_type_le (RulesType type, unsigned long le);
      void set_type_ge (RulesType type, unsigned long ge);
      void set_type_bounds (RulesType type, int low, int high);


    public:

      unsigned long _ge;
      int _lb, _hb;

      void clear ();
      void set_type_aggregate_and ();
      void set_type_aggregate_or ();
      void set_type_mark_read_b (int lb, int hb);
      void set_type_autocache_b (int lb, int hb);
      void set_type_dl_b (int lb, int hb);
      void set_type_delete_b (int lb, int hb);
  };
}

#endif
