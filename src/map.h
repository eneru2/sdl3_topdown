#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "entity.h"
#include "external/cute_tiled.h"
#include "camera.h"

typedef struct Texture {
  SDL_Texture* texture;
  int firstgid;
  int tilecount;
  int tileset_width;
  int tileset_height;
  struct Texture* next;
} Texture;

void init_map(SDL_Renderer* renderer);