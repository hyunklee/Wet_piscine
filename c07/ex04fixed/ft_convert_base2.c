/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:13:25 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/14 20:01:52 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*base_change(long long digit, int t_num, char *base_to, char *ret);
int	count_str(char c, char *base);

int	base_check(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (base[0] == 0 || base[1] == 0)
		return (0);
	while (base[i])
	{
		if (base[i] >= 9 && base[i] <= 13)
			return (0);
		else if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (i);
}

int	str_in_base(char c, char *base)
{
	while (*base)
	{
		if (c == *base)
			return (1);
		*base++;
	}
	return (0);
}

int	base_to_digit(char *str, char *base, int digit)
{
	while (str_in_base(*str, base))
	{
		digit *= 10;
		digit += count_str(*str, base);
		str++;
	}
	return (digit);
}

int	count_str(char c, char *base)
{
	int i;

	i = 0;
	while (c != base[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int sign;
	int digit;

	digit = 0;
	sign = 1;
	while ((*str >= 9  && *str <= 13) || *str == 32)
		str++;
	while ((*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
		
	}
	if (!(str_in_base(*str, base)))
		return (digit);
	else
		digit = (sign * base_to_digit(str, base, digit));
}

int	malloc_size(int digit, int t_num)
{
	int size;

	if (!digit)
		return (1);
	size = 0;
	if (digit < 0)
		size++;
	while (digit)
	{
		digit /= t_num;
		size++;
	}
	return (size);
}

char	*base_change(long long digit, int t_num, char *base_to, char *ret)
{
	int mod;

	if (digit == 0)
		return (ret);
	mod = digit % t_num;
	ret = base_change((digit / t_num), t_num, base_to, ret);
	*ret = base_to[mod];
	return (ret + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int t_num;
	char *ret;
	char *temp;
	long long digit;

	if (!(base_check(base_from) && base_check(base_to)))
		return (0);
	t_num = base_check(base_to);
	digit = ft_atoi_base(nbr, base_from);
	ret = (char *)malloc(sizeof(char) * (malloc_size(digit, t_num) + 1));
	temp = ret;
	if (digit == 0)
	{
		ret[0] = base_to[0];
		ret++;
	}
	if (digit < 0)
	{
		ret[0] = '-';
		digit *= -1;
		ret++;
	}
	ret = base_change(digit, t_num, base_to, ret);
	*ret = 0;
	return (temp);
}
