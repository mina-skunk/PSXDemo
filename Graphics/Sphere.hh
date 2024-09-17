#pragma once

#include "psyqo/fixed-point.hh"
#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "psyqo/vector.hh"
#include "Spatial3D.hh"

class Sphere : public Spatial3D  {
  public:
    psyqo::FixedPoint<> radius;
    psyqo::Fragments::FixedFragment<psyqo::Prim::Quad, 16> fragment1;
    psyqo::Fragments::FixedFragment<psyqo::Prim::Triangle, 16> fragment2;
};
