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


int main() {
  BinaryTree<int> tree_of_ints;
  
  tree_of_ints.add_root(1);
 
  // tree_of_ints.add_left(1,3);
 
  // tree_of_ints.add_left(3,4);
  
   tree_of_ints.add_left(1,5);
  // std::cout<<*tree_of_ints<<std::endl;
  //  tree_of_ints.begin_preorder();
  

}