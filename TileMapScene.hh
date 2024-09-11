#pragma once

#include "psyqo/scene.hh"
#include "psyqo/font.hh"

class TileMapScene final : public psyqo::Scene {
    void start(Scene::StartReason reason) override;
    void frame() override;
    void teardown(Scene::TearDownReason reason) override;

  public:
    psyqo::Font<> *font;
    psyqo::Prim::TPage tex_page;
    psyqo::Prim::Sprite16x16 sprite;
};
