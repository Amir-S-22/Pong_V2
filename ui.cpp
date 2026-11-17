#include <string>
#include "raylib.h"
#include "ui.h"
#include "paddle.h"
#include "ball.h"

void UI::init_window(){
    InitWindow(window_width, window_height, title);
    SetTargetFPS(fps);
}

void UI::draw_everything(const State& state){
    BeginDrawing();
    draw_background();   
    draw_line(); draw_score();
    draw_paddles(state.paddle_l, state.paddle_r);
    draw_ball(state.ball);

    EndDrawing();
}

void UI::draw_background(){
    ClearBackground(background_colour);
}

void UI::draw_line(){
    int middle { window_width / 2 };
    int x { middle - (line_width/2) };
    int y { 0 };
    //condition = y doesn't go outside window
    for(int i {0}; y < window_height; i++){
        if(i%2 == 0){
            y += line_spacing;
            continue;
        }

        DrawRectangle(x, y, line_width, line_spacing, WHITE);
        y += line_spacing;
    }
}

void UI::draw_score(){
    int l_x{ (window_width / 4) - (font_size/2) };
    int l_y{ score_y_displacement };
    int r_x{ ((window_width / 4) * 3) - (font_size/2) };
    int r_y{ score_y_displacement };
    std::string l_score { std::to_string(score_l) };
    std::string r_score { std::to_string(score_r) };

    DrawText(l_score.data(), l_x, l_y, font_size, WHITE);
    DrawText(r_score.data(), r_x, r_y, font_size, WHITE);
}

void UI::draw_paddles(const Paddle& lp, const Paddle& rp){
    DrawRectangle( lp.x, lp.y, lp.width, lp.height, WHITE );
    DrawRectangle( rp.x, rp.y, rp.width, rp.height, WHITE );
}

void UI::draw_ball(const Ball& ball){
    DrawCircle(ball.x, ball.y, ball_size, RED);
}
