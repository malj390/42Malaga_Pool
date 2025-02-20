// ./wdmatch "faya" "fhjgkfjgkfjlajkhfldjhblfhykjvdnlvka"

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

int	main(void)
{

	return (0);
}
