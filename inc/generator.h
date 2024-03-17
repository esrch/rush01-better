#ifndef GENERATOR_H
# define GENERATOR_H

#include <stdbool.h>
#include <stdlib.h>

#include "common.h"

typedef struct s_input
{
	bool	is_valid;
	size_t	size;
	bool	print_full;
}	t_input;

int	generate_map(t_map *map);

#endif