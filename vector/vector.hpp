/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:27:34 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/21 21:16:16 by thoberth         ###   ########.fr       */
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
		//typedef	ft::reverse_iterator<iterator>					reverse_iterator;
		//typedef	ft::const_reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef	typename iterator_traits<iterator>::difference_type	difference_type;
		typedef	size_t											size_type;

		/* Construct an empty container, with no elements. */
		explicit vector (const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _ptr(NULL), _size(0), _capacity(0) {}

		/* Constructs a container with n elements. Each element is a copy of val. */
		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) : _alloc(alloc)
		{
			_ptr = _alloc.allocate(n);
			for (size_type i=0; i<n; i++)
				_alloc.construct(_ptr + i, val);
		}

		/* Constructs a container with as many elements as the range [first,last),
		**	with each element constructed from its corresponding
		**	element in that range, in the same order. */
		template<class InputIterator>
		vector (InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0,
				const allocator_type& alloc = allocator_type()) : _alloc(alloc)
		{
			_alloc.allocate(last - first);
			for (size_type i = 0; first != last; i++, first++)
				_ptr = _alloc.construct(_ptr + i, *first);
		}

		/* Constructs a container with a copy of each of the elements in x,
		**	in the same order. */
		vector (const vector& x): _alloc(x._alloc), _ptr(NULL), _size(0), _capacity(0) // this capacity = size de x et non capacity de x
		{
			insert(this->begin(), x.begin(), x.end());
		}

		~vector()
		{
			this->clear();
			if (_capacity > 0)
				_alloc.deallocate(_ptr, _capacity);
		}

		vector& operator=(const vector& x) // this capacity = size de x et non capacity de x
		{
			this->clear();
			if (x._size > this->_capacity)
			{
				_alloc.deallocate(_ptr, _capacity);
				this->_ptr = _alloc.allocate(x._size);
			}
			this->_size = x.size;
			for (size_type i(0); i < _size ; i++)
				_ptr = _alloc.construct(_ptr + i, x[i]);
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
			if (n == 0)
				return ;
			if (this->_capacity < n)
			{
				pointer prev_ptr = _ptr;
				pointer	tmp = _ptr;
				this->_ptr = _alloc.allocate(n);
				for (size_type i(0); i < _size; i++)
				{
					_alloc.construct(_ptr + i, prev_ptr[i]);
					_alloc.destroy(prev_ptr + i);
				}
				_alloc.deallocate(tmp, _capacity);
				_capacity = n;
			}
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

	// Affecte un nouveau contenu au vecteur, remplaçant son contenu actuel,
	// et modifiant sa taille en conséquence.
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			this->clear();
			if ((last - first) > _capacity)
				this->reserve(last - first);
			for(; first != last; first++)
				this->insert(first, *first);
		}

		void assign (size_type n, const value_type& val)
		{
			this->clear();
			if (n > _capacity)
				this->reserve(n);
			iterator it = this->begin();
			for(size_type i(0); i < n ; i++, it++)
				this->insert(it, val);
		}

		void push_back (const value_type& val)
		{
			insert(this->end(), val);
		}

		void pop_back()
		{
			erase(this->end()--);
		}

		// ne pas oublier d'incrementer la size
		iterator insert (iterator position, const value_type& val)
		{
			difference_type index = position - this->begin();

			insert(position, 1, val);
			return(iterator(&_ptr[index]));
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0);

		// ne pas oublier de decrementer la size
		iterator erase (iterator position);
		// iterator erase (iterator first, iterator last);

		void clear()
		{
			if (_size > 0)
			{
				for (; _size > 0; _size--)
					_alloc.destroy(_ptr[_size - 1]);
			}
			_size = 0;
		}

	private :
		allocator_type	_alloc;
		pointer			_ptr;
		size_type		_size;
		size_type		_capacity;
	};
}
