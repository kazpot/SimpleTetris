//
// Created by Kazuhiro Nakagawa on 2020/04/19.
//

#ifndef PLAYER_H
#define PLAYER_H


#include <random>

class Player {
public:
    Player();
    void Move(int dir);
    void Drop();
    void Reset();
    void Rotate(int dir);
    bool Collide();
    void Merge();
    void Sweep();
    int GetScore();


    // piece attributes
    static const int ROW{4};
    static const int COL{4};
    static const int KINDS{7};

    // arena
    static const int ARENA_COL{15};
    static const int ARENA_ROW{25};

    // positions
    float x{0};
    float y{0};

    // piece type
    int kind{0};

    // arena
    int arena[ARENA_ROW][ARENA_COL]{0};

    // pieces
    int matrix[KINDS][ROW][COL]
            {
                    {
                            {0, 0, 0},
                            {1, 1, 1},
                            {0, 1, 0},
                    },
                    {
                            {1, 1},
                            {1, 1},
                    },
                    {
                            {0, 1, 0},
                            {0, 1, 0},
                            {0, 1, 1},
                    },
                    {
                            {0, 1, 0},
                            {0, 1, 0},
                            {1, 1, 0},
                    },
                    {
                            {0, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 1, 0, 0},
                    },
                    {
                            {0, 1, 1},
                            {1, 1, 0},
                            {0, 0, 0},
                    },
                    {
                            {1, 1, 0},
                            {0, 1, 1},
                            {0, 0, 0},
                    },
            };
private:
    int _score{0};
    float _speed{0.05};
    std::random_device _dev;
    std::mt19937 _engine;
    std::uniform_int_distribution<int> _random_w;
    std::uniform_int_distribution<int> _random_kind;
};


#endif
