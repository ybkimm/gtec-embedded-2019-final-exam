#ifndef __PAINTER_H__
#define __PAINTER_H__

typedef struct _screen_t {
	int width;
	int height;
} screen_t;

typedef struct _painter_t {
	screen_t screen;
} painter_t;

void painter_update_screen (painter_t* painter, int w, int h);

#endif
