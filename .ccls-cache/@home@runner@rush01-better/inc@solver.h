#ifndef SOLVER_H
# define SOLVER_H

# include <stdbool.h>

# include "common.h"

int		solve_map(t_map *map);

int		count_visible_top(t_map *map, size_t col, int *first_index);
int		count_visible_bottom(t_map *map, size_t col, int *first_index);
int		count_visible_left(t_map *map, size_t row, int *first_index);
int		count_visible_right(t_map *map, size_t row, int *first_index);

bool	is_unique_in_col(t_map *map, size_t row, size_t col, int value);
bool	constraint_top_ok(t_map *map, size_t col);
bool	constraint_bottom_ok(t_map *map, size_t col);
bool	constraint_left_ok(t_map *map, size_t row);
bool	constraint_right_ok(t_map *map, size_t row);

#endif