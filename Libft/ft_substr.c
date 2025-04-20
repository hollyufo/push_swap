/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:55:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/10 23:37:52 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	sub_len;
	char	*substr;

	if (!s)
	{
		return ((char *)ft_calloc(1, sizeof(char)));
	}
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		return ((char *)ft_calloc(1, sizeof(char)));
	}
	if (str_len - start < len)
		sub_len = str_len - start;
	else
		sub_len = len;
	substr = (char *)ft_calloc(sub_len + 1, sizeof(char));
	if (!substr)
	{
		return (NULL);
	}
	ft_strlcpy(substr, s + start, sub_len + 1);
	return (substr);
}
