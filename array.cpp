#include "array.h"

#include <bits/stdc++.h>

using namespace std;

void Array::arr() {
  /* Member functions
   * a.size(), a.max_size(), a.empty()
   *
   * a.at(), a.front(), a.back()
   *
   * a.fill(), a.swap(), a.data()
   */

  /* Modifiers
   * a.fill(), a.swap()
   */

  // ------------------------ Capacity -----------------------//
  // a.size(), a.max_size(), a.empty()

  array<int, 8> a1 = {1, 2, 3, 4, 5, 6, 7, 8};
  array<int, 8> a2 = {8, 7, 6, 5, 4, 3, 2, 1};

  a1.size();      // returns 8 | size of array
  a1.max_size();  // returns 8 | max size of array
                  // max_size & size are same for array
  a1.empty();     // Check if string is empty

  // ------------------------ Single element access ---------------------//
  // [], a.at(), a.front(), a.back()
  a1[2];       // returns 2
  a1[2] = 12;  // a1: {1, 2, 12, 4, 5, 6, 7, 8}
  a1[10];      // Undefined behaviour if index is out of range

  a1.at(2) = 14;  // a1: {1, 2, 14, 4, 5, 6, 7, 8}
                  // a1.at(10);     // Throws exception out_of_range

  a1.front();  // returns 1
  a1.back();   // returns 8

  // ----------------------- Others -------------------- //
  a1 = {1, 2, 3, 4, 5, 6, 7, 8};

  a1.fill(1);   // a1: {1, 1, 1, 1, 1, 1, 1, 1}
  a1.swap(a2);  // swaps array a1 and a2
  a1.data();    // returns an iterator pointing to first element
}