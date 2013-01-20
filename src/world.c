#include "world.h"

void monster_set_position( Monster *mon, mon_pos_t x, mon_pos_t y ) {
	mon->pos.x = x;
	mon->pos.y = y;
}
