#pragma once

#include "psyqo/scene.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
#include "Camera3D.hh"
#include "Plane.hh"

class Demo3DScene final : public psyqo::Scene {
    void start(Scene::StartReason reason) override;
    void frame() override;
    void teardown(Scene::TearDownReason reason) override;

  public:
    psyqo::Font<> *font;
    psyqo::SimplePad *input;
  private:
    Camera3D camera;
    Plane plane;
};
