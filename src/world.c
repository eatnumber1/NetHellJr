#include "direc.h"
#include "monst.h"
#include "ray.h"
#include "world.h"
#include "screen.h"

#include <stdbool.h>

int world_fall_off_edge(int x, int y){
	return (( x < 0 || x > 39) || ( y < 0 || y > 23));
}

#define RAY_SPEED 4
void world_tick( World *world ) {
	int i;
	Ray *ray;

	for(i=0; i<world->rays.size; ++i){
		ray = &world->rays.val[i];
		
		if(ray->age >= 0){
			switch(ray->angle){
				case DIREC_N:
					ray->start.y-=RAY_SPEED;
					break;
				case DIREC_NE:
					ray->start.y-=RAY_SPEED;
					ray->start.x+=RAY_SPEED;
					break;
				case DIREC_E:
					ray->start.x+=RAY_SPEED;
					break;
				case DIREC_SE:
					ray->start.x+=RAY_SPEED;
					ray->start.y+=RAY_SPEED;
					break;
				case DIREC_S:
					ray->start.y+=RAY_SPEED;
					break;
				case DIREC_SW:
					ray->start.x-=RAY_SPEED;
					ray->start.y+=RAY_SPEED;
					break;
				case DIREC_W:
					ray->start.x-=RAY_SPEED;
					break;
				case DIREC_NW:
					ray->start.x-=RAY_SPEED;
					ray->start.y-=RAY_SPEED;
					break;
			}
			if(world_fall_off_edge(ray->start.x,ray->start.y)){
				/*could do reflection here if we have time */
				ray->age-=1;
				ray->angle = ray_get_flipside(ray->angle);
			}
			else{
				ray->age -= 1;

				/* check intersection against peeps + reduce health */
			}
			ray_init(&world->rays,
				screen_grid_to_coordinate(ray->start.x),
				screen_grid_to_coordinate(ray->start.y),
				ray->angle,
				ray->age);
		}
	}
}

void world_init( World *w ) {
	monster_list_init(&w->monsters);
	ray_list_init(&w->rays);
}

static bool is_collision( MonsterList *m, Position *p ) {
	size_t i;

	for( i = 0; i < m->size; i++ ) {
		Position *mp = &m->val[i].pos;
		if( mp->x == p->x && mp->y == p->y ) return true;
	}
	return false;
}

WorldError world_move_monster( World *w, Monster *m, Direction d ) {
	static size_t max_x, max_y;
	static bool has_dimensions = false;
	Position np;

	if( !has_dimensions ) {
		screen_get_dimensions(&max_x, &max_y);
		has_dimensions = true;
	}

	np.x = m->pos.x;
	np.y = m->pos.y;
	switch( d ) {
		case DIREC_S:
			if( np.y == max_y - 1 ) goto collision;
			np.y += 1;
			break;
		case DIREC_N:
			if( np.y == 0 ) goto collision;
			np.y -= 1;
			break;
		case DIREC_E:
			if( np.x == max_x - 1 ) goto collision;
			np.x += 1;
			break;
		case DIREC_W:
			if( np.x == 0 ) goto collision;
			np.x -= 1;
			break;
	}
	if( is_collision(&w->monsters, &np) ) goto collision;
	m->pos.x = np.x;
	m->pos.y = np.y;

	return WORLD_ERR_OK;

collision:
	return WORLD_ERR_COLLIDE;
}

/* vim:set ff=dos: */
