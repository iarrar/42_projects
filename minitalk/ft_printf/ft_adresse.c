/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adresse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:15:09 by iarrar            #+#    #+#             */
/*   Updated: 2023/04/26 18:18:08 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base_add(void *ptr, char *str)
{
	char	*dest;
	size_t	i;
	size_t	res;
	size_t	mod;

	i = 0;
	res = (size_t)ptr;
	dest = ft_calloc(sizeof (char), (size_base(res, ft_strlen(str)) + 1));
	while (res >= (size_t)ft_strlen(str))
	{
		mod = res % (ft_strlen(str));
		dest[i] = str[mod];
		res = res / (ft_strlen(str));
		i++;
	}
	dest[i] = str[res];
	res = i;
	while (i > 0)
	{
		ft_putchar_fd(dest[i], 1);
		i--;
	}
	ft_putchar_fd(dest[0], 1);
	free(dest);
	return ((int)res + 1);
}

int	ft_adresse(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	i = ft_base_add(ptr, "0123456789abcdef");
	return (i + 2);
}
