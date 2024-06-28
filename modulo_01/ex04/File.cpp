/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:17:13 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/28 15:08:42 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string filename, std::string s1, std::string s2) :
	filename(filename), s1(s1), s2(s2) {}

File::~File() {}

std::string File::readFile(void){
	try {
		std::ifstream file(filename.c_str());
		if (!file) {
			throw std::runtime_error("Could not open file " + filename);
		}
		std::stringstream buffer;
		buffer << file.rdbuf();
		return (buffer.str());
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return ("");
	}
}

std::string File::replace(std::string str){
	std::string new_str;
	size_t i = 0;
	while (str[i]){
		if (str.substr(i, s1.size()) == s1){
				new_str += s2;
				i += s1.size();
		}
		else
			new_str += str[i++];
	}
	return (new_str);
}

void File::newFile(){
	std::string str = readFile();
	if (str.empty()) {
		return ;
	}
	std::string new_str = replace(str);
	try {
		std::ofstream file((filename + ".replace").c_str());
		if (!file) {
			throw std::runtime_error("Could not open file " + filename + ".replace");
		}
		file << new_str;
		file.close();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
