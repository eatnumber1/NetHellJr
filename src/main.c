#include "world.h"
#include "screen.h"
#include "input.h"

#include <stdint.h>
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

int main() {
	World world;
	world.nmonsters = 1;
	world.nrays = 1;

	world.monsters[0].sym = 'Z';
	world.monsters[0].hp = 5;
	world.monsters[0].maxhp = 10;
	monster_set_position(&world.monsters[0], 5, 8);

	world.rays[0].start.x = 6;
	world.rays[0].start.y = 9;
	world.rays[0].angle = 3;
	
	world.you.sym = '@';
	world.you.hp = 1;
	world.you.maxhp = 30;
	monster_set_position(&world.you, 20, 15);

	input_new_command_char('q', (CommandHandler) exit, NULL);
	input_new_command_escaped(0, 'H', (CommandHandler) key_up, &world);
	input_new_command_escaped(0, 'P', (CommandHandler) key_down, &world);
	input_new_command_escaped(0, 'K', (CommandHandler) key_left, &world);
	input_new_command_escaped(0, 'M', (CommandHandler) key_right, &world);

	screen_initialize_graphics();
	while( true ) {
		screen_display_world(&world);
		input_read_and_process();
	}
	screen_kill_graphics();
}

/* vim:set ff=dos: */
