#include "Animal.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include <string>
#include <iostream>
#include <iomanip>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

	const WrongAnimal* w = new WrongCat();
	w->makeSound();
	delete w;
	return 0;
}