/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/03/29 12:56:07 by thoberth         ###   ########.fr       */
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
	std::cout << "\n";
}

int main()
{
#ifndef USING_STD
	std::cout << YELLOW << "\t\t\tTESTER FT" << RESET << '\n';
#else
	std::cout << YELLOW << "\t\t\tTESTER STD" << RESET << '\n';
#endif
	/* test de map */
	std::cout << LIGHTBLUE << "////////////////////constructor test ->\n" << RESET;
	TYPE::map<int, int> m;

	TYPE::pair<int, int> v = TYPE::make_pair(0, 1);

	for (size_t i = 0; i < 10 ; i++, v.first++, (v.second *= v.first))
		m.insert(v);
	print_map(m);

	TYPE::map<int, int> m2(m.begin(), (--(--(--(--m.end())))));
	print_map(m2);

	TYPE::map<int, int> m3(m2);
	print_map(m3);

	std::cout << LIGHTBLUE << "////////////////////operator= test ->\n" << RESET;

	m3 = m;
	print_map(m3);
	m2 = m3;
	print_map(m);

	std::cout << LIGHTBLUE << "////////////////////iterator test ->\n" << RESET;
	std::cout << "m.begin()->first = " << m.begin()->first\
		<< "\n(++(++(m.begin())))->first = " << (++(++(m.begin())))->first << std::endl;

	std::cout << "\n(--m.end())->first = " << (--m.end())->first\
		<< "\n(--(--(m.end())))->first = " << (--(--(m.end())))->first << std::endl;

	TYPE::map<int, int>::const_iterator cit = m.begin();
	std::cout << "\nm.const_iterator(begin) key = " << cit->first << "\n\n";

	std::cout << LIGHTBLUE << "////////////////////reverse_iterator test ->\n" << RESET;

	std::cout << "m.rbegin()->first = " << m.rbegin()->first\
		<< "\n(++(++(m.rbegin())))->first = " << (++(++(m.rbegin())))->first << std::endl;

	std::cout << "\n(--m.rend())->first = " << (--m.rend())->first\
		<< "\n(--(--(m.rend())))->first = " << (--(--(m.rend())))->first << std::endl;

	std::cout << LIGHTBLUE << "////////////////////capacity test ->\n" << RESET;

	TYPE::map<std::string, std::string> m4;

	std::cout << "empty = " << m4.empty() << "\nsize = " << m4.size();
	std::cout << "\nmax_size = " << m4.max_size() << "\n\n";

	m4.insert(TYPE::make_pair("A", "A"));
	m4.insert(TYPE::make_pair("BB", "BB"));
	m4.insert(TYPE::make_pair("CCC", "CCC"));


	std::cout << "empty = " << m4.empty() << "\nsize = " << m4.size();
	std::cout << "\nmax_size = " << m4.max_size() << "\n\n";

	std::cout << LIGHTBLUE << "////////////////////element access test ->\n" << RESET;

	std::cout << "m4[\"BB\"] = " << m4["BB"] << "\n\n";
	std::cout << "m[4] = " << m[4] << "\n\n";

	std::cout << LIGHTBLUE << "////////////////////modifiers test ->\n" << RESET;
}
