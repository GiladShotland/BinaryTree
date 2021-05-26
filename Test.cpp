#include "doctest.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include "BinaryTree.hpp"
using namespace ariel;
const int NUM_TESTS = 100;
TEST_CASE("Initialization Check - different data types"){
    SUBCASE("Primitives"){
            
        CHECK_NOTHROW(BinaryTree<int> first_binary_tree);
        CHECK_NOTHROW(BinaryTree<double> second_binary_tree);
        CHECK_NOTHROW(BinaryTree<long> third_binary_tree);
        CHECK_NOTHROW(BinaryTree<float> fourth_binary_tree);
        CHECK_NOTHROW(BinaryTree<char> fifth_binary_tree);
        CHECK_NOTHROW(BinaryTree<string> sixth_binary_tree);
    }
    class DataType{
        private : int num;
        public:
            DataType(int n) : num(n) {}
            ~DataType(){}
    };
    SUBCASE("Our own created DataType"){
        for(int i = 0 ; i < NUM_TESTS ; i++){
            int num = rand() % NUM_TESTS + 0;       
        CHECK_NOTHROW( DataType data(num));
        }
    }
    
}

