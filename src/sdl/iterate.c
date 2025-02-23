#include "iterate.h"
#define TARGET_FPS 144
#define TARGET_FRAME_TIME (1000 / TARGET_FPS)

void app_wait_for_next_frame(void *appstate) {
  AppState* state = (AppState*) appstate;

  Uint64 frame_time = SDL_GetTicks() - state->current_tick;
  if (frame_time < TARGET_FRAME_TIME) SDL_Delay(TARGET_FRAME_TIME - frame_time);
}

SDL_AppResult SDL_AppIterate(void *appstate) {
  app_update(appstate);
  app_render(appstate);
  app_wait_for_next_frame(appstate);
  return SDL_APP_CONTINUE;
}