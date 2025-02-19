#include <stdio.h>

int ft_strlen(char *str);

int	main(void)
{
	char *str = "123456789";
	int	result;
	
	result = ft_strlen(str);
	printf("Len of %s is %d", str, result);
	return (0);
}