#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "sprite.h"

sprite_t* create_sprite(unsigned int width, unsigned int height, wchar_t* spriteData) {
	sprite_t* sprite = (sprite_t*) malloc(sizeof(sprite_t));
	sprite->width = width;
	sprite->height = height;
	sprite->data = spriteData;
	
	return sprite;
}
