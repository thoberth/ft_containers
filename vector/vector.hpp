/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:27:34 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/07 20:12:40 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

template < class T, class alloc = std::allocator<T> >
class vector
{
	public:
		explicit vector(const allocator_type& alloc = allocator_type());
};