/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:04:00 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/11 01:20:44 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	g_sign;

long long	base_check(char *base)
{
	long long i;
	long long j;

	j = 1;
	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] >= 9 && base[i] <= 13 || base[i] == 32)
			return (0);
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (i);
}
long long	str_in_base(char c, char* base)
{
	
	long long i;
	
	i = 0;
	if (c == '-' || c == '+')
		return (1);
	while (base[i] != 0)
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}
long long	count_str(char c, char *base)
{
	long long i;

	i = 0;
	while (base[i] != 0)
	{
		if(c == base[i])
			return (i);
		i++;
	}

}
long long	base_to_ten(char *str, char *base, long long base_nbr, long long i)
{
	long long sum;
	
	sum = 0;
	while (str_in_base(str[i],base))
	{
		if (str[i] >= 9 && str[i] <= 13 || str[i] == ' ' || str[i] == '+' || str[i] == '-' )
			break;
		sum += count_str(str[i],base);
		sum *= base_nbr;
		i++;
	}
	return (sum/base_nbr);
}

long long	ft_atoi_base(char *str, char *base)
{
	long long base_nbr;
	long long sum;
	long long i;
	long long sign;

	i = 0;
	sum = 0;
	base_nbr = base_check(base);
	sign = 1;
	if (!(base_nbr))
		return (0);
	while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
		i++;
	while (str[i] != 0)
	{
		if (!(str_in_base(str[i],base)))
			return (0);
		else if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign *= -1;
		}
		else if (str_in_base(str[i],base))
			return ((base_to_ten(str,base,base_nbr,i) * sign));
		i++;
	}
}
