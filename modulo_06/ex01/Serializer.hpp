/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:17:05 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/23 09:43:17 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

struct Data {
	std::string name;
	std::string lastName;
	int age;
};

class Serializer {
	private:
		Serializer();
		Serializer(Serializer const &src);
		Serializer &operator=(Serializer const &src);
		~Serializer();

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};