int	ft_atoi(const char *str)
{
	int i;
	int res;
	int negative;

	i = 0;
	res = 0;
	negative = 0;
	while (str[i] < 33 && str[i])
		i++;
	if (str[i] == '+' | str[i] == '-')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-res);
	return (res);
}
