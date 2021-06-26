/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:24:37 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/26 15:00:07 by jonghpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(s);
	if (!s || !(ret = (char *)malloc(len + 1)))
		return (NULL);
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}
