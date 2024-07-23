/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:18:55 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/23 09:48:33 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Data *data = new Data;
	data->name = "Everton";
	data->lastName = "Vaz";
	data->age = 19;

	uintptr_t raw = Serializer::serialize(data);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "Raw: " << raw << std::endl;
	std::cout << "Name: " << ptr->name << std::endl;
	std::cout << "Last Name: " << ptr->lastName << std::endl;
	std::cout << "Age: " << ptr->age << std::endl;

	Data data2;
	data2.name = "Everton";
	data2.lastName = "Vaz";
	data2.age = 35;
	raw = Serializer::serialize(&data2);
	ptr = Serializer::deserialize(raw);

	std::cout << "Raw: " << raw << std::endl;
	std::cout << "Name: " << ptr->name << std::endl;
	std::cout << "Last Name: " << ptr->lastName << std::endl;
	std::cout << "Age: " << ptr->age << std::endl;

	delete data;
	return 0;
}