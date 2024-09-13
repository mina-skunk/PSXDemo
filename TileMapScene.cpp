#include "TileMapScene.hh"
#include "tileset.h"
#include "TileMap.hh"

void TileMapScene::start(Scene::StartReason reason) {
    psyqo::Rect region = {.pos = {{.x = 512, .y = 0}}, .size = {{.w = tileset_tex_WIDTH, .h = tileset_tex_HEIGHT}}};
    gpu().uploadToVRAM(tileset_tex, region);

    tex_page.attr.setPageX(8).setPageY(0).set(psyqo::Prim::TPageAttr::Tex16Bits);

    // sprite.setColor(psyqo::Color{{.r = 0x80, .g = 0x80, .b = 0x80}});
    // sprite.position = {{.x = 32, .y = 56}};
    // sprite.texInfo = { .u = 0, .v = 0 };
}

void TileMapScene::frame() {
    gpu().clear({{ .r=0x23, .g=0x26, .b=0x34 }});
    font->print(gpu(), "Tiles", {{.x = 16, .y = 64}}, {{.r=255, .g=255, .b=255}});

    gpu().sendPrimitive(tex_page);
    // gpu().sendPrimitive(sprite);

    uint8_t map_data[] = {0,1,2,3,8,9,10,11,16,17,18,19,24,25,26,27};
    TileMap tileMap(4, 4, map_data);
    FixedFragment<Sprite16x16, MAX_TILES> fragment = tileMap.render_fragment({ .width = 8, .height = 11 });
    gpu().sendFragment(fragment);
}

void TileMapScene::teardown(Scene::TearDownReason reason) {

}
