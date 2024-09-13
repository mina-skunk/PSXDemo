#pragma once

#include "psyqo/application.hh"
#include "psyqo/scene.hh"

template <class S> 
class SimpleApp final : public psyqo::Application {
    void prepare() override;
    void createScene() override;

  public:
    S default_scene;

  private:
    bool initialized = false;
};
