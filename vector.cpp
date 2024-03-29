/* ************************** Vector ****************************** */
#include "vector.h"

#include <bits/stdc++.h>

using namespace std;

void Vector::vec() {
  /* Member functions
   *
   * Capacity
   * v.size(), v.max_size(), v.resize(), v.capacity(), v.reserve(),
   * v.shrink_to_fit(), v.empty()
   *
   * Element Access
   * [], v.at(), v.front(), v.back(), v.data()
   *
   * Modifiers
   * v.assign(), v.insert(), v.push_back(), v.pop_back(), v.emplace(),
   * v.emplace_back(), v.erase(), v.swap(), v.clear()
   *
   * Others
   * v.get_allocator()
   */

  // ------------------------ Constructors -----------------------//
  // Default constructor
  vector<int> v1;  // empty vector of ints

  // Initializer list constructor
  vector<int> v2 = {1, 2, 3};  // Like arrays

  vector<int> v3(4);       // vector of size 4 with value 0
  vector<int> v4(4, 100);  // vector of size 4 with value 100

  // Iterator constructor
  vector<int> v5(v4.begin(), v4.end());

  // Copy constructor
  vector<int> v6(v5);  // a copy of v5

  // Range constructor (Iterator constructor can also be used to construct from
  // arrays)
  int a[] = {16, 2, 77, 29};
  vector<int> v7(a, a + sizeof(a) / sizeof(int));

  // --------------------- Iterators ---------------------- //
  // v.begin(), v.end(), v.rbegin(), v.rend(), v.cbegin(), v.cend(),
  // v.crbegin(), v.crend()

  // ------------------------ Capacity -----------------------//
  // v.size(), v.max_size(), v.resize(), v.capacity(), v.reserve(),
  // v.shrink_to_fit(), v.empty()

  v7 = {16, 2, 77, 29};

  v7.size();      // returns 4 | size of vector
  v7.max_size();  // returns max size of vector
  v7.capacity();  // returns 4 (in this case) | size of storage space allocated
                  // to v7 | capacity >= size
  v7.reserve(100);  // space allocated to v7 is 100 chars | v7.capacity() == 100
  v7.reserve(3);    // v7: {16, 2, 77, 29}
                  // If capacity less than minimum (4, in this case) is given as
                  // parameter, capacity() doesn't change
                  // reserve() changes only the capacity(), not the size()
  v7.shrink_to_fit();  // shrink capacity to minimum
                       // shrink_to_fit() changes only capacity(), not size()

  v7.resize(7);      // v7: {16, 2, 77, 29, 0, 0, 0} | v7.size() == 7
  v7.resize(10, 1);  // v7: {16, 2, 77, 29, 0, 0, 0, 1, 1, 1} | v7.size() == 10
                     // s1.resize() changes v7.size()
                     // Also changes v7.capacity() if parameter is greater
                     // original capacity
  v7.resize(5);      // v7: {16, 2, 77, 29, 0} | v7.size() == 5

  v7.empty();  // Check if vector is empty

  // ------------------------ Element access ---------------------//
  // [], v.at(), v.front(), v.back(), v.data()

  v7 = {1, 2, 3, 4, 5, 6};

  v7[2];       // returns 3
  v7[2] = 10;  // v7: {1, 2, 10, 4, 5, 6}
  v7[10];      // Undefined behaviour if index is out of range

  v7.at(2);       // returns 10
  v7.at(2) = 12;  // v7: {1, 2, 12, 4, 5, 6}
  // v7.at(10);       // Throws exception out_of_range

  v7.front();  // returns 1 | If empty, undefined behaviour
  v7.back();   // returns 6 | If empty, undefined behaviour

  v7.data();  // Returns a direct pointer to the memory array used internally by
              // the vector to store its owned elements.

  // --------------------- Modifiers ------------------------- //
  // v.assign(), v.insert(), v.push_back(), v.pop_back(),  v.emplace(),
  // v.emplace_back(), v.erase(), v.swap(), v.clear()

  // v.assign() => (size, value)
  v7 = {};
  v7.assign(7, 100);  // v7: {100, 100, 100, 100, 100, 100, 100}
                      // (size, value)
  v7.assign(a, a + sizeof(a) / sizeof(int));  // from arrays
  v7.assign(v6.begin(), v6.end());            // from vectors
  v7.assign({1, 2, 3});  // from initializer list | v7: {1, 2, 3}

  // v.insert() => (pos, value) | (pos, size, value)
  v7 = {10, 20, 30, 40};
  auto it = v7.insert(v7.begin(), 3);  // v7: {3, 10, 20, 30, 40}
                                       // (pos, value)
  v7.insert(it, 2);                    // v7: {2, 3, 10, 20, 30, 40}
  v7.insert(v7.begin() + 2, {6, 7});   // v7: {2, 3, 6, 7, 10, 20, 30, 40}
                                       // initializer list
  it = v7.insert(v7.begin(), 1, 17);   // insert 17 one time at front
                                       // v7: {17, 2, 3, 6, 7, 10, 20, 30, 40}
                                       // (pos, size, value)
  v7.insert(it, 2, 4);  // v7: {4, 4, 17, 2, 3, 6, 7, 10, 20, 30, 40}

  v7.push_back(17);  // v7: {4, 4, 17, 2, 3, 6, 7, 10, 20, 30, 40, 17}
  v7.pop_back();     // v7: {4, 4, 17, 2, 3, 6, 7, 10, 20, 30, 40}
                     // returns & removes last element
                     // If empty, undefined behaviour

  // Advantage of emplace is, it does in-place insertion and avoids an
  // unnecessary copy of object. For primitive data types, it does not matter
  // which one we use. But for objects, use of emplace() is preferred for
  // efficiency reasons.
  v7.emplace_back(14);        // v7: {4, 4, 17, 2, 3, 6, 7, 10, 20, 30, 40, 14}
  v7.emplace(v7.begin(), 4);  // v7: {4, 4, 4, 17, 2, 3, 6, 7, 10, 20, 30, 40,
                              // 14} (pos, value)

  v7.erase(v7.begin());  // v7: {4, 4, 17, 2, 3, 6, 7, 10, 20, 30, 40, 14}
  v7.erase(v7.begin(), v7.begin() + 2);  // v7: {17, 2, 3, 6, 7, 10, 20, 30, 40}

  v7.swap(v6);

  v7.clear();  // Clears the vector

  // -------------------------- Others ------------------------- //
  v7.get_allocator();
}