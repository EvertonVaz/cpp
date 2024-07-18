/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:06:09 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/18 09:21:14 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./interfaces/IMateriaSource.hpp"
#include "./classes/MateriaSource.hpp"
#include "./interfaces/ICharacter.hpp"
#include "./classes/Character.hpp"
#include "./classes/AMateria.hpp"
#include "./classes/Cure.hpp"
#include "./classes/Fire.hpp"
#include "./classes/Ice.hpp"

int main() {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Fire());

    ICharacter *goku = new Character("Goku");
    AMateria *tmp;

    tmp = src->createMateria("ice");
    goku->equip(tmp);

    tmp = src->createMateria("fire");
    goku->equip(tmp);

    tmp = src->createMateria("cure");
    goku->equip(tmp);

    ICharacter* maj = new Character("Majimboo");

    goku->use(0, *maj);
    goku->use(1, *maj);
    goku->use(2, *maj);

    src->learnMateria(new Ice());
    tmp = src->createMateria("ice");
    goku->equip(tmp);
    src->learnMateria(new Ice());
    tmp = src->createMateria("ice");
    goku->equip(tmp);
    src->learnMateria(new Cure());
    tmp = src->createMateria("cure");
    goku->equip(tmp);

    Character *vegita = new Character("Vegita");
    src->learnMateria(new Ice());
    tmp = src->createMateria("ice");
    vegita->equip(tmp);
    src->learnMateria(new Ice());
    tmp = src->createMateria("qlqr");
    vegita->equip(tmp);
    src->learnMateria(new Cure());
    tmp = src->createMateria("cure");
    vegita->equip(tmp);
    vegita->use(0, *goku);
    Character *vegita2 = new Character(*vegita);
    vegita->unequip(1);
    vegita2->use(1, *vegita);
    delete vegita2;
    delete vegita;
    delete maj;
    delete goku;
    delete src;
    return 0;
}