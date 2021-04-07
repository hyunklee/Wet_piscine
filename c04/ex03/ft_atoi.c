/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 23:58:44 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/07 18:20:32 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char *no_space(char *str)
{
	while (*str < 33)
		*str++;
	return (str);
}

char *decide_sign(int *count, char *str)
{
	int cnt;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cnt++;
		*str++;
	}
	*count = cnt;
	return (str);
}

int	ft_atoi(char *str)
{
	int count;
	int nbr;

	nbr = 0;
	str = no_space(str);
	if (!(*str == '-' || *str == '+' ||( *str >= '0' && *str <= '9')))
		return (nbr);
	else if (*str >= '0' && *str <= '9')
	{	while (*str >= '0' && *str <= '9')
		{
			nbr += *str - '0';
			nbr *= 10;
			(*str)++;
		}
		return (nbr / 10);
	}
	else if (*str == '-' || *str == '+')
		str = decide_sign(&count, str);
	while (*str >= '0' && *str <= '9')
	{
		nbr += *str - '0';
		nbr *= 10;
		*str++;
	}
	nbr = count % 2 == 1 ? nbr * -1 : nbr;
	return (nbr / 10);
}

void	main(void)
{
	int a = ft_atoi(" ----+120521");
	printf("%d\n",a);
}
