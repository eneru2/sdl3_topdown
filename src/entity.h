#pragma once
#include <SDL3/SDL.h>
#define MAX_ENTITIES 100

typedef struct {
  void (*quit)(void);
  void (*handle_events)(SDL_Event*);
  void (*update)(float);
  void (*render)(SDL_Renderer*);
} Entity;