#include "render.h"

void app_render(void *appstate) {
  AppState* state = (AppState*) appstate;

  SDL_RenderClear(state->renderer);
  SDL_SetRenderDrawColor(state->renderer, 0, 255, 0, 255);
  
  for (int i = 0; i < entities_count; i++) {
    entities[i].render(state->renderer);
  }

  SDL_RenderPresent(state->renderer);
}