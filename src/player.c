#include "player.h"

static SDL_Texture* player_texture;
static SDL_FRect sprite_portion = {17,14,15,18};

typedef struct {
  float x, y;
} Position;

Position position = {0, 0};

static void quit() {

}

static void handle_events() {

}

static void update(float delta_time) {
  const _Bool *keyboard_state = SDL_GetKeyboardState(NULL);

  if (keyboard_state[SDL_SCANCODE_W]) {
    position.y -= 30 * delta_time;
  }

  if (keyboard_state[SDL_SCANCODE_S]) {
    position.y += 30  * delta_time;
  }

  if (keyboard_state[SDL_SCANCODE_A]) {
    position.x -= 30 * delta_time;
  }

  if (keyboard_state[SDL_SCANCODE_D]) {
    position.x += 30 * delta_time;
  }
}

static void render(SDL_Renderer* renderer) {
  SDL_FRect player_position = {position.x, position.y, 15, 18};
  SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);
  SDL_RenderTexture(renderer, player_texture, &sprite_portion, &player_position);
}

Entity init_player(SDL_Renderer* renderer) {

  const char path[] = "./char_spritesheet.png";
  player_texture = IMG_LoadTexture(renderer, path);

  Entity player = {
    .quit = quit,
    .handle_events = handle_events,
    .update = update,
    .render = render
  };

  return player;
}