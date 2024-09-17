#pragma once

#include "Camera3D.hh"
#include "Plane.hh"

class Render3D {
  public:
    static void init();
    static void set_camera(Camera3D *camera);
    static void render_plane(Plane *plane);
  private:
    static Camera3D *active_camera;
};
