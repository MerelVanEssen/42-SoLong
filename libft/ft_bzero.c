/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:28:41 by mvan-ess          #+#    #+#             */
/*   Updated: 2023/10/03 08:28:43 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	if (!s)
		return ;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

// int main(void)
// {
// 	char	pnt[] = "Hello World";

// 	printf("before: %s\n", pnt);
// 	ft_bzero(pnt + 2, 10);
// 	//bzero(pnt + 2, 7);
// 	printf("after: %c", pnt[6]);
// 	return (0);
// }
