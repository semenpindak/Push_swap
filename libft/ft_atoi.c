/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:44:07 by calpha            #+#    #+#             */
/*   Updated: 2020/03/30 23:21:47 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	rezult;
	long long			sign;

	rezult = 0;
	sign = 1;
	while (*str == '\a' || *str == '\b' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rezult = rezult * 10 + (*str - '0');
		str++;
	}
	if (rezult > 9223372036854775807 && sign == 1)
		rezult = -1;
	if (rezult > 9223372036854775807 && sign == -1)
		rezult = 0;
	return ((int)(sign * rezult));
}
