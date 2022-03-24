/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:04:18 by thoberth          #+#    #+#             */
/*   Updated: 2022/03/21 18:41:21 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "../utils/ft_utils.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/bidirectional_iterator.hpp"
#include "../utils/red_black_tree.hpp"
#include "vector.hpp"
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
			typedef ft::node<value_type> node_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename ft::bidirectional_iterator<node_type, value_type > iterator;
			typedef typename ft::bidirectional_iterator<const node_type, const value_type > const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef size_t size_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
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
			key_compare _comp;
			allocator_type _alloc;
			red_black_tree<value_type, key_type, Compare> _tree;

		public :

			map() : _comp(key_compare()), _alloc(allocator_type()) {}

			explicit map(const key_compare &comp,
						const allocator_type &alloc = allocator_type())
						: _comp(comp), _alloc(alloc)
			{}

			template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type())
				: _comp(comp), _alloc(alloc)
			{
				this->insert(first, last);
			}

			map(const map &x)
			{ *this = x; }

			virtual ~map()
			{}

			map& operator= (const map& x)
			{
				if (this != &x)
				{
					this->_tree = x._tree;
					this->_comp = x._comp;
				}
				return *this;
			}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									ITERATOR FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			void put_tree() const { this->_tree.put_tree(); }

			iterator begin()
			{
				return iterator(this->_tree.minimum(this->_tree.root()), this->_tree.root());
			}

			const_iterator begin() const
			{
				return const_iterator(this->_tree.minimum(this->_tree.root()), this->_tree.root());
			}

			iterator end()
			{
				return iterator(this->_tree.sentinel(), this->_tree.root());
			}

			const_iterator end() const
			{
				return const_iterator(this->_tree.sentinel(), this->_tree.root());
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
				return (this->_tree.max_size());
			}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**								ELEMENT ACCESS FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			mapped_type& operator[] (const key_type& k)
			{
				ft::pair<iterator, bool> it;

				it = this->insert(ft::make_pair(k, mapped_type()));
				return it.first->second;
			}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									MODIFIERS FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			pair<iterator, bool> insert(const value_type &val)
			{
				ft::pair<iterator, bool> to_ret;
				size_t s = this->_tree.size();
				ft::node<value_type>* ptr = this->_tree.insert(val);
				iterator it(ptr, this->_tree.root());
				if (s != this->_tree.size())
					to_ret.second = true;
				else
					to_ret.second = false;
				to_ret.first = it;
				return (to_ret);
			}

			iterator insert(iterator position, const value_type &val)
			{
				(void)position;
				ft::pair<iterator, bool> p = insert(val);
				return (p.first);
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					this->_tree.insert(*first);
					first++;
				}
			}

			void erase(iterator position)
			{
				this->_tree.erase(position.base());
			}

			size_type erase(const key_type &k)
			{
				iterator it = find(k);
				if (it != this->end())
				{
					this->_tree.erase(it.base());
					return 1;
				}
				return 0;
			}

			void erase(iterator first, iterator last)
			{

				ft::vector<key_type> tab;
				// key_type tab[s];
				while (first != last)
				{
					tab.push_back(first->first);
					first++;
				}
				typename ft::vector<key_type>::iterator it = tab.begin();
				typename ft::vector<key_type>::iterator ite = tab.end();
				for(; it != ite ; it++)
					this->erase(*it);
			}

			void swap (map& x)
			{
				this->_tree.swap(x._tree);
			}

			void clear()
			{
				this->_tree.destroy_tree();
			}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									OBSERVERS FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			key_compare key_comp() const
			{
				return key_compare();
			}

			value_compare value_comp() const
			{
				return value_compare(key_compare());
			}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									OPERATIONS FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			iterator find (const key_type& k)
			{
				iterator it = this->begin();
				while (it != this->end() && it->first != k)
				{
					it++;
				}
				if (it->first == k)
					return (it);
				return this->end();
			}

			const_iterator find(const key_type &k) const
			{
				const_iterator it = this->begin();
				while (it != this->end() && it->first != k)
				{
					it++;
				}
				if (it->first == k)
					return (it);
				return this->end();
			}

			size_type count(const key_type &k) const
			{
				if (find(k) != this->end())
					return 1;
				return 0;
			}

			iterator lower_bound(const key_type &k)
			{
				iterator it = this->begin();
				while (it != this->end())
				{
					if (!this->_comp(it->first, k))
						return it;
					it++;
				}
				return it;
			}

			const_iterator lower_bound(const key_type &k) const
			{
				const_iterator it = this->begin();
				while (it != this->end())
				{
					if (!this->_comp(it->first, k))
						return it;
					it++;
				}
				return it;
			}

			iterator upper_bound(const key_type &k)
			{
				iterator it = this->begin();
				while (it != this->end())
				{
					if (this->_comp(k, it->first))
						return it;
					it++;
				}
				return it;
			}

			const_iterator upper_bound(const key_type &k) const
			{
				const_iterator it = this->begin();
				while (it != this->end())
				{
					if (this->_comp(k, it->first))
						return it;
					it++;
				}
				return it;
			}

			pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			pair<iterator, iterator> equal_range(const key_type &k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									ALLOCATOR FUNC									   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

			allocator_type get_allocator() const
			{ return this->_alloc; }

	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs)
		{
			return (!(lhs == rhs));
		}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs)
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs)
		{
			return (lhs == rhs || lhs < rhs);
		}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs)
		{
			return(rhs < lhs);
		}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs)
		{
			return (lhs > rhs || lhs == rhs);
		}

	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc> &lhs,
		map<Key, T, Compare, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
