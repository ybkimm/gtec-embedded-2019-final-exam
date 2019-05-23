#ifndef __SPRITE_H__
#define __SPRITE_H__

typedef struct _sprite_t {
	int width;
	int height;
	char* data;
} sprite_t;

sprite_t* create_sprite(int width, int height, const char* spriteData);

#endif
