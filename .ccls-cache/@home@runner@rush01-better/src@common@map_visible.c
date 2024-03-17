#include "common.h"

int	map_visible_top(t_map *map, size_t col)
{
	size_t	i;
	int		max;
	int		count;

	max = 0;
	count = 0;
	i = 0;
	while (i < map->size)
	{
		if (map_at(map, i, col) > max)
		{
			count++;
			max = map_at(map, i, col);
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

	max = 0;
	count = 0;
	i = map->size;
	while (i--)
	{
		if (map_at(map, i, col) > max)
		{
			count++;
			max = map_at(map, i, col);
		}
	}
	return (count);
}

int	map_visible_left(t_map *map, size_t row)
{
	size_t	i;
	int		max;
	int		count;

	max = 0;
	count = 0;
	i = 0;
	while (i < map->size)
	{
		if (map_at(map, row, i) > max)
		{
			count++;
			max = map_at(map, row, i);
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

	max = 0;
	count = 0;
	i = map->size;
	while (i--)
	{
		if (map_at(map, row, i) > max)
		{
			count++;
			max = map_at(map, row, i);
		}
	}
	return (count);
}
