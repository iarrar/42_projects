/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:02:21 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 18:02:22 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H
#include <string>
#include <iostream>


typedef void (*function_ptr)(void);

class Harl
{
	public:
		Harl();
		~Harl();
		//int		check_input(char *argv);
		void    complain(std::string level);
	private:
		void    debug(void);
		void    info(void);
		void	warning(void);
		void    error(void);
};

#endif