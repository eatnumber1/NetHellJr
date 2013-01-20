#include "direc.h"
#include "ray.h"

#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>

void ray_list_init( RayList *rays ) {
	rays->size = 0;
	memset(rays->val, 0, sizeof(Ray) * MAX_RAYS);
}


Direction ray_get_flipside(Direction angle){
	switch(angle){
		case DIREC_N:
		case DIREC_NE:
		case DIREC_E:
		case DIREC_SE:
			return angle+4;
		case DIREC_S:
		case DIREC_SW:
		case DIREC_W:
		case DIREC_NW:
			return angle-4;

	}
}

void ray_init( RayList *rays, pos_t x, pos_t y, Direction angle, age_t age) {
	static size_t i = 0;
	Ray *r = NULL;

	if( i == MAX_RAYS ) i = 0;
	for( ; i < MAX_RAYS; i++ ) {
		if( !ray_is_alive(r = &rays->val[i]) ) break;
	}
	if( r == NULL ) assert(false);

	rays->size++;
	r->start.x = x;
	r->start.y = y;
	r->angle = angle;
	r->age = age;
}

bool ray_is_alive( Ray *r ) {
	return r->age != 0;
}


/* vim:set ff=dos: */

