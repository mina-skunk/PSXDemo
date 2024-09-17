#include "Camera3D.hh"
#include "Render3D.hh"

void Camera3D::set_active() {
  Render3D::set_camera(this);
}
