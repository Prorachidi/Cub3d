/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:00:54 by murachid          #+#    #+#             */
/*   Updated: 2019/10/29 14:54:21 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*phrase;
	size_t			i;

	phrase = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*(phrase + i) = 0;
		i++;
	}
}
