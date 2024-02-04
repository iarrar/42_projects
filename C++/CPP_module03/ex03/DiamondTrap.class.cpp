/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:53:04 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/31 14:18:44 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << _Name << " DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_Name = name;
	this->_Hit_points = FragTrap::_Hit_points;
	this->_Attack_damage = FragTrap::_Attack_damage;
	this->_Energy_points = ScavTrap::_Energy_points;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
	this->_Name = src._Name;
	this->_Hit_points = src._Hit_points;
	this->_Attack_damage = src._Attack_damage;
	this->_Energy_points = src._Energy_points;
}

DiamondTrap::~DiamondTrap()
{

}
void    DiamondTrap::attack(const std::string & target)
{
	ScavTrap::attack(target);
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & src)
{
	this->_Name = src._Name;
	this->_Hit_points = src._Hit_points;
	this->_Attack_damage = src._Attack_damage;
	this->_Energy_points = src._Energy_points;
	return (*this);
}

void    DiamondTrap::whoAmI(void)
{
	std::cout << "Je suis le DiamondTrap " << _Name << " hiiii Hiiiiii" << std::endl;
}