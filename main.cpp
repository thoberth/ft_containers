/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/17 16:58:15 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>     // std::cout
#include <functional>   // std::less
#include <algorithm>    // std::sort, std::includes
#include <map>
#include "map/map.hpp"

int main()
{
	ft::map<int, int> m;

	m.insert(ft::make_pair(0, 0));
	m.insert(ft::make_pair(1, 0));
	m.insert(ft::make_pair(2, 0));
	m.insert(ft::make_pair(3, 0));
	m.insert(ft::make_pair(4, 0));
	m.insert(ft::make_pair(5, 0));
	m.insert(ft::make_pair(6, 0));
	m.insert(ft::make_pair(7, 0));
	m.insert(ft::make_pair(8, 0));
	m.insert(ft::make_pair(9, 0));

	m.put_tree();

	m.erase(++m.begin());

	m.put_tree();

	ft::map<int, int>::const_iterator it = m.begin();

	for(; it != m.end(); it++)
	std::cout << "it = " << it->first << '\n';

	return 0;
}
