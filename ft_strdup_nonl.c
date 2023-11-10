/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_nonl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/15 13:49:54 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strdup_nonl(const char *s)
{
	size_t	slen;
	char	*result;

	slen = ft_strlen(s);
	result = (char *)ft_calloc(sizeof(char), slen);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, slen);
	return (result);
}
