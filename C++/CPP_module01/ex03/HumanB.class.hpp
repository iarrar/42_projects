/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:11:36 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/08 16:58:56 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_H
#define HUMANB_CLASS_H
# include <string>
# include <iostream>
# include "Weapon.class.hpp"

class HumanB
{
public:
    HumanB(std::string name);
    ~HumanB();
    void setWeapon(Weapon& weapon); 
    void    attack(void);

private:
    std::string name;
    Weapon* weapon;
};

#endif