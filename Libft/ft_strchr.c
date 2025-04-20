/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:45:05 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 22:04:23 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	char_to_find;

	char_to_find = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == char_to_find)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == char_to_find)
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}
