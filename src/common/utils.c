#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

char *stdin_to_str(void)
{
	char	*s;
	int		bytes;
	char	buf[4096];

	bytes = read(STDIN_FILENO, buf, 4095);
	if (buf[bytes - 1] == '\n')
		buf[bytes - 1] = '\0';
	else
		buf[bytes] = '\0';
	s = malloc(sizeof(*s) * (strlen(buf) + 1));
	if (!s)
		return (NULL);
	strcpy(s, buf);
	return (s);
}