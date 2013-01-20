#ifndef _WORLD_H_
#define _WORLD_H_

#include <string.h>
#include "monst.h"
#include "direc.h"

#define MAX_RAYS 128

typedef struct {
	Position start;
	angle_t angle;
} Ray;

typedef struct _World {
	Monster you;
	Ray rays[MAX_RAYS];
	size_t nrays;
	MonsterList monsters;
} World;

#endif

/* vim:set ff=dos: */
