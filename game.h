#pragma once

#include "raylib.h"
#include "paddle.h"
#include "ui.h"

class Game{
    public:
        void init(int window_w, int window_h);
        void read_input();
        void process();


        State get_state() { return State{left_paddle, right_paddle, ball}; };

        Paddle& get_l_paddle(){ return left_paddle; };
        Paddle& get_r_paddle(){ return right_paddle; };
        Ball&   get_ball()    { return ball; };

        int get_l_score(){ return l_score; };
        int get_r_score(){ return r_score; };

    private:
        //window
        int window_width {};
        int window_height {};

        //paddle
        int paddle_wall_displacement {40};
        int paddle_width {20};
        int paddle_height {125};
        int paddle_speed {15};
        Paddle left_paddle {};
        Paddle right_paddle {};

        enum Paddle_direction{
            NONE,
            UP,
            DOWN,
        } left_paddle_direction, right_paddle_direction;

        //ball
        int ball_x_speed {5};
        int ball_y_speed {5};
        int ball_x_acceleration {3};
        int ball_y_acceleration {3};
        Ball ball;
        void reset_ball();

        //score
        int l_score {};
        int r_score {};
};
