#include <iostream>
#include <vector>
#include <string>
#include "chip8.hpp"

#define SDL_MAIN_HANDLED
#include "SDL2/include/SDL.h"
#include "SDL2/include/SDL_opengl.h"
#include "SDL2/include/SDL_thread.h"

using namespace std;

const unsigned char SCREEN_WIDTH = 32;
const unsigned char SCREEN_HEIGHT = 64;

//Initializes SDL and returns a window handle.
SDL_Window* initialize_sdl()
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0) 
  {
    return NULL;
  }

  // Setup window
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_DisplayMode current;
  SDL_GetCurrentDisplayMode(0, &current);

  SDL_Window* window = SDL_CreateWindow(
      "Chip-8 Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      SCREEN_WIDTH, SCREEN_HEIGHT, SDL_RENDERER_ACCELERATED);

  return window;
}


int main()
{
    printf("hello world");
    return 0;
}
