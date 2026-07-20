#ifndef RENDER_H
#define RENDER_H

#include <SDL3/SDL.h>
#include <stdint.h>
#include "objects.h"

void renderInitialise(SDL_Window *win);
void renderHandleDraw(SDL_Window *win);

// Helper functions
bool renderGetSize(int *ren_width, int *ren_height);
void renderObject(object obj);

#endif // !RENDER_H
