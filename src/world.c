#include "monst.h"
#include "ray.h"
#include "world.h"

void world_init( World *w ) {
	monster_list_init(&w->monsters);
	ray_list_init(&w->rays);
}

/* vim:set ff=dos: */
