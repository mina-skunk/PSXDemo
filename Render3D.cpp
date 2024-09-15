#include "psyqo/gte-kernels.hh"
#include "psyqo/gte-registers.hh"
#include "psyqo/vector.hh"
#include "Render3D.hh"

void Render3D::init() {
  psyqo::GTE::clear<psyqo::GTE::Register::TRX, psyqo::GTE::Unsafe>();
  psyqo::GTE::clear<psyqo::GTE::Register::TRY, psyqo::GTE::Unsafe>();
  psyqo::GTE::clear<psyqo::GTE::Register::TRZ, psyqo::GTE::Unsafe>();

  psyqo::GTE::write<psyqo::GTE::Register::OFX, psyqo::GTE::Unsafe>(psyqo::FixedPoint<16>(160.0).raw());
  psyqo::GTE::write<psyqo::GTE::Register::OFY, psyqo::GTE::Unsafe>(psyqo::FixedPoint<16>(120.0).raw());
}

Camera3D* Render3D::active_camera;

void Render3D::set_camera(Camera3D *camera) {
  active_camera = camera;
  psyqo::GTE::write<psyqo::GTE::Register::H, psyqo::GTE::Unsafe>(active_camera->projection_plane_distance);
}

void Render3D::render_plane(Plane *plane) {
  psyqo::Vec3 cam_space_pos = {
    .x = plane->position.x - active_camera->position.x,
    .y = plane->position.y - active_camera->position.y,
    .z = plane->position.z - active_camera->position.z
  };
  psyqo::GTE::write<psyqo::GTE::Register::TRX, psyqo::GTE::Unsafe>(cam_space_pos.x.raw());
  psyqo::GTE::write<psyqo::GTE::Register::TRY, psyqo::GTE::Unsafe>(cam_space_pos.y.raw());
  psyqo::GTE::write<psyqo::GTE::Register::TRZ, psyqo::GTE::Unsafe>(cam_space_pos.z.raw());

  psyqo::Vec3 top_left = {
    .x = -(plane->size.x / 2),
    .y = -(plane->size.y / 2),
    .z = 0
  };
  psyqo::Vec3 top_right = {
    .x = (plane->size.x / 2),
    .y = -(plane->size.y / 2),
    .z = 0
  };
  psyqo::Vec3 bottom_right = {
    .x = (plane->size.x / 2),
    .y = (plane->size.y / 2),
    .z = 0
  };
  psyqo::Vec3 bottom_left = {
    .x = -(plane->size.x / 2),
    .y = (plane->size.y / 2),
    .z = 0
  };

  psyqo::GTE::writeUnsafe<psyqo::GTE::PseudoRegister::V0>(top_left);
  psyqo::GTE::writeUnsafe<psyqo::GTE::PseudoRegister::V1>(top_right);
  psyqo::GTE::writeSafe<psyqo::GTE::PseudoRegister::V2>(bottom_right);

  psyqo::GTE::Kernels::rtpt();

  psyqo::GTE::read<psyqo::GTE::Register::SXY0>(&plane->primitive.pointA.packed);
  psyqo::GTE::read<psyqo::GTE::Register::SXY1>(&plane->primitive.pointB.packed);
  psyqo::GTE::read<psyqo::GTE::Register::SXY2>(&plane->primitive.pointC.packed);

  psyqo::GTE::writeUnsafe<psyqo::GTE::PseudoRegister::V0>(bottom_left);
  psyqo::GTE::Kernels::rtps();
  psyqo::GTE::read<psyqo::GTE::Register::SXY2>(&plane->primitive.pointD.packed);
}
