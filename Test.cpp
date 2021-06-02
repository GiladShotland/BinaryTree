#include "doctest.h"
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <vector>
using namespace std;
#include "BinaryTree.hpp"
using namespace ariel;

const int NUM_TESTS = 100;
/*class for checking the functionallity of the template with objects*/
class DataType
{
private:
    int num;

public:
    DataType(int n) : num(n) {}
    ~DataType() {}
    int get_data() const { return num; }
    bool operator==(DataType &other) const
    {
        return get_data() == other.get_data();
    }

};


/*basic tree operations*/
TEST_CASE("Initialization Check - different data types")
{
    SUBCASE("Primitives")
    {

        CHECK_NOTHROW(BinaryTree<int> first_binary_tree);
        CHECK_NOTHROW(BinaryTree<double> second_binary_tree);
        CHECK_NOTHROW(BinaryTree<long> third_binary_tree);
        CHECK_NOTHROW(BinaryTree<float> fourth_binary_tree);
        CHECK_NOTHROW(BinaryTree<char> fifth_binary_tree);
        CHECK_NOTHROW(BinaryTree<string> sixth_binary_tree);
    }

    SUBCASE("Our own created DataType")
    {
        CHECK_NOTHROW(BinaryTree<DataType> seventh_binary_tree);
    }
}
TEST_CASE("Building huge tree"){
    BinaryTree<int> bt_ints;
    bt_ints.add_root(0);
    for(int i = 1 ; i < 1000000 ; i++){
        CHECK_NOTHROW(bt_ints.add_left(i-1,i));
    }
}
TEST_CASE("root check - different data types")
{
    /*test if the root is created and replaced correctly*/
    SUBCASE("int data type")
    {
        BinaryTree<int> bt_ints;
        int num;
        for (int i = 0; i < NUM_TESTS; i++)
        {
            num = rand() % NUM_TESTS + 0;
            CHECK_NOTHROW(bt_ints.add_root(num));
            /*adding and replacing the root with objects*/
            CHECK_EQ(*(bt_ints.begin()), num);
        }
    }
    SUBCASE("double data type")
    {
        BinaryTree<double> bt_doubles;
        double num;
        for (int i = 0; i < NUM_TESTS; i++)
        {
            num = (double)(rand() % NUM_TESTS + 0);
            CHECK_NOTHROW(bt_doubles.add_root(num));
            /*adding and replacing the root with objects*/
            CHECK_EQ(*(bt_doubles.begin()), num);
        }
    }
    SUBCASE("char data type")
    {
        BinaryTree<char> bt_chars;
        char character;
        int random;

        for (int i = 0; i < NUM_TESTS; i++)
        {
            random = rand() % 26 + 0;
            character = 'a' + random;
            CHECK_NOTHROW(bt_chars.add_root(character));
            /*adding and replacing the root with objects*/
            CHECK_EQ(*(bt_chars.begin()), character);
        }
    }
    SUBCASE("string data type")
    {
        vector<string> strings_vector = {"cpp", "is", "a", "powerful", "language", "it", "is", "fast", "and", "has", "many", "options"};
        BinaryTree<string> bt_strings;
        for (uint i = 0; i < 11; i++)
        {
            CHECK_NOTHROW(bt_strings.add_root(strings_vector.at(i)));
            /*adding and replacing the root with objects*/
            CHECK_EQ(*(bt_strings.begin()), strings_vector.at(i));
        }
    }
    SUBCASE("our own dt ")
    {
        BinaryTree<DataType> bt_dt;
        for (int i = 0; i < NUM_TESTS; i++)
        {
            int num = rand() % NUM_TESTS + 0;
            DataType obj(num);
            /*adding and replacing the root with objects*/
            CHECK_NOTHROW(bt_dt.add_root(obj));
            CHECK_EQ(bt_dt.begin()->get_data(), num);
        }
    }
}
TEST_CASE("adding left")
{
    SUBCASE("ints")
    {
        BinaryTree<int> bt_ints;

        bt_ints.add_root(0);

        /*should create kind of linked list*/
        for (int i = 1; i < NUM_TESTS; i++)
        {
            /*inorder traversal starts from the most left child*/

            CHECK_NOTHROW(bt_ints.add_left(i - 1, i));
            CHECK_EQ(*(bt_ints.begin()), i);
        }
        /*replacing*/
        int j = 0;
        for (int i = NUM_TESTS - 1; i > 0; i--)
        {
            CHECK_NOTHROW(bt_ints.add_left(i - 1, j++));
        }
        bt_ints.add_root(j);
        j = 0;
        auto it = bt_ints.begin();
        for (int i = NUM_TESTS - 1; i >= 0; i--)
        {
            CHECK_EQ(*(it), j++);
            ++it;
        }
        CHECK_THROWS(bt_ints.add_left(100, 2));
    }
    SUBCASE("doubles")
    {
        BinaryTree<int> bt_doubles;

        bt_doubles.add_root(0);

        /*should create kind of linked list*/
        for (int i = 1; i < NUM_TESTS; i++)
        {
            /*inorder traversal starts from the most left child*/

            CHECK_NOTHROW(bt_doubles.add_left(i - 1, i));
            CHECK_EQ(*(bt_doubles.begin()), i);
        }
        /*replacing*/
        int j = 0;
        for (int i = NUM_TESTS - 1; i > 0; i--)
        {
            CHECK_NOTHROW(bt_doubles.add_left(i - 1, j++));
        }
        bt_doubles.add_root(j);
        j = 0;
        for (auto it = bt_doubles.begin() ; it != bt_doubles.end() ; ++it){
            CHECK_EQ(*(it), j++);
        }
        
        CHECK_THROWS(bt_doubles.add_left(100, 2));
    }
    SUBCASE("chars")
    {
        BinaryTree<char> bt_chars;
        char character;

        for (int i = 0; i < 26; i++)
        {
            character = 'a' + i;
            CHECK_NOTHROW(bt_chars.add_left(character - 1, character));
            CHECK_EQ(*(bt_chars.begin()), character);
        }
        for (int i = 0; i < 25; i++)
        {
            CHECK_NOTHROW(bt_chars.add_left('z' - i, 'a' + i));
        }
        bt_chars.add_root('z');
        /*inorder traversal starts from the most left child*/
        auto it = bt_chars.begin();
        int i = 0;
        for(auto it = bt_chars.begin() ; it != bt_chars.end() ; ++it){
            CHECK_EQ(*it, 'a' + i++);
        }
        
        CHECK_THROWS(bt_chars.add_left('z', 'y'));
    }
    SUBCASE("string")
    {
        vector<string> strings_vector = {"cpp", "is", "a", "powerful", "language", "it", "is", "fast", "and", "has", "many", "options"};
        BinaryTree<string> bt_strings;
        bt_strings.add_root(strings_vector.at(0));
        for (uint i = 1; i < 12; i++)
        {
            CHECK_NOTHROW(bt_strings.add_left(strings_vector.at(i - 1), strings_vector.at(i)));
            CHECK_EQ(*(bt_strings.begin()), strings_vector.at(i));
        }
        /*replacing*/
        for (uint i = 0; i < 12; i++)
        {
            CHECK_NOTHROW(bt_strings.add_left(strings_vector.at(11 - i), strings_vector.at(i)));
        }
        bt_strings.add_root("options");
        /*inorder traversal starts from the most left child*/
        auto it = bt_strings.begin();
        uint i = 0 ;
        for(auto it = bt_strings.begin(); it != bt_strings.end() ; ++it){
            CHECK_EQ(*it, strings_vector.at(i++));
        }
        CHECK_THROWS(bt_strings.add_left("z", "y"));
    }
    SUBCASE("our own datatype"){
        BinaryTree<DataType> bt_dt;
        bt_dt.add_root(DataType{0});
        /*creating a linked list*/
        for(int i = 1 ; i < NUM_TESTS ; i++){
            CHECK_NOTHROW(
            bt_dt.add_left(DataType{i-1},DataType{i}));
            CHECK_EQ(bt_dt.begin_inorder()->get_data(),i);
        }
        /*replacing*/
        for(int i = 0 ; i<NUM_TESTS ;i++){
            CHECK_NOTHROW(bt_dt.add_left(DataType{NUM_TESTS-1-i},DataType{i}));
        }
        int i = 0;
        /*from bottom to the root*/
        for(auto it = bt_dt.begin_postorder() ; it != bt_dt.end_postorder() ; ++it){
            CHECK_EQ(it->get_data(),i);
        }

    }
    
}
TEST_CASE("adding right")
{
    SUBCASE("ints")
    {
        BinaryTree<int> bt_ints;

        bt_ints.add_root(0);

        /*should create kind of linked list*/
        for (int i = 1; i < NUM_TESTS; i++)
        {
            /*postorder traversal starts from the most left child*/

            CHECK_NOTHROW(bt_ints.add_right(i - 1, i));
            CHECK_EQ(*(bt_ints.begin_postorder()), i);
        }
        /*replacing*/
        int j = 0;
        for (int i = NUM_TESTS - 1; i > 0; i--)
        {
            CHECK_NOTHROW(bt_ints.add_right(i - 1, j++));
        }
        bt_ints.add_root(j);
        j = 0;
        auto it = bt_ints.begin_postorder();
        for (int i = NUM_TESTS - 1; i >= 0; i--)
        {
            CHECK_EQ(*(it), j++);
            ++it;
        }
    }
    SUBCASE("doubles")
    {
        BinaryTree<int> bt_doubles;

        bt_doubles.add_root(0);

        /*should create kind of linked list*/
        for (int i = 1; i < NUM_TESTS; i++)
        {
            /*postorder traversal starts from the most left child*/

            CHECK_NOTHROW(bt_doubles.add_right(i - 1, i));
            CHECK_EQ(*(bt_doubles.begin_postorder()), i);
        }
        /*replacing*/
        int j = 0;
        for (int i = NUM_TESTS - 1; i > 0; i--)
        {
            CHECK_NOTHROW(bt_doubles.add_right(i - 1, j++));
        }
        bt_doubles.add_root(j);
        j = 0;
        auto it = bt_doubles.begin_postorder();
        for (int i = NUM_TESTS - 1; i >= 0; i--)
        {
            CHECK_EQ(*(it), j++);
            ++it;
        }
    }
    SUBCASE("chars")
    {
        BinaryTree<char> bt_chars;
        char character;

        for (int i = 0; i < 26; i++)
        {
            character = 'a' + i;
            CHECK_NOTHROW(bt_chars.add_right(character - 1, character));
            CHECK_EQ(*(bt_chars.begin_postorder()), character);
        }
        for (int i = 0; i < 25; i++)
        {
            CHECK_NOTHROW(bt_chars.add_left('z' - i, 'a' + i));
        }
        bt_chars.add_root('z');
        /*postorder traversal starts from the most left child*/
        auto it = bt_chars.begin_postorder();
        for (int i = 0; i < 26; i++)
        {
            CHECK_EQ(*it, 'a' + i);
            ++it;
        }
    }
    SUBCASE("string")
    {
        vector<string> words_vector = {"cpp", "is", "a", "powerful", "language", "it", "is", "fast", "and", "has", "many", "options"};
        BinaryTree<string> bt_strings;
        bt_strings.add_root(words_vector.at(0));
        for (uint i = 1; i < 12; i++)
        {
            CHECK_NOTHROW(bt_strings.add_left(words_vector.at(i - 1), words_vector.at(i)));
            CHECK_EQ(*(bt_strings.begin_postorder()), words_vector.at(i));
        }
        /*replacing*/
        for (uint i = 0; i < 12; i++)
        {
            CHECK_NOTHROW(bt_strings.add_right(words_vector.at(11 - i), words_vector.at(i)));
        }
        bt_strings.add_root("options");
        /*inorder traversal starts from the most left child*/
        auto it = bt_strings.begin_postorder();
        for (uint i = 0; i < 12; i++)
        {
            CHECK_EQ(*it, words_vector.at(i));
            ++it;
        }
    }
    SUBCASE("our own datatype"){
        BinaryTree<DataType> bt_dt;
        bt_dt.add_root(DataType{0});
        /*creating a linked list*/
        for(int i = 1 ; i < NUM_TESTS ; i++){
            CHECK_NOTHROW(
            bt_dt.add_right(DataType{i-1},DataType{i}));
            CHECK_EQ(bt_dt.begin_postorder()->get_data(),i);
        }
        /*replacing*/
        for(int i = 0 ; i<NUM_TESTS ;i++){
            CHECK_NOTHROW(bt_dt.add_right(DataType{NUM_TESTS-1-i},DataType{i}));
        }
        int i = 0;
        /*from bottom to the top*/
        for(auto it = bt_dt.begin_postorder() ; it != bt_dt.end_postorder() ; ++it){
            CHECK_EQ(it->get_data(),i);
        }

    }
}
TEST_CASE("two subtrees and zigzags")
{
    SUBCASE("ints")
    {
        BinaryTree<int> bt_int;
        bt_int.add_root(9);
        bt_int.add_left(9, 5);
        bt_int.add_right(9, 8);
        bt_int.add_left(5, 3);
        bt_int.add_right(5, 4);
        bt_int.add_right(8, 7);
        bt_int.add_left(8, 6);
        /*
                9
            5   |   8
        3      4|6     7
        
        */
        int num = 3;
        /*postorder giving the children firstly*/
        for (auto it = bt_int.begin_postorder(); it != bt_int.end_postorder(); ++it)
        {
            CHECK_EQ(*it, num++);
        }
    }
    SUBCASE("doubles")
    {
        BinaryTree<double> bt_doubles;
        bt_doubles.add_root(9);
        bt_doubles.add_left(9, 5);
        bt_doubles.add_right(9, 8);
        bt_doubles.add_left(5, 3);
        bt_doubles.add_right(5, 4);
        bt_doubles.add_right(8, 7);
        bt_doubles.add_left(8, 6);
        /*
                9
            5   |   8
        3      4|6     7
        
        */
        double num = 3;
        /*postorder giving the children firstly*/
        for (auto it = bt_doubles.begin_postorder(); it != bt_doubles.end_postorder(); ++it)
        {
            CHECK_EQ(*it, num++);
        }
    }
    SUBCASE("chars")
    {
        BinaryTree<char> bt_chars;
        bt_chars.add_root('g');
        bt_chars.add_left('g', 'c');
        bt_chars.add_right('g', 'f');
        bt_chars.add_left('c', 'a');
        bt_chars.add_left('f', 'd');
        bt_chars.add_right('c', 'b');
        bt_chars.add_right('f', 'e');
        /*postorder giving the childern firstly*/
        double add = 0;
        for (auto it = bt_chars.begin_postorder(); it != bt_chars.end_postorder(); ++it)
        {
            CHECK_EQ(*it, 'a' + add);
        }
    }
    SUBCASE("strings")
    {
        BinaryTree<string> bt_strings;
        bt_strings.add_root("g");
        bt_strings.add_left("g", "c");
        bt_strings.add_right("g", "f");
        bt_strings.add_left("c", "a");
        bt_strings.add_left("f", "d");
        bt_strings.add_right("c", "b");
        bt_strings.add_right("f", "e");
        vector<string> vec_string = {"a", "b", "c", "d", "e", "d", "e", "f", "g"};
        /*postorder giving the childern firstly*/
        uint index = 0;
        for (auto it = bt_strings.begin_postorder(); it != bt_strings.end_postorder(); ++it)
        {
            CHECK_EQ(*it, vec_string.at(index++));
        }
    }
}
TEST_CASE("structure after update")
{
    BinaryTree<int> bt_ints;
    bt_ints.add_root(0);
    bt_ints.add_left(0, 1);
    bt_ints.add_left(1, 2);
    bt_ints.add_left(0, 3);
    /*2 should be exist there*/
    CHECK_EQ(*(bt_ints.begin_inorder()), 2);
    BinaryTree<int> bt_doubles;
    bt_doubles.add_root(0);
    bt_doubles.add_right(0, 1);
    bt_doubles.add_right(1, 2);
    bt_doubles.add_right(0, 3);
    /*2 should be there*/
    CHECK_EQ(*(bt_ints.begin_postorder()), 2);
}

/*iterators - we can assume that the tree is built well, so we only need to check functionality*/
TEST_CASE("iterators traversals")
{

    BinaryTree<int> bt_ints;
    bt_ints.add_root(4);
    SUBCASE("* operator")
    {
        auto start_checkr_in = bt_ints.begin_inorder();
        auto start_checkr_pre = bt_ints.begin_preorder();
        auto start_checkr_post = bt_ints.begin_postorder();
        CHECK_EQ(*start_checkr_in, 4);
        CHECK_EQ(*start_checkr_pre, 4);
        CHECK_EQ(*start_checkr_post, 4);
    }
    bt_ints.add_left(4, 3);
    bt_ints.add_right(4, 7);
    bt_ints.add_left(3, 1);
    bt_ints.add_right(3, 2);
    bt_ints.add_left(7, 5);
    bt_ints.add_right(7, 6);
    /*
    tree structure:
        4
    3       7
1      2|5      6
    
    */
    BinaryTree<string> bt_str;
    bt_str.add_root("gilad");
    SUBCASE("inorder")
    {
        /*check regular traversal - prefix operator*/
        vector<int> inorder = {1, 3, 2, 4, 5, 7, 6};
        uint i = 0;
        for (auto it = bt_ints.begin_inorder(); it != bt_ints.end_inorder(); ++it)
        {
            CHECK_EQ(*it, inorder.at(i++));
        }
        /*check updates by reference*/
        bt_ints.add_left(3, 6);
        auto it = bt_ints.begin_inorder();
        CHECK_EQ(*it, 6);
        /*check postfix*/
        CHECK_EQ(*(it++), 1);
        CHECK_EQ(*it, 3);
        it = bt_ints.begin_inorder();
        /*check = and != operators*/
        auto another_it = bt_ints.begin_inorder();
        CHECK_EQ(it, another_it);
        ++another_it;
        CHECK(another_it != it);
        bt_ints.add_left(3, 1);
        /*checking -> operator - length should be 5*/
        auto str_it = bt_str.begin_inorder();
        CHECK_EQ(str_it->size(), 5);
    }
    SUBCASE("postorder")
    {
        /*check regular traversal*/
        vector<int> postorder = {1, 2, 3, 5, 6, 7, 4};
        uint i = 0;
        for (auto it = bt_ints.begin_postorder(); it != bt_ints.end_postorder(); ++it)
        {
            CHECK_EQ(*it, postorder.at(i++));
        }
        /*check updates by reference*/
        bt_ints.add_left(3, 6);
        auto it = bt_ints.begin_postorder();
        CHECK_EQ(*it, 6);
        bt_ints.add_left(3, 1);
        /*check  postfix*/

        CHECK_EQ(*(it++), 1);
        CHECK_EQ(*it, 2);
        it = bt_ints.begin_postorder();
        /*check = and != operators*/
        auto another_it = bt_ints.begin_postorder();
        CHECK_EQ(it, another_it);
        ++another_it;
        CHECK(another_it != it);
        bt_ints.add_left(3, 1);
        /*checking -> operator - length should be 5*/
        auto str_it = bt_str.begin_postorder();
        CHECK_EQ(str_it->size(), 5);
    }
    SUBCASE("preorder")
    {
        /*check regular traversal*/
        vector<int> preorder = {4, 3, 1, 2, 7, 5, 6};
        uint i = 0;
        for (auto it = bt_ints.begin_preorder(); it != bt_ints.end_preorder(); ++it)
        {
            CHECK_EQ(*it, preorder.at(i));
        }
        /*check updates by reference*/
        bt_ints.add_root(10);
        auto it = bt_ints.begin_preorder();
        CHECK_EQ(*it, 10);
        /*check postfix*/
        CHECK_EQ(*(it++), 4);
        CHECK_EQ(*it, 3);
        it = bt_ints.begin_preorder();
        /*check = and != operators*/
        auto another_it = bt_ints.begin_preorder();
        CHECK_EQ(it, another_it);
        ++another_it;
        CHECK(another_it != it);
        bt_ints.add_left(3, 1);
        /*checking -> operator - length should be 5*/
        auto str_it = bt_str.begin_preorder();
        CHECK_EQ(str_it->size(), 5);
    }
    SUBCASE("identical functionality of inorder iterator and defualt iterator"){
        auto defualt_it =bt_ints.begin();
        auto inorder_it = bt_ints.begin_inorder();
        while(inorder_it != bt_ints.end_inorder() && defualt_it != bt_ints.end()){
            CHECK_EQ(*defualt_it,*inorder_it);
        }
    }
}
