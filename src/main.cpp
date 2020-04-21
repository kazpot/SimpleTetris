#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
    constexpr std::size_t kFramePerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramePerSecond};
    constexpr std::size_t kScreenWidth{300};
    constexpr std::size_t kScreenHeight{500};
    constexpr std::size_t kGridWidth{15};
    constexpr std::size_t kGridHeight{25};

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game;
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";

    return 0;
}