#ifndef __MAIN_H__
#define __MAIN_H__

#include "painter.h"
#include "sprite.h"
#include "game_object.h"

#define TARGET_FRAME 10
#define FRAME_DURATION 1000.0 / TARGET_FRAME

typedef struct _game_t {
	painter_t* painter;
	game_object_list_t* object_list;
} game_t;

int setup(game_t* game);
int game_start(game_t* game);
int game_update(game_t* game, double delta_time);
int game_render(game_t* game);

#endif
