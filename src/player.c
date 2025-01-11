#include "player.h"

static SDL_Texture* player_texture;
static SDL_FRect sprite_portion = {17,14,15,18};
static SDL_FRect player_position = {250, 250, 15, 18};

static void quit() {

}

static void handle_events() {

}

static void update() {

}

static void render(SDL_Renderer* renderer) {
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