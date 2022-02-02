/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:22:35 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/02 14:33:46 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef random_access_iterator_HPP
# define random_access_iterator_HPP

#include "iterator.hpp"

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

			pointer	base() const { return this->_elem; }

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

			reference operator[](difference_type val)
			{
				return this->_elem[val];
			}

			operator random_access_iterator<const value_type>() const
			{
				return random_access_iterator<const value_type>(this->_elem);
			}

		random_access_iterator operator+(difference_type val) { return (this->_elem + val); }

		random_access_iterator operator-(difference_type val) { return (this->_elem - val); }

		random_access_iterator operator+=(difference_type val) {
			this->_elem += val;
			return *this; }

		random_access_iterator operator-=(difference_type val) { 
			this->_elem -= val;
			return *this; }

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

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator-(const ft::random_access_iterator<T> lhs,
			const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() - rhs.base());
	}

	/* For iterator - const_iterator */
	template <typename T_L, typename T_R>
	typename ft::random_access_iterator<T_L>::difference_type
	operator-(const ft::random_access_iterator<T_L> lhs,
			const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template<typename T>
	ft::random_access_iterator<T> operator+(
		typename ft::random_access_iterator<T>::difference_type n,
		typename ft::random_access_iterator<T>& rai)
		{
			return (&(*rai) + n);
		}
}

#endif
