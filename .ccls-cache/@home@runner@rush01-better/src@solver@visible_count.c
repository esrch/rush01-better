#include "common.h"
#include "solver.h"

int count_visible_top(t_map *map, size_t col, size_t *first_index)
{
	int		visible;
	int		max;
	size_t	_first_index;
	size_t	i;
	int		value;

	visible = 0;
	max = 0;
	_first_index = -1;
	i = 0;
	while (i < map->size)
	{
		value = map_get_at(map, i, col);
		if (value != 0 && _first_index == -1)
			_first_index = i;
		if (value > max)
		{
			max = value;
			visible++;
		}
		i++;
	}
	*first_index = _first_index;
	return (visible);
}

int count_visible_bottom(t_map *map, size_t col, size_t *first_index)
{
	int		visible;
	int		max;
	size_t	_first_index;
	size_t	i;
	int		value;

	visible = 0;
	max = 0;
	_first_index = -1;
	i = map->size;
	while (i-- > 0)
	{
		value = map_get_at(map, i, col);
		if (value != 0 && _first_index == -1)
			_first_index = map->size - i - 1;
		if (value > max)
		{
			max = value;
			visible++;
		}
		i++;
	}
	*first_index = _first_index;
	return (visible);
}

int count_visible_left(t_map *map, size_t row, size_t *first_index)
{
	int		visible;
	int		max;
	size_t	_first_index;
	size_t	i;
	int		value;

	visible = 0;
	max = 0;
	_first_index = -1;
	i = 0;
	while (i < map->size)
	{
		value = map_get_at(map, row, i);
		if (value != 0 && _first_index == -1)
			_first_index = i;
		if (value > max)
		{
			max = value;
			visible++;
		}
		i++;
	}
	*first_index = _first_index;
	return (visible);
}

int count_visible_right(t_map *map, size_t row, size_t *first_index)
{
	int		visible;
	int		max;
	size_t	_first_index;
	size_t	i;
	int		value;

	visible = 0;
	max = 0;
	_first_index = -1;
	i = map->size;
	while (i-- > 0)
	{
		value = map_get_at(map, row, i);
		if (value != 0 && _first_index == -1)
			_first_index = map->size - i - 1;
		if (value > max)
		{
			max = value;
			visible++;
		}
		i++;
	}
	*first_index = _first_index;
	return (visible);
}
