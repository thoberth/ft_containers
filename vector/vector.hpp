/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:27:34 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/18 17:45:47 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include "../random_access_iterator.hpp"

/*	Rappel : si on essaie d'ajouter un element et que size = capacity -> capacity * 2
**	
**	
**	
**	
**	*/



namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public :
		typedef T												value_type;
		typedef	Alloc											allocator_type;
		typedef	typename allocator_type::reference				reference;
		typedef	typename allocator_type::const_reference		const_reference;
		typedef	typename allocator_type::pointer				pointer;
		typedef	typename allocator_type::const_pointer			const_pointer;
		typedef	ft::random_access_iterator<value_type>			iterator;
		typedef	ft::random_access_iterator<const value_type>	const_iterator;
		//typedef	reverse_iterator<iterator>					reverse_iterator;
		//typedef	const_reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef	typename iterator_traits<iterator>::difference_type	difference_type;
		typedef	size_t											size_type;

		/* Construct an empty container, with no elements. */
		explicit vector (const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _size(0), _capacity(0) {}

		/* Constructs a container with n elements. Each element is a copy of val. */
		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());


		/* Constructs a container with as many elements as the range [first,last),
		**	with each element constructed from its corresponding
		**	element in that range, in the same order. */
		// template<class InputIterator>
		// vector (InputIterator first, InputIterator last,
		// 		const allocator_type& alloc = allocator_type(),
		// 		typename ft::enable_if<ft::is_integral<T>::value>::type = NULL);

		/* Constructs a container with a copy of each of the elements in x,
		**	in the same order. */
		vector (const vector& x); // this capacity = size de x et non capacity de x

		~vector() { } // dont forget to define a body for destructor when its template class

		vector& operator=(const vector& x) // this capacity = size de x et non capacity de x
		{ (void)x;
		}

		iterator begin()
		{
			ft::random_access_iterator<value_type> begin(_ptr);
			return begin;
		}

		void reserve (size_type n)
		{
			this->*_ptr = allocator_type().allocate(n);
		}

	private :
		allocator_type	_alloc;
		pointer			_ptr;
		size_type		_size;
		size_type		_capacity;
	};
}
