/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:21:45 by opopov            #+#    #+#             */
/*   Updated: 2025/03/18 10:23:02 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spacecalc(const char *nptr, int a)
{
	while (nptr[a] == ' ' || nptr[a] == '\n'
		|| nptr[a] == '\t' || nptr[a] == '\v'
		|| nptr[a] == '\f' || nptr[a] == '\r')
	{
		a++;
	}
	return (a);
}

static int	ft_plusminus(const char *nptr, int *a, int min)
{
	if (nptr[*a] == '-' || nptr[*a] == '+')
	{
		if (nptr[*a] == '-')
		{
			min *= -1;
		}
		(*a)++;
	}
	return (min);
}

long long	ft_atol(const char *nptr)
{
	long long	res;
	int	a;
	int	min;

	res = 0;
	a = 0;
	min = 1;
	a = ft_spacecalc(nptr, a);
	min = ft_plusminus(nptr, &a, min);
	while (nptr[a] >= '0' && nptr[a] <= '9')
	{
		res = res * 10 + (nptr[a] - '0');
		a++;
	}
	return (res * min);
}
