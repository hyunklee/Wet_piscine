/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:52:48 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/10 14:57:50 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int i;

	i = argc - 1;

	while (i >= 1)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
