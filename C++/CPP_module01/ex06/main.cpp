/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:02:25 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 18:02:27 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

int main(int argc, char **argv)
{
	Harl Karen;
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (0);
	}
	else
	{
		Karen.complain(argv[1]);
		return (0);
	}
}