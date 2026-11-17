#include "game.h"
#include "raylib.h"
#include "paddle.h"
#include "ui.h"

void Game::init(int window_w, int window_h){
    window_width = window_w;
    window_height = window_h;

    left_paddle.x = paddle_wall_displacement;
    left_paddle.y = window_height/2;
    left_paddle.width = paddle_width;
    left_paddle.height = paddle_height;

    right_paddle.x = window_width - paddle_wall_displacement - paddle_width;
    right_paddle.y = window_height/2;
    right_paddle.width = paddle_width;
    right_paddle.height = paddle_height;

    ball.x = window_width/2;
    ball.y = window_height/2;
    ball.speed_x = ball_x_speed;
    ball.speed_y = ball_y_speed;
    ball.acceleration_x = ball_x_acceleration;
    ball.acceleration_y = ball_y_acceleration;
}

void Game::read_input(){
    if(IsKeyDown(KEY_UP)){
        right_paddle_direction = UP;
    }else if(IsKeyDown(KEY_DOWN)){
        right_paddle_direction = DOWN;
    }else{
        right_paddle_direction = NONE;
    }

    if(IsKeyDown(KEY_W)){
        left_paddle_direction = UP;
    }else if(IsKeyDown(KEY_S)){
        left_paddle_direction = DOWN;
    }else{
        left_paddle_direction = NONE;
    }
}

void Game::reset_ball(){
    ball.x = window_width/2;
    ball.y = window_height/2;
    if((r_score + l_score) % 2 == 0){
        ball.speed_x = ball_x_speed;
        ball.speed_y = ball_y_speed;
    }else{
        ball.speed_x = ball_x_speed;
        ball.speed_y = ball_y_speed;
    }
    ball.acceleration_x = ball_x_acceleration;
    ball.acceleration_y = ball_y_acceleration;
}

void Game::process(){
    if(ball.x <= 0){
        r_score++;
        reset_ball();
    }else if(ball.x >= window_width){
        l_score++;
        reset_ball();
    }

    if((ball.x <= left_paddle.x+left_paddle.width) && (ball.x >= left_paddle.x-left_paddle.width)
        && (left_paddle.y <= ball.y) && (left_paddle.y+left_paddle.height >= ball.y)){
        ball.speed_x *= -1;
        ball.speed_x += ball.acceleration_x;
    }else if((ball.x >= right_paddle.x) && (ball.x <= right_paddle.x+2*right_paddle.width)
                && (right_paddle.y <= ball.y) && (right_paddle.y+right_paddle.height >= ball.y)){
        ball.speed_x += ball.acceleration_x;
        ball.speed_x *= -1;
    }
    
    if(ball.y <= 0){
        ball.speed_y *= -1;
    }else if(ball.y >= window_height){
        ball.speed_y *= -1;
    }
    
    ball.x += ball.speed_x;
    ball.y += ball.speed_y;

    if(left_paddle_direction == UP 
        && left_paddle.y >= 0){
        left_paddle.y -= paddle_speed;
    }else if(left_paddle_direction == DOWN
                && left_paddle.y <= (window_height - left_paddle.height)){
        left_paddle.y += paddle_speed;
    }
    
    if(right_paddle_direction == UP
        && right_paddle.y >= 0){
        right_paddle.y -= paddle_speed;
    }else if(right_paddle_direction == DOWN
                && right_paddle.y <= (window_height - right_paddle.height)){
        right_paddle.y += paddle_speed;
    }
}
