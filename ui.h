#pragma once

#include <string>
#include "raylib.h"
#include "paddle.h"
#include "ball.h"
#include "state.h"

class UI{
	public:
		//window
		void init_window();
		void draw_everything(const State& state);

		//score
		void set_score_l(int x){ score_l = x; };
		void set_score_r(int x){ score_r = x; };
	
		//winodw
		int get_window_height() const { return window_height; };
		int get_window_width() const { return window_width; };
	
	private:
		//window variables
		int window_width {1250};
		int window_height {750};
		int fps {60};
		const char* title {"Pong"};

		//background
		Color background_colour {BLACK};
		void draw_background();

		//line
		int line_width {10};
		int line_spacing {30};
		void draw_line();

		//score
		int score_l {};
		int score_r {};
		int score_y_displacement {40};
		int font_size {100};
		void draw_score();

		//paddles
		void draw_paddles(const Paddle& lp, const Paddle& rp);

		//ball
		int ball_size {8};
		void draw_ball(const Ball& ball);

};
