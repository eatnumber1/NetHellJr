#include "monst.h"
#include "ray.h"
#include "world.h"

void world_init( World *w ) {
	monster_list_init(&w->monsters);
	ray_list_init(&w->rays);
}

int world_fall_off_edge(int x, int y){
	return (( x < 0 || x > 39) || ( y < 0 || y > 23));
}

#define RAY_SPEED 4
void world_tick( World *world ) {
	int i;
	Ray *ray;

	for(i=0; i<world->rays.size; ++i){
		ray = &world->rays.val[i];
		if(ray->start.x < 0 || ray->start.y < 0){
		}
		else{
			switch(ray->angle){
				case 0:
					ray->start.y-=RAY_SPEED;
					break;
				case 1:
					ray->start.y-=RAY_SPEED;
					ray->start.x+=RAY_SPEED;
					break;
				case 2:
					ray->start.x+=RAY_SPEED;
					break;
				case 3:
					ray->start.x+=RAY_SPEED;
					ray->start.y+=RAY_SPEED;
					break;
				case 4:
					ray->start.y+=RAY_SPEED;
					break;
				case 5:
					ray->start.x-=RAY_SPEED;
					ray->start.y+=RAY_SPEED;
					break;
				case 6:
					ray->start.x-=RAY_SPEED;
					break;
				case 7:
					ray->start.x-=RAY_SPEED;
					ray->start.y-=RAY_SPEED;
					break;
			}
			if(world_fall_off_edge(ray->start.x,ray->start.y)){
				/*could do reflection here if we have time */
				ray->start.x= -1, ray->start.y= -1;
			}
			else{
				/* check intersection against peeps + reduce health */
			}
			ray_init(&world->rays,
				screen_grid_to_coordinate(ray->start.x),
				screen_grid_to_coordinate(ray->start.y),
				ray->angle);
		}
	}
}
/* vim:set ff=dos: */
