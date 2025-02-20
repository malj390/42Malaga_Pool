// ./interval_space "Coconut"
// C   o   c    o    n   u    t\n
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

int	wordlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

void	interval_space(char *str)
{
	int	i;
	int len;
	
	len = wordlen(str) - 1;
	i = 0;
	while (i < len)
	{
		putchar(str[i]);
		ft_putstr("   ");
		i++;
	}
	putchar(str[i]);
	ft_putstr("\n");
}

int	main(void)
{
	char *str = "Coconut";
	interval_space(str);
	return (0);
}
