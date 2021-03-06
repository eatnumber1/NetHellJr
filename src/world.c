#include "direc.h"
#include "monst.h"
#include "ray.h"
#include "world.h"
#include "screen.h"

#include <stdbool.h>
#include <assert.h>
#include <Math.h>


int world_fall_off_edge(int x, int y){
	return (( x < 0 || x > 39) || ( y < 0 || y > 23));
}

bool intersects(Monster* monster, Ray* ray){
	return
	(abs(abs(ray->start.x)-abs(monster->pos.x)) < 2) &&
	(abs(abs(ray->start.y)-abs(monster->pos.y)) < 2);
}

Direction world_direction_of( Monster *me, Monster *them ) {
	Direction d;

	if( me->pos.x > them->pos.x ) {
		if( me->pos.y > them->pos.y ) {
			d = DIREC_NW;
		} else if( me->pos.y < them->pos.y ) {
			d = DIREC_SW;
		} else {
			d = DIREC_W;
		}
	} else if( me->pos.x < them->pos.x ) {
		if( me->pos.y > them->pos.y ) {
			d = DIREC_NE;
		} else if( me->pos.y < them->pos.y ) {
			d = DIREC_SE;
		} else {
			d = DIREC_E;
		}
	} else {
		if( me->pos.y > them->pos.y ) {
			d = DIREC_N;
		} else if( me->pos.y < them->pos.y ) {
			d = DIREC_S;
		} else {
			/* assert(false); */
		}
	}
	return d;
}

static bool do_monster_ai( Monster *m, World *w ) {
	Direction d;

	if( m == &w->you ) return true;
	d = world_direction_of(m, &w->you);
	/*
	 * We're already unfair not allowing diagonal movement or shooting.
	 * Lets only do EITHER shooting or movement
	 */
	switch( d ) {
		case DIREC_N:
		case DIREC_S:
		case DIREC_E:
		case DIREC_W:
			ray_init(&w->rays, m->pos.x, m->pos.y, d, DEFAULT_RAY_LIFETIME);
			break;
		case DIREC_NE:
		case DIREC_SW:
		case DIREC_NW:
		case DIREC_SE:
			world_move_monster(w, m, d);
			break;
		default:
			/* assert(false); */
			break;
	}
	return true;
}

static bool do_monster_damage( Monster *monster, Ray *ray ) {
	if( intersects(monster, ray) ) {
		monster_sub_health(monster, RAY_DAMAGE);
		if( !monster_is_alive(monster) ) {
			ray_sub_age(ray, DEFAULT_RAY_LIFETIME / 2);
		} else {
			ray_kill(ray);
		}
	}
	return true;
}

static bool do_ray_movement( Ray *ray, World *world ) {
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
		ray->age-=1;
		ray->angle = ray_get_flipside(ray->angle);
	} else {
		ray->age -= 1;

		/* check intersection against peeps + reduce health */
		monster_list_foreach(&world->monsters, (MonsterIterator) do_monster_damage, ray);
	}
	return true;
}

void world_tick( World *world ) {
	int i;
	Ray *ray;
	Monster *monster;

	ray_list_foreach(&world->rays, (RayIterator) do_ray_movement, world);
	monster_list_foreach(&world->monsters, (MonsterIterator) do_monster_ai, world);
}

void world_init( World *w ) {
	monster_list_init(&w->monsters, &w->you);
	ray_list_init(&w->rays);
}

static bool single_is_not_collision( Monster *m, Position *p ) {
	Position *mp;

	mp = &m->pos;
	return mp->x != p->x || mp->y != p->y;
}

static bool is_collision( MonsterList *m, Position *p ) {
	return !monster_list_foreach(m, (MonsterIterator) single_is_not_collision, p);
}

WorldError world_move_monster( World *w, Monster *m, Direction d ) {
	static size_t max_x, max_y;
	static bool has_dimensions = false;
	Position np;
	WorldError err, err2;

	if( !has_dimensions ) {
		screen_get_dimensions(&max_x, &max_y);
		has_dimensions = true;
	}

	np.x = m->pos.x;
	np.y = m->pos.y;
	switch( d ) {
		case DIREC_NE:
			err = world_move_monster(w, m, DIREC_N);
			err2 = world_move_monster(w, m, DIREC_E);
			if( err != WORLD_ERR_OK ) {
				return err;
			} else if( err2 != WORLD_ERR_OK ) {
				return err2;
			}
			return WORLD_ERR_OK;
		case DIREC_SE:
			err = world_move_monster(w, m, DIREC_S);
			err2 = world_move_monster(w, m, DIREC_E);
			if( err != WORLD_ERR_OK ) {
				return err;
			} else if( err2 != WORLD_ERR_OK ) {
				return err2;
			}
			return WORLD_ERR_OK;
		case DIREC_SW:
			err = world_move_monster(w, m, DIREC_S);
			err2 = world_move_monster(w, m, DIREC_W);
			if( err != WORLD_ERR_OK ) {
				return err;
			} else if( err2 != WORLD_ERR_OK ) {
				return err2;
			}
			return WORLD_ERR_OK;
		case DIREC_NW:
			err = world_move_monster(w, m, DIREC_N);
			err2 = world_move_monster(w, m, DIREC_W);
			if( err != WORLD_ERR_OK ) {
				return err;
			} else if( err2 != WORLD_ERR_OK ) {
				return err2;
			}
			return WORLD_ERR_OK;
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
		default:
			assert(false);
	}
	if( is_collision(&w->monsters, &np) ) goto collision;
	m->pos.x = np.x;
	m->pos.y = np.y;

	return WORLD_ERR_OK;

collision:
	return WORLD_ERR_COLLIDE;
}

/* vim:set ff=dos: */
