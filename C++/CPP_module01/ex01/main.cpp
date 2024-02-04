/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:59:08 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 17:59:51 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.class.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int i = 0;
    Zombie *horde = zombieHorde(42, "Imad");
    while (i < 42)
    {
        horde[i].announce();
        i++;
    }
    
    delete [] horde;

    std::cout << "delete worked fine" << std::endl;
	return (0);
}