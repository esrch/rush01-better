#include <stdio.h>

#include "common.h"
#include "solver.h"

static int handle_error(char *msg)
{
	printf("%s\n", msg);
	return (1);
}

int main(int argc, char **argv)
{
	char	*constraints_str;
	int		*constraints;
	size_t	size;
	t_map	*map;

	if (argc == 1)
		constraints_str = stdin_to_str();
	else
		constraints_str = argv[1];
	constraints = int_str_to_arr(constraints_str);
	if (argc == 1)
		free(constraints_str);
	if (!constraints)
		return (handle_error("Error: Allocation error when generating constraints."));
	size = int_arr_len(constraints) / 4;
	if (int_arr_len(constraints) % 4 != 0)
		return (handle_error("Error: Invalid number of constraints."));
	map = map_create(size);
	if (!map)
	{
		free(constraints);
		return (handle_error("Error: Allocation error when creating map."));
	}
	if (map_set_constraints(map, constraints) != 0)
	{
		map_destroy(map);
		free(constraints);
		return (handle_error("Error: Invalid constraints"));
	}
	printf("Constraints:\n");
	map_print_constraints_long(map);
	printf("------\n");
	if (solve_map(map) != 0)
	{
		map_destroy(map);
		printf("No solution found.\n");
	}
	else
		map_print_buildings(map);
}