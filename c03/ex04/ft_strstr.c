char	ft_strncmp(char *s1, char *s2, unsigned int n);
char	ft_strlen(char *s);
char	*ft_strstr(char *str, char *to_find)
{	
	int i;
	int size;
	int res;

	i = 0;
	if (to_find[0] == 0)
		return (&str[0]);
	if (ft_strlen(str) < ft_strlen(to_find))
		return (0);
	size = ft_strlen(to_find);
	while (str[i] != 0)
	{
		res = ft_strncmp(&str[i], to_find, size);
		if (res == 0)
			return &str[i];
		i++;
	}
	return (0);
}
