/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:31:48 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/07 14:56:01 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef bidirectional_iterator_HPP
# define bidirectional_iterator_HPP

#include "iterator.hpp"

/*
**	THIS BIDIRECTIONAL ITERATOR IS ONLY FOR FT::MAP
*/

namespace ft
{
	template<typename T1, typename T2>
	class bidirectional_iterator
	{
		public :
			typedef	std::ptrdiff_t					difference_type;
			typedef	ft::node<T1, T2>				value_type;
			typedef	ft::node<T1, T2>::key_val*				pointer;
			typedef	ft::node<T1, T2>::key_val&				reference;
			typedef	ft::bidirectional_iterator_tag	iterator_category;

			bidirectional_iterator() : _elem(0) {}

			bidirectional_iterator(bidirectional_iterator const & src) : _elem(src._elem)
			{ }

			bidirectional_iterator(value_type elem) : _elem(elem) {}

			bidirectional_iterator&	operator=(const bidirectional_iterator &to_copy)
			{
				if (this != &to_copy)
					this->_elem = to_copy;
				return *this;
			}

			reference operator*()
			{ return this->_elem.key_val; }

			pointer	operator->()
			{ return &this->operator*(); }

			bidirectional_iterator& operator++()
			{
				this->_elem = ft::increase(this->_elem);
				return *this; }

			bidirectional_iterator operator++(int)
			{
				bidirectional_iterator rtn(*this);
				operator++();
				return (rtn);
			}

			bidirectional_iterator& operator--()
			{
				this->_elem = ft::decrease(this->_elem);
				return *this; }

			bidirectional_iterator operator--(int)
			{
				bidirectional_iterator rtn(*this);
				operator--();
				return (rtn);
			}

			operator bidirectional_iterator<const value_type>() const
			{
				return bidirectional_iterator<const value_type>(this->_elem);
			}

		private :
			value_type	_elem;
	};
}

#endif
