#include "monst.h"
#include "world.h"

void world_init( World *w ) {
	monster_list_init(&w->monsters);
	w->nrays = 0;
}

/* vim:set ff=dos: */
