
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long nb = n;  
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int	count_alen(char *str)
{
	int	i;
	
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == 'a')
			return (i);
		i++;
	}
	return (i);
}

int	main(void)
{
	char	*str = "0123a5678";
	char	*str2 = "012346789";
	int	res;
	int	res2;

	res = count_alen(str);
	res2 = count_alen(str2);
	ft_putnbr(res);
	ft_putstr("\n");
	ft_putnbr(res2);
}