/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:50:33 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/18 10:01:30 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

	Animal t1 = Dog();
	Animal t2 = t1;
	t2.setType("OUTRO TIPO");
	std::cout << t1.getType() << std::endl;
	std::cout << t2.getType() << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n\n--------------------\n\n" << std::endl;
    Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
    }

	std::cout << "\n\n--------------------\n\n" << std::endl;
	Animal *copy = new Cat(*(Cat *)animals[1]);

	copy->setType("OUTRO TIPO");
	std::cout << animals[1]->getType() << std::endl;
	std::cout << copy->getType() << std::endl;
	copy->makeSound();
	delete copy;

    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }

   	std::cout << "\n\n--------------------\n\n" << std::endl;

    Dog dog42 = Dog();
    {
        Dog tmp = dog42;
        std::cout << tmp.getBrain()[97] << std::endl;
        tmp.makeSound();
    }
    dog42.makeSound();
    std::cout << dog42.getBrain()[97] << std::endl;
	return 0;
}
