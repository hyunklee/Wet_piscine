/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:49:57 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/11 02:00:16 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert_base.c"
#include <stdio.h>
#include <stdlib.h>

char	*base_change(long long nbr, long long  base_nbr, char *base_to, char *ret)
{
	int mod;

	if (nbr == 0)
		return (ret + 1);
	mod = nbr % base_nbr;
	ret = base_change((nbr / base_nbr), base_nbr, base_to, ret);
	*ret = base_to[mod];
	return (ret + 1);
}
char	*make_zero(char *ret, char *base_to)
{
	ret = (char *)malloc(sizeof(char) * 2);
	ret[0] = base_to[0];
	ret[1] = 0;
	return (ret);
}
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long  nbr_ten;
	long long  base_nbr;
	char *ret;
	char *temp;

	if (!(base_check(base_from)))
		return (0);
	nbr_ten = ft_atoi_base(nbr,base_from);
	base_nbr = base_check(base_to);
	if (!(base_nbr))
		return (0);
	if (nbr_ten == 0)
		return (make_zero(ret, base_to));
	ret = (char *)malloc(sizeof(char) * 34);
	temp = ret;
	if (nbr_ten < 0)
	{
		*ret = '-';
		nbr_ten *= -1;
	}
	ret = base_change(nbr_ten, base_nbr, base_to, ret);
	*ret = 0;
	return (temp);
}
