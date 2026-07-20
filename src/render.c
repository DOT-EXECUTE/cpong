#include <SDL3/SDL.h>
#include <stdint.h>
#include <stdio.h>
#include "render.h"
#include "globals.h"
#include "objects.h"

bool renderer_initialised = false;

SDL_Renderer *renderer;
char buffer[32];

void renderInitialise(SDL_Window *win) {
  SDL_Renderer *mrenderer = SDL_CreateRenderer(win, NULL);

  if (mrenderer == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to create hardware accelerated renderer: %s\n", SDL_GetError());
    return;
  }

  renderer_initialised = true;

  renderer = mrenderer;
}

void renderHandleDraw(SDL_Window *win) {
  if (!renderer_initialised) {
    renderInitialise(win);
  }

  // Clear the previous frame to render the current
  if (!SDL_RenderClear(renderer)) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to clear the renderer: %s\n", SDL_GetError());
  }

  //snprintf(buffer, sizeof(buffer), "%d", frames_per_second);

  // === Draw UI ===
  // Text Colour
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  //SDL_RenderDebugText(renderer, (renderer_width / 2), ((renderer_height / 2)), buffer);

  // === Draw Objects ===
  objectsProcess();

  // Background Colour
  SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);

  // Render current frame to the window
  SDL_RenderPresent(renderer);
}

// === Helper Functions ===
bool renderGetSize(int *ren_width, int *ren_height) {
  if (!SDL_GetRenderOutputSize(renderer, ren_width, ren_height)) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to get renderer output size: %s\n", SDL_GetError());
    return false;
  }

  return true;
}

void renderObject(object obj) {
  // Set object colour to be specified
  SDL_SetRenderDrawColor(renderer, obj.render_colour.r, obj.render_colour.g, obj.render_colour.b, obj.render_colour.a);

  // Draw the object. NOTE: The object can ONLY be a filled rectangle
  SDL_RenderFillRect(renderer, &obj.render_shape);
}

