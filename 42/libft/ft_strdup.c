#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int	i;
	char	*dest;

	i = 0;
	while (s1[i])
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
