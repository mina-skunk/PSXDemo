#include "Render3D.hh"

Camera3D* Render3D::active_camera;

void Render3D::set_camera(Camera3D *camera) {
  active_camera = camera;
}

void Render3D::render_plane() {
  
}
