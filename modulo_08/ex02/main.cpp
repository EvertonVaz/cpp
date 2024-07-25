/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:44:22 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/25 16:26:16 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void) {
	{
		std::cout << "\nMutantStack" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << "\nList" << std::endl;
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << "top: " << list.back() << std::endl;
		list.pop_back();
		std::cout << "size: " << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		std::list<int>::iterator itl = list.begin();
		std::list<int>::iterator itle = list.end();
		++itl;
		--itl;
		while (itl != itle)
		{
			std::cout << *itl << std::endl;
			++itl;
		}
	}

	{
		std::cout << "\nother test" << std::endl;
		std::cout << "\nMutantStack" << std::endl;
		MutantStack<int> mstack2;
		int n[] = {1, 12, 3, 11, 33};
		for (int i = 0; i < 5; i++)
			mstack2.push(n[i]);
		MutantStack<int>::iterator it2 = mstack2.begin();
		MutantStack<int>::iterator ite2 = mstack2.end();
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
		std::cout << "top: " << mstack2.top() << std::endl;
		std::cout << "size: " << mstack2.size() << std::endl;
		std::cout << "pop" << std::endl;
		mstack2.pop();
		std::cout << "top: " << mstack2.top() << std::endl;
		std::cout << "size: " << mstack2.size() << std::endl;

		std::cout << "\nList" << std::endl;
		std::list<int> list;
		for (int i = 0; i < 5; i++)
			list.push_back(n[i]);
		std::list<int>::iterator it3 = list.begin();
		std::list<int>::iterator ite3 = list.end();
		while (it3 != ite3)
		{
			std::cout << *it3 << std::endl;
			++it3;
		}
		std::cout << "top: " << list.back() << std::endl;
		std::cout << "size: " << list.size() << std::endl;
		std::cout << "pop" << std::endl;
		list.pop_back();
		std::cout << "top: " << list.back() << std::endl;
		std::cout << "size: " << list.size() << std::endl;
	}
	return 0;
}