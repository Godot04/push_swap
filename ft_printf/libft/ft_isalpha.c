/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:18:27 by opopov            #+#    #+#             */
/*   Updated: 2024/11/12 14:18:32 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int argument)
{
	if ((argument >= 65 && argument <= 90)
		|| (argument >= 97 && argument <= 122))
	{
		return (1024);
	}
	else
	{
		return (0);
	}
}
