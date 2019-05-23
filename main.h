#ifndef __MAIN_H__
#define __MAIN_H__

#include "painter.h"
#include "sprite.h"

#define TARGET_FRAME 10
#define FRAME_DURATION 1000.0 / TARGET_FRAME

typedef struct _game_t {
	painter_t* painter;
	sprite_t* sprites[];
} game_t;

int setup(game_t* game);
void game_start(game_t* game);
void game_update(game_t* game, double delta_time);
void game_render(game_t* game);

#endif
