/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:41:44 by thoberth          #+#    #+#             */
/*   Updated: 2022/02/07 17:01:48 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

# define RED 0
# define BLACK 1

#include <iostream>
#include "bidirectional_iterator.hpp"


namespace ft
{
	struct input_iterator_tag {};

	struct output_iterator_tag {};

	struct forward_iterator_tag {};

	struct bidirectional_iterator_tag {};

	struct random_access_iterator_tag {};

	/*
	**	DEF ENABLE_IF
	*/

	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	/*
	**	DEF IS_INTEGRAL
	*/

	template<typename T>
	struct is_integral { static const bool value = false; };

	template<>
	struct is_integral<bool> { static const bool value = true; };

	template<>
	struct is_integral<char> { static const bool value = true; };

	template<>
	struct is_integral<wchar_t> { static const bool value = true; };

	template<>
	struct is_integral<signed char> { static const bool value = true; };

	template<>
	struct is_integral<short int> { static const bool value = true; };

	template<>
	struct is_integral<int> { static const bool value = true; };

	template<>
	struct is_integral<long int> { static const bool value = true; };

	template<>
	struct is_integral<unsigned char> { static const bool value = true; };

	template<>
	struct is_integral<unsigned short int> { static const bool value = true; };

	template<>
	struct is_integral<unsigned int> { static const bool value = true; };

	template<>
	struct is_integral<unsigned long int> { static const bool value = true; };

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class T1, class T2>
	struct pair
	{
		typedef	T1		first_type;
		typedef	T2		second_type;
		first_type		first;
		second_type		second;

		pair() : first(first_type()), second(second_type()) {}

		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

		pair (const first_type& a, const second_type& b) : first(a), second(b) {}

		pair& operator= (const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ft::pair<T1, T2>(x, y);
	}

	template <class T>
	struct node
	{
		node *parent;	/*	The node parent */
		node *left;		/*	The node strictly inferior */
		node *right;	/* The node superior or equal */
		int	color;		/* color == 0 if red , color == 1 if black */
		T	key_val;
	};

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**									RED BLACK TREE FUNC								   **
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

	// template <typename T1, typename T2>
	// ft::bidirectional_iterator<T1, T2>
	// smaller_pair(ft::node<T1, T2> *root, ft::node<T1, T2> *sentinel)
	// {
	// 	ft::node *tmp = root;
	// 	while (root->left != sentinel)
	// 	{
	// 		tmp = root;
	// 		root = root->left;
	// 	}
	// 	return ft::bidirectional_iterator(tmp->key_val);
	// }

	// template <typename T1, typename T2>
	// ft::bidirectional_iterator<T1, T2>
	// greatest_pair(ft::node<T1, T2> *root, ft::node<T1, T2> *sentinel)
	// {
	// 	ft::node *tmp = root;
	// 	while (root->right != sentinel)
	// 	{
	// 		tmp = root;
	// 		root = root->right;
	// 	}
	// 	return ft::bidirectional_iterator(tmp->key_val);
	// }


	// template <typename T1, typename T2>
	// ft::node<T1, T2> increase(ft::node<T1, T2> current)
	// {
	// 	if (current.parent == NULL && current.)
	// }

}

#endif
