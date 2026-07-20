#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL.h>

SDL_Window *windowCreate(void);
void windowCleanUp(SDL_Window *win);

#endif
