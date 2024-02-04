/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:38:33 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 18:02:10 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

int main(int argc, char **argv)
{
	Harl Karen;
	

	if (argc == 1)
	{
		std::cout << "Enter an argument" << std::endl;
		return (0);
	}

	Karen.complain(argv[1]);
	return (0);
}