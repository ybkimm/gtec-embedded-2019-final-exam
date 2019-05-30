#ifndef __PAINTER_H__
#define __PAINTER_H__

#include "sprite.h"
#include "game_object.h"

typedef struct _screen_t {
	int width;
	int height;
} screen_t;

typedef struct _painter_t {
	screen_t screen;
} painter_t;

void painter_update_screen (painter_t* painter, int w, int h);
void painter_print_row(painter_t* painter, sprite_t* sprite, int line);
void painter_draw_sprite(painter_t* painter, sprite_t* sprite, int width, int height);
void painter_draw_object(painter_t* painter, game_object_t* object);

#endif
