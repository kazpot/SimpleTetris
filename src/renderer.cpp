//
// Created by Kazuhiro Nakagawa on 2020/04/19.
//

#include "renderer.h"
#include <iostream>

Renderer::Renderer(std::size_t screen_width, std::size_t screen_height,
        std::size_t grid_width, std::size_t grid_height)
        : screen_width(screen_width), screen_height(screen_height),
          grid_width(grid_width), grid_height(grid_height) {
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Could not initialize SDL...\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // create window
    sdl_window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, screen_width,
                                  screen_height, SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window) {
        std::cerr << "Could not create window...\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer) {
        std::cerr << "Could not be create renderer...\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}

Renderer::~Renderer() {
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::Render(const std::shared_ptr<Player>& player) {
    SDL_Rect block;
    block.w = int(screen_width / grid_width);
    block.h = int(screen_height / grid_height);

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render piece
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (int row = 0; row < player->ROW; ++row)
    {
        for (int col = 0; col < player->COL; ++col)
        {
            if (player->matrix[player->kind][row][col] == 1)
            {
                block.x = (col + int(player->x)) * block.w;
                block.y = (row + int(player->y)) * block.h;
                SDL_RenderFillRect(sdl_renderer, &block);
            }
        }
    }

    // render arena
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (int row = 0; row < player->ARENA_ROW; ++row)
    {
        for (int col = 0; col < player->ARENA_COL; ++col)
        {
            if (player->arena[row][col] == 1)
            {
                block.x = col * block.w;
                block.y = row * block.h;
                SDL_RenderFillRect(sdl_renderer, &block);
            }
        }
    }

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
    std::string title{"Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}