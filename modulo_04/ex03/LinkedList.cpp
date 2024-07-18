/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:57:23 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 17:50:00 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/LinkedList.hpp"

LinkedList::LinkedList() : head(NULL) {}

LinkedList::LinkedList(LinkedList const &src) : head(NULL) {
    Node* temp = src.head;
    while (temp) {
        add(temp->materia->clone());
        temp = temp->next;
    }
}

LinkedList &LinkedList::operator=(LinkedList const &rhs) {
    if (this != &rhs) {
        clear();
        Node* temp = rhs.head;
        while (temp) {
            add(temp->materia->clone());
            temp = temp->next;
        }
    }
    return *this;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::add(AMateria* item) {
    Node* newNode = new Node(item);
    newNode->next = head;
    head = newNode;
}

std::size_t LinkedList::size() {
    std::size_t count = 0;
    Node* temp = head;

    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void LinkedList::clear() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }
}
