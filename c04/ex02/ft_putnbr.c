/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 23:32:57 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/05 23:58:27 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char g_nbr[11];

void	ft_check_ten(int nb,int *i)
{
	int nbr;

	if ( nb == 0)
		return ;
	g_nbr[*i] = nb % 10;
	write(1, &nbr, 1);
	nb /= 10;
	*i += 1;
	ft_check_ten(nb, i);

}
void	ft_putnbr(int nb)
{
	int i;
	
	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	ft_check_ten(nb,&i);
	i--;
	while (i >= 0)
	{
		g_nbr[i] += '0';
		write(1, &g_nbr[i], 1);
		i--;
	}		
}
int	main(void)
{
	ft_putnbr(200030000);
}
