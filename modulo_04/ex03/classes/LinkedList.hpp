/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:50:49 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 17:34:15 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"

class LinkedList {
	private:
		Node* head;

	public:
		LinkedList();
		LinkedList(LinkedList const &src);
		LinkedList &operator=(LinkedList const &rhs);
		~LinkedList();

		void add(AMateria* item);
		void clear();
		std::size_t size();
};

#endif