/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:04:00 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/07 23:04:12 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_sign;

int	base_check(char *base)
{
	int i;
	int j;

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
int	str_in_base(char c, char* base)
{
	
	int i;
	
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
int	count_str(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != 0)
	{
		if(c == base[i])
			return (i);
		i++;
	}

}
int	base_to_ten(char *str, char *base, int base_nbr)
{
	int sum;
	int i;
	
	i = 0;
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

int	ft_atoi_base(char *str, char *base)
{
	int base_nbr;
	int sum;

	sum = 0;
	base_nbr = base_check(base);
	g_sign = 1;
	if (!(base_nbr))
		return (0);
	while (*str >= 9 && *str <= 13 || *str == 32)
		*str++;
	while (*str != 0)
	{
		if (!(str_in_base(*str,base)))
			return (0);
		else if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				g_sign *= -1;
		}
		else if (str_in_base(*str,base))
			return ((base_to_ten(str,base,base_nbr) * g_sign));
		*str++;
	}
} 	
