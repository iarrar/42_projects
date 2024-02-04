#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include <string>
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "Test des leaks de base \n\n" << std::endl;
	Cat *Miaou = new Cat();
	Dog *Ouaf = new Dog();
	delete Miaou;
	delete Ouaf;
	std::cout << "\n\n Test du tableau d'Animal \n\n" << std::endl;
	AAnimal *Tab[4];
	std::cout << "\n\n" << std::endl;
	Tab[0] = new Dog();
	Tab[1] = new Dog();
	Tab[2] = new Cat();
	Tab[3] = new Cat();
	int i = 0;
 	while (i < 4)
	{
		Tab[i]->makeSound();
		delete Tab[i];
		i++;
	}
	std::cout << "\n\n Test des copies profondes \n\n" << std::endl;
	Cat Chat;
	Cat Mistoufle(Chat);
	Chat.affBrainAdress();
	Mistoufle.affBrainAdress();

	std::cout << "\n\n Tentative d'instanciation de la classe Animal" << std::endl;
	AAnimal Boo;
	std::cout << Boo.getType() << std::endl;
	Boo.makeSound();

}