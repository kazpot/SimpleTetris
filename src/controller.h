//
// Created by Kazuhiro Nakagawa on 2020/04/19.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"
#include <memory>

class Controller {
public:
    void HandleInput(bool &running, std::shared_ptr<Player> player) const;

};


#endif
