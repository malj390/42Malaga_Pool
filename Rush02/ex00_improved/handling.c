
#include "FUNCTIONS_H"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void ft_putnbr(int	nbr)
{
	long	n;

   	n = nbr;
	if (n < 0)
	{
		n = -n;
		ft_putstr("-");
	}

	if ( n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if ( n < 10)
	{
		ft_putchar(n + '0');
	}
}

int count_char(char *str, char target) {
    int count = 0;
    
    while (*str) 
    {
        if (*str == target) {
            count++;
        }
        str++;
    }

    return (count + 1);
}

int	count_lines(char *str)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			counter++;
		i++;
	}
	return (i);
}

void remove_spaces(char *str) {
    int i;
    int j;

	i = 0;
	j = 0;
    while (str[i] != '\0') 
    {
        if (str[i] != ' ') 
        {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    
    str[j] = '\0';
}

int	count_text(char *str)
{
	int	i;

	i = 0;
	while( ' ' <= str[i] && str[i] <= '~')
	{
		i++;
	}
	return(i);
}