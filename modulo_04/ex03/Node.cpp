/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:55:10 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 17:53:11 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Node.hpp"

Node::Node(AMateria* m) : materia(m), next(NULL) {}

Node::Node(Node const &src) : materia(src.materia), next(src.next) {}

Node &Node::operator=(Node const &rhs) {
	if (this != &rhs) {
		materia = rhs.materia;
		next = rhs.next;
	}
	return *this;
}

Node::~Node() {
	if (materia) {
		delete materia;
		materia = NULL;
	}
}