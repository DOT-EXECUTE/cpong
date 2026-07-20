#include <SDL3/SDL.h>
#include <stdint.h>
#include <stdlib.h>
#include "objects.h"
#include "globals.h"
#include "render.h"
#include "input.h"

object ball = {
  .velocity = {0.0f, 0.0f},
  .position = {250.0f, 250.0f},
  .origin = {0.0f, 0.0f},
  .width = 15.0f,
  .height = 15.0f,

  // Rendering
  .render_colour = {255, 51, 84, 200} // R G B A
};

object player1 = {
  .velocity = {0.0f, 0.0f},
  .position = {10.0f, 250.0f},
  .origin = {0.0f, 0.0f},
  .width = 20.0f,
  .height = 166.67f,

  // Rendering
  .render_colour = {30, 160, 255, 255} // R G B A
};

object player2 = {
  .velocity = {0.0f, 0.0f},
  .position = {490.0f, 250.0f},
  .origin = {0.0f, 0.0f},
  .width = 20.0f,
  .height = 166.67f,

  // Rendering
  .render_colour = {30, 160, 255, 255} // R G B A
};

bool objects_initialised = false;
int renderer_width, renderer_height;

bool objectsInitialise() {
  if (!renderGetSize(&renderer_width, &renderer_height)) {
    return false;
  }

  ball.origin.x = ball.width / 2;
  ball.origin.y = ball.height / 2;

  player1.origin.x = player1.width / 4;
  player1.origin.y = player1.height / 2;

  player2.origin.x = player2.width / 2;
  player2.origin.y = player2.height / 2;

  ball.position.x = renderer_width / 2;
  ball.position.y = renderer_height / 2;

  player1.position.x = renderer_width / 2;
  player1.position.y = renderer_height / 2;

  player2.position.x = renderer_width / 2;
  player2.position.y = renderer_height / 2;

  SDL_FRect ballShape = {
    ball.position.x + ball.origin.x,
    ball.position.y + ball.origin.y,
    ball.width,
    ball.height
  };

  SDL_FRect player1Shape = {
    player1.position.x + ball.origin.x,
    player1.position.y + ball.origin.x,
    player1.width,
    player1.height
  };

  SDL_FRect player2Shape = {
    player2.position.x + ball.origin.x,
    player2.position.y + ball.origin.y,
    player2.width,
    player2.height
  };

  ball.render_shape = ballShape;
  player1.render_shape = player1Shape;
  player2.render_shape = player2Shape;

  objectsBallMove();

  return objects_initialised = true;
}

void objectsProcess() {
  if (!objects_initialised) {
    objectsInitialise();
  }

  // Update Both Players
  objectsUpdate(&player2);
  renderObject(player2);

  objectsUpdate(&player1);
  renderObject(player1);

  // Update the Ball
  objectsUpdate(&ball);
  objectsBallMove();
  renderObject(ball);

  renderGetSize(&renderer_width, &renderer_height);

  player1.position.x = (renderer_width / 16);
  player2.position.x = renderer_width - (renderer_width / 16);
}

void objectsUpdate(object *obj) {
  obj->position.x += obj->velocity.x;
  obj->position.y += obj->velocity.y;

  obj->render_shape.x = obj->position.x;
  obj->render_shape.y = obj->position.y;
}

void objectsPlayerMove(playerInputDir input_dir) {
  switch (input_dir) {
    case UP:
      player1.velocity.y = -0.25f;
      break;
    case DOWN:
      player1.velocity.y = 0.25f;
      break;
    case NONE:
      player1.velocity.y = 0.0f;
      break;
  }
}

void objectsBallMove(void) {
  if (!objects_initialised) {
    float rand_intial_velocity_x = (float)(rand() / (float)rand());
    float rand_intial_velocity_y = (float)(rand() / (float)rand());

    ball.velocity.x = /* rand_intial_velocity_x */ 0.05f;
    ball.velocity.y = /* rand_intial_velocity_y */ 0.05f;
  }

  // Player Collisions
  if (ball.position.x == player1.position.x || ball.position.x == player2.position.x) {
    ball.velocity.x = -ball.velocity.x;
    ball.velocity.y = -ball.velocity.y;
  }

  // Edge Collisions
  if (ball.position.x >= renderer_width || ball.position.x <= 0) {
    ball.velocity.x = -ball.velocity.x;
  }
  if (ball.position.y >= renderer_height || ball.position.y <= 0) {
    ball.velocity.y = -ball.velocity.y;
  }
}
