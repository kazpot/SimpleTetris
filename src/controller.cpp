//
// Created by Kazuhiro Nakagawa on 2020/04/19.
//

#include "controller.h"
#include "SDL.h"
#include "player.h"

void Controller::HandleInput(bool &running, std::shared_ptr<Player> player) const
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
                case SDLK_LEFT:
                    player->Move(-1);
                    break;
                case SDLK_RIGHT:
                    player->Move(1);
                    break;
                case SDLK_q:
                    player->Rotate(-1);
                    break;
                case SDLK_w:
                    player->Rotate(1);
                    break;
            }
        }
    }
}