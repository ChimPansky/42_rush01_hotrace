/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsizet_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/15 14:26:34 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_putsizet_fd(size_t n, int fd)
{
	long	nr;

	if (fd < 0)
		return ;
	nr = (long) n;
	if (nr >= 10)
	{
		ft_putsizet_fd(nr / 10, fd);
		ft_putsizet_fd(nr % 10, fd);
	}
	if (nr < 10)
		ft_putchar_fd('0' + nr, fd);
}
