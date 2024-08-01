/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:39:18 by egeraldo          #+#    #+#             */
/*   Updated: 2024/08/01 16:44:42 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>
#include <iostream>

template <typename T>
void PmergeMe::mergeInsertSort(T &container, int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergeInsertSort(container, left, middle);
		mergeInsertSort(container, middle + 1, right);

		T leftContainer(container.begin() + left, container.begin() + middle + 1);
		T rigthContainer(container.begin() + middle + 1, container.begin() + right + 1);

		size_t i = 0, j = 0, k = left;
		while (i < leftContainer.size() && j < rigthContainer.size()) {
			if (leftContainer[i] <= rigthContainer[j])
			container[k++] = leftContainer[i++];
			else
			container[k++] = rigthContainer[j++];
		}
		while (i < leftContainer.size())
			container[k++] = leftContainer[i++];

		while (j < rigthContainer.size())
			container[k++] = rigthContainer[j++];
	}
}

template <typename T>
double PmergeMe::getTime(T &container) {
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	mergeInsertSort(container, 0, container.size() - 1);
	clock_gettime(CLOCK_MONOTONIC, &end);
	return (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e6;
}

template <typename T>
void PmergeMe::showTime(T container, double time, std::string type) {
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << container.size();
	std::cout << " elements with std::" << std::setw(6) << type << ": ";
	std::cout << time << " us" << std::endl;
}

template <typename T>
void PmergeMe::printPhase(T &container, std::string phase) const {
	std::cout << phase;
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}