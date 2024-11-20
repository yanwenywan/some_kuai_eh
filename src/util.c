#include "util.h"

float getZoom(int xUnits, int yUnits) {
    if (GetScreenWidth() > GetScreenHeight()) {
        return (float) GetScreenWidth() / (float) xUnits;
    } else {
        return (float) GetScreenHeight() / (float) yUnits;
    }
}

Vector2 getScreenCentre() {
    return (Vector2){GetScreenWidth() / 2, GetScreenHeight() / 2};
}

void errorOut(const char* message, ...) {
    va_list args;
    va_start(args, message);
    fprintf(stderr, "An illegal state was reached:");
    vfprintf(stderr, message, args);
    fprintf(stderr, "\n");
    va_end(args);

    exit(1);
}
