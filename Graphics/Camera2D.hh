#pragma once

#include "psyqo/fixed-point.hh"
#include "psyqo/vector.hh"

using namespace psyqo;
using namespace psyqo::fixed_point_literals;

class Camera2D {
  public:
    Vec2 position = { .x = 0.0_fp, .y = 0.0_fp };
    Vec2 size = { .x = 320.0_fp, .y = 240.0_fp };
    Vec2 get_top_left();
};
