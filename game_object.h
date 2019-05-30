#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <stdlib.h>
#include "sprite.h"

typedef struct game_object_t {
	sprite_t* sprite;
	int pos_x;
	int pos_y;
} game_object_t;

game_object_t* create_object(int x, int y, sprite_t* sprite);


typedef struct game_object_list_node_t {
	game_object_t* object;
	game_object_list_node_t* prev_node;
	game_object_list_node_t* next_node;
} game_object_list_node_t;

game_object_list_node_t* create_game_object_list_node(game_object_t* object) {
	game_object_list_node_t* node = (game_object_list_node_t*) malloc(sizeof(game_object_list_node_t));
	node->object = object;
	node->prev_node = NULL;
	node->next_node = NULL;
	return node;
}


typedef struct game_object_list_t {
	game_object_list_node_t* first_node;
	game_object_list_node_t* last_node;
} game_object_list_t;

game_object_list_t* create_game_object_list() {
	game_object_list_t* list = (game_object_list_t*) malloc(sizeof(game_object_list_t));
	list->first_node = NULL;
	return list;
}

void go_list_insert (game_object_list_t* list, game_object_t* object) {
	game_object_list_node_t* node = create_game_object_list_node(list, object);
	
	if (list->last_node == NULL) {
		list->first_node = node;
		list->last_node = node;
	} else {
		list->last_node->next_node = node;
		node->prev_node = list->last_node;
		list->last_node = node;
	}
}

game_object_list_node_t* go_list_search(game_object_list_t* list, game_object_t* object) {
	game_object_list_node_t* node = list->first_node;
	
	for (;;) {
		if (node == NULL) {
			break;
		}
		
		if (node->object != object) {
			node = node->next_node;
			continue;
		}
		
		break;
	}
	
	if (node == NULL) {
		return NULL;
	}
	
	return node;
}

void go_list_delete(game_object_list_t* list, game_object_t* object) {
	game_object_list_node_t* node = go_list_search(list, object);
	
	if (node != NULL) {
		node->prev_node->next_node = node->next_node;
		node->next_node->prev_node = node->prev_node;
	
		free(node);
	}
	
	return;
}

#endif
