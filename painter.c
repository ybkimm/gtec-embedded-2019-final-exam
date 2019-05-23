#include "painter.h"

void painter_update_screen (painter_t* painter, int w, int h) {
	painter->screen.width = w;
	painter->screen.height = h;
}
