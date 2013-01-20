#include "monst.h"
#include "world.h"
#include "screen.h"
#include "input.h"
#include "ray.h"

#include <stdbool.h>
#include <stddef.h>
#include <process.h>
#include <stdint.h>
#include <stdlib.h>

static void key_s( World *world ) {
	world_move_monster(world, &world->you, DIREC_S);
}

static void key_n( World *world ) {
	world_move_monster(world, &world->you, DIREC_N);
}

static void key_w( World *world ) {
	world_move_monster(world, &world->you, DIREC_W);
}

static void key_e( World *world ) {
	world_move_monster(world, &world->you, DIREC_E);
}

static void key_ne( World *world ) {
	world_move_monster(world, &world->you, DIREC_NE);
}

static void key_se( World *world ) {
	world_move_monster(world, &world->you, DIREC_SE);
}

static void key_sw( World *world ) {
	world_move_monster(world, &world->you, DIREC_SW);
}

static void key_nw( World *world ) {
	world_move_monster(world, &world->you, DIREC_NW);
}

static void key_fire_left( World *world ) {
	ray_init(&world->rays, world->you.pos.x, world->you.pos.y, DIREC_W, DEFAULT_RAY_LIFETIME);
}

static void key_fire_right( World *world ) {
	ray_init(&world->rays, world->you.pos.x, world->you.pos.y, DIREC_E, DEFAULT_RAY_LIFETIME);
}

static void key_fire_up( World *world ) {
	ray_init(&world->rays, world->you.pos.x, world->you.pos.y, DIREC_N, DEFAULT_RAY_LIFETIME);
}

static void key_fire_down( World *world ) {
	ray_init(&world->rays, world->you.pos.x, world->you.pos.y, DIREC_S, DEFAULT_RAY_LIFETIME);
}

static void key_wait() {
}

static void quit() {
	screen_kill_graphics();
	exit(0);
}

int main() {
	World world;
	world_init(&world);

	monster_init_you(&world.you, '@', 50, 50, 20, 15);
	monster_init(&world.monsters, 'Z', 10, 10, 5, 15);
	monster_init(&world.monsters, 'V', 10, 10, 35, 15);

	input_new_command_char('q', (CommandHandler) quit, NULL);
	input_new_command_escaped(0, 'H', (CommandHandler) key_n, &world);
	input_new_command_escaped(0, 'P', (CommandHandler) key_s, &world);
	input_new_command_escaped(0, 'K', (CommandHandler) key_w, &world);
	input_new_command_escaped(0, 'M', (CommandHandler) key_e, &world);

	input_new_command_char('k', (CommandHandler) key_n, &world);
	input_new_command_char('j', (CommandHandler) key_s, &world);
	input_new_command_char('h', (CommandHandler) key_w, &world);
	input_new_command_char('l', (CommandHandler) key_e, &world);
	input_new_command_char('y', (CommandHandler) key_nw, &world);
	input_new_command_char('u', (CommandHandler) key_ne, &world);
	input_new_command_char('b', (CommandHandler) key_sw, &world);
	input_new_command_char('n', (CommandHandler) key_se, &world);

	input_new_command_char('w', (CommandHandler) key_fire_up, &world);
	input_new_command_char('s', (CommandHandler) key_fire_down, &world);
	input_new_command_char('a', (CommandHandler) key_fire_left, &world);
	input_new_command_char('d', (CommandHandler) key_fire_right, &world);

	input_new_command_char('.', (CommandHandler) key_wait, NULL);

	screen_initialize_graphics();
	screen_display_start_message();

	while( true ) {
		screen_display_world(&world);
		input_read_and_process();
		if(random(3)==1){
			monster_init(&world.monsters, random(2)?random(26)+64:random(26)+96, 10, 10, random(39), random(27));
		}
		world_tick(&world);
	}
}

/* vim:set ff=dos: */
