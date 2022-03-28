/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/03/28 21:12:01 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <vector>
#include <stack>
#include "containers/map.hpp"
#include "containers/vector.hpp"
#include "containers/stack.hpp"

#ifndef USING_STD
 #define TYPE ft
#else
 #define TYPE std
#endif

template<typename T, typename T2>
void print_map(TYPE::map<T, T2> &m)
{
	(void)m;
	std::cout << "size = " << m.size() << std::endl;
	for (typename TYPE::map<T, T2>::iterator it = m.begin(), ite = m.end();
		it != ite; it++)
		std::cout << "key = " << it->first << " val = " << it->second << std::endl;
}

int main()
{
#ifndef USING_STD
	std::cout << "\t\t\tTESTER FT\n";
#else
	std::cout << "\t\t\tTESTER STD\n";
#endif
	/* test de map */
	TYPE::map<int, int> m;


	TYPE::pair<int, int> v = TYPE::make_pair(0, 0);

	for (size_t i = 0; i < 10 ; i++, v.first++)
		m.insert(v);
	print_map(m);
}
