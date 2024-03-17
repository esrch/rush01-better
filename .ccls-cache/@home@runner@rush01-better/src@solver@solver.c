#include <stdbool.h>

#include "common.h"
#include "solver.h"

static bool is_valid(t_map *map, size_t row, size_t col, int value)
{
	return (
		is_unique_in_col(map, row, col, value)
		&& constraint_top_ok(map, col)
		&& constraint_bottom_ok(map, col)
		&& constraint_left_ok(map, row)
		&& constraint_right_ok(map, row));
}

static int solve_map_exec(t_map *map, size_t index)
{
	size_t	row;
	int		value;
	size_t	i;

	if (index == map->size * map->size)
		return (0);
	row = index % map->size;
	value = map->size - index / map->size;
	i = 0;
	while (i < map->size)
	{
		if (map_get_at(map, row, i) != 0)
		{
			i++;
			continue ;
		}
		map_set_at(map, row, i, value);
		if (is_valid(map, row, i, value) && solve_map_exec(map, index + 1) == 0)
			return (0);
		map_set_at(map, row, i, 0);
		i++;
	}
	return (-1);
}

int solve_map(t_map *map)
{
	return (solve_map_exec(map, 0));
}