/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:01:35 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/10 17:03:27 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}


char	*ft_strdup(char *src)
{
	int size;
	char *result;
	int i;
	
	i = 0;
	size = ft_strlen(src);
	result = (char *)malloc(sizeof(char) * (size + 1));
	while(i < size)
	{
		result[i] = src[i];
		i++;
	}
	result[size] = 0;
	return (result);
}
