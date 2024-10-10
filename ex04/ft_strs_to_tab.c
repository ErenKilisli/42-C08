/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikilisli <ikilisli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:19:31 by ikilisli          #+#    #+#             */
/*   Updated: 2024/08/22 14:16:46 by ikilisli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)

{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)

{
	char	*dest;
	int		length;

	length = 0;
	while (src[length] != '\0')
		length++;
	dest = (char *)malloc((length + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	length = 0;
	while (src[length] != '\0')
	{
		dest[length] = src[length];
		length++;
	}
	dest[length] = '\0';
	return (dest);
}

void	ft_free(t_stock_str *retrn, int i)

{
	int	j;

	j = 0;
	while (j < i)
	{
		free(retrn[j].copy);
		j++;
	}
	free(retrn);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)

{
	t_stock_str	*retrn;
	int			i;

	i = 0;
	retrn = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (retrn == NULL)
		return (NULL);
	while (i < ac)
	{
		retrn[i].size = ft_strlen(av[i]);
		retrn[i].str = av[i];
		retrn[i].copy = ft_strdup(av[i]);
		if (retrn[i].copy == NULL)
		{
			ft_free(retrn, i);
			return (NULL);
		}
		i++;
	}
	retrn[ac].str = NULL;
	return (retrn);
}
