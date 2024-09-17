#pragma once

#include "psyqo/primitives.hh"
#include "psyqo/vector.hh"
#include "Spatial3D.hh"

class Plane : public Spatial3D {
  public:
    psyqo::Vec2 size;
    psyqo::Prim::Quad primitive;
};
