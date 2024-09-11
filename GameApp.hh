#pragma once

#include "psyqo/application.hh"
#include "psyqo/font.hh"
#include "psyqo/simplepad.hh"
#include "SplashScene.hh"

class GameApp final : public psyqo::Application {

    void prepare() override;
    void createScene() override;

  public:
    psyqo::Font<> font;
    psyqo::SimplePad input;
    SplashScene splash;

  private:
    bool initialized = false;
};
