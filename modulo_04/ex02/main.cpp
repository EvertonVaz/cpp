/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:50:33 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/18 10:12:26 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    {
        const AAnimal *j = new Dog();
        const AAnimal *i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //vai imprimir o som do gato!
        j->makeSound();
        delete j;
        delete i;
    }
    {
        std::cout << "\n\n---------------------\n\n" << std::endl;
        Dog t1 = Dog();
        Dog t2 = t1;
        t2.setType("OUTRO TIPO");
        std::cout << t1.getType() << std::endl;
        std::cout << t2.getType() << std::endl;
    }

    {
        std::cout << "\n\n---------------------\n\n" << std::endl;
        AAnimal* animals[4];

        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Dog();
        animals[3] = new Cat();

        for (int i = 0; i < 4; i++) {
            animals[i]->makeSound();
        }
        for (int i = 0; i < 4; i++) {
            delete animals[i];
        }
    }
    {
        std::cout << "\n\n---------------------\n\n" << std::endl;
        AAnimal *cat = new Cat();
        AAnimal *copy = new Cat(*(Cat *)cat);
        copy->setType("OUTRO TIPO");
        std::cout << copy->getType() << std::endl;
        std::cout << cat->getType() << std::endl;
        copy->makeSound();
        delete copy;
        delete cat;
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
