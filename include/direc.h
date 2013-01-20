#ifndef _DIREC_H_
#define _DIREC_H_

#include <stdint.h>

typedef enum {
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT
} Direction;

typedef uint_fast16_t pos_t;
typedef uint_fast8_t angle_t;

typedef struct _Position {
	pos_t x, y;
} Position;

#endif

/* vim:set ff=dos: */
