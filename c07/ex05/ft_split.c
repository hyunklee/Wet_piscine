/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 02:05:09 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/11 03:51:15 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>




int	search_charset(char c, char *charset)
{
	while (charset[i] != 0)
	{
		if(c == charset[i])
			return (1);
		i++;
	}
	return (0);
}
int	guess_str(char *str, char *charset)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i] != 0)
	{
		if (!search_charset(str[i],charset))
		{	cnt++;
			while (!sarch_charset(str[i],charset))
				i++;
		}
		i++;
	}
	return (cnt);
}
int	cut_str(char *str, char *charset)
{
	int cnt;

	cnt = 0;
	while(*str != 0)
	{
		if(search_charset(c,charset))
		       return (cnt);	
		cnt++;
		str++;
	}
	return (cnt);
}


char	**ft_split(char *str, char *charset)
{
	char **ret;
	char *str_cp;
	int i;
	int j;
	
	j = 0;
	i = 0;
	str_cp = str;
	ret = (char **)malloc(sizeof(char *) * (guess_str(str,charset) + 1));

	while (i < guess_str(str,charset))
	{
		ret[i] = (char *)malloc(sizeof(char) * (cut_str(str_cp, charset) + 1));

		i++;
	}
	ret[i] = 0;
}


