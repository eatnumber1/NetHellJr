#ifndef _WORLD_H_
#define _WORLD_H_

#define MAX_MONSTERS 128

#include <string.h>

typedef struct _World {
	Monster you;
	Monster monsters[MAX_MONSTERS];
	size_t nmonsters;
} World;

#endif

/* vim:set ff=dos: */
