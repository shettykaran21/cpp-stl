#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> &v) {
  for (auto &value : v) {
    cout << value << ' ';
  }
  cout << '\n';
}

void printVectorOfPairs(vector<pair<int, int> > &v) {
  for (auto &value : v) {
    cout << value.first << ' ' << value.second << '\n';
  }
  cout << '\n';
}

bool compareInterval(pair<int, int> p1, pair<int, int> p2) {
  return (p1.first < p2.first);
}

bool comp(int a, int b) { return (a < b); }

int main() {
  // ------------------------------------------------------------------//
  // sort() - Intrasort (Combination of quick, heap and insertion sort)
  // Time complexity - O(nlogn)
  // By default, it uses QuickSort but if QuickSort is doing unfair partitioning
  // and taking more than N*logN time, it switches to HeapSort and when the
  // vay size becomes really small, it switches to InsertionSort.
  vector<int> v;
  v = {6, 3, 7, 5, 8};
  sort(v.begin(), v.end());  // {3, 5, 6, 7, 8}

  v = {6, 3, 7, 5, 8};
  sort(v.begin(), v.end(), greater<int>());  // {8, 7, 6, 5, 3}

  vector<pair<int, int> > v2 = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
  sort(v2.begin(), v2.end(), compareInterval);

  // ------------------------------------------------------------------//
  // min(), max(), minmax(), swap()

  // min()
  // Time complexity - O(n)
  min(-5, -10);  // returns -10
  min(-5, -10, [](int a, int b) {
    return abs(a) < abs(b);
  });                              // With comparator | returns -5
  min({1, 2, 3, 4, 5, 0, -1, 7});  // returns -1

  // max()
  // Time complexity - O(n)
  max(-5, -10);  // returns -5
  max(-5, -10, [](int a, int b) {
    return abs(a) > abs(b);
  });                              // With comparator | returns -10
  max({1, 2, 3, 4, 5, 0, -1, 7});  // returns 7

  // minmax()
  // Time complexity - O(n)
  // returns {min, max} pair
  minmax(-5, -10);                 // returns {-10, -5}
  minmax({3, 1, 2011, 2014, -5});  // returns {-5, 2014}
  minmax({3, 1, 2011, 2014, -5},
         [](int a, int b) { return abs(a) < abs(b); });  // returns {1, 2014}

  // swap()
  int a = 10, b = 20;
  swap(a, b);  // a = 20, b = 10

  // ------------------------------------------------------------------//
  // reverse(), rotate()

  // reverse()
  // Time complexity - O(n)
  v = {6, 3, 7, 5, 8};
  reverse(v.begin(), v.end());  // v = {8, 5, 7, 3, 6};

  // ------------------------------------------------------------------//
  // rotate()
  // Time complexity - O(n)
  v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // Rotate left 3 times
  rotate(v.begin(), v.begin() + 3, v.end());

  v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // Rotate right 3 times
  rotate(v.begin(), v.begin() + v.size() - 3, v.end());

  // ------------------------------------------------------------------//
  // accumulate(), max_element(), min_element()

  // ------------------------------------------------------------------//
  // next_permutation()

  // ------------------------------------------------------------------//
  // lower_bound(), upper_bound(), binary_search()

  // binary_search()
  // Time complexity - O(logn)
  // returns boolean true if element is present in the container, else returns
  // false.
  v = {6, 3, 7, 5, 8};
  binary_search(v.begin(), v.end(), 3);

  v = {10, 20, 30, 30, 30, 40, 50};
  // Element in vector >= Element in parameter
  // To get index, subtract from v.begin() => lower - v.begin()
  lower_bound(v.begin(), v.end(), 5);   // returns iterator at index 0
  lower_bound(v.begin(), v.end(), 30);  // returns iterator at index 2
  lower_bound(v.begin(), v.end(), 35);  // returns iterator at index 5
  lower_bound(v.begin(), v.end(), 55);  // returns iterator at index 7 (v.end())

  v = {1, 2, 4, 4, 5, 6};
  // Element in vector > Element in parameter
  upper_bound(v.begin(), v.end(), 0);  // returns iterator at index 0
  upper_bound(v.begin(), v.end(), 2);  // returns iterator at index 2
  upper_bound(v.begin(), v.end(), 3);  // returns iterator at index 2
  upper_bound(v.begin(), v.end(), 4);  // returns iterator at index 4
  upper_bound(v.begin(), v.end(), 9);  // returns iterator at index 6

  return 0;
}