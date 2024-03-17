#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>

typedef struct s_map
{
	size_t	size;
	int		*constraints;
	int		*buildings;
}	t_map;

typedef struct s_int_list
{
	struct s_int_list	*next;
	int					num;
}	t_int_list;

// Int list
int			int_list_add(t_int_list **list, int num);
void		int_list_destroy(t_int_list *list);
size_t		int_list_len(t_int_list *list);
t_int_list	*int_list_last(t_int_list *list);
t_int_list	*int_list_from_str(char *s);
int			*int_list_to_arr(t_int_list *list);
int			*int_str_to_arr(char *s);

// Map
t_map		*map_create(size_t size);
void		map_destroy(t_map *map);
int			map_set_constraints(t_map *map, int *constraints);
int			map_set_buildings(t_map *map, int *buildings);
int			map_get_at(t_map *map, size_t row, size_t col);
void		map_set_at(t_map *map, size_t row, size_t col, int value);

// Map visible
int			map_visible_top(t_map *map, size_t col);
int			map_visible_bottom(t_map *map, size_t col);
int			map_visible_left(t_map *map, size_t row);
int			map_visible_right(t_map *map, size_t row);

// Map print
void		map_print_buildings(t_map *map);
void		map_print_constraints(t_map *map);
void		map_print_constraints_long(t_map *map);
// Utils
size_t		int_arr_len(int *arr);
char		*stdin_to_str(void);

#endif