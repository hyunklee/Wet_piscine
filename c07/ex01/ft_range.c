/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:03:48 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/10 17:52:59 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *result;
	int i;

	i = 0;
	if (max - min <= 0)
	{
		return (0);
	}
	result = (int *)malloc(sizeof(int) * (max - min));
	if (!result)
		return (0);
	while (min < max)
	{
		result[i] = min;
		min++;
		i++;
	}	
	return (result);
}
