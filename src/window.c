#include <SDL3/SDL.h>
#include "window.h"

SDL_Window *windowCreate(void) {
  SDL_Window *pwindow;

  const int window_default_size_x = 500;
  const int window_default_size_y = 500;

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initialise SDL: %s\n", SDL_GetError());
    return NULL;
  }

  pwindow = SDL_CreateWindow(
    "CPong",
    window_default_size_x,
    window_default_size_y,
    SDL_WINDOW_RESIZABLE
  );

  if (pwindow == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    return NULL;
  }

  return pwindow;
}

void windowCleanUp(SDL_Window *win) {
  SDL_DestroyWindow(win);

  SDL_Quit();
}
