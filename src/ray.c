#include "ray.h"

void ray_list_init( RayList *rays ) {
	rays->size = 0;
}

void ray_init( RayList *rays, pos_t x, pos_t y, angle_t a ) {
	Ray *r = &rays->val[rays->size++];
	r->start.x = x;
	r->start.y = y;
	r->angle = a;
}

/* vim:set ff=dos: */
