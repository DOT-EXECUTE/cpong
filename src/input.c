#include <SDL3/SDL.h>
#include "globals.h"
#include "input.h"
#include "objects.h"

playerInputDir input_dir;

bool inputKeyEvent(int key_code) {
  const bool* keyEventState = SDL_GetKeyboardState(NULL);

  // Read the event queue
  if (keyEventState[key_code] == true) {
    return true;
  } else {
    return false;
  }
}

bool inputEventType(SDL_Event event, int event_type) {
  if (event.type == event_type) {
    return true;
  } else {
    return false;
  }
}

void inputHandle(void) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (inputEventType(event, SDL_EVENT_QUIT) || inputKeyEvent(SDL_SCANCODE_ESCAPE)) {
      window_finished = true;
    }

     if (inputEventType(event, SDL_EVENT_KEY_DOWN)) {
      switch (event.key.scancode) {
        // Up
        case SDL_SCANCODE_W:
          objectsPlayerMove(input_dir = UP);
          break; 
        case SDL_SCANCODE_UP:
          objectsPlayerMove(input_dir = UP);
          break;
        case SDL_SCANCODE_S:
          objectsPlayerMove(input_dir = DOWN);
          break;
        case SDL_SCANCODE_DOWN:
          objectsPlayerMove(input_dir = DOWN);
          break;
      }
    } else if (inputEventType(event, SDL_EVENT_KEY_UP)) {
      objectsPlayerMove(input_dir = NONE);
    }
  }
}
