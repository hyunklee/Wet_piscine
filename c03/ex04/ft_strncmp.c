int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int size;
	int i;

	i = 0;
	if (n == 0)
		return (0);
	size = ft_strlen(s1) <= ft_strlen(s2) ? ft_strlen(s1) : ft_strlen(s2);
	if (size <= n)
		n = size;
	while (i < n)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}
