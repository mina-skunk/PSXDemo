#pragma once

#include "psyqo/primitives.hh"
#include "psyqo/vector.hh"
#include "Spatial3D.hh"

class Plane : Spatial3D {
  public:
    psyqo::Vec2 size;
  private:
    psyqo::Prim::Quad primative;
};
