/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:08:20 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/17 17:48:49 by thoberth         ###   ########.fr       */
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
			this->_alloc.construct(this->_sentinel, value_type());
			this->_sentinel->parent = NULL;
			this->_sentinel->left = NULL;
			this->_sentinel->right = NULL;
			this->_sentinel->color = BLACK;
			this->_root = this->_sentinel;
		}

		virtual ~red_black_tree()
		{
			this->destroy_tree();
			if(this->_sentinel != this->_root)
			{
				this->_alloc.destroy(this->_sentinel);
				this->_alloc.deallocate(this->_sentinel, 1);
			}
		}

		red_black_tree & operator=(const red_black_tree & x)
		{
			if (this != &x)
			{
				this->destroy_tree();
				if (x._size == 0)
					return *this;
				ft::node<value_type> *to_destroy[x._size];
				ft::node<value_type> * to_move = x._root;
				size_t child = 1;
				size_t parent = 1;
				to_destroy[0] = x._root;

				while (parent <= x._size)
				{
					if (to_move->left != x._sentinel)
						to_destroy[child++] = to_move->left;
					if (to_move->right != x._sentinel)
						to_destroy[child++] = to_move->right;
					this->insert(to_move->key_val);
					to_move = to_destroy[parent++];
				}
			}
			return (*this);
		}

		ft::node<value_type>*
		init_node(ft::node<value_type> *to_init, ft::node<value_type> *parent, ft::node<value_type> *left,
				  ft::node<value_type> *right, const value_type &val, int color = RED)
		{
			to_init = this->_alloc.allocate(1);
			this->_alloc.construct(to_init, val);
			to_init->parent = parent;
			to_init->left = left;
			to_init->right = right;
			to_init->color = color;
			return to_init;
		}

		void destroy_tree()
		{
			if (this->_size == 0)
				return ;
			ft::node<value_type> *to_destroy[this->_size];
			size_t child = 1;
			size_t parent = 1;
			to_destroy[0] = this->_root;

			while (parent < this->_size)
			{
				if (this->_root->left != this->_sentinel)
					to_destroy[child++] = this->_root->left;
				if (this->_root->right != this->_sentinel)
					to_destroy[child++] = this->_root->right;
				this->_alloc.destroy(this->_root);
				this->_alloc.deallocate(this->_root, 1);
				this->_root = to_destroy[parent++];
			}
			this->_root = this->_sentinel;
			this->_size = 0;
		}

		size_t max_size() const
		{
			return this->_alloc.max_size();
		}

		ft::node<value_type>* minimum(ft::node<value_type> *node) const
		{
			while (node->left != this->_sentinel && node != this->_sentinel)
				node = node->left;
			return node;
		}

		ft::node<value_type>* maximum(ft::node<value_type> *node) const
		{
			while (node->right != this->_sentinel && node != this->_sentinel)
				node = node->right;
			return node;
		}

		ft::node<value_type>* found_next_one(ft::node<value_type> *node)
		{
			if (node == maximum(this->_root))
				return this->_sentinel;
			if (node->right != this->_sentinel)
				return (minimum(node->right));
			while (node != node->parent->left)
				node = node->parent;
			return node;
		}

		ft::node<value_type>* found_prec(ft::node<value_type> *node)
		{
			if (node == minimum(this->_root))
				return this->_sentinel;
			if (node->left != this->_sentinel)
				return (maximum(node->left));
			while (node != node->parent->right)
				node = node->parent;
			return node;
		}

		/*
		**	x = old parent && y = new parent
		*/
		void left_rotate(ft::node<value_type> *x, ft::node<value_type> *y)
		{
			if (x->parent == this->_sentinel)
				this->_root = y;
			if (y->left != this->_sentinel)
			{
				x->right = y->left;
				x->right->parent = x;
			}
			else
				x->right = this->_sentinel;
			y->parent = x->parent;
			if (x->parent != this->_sentinel)
			{
				if (x->parent->left == x)
					x->parent->left = y;
				else
					x->parent->right = y;
			}
			x->parent = y;
			y->left = x;
		}

		void right_rotate(ft::node<value_type> *new_p, ft::node<value_type> *old_p)
		{
			if (old_p->parent == this->_sentinel)
				this->_root = new_p;
			if (new_p->right != this->_sentinel)
			{
				old_p->left = new_p->right;
				old_p->left->parent = old_p;
			}
			else
				old_p->left = this->_sentinel;
			new_p->parent = old_p->parent;
			if (old_p->parent != this->_sentinel)
			{
				if (old_p->parent->left == old_p)
					old_p->parent->left = new_p;
				else
					old_p->parent->right = new_p;
			}
			old_p->parent = new_p;
			new_p->right = old_p;
		}

		void insert(const value_type& ins)
		{
			ft::node<value_type> *to_move = this->_root;
			ft::node<value_type> *to_ins = NULL;
			if (this->_size == 0)
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

		/*
		** Try to insert in the tree.
		*/
		void insert2(const value_type& ins, ft::node<value_type> *to_move, ft::node<value_type> *to_ins)
		{
			if (this->_comp(ins, to_move->key_val)) /* if key of ins < key of to_move */
			{
				if (to_move->left == this->_sentinel)
				{
					to_ins = this->init_node(to_ins, to_move, this->_sentinel,
						this->_sentinel, ins, RED);
					to_move->left = to_ins;
					this->_size++;
					rb_tree_post_insert(to_ins);
				}
				else
				{
					to_move = to_move->left;
					insert2(ins, to_move, to_ins);
				}
			}
			else if (!(this->_comp(ins, to_move->key_val)) &&
					 !(this->_comp(to_move->key_val, ins))) /* if equal the new insert is ignored */
				return ;
			else
			{
				if (to_move->right == this->_sentinel)
				{
					to_ins = this->init_node(to_ins, to_move, this->_sentinel,
						this->_sentinel, ins, RED);
					to_move->right = to_ins;
					this->_size++;
					rb_tree_post_insert(to_ins);
				}
				else
				{
					to_move = to_move->right;
					insert2(ins, to_move, to_ins);
				}
			}
		}

		void rb_tree_post_insert(ft::node<value_type> *z)
		{
			ft::node<value_type> *z_gp = z->parent->parent;
			ft::node<value_type> *z_p = z->parent;
			while (z_p->color == RED)
			{
				if (z_p == z_gp->left)
				{
					if (z_gp->right->color == RED)
					{
						z_gp->right->color = BLACK;
						z_gp->left->color = BLACK;
						z_gp->color = RED;
						z = z_gp;
					}
					else if (z == z_p->right)
					{
						left_rotate(z_p, z);
						z = z_p;
					}
					else
					{
						z_p->color = BLACK;
						z_gp->color = RED;
						right_rotate(z_p, z_gp);
					}
				}
				else
				{
					if (z_gp->left->color == RED)
					{
						z_gp->left->color = BLACK;
						z_gp->right->color = BLACK;
						z_gp->color = RED;
						z = z_gp;
					}
					else if (z == z_p->left)
					{
						right_rotate(z, z_p);
						z = z_p;
					}
					else
					{
						z_p->color = BLACK;
						z_gp->color = RED;
						left_rotate(z_gp, z_p); 

					}
				}
				z_p = z->parent;
				z_gp = z->parent->parent;
			}
			this->_root->color = BLACK;
		}

		void	erase(ft::node<value_type> *z)
		{
			if (this->_size == 0)
				return ;
			int color = z->color;
			ft::node<value_type> *y = z;
			ft::node<value_type> *x;
			if (z->left == this->_sentinel) /*  1 child case  */
			{
				x = z->right;
				transplant(z, z->right);
			}
			else if (z->right == this->_sentinel) /*  1 child case  */
			{
				x = z->left;
				transplant(z, z->left);
			}
			else  /*  2 child specific case  */
			{
				y = minimum(z->right);
				color = y->color;
				x = y->right;
				if (y->parent == z) /* if z->right == y */
				{
					x->parent = y;
				}
				else
				{
					transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

				transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			this->_alloc.deallocate(z, 1);
			this->_size--;
			if (color == BLACK)
				rb_tree_post_erase(x);
		}

		void	rb_tree_post_erase(ft::node<value_type> *x)
		{
			ft::node<value_type> *s; /* the sibling of x */
			while (x != this->_root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						left_rotate(x->parent, x->parent->right);
						s = x->parent->right;
					}
					if (s->left->color == BLACK && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->right->color == BLACK)
						{
							std::cerr << "1.4\n";
							s->left->color = BLACK;
							s->color = RED;
							right_rotate(s->left, s);
							s = x->parent->right;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->right->color = BLACK;
						left_rotate(x->parent, x->parent->right);
						x = this->_root;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						right_rotate(x->parent->left, x->parent);
						s = x->parent->left;
					}
					if (s->right->color == BLACK && s->left->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->left->color == BLACK)
						{
							s->right->color = BLACK;
							s->color = RED;
							left_rotate(s, s->right);
							s = x->parent->left;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->left->color = BLACK;
						right_rotate(x->parent->left, x->parent);
						x = this->_root;
					}
				}
			}
			x->color = BLACK;
		}

		/*
		**	v become u
		*/
		void transplant(ft::node<value_type> *u, ft::node<value_type> *v)
		{
			if (u->parent == this->_sentinel)
				this->_root = v;
			else if (u  == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		/*
		**	Function to show the tree
		*/
		void	put_tree(ft::node<value_type> *to_aff[] = NULL,
			size_t nbr_tab = 50, size_t size_tab = 1) const
		{
			if (this->_size == 0)
			{
				std::cout << "rb tree size = 0" << std::endl;
				return ;
			}
			size_t i = 0;
			size_t t = 0;
			size_t nbr_tab2 = nbr_tab;
			size_tab *= 2;
			ft::node<value_type> *to_aff2[size_tab];
			if (to_aff == NULL)
			{
				if (this->_root->left != this->_sentinel)
					to_aff2[i++] = this->_root->left;
				else
					to_aff2[i++] = NULL;
				if (this->_root->right != this->_sentinel)
					to_aff2[i++] = this->_root->right;
				else
					to_aff2[i++] = NULL;
				for (int tab = nbr_tab2; tab > 0; --tab)
					std::cout << ' ';
				std::cout << this->_root->key_val.first;
				if (this->_root->color == RED)
					std::cout << "R\n";
				else
					std::cout << "B\n";
				put_tree(to_aff2, nbr_tab - 2, size_tab);
			}
			else
			{
				for (int tab = nbr_tab2; tab > 0; --tab)
					std::cout << ' ';
				std::cout << '|';
				while (i < (size_tab / 2))
				{
					if (to_aff[i] != NULL)
					{
						std::cout << to_aff[i]->key_val.first;
						if (to_aff[i]->color == RED)
							std::cout << "R";
						else
							std::cout << "B";
					}
					else
						std::cout << "Nu"; 
					if (to_aff[i] != NULL && to_aff[i]->left != this->_sentinel)
						to_aff2[t++] = to_aff[i]->left;
					else
						to_aff2[t++] = NULL;
					if (to_aff[i] != NULL && to_aff[i]->right != this->_sentinel)
						to_aff2[t++] = to_aff[i]->right;
					else
						to_aff2[t++] = NULL;
					if (!(i % 2 == 0))
						std::cout << "|";
					else
						std::cout << " ";
					i++;
				}
				std::cout << '\n';
				i = 0;
				t = 0;
				while (i < size_tab)
				{
					if (to_aff2[i++] != NULL)
						t++;
				}
				if (t > 0)
					put_tree(to_aff2, nbr_tab - 3, size_tab);
			}
		}

		size_t size() const
		{
			return this->_size;
		}

		ft::node<value_type> *root() const
		{
			return this->_root;
		}

		ft::node<value_type> *sentinel() const
		{
			return this->_sentinel;
		}
};

#endif
