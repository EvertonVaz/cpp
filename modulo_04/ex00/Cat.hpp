/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:52:35 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 11:21:51 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &copy);
		Cat &operator=(Cat const &copy);
		virtual ~Cat();
		void makeSound() const;
		std::string getType() const;
};

#endif