/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:01:55 by imad              #+#    #+#             */
/*   Updated: 2024/01/25 14:31:21 by home             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include <iostream>
# include "Contact.class.hpp"

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	add_contact(int index, std::string fname, std::string lname, std::string nickname, std::string number, std::string secret);
	void	show_contacts(void);
	void	display_info(int index);
private:
	Contact contacts[8];
};

#endif