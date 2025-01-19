#pragma once

#include <cstdint>
#define GLAD_GL_IMPLEMENTATION
#include "glad/include/glad/glad.h"

#define SDL_MAIN_HANDLED
#include "SDL2/include/SDL.h"
#include "SDL2/include/SDL_opengl.h"
#include "SDL2/include/SDL_thread.h"

class Platform
{
	friend class Imgui;

public:
	Platform(char const* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight);
	~Platform();
	void Update(void const* buffer, int pitch);
	bool ProcessInput(uint8_t* keys);

private:
	SDL_Window* window{};
	SDL_GLContext gl_context{};
	GLuint framebuffer_texture;
	SDL_Renderer* renderer{};
	SDL_Texture* texture{};
};
