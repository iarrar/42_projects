/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:52:26 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/30 14:52:27 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"

int main()
{
	FragTrap premier;
	FragTrap second("Imad");
	ClapTrap CP("Imad");
	ScavTrap p;
	ScavTrap s("Imad");

	CP.attack("Les mechants");
	CP.takeDamage(4);
	CP.attack("plein de mechants");
	CP.beRepaired(10);

	s.guardGate();
	s.guardGate();
	s.beRepaired(10);
	s.attack("Des mechants");


	second.highFiveGuys();
	second.highFiveGuys();
	second.beRepaired(10);
	second.takeDamage(76);
	second.attack("Des mechants");
}