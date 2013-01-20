#ifndef _RAY_H_
#define _RAY_H_

#include "direc.h"

#define MAX_RAYS 128

typedef struct {
	Position start;
	Direction angle;
} Ray;

typedef struct {
	Ray val[MAX_RAYS];
	size_t size;
} RayList;

void ray_list_init( RayList *rays );
void ray_init( RayList *rays, pos_t x, pos_t y, Direction a );

#endif
/* vim:set ff=dos: */
