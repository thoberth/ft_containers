/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:22:35 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/28 17:57:50 by thoberth         ###   ########.fr       */
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

			reference	base() const { return *this->_elem; }

			random_access_iterator&	operator=(const random_access_iterator &to_copy)
			{
				if (this != &to_copy)
					this->_elem = to_copy._elem;
				return *this;
			}

			reference operator*()
			{ return *this->base(); }

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
				return random_access_iterator<const value_type>(this->_elem);
			}

		random_access_iterator operator+(int val) { return (this->_elem + val); }

		random_access_iterator operator-(int val) { return (this->_elem - val); }

		random_access_iterator operator+=(int val) {
			this->_elem += val;
			return *this; }

		random_access_iterator operator-=(int val) { 
			this->_elem -= val;
			return *this; }

		// difference_type operator-(const random_access_iterator &rhs) 
		// {
		// 	return (this->base() - rhs.base());
		// }

		private :
			pointer	_elem;
	};

	template<typename T, typename X>
	bool operator==(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.base() == B.base())
			return (true);
		return (false);
	}

	template<typename T, typename X>
	bool operator!=(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.base() != B.base())
			return (true);
		return (false);
	}

	template<typename T, typename X>
	bool operator>(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.base() > B.base())
			return (true);
		return (false);
	}

	template<typename T, typename X>
	bool operator<(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.base() < B.base())
			return (true);
		return (false);
	}

	template<typename T, typename X>
	bool operator>=(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.base() >= B.base())
			return (true);
		return (false);
	}

	template<typename T, typename X>
	bool operator<=(const random_access_iterator<T> & A,
		const random_access_iterator<X> & B)
	{
		if (A.base() <= B.base())
			return (true);
		return (false);
	}
}
	template<typename T>
	ft::random_access_iterator<T> operator+(int n,
	const ft::random_access_iterator<T> &rai)
		{
			return (rai.base() + n);
		}

#endif
