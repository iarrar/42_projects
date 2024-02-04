/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:53:14 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/30 16:00:50 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"

FragTrap::FragTrap()
{
	std::cout << this->_Name << " FragTrap constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << name << " FragTrap constructor called" << std::endl;
	this->_Hit_points = 100;
	this->_Energy_points = 100;
	this->_Attack_damage = 30;
	return;
}
void    FragTrap::highFiveGuys(void)
{
	std::cout << "HIGH FIVE !!! HIGH FIVE ?? anyone...?" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	this->_Name = src._Name;
	this->_Attack_damage = src._Attack_damage;
	this->_Hit_points = src._Hit_points;
	this->_Energy_points = src._Energy_points;
}

FragTrap::~FragTrap()
{
	std::cout << this->_Name << " FragTrap destructor has been called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
	this->_Name = src._Name;
	this->_Attack_damage = src._Attack_damage;
	this->_Hit_points = src._Hit_points;
	this->_Energy_points = src._Energy_points;
	return (*this);
}
