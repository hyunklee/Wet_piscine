/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:58:46 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/14 22:22:45 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.>
#include "ft_stock_str.h"

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char			*ft_strdup(char *str)
{
	int		i;
	int		size;
	char	*ret;

	i = 0;
	size = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	while (str[i] != 0)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int		i;
	t_stock_str 	*temp;
	t_stock_str	*ret;

	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!ret)
		return (0);
	i = 0;
	temp = ret;
	while (i < ac)
	{
		ret->size = ft_strlen(av[i]);
		ret->str = av[i];
		ret->copy = ft_strdup(av[i]);
		i++;
		ret++;
	}
	ret->str = 0;
	return (temp);
}
