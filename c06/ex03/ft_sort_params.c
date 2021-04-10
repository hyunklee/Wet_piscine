/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 05:54:36 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/10 16:17:31 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	strcmp(char *dest, char *src)
{
	int i;
	i = 0;
	
	while (dest[i] != 0 && src[i] != 0)
	{
		if (dest[i] != src[i])
			break;
		i++;
	}
	return (dest[i] - src[i]);
}

void	arr_swap(char **dest, char **src)
{
	char *temp;

	temp = *dest;
	*dest = *src;
	*src = temp;
	return ;	
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
int	main(int argc, char *argv[])
{

	int i;
	int j;
	
	j = 0;
	i = 1;
	while (j < argc - 1)
	{	
		while (i < argc - j - 1)
		{
			if (strcmp(argv[i],argv[i + 1]) < 0)
				arr_swap(&argv[i], &argv[i + 1]);
			i++;
		}
		i = 1;
		j++;
	}
	i = 1;
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
			
