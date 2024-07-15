/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:50:33 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 15:36:51 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //vai imprimir o som do gato!
    j->makeSound();

	Dog t1 = Dog();
	Dog t2 = t1;
	t2.setType("OUTRO TIPO");
	std::cout << t1.getType() << std::endl;
	std::cout << t2.getType() << std::endl;
	delete j;
	delete i;

	std::cout << "---------------------" << std::endl;
    Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
    }

	std::cout << "\n\n-------COPY----------\n\n" << std::endl;
	Animal *copy = new Cat(*(Cat *)animals[1]);
	copy->setType("OUTRO TIPO");
	std::cout << copy->getType() << std::endl;
	std::cout << animals[1]->getType() << std::endl;
	copy->makeSound();
	delete copy;

    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }

	return 0;
}
