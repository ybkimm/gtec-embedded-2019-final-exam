#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <wchar.h>

typedef struct _sprite_t {
	int width;
	int height;
	wchar_t* data;
} sprite_t;

sprite_t* create_sprite(unsigned int width, unsigned int height, wchar_t* spriteData);

#endif
