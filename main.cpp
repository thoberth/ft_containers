/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/20 19:15:03 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iterator>
#include "vector/vector.hpp"


// 1. the return type (bool) is only valid if T is an integral type:
// template <class T>
// typename std::enable_if<std::is_integral<T>::value,bool>::type
//   is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
// template < class T,
//            class = typename std::enable_if<std::is_integral<T>::value>::type>
// bool is_even (T i) {return !bool(i%2);}

// int main() {

//   int i = 1;    // code does not compile if type of i is not integral

//   std::cout << std::boolalpha;
// //   std::cout << "i is odd: " << is_odd(i) << std::endl;
//   std::cout << "i is even: " << is_even(i) << std::endl;

//   return 0;}


int main ()
{
	std::vector<int> test2;
	ft::vector<int> test;

	ft::vector<int>::iterator const it = test.begin();
	ft::vector<int>::iterator const ite = test.end();
	(void)it;
	(void)ite;
	std::cout << /*test2.at(0) << */" // " << test.at(0) << std::endl;
	test2.resize(8, 5);
	std::cout << test2.size() << " // " << test2.capacity() << std::endl;
	test2.resize(3, 5);
	std::cout << test2.size() << " // " << test2.capacity() << std::endl;
}
