/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:11:42 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/30 20:36:20 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sys/time.h>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe) {
	*this = pmergeMe;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe) {
	(void)pmergeMe;
	return *this;
}

template <typename T>
void PmergeMe::mergeInsertSort(T &container, int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergeInsertSort(container, left, middle);
		mergeInsertSort(container, middle + 1, right);

		std::inplace_merge(
			container.begin() + left,
			container.begin() + middle + 1,
			container.begin() + right + 1
		);
	}
}

template <typename T>
double PmergeMe::getTime(T container) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    mergeInsertSort(container, 0, container.size() - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    return (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e6;
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

    printResults(vec, deq, "Before: ");
    double timeVec = getTime(vec);
    double timeDeq = getTime(deq);
	printResults(vec, deq, "After: ", timeVec, timeDeq);
}

template <typename T>
void showTime(T container, double time, std::string type) {
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << container.size();
	std::cout << " elements with std::" << type << ": ";
	std::cout << time << " us" << std::endl;
}

void PmergeMe::printResults(
		const std::vector<int> &vec,
		const std::deque<int> &deq,
		std::string time,
		double timeVec,
		double timeDeq
	) const {
	std::cout << time;
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
    if (time == "Before: " && (timeDeq == 0 || timeVec == 0))
		return;

	showTime(deq, timeDeq, "deque");
	showTime(vec, timeVec, "vector");
}