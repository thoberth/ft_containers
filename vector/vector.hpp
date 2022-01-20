/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:27:34 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/20 19:14:41 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <stdexcept>
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
		typedef	T&				reference;
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
			_alloc(alloc), _size(0), _capacity(0)
		{
			_ptr = NULL;
		}

		/* Constructs a container with n elements. Each element is a copy of val. */
		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());


		/* Constructs a container with as many elements as the range [first,last),
		**	with each element constructed from its corresponding
		**	element in that range, in the same order. */
		template<class InputIterator>
		vector (InputIterator first, InputIterator last,
				typename ft::enable_if<ft::is_integral<T>::value>::type* = 0,
				const allocator_type& alloc = allocator_type());

		/* Constructs a container with a copy of each of the elements in x,
		**	in the same order. */
		vector (const vector& x); // this capacity = size de x et non capacity de x

		~vector() { } // dont forget to define a body for destructor when its template class

		vector& operator=(const vector& x) // this capacity = size de x et non capacity de x
		{
			this->_ptr = _alloc.allocate(x._size);
		}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									ITERATOR FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

		iterator begin()
		{
			ft::random_access_iterator<value_type> begin(_ptr);
			return begin;
		}

		const_iterator begin() const
		{
			ft::random_access_iterator<value_type> const begin(_ptr);
			return begin;
		}


		iterator end()
		{
			ft::random_access_iterator<value_type> begin(_ptr);
			for(size_type i(0); i <= _size; i++)
				begin++;
			return begin;
		}

		const_iterator end() const
		{
			ft::random_access_iterator<value_type> const begin(_ptr);
			for(size_type i(0); i <= _size; i++)
				begin++;
			return begin;
		}

		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;

		//	reverse_iterator rend();
		//	const_reverse_iterator rend() const;

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									CAPACITY FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

		size_type size() const { return _size; }

		size_type max_size() const { return allocator_type().max_size(); }

		void resize (size_type n, value_type val = value_type())
		{
			if (this->_size < n)
			{
				while (this->_size < n)
					this->insert(this->end(), val);
			}
			else
			{
				while (this->_size > n)
					this->erase(this->end());
			}
		}

		size_type capacity() const { return _capacity; }

		bool empty() const { if (this->_size == 0) return(true); return (false); }


		void reserve (size_type n)
		{
			if (this->_capacity < n)
				this->_ptr = allocator_type().allocate(n);
		}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**								ELEMENT ACCESS FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

		reference operator[] (size_type n) { return	this->_ptr[n]; }

		const_reference operator[] (size_type n) const { return this->_ptr[n]; }

		reference at (size_type n)
		{
			if (n >= size())
				throw std::out_of_range("Out of Range!");
			return this->_ptr[n];
		}

		const_reference at (size_type n) const
		{
			if (n >= size())
				throw std::out_of_range("Out of Range!");
			return this->_ptr[n];
		}

		reference front()
		{
			return *this->begin();
		}

		const_reference front() const
		{
			return *this->begin();
		}

		reference back()
		{
			return *(this->end()--);
		}

		const_reference back() const
		{
			return *(this->end()--);
		}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									MODIFIER FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

		// ne pas oublier d'incrementer la size
		iterator insert (iterator position, const value_type& val);
		// void insert (iterator position, size_type n, const value_type& val);
		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last);

		// ne pas oublier de decrementer la size
		iterator erase (iterator position);
		// iterator erase (iterator first, iterator last);


	private :
		allocator_type	_alloc;
		pointer			_ptr;
		size_type		_size;
		size_type		_capacity;
	};
}
