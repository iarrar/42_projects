/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:11:32 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/08 16:59:32 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.class.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	this->weapon = NULL;
	return ;
}

HumanB::~HumanB()
{

}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void		HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}