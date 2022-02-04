/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:04:18 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/04 17:14:08 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "../ft_utils.hpp"
#include "../reverse_iterator.hpp"
// to do #include "../bidirectional_iterator.hpp"
#include <map>

namespace ft
{
	template <class Key,								  // map::key_type
			class T,									  // map::mapped_type
			class Compare = std::less<Key>,				  // map::key_compare
			class Alloc = std::allocator<ft::pair<const Key, T> > > // map::allocator_type
	class map
	{
		public :
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename ft::bidirectional_iterator<ft::pair<key_type, mapped_type> > iterator;
			typedef typename ft::bidirectional_iterator<const ft::pair<key_type, mapped_type> > const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef size_t size_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				protected :
					key_compare comp;
					value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
				public :
					typedef bool	result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		private :
			key_compare _comp;
			Alloc _alloc;
			ft::node *_root;
			ft::node *_sentinel;

		public :
			explicit map(const key_compare &comp = key_compare(),
						const allocator_type &alloc = allocator_type())
						: _comp(comp), _alloc(alloc)
			{ this->_sentinel = _alloc.allocate(1); }

			template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type())
				: _comp(comp), _alloc(alloc)
			{
				this->_sentinel = _alloc.allocate(1);
				this->insert(first, last);
			}

			map(const map &x) : _comp(x._comp), _alloc(x._alloc)
			{ this = x; }

			~map()
			{
				_alloc.deallocate(this->_sentinel, 1);
				ft::destroy_tree(this->_root);
			}

			map& operator= (const map& x)
			{
				clear();
				ft::node *tmp = this->_root;
				this->_root = ft::copy_tree(x._root);
				ft::destroy_tree(this->tmp);
				return *this;
			}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									ITERATOR FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			iterator begin() 
			{
				return (ft::smaller_pair(this->_root, this->_sentinel));
			}

			const_iterator begin() const
			{
				return (ft::smaller_pair(this->root, this->_sentinel));
			}

			iterator end()
			{
				return (this->_sentinel);
			}

			const_iterator end() const
			{
				return (this->_sentinel);
			}

			reverse_iterator rbegin()
			{
				
			}

			const_reverse_iterator rbegin() const
			{}

			reverse_iterator rend()
			{}

			const_reverse_iterator rend() const
			{}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									CAPACITY FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			bool empty() const
			{}

			size_type size() const
			{}

			size_type max_size() const
			{}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**								ELEMENT ACCESS FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			mapped_type& operator[] (const key_type& k)
			{}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									MODIFIERS FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			pair<iterator, bool> insert(const value_type &val)
			{}

			iterator insert(iterator position, const value_type &val)
			{}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{}

			void erase(iterator position)
			{}

			size_type erase(const key_type &k)
			{}

			void erase(iterator first, iterator last)
			{}

			void swap (map& x)
			{}

			void clear()
			{}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									OBSERVERS FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			key_compare key_comp() const
			{}

			value_compare value_comp() const
			{}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									OPERATIONS FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			iterator find (const key_type& k)
			{}

			const_iterator find(const key_type &k) const
			{}

			size_type count(const key_type &k) const
			{}

			iterator lower_bound(const key_type &k)
			{}

			const_iterator lower_bound(const key_type &k) const
			{}

			iterator upper_bound(const key_type &k)
			{}

			const_iterator upper_bound(const key_type &k) const
			{}

			pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{}

			pair<iterator, iterator> equal_range(const key_type &k)
			{}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									ALLOCATOR FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			allocator_type get_allocator() const
			{ return this->_alloc; }

	};
}

#endif
