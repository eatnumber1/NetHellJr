#include "monst.h"
#include "world.h"
#include "screen.h"
#include "input.h"
#include "ray.h"

#include <stdbool.h>
#include <stddef.h>
#include <process.h>
#include <stdint.h>

static void key_down( World *world ) {
	world_move_monster(world, &world->you, DIREC_S);
}

static void key_up( World *world ) {
	world_move_monster(world, &world->you, DIREC_N);
}

static void key_left( World *world ) {
	world_move_monster(world, &world->you, DIREC_W);
}

static void key_right( World *world ) {
	world_move_monster(world, &world->you, DIREC_E);
}

static void key_fire_left( World *world ) {
	ray_init(&world->rays, world->you.pos.x, world->you.pos.y, DIREC_W);
}

static void key_fire_right( World *world ) {
	ray_init(&world->rays, world->you.pos.x, world->you.pos.y, DIREC_E);
}

static void key_fire_up( World *world ) {
	ray_init(&world->rays, world->you.pos.x, world->you.pos.y, DIREC_N);
}

static void key_fire_down( World *world ) {
	ray_init(&world->rays, world->you.pos.x, world->you.pos.y, DIREC_S);
}

static void quit() {
	screen_kill_graphics();
	exit(0);
}

int main() {
	World world;
	world_init(&world);

	monster_init_you(&world.you, '@', 1, 30, 20, 15);
	monster_init(&world.monsters, 'Z', 5, 10, 5, 8);
	monster_init(&world.monsters, 'V', 5, 10, 8, 5);

	ray_init(&world.rays, 6, 9, 0);
	ray_init(&world.rays, 6, 9, 1);
	ray_init(&world.rays, 6, 9, 2);
	ray_init(&world.rays, 6, 9, 3);
	ray_init(&world.rays, 6, 9, 4);
	ray_init(&world.rays, 6, 9, 5);
	ray_init(&world.rays, 6, 9, 6);
	ray_init(&world.rays, 6, 9, 7);

	input_new_command_char('q', (CommandHandler) quit, NULL);
	input_new_command_escaped(0, 'H', (CommandHandler) key_up, &world);
	input_new_command_escaped(0, 'P', (CommandHandler) key_down, &world);
	input_new_command_escaped(0, 'K', (CommandHandler) key_left, &world);
	input_new_command_escaped(0, 'M', (CommandHandler) key_right, &world);

	input_new_command_char('w', (CommandHandler) key_up, &world);
	input_new_command_char('s', (CommandHandler) key_down, &world);
	input_new_command_char('a', (CommandHandler) key_left, &world);
	input_new_command_char('d', (CommandHandler) key_right, &world);

	input_new_command_char('i', (CommandHandler) key_fire_up, &world);
	input_new_command_char('k', (CommandHandler) key_fire_down, &world);
	input_new_command_char('j', (CommandHandler) key_fire_left, &world);
	input_new_command_char('l', (CommandHandler) key_fire_right, &world);

	screen_initialize_graphics();
	while( true ) {
		screen_display_world(&world);
		input_read_and_process();
		world_tick(&world);
	}
}

/* vim:set ff=dos: */
