/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:36:05 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/10 23:49:43 by hyunklee         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int i;
	
	i = 0;
	while (src[i] != 0)
	{
		*dest = src[i];
		dest++;
		i++;
	}
	return (dest);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	char *ret;
	char *temp;
	int size_strs;
	int i;

	if (size == 0)
	{
		ret = (char *)malloc(sizeof(char) * 1);
		*ret = 0;
		return (ret);
	}
	i = -1;
	size_strs = 0;
	while (++i < size)
		size_strs += ft_strlen(strs[i]);
	ret = (char *)malloc(sizeof(char) * (size_strs + (size - 1) * ft_strlen(sep) + 1));
	temp = ret;
	i = -1;
	while (++i < size)
	{
		ret = ft_strcat(ret,strs[i]);
		if ( i != size - 1)
			ret = ft_strcat(ret,sep);
	}
	*ret = 0;
	return (temp);
}
