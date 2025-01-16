#pragma once
#include <SDL3/SDL.h>
#define MAX_ENTITIES 100

typedef struct {
  void (*cleanup)(void);
  void (*handle_events)(SDL_Event*);
  void (*update)(float);
  void (*render)(SDL_Renderer*);
} Entity;

extern Entity entities[MAX_ENTITIES];
extern int entities_count;