int	my_exp(int base, int n)
{
	int	i;
	int	result;

	i = 0;
	if (n == 0)
		return (1);
	result = 1;
	while (i < n)
	{
		result *= base;
		++i;
	}
	return (result);
}

#include <stdio.h>

int main(void)
{
	int a = my_exp(2, 3);
	printf("%d\n", a);
}