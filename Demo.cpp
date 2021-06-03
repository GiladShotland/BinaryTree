/**
 * Demo file for the exercise on binary tree
 *
 * @author Erel Segal-Halevi
 * @since 2021-04
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

int main()
{
  BinaryTree<int> tree_of_ints;
  tree_of_ints.add_root(1);
   tree_of_ints.add_right(1,2);
   tree_of_ints.add_right(2,3);
   
}