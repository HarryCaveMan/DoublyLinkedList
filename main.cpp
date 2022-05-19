#include <iostream> // cout
#include "doubly-linked-list.h" // DoublyLinkedList,DoublyLinkedListNode
//#include <mcheck.h> //mcheck()


using std::cout;
using std::endl;
using std::string;
// main method
int main(int argc, char** argv){
    {
        DoublyLinkedList<string> my_list = DoublyLinkedList<string>();
        my_list.append("the middle");
        cout << "tail is " << my_list.get_tail() << endl; 
        my_list.append("the end");
        cout << "tail is " << my_list.get_tail() << endl; 
        my_list.prepend("the start");
        my_list.insert_after("before the middle",0);
        my_list.insert_after("after the middle",2);
        my_list.insert_after("The very end",4);
        my_list.insert_after("The very beginning",-1);
        cout << endl << endl; 
        cout << my_list.get_head() << endl;
        cout << my_list.at(1) << endl;
        cout << my_list.at(2) << endl;
        cout << my_list.at(3) << endl;
        cout << my_list.at(4) << endl;
        cout << my_list.at(5) << endl;
        cout << my_list.get_tail() << endl;
        //should throw out of range exception
        cout << endl << endl;
        try{
        cout << my_list.at(7) << endl;
        } catch(out_of_range& err){
            cout << "Caught: " << err.what() << endl;
        }
        try{
            my_list.insert_after("nothing",7);
        } catch(out_of_range& err){
            cout << "Caught: " << err.what() << endl;
        }
    }
    return 0;
}