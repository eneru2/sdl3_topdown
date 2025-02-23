#include "camera.h"

Camera camera = {0, 0, 320, 180};

static void update(float delta_time) {
  camera.x = player_position.x - camera.w / 2;
  camera.y = player_position.y - camera.h / 2;

  if (camera.x < 0) camera.x = 0;
  if (camera.y < 0) camera.y = 0;

  if (camera.x + camera.w > 420) camera.x = 420 - camera.w;
  if (camera.y + camera.h > 240) camera.y = 240 - camera.h;
}

void init_camera(SDL_Renderer* renderer) {
  Entity camera = {
    .name = "camera",
    .update = update,
  };

  create_entity(camera);
}