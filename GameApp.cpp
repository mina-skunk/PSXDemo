#include "GameApp.hh"

void GameApp::prepare() {
    psyqo::GPU::Configuration config;
    config.set(psyqo::GPU::Resolution::W320)
        .set(psyqo::GPU::VideoMode::AUTO)
        .set(psyqo::GPU::ColorMode::C15BITS)
        .set(psyqo::GPU::Interlace::PROGRESSIVE);
    gpu().initialize(config);
}

void GameApp::createScene() {
    if (!initialized) {
        font.uploadSystemFont(gpu());
        input.initialize();
        initialized = true;
    }

    splash.font = &font;
    splash.input = &input;
    pushScene(&splash);
}
