#ifndef _RAY_H_
#define _RAY_H_

#include "direc.h"

#include <stdbool.h>

#define MAX_RAYS 128
#define DEFAULT_RAY_LIFETIME 9
#define RAY_SPEED 4
#define RAY_DAMAGE 1

typedef unsigned int ray_age_t;

typedef struct {
	Position start;
	Direction angle;
	ray_age_t age;
} Ray;

typedef struct {
	Ray val[MAX_RAYS];
	size_t size;
} RayList;
/* TODO: RayList is no longer needed */

void ray_list_init( RayList *rays );
void ray_init( RayList *rays, pos_t x, pos_t y, Direction a , age_t age );
bool ray_is_alive( Ray *r );

typedef bool (*RayIterator)( Ray *, void * );
bool ray_list_foreach( RayList *r, RayIterator f, void *arg );

ray_age_t ray_get_age( Ray *r );
void ray_set_age( Ray *r, ray_age_t age );
void ray_sub_age( Ray *r, ray_age_t diff );
void ray_add_age( Ray *r, ray_age_t diff );
void ray_kill( Ray *r );

#endif

/* vim:set ff=dos: */

