/* ************************** Map ****************************** */
#include "map.h"

#include <bits/stdc++.h>

using namespace std;

void Map::m() {
  /* Member functions
   *
   * Capacity
   * m.size(), m.max_size(), m.empty()
   *
   * Modifiers
   * m.insert(), m.emplace, m.emplace_hint(), m.erase(), m.swap(), m.clear()
   *
   * Observers
   * m.key_comp(), m.value_comp()
   *
   * Operations
   * m.find(), m.count(), m.lower_bound(), m.upper_bound(), m.equal_range()
   *
   * Others
   * m.get_allocator()
   */

  // ------------------------ Constructors -----------------------//
  // Default constructor
  map<int, int> m1;  // empty map

  // Copy constructor
  map<int, int> m2(m1);

  // Initializer list constructor
  map<int, int> m3 = {
      {1, 10},
      {2, 20},
      {3, 30},
      {4, 40},
  };

  // Iterator constructor
  map<int, int> m4(m1.begin(), m1.end());

  // ---------------------- Iterators ---------------------- //
  // s.begin(), s.end(), s.rbegin(), s.rend(), s.cbegin(), s.cend(),
  // s.crbegin(), s.crend()

  // ------------------------ Capacity -----------------------//
  // m.size(), m.max_size(), m.empty()
  m3 = {
      {1, 10},
      {2, 20},
      {3, 30},
      {4, 40},
  };

  cout << m3.size() << '\n';  // returns 5 | size of set
  m1.max_size();              // returns max size of set
  m1.empty();                 // Check if set is empty

  for (auto itr = m3.begin(); itr != m3.end(); ++itr) {
    cout << '\t' << itr->first << '\t' << itr->second << '\n';
  }

  // ----------------------- Modifiers ------------------------- //
  // m.insert(), m.emplace, m.emplace_hint(), m.erase(), m.swap(), m.clear()

  // ----------------------- Observers ------------------------- //
  // m.key_comp(), m.value_comp()

  // ----------------------- Operations ------------------------- //
  // m.find(), m.count(), m.lower_bound(), m.upper_bound(), m.equal_range()

  // -------------------------- Others ------------------------- //
}