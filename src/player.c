#include "player.h"

static SDL_Texture* player_texture;
static SDL_FRect sprite_portion = {17,14,15,18};

SpriteSize sprite_size = {15, 18};
Position player_position = {0, 0};

static void cleanup() {

}

static void handle_events() {

}

static void update(float delta_time) {
  const _Bool *keyboard_state = SDL_GetKeyboardState(NULL);

  if (keyboard_state[SDL_SCANCODE_W]) {
    player_position.y -= 30 * delta_time;
  }

  if (keyboard_state[SDL_SCANCODE_S]) {
    player_position.y += 30  * delta_time;
  }

  if (keyboard_state[SDL_SCANCODE_A]) {
    player_position.x -= 30 * delta_time;
  }

  if (keyboard_state[SDL_SCANCODE_D]) {
    player_position.x += 30 * delta_time;
  }
}

static void render(SDL_Renderer* renderer) {
  float final_x = camera.w / 2 - sprite_size.w / 2;
  float final_y = camera.h / 2 - sprite_size.h / 2;

  if (camera.x <= 0) final_x = player_position.x - sprite_size.w / 2;
  if (camera.y <= 0) final_y = player_position.y - sprite_size.h / 2;

  if (camera.x + camera.w >= 420) final_x = player_position.x - (420 - camera.w) - sprite_size.w / 2;
  if (camera.y + camera.h >= 240) final_y = player_position.y - (240 - camera.h) - sprite_size.h / 2;

  SDL_FRect player_rect = {
    final_x,
    final_y,
    sprite_size.w,
    sprite_size.h
  };

  SDL_RenderTexture(renderer, player_texture, &sprite_portion, &player_rect);
}

void init_player(SDL_Renderer* renderer) {

  const char path[] = "./char_spritesheet.png";
  player_texture = IMG_LoadTexture(renderer, path);
  SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);

  Entity player = {
    .cleanup = cleanup,
    .handle_events = handle_events,
    .update = update,
    .render = render
  };

  create_entity(player);
}