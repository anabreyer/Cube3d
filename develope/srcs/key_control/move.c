#include "cub3d.h"

void move_w(t_player *player, t_map *map)
{
    double  vector_x;
    double  vector_y;
    double  wall_dist;

    wall_dist = 1.1;
    vector_x = player->dir_x * player->speed_move;
    vector_y = player->dir_y * player->speed_move;
    if (map->map[(int)(player->pos_y)][(int)(player->pos_x + vector_x * wall_dist)] == '0')
        player->pos_x += vector_x;
    if (map->map[(int)(player->pos_y + vector_y * wall_dist)][(int)(player->pos_x)] == '0')
        player->pos_y += vector_y;
}

void move_s(t_player *player, t_map *map)
{
    double  vector_x;
    double  vector_y;
    double  wall_dist;

    wall_dist = 1.1;
    vector_x = player->dir_x * player->speed_move;
    vector_y = player->dir_y * player->speed_move;
    if (map->map[(int)(player->pos_y)][(int)(player->pos_x - vector_x * wall_dist)] == '0')
        player->pos_x -= vector_x;
    if (map->map[(int)(player->pos_y - vector_y * wall_dist)][(int)(player->pos_x)] == '0')
        player->pos_y -= vector_y;
}

void move_d(t_player *player, t_map *map)
{
    double  vector_x;
    double  vector_y;
    double  wall_dist;

    wall_dist = 1.1;
    vector_x = player->dir_x * player->speed_move;
    vector_y = player->dir_y * player->speed_move;
    if (map->map[(int)(player->pos_y)][(int)(player->pos_x + vector_y * wall_dist)] == '0')
        player->pos_x += vector_y;
    if (map->map[(int)(player->pos_y - vector_x * wall_dist)][(int)(player->pos_x)] == '0')
        player->pos_y -= vector_x;
}

void move_a(t_player *player, t_map *map)
{
    double  vector_x;
    double  vector_y;
    double  wall_dist;

    wall_dist = 1.1;
    vector_x = player->dir_x * player->speed_move;
    vector_y = player->dir_y * player->speed_move;
    if (map->map[(int)(player->pos_y)][(int)(player->pos_x - vector_y * wall_dist)] == '0')
        player->pos_x -= vector_y;
    if (map->map[(int)(player->pos_y + vector_x * wall_dist)][(int)(player->pos_x)] == '0')
        player->pos_y += vector_x;
}