
#ifndef UTIL_H
#define UTIL_H


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

#include "raylib.h"


#define SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef void (*Runnable)();

typedef struct Screen {
    Runnable init;
    Runnable update;
    Runnable draw;
    Runnable free;
    bool initialised;
} Screen;


float getZoom(int xUnits, int yUnits);

Vector2 getScreenCentre();

void errorOut(const char* message, ...);

#endif
