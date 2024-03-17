#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "common.h"
#include "generator.h"

static int handle_error(char *msg)
{
	printf("%s\n", msg);
	return (1);
}

static t_input handle_input_error(char *msg)
{
	t_input	input;

	input.is_valid = false;
	printf("%s\n", msg);
	return (input);
}

static t_input parse_input(char **argv)
{
	t_input	input;
	int		int_size;

	input.is_valid = true;
	input.print_full = false;
	argv++;
	if (*argv && argv[0][0] == '-')
	{
		if (argv[0][1] == 'f')
			input.print_full = true;
		else
			return (handle_input_error("Invalid option"));
		argv++;
	}
	if (!*argv)
		return (handle_input_error("Usage: generator [-f] size"));
	int_size = atoi(*argv);
	if (int_size < 1)
		return (handle_input_error("Size must be larger than 0."));
	input.size = (size_t) int_size;
	argv++;
	if (*argv)
		return (handle_input_error("Too many arguments"));
	return (input);
}

int main(int argc, char **argv)
{
	t_input	input;
	t_map	*map;

	(void) argc;
	input = parse_input(argv);
	if (!input.is_valid)
		return (1);
	map = map_create(input.size);
	if (!map)
		return (handle_error("Error allocating map."));
	srand(time(NULL));
	if (generate_map(map) != 0)
	{
		map_destroy(map);
		return (handle_error("Error generating buildings."));
	}
	if (input.print_full)
	{
		map_print_buildings(map);
		printf("-----\n");
		map_print_constraints_long(map);
		printf("-----\n");
		map_print_constraints(map);
		printf("\n");
	}
	else
		map_print_constraints(map);
	map_destroy(map);
}