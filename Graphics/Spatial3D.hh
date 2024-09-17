#pragma once

#include "psyqo/vector.hh"

// before Vector generic template was in psyqo
// #include "psyqo/trigonometry.hh"
// struct Rotation3D {
//   psyqo::Angle x;
//   psyqo::Angle y;
//   psyqo::Angle z;
// };

typedef psyqo::Vector<3, 10> Rotation3D;

class Spatial3D  {
  public:
    psyqo::Vec3 position;
    Rotation3D rotation;
};
