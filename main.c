/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:08:13 by asenel            #+#    #+#             */
/*   Updated: 2023/12/16 20:17:23 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_correct_input_av(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0 || ft_str_only_spaces(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (size == 3)
		little_sort(stack_a);
	else if (size > 3 && !is_sorted(*stack_a))
		lazy_sort(stack_a, stack_b);
}

char	**process_input(int ac, char **av, int *split_ac)
{
	char	delimiter;
	char	**split_data;

	if (ac < 2)
		error(NULL);
	if (!is_correct_input_av(av))
		error(NULL);
	delimiter = ' ';
	split_data = split_av(av, delimiter);
	if (!split_data)
		error(NULL);
	*split_ac = 0;
	while (split_data[*split_ac] != NULL)
		(*split_ac)++;
	if (!is_correct_input(split_data))
		error(NULL);
	return (split_data);
}

int	main(int ac, char **av)
{
	int		split_ac;
	char	**split_data;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	split_data = process_input(ac, av, &split_ac);
	stack_a = fill_stack(split_ac, split_data);
	stack_b = NULL;
	size = get_stack_size(stack_a);
	index_assign(stack_a, size);
	push_swap(&stack_a, &stack_b, size);
	stack_free(&stack_a);
	stack_free(&stack_b);
	free_data(split_data, split_ac);
	return (0);
}
