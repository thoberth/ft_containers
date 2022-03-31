/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/03/31 18:16:58 by thoberth         ###   ########.fr       */
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
	std::cout << "size = " << m.size() << std::endl;
	for (typename TYPE::map<T, T2>::iterator it = m.begin(), ite = m.end();
		it != ite; it++)
		std::cout << "key = " << it->first << " val = " << it->second << std::endl;
	std::cout << "\n";
}

template<typename T>
void	print_vector(TYPE::vector<T> &v)
{
	std::cout << "size = " << v.size() << " capacity = " << v.capacity() << std::endl;
	for (typename TYPE::vector<T>::iterator it = v.begin(), ite = v.end();
		it != ite; it++)
		std::cout << "val = " << *it << std::endl;
	std::cout << "\n";
}

int main()
{
#ifndef USING_STD
	std::cout << YELLOW << "\t\t\tTESTER FT" << RESET << '\n';
#else
	std::cout << YELLOW << "\t\t\tTESTER STD" << RESET << '\n';
#endif
	std::cout << YELLOW << "\t\t MAP TEST" << RESET << '\n';
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
	std::cout << LIGHTBLUE << "/////////insert test ->\n" << RESET;
	std::cout << "before insert ->\n";
	print_map(m);
	TYPE::pair<TYPE::map<int, int>::iterator, bool> ret = m.insert(TYPE::make_pair(13, 42));

	std::cout << "return = " << ret.first->first << " " << ret.first->second << '\n';
	std::cout << "after insert ->\n";
	print_map(m);

	std::cout << "new insert ->\n";
	TYPE::map<int, int>::iterator it = m.insert(++(++(++(m.begin()))), TYPE::make_pair(10, 42));
	std::cout << "return = " << it->first << " " << it->second << '\n';
	std::cout << "after insert ->\n";
	print_map(m);
	
	std::cout << "before insert ->\n";
	print_map(m2);
	m2.insert(--(--(--m.end())), m.end());
	std::cout << "after insert ->\n";
	print_map(m2);

	std::cout << LIGHTBLUE << "/////////erase test ->\n" << RESET;

	std::cout << "before erase ->\n";
	print_map(m2);
	m2.erase(m2.begin());
	std::cout << "after erase ->\n";
	print_map(m2);

	std::cout << "new erase by key = 9 ->\n";
	m2.erase(9);
	std::cout << "after erase ->\n";
	print_map(m2);

	std::cout << "new erase by iterator from to begin + 3 to end ->\n";
	m2.erase(++(++(++m2.begin())), m2.end());
	std::cout << "after erase ->\n";
	print_map(m2);

	std::cout << LIGHTBLUE << "/////////swap test ->\n" << RESET;
	std::cout << "map 1 = \n";
	print_map(m3);
	std::cout << "map 2 = \n";
	print_map(m2);
	std::cout << "after swap map1 by map2 ->\n";
	m3.swap(m2);
	print_map(m3);

	std::cout << LIGHTBLUE << "/////////clear test ->\n" << RESET;

	std::cout << "before clear ->\n";
	print_map(m2);
	m2.clear();
	std::cout << "after clear ->\n";
	print_map(m2);

	std::cout << LIGHTBLUE << "////////////////////operations test ->\n" << RESET;

	std::cout << LIGHTBLUE << "/////////find test ->\n" << RESET;

	std::cout << "containers = ->\n";
	print_map(m);

	std::cout << "find  0 ->\n";
	it = m.find(0);
	std::cout << "resulat " << it->first << " " << it->second << "\n";
	std::cout << "find  9->\n";
	it = m.find(9);
	std::cout << "resulat " << it->first << " " << it->second << "\n";

	std::cout << LIGHTBLUE << "/////////count test ->\n" << RESET;

	std::cout << "count key = 0 ->\n";
	size_t ret1 = m.count(0);
	std::cout << "resulat " << ret1 << "\n";
	std::cout << "count key =11 ->\n";
	ret1 = m.count(119);
	std::cout << "resulat " << ret1 << "\n";

	std::cout << LIGHTBLUE << "/////////lower_bound test ->\n" << RESET;

	std::cout << "containers = ->\n";
	print_map(m);

	std::cout << "lower_bound 5 ->\n";
	it = m.lower_bound(5);
	std::cout << "resulat " << it->first << " " << it->second << "\n";
	std::cout << "lower_bound 13 ->\n";
	it = m.lower_bound(13);
	std::cout << "resulat " << it->first << " " << it->second << "\n";

	std::cout << LIGHTBLUE << "/////////upper_bound test ->\n" << RESET;

	std::cout << "upper_bound 5 ->\n";
	it = m.upper_bound(5);
	std::cout << "resulat " << it->first << " " << it->second << "\n";
	std::cout << "upper_bound 10 ->\n";
	it = m.upper_bound(10);
	std::cout << "resulat " << it->first << " " << it->second << "\n";

	std::cout << YELLOW << "\t\t VECTOR TEST" << RESET << '\n';

	std::cout << LIGHTBLUE << "////////////////////contructor test ->\n" << RESET;

	std::cout << "default cons ->\n";
	TYPE::vector<int> vec;
	print_vector(vec);

	std::cout << "fill cons ->\n";
	TYPE::vector<int> vec2(8, 42);
	print_vector(vec2);

	std::cout << "range cons ->\n";
	TYPE::vector<int> vec3(vec2.begin() + 2, vec2.end() - 2);
	print_vector(vec3);

	std::cout << "copy constructor ->\n";
	TYPE::vector<int> vec4(vec2);
	print_vector(vec4);

	std::cout << LIGHTBLUE << "////////////////////operator= test ->\n" << RESET;

	vec = vec3;
	std::cout << "vector empty after operator= ->\n";
	print_vector(vec);

	std::cout << LIGHTBLUE << "////////////////////iterator test ->\n" << RESET;

	std::cout << "modifying vector while using iterator begin and end ->\nbefore modif\n";
	print_vector(vec2);
	TYPE::vector<int>::iterator itv = vec2.begin();
	for (int i = 1; itv != vec2.end(); itv++ , i++)
		*itv /= i;
	std::cout << "after modif->\n";
	print_vector(vec2);

	std::cout << "modifying vector while using reverse iterator begin and end ->\nbefore modif\n";
	print_vector(vec2);
	TYPE::vector<int>::reverse_iterator ritv = vec2.rbegin();
	for (int i = 1; ritv != vec2.rend(); ritv++ , i++)
		*ritv += i;
	std::cout << "after modif->\n";
	print_vector(vec2);

	std::cout << LIGHTBLUE << "////////////////////capacity test ->\n" << RESET;
	std::cout << LIGHTBLUE << "/////////max_size test ->\n" << RESET;
	std::cout << "max size = " << vec.max_size() << '\n';

	std::cout << LIGHTBLUE << "/////////resize test ->\n" << RESET;
	std::cout << "before resize ->\n";
	print_vector(vec3);
	vec3.resize(6, 12);
	std::cout << "after resize ->\n";
	print_vector(vec3);

	std::cout << LIGHTBLUE << "/////////empty test ->\n" << RESET;
	std::cout << "is vector empty ?\n" << vec4.empty() << '\n';
	vec4.clear();
	std::cout << "***vector clean***\nis vector empty ?\n" << vec4.empty() << '\n';

	std::cout << LIGHTBLUE << "/////////reserve test ->\n" << RESET;

	std::cout << "before reserve 3 ->\n";
	print_vector(vec);
	vec.reserve(3);
	std::cout << "after reserve ->\n";
	print_vector(vec);

	std::cout << "before reserve 5 ->\n";
	print_vector(vec);
	vec.reserve(5);
	std::cout << "after reserve ->\n";
	print_vector(vec);

	std::cout << LIGHTBLUE << "////////////////////element access test ->\n" << RESET;
	
	print_vector(vec2);

	std::cout << "front = " << vec2.front() << "\nback = " << vec2.back()
		<< "\nat(4) = " << vec2.at(4) << "\nvector[2] = " << vec2[2] << '\n';

	std::cout << LIGHTBLUE << "////////////////////modifiers test ->\n" << RESET;
	std::cout << LIGHTBLUE << "/////////assign test ->\n" << RESET;
	std::cout << "before assign n=7 val =6 ->\n";
	print_vector(vec3);
	vec3.assign(7, 6);
	std::cout << "after assign ->\n";
	print_vector(vec3);

	std::cout << "before assign from another vector \n another vector = ->\n";
	print_vector(vec2);
	vec3.assign(vec2.begin(), vec2.end());
	std::cout << "after assign ->\n";
	print_vector(vec3);

	std::cout << LIGHTBLUE << "/////////push_back test ->\n" << RESET;
	std::cout << "before push back 1234 ->\n";
	print_vector(vec);
	vec.push_back(1234);
	std::cout << "after push back ->\n";
	print_vector(vec);

	std::cout << LIGHTBLUE << "/////////pop_back test ->\n" << RESET;
	std::cout << "before pop back 1234 ->\n";
	print_vector(vec);
	vec.pop_back();
	std::cout << "after pop back ->\n";
	print_vector(vec);

	std::cout << LIGHTBLUE << "/////////insert test ->\n" << RESET;
	std::cout << "before insert 13 at begin + 2 ->\n";
	print_vector(vec);
	vec.insert(vec.begin() + 2, 13);
	std::cout << "after insert ->\n";
	print_vector(vec);

	std::cout << "before insert -4 3 times at begin ->\n";
	print_vector(vec2);
	vec2.insert(vec2.begin(), 3, -4);
	std::cout << "after insert ->\n";
	print_vector(vec2);

	std::cout << "before insert val of an other vector a end of this vector ->\n";
	print_vector(vec2);
	std::cout << "vector which is insert ->\n";
	print_vector(vec);
	vec2.insert(vec2.end(), vec.begin(), vec.end());
	std::cout << "after insert ->\n";
	print_vector(vec2);

	std::cout << LIGHTBLUE << "/////////erase test ->\n" << RESET;
	std::cout << "before erase at [0] ->\n";
	print_vector(vec2);
	vec2.erase(vec2.begin());
	std::cout << "after erase ->\n";
	print_vector(vec2);

	std::cout << "before erase from begin +2 to end -2 ->\n";
	print_vector(vec2);
	vec2.erase(vec2.begin() + 2, vec2.end() -2);
	std::cout << "after erase ->\n";
	print_vector(vec2);

	std::cout << LIGHTBLUE << "/////////swap test ->\n" << RESET;
	std::cout << "vector1 = \n";
	print_vector(vec2);
	std::cout << "vector2 = \n";
	print_vector(vec4);
	std::cout << "***SWAP***";
	vec2.swap(vec4);
	std::cout << "\n\nvector1 = \n";
	print_vector(vec2);
	std::cout << "vector2 = \n";
	print_vector(vec4);

	std::cout << YELLOW << "\t\t STACK TEST" << RESET << '\n';
	TYPE::stack<std::string> my_stack;

	std::cout << LIGHTBLUE << "////////////////////push and top test ->\n" << RESET;
	for (std::string str = "A"; str.size() < 5; str.push_back('A'))
	{
		my_stack.push(str);
		std::cout << "top = " << my_stack.top() << '\n'	;
	}

	std::cout << LIGHTBLUE << "////////////////////empty test ->\n" << RESET;
	std::cout << "stack empty ? " << my_stack.empty() << '\n';

	std::cout << LIGHTBLUE << "////////////////////pop and top test ->\n" << RESET;
	for (; my_stack.size() > 0; my_stack.pop())
	{
		std::cout << "top = " << my_stack.top() << '\n'	;
	}

	std::cout << LIGHTBLUE << "////////////////////empty test ->\n" << RESET;
	std::cout << "stack empty ? " << my_stack.empty() << '\n';
}
