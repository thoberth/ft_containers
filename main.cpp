/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/03/12 17:38:27 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "containers/map.hpp"

#define TYPE ft

int main()
{
	TYPE::map<int, int> m;

	TYPE::pair<int, int> v = TYPE::make_pair(0, 0);

	for (size_t i = 0; i < 1000000 ; i++, v.first++)
		m.insert(v);
}
