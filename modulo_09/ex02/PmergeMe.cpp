/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:11:42 by etovaz            #+#    #+#             */
/*   Updated: 2024/08/01 11:49:03 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe) {
	*this = pmergeMe;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe) {
	(void)pmergeMe;
	return *this;
}


void PmergeMe::process(int argc, char **argv) {
	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num < 0) {
            std::cerr << "Error: negative number not allowed." << std::endl;
            return;
        }
        vec.push_back(num);
        deq.push_back(num);
    }

    printPhase(vec, "Before: ");
    double timeVec = getTime(vec);
    double timeDeq = getTime(deq);
	printPhase(vec, "After: ");
	showTime(vec, timeVec, "vector");
	showTime(deq, timeDeq, "deque");
}
