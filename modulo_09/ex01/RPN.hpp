/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:20:47 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/31 15:38:20 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stack>

class RPN {
	private:
		std::stack<int> _stack;
		int _applyOperator(const std::string &op, int a, int b) const;
		int _getTop();

	public:
		RPN();
		~RPN();
		RPN(const RPN &rpn);
		RPN &operator=(const RPN &rpn);

		int evaluate(const std::string &expression);
};