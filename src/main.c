#include "world.h"
#include "screen.h"
#include "input.h"

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
	World world;
	world.nmonsters = 1;

	world.monsters[0].sym = 'Z';
	world.monsters[0].hp = 5;
	world.monsters[0].maxhp = 10;
	monster_set_position(&world.monsters[0], 5, 8);
	world.monsters[0].pos.x = 5;
	world.monsters[0].pos.y = 8;

	world.you.sym = '@';
	world.you.hp = 1;
	world.you.maxhp = 30;
	monster_set_position(&world.you, 1, 1);
	world.you.pos.x = 1;
	world.you.pos.y = 1;

	display_world(&world);

	while( true ) {
		Key key = getkey();
		printf("Got key %c\n", key);
	}
}

/* vim:set ff=dos: */
