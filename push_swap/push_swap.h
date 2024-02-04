/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:27:44 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/21 11:27:47 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_data
{
	int	*tab;
	int	*sort;
	int	size;
	int	bit_max;
}	t_data;

t_data	*ft_init_params(char **str, int size);
t_data	*ft_init_stack(int size);
char	**ft_init_oneparam(char *str);
int		min(int *tab, int size);
int		max(int *tab, int size);
int		index_max(int *tab, int size);
int		index_min(int *tab, int size);
void	ft_index_tab(t_data *stack);
void	ft_ciao(t_data *stack_a, t_data *stack_b, char **param);
void	ft_push_pb(t_data *stack_a, t_data *stack_b);
void	ft_push_pa(t_data *stack_a, t_data *stack_b);
void	ft_rotate(t_data *stack);
void	ft_swap(t_data *stack);
void	ft_reverse_rotate(t_data *stack);
void	print_stacks(t_data *stack_a, t_data *stack_b);
int		ft_check_string(char *str);
int		ft_check_input(char **str);
void	ft_radix(t_data *stack_a, t_data *stack_b);
void	ft_dry_stack(t_data *stack_a, t_data *stack_b);
int		ft_count_bits(int n);
int		ft_check_double(char **tab);
int		ft_check_allnum(char *str);
int		ft_is_sorted(int *tab, int size);
void	ft_tdu(t_data *stack_a);
void	ft_tud(t_data *stack_a);
void	ft_dut(t_data *stack_a);
void	ft_dtu(t_data *stack_a);
void	ft_utd(t_data *stack_a);
void	ft_sort_three(t_data *s, int zero, int one, int two);
int		ft_all_equal(int *tab, int size);
void	ft_sort_five(t_data *s_a, t_data *s_b);
void	ft_sort(t_data *s_a, t_data *s_b);
void	ft_five(t_data *s_a);
void	ft_sort_four(t_data *s_a, t_data *s_b);

#endif
