#include "mainScreen.h"
#include "components/button.h"


Screen mainScreen = {&initMainScreen, &updateMainScreen, &drawMainScreen, &disposeMainScreen, false};

Camera2D camera;

int xUnits = 500;
int yUnits = 300;

KeyButton key_naught; 

void initMainScreen() {
    camera = (Camera2D) {
        .offset = getScreenCentre(),
        .target = {0, 0},
        .rotation = 0.0f,
        .zoom = getZoom(xUnits, yUnits)
    };

    Color c = fromHex(0x304050FF);
    printf("Color {%d, %d, %d, %d}", c.r, c.g, c.b, c.a);
}

void updateMainScreen() {
    camera.zoom = getZoom(xUnits, yUnits);
    camera.offset = getScreenCentre();

    if (IsKeyDown(KEY_A)) {
        camera.target.x -= 2;
    }

    if (IsKeyDown(KEY_W)) {
        camera.target.y -= 2;
    }

    if (IsKeyDown(KEY_S)) {
        camera.target.y += 2;
    }

    if (IsKeyDown(KEY_D)) {
        camera.target.x += 2;
    }

}

void drawMainScreen() {
    BeginDrawing();
    
    ClearBackground(RAYWHITE);
    
    BeginMode2D(camera);

    DrawText("This is the first window in Raylib", 0, 0, 12, BLACK);

    for (int i = -200; i <= 200; i+= 10) {
        DrawLine(i, 0, i, yUnits, (Color){0, 255, 0, 255 - abs(i)});
    }
    for (int j = -300; j <= 300; j += 10) {
        DrawLine(0, j, xUnits, j, (Color){0, 0, 255, 255 - abs(j)});
    }

    EndMode2D();

    EndDrawing();
}

void disposeMainScreen() {

}


