/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:31:48 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/12 12:56:51 by thoberth         ###   ########.fr       */
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
	template<typename T1>
	class bidirectional_iterator
	{
		public :
			typedef	std::ptrdiff_t						difference_type;
			typedef	ft::node<T1>						value_type;
			typedef	typename ft::node<T1>*				pointer;
			typedef	typename ft::node<T1>&				reference;
			typedef	ft::bidirectional_iterator_tag		iterator_category;

			bidirectional_iterator() : _elem(), _root(), _senti()
			{}

			bidirectional_iterator(bidirectional_iterator const & src) : _elem(src._elem),
				_root(src._root), _senti(src._senti)
			{ }

			bidirectional_iterator(value_type elem) : _elem(elem)
			{
				pointer tmp = this->_elem;
				if (tmp->parent == NULL)
				{
					this->_root = tmp;
					this->_senti = tmp->parent;
				}
				while (tmp->parent->parent == NULL)
					tmp = tmp->parent;
				this->_root = tmp;
				this->_senti = tmp->parent;
			}

			bidirectional_iterator&	operator=(const bidirectional_iterator &to_copy)
			{
				if (this != &to_copy)
				{
					this->_elem = to_copy._elem;
					this->_root = to_copy._root;
					this->_senti = to_copy._senti;
				}
				return *this;
			}

			reference operator*()
			{ return this->_elem.key_val; }

			pointer	operator->()
			{ return &this->operator*(); }

			bidirectional_iterator& operator++()
			{
				this->_elem = _found_next_one(_elem);
				return *this; }

			bidirectional_iterator operator++(int)
			{
				bidirectional_iterator rtn(*this);
				operator++();
				return (rtn);
			}

			bidirectional_iterator& operator--()
			{
				this->_elem = _found_prec(_elem);
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
			pointer	_elem;
			pointer _root;
			pointer _senti;

			ft::node<value_type> *found_next_one(ft::node<value_type> *node)
			{
				if (node == maximum(this->_root))
					return this->_sentinel;
				if (node->right != this->_senti)
					return (minimum(node->right));
				while (node != node->parent->left)
					node != node->parent;
				return node;
			}

			ft::node<value_type> *found_prec(ft::node<value_type> *node)
			{
				if (node == minimum(this->_root))
					return this->_sentinel;
				if (node->left != this->_senti)
					return (maximum(node->left));
				while (node != node->parent->right)
					node != node->parent;
				return node;
			}

			ft::node<value_type> *minimum(ft::node<value_type> *node)
			{
				while (node->left != this->_senti)
					node = node->left;
				return node;
			}

			ft::node<value_type> *maximum(ft::node<value_type> *node)
			{
				while (node->right != this->_senti)
					node = node->right;
				return node;
			}
	};
}

#endif
