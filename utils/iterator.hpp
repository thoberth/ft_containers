/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:18:40 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/29 17:12:04 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
	template <class Category,			  // iterator::iterator_category
			  class T,					  // iterator::value_type
			  class Distance = std::ptrdiff_t, // iterator::difference_type
			  class Pointer = T*,		  // iterator::pointer
			  class Reference = T&>		  // iterator::reference
	class iterator
	{
		public :
			typedef T			value_type;

			typedef Distance	difference_type;

			typedef Pointer		pointer;

			typedef Reference	reference;

			typedef Category	iterator_category;
	};
}

#endif
