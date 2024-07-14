/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:17:13 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/14 10:40:13 by etovaz           ###   ########.fr       */
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
	std::size_t pos = 0;

	while (pos != std::string::npos) {
		pos = file.find(s1, pos);
		if (pos == std::string::npos)
			break;
		file.erase(pos, s1.length());
		file.insert(pos, s2);
		pos += s1.length();
	}
	return (file);
}

void File::newFile(){
	try {
		std::string originFile = readFile();
		std::string newFile = replace(originFile);
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
