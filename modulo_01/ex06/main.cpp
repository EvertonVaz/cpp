/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:45:44 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/28 16:51:34 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void filter(Harl& harl, std::string level) {
    std::string levels[] = {"debug", "info", "warning", "error"};
    int startLevel = -1;

    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            startLevel = i;
            break;
        }
    }

    switch (startLevel) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("debug");
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("info");
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("warning");
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("error");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }

    Harl harl;
    filter(harl, argv[1]);
    return 0;
}