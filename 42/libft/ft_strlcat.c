size_t		ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t  i;
	size_t  j;
	size_t  size_dst;
	int     len;

	i = 0;
	j = 0;
	len = 0;
	while (src[len])
		len++;
	while (dst[i] && i < size)
		i++;
	size_dst = i;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (size_dst + len);
}
