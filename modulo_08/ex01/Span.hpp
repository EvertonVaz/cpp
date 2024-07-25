/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:19:37 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/25 15:32:06 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

class Span {
	private:
		unsigned int _N;
		unsigned int _size;
		std::vector<int> _vec;

	public:
		Span();
		Span(unsigned int N);
		Span(Span const &src);
		~Span();
		Span &operator=(Span const &rhs);

		void addNumber(int n);
		void addRandomNumbers(unsigned int count, int min = -10, int max = 10);
		int shortestSpan(void);
		int longestSpan(void);
};
