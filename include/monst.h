#ifndef _MONST_H_
#define _MONST_H_

typedef uint_fast16_t mon_pos_t;

struct _MonsterPosition {
	mon_pos_t x, y;
};

typedef struct {
	char sym;
	uint_fast8_t maxhp, hp;
	struct _MonsterPosition pos;
} Monster;

struct _World;

void monster_init_you( Monster *m, char sym, uint_fast8_t hp, uint_fast8_t maxhp, mon_pos_t x, mon_pos_t y );
void monster_init( struct _World *w, char sym, uint_fast8_t hp, uint_fast8_t maxhp, mon_pos_t x, mon_pos_t y );
void monster_set_position( Monster *mon, mon_pos_t x, mon_pos_t y );
void monster_move( Monster *m, Direction d );

#endif
/* vim:set ff=dos: */
