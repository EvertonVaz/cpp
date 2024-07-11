/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:17:13 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/06 10:07:00 by etovaz           ###   ########.fr       */
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

std::string File::replace(std::string file){
	while (file.find(s1) != std::string::npos) {
		std::size_t pos = file.find(s1);
		file.erase(pos, s1.length());
		file.insert(pos, s2);
	}
	return (file);
}

void File::newFile(){
	std::string file = readFile();
	try {
		std::string newFile = replace(file);
		std::ofstream file((filename + ".replace").c_str());
		if (!file) {
			return throw std::runtime_error("Could not open file " + filename + ".replace");
		}
		file << newFile;
		file.close();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
