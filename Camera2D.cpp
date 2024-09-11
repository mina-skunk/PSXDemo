#include "Camera2D.hh"
#include "psyqo/fixed-point.hh"
#include "psyqo/vector.hh"

using namespace psyqo;
using namespace psyqo::fixed_point_literals;

Vec2 Camera2D::get_top_left() {
    return position - (size / 2.0_fp);
}
