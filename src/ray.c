#include "ray.h"

#include <assert.h>

void ray_list_init( RayList *rays ) {
	rays->size = 0;
}

void ray_init( RayList *rays, pos_t x, pos_t y, Direction a ) {
	Ray *r;

	assert(rays->size != MAX_RAYS);
	r = &rays->val[rays->size++];
	r->start.x = x;
	r->start.y = y;
	r->angle = a;
}

/* vim:set ff=dos: */
