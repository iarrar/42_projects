/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:05:58 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 14:56:00 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>


int main(int argc, char **argv)
{
	
	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (0);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream ifs(filename.c_str());

	if (ifs.is_open())
	{
		std::string replace = filename + ".replace"; 
		std::ofstream ofs(replace.c_str());
		size_t size = s1.size();
		std::string ligne;
		size_t position = 1;
		getline(ifs, ligne, '\0');
		while (position != std::string::npos)
		{
			position = ligne.find(s1);
			if (position != std::string::npos)
			{
			 	ligne.erase(position, size);
			 	ligne.insert(position, s2); 
			}
		}
		ofs << ligne << std::endl;
		ifs.close();
		ofs.close();
	}
	else
	{
		std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
	}
	return 0;
}

