/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:07:51 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/30 22:19:41 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	if (*needle == '\0')
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (*haystack && len >= n_len)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, n_len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
