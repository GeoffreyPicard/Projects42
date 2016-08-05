#include <stdio.h>
#include <string.h>
	

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t i;
}


int	main(void)
{
	char b[] = "hello";

	printf("%s\n", ft_bzero(b, 4));
	printf("%s\n", bzero(b, 4));
	return (0);
}
