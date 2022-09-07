/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:12:55 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/07 18:33:46 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	stopped_atoi(int sign, int result, char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (sign * result);
	while (str[i])
	{
		if (str[i] != ' ')
		{
			printf("Error\nOnly numbers are allowed for C and R\n");
			exit(1);
		}
		i++;
	}
	return (sign * result);
}

int	ft_custom_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (stopped_atoi(sign, result, &str[i]));
		else
			result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (sign * result);
		else
			result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}
