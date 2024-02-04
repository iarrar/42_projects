/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:05:44 by imad              #+#    #+#             */
/*   Updated: 2024/01/29 14:09:05 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add_contact(int index, std::string fname, std::string lname, std::string nickname, std::string number, std::string secret)
{
	contacts[index].getLname(lname);
	contacts[index].getFname(fname);
	contacts[index].getNickname(nickname);
	contacts[index].getNumber(number);
	contacts[index].getSecret(secret);
}

void	PhoneBook::show_contacts(void)
{
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
	size_t i = 0;
	while (i < 8)
	{
		contacts[i].display_contact(i);
		i++;
	}
	return ;
}

void	PhoneBook::display_info(int index)
{
	contacts[index].contact_details();
	return ;
}