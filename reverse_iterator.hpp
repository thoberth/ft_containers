/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:06:33 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/31 23:28:42 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iter>
	class reverse_iterator : public ft::iterator<
								 typename ft::iterator_traits<Iter>::iterator_category,
								 typename ft::iterator_traits<Iter>::value_type,
								 typename ft::iterator_traits<Iter>::difference_type,
								 typename ft::iterator_traits<Iter>::pointer,
								 typename ft::iterator_traits<Iter>::reference>
	{
	protected:
		typedef iterator_traits<Iter> _traits_type;

	public:
		typedef Iter iterator_type;
		typedef typename _traits_type::difference_type difference_type;
		typedef typename _traits_type::pointer pointer;
		typedef typename _traits_type::reference reference;

		reverse_iterator() : _elem() {}

		explicit reverse_iterator(iterator_type x) : _elem(x) {}

		template <class U>
		reverse_iterator(const reverse_iterator<U> &other) : _elem(other.base()) {}

		iterator_type base() const { return this->_elem; }

		reverse_iterator& operator=( const reverse_iterator& to_copy )
		{
			if (this != &to_copy)
				this->_elem = to_copy.base();
			return *this;
		}

		reference operator*() const
		{
			iterator_type tmp = _elem;
			return *--tmp;
		}
		

		pointer operator->() const
		{
			return &this->operator*();
		}

		reverse_iterator &operator++()
		{
			this->_elem--;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator rtn(*this);
			operator++();
			return (rtn);
		}

		reverse_iterator &operator--()
		{
			this->_elem++;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator rtn(*this);
			operator--();
			return (rtn);
		}

		reference operator[](difference_type val) const
		{
			return this->base()[-val -1];
		}

		operator reverse_iterator<const iterator_type>() const
		{
			return reverse_iterator<const iterator_type>(this->base());
		}

		reverse_iterator operator+(difference_type val) {
			return reverse_iterator(this->_elem.base() - val);
		}

		reverse_iterator operator-(difference_type val) {
			return reverse_iterator(this->_elem.base() + val);
		}

		reverse_iterator& operator+=(difference_type val)
		{
			this->_elem -= val;
			return *this;
		}

		reverse_iterator& operator-=(difference_type val)
		{
			this->_elem += val;
			return *this;
		}

		private:
			iterator_type _elem;
	};

	template <typename T, typename X>
	bool operator==(const reverse_iterator<T> &A,
					const reverse_iterator<X> &B)
	{
		if (A.base() == B.base())
			return (true);
		return (false);
	}

	template <class T, class X>
	bool operator!=(const reverse_iterator<T> &A,
					const reverse_iterator<X> &B)
	{
		if (A.base() != B.base())
			return (true);
		return (false);
	}

	template <typename T, typename X>
	bool operator>(const reverse_iterator<T> &A,
				   const reverse_iterator<X> &B)
	{
		if (A.base() < B.base())
			return (true);
		return (false);
	}

	template <typename T, typename X>
	bool operator<(const reverse_iterator<T> &A,
				   const reverse_iterator<X> &B)
	{
		if (A.base() > B.base())
			return (true);
		return (false);
	}

	template <typename T, typename X>
	bool operator>=(const reverse_iterator<T> &A,
					const reverse_iterator<X> &B)
	{
		if (A.base() <= B.base())
			return (true);
		return (false);
	}

	template <typename T, typename X>
	bool operator<=(const reverse_iterator<T> &A,
					const reverse_iterator<X> &B)
	{
		if (A.base() >= B.base())
			return (true);
		return (false);
	}

	/* For iterator - const_iterator */
	template <typename T_L, typename T_R>
	typename ft::reverse_iterator<T_L>::difference_type
	operator-(const ft::reverse_iterator<T_L> lhs,
			  const ft::reverse_iterator<T_R> rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template <class T>
	ft::reverse_iterator<T> operator+(
		typename ft::reverse_iterator<T>::difference_type n,
		typename ft::reverse_iterator<T> &rai)
	{
		return (reverse_iterator<T>(rai.base() - n));
	}
}
