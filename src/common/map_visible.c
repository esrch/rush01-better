#include "common.h"

int	map_visible_top(t_map *map, size_t col)
{
	size_t	i;
	int		max;
	int		count;
	int		value;

	max = 0;
	count = 0;
	i = 0;
	while (i < map->size)
	{
		value = map_get_at(map, i, col);
		if (value > max)
		{
			count++;
			max = value;
		}
		i++;
	}
	return (count);
}

int	map_visible_bottom(t_map *map, size_t col)
{
	size_t	i;
	int		max;
	int		count;
	int		value;

	max = 0;
	count = 0;
	i = map->size;
	while (i--)
	{
		value = map_get_at(map, i, col);
		if (value > max)
		{
			count++;
			max = value;
		}
	}
	return (count);
}

int	map_visible_left(t_map *map, size_t row)
{
	size_t	i;
	int		max;
	int		count;
	int		value;

	max = 0;
	count = 0;
	i = 0;
	while (i < map->size)
	{
		value = map_get_at(map, row, i);
		if (value > max)
		{
			count++;
			max = value;
		}
		i++;
	}
	return (count);
}

int	map_visible_right(t_map *map, size_t row)
{
	size_t	i;
	int		max;
	int		count;
	int		value;

	max = 0;
	count = 0;
	i = map->size;
	while (i--)
	{
		value = map_get_at(map, row, i);
		if (value > max)
		{
			count++;
			max = value;
		}
	}
	return (count);
}
