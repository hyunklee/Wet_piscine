/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:22:54 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/07 23:24:05 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int multiple;

	multiple = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	
	while (nb)
	{
		multiple *= nb;
		nb--;
	}
	return (multiple);
}
