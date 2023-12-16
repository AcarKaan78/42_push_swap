/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:59:05 by asenel            #+#    #+#             */
/*   Updated: 2023/12/16 19:32:48 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_words(char **av, char c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (av[i])
	{
		total += ft_count_words(av[i], c);
		i++;
	}
	return (total);
}

static char	**allocate_data(char **av, char c)
{
	char	**data;
	int		total;

	total = total_words(av, c);
	data = (char **)malloc(sizeof(char *) * (total + 1));
	return (data);
}

void	free_data(char **data, int word)
{
	while (word > 0)
		free(data[--word]);
	free (data);
}

static void	add_words(char **data, char **temp, int *word)
{
	int	j;

	j = 0;
	while (temp[j])
	{
		data[*word] = temp[j];
		(*word)++;
		j++;
	}
}

char	**split_av(char **av, char c)
{
	char	**data;
	char	**temp;
	int		i;
	int		word;

	data = allocate_data(av, c);
	if (!data)
		return (NULL);
	i = 0;
	word = 0;
	while (av[i])
	{
		temp = ft_split(av[i], c);
		if (!temp)
		{
			free_data(data, word);
			return (NULL);
		}
		add_words(data, temp, &word);
		free(temp);
		i++;
	}
	data[word] = NULL;
	return (data);
}
