char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (big[k] && i < len)
	{
		i = k;
		j = 0;
		while(big[i] == little[j] && i < len)
		{
			if (little[j + 1] == '\0')
				return (char *)(big + i - j);
			i++;
			j++;
		}
		k++;
	}
	return (NULL);
}
