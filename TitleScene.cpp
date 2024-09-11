#include "TitleScene.hh"

void TitleScene::start(Scene::StartReason reason) {
    selection.setColor(psyqo::Color{{.r = 0xf2, .g = 0xd5, .b = 0xcf}});
    outlines.primitives[0].setColor(psyqo::Color{{.r = 0x80, .g = 0x80, .b = 0x80}});
    outlines.primitives[1].setColor(psyqo::Color{{.r = 0x80, .g = 0x80, .b = 0x80}});
    outlines.primitives[2].setColor(psyqo::Color{{.r = 0x80, .g = 0x80, .b = 0x80}});

    selection.size = { .w = 260, .h = 18 };
    selection.position.x = 30;

    outlines.primitives[0].points[0] = {.x = 30, .y = 94};
    outlines.primitives[0].points[1] = {.x = 290, .y = 94};
    outlines.primitives[0].points[2] = {.x = 290, .y = 112};
    outlines.primitives[0].points[3] = {.x = 30, .y = 112};
    outlines.primitives[0].points[4] = {.x = 30, .y = 94};

    outlines.primitives[1].points[0] = {.x = 30, .y = 126};
    outlines.primitives[1].points[1] = {.x = 290, .y = 126};
    outlines.primitives[1].points[2] = {.x = 290, .y = 144};
    outlines.primitives[1].points[3] = {.x = 30, .y = 144};
    outlines.primitives[1].points[4] = {.x = 30, .y = 126};

    outlines.primitives[2].points[0] = {.x = 30, .y = 158};
    outlines.primitives[2].points[1] = {.x = 290, .y = 158};
    outlines.primitives[2].points[2] = {.x = 290, .y = 176};
    outlines.primitives[2].points[3] = {.x = 30, .y = 176};
    outlines.primitives[2].points[4] = {.x = 30, .y = 158};

    outlines.count = 3;

    input->setOnEvent([this](const psyqo::SimplePad::Event& event) {
        if (event.type == psyqo::SimplePad::Event::ButtonPressed) {
            if (event.button == psyqo::SimplePad::Up && selected > 0) {
                selected--;
            }
            if (event.button == psyqo::SimplePad::Down && selected < 2) {
                selected++;
            }
            if (event.button == psyqo::SimplePad::Cross || event.button == psyqo::SimplePad::Start) {
                // TODO handle more options
                tile_map_scene.font = font;
                // tile_map_scene.input = input;
                pushScene(&tile_map_scene);
            }
        }
    });
}

void TitleScene::frame() {
    gpu().clear({{ .r=0x23, .g=0x26, .b=0x34 }});
    font->print(gpu(), "PSX Demo", {{.x = 128, .y = 64}}, {{.r=255, .g=255, .b=255}});

    selection.position.y = 94 + (selected * 32) ;

    gpu().sendPrimitive(selection);
    gpu().sendFragment(outlines);


    font->print(gpu(), "1. Tile Map", {{.x = 32, .y = 96}}, {{.r=255, .g=255, .b=255}});
    font->print(gpu(), "2. TODO", {{.x = 32, .y = 128}}, {{.r=255, .g=255, .b=255}});
    font->print(gpu(), "3. TODO", {{.x = 32, .y = 160}}, {{.r=255, .g=255, .b=255}});
}

void TitleScene::teardown(Scene::TearDownReason reason) {
    input->setOnEvent(nullptr);
}
