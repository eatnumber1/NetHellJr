#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "world.h"

#include <stdint.h>

void screen_display_world( World *world );
void screen_get_dimensions( size_t *x, size_t *y );

void screen_show_chr( char c );

#endif

/* vim:set ff=dos: */
