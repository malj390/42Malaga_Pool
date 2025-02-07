#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet()
{
	int	i;

	i = 'a';
	while(i <= 'z')
	{
		if (i % 2 == 0)
		{
			putchar(i - 32);
		}
		else
		{
			putchar(i);
		}
		i++;
	}
}

int main(void)
{
	ft_print_alphabet();
}
