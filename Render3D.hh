#pragma once

#include "Camera3D.hh"

class Render3D {
  public:
    static void set_camera(Camera3D *camera);
    static void render_plane();
  private:
    static Camera3D *active_camera;
};
