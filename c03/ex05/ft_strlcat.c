#include <stdio.h>
int	ft_strlen(char *s)
{
	int i;

	i = 0;
	
	while (s[i])
		i++;
	return (i);
}
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{

	int dest_size;
	int i;
	int j;
	
	dest_size = ft_strlen(dest);
	i = dest_size;
	j = 0;
	if (size <= dest_size)
	{
		if (size == dest_size)
			dest[dest_size - 1] = 0;
		return (size + ft_strlen(src));
	}
	size = size - dest_size;
	while (j < size - 1)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[dest_size + size] = 0;
	return ( dest_size + ft_strlen(src));
}
