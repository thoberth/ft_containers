/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:31:48 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/02 14:38:54 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef bidirectional_iterator_HPP
# define bidirectional_iterator_HPP

#include "iterator.hpp"

namespace ft
{
	template<typename T>
	class bidirectional_iterator
	{
		public :
			typedef	std::ptrdiff_t					difference_type;
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;
			typedef	ft::bidirectional_iterator_tag	iterator_category;

			bidirectional_iterator() : _elem(0) {}

			bidirectional_iterator(bidirectional_iterator const & src) : _elem(src._elem)
			{ }

			bidirectional_iterator(pointer elem) : _elem(elem) {}

			pointer	base() const { return this->_elem; }

			bidirectional_iterator&	operator=(const bidirectional_iterator &to_copy)
			{
				if (this != &to_copy)
					this->_elem = to_copy._elem;
				return *this;
			}

			reference operator*()
			{ return *this->base(); }

			pointer	operator->()
			{ return &this->operator*(); }

			bidirectional_iterator& operator++()
			{
				this->_elem++; 
				return *this; }

			bidirectional_iterator operator++(int)
			{
				bidirectional_iterator rtn(*this);
				operator++();
				return (rtn);
			}

			bidirectional_iterator& operator--()
			{
				this->_elem--; 
				return *this; }

			bidirectional_iterator operator--(int)
			{
				bidirectional_iterator rtn(*this);
				operator--();
				return (rtn);
			}

			reference operator[](difference_type val)
			{
				return this->_elem[val];
			}

			operator bidirectional_iterator<const value_type>() const
			{
				return bidirectional_iterator<const value_type>(this->_elem);
			}

		private :
			pointer	_elem;
	};

}

#endif
