#include "screen.h"
#include "world.h"

#include <stdio.h>
#include <stdint.h>

static void print_monster( Monster *monster ) {
	printf("%c (%d,%d) HP:%d/%d", monster->sym, monster->pos.x, monster->pos.y, monster->hp, monster->maxhp);
}

void display_world( World *world ) {
	size_t i;

	print_monster(&world->you);
	printf("\n");
	for( i = 0; i < world->nmonsters; i++ ) {
		print_monster(&world->monsters[i]);
		printf(" ");
	}
	printf("\n");
}

/* vim:set ff=dos: */
