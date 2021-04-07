/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:40:35 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/08 00:55:59 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int multiple;

	multiple = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power)
	{
		multiple *= nb;
		power --;
	}
	return (multiple);
}
