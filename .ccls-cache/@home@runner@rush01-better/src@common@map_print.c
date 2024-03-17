#include <stdio.h>

#include "common.h"

void map_print_buildings(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size * map->size)
	{
		if (i > 0 && i % map->size == 0)
			printf("\n");
		printf("%3d", map->buildings[i]);
		i++;
	}
	printf("\n");
}

void map_print_constraints(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size * 4)
	{
		if (i > 0)
			printf(" ");
		printf("%d", map->constraints[i]);
		i++;
	}
}

static void map_print_constraints_long_dim(char *title, int *constraints,
	size_t size)
{
	size_t	i;

	i = 0;
	printf("%s ", title);
	while (i < size)
	{
		printf("%3d", constraints[i]);
		i++;
	}
	printf("\n");
}

void map_print_constraints_long(t_map *map)
{
	map_print_constraints_long_dim("Top", map->constraints, map->size);
	map_print_constraints_long_dim("Bottom", map->constraints + map->size, map->size);
	map_print_constraints_long_dim("Left", map->constraints + 2 * map->size, map->size);
	map_print_constraints_long_dim("Right", map->constraints + 3 * map->size, map->size);
}