#include <stdio.h>

void	ft_plusplus(void);

int		main(void)
{
	ft_plusplus(); //1
	ft_plusplus(); //2
	ft_plusplus(); //3
	return (0);
}

void	ft_plusplus(void)
{
	static int i;

	i = i + 1;
	printf("%d\n", i);
}
