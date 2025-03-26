/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:39:26 by opopov            #+#    #+#             */
/*   Updated: 2025/03/18 14:06:54 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_duplicate_check(char **str)
{
	char *buff;
	int i;
	int j;

	if (*str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		buff = str[i];
		j = i + 1;
		while (str[j])
		{
			if (!ft_strncmp(buff, str[j], ft_strlen(str[j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
