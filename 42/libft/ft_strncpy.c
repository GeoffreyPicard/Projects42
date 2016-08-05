char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
