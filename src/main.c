// Libraries
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdint.h>
// Global Variables
#include "globals.h"
// Functionality
#include "window.h"
#include "input.h"
#include "render.h"

bool window_finished = false;
uint32_t frames_per_second = 0;

vector2 vector2_ZERO = {0.0f, 0.0f};

int main() {
  SDL_Window *window = windowCreate();
  //SDL_Surface *psurface;

  //psurface = SDL_GetWindowSurface(window);

  uint64_t last_time = 0;

  // Frame loop
  while (!window_finished) {
    uint64_t current_time = SDL_GetTicks();

    inputHandle();

    renderHandleDraw(window /*, psurface*/);
    frames_per_second++;
    uint64_t delta_time = SDL_GetTicks() - current_time;

    if (current_time > last_time + 1000) {
      last_time = current_time;
      frames_per_second = 0;
    }
  }

  windowCleanUp(window);

  return 0;
}
