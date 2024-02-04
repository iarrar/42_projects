/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:00:47 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 18:00:48 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string& stringREF = str;
    std::string* stringPTR = &str;

    std::cout << "Adress de str = " << &str << std::endl;
    std::cout << "Adresse pointee par *str = " << stringPTR << std::endl;
    std::cout << "Adresse pointee par &str = " << &stringREF << std::endl;
    std::cout << "Valeur de str = " << str << std::endl;
    std::cout << "Valeur pointee par *str = " << *stringPTR << std::endl;
    std::cout << "Valeur pointee par &str = " << stringREF << std::endl;
}
