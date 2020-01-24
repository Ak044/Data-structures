//Ammar Khan
//Program 2 Header File
//This file contains all
//the prototypes for the 
//functions, the node struct,
//package struct, queue class,
//and stack class.
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


const int MAX = 11;
const int LIMIT = 5;

//A struct for for the package. This contains the
//data for the package.
struct package 
{
    char * sender;
    long sender_numb;
    char * receiver;
    int package_size;
    int create(char [],long, char [], int);
    int copy_pack(package &);
    int display();
    int remove();
    int set_data();
};



//This a stack node, and it has a pointer 
//to the package data, and a pointer to next
//stack node.
struct s_node
{
    package * packages;
    s_node * next;
};



//This is a class that will implement the 
//stack ADT, using a LLL of arrays.
class stack
{
    public:
        stack();
        ~stack();
        int push(package &);
        int pop();
        int peek(package &);
        int display_all();

    private:
        s_node * head; //pointer to the beginning of the LLL of Arrays.
        int top_index; 
        int remove_all(s_node * &);//This recursive function will be called in the destructor
        int display(s_node * &);//This recursive function is used to display all.

};



//This is a queue node, and it has a pointer 
//to the next node, and a char pointer to
//the recepient name.
struct q_node
{
    char * recipient;
    int copy(char * );
    int display();
    int set_data();
    int remove();
    q_node * next;
};



//The queue ADT will be implemented with a 
//CLL This is the class for impleneting it.
class queue
{
    public:
        queue();
        ~queue();
        int enqueue(char * );
        int dequeue();
        int peek(char []);
        int display_all();

    private:
        q_node * rear;
        int remove_all(q_node * &);//recursive function that deletes the list
        int display(q_node * );//recursive function that shows the list
};
