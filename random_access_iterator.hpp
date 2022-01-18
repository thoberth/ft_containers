/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:22:35 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/18 17:29:56 by thoberth         ###   ########.fr       */
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
			typedef	T							value_type;
			typedef	T*							pointer;
			typedef	T&							reference;
			typedef	ft::random_access_iterator_tag	iterator_category;

			random_access_iterator() : _elem(T()) {} // a modifier avec null_ptr

			random_access_iterator(const random_access_iterator & src) { 
				this->_elem = src._elem; }

			random_access_iterator(pointer elem) : _elem(elem) {}

			const pointer &		getElem() { return this->_elem; }

			random_access_iterator&	operator=(random_access_iterator &to_copy)
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

			void operator++(int)
			{ this->operator++(); }

			random_access_iterator& operator--()
			{
				this->_elem--; 
				return *this; }

			void operator--(int)
			{ this->operator--(); }

			reference operator[](const int val)
			{
				return this->_elem[val];
			}

		random_access_iterator& operator+(int val) { return (this->_elem + val); }

		random_access_iterator& operator-(int val) { return (this->_elem - val); }

		template<class InputIterator, class Distance>
		void advance(InputIterator& it, Distance n)
		{
			it + n;
		}

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


}

#endif
