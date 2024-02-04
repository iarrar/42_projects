/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:11:42 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/08 16:34:51 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	return ;
}

Weapon::~Weapon()
{
	return ;
}

void	Weapon::setType(const std::string newWeapon)
{
	this->type = newWeapon;
	return ;
}

std::string Weapon::getType(void)
{
	return (this->type);
}