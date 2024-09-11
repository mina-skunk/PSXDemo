#include "psyqo/primitives/common.hh"
#include "SplashScene.hh"
#include "logo.h"

void SplashScene::start(Scene::StartReason reason) {
    psyqo::Rect region = {.pos = {{.x = 512, .y = 0}}, .size = {{.w = logo_tex_WIDTH, .h = logo_tex_HEIGHT}}};
    gpu().uploadToVRAM(logo_tex, region);

    logo_tex_page.attr.setPageX(8).setPageY(0).set(psyqo::Prim::TPageAttr::Tex16Bits);

    // logo_sprite.setColor(psyqo::Color{{.r = 0x80, .g = 0x80, .b = 0x80}});
    logo_sprite.position = {{.x = 32, .y = 56}};
    logo_sprite.size = {{.w = logo_tex_WIDTH, .h = logo_tex_HEIGHT}};
    logo_sprite.texInfo = { .u = 0, .v = 0 };
}

void SplashScene::frame() {
    // It is time to render the texture. We are going to clear the screen first.
    gpu().clear({{ .r=0x23, .g=0x26, .b=0x34 }});

    if (counter < 0x80) {
        logo_sprite.setColor(psyqo::Color{{.r = counter, .g = counter, .b = counter}});
    } else {
        logo_sprite.setColor(psyqo::Color{{.r = 0x80, .g = 0x80, .b = 0x80}});
    }
    counter ++;
    if (counter >= 0xFF) {
        // font->print(gpu(), "done", {{.x = 16, .y = 64}}, {{.r=255, .g=255, .b=255}});
        title.font = font;
        title.input = input;
        pushScene(&title);
    }
    

    // font->print(gpu(), "hello", {{.x = 16, .y = 32}}, {{.r=255, .g=255, .b=255}});
    gpu().sendPrimitive(logo_tex_page);
    // Finally, we can send the sprite to the GPU.
    gpu().sendPrimitive(logo_sprite);
}

void SplashScene::teardown(Scene::TearDownReason reason) {

}
