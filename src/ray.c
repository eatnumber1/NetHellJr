#include "ray.h"



#include <assert.h>



void ray_list_init( RayList *rays ) {

	rays->size = 0;

}


Direction ray_get_flipside(Direction angle){
	switch(angle){
		case 0:
		case 1:
		case 2:
		case 3:
			return angle+4;
		case 4:
		case 5:
		case 6:
		case 7:
			return angle-4;

	}
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

