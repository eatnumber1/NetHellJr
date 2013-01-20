#include "direc.h"

#include <stdint.h>

#include "monst.h"
#include "world.h"
#include "screen.h"
#include "input.h"

#include <stdbool.h>
#include <stddef.h>
#include <process.h>

static void key_down( World *world ) {
	monster_move(&world->you, DIRECTION_DOWN);
}

static void key_up( World *world ) {
	monster_move(&world->you, DIRECTION_UP);
}

static void key_left( World *world ) {
	monster_move(&world->you, DIRECTION_LEFT);
}

static void key_right( World *world ) {
	monster_move(&world->you, DIRECTION_RIGHT);
}

static void quit() {
	screen_kill_graphics();
	exit(0);
}

int main() {
	World world;
	world_init(&world);

	monster_init_you(&world.you, '@', 1, 30, 20, 15);
	monster_init(&world, 'Z', 5, 10, 5, 8);
	monster_init(&world, 'V', 5, 10, 8, 5);

	input_new_command_char('q', (CommandHandler) quit, NULL);
	input_new_command_escaped(0, 'H', (CommandHandler) key_up, &world);
	input_new_command_escaped(0, 'P', (CommandHandler) key_down, &world);
	input_new_command_escaped(0, 'K', (CommandHandler) key_left, &world);
	input_new_command_escaped(0, 'M', (CommandHandler) key_right, &world);

	screen_initialize_graphics();
	while( true ) {
		screen_display_world(&world);
		input_read_and_process();
	}
}

/* vim:set ff=dos: */
