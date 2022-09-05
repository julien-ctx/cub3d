/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:26:27 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/28 02:08:22 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}

int	ft_isalpha_str(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[0] == '-')
		i = 1;
	while ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))
		i++;
	if (str[i])
		return (0);
	else
		return (1);
}
