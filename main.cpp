/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/23 17:40:01 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map/map.hpp"

#define TYPE ft

int main()
{
	TYPE::map<int, int> m;

	TYPE::pair<int, int> v = TYPE::make_pair(0, 0);

	for (size_t i = 0; i < 10000000 ; i++, v.first++)
		m.insert(v);
}
