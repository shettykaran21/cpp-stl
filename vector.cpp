/* ************************** Vector ****************************** */
#include "vector.h"

#include <bits/stdc++.h>

using namespace std;

void Vector::vec() {
  /* Member functions
   * v.size(), v.capacity(), v.reserve(), v.shrink_to_fit(),
   * v.resize(), v.max_size(), v.clear(), v.empty()
   *
   * v.at(), v.front(), v.back(), v.push_back(), v.pop_back()
   *
   * v.assign(), v.insert()
   *
   * v.erase(), v.data(), v.get_allocator(), v.swap()
   *
   * v.copy(), v.find(), v.compare()
   */

  /* Modifiers
   * v.assign(), v.insert(), v.erase(), v.clear(), v.swap(), v.emplace(),
   * v.emplace_back(), v.push_back(), v.pop_back()
   */

  // ------------------------ Constructors -----------------------//
  vector<int> v1;              // empty vector of ints
  vector<int> v2 = {1, 2, 3};  // Like arrays
  vector<int> v3(4);           // vector of size 4
  vector<int> v4(4, 100);      // vector of size 4 with value 100
  vector<int> v5(v4.begin(),
                 v4.end());  // iterating through v4
  vector<int> v6(v5);        // a copy of v5

  // the iterator constructor can also be used to construct from arrays
  int a[] = {16, 2, 77, 29};
  vector<int> v7(a, a + sizeof(a) / sizeof(int));

  // ------------------------ Capacity -----------------------//
  // v.size(), v.max_size(), v.reserve(), v.shrink_to_fit(),
  // v.resize(), v.clear(), v.empty()

  v7.size();      // returns 4 | size of vector
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

  v7.max_size();  // returns max size of vector
  v7.clear();     // Clears the vector
  v7.empty();     // Check if vector is empty
}