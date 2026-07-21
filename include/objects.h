#ifndef OBJECTS_H
#define OBJECTS_H

#include <SDL3/SDL.h>
#include "input.h"
#include "globals.h"

typedef struct object{
  vector2 velocity;
  vector2 position;

  float width;
  float height;

  SDL_FRect render_shape;
  rgbaColour render_colour;
  int z_index;
} object;

bool objectsInitialise();

void objectsProcess();
void objectsUpdate(object *obj);

void objectsPlayerMove(playerInputDir direction);

void objectsBallMove(void);

// Helper Func
bool objectsCheckCollision(object obj_a, object obj_b);

#endif // !OBJECTS_H
