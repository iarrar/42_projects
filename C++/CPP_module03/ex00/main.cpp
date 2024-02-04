/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:51:30 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/31 14:04:37 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main ()
{
	ClapTrap CP("Imad");
	ClapTrap Copy(CP);

	CP.attack("Les mechants");
	CP.takeDamage(4);
	CP.attack("plein de mechants");
	CP.beRepaired(10);
	std::cout << "CP name is : " << std::endl;
	CP.getName();
	std::cout << "Copy name is : " << std::endl;
	Copy.getName();
	return (0);
}