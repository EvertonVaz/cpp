/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:57:51 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/30 19:19:51 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma  once

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
	private:
		template <typename T>
		void mergeInsertSort(T &container, int left, int right);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &pmergeMe);
		PmergeMe &operator=(const PmergeMe &pmergeMe);

		void process(int argc, char **argv);
		template <typename T>
		double	getTime(T container);

		void printResults(
			const std::vector<int> &vec,
			const std::deque<int> &deq,
			std::string time,
			double timeVec = 0,
			double timeDeq = 0
		) const;
};