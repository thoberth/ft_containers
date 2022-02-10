/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/10 18:22:29 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>     // std::cout
#include <functional>   // std::less
#include <algorithm>    // std::sort, std::includes
#include <map>
#include "red_black_tree.hpp"

// void change_ptr(int *ptr)
// {
// 	int i = 2;
// 	int *p = &i;
// 	*ptr = *p;
// }

int main()
{
	typedef ft::pair<int, int> value_type;
	red_black_tree<value_type, int> rbt;

	rbt.insert(ft::make_pair(0, 0));
	rbt.insert(ft::make_pair(1, 0));
	rbt.insert(ft::make_pair(2, 0));
	rbt.insert(ft::make_pair(3, 0));
	rbt.insert(ft::make_pair(4, 0));
	rbt.insert(ft::make_pair(5, 0));
	rbt.put_tree();
	

	// int i = 12;
	// int *p = &i;
	// int *ptr = p;

	// std::cout << *ptr << '\n';
	// change_ptr(ptr);
	// std::cout << *ptr << '\n';
	return 0;
}

// int main()
// {
// 	std::map<int, int> m;

// 	m.insert(std::make_pair(0, 0));
// 	m.insert(std::make_pair(1, 1));
// 	m.insert(std::make_pair(2, 2));
// 	m.insert(std::make_pair(3, 3));

// 	std::map<int, int>::iterator it = m.begin();

// 	for (; it != m.end(); it++)
// 		std::cout << it->second << std::endl;

// 	std::cout << std::endl;

// 	m.insert(std::make_pair(0, 3));

// 	it = m.begin();

// 	for (; it != m.end(); it++)
// 		std::cout << it->first << std::endl;
// }
