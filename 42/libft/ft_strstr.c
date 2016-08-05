char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (big[k])
	{
		i = k;
		j = 0;
		while(big[i] == little[j])
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
