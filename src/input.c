#include "input.h"

#include <conio.h>
#include <stdbool.h>
#include <stdio.h>

Key getkey() {
	int c;

	while( true ) {
		c = getch(), getch();
		switch( c ) {
			case KEY_UP:
			case KEY_DOWN:
			case KEY_LEFT:
			case KEY_RIGHT:
				return c;
			default:
				printf("Invalid key '%c' (%x)\n", c, c);
		}
	}
}
/* vim:set ff=dos: */
