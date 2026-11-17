#include <iostream>
#include <string>
#include "ui.h"
#include "paddle.h"
#include "ball.h"
#include "game.h"

int main(){
    UI ui {};
    ui.init_window();

    Game game {};
    game.init(ui.get_window_width(), ui.get_window_height());

    while(!WindowShouldClose()){
        //input
        game.read_input();
        game.process();
        ui.set_score_l( game.get_l_score() );
        ui.set_score_r( game.get_r_score() );

        //render
        ui.draw_everything( game.get_state() );
    }

	return 0;
}

