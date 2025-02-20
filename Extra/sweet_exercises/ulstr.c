#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long nb = n;  // Convert to long to avoid overflow
	if (nb < 0)
	{
		putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	putchar((nb % 10) + '0');
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
}

void	ulstr(char *str)
{
	int	i;
	int	dif;

	i = 0;
	dif = 'a' - 'A';
	while (str[i] != '\0')
	{
		if (str[i] <= 'z' && str[i] >= 'a' )
		{
			str[i] = str[i] - dif;
		}

		else if (str[i] <= 'Z' && str[i] >= 'A' )
		{
			str[i] = str[i] + dif;
			
		}
		i++;

	}
}

int	main(void)
{
	char str[] = "mAmAmAmAmAmA";
	
	ft_putstr("Input: ");
	ft_putstr(str);
	ulstr(str);
	ft_putstr("\nOutput: ");
	ft_putstr(str);
	return (0);
}