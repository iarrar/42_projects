/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:59:40 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 17:59:41 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *horde;
    int i = 0;

    horde = new Zombie[N];
    while (i < N)
    {
        horde[i].attribut_name(name);
        i++;
    }
    return(horde);
}