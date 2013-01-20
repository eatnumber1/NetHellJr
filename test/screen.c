#include "direc.h"
#include <stdint.h>
#include <string.h>
#include "monst.h"
#include "world.h"
#include "screen.h"

#include <stdio.h>

static void print_monster( Monster *monster ) {
	printf("%c (%d,%d) HP:%d/%d", monster->sym, monster->pos.x, monster->pos.y, monster->hp, monster->maxhp);
}

void screen_display_world( World *world ) {
	size_t i;

	print_monster(&world->you);
	printf("\n");
	for( i = 0; i < world->nmonsters; i++ ) {
		print_monster(&world->monsters[i]);
		printf(" ");
	}
	printf("\n");
}

void screen_get_dimensions( size_t *x, size_t *y ) {
	*x = 40;
	*y = 30;
}

void screen_show_chr( char c ) {
	printf("chr '%c' (%x)\n", c, c);
}

/* vim:set ff=dos: */
