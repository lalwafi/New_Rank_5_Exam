#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"
#include <iostream>

static void print_bool_line(const char *label, bool v, bool expected)
{
  std::cout << label << ": ";
  if (v)
  {
    std::cout << "true";
  }
  else
  {
    std::cout << "false";
  }
  std::cout << " | ";
  if (expected)
  {
    std::cout << "true";
  }
  else
  {
    std::cout << "false";
  }
  std::cout << std::endl;
}

int main()
{
  // --- 1) Reference-ctor with array backend
  searchable_array_bag ab;
  set s_ref(ab); // reference constructor

  s_ref.insert(1);
  s_ref.insert(1); // duplicate ignored
  s_ref.insert(2);
  s_ref.insert(2); // duplicate ignored
  s_ref.insert(3);

  print_bool_line("ref_arr_has_1", s_ref.has(1), true);
  print_bool_line("ref_arr_has_2", s_ref.has(2), true);
  print_bool_line("ref_arr_has_3", s_ref.has(3), true);
  print_bool_line("ref_arr_has_9", s_ref.has(9), false);

  // Optional: show underlying contents (order depends on array_bag)
  std::cout << "ref_arr_print (no duplicates expected):" << std::endl;
  s_ref.print();

  s_ref.clear();
  print_bool_line("ref_arr_after_clear_has_1", s_ref.has(1), false);

  // --- 2) Pointer-ctor with tree backend
  searchable_tree_bag tb;
  set s_ptr(&tb); // pointer constructor

  int vals[7];
  vals[0] = 5;
  vals[1] = 3;
  vals[2] = 7;
  vals[3] = 5;
  vals[4] = 3;
  vals[5] = 8;
  vals[6] = 7;
  s_ptr.insert(vals, 7); // duplicates in batch should be filtered

  print_bool_line("ptr_tree_has_3", s_ptr.has(3), true);
  print_bool_line("ptr_tree_has_5", s_ptr.has(5), true);
  print_bool_line("ptr_tree_has_7", s_ptr.has(7), true);
  print_bool_line("ptr_tree_has_8", s_ptr.has(8), true);
  print_bool_line("ptr_tree_has_9", s_ptr.has(9), false);

  std::cout << "ptr_tree_print (no duplicates expected):" << std::endl;
  s_ptr.print();

  s_ptr.clear();
  print_bool_line("ptr_tree_after_clear_has_5", s_ptr.has(5), false);

  // --- 3) Default-constructed set with NULL backend (defensive behavior)
  set s_null;        // bag_ == NULL
  s_null.insert(42); // should be a no-op, not crash
  print_bool_line("null_backend_has_42", s_null.has(42), false);
  s_null.clear(); // no-op
  std::cout << "null_backend_print (should print nothing):" << std::endl;
  s_null.print();

  return 0;
}

// Assigment name: Polyset
// Expected File: searchable_array_bag.cpp, searchable_array_bag.hpp,
// searchable_tree_bg.cpp, searchable_tree_bag.hpp, set.cpp, set.hpp

// You will find in this directory some classes:
// - bag: an abstract class representing a bag
// - searchable_bag: an abstract class representing a bag with the ability to search in it.
// - array_bag: an implementation of a bag with an array an underlying data structure.
// - tree_bag: an implementation of a bag with a binary search tree as underlying data structure.

// If you don't know what is a set or a bag (shame!) you can read the attached
// file shame.en.txt

// First Part:
// Since a bag without a searching function isn't very useful, implement two
// classes searchable_array_bag and searchable_tree_bag, that will inherit from
// array_bag and tree_bag and implement the searchable bag abstract class.

// Second Part:
// Implement the class set that will wrap a searchable_bag and turn it into a set.
// You will find in this dir a main that must compile with your code.
// All classes should be under orthodox canonical form. Don't forget the const.