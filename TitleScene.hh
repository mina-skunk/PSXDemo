#pragma once

#include "TileMapScene.hh"
#include "psyqo/fragments.hh"
#include "psyqo/scene.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
#include "psyqo/primitives.hh"

class TitleScene final : public psyqo::Scene {
    void start(Scene::StartReason reason) override;
    void frame() override;
    void teardown(Scene::TearDownReason reason) override;

  public:
    psyqo::Font<> *font;
    psyqo::SimplePad *input;
  private:
    psyqo::Fragments::FixedFragment<psyqo::Prim::PolyLine<4>, 3> outlines;
    psyqo::Prim::Rectangle selection;
    uint8_t selected = 0;
    TileMapScene tile_map_scene;

};
