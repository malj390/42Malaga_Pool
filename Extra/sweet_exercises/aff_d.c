#include <unistd.h>

void	aff_d(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	aff_d('d');
	return (0);
}
