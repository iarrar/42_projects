/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:01:54 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 18:01:56 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"
//typedef void	(*function_ptr)(void);
Harl::Harl()
{

}

Harl::~Harl()
{

}

void    Harl::debug(void)
{
	std::cout << "recherche de petits insectes " << std::endl;
	return ;
}
void    Harl::info(void)
{
	std::cout << "Je sais pas ce que j'ai..." << std::endl;
	return ;
}
void    Harl::warning(void)
{
	std::cout << "Wallah lradim je vais faire une dinguerie" << std::endl;
	return ;
}
void    Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}


void	Harl::complain(std::string level)
{
	void (Harl::*function_ptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	complain_tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	while (i < 4)
	{
		if (complain_tab[i] == level)
		{
			(this->*function_ptr[i])();
			return ;
		}
		i++;
		if (i == 4)
			std::cout << "Please enter DEBUG INFO WARNING or ERROR" << std::endl;
	}

}