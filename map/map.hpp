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

#ifndef MAP_HPP
# define MAP_HPP

#include "../ft_utils.hpp"
#include "../reverse_iterator.hpp"
// to do #include "../bidirectional_iterator.hpp"
#include <map>

namespace ft
{
	template <class Key,								  // map::key_type
			class T,									  // map::mapped_type
			class Compare = std::less<Key>,				  // map::key_compare
			class Alloc = std::allocator<ft::pair<const Key, T> > > // map::allocator_type
	class map
	{
		public :
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef ::value_comp()	value_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			// typedef typename ft::bidirectional_iterator<ft::pair<key_type, mapped_type> > iterator;
			// typedef typename ft::bidirectional_iterator<const ft::pair<key_type, mapped_type> > const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef size_t size_type;


	};
}

#endif
