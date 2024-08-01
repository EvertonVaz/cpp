/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:57:51 by etovaz            #+#    #+#             */
/*   Updated: 2024/08/01 11:50:44 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma  once

#include <string>

class PmergeMe {
	private:
		template <typename T>
		void mergeInsertSort(T &container, int left, int right);

		template <typename T>
		double	getTime(T &container);

		template <typename T>
		void showTime(T container, double time, std::string type);

		template <typename T>
		void printPhase(T &container, std::string phase) const;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &pmergeMe);
		PmergeMe &operator=(const PmergeMe &pmergeMe);

		void process(int argc, char **argv);
};

#include "PmergeMe.tpp"