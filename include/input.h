#ifndef _INPUT_H_
#define _INPUT_H_

typedef enum {
	KEY_UP = 'K',
	KEY_DOWN = 'P',
	KEY_LEFT = 'M',
	KEY_RIGHT = 'H'
} Key;

Key getkey();

#endif
/* vim:set ff=dos: */
