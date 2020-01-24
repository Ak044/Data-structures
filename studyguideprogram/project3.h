//Ammar Khan
//Program 3, header file
//This  contains the structs,
//and classes. The structs
//for the underlying data,
//and the class for the 
//Table ADT.

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

//This struct contains the 
//underlying data that will
//be read in from the file.
struct book_info
{
    char * title;
    char * notes;
    int chapter;
    int page;
    int extra_study;
    int create_info(char [], char [], int, int, int);
    int copy_info(book_info &);
    int update_notes(char []);
    int display_info();
    int remove_info();
    int set_info();
};



//This is the node struct
//for the hash table.
//It contains a next pointer,
//and an object of book info.
struct node
{
    book_info info;
    node * next;
};


//This is a node struct that
//has pointers to the book 
//info data.
struct node2
{
    book_info * info;
    node2 * next;
};



//This is the hash table.
//It will be implemented with a
//class.
class table
{
    public:
        table(int size = 7);
        ~table();
        int load_file(book_info &);
        int insert_file(char *, book_info &);
        int insert_key(char * key_word,book_info &);
        int insert_chap(int key, book_info &);
        int retrieve(char * to_find, book_info to_copy)const;
        int remove(char *);
        int edit(char *, char []);
        int display_chapter(int);
        int display_all();

    private:
        node ** hash_table;
        node2 ** hash_table2;//This is used for the hashs for chapters.
        int hash_table_size;
        int disp_all(node * );
        int hash_func(char *)const;
        int hash_func2(int key_value)const; //Hash function for the second chapter
        int remove_match(node * &, char * &);
        int remove_all(node * & );
        book_info* find(node *, book_info &);
        int removal(node2 * &);
        int display(node2 * head, int);
};
