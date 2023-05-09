#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename S, typename F>
void iter(T *arr, S size, F func) {
	for (S i = 0; i < size; i++) {
		func(arr[i]);
	}
}

template <typename T>
void print(T x) {
	std::cout << x << std::endl;
}

#endif