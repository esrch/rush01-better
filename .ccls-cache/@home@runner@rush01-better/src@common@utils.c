#include <stdlib.h>

#include "common.h"

size_t	int_arr_len(int *arr)
{
	size_t	len;

	len = 0;
	while (*arr)
	{
		len++;
		arr++;
	}
	return (len);
}