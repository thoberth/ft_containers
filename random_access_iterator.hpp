/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:22:35 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/26 16:18:13 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
	template<typename T>
	class random_access_iterator
	{
		public :
			typedef	std::ptrdiff_t					difference_type;
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;
			typedef	ft::random_access_iterator_tag	iterator_category;

			random_access_iterator() : _elem(0) {}

			random_access_iterator(random_access_iterator const & src) : _elem(src._elem)
			{ }

			random_access_iterator(pointer elem) : _elem(elem) {}

			const pointer &		getElem() const { return this->_elem; }

			random_access_iterator&	operator=(random_access_iterator const& to_copy)
			{
				this->_elem = to_copy._elem;
				return *this;
			}

			reference operator*()
			{ return *this->getElem(); }

			pointer	operator->()
			{ return &this->operator*(); }

			random_access_iterator& operator++()
			{
				this->_elem++; 
				return *this; }

			random_access_iterator operator++(int)
			{
				random_access_iterator rtn(*this);
				operator++();
				return (rtn);
			}

			random_access_iterator& operator--()
			{
				this->_elem--; 
				return *this; }

			random_access_iterator operator--(int)
			{
				random_access_iterator rtn(*this);
				operator--();
				return (rtn);
			}

			reference operator[](const int val)
			{
				return this->_elem[val];
			}

			operator random_access_iterator<const value_type>() const
			{
				return _elem;
			}

		random_access_iterator operator+(int val) { return (this->_elem + val); }

		random_access_iterator operator-(int val) { return (this->_elem - val); }

		random_access_iterator operator+=(int val) {
			this->_elem += val;
			return *this; }

		random_access_iterator operator-=(int val) { 
			this->_elem -= val;
			return *this; }

		private :
			pointer	_elem;
	};

	template<typename T, typename X>
	bool operator==(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.getElem() == B.getElem())
			return (true);
		return (false);
	}

	template<typename T, typename X>
	bool operator!=(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.getElem() != B.getElem())
			return (true);
		return (false);
	}

	template<typename T, typename X>
	bool operator>(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.getElem() > B.getElem())
			return (true);
		return (false);
	}

	template<typename T, typename X>
	bool operator<(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.getElem() < B.getElem())
			return (true);
		return (false);
	}

	template<typename T, typename X>
	bool operator>=(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.getElem() >= B.getElem())
			return (true);
		return (false);
	}

	template<typename T, typename X>
	bool operator<=(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.getElem() <= B.getElem())
			return (true);
		return (false);
	}

	template<typename T>
	ft::random_access_iterator<T> operator+(
		typename ft::random_access_iterator<T>::difference_type n,
		typename ft::random_access_iterator<T>& rai)
		{
			return (&(*rai) + n);
		}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator-(const ft::random_access_iterator<T> lhs,
			const ft::random_access_iterator<T> rhs)
	{
		return (lhs.getElem() - rhs.getElem());
	}

	/* Same for const and not const */
	template <typename T_R, typename T_L>
	typename ft::random_access_iterator<T_R>::difference_type
	operator-(const ft::random_access_iterator<T_L> lhs,
			const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.getElem() - rhs.getElem());
	}
}

#endif
