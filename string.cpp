/* ************************** String ****************************** */
#include "string.h"

#include <bits/stdc++.h>

using namespace std;

void String::str() {
  /* Points
    1. If only one int parameter with string => (size)
    2. If only one int parameter with string_name => (pos)
    3. If two int parameters => (pos, size)
  */

  /* Member functions
   * s.size(), s.length(), s.capacity(), s.reserve(), s.shrink_to_fit(),
   * s.resize(), s.max_size(), s.clear(), s.empty()
   *
   * s.at(), s.front(), s.back(), s.push_back(), s.pop_back()
   *
   * s.assign(), s.append(), s.insert(), s.replace()
   *
   * s.erase(), s.c_str(), s.data(), s.get_allocator(), s.substr(), s.swap()
   *
   * s.copy(), s.find(), s.compare()
   */

  /* Modifiers
   * +=, s.append(), s.push_back(), s.assign(), s.insert(), s.erase(),
   * s.replace(), s.swap(), s.pop_back(), s.clear()
   */

  // ------------------------ Constructors -----------------------//
  string s1("Hello");          // s1: Hello
  string s7(s1);               // s7: Hello
  string s2("Hello", 3);       // s2: Hel
                               // (string, size)
  string s3(s1, 2);            // s3: llo
                               // (string_name, pos)
  string s4(s1, 2, 2);         // s4: ll
                               // (string_name, pos, size)
  string s5(5, 'a');           // s5: aaaaa
                               // (size, char) | char works with ASCII too
  string s6({'a', 'b', 'c'});  // s6: abc

  // ------------------------ Capacity -----------------------//
  // s.size(), s.length(), s.max_size(), s.reserve(), s.shrink_to_fit(),
  // s.resize(), s.clear(), s.empty()
  string s9 = "Goodbye";

  s9.size();        // returns 7 | length
  s9.length();      // returns 7 | length | Same as s9.size()
  s9.capacity();    // returns 15 | size of storage space allocated to s9
  s9.reserve(100);  // space allocated to s9 is 100 chars | s9.capacity() == 100
  s9.reserve(5);    // s1: Goodbye
                    // If capacity less than minimum is given as parameter, (15,
                    // in this case) then s9.capacity() == 15
                    // reserve() changes only the capacity(), not the size()
  s9.shrink_to_fit();  // shrink capacity to minimum
                       // Same as reserve() with parameter less than minimum
                       // shrink_to_fit() changes only capacity(), not size()

  s9.resize(9);        // s1: Goodbye\0\0 | s9.size() == 9
  s9.resize(12, 'x');  // s1: Goodbye\0\0xxx | s9.size() == 12
                       // s1.resize() changes s9.size()
                       // Also changes s9.capacity() if parameter is greater
                       // original capacity
  s9.max_size();       // returns max size of string
  s9.clear();          // Clears the string
  s9.empty();          // Check if string is empty

  // ------------------------ Single element access ---------------------//
  // [], s.at(), s.front(), s.back(), s.push_front(), s.push_back()
  string s10 = "Goodbye";
  s10[2];        // returns 'o'
  s10[2] = 'x';  // s10: Goxdbye
  s10[10];       // Undefined behaviour

  s10.at(2) = 'y';  // s10: Goydbye
  // s10.at(10);       // Throws exception out_of_range

  s10.front();         // returns 'G'
  s10.back();          // returns 'e'
  s10.push_back('z');  // s10: Goydbyez
  s10.pop_back();      // retuns and removes last character | s10: Goydbye

  // -------------------------- Ranged access ----------------------- //
  // s.assign(), s.append(), s.insert(), s.replace()
  s1 = "Dragon Land";
  string s11;

  s11.assign(s1);        // s11: Dragon Land | s11 = s1
  s11.assign(s1, 2);     // s11: agon Land
                         // (string_name, pos)
  s11.assign(s1, 2, 4);  // s11: agon
                         // (string_name, pos, size)

  s11.assign("Wisdom");        // s11: Wisdom
  s11.assign("Wisdom", 3);     // s11: Wis
                               // (string, size)
  s11.assign("Wisdom", 2, 3);  // s11: sdo
                               // (string, pos, size)

  s11.assign(3, 'x');  // s11: xxx
                       // (size, char) | char works with ASCII too
  s11.assign({'a', 'b', 'c', 'd', 'e', 'f'});  // s11: abcdef
  // append, insert and replace also has similar syntax

  s11 = "Hello there";
  s11.erase(1, 4);  // s11: H there
                    // (pos, size)

  // ----------------------- Others -------------------- //
  s11 = "abcdef";
  s11.c_str();  // returns c string | "abcdef\0"
  s11.data();   // returns c string | "abcdef\0" | After c++11 both are same
  s11.substr(2, 4);  // returns cdef
  s11.swap(s2);

  // ---------------- Member function algorithms ------------ //
  // s.copy(), s.find(), s.compare()
  // s.copy()
  string s12 = "abcdefg";
  char buf[20];

  size_t len = s12.copy(buf, 3);  // buf: abc[some random chars] | len == 3
  len = s12.copy(buf, 4, 2);      // buf: cdef[some random chars] | len == 4
                              // (char_arr_name, size, pos) | Point 3 exception

  // s.find()
  string s13 = "If a job is worth doing, it's worth doing well";

  size_t found;
  found = s13.find("doing");             // found == 18
  found = s13.find("doing", 20);         // found == 36
                                         // (string, pos)
  found = s13.find("doing well", 0);     // found == 36
  found = s13.find("doing well", 0, 5);  // found == 18
                                         // (string, pos, size)

  found = s13.find_first_of("doing");         // found == 6
  found = s13.find_first_of("doing", 10);     // found == 6
                                              // (string, pos)
  found = s13.find_first_of("doing", 10, 1);  // found == 18
                                              // (string, pos, size)
  found = s13.find_last_of("doing");          // found == 40

  found = s13.find_first_not_of("doing");  // found == 0
  found = s13.find_last_not_of("doing");   // found == 45

  // s.compare()
  s13.compare(s1);  // return +ve if s1 > s2 | -ve if s1 < s2 | 0 if s1 == s2
  s13.compare(3, 2, s1);  // (pos, size, string_name)

  // ---------------- Non-Member function algorithms ------------ //
  string s14;
  // getline(cin, s14);       // default delimiter is '\n'
  // getline(cin, s14, ';');  // delimiter is ';'

  // Number to String - number can be int, hex, octal, exponential
  s14 = to_string(8);      // s14: 8
  s14 = to_string(2.4e7);  // s14: 24000000.000000
  s14 = to_string(0xa4);   // s14: 164
  s14 = to_string(034);    // s14: 28

  // String to Number
  // stoi(), stod(), stof(), etc.

  // ---------------- STL Algorithms ------------ //
  // search(), is_permutation(), replace(), transform(), rotate()

  // --------------------- Iterators ---------------------- //
  // s.begin(), s.end(), s.rbegin(), s.rend(), s.cbegin(), s.cend(),
  // s.cebegin(), s.crend()
}