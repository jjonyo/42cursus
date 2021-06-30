/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:30:05 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/28 18:01:14 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strrchr(set, s1[i]))
		i++;
	j = ft_strlen(s1 + i);
	while (j && ft_strrchr(set, s1[i + j]))
		j--;
	return (ft_substr(s1 + i, 0, j + 1));
}
