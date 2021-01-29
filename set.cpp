/* ************************** Set ****************************** */
#include "set.h"

#include <bits/stdc++.h>

using namespace std;

void Set::s() {
  /* Member functions
   *
   * Capacity
   * s.size(), s.max_size(), s.empty()
   *
   * Modifiers
   * s.insert(), s.emplace, s.emplace_hint(), s.erase(), s.swap(), s.clear()
   *
   * Observers
   * s.key_comp(), s.value_comp()
   *
   * Operations
   * s.find(), s.count(), s.lower_bound(), s.upper_bound(), s.equal_range()
   *
   * Others
   * s.get_allocator()
   */

  // ------------------------ Constructors -----------------------//
  // Default constructor
  set<int> s1;  // empty set

  // Range constructor
  int myints[] = {10, 20, 30, 40, 50};
  set<int> s2(myints, myints + 5);

  // Copy constructor
  set<int> s3(s2);

  // Initializer list constructor
  set<int> s4 = {1, 2, 3, 4, 5};

  // Iterator constructor
  set<int> s5(s4.begin(), s4.end());

  // ---------------------- Iterators ---------------------- //
  // s.begin(), s.end(), s.rbegin(), s.rend(), s.cbegin(), s.cend(),
  // s.crbegin(), s.crend()

  // ------------------------ Capacity -----------------------//
  // s.size(), s.max_size(), s.empty()
  s1 = {1, 2, 3, 4, 4, 5};

  s1.size();      // returns 5 | size of set
  s1.max_size();  // returns max size of set
  s1.empty();     // Check if set is empty

  // ----------------------- Modifiers ------------------------- //
  // s.insert(), s.emplace, s.emplace_hint(), s.erase(), s.swap(), s.clear()
  s1 = {1, 2, 3, 4, 5};

  s1.insert({-1, 8, 10});  // s1: {-1, 1, 2, 3, 4, 5, 8, 10}
  s1.insert(11);           // s1: {-1, 1, 2, 3, 4, 5, 8, 10, 11}

  s1.emplace(6);  // s1: {-1, 1, 2, 3, 4, 5, 6, 8, 10, 11}
  auto it = s1.emplace_hint(s1.begin(),
                            7);  // s1: {-1, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11}
  // Faster insertion as search starts at position where 7 was inserted
  // previously
  s1.emplace_hint(it, 9);  // s1: {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}

  s1.erase(s1.begin());  // s1: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
  s1.erase(4);           // s1: {1, 2, 3, 5, 6, 7, 8, 9, 10, 11}

  s1.swap(s2);  // swaps sets s1 and s2

  s1.clear();  // Clears the set

  // ----------------------- Observers ------------------------- //
  // s.key_comp(), s.value_comp()

  // ----------------------- Operations ------------------------- //
  // s.find(), s.count(), s.lower_bound(), s.upper_bound(), s.equal_range()
  s1 = {1, 2, 5, 6, 7, 8, 9, 10, 11};

  s1.find(10);  // Returns iterator pointing to 10

  s1.count(10);  // Returns 1 if element is present, else 0

  // Returns iterator pointing to value >= 3 (Here, points to 5)
  s1.lower_bound(3);

  // Returns iterator pointing to value > 3 (Here, points to 5)
  s1.upper_bound(3);
  s1.upper_bound(6);  // (Here, points to 7)

  // -------------------------- Others ------------------------- //
  s1.get_allocator();
}
