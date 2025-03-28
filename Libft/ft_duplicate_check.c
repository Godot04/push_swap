/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:39:26 by opopov            #+#    #+#             */
/*   Updated: 2025/03/27 10:36:38 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_duplicate_check(char **str)
{
	int i;
	int j;
	long num_i;
	long num_j;

	if (*str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		num_i = ft_atol(str[i]);
		j = i + 1;
		while (str[j])
		{
			num_j = ft_atol(str[j]);
			if (!ft_strcmp(str[i], str[j]))
				return (0);
			if (num_i == num_j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
