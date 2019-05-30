#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <wiringPi.h>
#include <time.h>
#include <sys/ioctl.h>
#include "main.h"
#include "utils.h"
#include "game_object.h"
#include "painter.h"
#include "sprite.h"
#include "sprite_cards.h"

int main () {
	game_t* game = (game_t*) malloc(sizeof(game_t));
	
	setlocale(LC_ALL, "");
	
	wprintf(L"[INFO] Setup...\n");
	if (setup(game) < 0) {
		return -1;
	}
	
	return game_start(game);
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
	
	// Setup object list
	game->object_list = create_game_object_list();
	
	// Setup GPIO
	if (wiringPiSetupGpio() == -1) {
		printf("[CRIT] Failed to setup GPIO.");
		return -1;
	}
	
	return 0;
}

int game_start (game_t* game) {
	int last_update = 0;
	int current_time = 0;
	int delta_time = 0;
	
	sprite_t* sprite = CREATE_CARD_SPRITE('S', 1);
	if (sprite == NULL) {
		printf("Failed to create sprite!\n");
		return -1;
	}
	game_object_t* object = create_object(5, 3, sprite);
	
	go_list_insert(game->object_list, object);
	
	while (1) {
		current_time = millis();
		delta_time = current_time - last_update;
		
		game_update(game, delta_time);
	}
	
	return 0;
}

int game_update (game_t* game, double delta_time) {
	if (game_render(game) != 0) {
		return -1;
	}
	
	return 0;
}

int game_render (game_t* game) {
	cls();
	
	game_object_list_node_t* object_node = game->object_list->first_node;
	for (;;) {
		if (object_node == NULL) {
			break;
		}
		
		painter_draw_object(game->painter, object_node->object);
	}
	
	return 0;
}
