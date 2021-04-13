/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:08:15 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/13 00:09:57 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_atoi(int nb)
{
	int mod;

	if (nb == 0)
		return ;
	mod = (nb % 10) + '0';
	ft_atoi(nb / 10);
	write (1, &mod, 1);
	return ;
}

int	ft_strlen2(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		write(1, par->str, par->size);
		write(1, "\n", 1);
		if (par->size == 0)
			write(1, "0", 1);
		else
			ft_atoi(par->size);
		write(1, "\n", 1);
		write(1, par->copy, ft_strlen2(par->copy));
		write(1, "\n", 1);
		par++;
	}
	return ;
}
