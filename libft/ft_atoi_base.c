/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:34:08 by calpha            #+#    #+#             */
/*   Updated: 2020/03/25 13:50:55 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(int nb, int power)
{
	int i;
	int pow;

	i = 1;
	pow = 1;
	if (power >= 0)
	{
		while (i++ <= power)
			pow = pow * nb;
		return (pow);
	}
	else
		return (0);
}

static int	position(const char *str, const char *number)
{
	int i;

	i = 0;
	while (*number != '\0')
	{
		if (*number == *str)
			return (i);
		i++;
		number++;
	}
	return (-1);
}

static int	cast_int(char *str, int i, int sign, int int_base)
{
	unsigned long long	int_nbr;
	char				*number;

	int_nbr = 0;
	number = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (str[i] != '\0')
	{
		if (int_base == 10)
			int_nbr = int_nbr * 10 + (str[i] - '0');
		if (int_base != 10)
			int_nbr += (position(&str[i], number)) *
			(power(int_base, (ft_strlen(str) - 1) - i));
		i++;
	}
	if (int_nbr > 9223372036854775807 && sign == 1)
		int_nbr = -1;
	if (int_nbr > 9223372036854775807 && sign == -1)
		int_nbr = 0;
	return ((int)(sign * int_nbr));
}

int			ft_atoi_base(char *str, char *base)
{
	int			int_base;
	size_t		k;
	long long	sign;

	int_base = 0;
	k = 0;
	sign = 1;
	while (*base != '\0')
		int_base = int_base * 10 + (*base++ - '0');
	if (int_base < 2 || int_base > 36)
		return (0);
	while (str[k] == '\a' || str[k] == '\b' || str[k] == '\t' || str[k] == '\n'
		|| str[k] == '\v' || str[k] == '\f' || str[k] == '\r' || str[k] == ' ')
		k++;
	if (str[k] == '-' || str[k] == '+')
	{
		if (str[k] == '-')
			sign = -1;
		k++;
	}
	return (cast_int(str, k, sign, int_base));
}
