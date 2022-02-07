/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/07 19:09:50 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>     // std::cout
#include <functional>   // std::less
#include <algorithm>    // std::sort, std::includes
#include <map>
#include "red_black_tree.hpp"

int main()
{
	typedef ft::pair<int, int> value_type;
	red_black_tree<value_type> rbt;

	rbt.insert(ft::make_pair(1,2));


	return 0;
}
