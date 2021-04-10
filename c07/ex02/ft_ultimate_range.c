/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:27:10 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/11 02:01:36 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	
	int *temp;
	int i;

	i = 0;
	if ((long long)max - min <= 0)
		return (0);
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (!(*range))
		return (-1);
	temp = *range;
	while ( min + i < max)
	{
		temp[i] = min + i;
		i++;
	}
	return (max - min);
}

int	main(void)
{
	int **range;
	range = (int **)malloc(sizeof(int *));

	printf("%d",ft_ultimate_range(range, 32, 35));
}
