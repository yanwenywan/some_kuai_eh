#include "util.h"
#include "mainScreen.h"

void selectScreen(int screenIndex);

int width = 1600;
int height = 960;

Screen* screenRefs[] = { &mainScreen };

Screen* selected;

int main() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, "Raylib Game");
    SetTargetFPS(60);

    selectScreen(0);

    while (!WindowShouldClose()) {
        selected->update();
        selected->draw();
    }

    for (int i = 0; i < SIZE(screenRefs); i++) {
        Screen* screen = screenRefs[i];
        if (screen->initialised) {
            screen->free();
        }
    }

    CloseWindow();

    return 0;
}

void selectScreen(int screenIndex) {
    if (screenIndex < 0 || screenIndex >= SIZE(screenRefs)) {
        errorOut("SelectScreen: illegal screen index %d", screenIndex);
    }

    selected = screenRefs[screenIndex];

    if (!selected->initialised) {
        selected->init();
        selected->initialised = true;
    }
}
