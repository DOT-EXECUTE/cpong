#ifndef INPUT_H
#define INPUT_H

#include <SDL3/SDL.h>

typedef enum {
  UP, DOWN, NONE
} playerInputDir;

bool inputKeyEvent(int key_code);
bool inputEventType(SDL_Event event, int event_type);

void inputHandle(void);

#endif
