/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:45:03 by thoberth          #+#    #+#             */
/*   Updated: 2022/03/16 12:58:38 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft 
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{

		public :
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected :
			container_type my_container;

		public:
			explicit stack(const container_type &ctnr = container_type()) : my_container(ctnr)
			{}

			~stack() {}

			bool empty() const { return my_container.empty(); }

			size_type size() const { return my_container.size(); }

			value_type &top() { return my_container.back(); }

			const value_type &top() const { return my_container.back(); }

			void push(const value_type &val)
			{
				my_container.push_back(val);
			}

			void pop()
			{
				my_container.pop_back();
			}

			template <class T1, class Container1>
			friend bool operator==(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

			template <class T1, class Container1>
			friend bool operator<(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (lhs.my_container == rhs.my_container); }

	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (!(lhs == rhs)); }

	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (lhs.my_container < rhs.my_container); }

	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (!(rhs < lhs)); }

	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (rhs < lhs); }

	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (!(lhs < rhs)); }
}

#endif
