/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:41:39 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/14 13:54:30 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS
# define ITERATOR_TRAITS

#include <iostream>
#include "ft_utils.hpp"

namespace ft 
{
	/*	Version Generic */

	template <class Iterator>
	class iterator_traits
	{
	public:
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	/*	Specialization Type T* not const */

	template <typename T>
	class iterator_traits<T*>
	{
	public:
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};

	/*	Specialization Type T* const */

	template <typename T>
	class iterator_traits<const T*>
	{
	public:
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};
}

#endif
