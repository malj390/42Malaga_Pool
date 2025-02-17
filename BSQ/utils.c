
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "functions.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	count_char(char *str, char target)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == target)
		{
			count++;
		}
		str++;
	}
	return (count + 1);
}

int	count(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}