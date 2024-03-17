#include "common.h"
#include "solver.h"

#include <stdbool.h>
#include <stdlib.h>

bool is_unique_in_col(t_map *map, size_t row, size_t col, int value)
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

bool constraint_top_ok(t_map *map, size_t col)
{
	int	visible;
	int	first_index;
	int	min_constraint;
	int	max_constraint;

	visible = count_visible_top(map, col, &first_index);
	max_constraint = visible + first_index;
	if (first_index == 0)
		min_constraint = visible;
	else
		min_constraint = visible + 1;
	return (map->constraints[col] >= min_constraint
		&& map->constraints[col] <= max_constraint);	
}

bool constraint_bottom_ok(t_map *map, size_t col)
{
	int	visible;
	int	first_index;
	int	min_constraint;
	int	max_constraint;

	visible = count_visible_bottom(map, col, &first_index);
	max_constraint = visible + first_index;
	if (first_index == 0)
		min_constraint = visible;
	else
		min_constraint = visible + 1;
	return (map->constraints[map->size + col] >= min_constraint
		&& map->constraints[map->size + col] <= max_constraint);	
}

bool constraint_left_ok(t_map *map, size_t row)
{
	int	visible;
	int	first_index;
	int	min_constraint;
	int	max_constraint;

	visible = count_visible_left(map, row, &first_index);
	max_constraint = visible + first_index;
	if (first_index == 0)
		min_constraint = visible;
	else
		min_constraint = visible + 1;
	return (map->constraints[2 * map->size + row] >= min_constraint
		&& map->constraints[2 * map->size + row] <= max_constraint);	
}

bool constraint_right_ok(t_map *map, size_t row)
{
	int	visible;
	int	first_index;
	int	min_constraint;
	int	max_constraint;

	visible = count_visible_right(map, row, &first_index);
	max_constraint = visible + first_index;
	if (first_index == 0)
		min_constraint = visible;
	else
		min_constraint = visible + 1;
	return (map->constraints[3 * map->size + row] >= min_constraint
		&& map->constraints[3 * map->size + row] <= max_constraint);	
}
