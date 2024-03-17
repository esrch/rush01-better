#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "generator.h"

static bool is_valid_col(t_map *map, size_t row, size_t col, int value)
{
	size_t	i;

	if (row == 0)
		return (true);
	i = 0;
	while (i < row)
	{
		if (map_get_at(map, i, col) == value)
			return (false);
		i++;
	}
	return (true);
}

static int generate_building(t_map *map, size_t index)
{
	size_t	row;
	int		value;
	size_t	base_col;
	size_t	i;

	if (index == map->size * map->size)
		return (0);
	row = index % map->size;
	value = index / map->size + 1;
	base_col = rand() % map->size;
	i = 0;
	while (i < map->size)
	{
		if (map_get_at(map, row, (base_col + i) % map->size) != 0)
		{
			i++;
			continue ;
		}
		map_set_at(map, row, (base_col + i) % map->size, value);
		if (is_valid_col(map, row, (base_col + i) % map->size, value)
			&& generate_building(map, index + 1) == 0)
			return (0);
		map_set_at(map, row, (base_col + i) % map->size, 0);
		i++;
	}
	return (-1);
}

static void generate_constraints_dim(t_map *map, int *constraints,
	int (*calc_visible)(t_map*, size_t))
{
	size_t	i;
	
	i = 0;
	while (i < map->size)
	{
		constraints[i] = calc_visible(map, i);
		i++;
	}
}

static void generate_constraints(t_map *map)
{
	generate_constraints_dim(map, map->constraints, map_visible_top);
	generate_constraints_dim(map, map->constraints + map->size, map_visible_bottom);
	generate_constraints_dim(map, map->constraints + 2 * map->size, map_visible_left);
	generate_constraints_dim(map, map->constraints + 3 * map->size, map_visible_right);
}

int generate_map(t_map *map)
{
	if (generate_building(map, 0) < 0)
		return (-1);
	generate_constraints(map);
	return (0);
}