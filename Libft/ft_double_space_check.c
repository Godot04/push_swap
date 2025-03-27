/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_space_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:19:35 by opopov            #+#    #+#             */
/*   Updated: 2025/03/26 18:27:59 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_double_space_check(char **str)
{
	int	i;
	int	j;
	int	space_count;

	i = 0;
	while (str[i][j] != '\0')
	{
		j = 0;
		space_count = 0;
		while (str[i][j])
		{
			if (str[i][j] == ' ')
			{
				space_count++;
				if (space_count > 1)
					return (0);
			}
			else
				space_count = 0;
			j++;
		}
		i++;
	}
	return (1);
}
