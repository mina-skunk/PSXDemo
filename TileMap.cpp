#include "TileMap.hh"

using namespace psyqo::Fragments;
using namespace psyqo::Prim;

FixedFragment<Sprite16x16, MAX_TILES> TileMap::render_fragment(TileSet tile_set) {
  FixedFragment<Sprite16x16, MAX_TILES>  fragment;
  fragment.count = height * width;

  uint8_t index = 0;
  for (uint8_t y = 0; y < height; y++) {
      for (uint8_t x = 0; x < width; x++) {
        Sprite16x16 tile(psyqo::Color{{.r = 0x80, .g = 0x80, .b = 0x80}});

        int16_t pixel_x = x * 16;
        int16_t pixel_y = y * 16;
        int16_t tile_pos_x = pixel_x + 32;
        int16_t tile_pos_y = pixel_y + 32;
        tile.position = {{.x = tile_pos_x, .y = tile_pos_y}};

        uint8_t set_index = data[index];
        if (set_index < tile_set.width) {
          tile.texInfo.u = set_index * 16;
          tile.texInfo.v = 0;
        } else {
          tile.texInfo.u = (set_index % tile_set.width) * 16;
          tile.texInfo.v = (set_index / tile_set.width) * 16;
        }

        fragment.primitives[index] = tile;
        index++;
    }
  }

  return fragment;

}
