/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:51 by thoberth          #+#    #+#             */
/*   Updated: 2022/01/25 05:59:55 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iterator>
#include "vector/vector.hpp"


// 1. the return type (bool) is only valid if T is an integral type:
// template <class T>
// typename std::enable_if<std::is_integral<T>::value,bool>::type
//   is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
// template < class T,
//            class = typename std::enable_if<std::is_integral<T>::value>::type>
// bool is_even (T i) {return !bool(i%2);}

// int main() {

//   int i = 1;    // code does not compile if type of i is not integral

//   std::cout << std::boolalpha;
// //   std::cout << "i is odd: " << is_odd(i) << std::endl;
//   std::cout << "i is even: " << is_even(i) << std::endl;

//   return 0;}

// using namespace std;
// int main()
// {
  
//     // allocator for integer values
//     allocator<int> myAllocator; // = _alloc dans mon vector
  
//     // allocate space for five ints
//     int* arr = myAllocator.allocate(5); // = malloc ou new
  
//     // construct arr[0] and arr[3]
//     myAllocator.construct(arr, 100);
//     arr[3] = 10;
// 	arr[3] = 12;
  
//     cout << arr[3] << endl;
//     cout << arr[0] << endl;
  
//     // deallocate space for five ints
//     myAllocator.deallocate(arr, 5);
  
//     return 0;
// }


// using namespace std;
  
// int main()
// {
  
//     // allocator for string values
//     allocator<string> myAllocator;
  
//     // allocate space for three strings
//     string* str = myAllocator.allocate(4);
  
//     // construct these 3 strings
//     myAllocator.construct(str, "Geeks");
//     myAllocator.construct(str + 1, "for");
//     myAllocator.construct(str + 2, "Geeks");
// 	str[3] = "yoooo";
  
//     cout << str[0] << str[1] << str[2] << str[3];
  
//     // destroy these 3 strings
//     myAllocator.destroy(str);
//     myAllocator.destroy(str + 1);
//     myAllocator.destroy(str + 2);
//     myAllocator.destroy(str + 3);

//      deallocate space for 3 strings
//     myAllocator.deallocate(str, 3);
// }

int main ()
{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains: " << foo.size() << " " << foo.capacity();
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains: " << bar.size() << " " << bar.capacity();
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

  return 0;
}
