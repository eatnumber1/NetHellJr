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

bool ray_list_foreach( RayList *rays, RayIterator f, void *arg ) {
	size_t i;
	Ray *ray;

	for( i = 0; i < MAX_RAYS; i++ ) {
		if( ray_is_alive(ray = &rays->val[i]) && !f(ray, arg) )
			return false;
	}

	return true;
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

ray_age_t ray_get_age( Ray *r ) {
	return r->age;
}

void ray_set_age( Ray *r, ray_age_t age ) {
	r->age = age;
}

void ray_sub_age( Ray *r, ray_age_t diff ) {
	if( r->age < diff ) {
		r->age = 0;
	} else {
		r->age -= diff;
	}
}

void ray_add_age( Ray *r, ray_age_t diff ) {
	r->age += diff;
}

void ray_kill( Ray *r ) {
	r->age = 0;
}

/* vim:set ff=dos: */

