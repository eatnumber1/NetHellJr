#include "ray.h"



#include <assert.h>



void ray_list_init( RayList *rays ) {

	rays->size = 0;

}



void ray_init( RayList *rays, pos_t x, pos_t y, Direction angle, age_t age) {

	Ray *r;



	assert(rays->size != MAX_RAYS);

	r = &rays->val[rays->size++];

	r->start.x = x;

	r->start.y = y;

	r->angle = angle;

	r->age = age;

}



/* vim:set ff=dos: */

