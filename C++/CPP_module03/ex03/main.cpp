/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:53:59 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/31 14:21:36 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"

int main()
{
	
	std::cout << "\n\n### TESTING DIAMONDTRAP ###\n" << std::endl;
	DiamondTrap a;
	DiamondTrap b("DT");
	DiamondTrap c(a);

	a.whoAmI();
	a.attack("un mechant");
	b.whoAmI();
	b.attack("un autre mechant");
	c.whoAmI();
	return (0);
}