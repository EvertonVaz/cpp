/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:13:30 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/06 10:00:37 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class File
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;

	public:
		File(std::string filename, std::string s1, std::string s2);
		~File();
		std::string readFile(void);
		std::string replace(std::string str);
		void		newFile();
};

#endif