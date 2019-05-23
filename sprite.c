#include <stdlib.h>
#include <string.h>
#include "sprite.h"

sprite_t* create_sprite(int width, int height, const char* spriteData) {
	// Validate sprite data
	if (strlen(spriteData) != width * height) {
		return NULL;
	}
	
	sprite_t* sprite = (sprite_t*) malloc(sizeof(sprite_t));
	sprite->width = width;
	sprite->height = height;
	sprite->data = spriteData;
	
	return sprite;
}
