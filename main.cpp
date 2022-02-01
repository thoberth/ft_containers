/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/01 14:48:25 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>	// std::pair
#include <iostream> // std::cout
#include "ft_utils.hpp"

int main()
{
	std::pair<int, int> foo;
	std::pair<int, int> bar;

	foo = std::make_pair(10, 20);
	bar = std::make_pair(10.5, 'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

	return 0;
}
