/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/12 11:41:30 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>     // std::cout
#include <functional>   // std::less
#include <algorithm>    // std::sort, std::includes
#include <map>
//#include "map/map.hpp"

int main()
{
	// ft::map<int, int> m;

	std::map<int, int> m;
	
	m.insert(std::make_pair(7, 0));
	m.insert(std::make_pair(2, 0));
	m.insert(std::make_pair(3, 0));
	m.insert(std::make_pair(4, 0));
	m.insert(std::make_pair(5, 0));
	m.insert(std::make_pair(6, 0));

	std::map<int, int>::iterator it;
	
	std::cout << "it->first = " << it->first << '\n';
	it--;
	std::cout << "it->first = " << it->first << '\n';

	return 0;
}
