#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

int main(int argc, char* argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
    return 1;
  }
  if (TTF_Init() < 0) {
    std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
    return 1;
  }
  SDL_Window* window = SDL_CreateWindow("CS:GO GUI", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
    return 1;
  }
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr) {
    std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
    return 1;
  }
  TTF_Font* font = TTF_OpenFont("font.ttf", 20);
  if (font == nullptr) {
    std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    return 1;
  }
  SDL_Color color = {255, 255, 255, 255};
  SDL_Surface* surface = TTF_RenderText_Solid(font, "Hello, World!", color);
  if (surface == nullptr) {
    std::cerr << "Failed to render text: " << TTF_GetError() << std::endl;
    return 1;
  }
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (texture == nullptr) {
    std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    return 1;
  }
  SDL_FreeSurface(surface);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, nullptr, nullptr);
  SDL_RenderPresent(renderer);
  bool running = true;
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
       running = false;
      }
    }
  }

  // Clean up
  SDL_DestroyTexture(texture);
  TTF_CloseFont(font);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();

  return 0;
}
