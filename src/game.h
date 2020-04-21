//
// Created by Kazuhiro Nakagawa on 2020/04/19.
//

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "renderer.h"
#include "controller.h"
#include "player.h"
#include <memory>


class Game {
public:
    Game();
    void Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration);

private:
    std::shared_ptr<Player> _player;

    void Update();
};

#endif
