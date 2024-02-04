/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:11:47 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 18:01:30 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H
# include <string>
# include <iostream>


class Weapon
{
public:
    Weapon(std::string type);
    ~Weapon();
    std::string getType(void);
    void    setType(const std::string newWeapon);

private:
    std::string type;
};

#endif