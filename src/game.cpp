//
// Created by Kazuhiro Nakagawa on 2020/04/19.
//

#include "game.h"
#include <iostream>

Game::Game()
{
    _player = std::make_shared<Player>();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration = 0;
    int frame_count = 0;
    bool running = true;

    _player->Reset();
    while (running)
    {
        frame_start = SDL_GetTicks();
        controller.HandleInput(running, _player);
        Update();
        renderer.Render(_player);

        frame_end = SDL_GetTicks();

        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000) {
            renderer.UpdateWindowTitle(_player->GetScore(), frame_count);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        if (frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void Game::Update()
{
    _player->Drop();
}