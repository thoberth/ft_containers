/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:08:20 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/07 18:45:06 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "ft_utils.hpp"

# define RED 0
# define BLACK 1

template<typename value_type, typename Compare = std::less<value_type>,
		typename Alloc = std::allocator<ft::node<value_type> > >
class red_black_tree
{
	private:
		Compare					_comp;
		Alloc					_alloc;
		ft::node<value_type>	_root;
		ft::node<value_type>	_sentinel;
		size_t					_size;
	public:
		red_black_tree() : _size(0)
		{
			this->_sentinel = this->_alloc.allocate(1);
			this->_sentinel = this->init_node(this->_sentinel, NULL, NULL, NULL, ft::pair<size_t, int>, BLACK);
		}

		~red_black_tree()
		{
			this->destroy_tree();
		}

		ft::node<value_type>
		init_node(ft::node<value_type> to_init, ft::node<value_type> *parent, ft::node<value_type> *left,
				  ft::node<value_type> *right, value_type key_val, int color = RED)
		{
			to_init->key_val = key_val;
			to_init->parent = parent;
			to_init->left = left;
			to_init->right = right;
			to_init->color = color;
		}

		void destroy_tree()
		{
			ft::node *to_destroy[this->_size];
			size_t child = 0;
			size_t parent = 0;

			while (child > parent)
			{
				if (this->_root.left != this->_sentinel)
					to_destroy[child++] = this->_root.left;
				if (this->_root.right != this->_sentinel)
					to_destroy[child++] = this->_root.right;
				this->_alloc.deallocate(this->_root, 1);
				this->_root = to_destroy[parent++];
			}
		}

		void insert(const value_type& ins)
		{
			ft::node<value_type> to_ins = this->_alloc.allocate(1);
			if (_size == 0)
			{
				to_ins = this->init_node(to_ins, this->_sentinel, this->_sentinel,
					this->_sentinel, ins, BLACK);
				this->_root = to_ins;
			}
			else
			{

			}
		}
};

#endif
