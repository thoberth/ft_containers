/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:27:34 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/31 20:09:07 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <stdexcept>
#include "../random_access_iterator.hpp"
#include "../reverse_iterator.hpp"


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
		typedef	ft::reverse_iterator<iterator>					reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef	size_t											size_type;

		/* Construct an empty container, with no elements. */
		explicit vector (const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _ptr(NULL), _size(0), _capacity(0) { _ptr = _alloc.allocate(0); }

		/* Constructs a container with n elements. Each element is a copy of val. */
		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) : _alloc(alloc)
		{
			_ptr = _alloc.allocate(n);
			for (size_type i=0; i<n; i++)
				_alloc.construct(_ptr + i, val);
			_size = n;
			_capacity = n;
		}

		/* Constructs a container with as many elements as the range [first,last),
		**	with each element constructed from its corresponding
		**	element in that range, in the same order. */
		template<class InputIterator>
		vector (InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0,
				const allocator_type& alloc = allocator_type()) : _alloc(alloc) , _size(0), _capacity(0)
		{
			size_type len = 0;
			InputIterator tmp = first;
			while (tmp++ != last)
				len++;
			_ptr = _alloc.allocate(len);
			_capacity = len;
			for (size_type i = 0; first != last; i++, first++)
			{
				_alloc.construct(_ptr + i, *first);
				_size++;
			}
		}

		/* Constructs a container with a copy of each of the elements in x,
		**	in the same order. */
		vector (const vector& x): _alloc(x._alloc), _ptr(NULL), _size(0), _capacity(0)
		{
			insert(this->begin(), x.begin(), x.end());
		}

		~vector()
		{
			this->clear();
			if (_capacity > 0)
				_alloc.deallocate(_ptr, _capacity);
		}

		vector& operator=(const vector& x)
		{
			this->clear();
			if (x._size > this->_capacity)
			{
				_alloc.deallocate(_ptr, _capacity);
				this->_ptr = _alloc.allocate(x._size);
			}
			this->_size = x._size;
			this->_capacity = x._size;
			for (size_type i(0); i < _size ; i++)
				_alloc.construct(_ptr + i, x[i]);
			return *this;
		}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									ITERATOR FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

		iterator begin()
		{
			return _ptr;
		}

		const_iterator begin() const
		{
			return _ptr;
		}


		iterator end()
		{
			return _ptr + _size;
		}

		const_iterator end() const
		{
			return _ptr + _size;
		}

		reverse_iterator rbegin()
		{ return reverse_iterator(this->end()); }

		const_reverse_iterator rbegin() const
		{ return const_reverse_iterator(this->end()); }

		reverse_iterator rend()
		{ return reverse_iterator(this->begin()); }

		const_reverse_iterator rend() const
		{ return const_reverse_iterator(this->begin()); }

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
					this->erase(this->end() - 1);
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
			return *(this->end() - 1);
		}

		const_reference back() const
		{
			return *(this->end() - 1);
		}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									MODIFIER FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

		/* Affecte un nouveau contenu au vecteur, remplaçant son contenu actuel,
		** et modifiant sa taille en conséquence. */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			InputIterator tmp = first;
			size_type len = 0;
			while (tmp++ != last)
				len++;
			if (_capacity == 0 && len > 0)
			{
				reserve(1);
			}
			this->clear();
			if (len > _capacity)
				this->reserve(len);
			insert(this->begin(), first, last);
		}

		void assign (size_type n, const value_type& val)
		{
			this->clear();
			if (n > _capacity)
				this->reserve(n);
			iterator it = this->begin();
			for(size_type i(0); i < n ; i++, it++)
			{
				this->insert(it, val);
			}
		}

		void push_back (const value_type& val)
		{
			insert(this->end(), val);
		}

		void pop_back()
		{
			erase(this->end() - 1);
		}

		// don't forget to inc the size
		iterator insert (iterator position, const value_type& val)
		{
			difference_type index = position - this->begin();

			insert(position, 1, val);
			return(iterator(&_ptr[index]));
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			difference_type index = position - this->begin();
			int to_construct = n;
			int to_move = _size - index;
			int i = n;
			size_type j = _size;

			if (_capacity == 0)
				reserve(1);
			while (_size + n > _capacity)
				reserve(_capacity * 2);
			if (_size != 0 && static_cast<unsigned long>(index) != _size)
			{
				while (to_construct)
				{
					_alloc.construct(_ptr + j++, T());
					to_construct--;
				}
				j = _size - 1;
				while (to_move)
				{
					_ptr[j + n] = _ptr[j] ;
					j--;
					to_move--;
				}
				_size += n;
				while (i)
				{
					_ptr[index++] = val;
					i--;
				}
			}
			else
			{
				while (i)
				{
					_alloc.construct((_ptr + _size++), val);
					i--;
				}
			}
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			size_type len = 0;
			InputIterator tmp = first;
			difference_type index = position - this->begin();
			difference_type indexbis = index;
			size_type to_move = _size - index;
			size_type i = _size - 1;
			size_type t;

			while (tmp++ != last)
				len++;
			if (_capacity == 0)
				reserve(1);
			if (len + _size >= _capacity)
				reserve(_size + len);
			t = len;
			while (len)
			{
				_alloc.construct((_ptr + _size++), T());
				len--;
			}
			while (to_move)
			{
				_ptr[i + t] = _ptr[i] ;
				i--;
				to_move--;
			}
			while (first != last)
			{
				_ptr[indexbis++] = *first;
				first++;
			}
		}

		iterator erase (iterator position)
		{
			return erase(position, position + 1);
		}

		iterator erase (iterator first, iterator last)
		{
			difference_type len = last - first;
			difference_type index = first - this->begin();
			difference_type to_ret = index;

			while (first != (this->end() - 1))
			{
				_ptr[index] = _ptr[index + len];
				first++;
				index++;
			}
			while (len)
			{
				_alloc.destroy(&_ptr[_size-- - 1]);
				len--;
			}
			return iterator(&_ptr[to_ret]);
		}

		void swap (vector& x)
		{
			pointer tmp = _ptr;
			size_type tmpsize = _size;
			size_type tmpcapacity = _capacity;
			allocator_type tmpalloc = _alloc;

			_ptr = x._ptr;
			_size = x._size;
			_capacity = x._capacity;
			_alloc = x._alloc;

			x._ptr = tmp;
			x._size = tmpsize;
			x._capacity = tmpcapacity;
			x._alloc = tmpalloc;
		}

		void clear()
		{
			if (_size > 0)
			{
				for (; _size > 0; _size--)
					_alloc.destroy(&_ptr[_size - 1]);
			}
		}

		allocator_type get_allocator() const { return _alloc; }

	private :
		allocator_type	_alloc;
		pointer			_ptr;
		size_type		_size;
		size_type		_capacity;
	};

	//use the equal algo
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size()!= rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	// is equal to (!(lhs == rhs))
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	// use the lexicographical_compare algo
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	// is equal to (!(rhs < lhs))
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	// is equal to (rhs < lhs) 
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	// is equal to (!(lhs < rhs))
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}
}
