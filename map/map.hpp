/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:04:18 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/10 23:17:33 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "../ft_utils.hpp"
#include "../reverse_iterator.hpp"
#include "../bidirectional_iterator.hpp"
#include "../red_black_tree.hpp"
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
			typedef ft::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename ft::bidirectional_iterator<ft::node<key_type, mapped_type> > iterator;
			typedef typename ft::bidirectional_iterator<const ft::node<key_type, mapped_type> > const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef size_t size_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class ft::map;
				protected :
					Compare _comp;
					value_compare(Compare c) : _comp(c) {} // constructed with map's comparison object
				public :
					typedef bool	result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

					bool operator() (const value_type& x, const value_type& y) const
					{
						return _comp(x.first , y.first);
					}
			};

		private :
			value_compare _comp;
			Alloc _alloc;
			red_black_tree<value_type, key_type> _tree;

		public :
			explicit map(const key_compare &comp = key_compare(),
						const allocator_type &alloc = allocator_type())
						: _comp(comp), _alloc(alloc), _tree()
			{}

			template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type())
				: _comp(comp), _alloc(alloc), _tree()
			{
				this->insert(first, last);
			}

			map(const map &x)
			{ *this = x; }

			~map()
			{}

			map& operator= (const map& x)
			{
				ft::node *tmp = this->_root;
				this->_root = ft::copy_tree(x._root);
				ft::destroy_tree(this->tmp, this->_sentinel, this->_size, this->_alloc);
				return *this;
			}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									ITERATOR FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			iterator begin()
			{
				return ();
			}

			const_iterator begin() const
			{
				return ();
			}

			iterator end()
			{
				return (iterator(this->_sentinel.key_val));
			}

			const_iterator end() const
			{
				return (iterator(this->_sentinel.key_val));
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(this->end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(this->end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(this->begin());
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(this->begin());
			}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									CAPACITY FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			bool empty() const
			{
				if (this->_tree.size() == 0)
					return (true);
				return (false);
			}

			size_type size() const
			{
				return (this->_tree.size());
			}

			size_type max_size() const
			{
				return (this->_alloc.max_size());
			}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**								ELEMENT ACCESS FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			mapped_type& operator[] (const key_type& k)
			{
				return *find(k);	/* uniquement si operator*() retourne mapped_type */
			}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									MODIFIERS FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			pair<iterator, bool> insert(const value_type &val)
			{}

			iterator insert(iterator position, const value_type &val)
			{}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					this->_tree.insert(first);
				}
			}

			void erase(iterator position)
			{
				this->_tree.erase(position);
			}

			size_type erase(const key_type &k)
			{
				this->_tree.erase(k);
			}

			void erase(iterator first, iterator last)
			{
				while (first != last)
				{
					this->_tree.erase(first);
				}
			}

			void swap (map& x)
			{}

			void clear()
			{
				this->_tree.destroy_tree();
			}

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
			{
				iterator it = this->begin();
				while (it != this->end() || it->first != k)
				{
					it++;
				}
				if (it->first == k)
					return (it);
			}

			const_iterator find(const key_type &k) const
			{
				const_iterator it = this->begin();
				while (it != this->end() || it->first != k)
				{
					it++;
				}
				if (it->first == k)
					return (it);
			}

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
