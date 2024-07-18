/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:51:26 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 16:55:50 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef NODE_HPP
#define NODE_HPP

#include "AMateria.hpp"

class Node {
	public:
		AMateria* materia;
		Node* next;

		Node(AMateria* m);
		Node(Node const &src);
		Node &operator=(Node const &rhs);
		~Node();
};

#endif