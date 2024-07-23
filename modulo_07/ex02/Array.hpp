/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:38:07 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/23 14:44:30 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
private:
	T *_array;
	unsigned int _size;

	public:
		Array() : _array(NULL), _size(0) {}

		Array(unsigned int n) : _array(new T[n]), _size(n) {}

		Array(const Array &src) : _array(NULL), _size(0) {
			*this = src;
		}

		~Array() {
			if (this->_array)
			delete[] _array;
		}

		Array &operator=(const Array &src) {
			if (this != &src) {
				delete[] _array;
				_size = src._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++) {
					_array[i] = src._array[i];
				}
			}
			return *this;
		}

		T &operator[](unsigned int i) {
			if (i >= _size) {
				throw std::out_of_range("Index out of range");
			}
			return _array[i];
		}

		unsigned int size() const { return _size; }
};
