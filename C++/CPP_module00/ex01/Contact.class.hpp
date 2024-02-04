/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:19:26 by imad              #+#    #+#             */
/*   Updated: 2024/01/25 13:17:09 by home             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef Contact_CLASS_H
# define Contact_CLASS_H
# include <iostream>
# include <iomanip>

class Contact 
{
private:
	std::string	fname;
	std::string	lname;
	std::string	nickname;
	std::string	number;
	std::string	secret;
	std::string	aff_ten_char(const std::string& str);
public:

	Contact(void);
	~Contact(void);
	void	display_contact(int index);
	void	contact_details(void);
	void	getFname(std::string entry);
	void	getLname(std::string entry);
	void	getNickname(std::string entry);
	void	getNumber(std::string entry);
	void	getSecret(std::string entry);


};

#endif