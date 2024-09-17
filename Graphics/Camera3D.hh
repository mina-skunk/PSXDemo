#pragma once

#include "Spatial3D.hh"

class Camera3D : public Spatial3D  {
  public:
    uint16_t projection_plane_distance = 300; // ?? whats a good default: 300, 320, 280 ect
    void set_active();
};
