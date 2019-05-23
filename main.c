#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include <time.h>
#include <sys/ioctl.h>
#include "main.h"
#include "utils.h"
#include "painter.h"
#include "sprite.h"
#include "sprite_cards.h"

int main () {
	game_t* game = (game_t*) malloc(sizeof(game_t));
	
	printf("[INFO] Setup...\n");
	if (setup(game) < 0) {
		return -1;
	}
	
	game_start(game);
	
	return 0;
}

int setup (game_t* game) {
	// check terminal size
	struct winsize term_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &term_size);
	
	if (term_size.ws_col < 80 || term_size.ws_row < 24) {
		printf("[CRIT] Terminal size is too small.\n");
		printf("[CRIT] Please increase the size of the terminal and try again!\n");
		printf("[CRIT] HINT: Minimum size is: 80 columns, 24 rows.\n");
		return -1;
	}
	
	// Setup painter
	game->painter = (painter_t*) malloc(sizeof(painter_t));
	painter_update_screen(game->painter, term_size.ws_col, term_size.ws_row);
	
	// Setup GPIO
	if (wiringPiSetupGpio() == -1) {
		printf("[CRIT] Failed to setup GPIO.");
		return -1;
	}
	
	return 0;
}

void game_start (game_t* game) {
	int last_update = 0;
	int current_time = 0;
	int delta_time = 0;
	
	while (1) {
		current_time = millis();
		delta_time = current_time - last_update;
		
		update(game, delta_time);
	}
}

void game_update (game_t* game, double delta_time) {
	printf("Update!");
}

void game_render (game_t* game) {
	cls();
}
