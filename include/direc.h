#ifndef _DIREC_H_
#define _DIREC_H_

#include <stdint.h>

typedef enum {
	DIREC_N,
	DIREC_NE,
	DIREC_E,
	DIREC_SE,
	DIREC_S,
	DIREC_SW,
	DIREC_W,
	DIREC_NW
} Direction;

typedef uint_fast16_t pos_t;
typedef uint_fast8_t age_t;

typedef struct _Position {
	pos_t x, y;
} Position;

#endif

/* vim:set ff=dos: */
