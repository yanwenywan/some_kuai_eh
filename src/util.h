
#ifndef UTIL_H
#define UTIL_H


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include <raylib.h>


#define SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef void (*Runnable)();

typedef struct Screen {
    Runnable init;
    Runnable update;
    Runnable draw;
    Runnable free;
    bool initialised;
} Screen;

#define fromHex(i32_t) (Color){(i32_t >> 24) & 0xFF, (i32_t >> 16) & 0xFF, (i32_t >> 8) & 0xFF, i32_t & 0xFF};

float getZoom(int xUnits, int yUnits);

Vector2 getScreenCentre();

void errorOut(const char* message, ...);

#endif
