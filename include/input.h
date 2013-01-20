#ifndef _INPUT_H_
#define _INPUT_H_

typedef void (*CommandHandler)( void * );

typedef union {
	char one;
	char two[2];
} KeyValue;

typedef enum {
	KEY_TYPE_TWO,
	KEY_TYPE_ONE
} KeyType;

typedef struct {
	KeyType type;
	KeyValue value;
} Key;

void input_new_command( Key key, CommandHandler handler, void *arg );
void input_new_command_char( char c, CommandHandler handler, void *arg );
void input_new_command_escaped( char a, char b, CommandHandler handler, void *arg );

#define MAX_COMMANDS 10

#endif
/* vim:set ff=dos: */
