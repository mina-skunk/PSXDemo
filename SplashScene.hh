#pragma once

#include "psyqo/scene.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
#include "TitleScene.hh"

class SplashScene final : public psyqo::Scene {
    void start(Scene::StartReason reason) override;
    void frame() override;
    void teardown(Scene::TearDownReason reason) override;

  public:
    psyqo::Font<> *font;
    psyqo::SimplePad *input;
  private:
    psyqo::Prim::TPage logo_tex_page;
    psyqo::Prim::Sprite logo_sprite;
    unsigned char counter = 0;
    TitleScene title;

};
