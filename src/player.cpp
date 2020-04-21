//
// Created by Kazuhiro Nakagawa on 2020/04/19.
//

#include "player.h"
#include <iostream>

Player::Player() :
    _engine(_dev()),
    _random_w(5, static_cast<int>(ARENA_COL - 5)),
    _random_kind(0, KINDS - 1)
{
}

void Player::Drop()
{
    y += _speed;

    if (Collide())
    {
       --y;
       Merge();
       Reset();
       Sweep();
    }
}

void Player::Move(int dir)
{
    x += float(dir);
    if (Collide())
    {
        x -= float(dir);
    }
}

void Player::Reset()
{
    y = 0;
    x = _random_w(_engine);
    kind = _random_kind(_engine);

    if (Collide())
    {
        for (int yy = 0; yy < ARENA_ROW; ++yy)
        {
            for (int xx = 0; xx < ARENA_COL; ++xx)
            {
                arena[yy][xx] = 0;
                _score = 0;
                _speed = 0.05;
            }
        }
    }
}

bool Player::Collide()
{
    auto mat = matrix[kind];
    int px = floor(x);
    int py = floor(y);

    for (int yy = 0; yy < ROW; ++yy)
    {
        for (int xx = 0; xx < COL; ++xx)
        {
            if (mat[yy][xx] != 0 && (
                    (yy + py) >= ARENA_ROW ||
                    (xx + px) >= ARENA_COL ||
                    (xx + px) < 0 ||
                    arena[yy + py][xx + px]) != 0)
            {
                return true;
            }
        }
    }
    return false;
}

void Player::Merge()
{
    auto mat = matrix[kind];
    int px = floor(x);
    int py = floor(y);

    for (int yy = 0; yy < ROW; ++yy)
    {
        for (int xx = 0; xx < COL; ++xx)
        {
            if (mat[yy][xx] == 1)
            {
                arena[yy + py][xx + px] = 1;
            }
        }
    }
}

void Player::Rotate(int dir)
{
    // transpose matrix
    for (int i = 0; i < ROW; i++)
    {
        for (int j = i; j < COL; j++)
        {
            std::swap(matrix[kind][i][j], matrix[kind][j][i]);
        }
    }


    // dir > 0 -> rotate anti-clockwise
    // dir <= 0 -> rotate clockwise
    if (dir > 0)
    {
        for (int i = 0; i < COL; i++)
        {
            for (int j = 0, k = COL - 1; j < k; j++, k--)
            {
                std::swap(matrix[kind][j][i], matrix[kind][k][i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < COL; i++)
        {
            for (int j = 0, k = COL - 1; j < k; j++, k--)
            {
                std::swap(matrix[kind][k][i], matrix[kind][j][i]);
            }

        }
    }

    int offset = 1;
    while (Collide())
    {
        x += float(offset);
        offset = -(offset + (offset > 0 ? 1 : -1));
    }
}

void Player::Sweep()
{
    int row_count = 0;
    for (int yy = ARENA_ROW - 1; yy > 0; --yy)
    {
        for (int xx = 0; xx < ARENA_COL; ++xx)
        {
            if (arena[yy][xx] == 0)
            {
                goto cnt;
            }
        }
        for (int xx = 0; xx < ARENA_COL; ++xx)
        {
            arena[yy][xx] = 0;
        }

        row_count += 1;
        _score += row_count * 10;
        row_count *= 2;
        _speed += 0.01;
        cnt:;
    }

    int count = 0;
    while (true)
    {
        // max row size=4 that can be deleted at one time
        if (count >= 4)
        {
            break;
        }
        for (int yy = ARENA_ROW; yy > 0; --yy)
        {
            for (int xx = 0; xx < ARENA_COL; ++xx)
            {
                if (arena[yy][xx] == 1)
                {
                    goto cnt2;
                }
            }

            for (int col = 0; col < ARENA_COL; ++col)
            {
                arena[yy][col] = arena[yy - 1][col];
                arena[yy - 1][col] = 0;
            }
            cnt2:;
        }
        ++count;
    }
}

int Player::GetScore()
{
    return _score;
}