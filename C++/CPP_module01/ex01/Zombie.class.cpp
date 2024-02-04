/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:50:24 by imad              #+#    #+#             */
/*   Updated: 2024/01/29 17:59:46 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"


void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::attribut_name(std::string name)
{
	this->name = name;
	return;
}

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " has been killed" << std::endl;
	return ;
}
