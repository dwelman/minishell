/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrwide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 08:48:12 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/20 10:39:56 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrwide(wchar_t *str)
{
	while (*str)
	{
		ft_putchar((char)*str);
		str++;
	}
}
