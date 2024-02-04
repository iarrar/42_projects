/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:51:53 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/30 14:51:54 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

int main()
{
	ScavTrap premier;
	ScavTrap second("Imad");

	second.guardGate();
	second.guardGate();
	second.beRepaired(10);
	second.attack("Des mechants");
}