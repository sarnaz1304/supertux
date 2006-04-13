//  $Id$
//
//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef __YETI_H__
#define __YETI_H__

#include "badguy.hpp"

class Yeti : public BadGuy
{
public:
  Yeti(const lisp::Lisp& lisp);
  ~Yeti();

  void draw(DrawingContext& context);
  void write(lisp::Writer& writer);
  void active_update(float elapsed_time);
  HitResponse collision_solid(GameObject& object, const CollisionHit& hit);
  bool collision_squished(Player& player);
  void kill_fall();

private:
  void go_right();
  void go_left();
  void angry_jumping();
  void drop_stalactite();
  void summon_snowball();
  
  enum YetiState {
    INIT,
    ANGRY_JUMPING,
    THROW_SNOWBALL,
    GO_RIGHT,
    GO_LEFT
  };
  Direction side;
  YetiState state;
  Timer timer;
  Timer safe_timer;
  int jumpcount;
  int hit_points;
  std::string dead_script;
};

#endif

