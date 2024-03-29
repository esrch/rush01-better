#include <stdlib.h>

#include "common.h"

static t_map *map_create_error(t_map *map, int *new_constraints)
{
	free(map);
	free(new_constraints);
	return (NULL);
}

t_map *map_create(size_t size)
{
	t_map	*map;

	if (size < 1)
		return (NULL);
	map = malloc(sizeof(*map));
	if (!map)
		return (NULL);
	map->constraints = calloc(size * 4 + 1, sizeof(int));
	map->buildings = calloc(size * size + 1, sizeof(int));
	if (!map->constraints || !map->buildings)
	{
		map_destroy(map);
		return (NULL);
	}
	return (map);
}

int map_set_constraints(t_map *map, int *constraints)
{
	size_t	len;

	if (!map || !constraints)
		return (-1);
	len = int_arr_len(constraints);
	if (len != map->size * 4)
		return (-1);
	free(map->constraints);
	map->constraints = constraints;
	return (0);
}

int map_set_buildings(t_map *map, int *buildings)
{
	size_t	len;

	if (!map || !buildings)
		return (-1);
	len = int_arr_len(buildings);
	if (len != map->size * map->size)
		return (-1);
	free(map->buildings);
	map->buildings = buildings;
	return (0);
}

void map_destroy(t_map *map)
{
	free(map->constraints);
	free(map->buildings);
	free(map);
}

int map_at(t_map *map, size_t row, size_t col)
{
	if (row < 1 || row >= map->size || col < 1 || col >= map->size)
		return (-1);
	return map->buildings[row * map->size + col];
}