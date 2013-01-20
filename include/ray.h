#ifndef _RAY_H_
#define _RAY_H_

#include "direc.h"

#include <stdbool.h>

#define MAX_RAYS 128
#define DEFAULT_RAY_LIFETIME 6


typedef struct {
	Position start;
	Direction angle;
	unsigned int age;
} Ray;

typedef struct {
	Ray val[MAX_RAYS];
	size_t size;
} RayList;

void ray_list_init( RayList *rays );
void ray_init( RayList *rays, pos_t x, pos_t y, Direction a , age_t age );
bool ray_is_alive( Ray *r );

#endif

/* vim:set ff=dos: */

