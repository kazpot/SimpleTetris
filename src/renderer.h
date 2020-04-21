//
// Created by Kazuhiro Nakagawa on 2020/04/19.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "player.h"

class Renderer {
public:
    Renderer(std::size_t screen_width, std::size_t screen_height,
            std::size_t grid_width, std::size_t grid_height);
    ~Renderer();

    void Render(const std::shared_ptr<Player>& player);
    void UpdateWindowTitle(int score, int fps);

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const std::size_t screen_width{0};
    const std::size_t screen_height{0};
    const std::size_t grid_width{0};
    const std::size_t grid_height{0};
};

#endif