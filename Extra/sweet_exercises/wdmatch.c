// ./wdmatch.out "faya" "fhjgkfjgkfjlajkhfldjhblfhykjvdnlvka"

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long nb = n;
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

void	wdmatch(char *str1, char *str2)
{
	int i = 0;
	int j = 0;

	
	while (str1[i] != '\0')
	{
		while (str2[j] != '\0' && str2[j] != str1[i])
			j++;
		
		if (str2[j] == '\0')
			return;
		i++; 
		j++;
	}
	ft_putstr(str1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
			ft_putstr("Less than 1 argument was taken, please provide one.\n");
	else
	{
		wdmatch(argv[1], argv[2]);
		putchar('\n');
	}	
	return (0);
}
