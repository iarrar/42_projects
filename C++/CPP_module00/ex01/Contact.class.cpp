/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:58:09 by imad              #+#    #+#             */
/*   Updated: 2024/01/29 14:09:03 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::display_contact(int index)
{
	std::cout << std::setw(10) << std::right << index << "|";
	std::cout << std::setw(10) << std::right << aff_ten_char(fname) << "|";
	std::cout << std::setw(10) << std::right << aff_ten_char(lname) << "|";
	std::cout << std::setw(10) << std::right << aff_ten_char(nickname) << std::endl;
	return ;
}

void	Contact::contact_details(void)
{
	std::cout << "First name : " << fname << std::endl;
	std::cout << "Last name : " << lname << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Phone Number : " << number << std::endl;
	std::cout << "Darkest Secret : " << secret << std::endl;
}

std::string	Contact::aff_ten_char(const std::string& str)
{
	if (str.size() < 10)
		return (str);
	else
	{
		std::string dest = str.substr(0, 9) + ".";
		return(dest);
	}
}

void	Contact::getFname(std::string entry)
{
	this->fname = entry;
	return ;
}
void	Contact::getLname(std::string entry)
{
	this->lname = entry;
	return ;
}
void	Contact::getNickname(std::string entry)
{
	this->nickname = entry;
	return ;
}
void	Contact::getNumber(std::string entry)
{
	this->number = entry;
	return ;
}
void	Contact::getSecret(std::string entry)
{
	this->secret = entry;
	return ;
}