#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "psyqo/vector.hh"
#include "Spatial3D.hh"

class Cube : public Spatial3D  {
  public:
    psyqo::Vec3 size;
    psyqo::Fragments::FixedFragment<psyqo::Prim::Quad, 6> fragment;
};
