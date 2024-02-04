/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:54:04 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/30 16:01:15 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Deflaut ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << name << " ScavTrap constructor called" << std::endl;
	this->_Hit_points = 100;
	this->_Energy_points = 50;
	this->_Attack_damage = 20;
	this->guard = 0;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	this->_Name = src._Name;
	this->_Attack_damage = src._Attack_damage;
	this->_Hit_points = src._Hit_points;
	this->_Energy_points = src._Energy_points;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->_Name << " ScavTrap destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
	this->_Name = src._Name;
	this->_Attack_damage = src._Attack_damage;
	this->_Hit_points = src._Hit_points;
	this->_Energy_points = src._Energy_points;
	return (*this);
}

void    ScavTrap::guardGate(void)
{
	if (guard == 0)
	{
		this->guard = 1;
		std::cout << "ScavTrap is now guarding the gates" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap is already at gate" << std::endl;
	}
}
