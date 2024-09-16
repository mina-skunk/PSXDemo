#pragma once

#include "psyqo/primitives.hh"

#define MAX_VOLUME 0xFFFF

class Sound {
  public:
    static void set_volume(psyqo::Vertex volume);
    static void set_volume(uint16_t volume);
    static void set_cd_volume(psyqo::Vertex volume);
    static void set_cd_volume(uint16_t volume);
};
