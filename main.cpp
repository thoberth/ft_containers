/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/16 19:51:38 by thoberth         ###   ########.fr       */
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

	m.insert(ft::make_pair(1, 0));
	m.insert(ft::make_pair(3, 0));
	m.insert(ft::make_pair(2, 0));

	ft::map<int, int>::const_iterator it = m.begin();

	for(; it != m.end(); it++)
	std::cerr << "it = " << it->first << '\n';

	return 0;
}
