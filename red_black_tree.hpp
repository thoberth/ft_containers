/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:08:20 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/08 18:39:09 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "ft_utils.hpp"

# define RED 0
# define BLACK 1

template<typename value_type, typename key_type, typename Compare = std::less<key_type>,
		typename Alloc = std::allocator<ft::node<value_type> > >
class red_black_tree
{
	public:
		class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class red_black_tree;
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

	private:
		value_compare			_comp;
		Alloc					_alloc;
		size_t					_size;
		ft::node<value_type>	*_root;
		ft::node<value_type>	*_sentinel;

	public:
		red_black_tree(const Compare &comp = Compare(),
					const Alloc &alloc = Alloc())
					: _comp(comp), _alloc(alloc), _size(0)
		{
			this->_sentinel = this->_alloc.allocate(1);
			this->_sentinel = this->init_node(this->_sentinel, NULL, NULL, NULL, ft::make_pair(0,0), BLACK);
		}

		~red_black_tree()
		{
			this->destroy_tree();
		}

		ft::node<value_type>*
		init_node(ft::node<value_type> *to_init, ft::node<value_type> *parent, ft::node<value_type> *left,
				  ft::node<value_type> *right, value_type key_val, int color = RED)
		{
			to_init->key_val = key_val;
			to_init->parent = parent;
			to_init->left = left;
			to_init->right = right;
			to_init->color = color;
			return to_init;
		}

		void destroy_tree()
		{
			if (this->_size == 0)
			{
				std::cout << "rb tree size = 0" << std::endl;
				return ;
			}
			ft::node<value_type> *to_destroy[this->_size];
			size_t child = 1;
			size_t parent = 1;
			to_destroy[0] = this->_root;

			while (parent <= this->_size)
			{
				if (this->_root->left != this->_sentinel)
					to_destroy[child++] = this->_root->left;
				if (this->_root->right != this->_sentinel)
					to_destroy[child++] = this->_root->right;
				this->_alloc.deallocate(this->_root, 1);
				this->_root = to_destroy[parent++];
			}
		}

		void insert(const value_type& ins)
		{
			ft::node<value_type> *to_move = this->_root;
			ft::node<value_type> *to_ins = this->_alloc.allocate(1);
			if (_size == 0)
			{
				to_ins = this->init_node(to_ins, this->_sentinel, this->_sentinel,
					this->_sentinel, ins, BLACK);
				this->_root = to_ins;
				this->_size++;
				
			}
			else
			{
				insert2(ins, to_move, to_ins);
			}
		}

		int insert2(const value_type& ins, ft::node<value_type> *to_move, ft::node<value_type> *to_ins)
		{
			if (this->_comp(ins, to_move->key_val)) /* if key of ins < key root */
			{
				if (to_move->left == this->_sentinel)
				{
					to_ins = this->init_node(to_ins, to_move, this->_sentinel,
						this->_sentinel, ins, BLACK);
					to_move->left = to_ins;
					this->_size++;
					return (1);
				}
				else
				{
					to_move = to_move->left;
					return (insert2(ins, to_move, to_ins));
				}
				return (0);
			}
			else if (!(this->_comp(ins, to_move->key_val)) &&
					 !(this->_comp(to_move->key_val, ins))) /* if equal the new insert is ignored */
			{
				this->_alloc.deallocate(to_ins, 1);
				return (1);
			}
			else
			{
				if (to_move->right == this->_sentinel)
				{
					to_ins = this->init_node(to_ins, to_move, this->_sentinel,
						this->_sentinel, ins, BLACK);
					to_move->right = to_ins;
					this->_size++;
					return (1);
				}
				else
				{
					to_move = to_move->right;
					return (insert2(ins, to_move, to_ins));
				}
				return(0);
			}
		}

		void	put_tree()
		{
			if (this->_size == 0)
			{
				std::cout << "rb tree size = 0" << std::endl;
				return ;
			}
			ft::node<value_type> *to_destroy[this->_size];
			ft::node<value_type> *to_move = this->_root;
			size_t child = 1;
			size_t parent = 1;
			to_destroy[0] = this->_root;

			while (parent <= this->_size)
			{
				if (to_move->left != this->_sentinel)
					to_destroy[child++] = to_move->left;
				if (to_move->right != this->_sentinel)
					to_destroy[child++] = to_move->right;
				to_move = to_destroy[parent++];
			}
		}
};

#endif
