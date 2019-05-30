#include <stdio.h>
#include <stdlib.h>
#include "painter.h"
#include "sprite.h"

#define MOVE_POS(x,y) wprintf(L"\033[%d;%dH", (y) + 1, (x))

void painter_update_screen (painter_t* painter, int w, int h) {
	painter->screen.width = w;
	painter->screen.height = h;
}

void painter_print_row(painter_t* painter, sprite_t* sprite, int line) {
	int width = sprite->width;

	wchar_t* sprite_data = sprite->data;
	wchar_t* sprite_line = (wchar_t*) malloc(width * sizeof(wchar_t));
	
	int offset = width * line;
	for (int i = 0; i < width; i++) {
		sprite_line[i] = sprite_data[offset + i];
	}
	
	wprintf(L"%ls\n", sprite_line);
}

void painter_draw_sprite(painter_t* painter, sprite_t* sprite, int pos_x, int pos_y) {
	int height = sprite->height;
	
	for (int y = 0; y < height; y++) {
		MOVE_POS(pos_x, pos_y + y);
		painter_print_row(painter, sprite, y);
	}
	
}

void painter_draw_object(painter_t* painter, game_object_t* object) {
	painter_draw_sprite(painter, object->sprite, object->pos_x, object->pos_y);
}
