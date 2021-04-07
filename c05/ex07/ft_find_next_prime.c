/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 01:38:24 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/08 02:04:19 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb == 1 || nb == 0)
		return (0);
	while (i <= 46341)
	{
		if (nb != i)
			if (nb % i == 0)
				return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int i;

	i = 0;
	while (1)
	{
		if (ft_is_prime(nb + i))
			return (nb + i);
		i++;
	}
}
