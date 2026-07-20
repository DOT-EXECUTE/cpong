#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdint.h>
#include <SDL3/SDL.h>

extern bool window_finished;
extern uint32_t frames_per_second;

typedef struct vector2 {
  float x;
  float y;
} vector2;

extern vector2 vector2_ZERO;

typedef struct rbgaColour {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
} rgbaColour;


#endif // !GLOBALS_H
