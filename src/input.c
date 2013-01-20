#include "input.h"

#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct {
	Key key;
	CommandHandler handler;
	void *arg;
} Command;

static size_t commands_len = 0;
static Command commands[MAX_COMMANDS];

void input_new_command( Key key, CommandHandler handler, void *arg ) {
	Command *command;

	assert(commands_len < MAX_COMMANDS);
	command = &commands[commands_len++];
	memcpy(&command->key, &key, sizeof(Key));
	command->handler = handler;
	command->arg = arg;
}

void input_new_command_char( char c, CommandHandler handler, void *arg ) {
	Key key;

	key.type = KEY_TYPE_ONE;
	key.value.one = c;
	input_new_command(key, handler, arg);
}

void input_new_command_escaped( char a, char b, CommandHandler handler, void *arg ) {
	Key key;

	key.type = KEY_TYPE_TWO;
	key.value.two[0] = a;
	key.value.two[1] = b;
	input_new_command(key, handler, arg);
}

static char get_val_two( KeyValue *val ) {
	return val->one;
}

static char get_val_one( KeyValue *val ) {
	return val->two[1];
}

static Command *get_command() {
	int c;
	char v, d;
	char (*valof)( KeyValue * );
	size_t i;

	while( true ) {
		c = getch();
		if( c == 0 ) {
			c = getch();
			valof = get_val_one;
		} else {
			valof = get_val_two;
		}
		screen_show_chr(c);
		for( i = 0; i < commands_len; i++ ) {
			Command *cmd = &commands[i];
			d = valof(&cmd->key.value);
			if( d == c ) return cmd;
		}
	}
}

void input_read_and_process() {
	Command *cmd = get_command();
	cmd->handler(cmd->arg);
}
/* vim:set ff=dos: */
