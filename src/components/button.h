#ifndef BUTTON_H
#define BUTTON_H

#include "util.h"

typedef enum KeyEntry {
    NONE
} KeyEntry;

typedef struct KeyButton {
    KeyEntry keyType;
    void (*callback)(KeyEntry);
    char label;

    bool _down; 
} KeyButton;

// static const Color BUTTON_INACTIVE = ;

void keyboardKey_draw(KeyButton key, Font labelFont);

void keyboardKey_update(KeyButton key);

#endif