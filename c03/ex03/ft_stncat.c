char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;
	int j;
	int src_size;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	src_size = j;
	j = 0;
	if (src_size < nb)
		nb = src_size;
	while (nb)
	{
		dest[i] = src[j];
		nb--;
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}
