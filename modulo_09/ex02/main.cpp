/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:20:37 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/31 17:07:18 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "Usage: ./pmergme [num1] [num2] [num3] ..." << std::endl;
        return 1;
    }
    PmergeMe pmergeMe;
    pmergeMe.process(argc, argv);
    return 0;
}
