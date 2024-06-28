/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:07:29 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/28 15:28:45 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int main(int argc, char **argv){
	if (argc != 4){
		std::cerr << "Usage: ./File filename s1 s2" << std::endl;
		return (1);
	}
	File file(argv[1], argv[2], argv[3]);
	file.newFile();
	return (0);
}