#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"
#include "psyqo/vector.hh"
#include "Spatial3D.hh"

#define MAX_QUAD_MESH 255

class QuadMesh : public Spatial3D  {
  public:
    // psyqo::Vec3 points[]; // eastl?
    // unsigned int indices[];
    psyqo::Fragments::FixedFragment<psyqo::Prim::Quad, MAX_QUAD_MESH> fragment;
};
