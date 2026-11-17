#pragma once

#include "paddle.h"
#include "ball.h"

struct State{
    const Paddle& paddle_l {};
    const Paddle& paddle_r {};
    const Ball& ball {};
};
