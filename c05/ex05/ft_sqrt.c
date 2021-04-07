/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 00:59:08 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/08 01:19:40 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long i;
	long long long_nb;

	long_nb = (long long)nb;
	i = 1;
	while (i <= 46341)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);

}
