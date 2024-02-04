/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:11:28 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 18:01:17 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_H
#define HUMANA_CLASS_H
# include <string>
# include <iostream>
# include "Weapon.class.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA(); 
        void    attack(void);

    private:
        std::string name;
        Weapon& weapon;
};

#endif