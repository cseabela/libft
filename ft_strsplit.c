/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 09:30:31 by cseabela          #+#    #+#             */
/*   Updated: 2018/06/19 09:30:37 by cseabela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**strmagic;
	int		i;
	int		i2;
	int		i3;

	if (!s || !(strmagic = (char **)malloc(sizeof(*strmagic)
					* (ft_wordcount(s, c) + 1))))
		return (0);
	i = -1;
	i2 = 0;
	while (++i < ft_wordcount(s, c))
	{
		i3 = 0;
		if (!(strmagic[i] = ft_strnew(ft_wordlen(&s[i2], c) + 1)))
			strmagic[i] = NULL;
		while (s[i2] == c)
			i2++;
		while (s[i2] != c && s[i2])
			strmagic[i][i3++] = s[i2++];
		strmagic[i][i3] = '\0';
	}
	strmagic[i] = 0;
	return (strmagic);
}
