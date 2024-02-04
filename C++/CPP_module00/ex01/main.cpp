/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:09:39 by imad              #+#    #+#             */
/*   Updated: 2024/01/25 16:48:03 by home             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

 #include "PhoneBook.class.hpp"
 #include "Contact.class.hpp"

 int	main()
 {
	PhoneBook	repertoire;
	std::string	buffer;
	int			add = 0;

	while (1)
	{
		std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
		{
			std::string fname, lname, nickname, number, secret;

			std::cout << "Enter first name :" << std::endl;
			std::getline(std::cin, fname);
			std::cout << "Enter last name :" << std::endl;
			std::getline(std::cin, lname);
			std::cout << "Enter nickname :" << std::endl;
			std::getline(std::cin, nickname);
			std::cout << "Enter phone number :" << std::endl;
			std::getline(std::cin, number);
			std::cout << "Tell me " << fname << "'s darkest secret... :" << std::endl;
			std::getline(std::cin, secret);
			add = add % 8;
			repertoire.add_contact(add, fname, lname, nickname, number, secret);
			add++;
		}
		else if (buffer == "SEARCH")
		{
			long unsigned int	index;
			repertoire.show_contacts();
			std::cout << "Enter contact index to see details : " << std::endl;
			std::cin >> index;
			std::cin.ignore();
			if (index > 7)
				std::cout << "Invalid index" << std::endl;
			else
			{
				repertoire.display_info(index);
			}
		}
		else if (buffer == "EXIT")
			break;
		else
			std::cout << "Wrong Entry" <<std::endl;
	}
	

	return (0);
 }