/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:51:10 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/30 15:56:02 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

ClapTrap::ClapTrap() : _Hit_points(10) , _Energy_points(10), _Attack_damage(0)
{
	_Name = "Random Player";
	std::cout << _Name << "joined the party" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string Name) : _Name(Name), _Hit_points(10) , _Energy_points(10), _Attack_damage(0)
{
	std::cout << "Player " << _Name << " joined the party" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	this->_Name = src._Name;
	this->_Attack_damage = src._Attack_damage;
	this->_Hit_points = src._Hit_points;
	this->_Energy_points = src._Energy_points;
}

ClapTrap::~ClapTrap()
{
	std::cout << "end of game" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	this->_Name = src._Name;
	this->_Attack_damage = src._Attack_damage;
	this->_Hit_points = src._Hit_points;
	this->_Energy_points = src._Energy_points;
	return (*this);
}

void	ClapTrap::attack(const std::string & target)
{
	if (_Hit_points > 0 && _Energy_points > 0)
	{
		std::cout << _Name << " attacked " << target << " causing it " << _Attack_damage << " loss of Hit Points" << std::endl;
		_Energy_points--;
	}
	else if (_Energy_points == 0)
	{
		std::cout << _Name << "has no Energy points left" << std::endl;
	}
	else if (_Hit_points == 0)
	{
		std::cout << _Name << "has no Hit Points left" << std::endl;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_Hit_points -= amount;
	std::cout << _Name << " suffered an attack. Hit points = " << _Hit_points << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_Energy_points > 0)
	{
		_Hit_points = _Hit_points + amount;
		std::cout << _Name << " has gained" << amount << " points of Hit. Now has " << _Hit_points << " Hit Points." << std::endl;
	}
	else
	{
		std::cout << _Name << " has no energy points left to gain repair himself" << std::endl;
	}
	return ;
}

void	ClapTrap::getName(void)
{
	std::cout << "My name is : " << _Name << std::endl;
}