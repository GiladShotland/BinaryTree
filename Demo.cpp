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
 BinaryTree<bool> t_bool;
 bool a = (t_bool.begin_postorder() == t_bool.end_postorder());
 std::cout<<a << std::endl;
}