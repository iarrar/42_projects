/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:02:16 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 18:02:17 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void    Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "recherche de petits insectes " << std::endl;
	return ;
}

void    Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "Je sais pas ce que j'ai..." << std::endl;
	return ;
}

void    Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "Wallah lradim je vais faire une dinguerie" << std::endl;
	return ;
}

void    Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
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
			while (i < 4)
			{
				(this->*function_ptr[i])();
				i++;
			}
			return ;
		}
		i++;
	}
	std::cout << "Invalid level" << std::endl;
}