#include "iterate.h"

SDL_AppResult SDL_AppIterate(void *appstate) {
  app_update(appstate);
  app_render(appstate);
  return SDL_APP_CONTINUE;
}