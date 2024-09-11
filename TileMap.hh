#pragma once

#include "psyqo/fragments.hh"
#include "psyqo/primitives.hh"

using namespace psyqo::Fragments;
using namespace psyqo::Prim;

#define MAX_TILES 255

struct TileSet {
    uint8_t width, height;
    uint8_t * data;
};

class TileMap {
    uint8_t width, height;
    uint8_t * data;
  public:
    TileMap(uint8_t width_, uint8_t height_, uint8_t * data_) : width(width_), height(height_), data(data_) {}

    FixedFragment<Sprite16x16, MAX_TILES> render_fragment(TileSet tile_set);
};
