/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_module00.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imad <imad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:20:47 by imad              #+#    #+#             */
/*   Updated: 2023/12/27 11:53:09 by imad             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc < 2)
	{
		std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
	}
	else
	{
		while (j < argc)
		{
			while (argv[j][i])
			{
				std::cout << (char)std::toupper(argv[j][i]);
				i++;
			}
			i = 0;
			j++;
		}
	}
	std::cout << std::endl;
	return (0);
}