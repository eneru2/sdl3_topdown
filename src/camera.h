#pragma once
#include "entity.h"
#include "player.h"

typedef struct {
  float x, y, w, h;
} Camera;

extern Camera camera;
void init_camera(SDL_Renderer* renderer);