/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:04:18 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/01 14:27:10 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_utils.hpp"
#include "../reverse_iterator.hpp"
#include <map>

namespace ft
{
	template <class Key,								  // map::key_type
			  class T,									  // map::mapped_type
			  class Compare = std::less<Key>,				  // map::key_compare
			  class Alloc = std::allocator<ft::pair<const Key, T>> // map::allocator_type
			  >
	class map
	{

	};
}