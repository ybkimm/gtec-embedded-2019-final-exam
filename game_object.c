#include <stdlib.h>
#include "game_object.h"
#include "sprite.h"

game_object_t* create_object(int pos_x, int pos_y, sprite_t* sprite) {
	game_object_t* object = (game_object_t*) malloc(sizeof(game_object_t));
	
	object->pos_x = pos_x;
	object->pos_y = pos_y;
	object->sprite = sprite;
	
	return object;
}
