/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:53:09 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/31 14:13:43 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H
#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const & src);
        ~DiamondTrap();
       DiamondTrap& operator=(DiamondTrap const & src);
       void attack(const std::string & target);
       void whoAmI(void);

    private:
        std::string _Name;
        
};

#endif