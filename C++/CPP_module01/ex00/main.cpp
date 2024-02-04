/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:49:06 by imad              #+#    #+#             */
/*   Updated: 2024/01/29 18:00:07 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie*	newZombie(std::string name);

int main()
{
	Zombie *Imad = newZombie("Imad");
	Imad->announce();
	randomChump("Anis");
	delete Imad;
	return (0);
}