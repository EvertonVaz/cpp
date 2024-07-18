/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:42:29 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/16 18:09:59 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const &copy);
		AAnimal &operator=(AAnimal const &copy);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		virtual std::string getType() const;
		virtual void setType(std::string type);
};

#endif